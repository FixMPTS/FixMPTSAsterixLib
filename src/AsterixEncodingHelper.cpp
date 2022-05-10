/**
 * @file AsterixEncodingHelper.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 5 Apr 2016
 *
 * @section LICENSE
 *
 * This file is part of FixMPTS Asterix Library.
 * FixMPTS Asterix Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FixMPTS Asterix Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with FixMPTS Asterix Library. If not, see <https://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * This class provides some function needed for the encoding of Asterix messages. Most of the functions
 * take a set of input values and just convert them into the appropriate binary format required for
 * the output stream.
 */

// project includes
#include "AsterixEncodingHelper.h"
#include "AsterixConversionHelper.h"
#include "AircraftDerivedDataItemExtended.h"
#include "GeneralEnumerations.h"
#include "AircraftDerivedDataItemBase.h"
#include "MathConstants.h"
#include "DetectionEntry.h"

// general includes
#include <iostream>
#include <cmath>
#include <bitset>
#include <map>
#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

std::vector<unsigned char> AsterixEncodingHelper::encodeSACSIC16Bit( unsigned sac, unsigned sic ) {
   std::vector<unsigned char> encoded_sac_sic;

   encoded_sac_sic.push_back( sac );
   encoded_sac_sic.push_back( sic );

   return encoded_sac_sic;
}

std::vector<unsigned char> AsterixEncodingHelper::encodeTrackNumber16Bit( unsigned number ) {
   std::vector<unsigned char> encoded_track_number;
   // make sure the track number is within the allowed range
   if( number >= 0 && number < pow( 2, 16 ) ) {
      encoded_track_number.push_back( (number >> 8) & 0xff );
      encoded_track_number.push_back( number & 0xff );
   }
   return encoded_track_number;
}

std::vector<unsigned char> AsterixEncodingHelper::encodeTrackMode3A( unsigned code, bool valid,
   bool garbled ) {

   std::vector<unsigned char> encoded_track_m3a;
   // Make sure the mode 3A code is within the required range
   if( code >= 0 && code <= 07777 ) { // octal comparison
   // convert code to oct
      char oct_code[5]; // One extra byte for the null termination which will be ignored later on
      sprintf( oct_code, "%.4o", code % 07777U );
      std::bitset<3> first_digit( oct_code[0] );
      std::bitset<3> second_digit( oct_code[1] );
      std::bitset<3> third_digit( oct_code[2] );
      std::bitset<3> fourth_digit( oct_code[3] );

      std::bitset<16> m3a_data_item(
         "0000" + first_digit.to_string() + second_digit.to_string() +
            third_digit.to_string() + fourth_digit.to_string() );

      // set the valid and garbled flags. Those are located at the end of the bit set
      m3a_data_item[15] = !valid;
      m3a_data_item[14] = garbled;
      m3a_data_item[13] = false; // changed
      m3a_data_item[12] = false; // Spare must be set to zero

      // Write the data structure
      uint16_t complete_code = m3a_data_item.to_ulong();
      encoded_track_m3a.push_back( (complete_code >> 8) & 0xff );
      encoded_track_m3a.push_back( complete_code & 0xff );
   }

   return encoded_track_m3a;
}

std::vector<unsigned char> AsterixEncodingHelper::encodeTimeOfTrackInfo24Bit(uint64_t time_in_ms) {
   std::vector<unsigned char> time_of_day;

   // convert delta to seconds
   unsigned long time_since_midnight;
   time_since_midnight = convertToTimeSinceMidnightMS( time_in_ms ) / 1000;

   // split into 128/ second
   time_since_midnight *= 128;

   //write the three bytes
   time_of_day.push_back( (time_since_midnight >> 16) & 0xff );
   time_of_day.push_back( (time_since_midnight >> 8) & 0xff );
   time_of_day.push_back( time_since_midnight & 0xff );

   return time_of_day;
}

std::vector<unsigned char> AsterixEncodingHelper::encodeTrackStatus(std::shared_ptr<TrackTypeIf> track,
   double service_track_confirmation_weight, std::shared_ptr<TrackMaxDetectionAgeMapping> max_ages,
   std::map<std::string, bool> track_live ) {

   std::map<DetectionEntry::DET_TYPE, bool> detection_type_list;
   bool multi_sensor = false;

   // key is SAC, value is list of SICs
   std::map<unsigned, std::vector<unsigned>> detecting_sensors;

   // Determine the type and count of sensors supporting this track
   for( size_t i = 0; i < track->getDetectionListSize(); i++ ) {
      DetectionEntry current_detection = track->getDetectionAt( i );

      // Set detecting technology
      if( detection_type_list.find( current_detection.getDetectionType() ) == detection_type_list.end() ) {
         detection_type_list[current_detection.getDetectionType()] = true;
      }

      // determine the multi or mono sensor update state
      unsigned short sac = current_detection.getSourceIDSacAt( 0 );
      if( detecting_sensors.find( sac ) == detecting_sensors.end() ) {

         detecting_sensors[sac] = std::vector<unsigned>();
         detecting_sensors[sac].push_back( current_detection.getSourceIDSicAt( 0 ) );
      } else {
         // if the SAC is already stored, store the SIC as well. This is a nasty way to do this
         unsigned sic = current_detection.getSourceIDSicAt( 0 );
         bool found = false;
         for( auto s : detecting_sensors[sac] ) {
            if( sic == s ) {
               found = true;
               break;
            }
         }

         // If the SIC was not contains in the list yet, add it
         if( !found ) {
            detecting_sensors[sac].push_back( sic );
         }
      }

      // More than on updating sensor per SAC => multi sensor or SAC list size ? 1
      multi_sensor =
         multi_sensor || detecting_sensors[sac].size() > 1 || detecting_sensors.size() > 1;
   }

   // Fill in the first extent
   std::bitset<8> first_octet( 0 );

   // Bit 8 MON
   first_octet[7] = !multi_sensor;

   // Bit 7 SPI. This is a store and forward item
   if( track->isADItemPresent( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::SPI ) ) {
      first_octet[6] =
         track->getADItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::SPI )->getBooleanValue();
   }

   // SKIP bits 6 to 3 for the moment
   // Bit 2 Confirmed or tentative track. This depends on the service configured weight
   first_octet[1] = track->getTrackWeight() <= service_track_confirmation_weight;

   // proceed with the fourth extend so we know about the FX bit. Note the fifth extent is not encoded
   // Implement as soon as needed
   std::bitset<8> fourth_extent( 0 );

   // Encode the third extent. Set the FX bit implicitly
   std::bitset<8> third_extent( fourth_extent.any() ? 1 : 0 );

   // Bit 4 ADS contribution to track
   third_extent[3] = (track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_ADS_B ) >
      max_ages->getMaxAgePerType( DetectionEntry::DET_TYPE::ADS_B ));

   // Bit 5 MDS contribution. It is expected that the MDS age is kept in sync if updated by CMB_MDS
   third_extent[4] = (track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_MDS ) >
      max_ages->getMaxAgePerType( DetectionEntry::DET_TYPE::MDS ));

   // Bit 6 SSR contribution. It is expected that the SSR age is kept in sync if updated by CMB
   third_extent[5] = (track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_SSR ) >
      max_ages->getMaxAgePerType( DetectionEntry::DET_TYPE::SSR ));

   // Bit 7 PSR contribution. It is expected that the PSR age is kept in sync if updated by CMB
   third_extent[6] = (track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_PSR ) >
      max_ages->getMaxAgePerType( DetectionEntry::DET_TYPE::PSR ));

   // Bit 8 Coasting
   third_extent[7] = ((getCurrentTimeMS() - track->getLastUpdatingTime())
      > max_ages->getMaxAgePerType( DetectionEntry::DET_TYPE::TRACK ));

   // Initiate the second extend with the proper FX bit
   std::bitset<8> second_extent( third_extent.any() ? 1 : 0 );
   // Currently nothing is encoded in the second extent.

   // Initialise the first extent with the correct FX bit
   std::bitset<8> first_extent( second_extent.any() ? 1 : 0 );

   // Bit 6 TSB (default is false)
   first_extent[5] = track_live.find( "TSB" ) != track_live.end() ? track_live["TSB"] : false;

   // Bit 7 TSE (default is false)
   first_extent[6] = track_live.find( "TSE" ) != track_live.end() ? track_live["TSE"] : false;

   // Finally set the FX bit of the first byte
   first_octet[0] = first_extent.any();

   // Add all extends that are not zero to the message
   std::vector<unsigned char> encoded_track_status;

   // The first octet is mandatory and always present
   encoded_track_status.push_back( first_octet.to_ulong() & 0xff );

   // Place all filled extends into byte array
   bool all_bytes_written = false; // Just to have only one return at the end
   if( !all_bytes_written && first_extent.any() ) { // First extent
      encoded_track_status.push_back( first_extent.to_ulong() & 0xff );
   }
   else {
      all_bytes_written = true;
   }

   if( !all_bytes_written && second_extent.any() ) { // second extent
      encoded_track_status.push_back( second_extent.to_ulong() & 0xff );
   }
   else {
      all_bytes_written = true; // Stop encoding
   }

   if( !all_bytes_written && third_extent.any() ) { // Third extent
      encoded_track_status.push_back( third_extent.to_ulong() & 0xff );
   }
   else {
      all_bytes_written = true; // Stop the encoding
   }

   if( !all_bytes_written && fourth_extent.any() ) { // Fourth extent
      encoded_track_status.push_back( fourth_extent.to_ulong() & 0xff );
   }
   // Last branch => no else needed at this point

   return encoded_track_status;
}

std::vector<unsigned char> AsterixEncodingHelper::encodePositionWG(std::shared_ptr<TrackTypeIf> track) {
   //Point3D position = track->getPosition().transformToGeo();

   // Ensure the point is within the Asterix range, which is the same as the geodetic rang
   //position = position.getPointInGeoBounds();
   return AsterixEncodingHelper::encodePositionWGS8Byte( track->getPositionLat(), track->getPositionLng() );
}

std::vector<unsigned char> AsterixEncodingHelper::encodePositionWGS8Byte( double latitude,
   double longitude ) {

   std::vector<unsigned char> position_wgs;

   // Bring all into the right resolution
   double lsb = 180.0 / pow( 2, 25 );
   latitude /= lsb;
   longitude /= lsb;

   // Convert to unsigned and store it in the byte array
   uint32_t lat = static_cast<uint32_t>( latitude ); // enforce the data type size and convert to unsigned
   uint32_t lng = static_cast<uint32_t>( longitude );

   position_wgs.push_back( (lat >> 24) & 0xff );
   position_wgs.push_back( (lat >> 16) & 0xff );
   position_wgs.push_back( (lat >> 8) & 0xff );
   position_wgs.push_back( lat & 0xff );

   position_wgs.push_back( (lng >> 24) & 0xff );
   position_wgs.push_back( (lng >> 16) & 0xff );
   position_wgs.push_back( (lng >> 8) & 0xff );
   position_wgs.push_back( lng & 0xff );

   return position_wgs;
}

std::vector<unsigned char> AsterixEncodingHelper::encodePositionWGS6Byte( double latitude,
   double longitude ) {

   std::vector<unsigned char> position_wgs;

   // Bring all into the right solution
   double lsb = 180.0 / pow( 2, 23 );
   latitude /= lsb;
   longitude /= lsb;

   // Convert to unsigned and store it in the byte array
   uint32_t lat = static_cast<uint32_t>( latitude ); // Use next bigger one since uint24 is currently missing
   uint32_t lng = static_cast<uint32_t>( longitude );

   position_wgs.push_back( (lat >> 16) & 0xff );
   position_wgs.push_back( (lat >> 8) & 0xff );
   position_wgs.push_back( lat & 0xff );

   position_wgs.push_back( (lng >> 16) & 0xff );
   position_wgs.push_back( (lng >> 8) & 0xff );
   position_wgs.push_back( lng & 0xff );

   return position_wgs;
}

std::vector<unsigned char> AsterixEncodingHelper::encodeGeoAltitude(std::shared_ptr<TrackTypeIf> track) {
   double altitude = track->getPositionAltGeo();
   // Convert to feet
   return encodeGeoAltitude( AsterixConversionHelper::metersToFeet( altitude ) );
}

std::vector<unsigned char> AsterixEncodingHelper::encodeGeoAltitude( double altitude ) {
   std::vector<unsigned char> geometric_altitude;

   // make sure the altitude is within the expected range of -1500ft <= altitude <= 150000 ft
   if( altitude >= -1500.0 && altitude <= 150000.0 ) {
      double lsb = 6.25;
      // apply LSB
      altitude /= lsb;

      uint16_t geo_alt = (uint16_t) altitude;
      // Pack the value into the byte array
      geometric_altitude.push_back( (geo_alt >> 8) & 0xff );
      geometric_altitude.push_back( geo_alt & 0xff );
   }

   return geometric_altitude;
}

std::vector<unsigned char> AsterixEncodingHelper::encodeBaroAltitude( double flight_level,
   int qnh_corrected ) {
   std::vector<unsigned char> baro_altitude;
   double altitude = flight_level;
   double lsb = 4.0; //25.0;

   // Ensure the value is within the expected ranges
   if( altitude >= -15.0 && altitude <= 1500.0 ) {
      altitude *= lsb;

      std::bitset<16> baro_alt_bits = (uint16_t) altitude;
      // Pack the value into the byte array
      if( qnh_corrected >= 0 ) {
         baro_alt_bits[0] = (qnh_corrected > 0);
         uint16_t baro_alt = baro_alt_bits.to_ulong();
         //Set Bit 16 to one
         baro_altitude.push_back( (baro_alt >> 8) & 0xff );
         baro_altitude.push_back( baro_alt & 0xff );
      } else {
         uint16_t baro_alt = baro_alt_bits.to_ulong();
         baro_altitude.push_back( (baro_alt >> 8) & 0xff );
         baro_altitude.push_back( baro_alt & 0xff );
      }
   }

   return baro_altitude;
}

std::vector<unsigned char> AsterixEncodingHelper::encodeRateCD( double rate ) {
   std::vector<unsigned char> rate_cb;
   double lsb = 6.25;

// Rate is already in feet

// Encode the value
   rate *= lsb;
   int encode_rate = (int) rate;
   rate_cb.push_back( (encode_rate >> 8) & 0xff );
   rate_cb.push_back( encode_rate & 0xff );

   return rate_cb;
}

std::vector<unsigned char> AsterixEncodingHelper::encodeMOF8Bit(std::shared_ptr<TrackTypeIf> track) {
   std::vector<unsigned char> mof_item;
   std::bitset<8> raw_mof( 0 );

   // Transversal MOF
   TrackTypeIf::TRACK_MOF tm = track->getTransversalMof();
   raw_mof[7] =
      (tm == TrackTypeIf::TRACK_MOF::LEFT_TURN
         || tm == TrackTypeIf::TRACK_MOF::UNDEFINED);
   raw_mof[6] =
      (tm == TrackTypeIf::TRACK_MOF::RIGHT_TURN
         || tm == TrackTypeIf::TRACK_MOF::UNDEFINED);

   // Longitudinal MOF
   TrackTypeIf::TRACK_MOF lm = track->getLongitudinalMof();
   raw_mof[5] =
      (lm == TrackTypeIf::TRACK_MOF::DECELERATION
         || lm == TrackTypeIf::TRACK_MOF::UNDEFINED);
   raw_mof[4] =
      (lm == TrackTypeIf::TRACK_MOF::ACCELERATION
         || lm == TrackTypeIf::TRACK_MOF::UNDEFINED);

   // Vertical MOF
   TrackTypeIf::TRACK_MOF vm = track->getVerticalMof();
   raw_mof[3] =
      (vm == TrackTypeIf::TRACK_MOF::DESCENT || vm == TrackTypeIf::TRACK_MOF::UNDEFINED);
   raw_mof[2] = (vm == TrackTypeIf::TRACK_MOF::CLIMB
      || vm == TrackTypeIf::TRACK_MOF::UNDEFINED);

   // ADF not encoded
   // Remaining bits are spare bits

   // encode the single bits of all three MOFs
   mof_item.push_back( raw_mof.to_ulong() & 0xff );
   return mof_item;
}

bool AsterixEncodingHelper::encode8BitAgeItem( std::vector<unsigned char>& msg, double age ) {

   const double CAT_MAX_AGE_COM = 63.75;
   const double AGE_LSB = 0.25;

   if( age < std::numeric_limits<double>::max() ) {
      if( age > CAT_MAX_AGE_COM ) {
         age = CAT_MAX_AGE_COM;
      }
      age /= AGE_LSB;
      msg.push_back( (unsigned char) age & 0xff );
      return true;
   }
   return false;
}

std::vector<unsigned char> AsterixEncodingHelper::encodeSystemTrackAges(std::shared_ptr<TrackTypeIf> track) {

   std::vector<unsigned char> age_item;
   std::vector<unsigned char> age_content; // encode the content of the item without the item fspec

   // Encode the sub items from last to the first item in order to properly set the item specific
   // local fspec
   std::bitset<8> second_fpsec_byte( 0 );

   // Encode the age items. Most of them are encoded with a resolution of 1/4 seconds and a maximum
   second_fpsec_byte[5] = encode8BitAgeItem( age_content,
      track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_MLAT ) );

   // LOP age is ignored at the moment

   // ADS-B update ages
   const double CAT_MAX_AGE_COM = 63.75;
   if( track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_ADS_B ) <= CAT_MAX_AGE_COM ) {
      // UAT age
      second_fpsec_byte[7] = encode8BitAgeItem( age_content,
         track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_ADS_B_UAT ) );
   }

   // Set the FX bit for the first fspec byte
   std::bitset<8> first_fpsec_byte( second_fpsec_byte.any() ? 1 : 0 );

   // ADS-B update ages second part
   if( track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_ADS_B ) <= CAT_MAX_AGE_COM ) {
      //VDL4 age
      first_fpsec_byte[1] = encode8BitAgeItem( age_content,
         track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_ADS_B_VDL ) );

      // ES age
      first_fpsec_byte[2] = encode8BitAgeItem( age_content,
         track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_ADS_B_ES ) );
   }

   // ADS-C age. This age needs special handling because it is encoded in a different way
   double ads_c_age = track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_ADS_C );
   if( ads_c_age < std::numeric_limits<double>::max() ) {
      const double ADS_C_MAX_AGE = 16383.75;
      if( ads_c_age > ADS_C_MAX_AGE ) {
         ads_c_age = ADS_C_MAX_AGE;
      }
      const double AGE_LSB = 0.25;

      ads_c_age *= AGE_LSB;
      // Required in this order because of the re-ordering at the end
      age_content.push_back( (int) ads_c_age & 0xff );
      age_content.push_back( ((int) ads_c_age >> 8) & 0xff );
      first_fpsec_byte[3] = true;
   }

   // MDS age
   first_fpsec_byte[4] = encode8BitAgeItem( age_content,
      track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_MDS ) );

   // SSR age
   first_fpsec_byte[5] = encode8BitAgeItem( age_content,
      track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_SSR ) );

   // PSR age
   first_fpsec_byte[6] = encode8BitAgeItem( age_content,
      track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_PSR ) );

   // Track age. This item shall always be there which currently is not enforced
   first_fpsec_byte[7] = encode8BitAgeItem( age_content,
      track->getDetectionAge( GenericEnumerations::AGE_ITEMS::DET_TRACK ) );

   // Write the item fpsec
   age_item.push_back( first_fpsec_byte.to_ulong() & 0xff );
   if( second_fpsec_byte.any() ) {
      age_item.push_back( second_fpsec_byte.to_ulong() & 0xff );
   }

   // Write the age items in opposite order into the message
   std::reverse( std::begin( age_content ), std::end( age_content ) );
   age_item.insert( age_item.end(), age_content.begin(), age_content.end() );

   return age_item;
}

std::vector<unsigned char> AsterixEncodingHelper::encodeTrackDataAges(
   std::shared_ptr<TrackTypeIf> track) {
   // Mapping of the fpsec entries to the age item. There are gap since not all items are encoded
   // This is highly CAT 62 bound. Therefore the order matters
   const std::map<unsigned, GenericEnumerations::AGE_ITEMS> age_mapping = {
      { 0, GenericEnumerations::AGE_ITEMS::DAP_MEAS_FL }, { 3, GenericEnumerations::AGE_ITEMS::DAP_MODE_3A },
      { 6, GenericEnumerations::AGE_ITEMS::DAP_MHG }, { 7, GenericEnumerations::AGE_ITEMS::NO_AGE /*FX*/},
      { 8, GenericEnumerations::AGE_ITEMS::DAP_IAS }, { 9, GenericEnumerations::AGE_ITEMS::DAP_TAS },
      { 13, GenericEnumerations::AGE_ITEMS::DAP_COM }, { 14, GenericEnumerations::AGE_ITEMS::DAP_SAB },
      { 15, GenericEnumerations::AGE_ITEMS::NO_AGE /*FX*/}, { 16, GenericEnumerations::AGE_ITEMS::DAP_ACS },
      { 17, GenericEnumerations::AGE_ITEMS::DAP_BVR }, { 18, GenericEnumerations::AGE_ITEMS::DAP_GVR },
      { 20, GenericEnumerations::AGE_ITEMS::DAP_TAR }, { 21, GenericEnumerations::AGE_ITEMS::DAP_TAN },
      { 22, GenericEnumerations::AGE_ITEMS::DAP_GSP }, { 23, GenericEnumerations::AGE_ITEMS::NO_AGE /*FX*/},
      { 26, GenericEnumerations::AGE_ITEMS::DAP_EMC }, { 27, GenericEnumerations::AGE_ITEMS::DAP_POS },
      { 28, GenericEnumerations::AGE_ITEMS::DAP_GAL }, { 30, GenericEnumerations::AGE_ITEMS::DAP_MB },
      { 31, GenericEnumerations::AGE_ITEMS::NO_AGE /*FX*/}, { 32, GenericEnumerations::AGE_ITEMS::DAP_IAR },
      { 33, GenericEnumerations::AGE_ITEMS::DAP_MAC }, { 34, GenericEnumerations::AGE_ITEMS::DAP_BPS } };

   std::vector<unsigned char> age_item;
   std::vector<unsigned char> age_content;

   // Currently there are up to five item fspec fields foreseen
   std::bitset<8> first_fspec( 0 );
   std::bitset<8> second_fspec( 0 );
   std::bitset<8> third_fspec( 0 );
   std::bitset<8> fourth_fspec( 0 );
   std::bitset<8> fith_fspec( 0 );

   // Encode all items contained in the track
   for( auto item : age_mapping ) {
      // We found an FX bit which will be skipped
      if( item.second == GenericEnumerations::AGE_ITEMS::NO_AGE ) {
         continue;
      }

      bool item_present = encode8BitAgeItem( age_content, track->getDetectionAge( item.second ) );
      unsigned fspec_pos = 7 - (item.first % 8); // Use little endian

      // Check which FSPEC octet needs to be modified
      if( item.first <= 6 ) {
         first_fspec[fspec_pos] = item_present;
      }
      else if( item.first > 7 && item.first < 15 ) {
         second_fspec[fspec_pos] = item_present;
      }
      else if( item.first > 15 && item.first < 23 ) {
         third_fspec[fspec_pos] = item_present;
      }
      else if( item.first > 23 && item.first < 31 ) {
         fourth_fspec[fspec_pos] = item_present;
      }
      else if( item.first > 31 && item.first <= 34 ) {
         fith_fspec[fspec_pos] = item_present;
      }
   }

   // Properly set the FX bit of the single fspec items and add those not empty to the message
   if( fith_fspec.any() ) {
      fourth_fspec[0] = true;
   }
   if( fourth_fspec.any() ) {
      third_fspec[0] = true;
   }
   if( third_fspec.any() ) {
      second_fspec[0] = true;
   }
   if( second_fspec.any() ) {
      first_fspec[0] = true;
   }

   // Add all FPSEC octet to the message. Make sure all FX bits on the way are set properly
   if( first_fspec.any() ) {
      age_item.push_back( first_fspec.to_ulong() & 0xff );
   }
   if( second_fspec.any() && first_fspec[0] ) {
      age_item.push_back( second_fspec.to_ulong() & 0xff );
   }
   if( third_fspec.any() && second_fspec[0] ) {
      age_item.push_back( third_fspec.to_ulong() & 0xff );
   }
   if( fourth_fspec.any() && third_fspec[0] ) {
      age_item.push_back( fourth_fspec.to_ulong() & 0xff );
   }
   if( fith_fspec.any() && fourth_fspec[0] ) {
      age_item.push_back( fith_fspec.to_ulong() & 0xff );
   }
   if( !first_fspec.any() ) { // An error occurred
      return std::vector<unsigned char>();
   }

   // Add the already encoded content to he message
   age_item.insert( age_item.end(), age_content.begin(), age_content.end() );

   return age_item;
}

std::vector<unsigned char> AsterixEncodingHelper::encodeMeasuredItems(std::shared_ptr<TrackTypeIf> track) {
   std::vector<unsigned char> meas_info;
   std::vector<unsigned char> meas_info_content; // encode the content of the item without the item fspec

   std::bitset<8> item_fspec( 0 );

   // Get the last report which updated the and which is from a radar
   bool found = false;
   DetectionEntry last_updating_report;
   for( int i = track->getDetectionListSize() - 1; i >= 0; i-- ) {
      DetectionEntry detection = track->getDetectionAt( i );

      // Check whether the report is from a conventional radar
      if( !(detection.isDummyDetection()) && detection.getDetectionType() < DetectionEntry::DET_TYPE::ADS_B ) {
         last_updating_report = detection; // Found the latest matching report
         found = true;
         break;
      }
   }

   // Encode the item
   if( found ) {
      // Sensor Identification
      int sac = last_updating_report.getSourceIDSacAt( 0 );
      int sic = last_updating_report.getSourceIDSicAt( 0 );
      meas_info_content.push_back( sac & 0xff );
      meas_info_content.push_back( sic & 0xff );
      item_fspec[7] = true; // mandatory sub field of item

      // Measured Position
      double rho = last_updating_report.getMeasuredRange();
      double theta = last_updating_report.getMeasuredAzimuth();

      int rho_encode = rho * 256; // LSB is 1/256
      int theta_encode = theta / 0.0055; // LSB is 360 / 2**16
      meas_info_content.push_back( (rho_encode >> 8) & 0xff );
      meas_info_content.push_back( rho_encode & 0xff );
      meas_info_content.push_back( (theta_encode >> 8) & 0xff );
      meas_info_content.push_back( theta_encode & 0xff );
      item_fspec[6] = true; // mandatory sub field of item

      // Measured 3-D Height
      if( last_updating_report.get3DHeight().has_value() ) {
         double meas_3d_height = last_updating_report.get3DHeight().value();
         meas_3d_height /= 25;
         int encode_3d_height = (int) meas_3d_height;

         meas_info_content.push_back( (encode_3d_height >> 8) & 0xff );
         meas_info_content.push_back( encode_3d_height & 0xff );

         item_fspec[5] = true;
      }

      // Last Measured Mode C
      if( last_updating_report.getModeC().has_value() ) {
         // check the code is within -12FL and 1270FL with an LSB of 1/4 if need be

         DetectionEntry::ModeX mode_c = last_updating_report.getModeC().value();
         std::bitset<16> mode_c_item( mode_c.getCode() );
         // Overwrite valid and gabled flag
         mode_c_item[15] = !mode_c.isValid();
         mode_c_item[14] = mode_c.isGarbled();

         int encode_mc_item = mode_c_item.to_ulong();
         meas_info_content.push_back( (encode_mc_item >> 8) & 0xff );
         meas_info_content.push_back( encode_mc_item & 0xff );

         item_fspec[4] = true;
      }

      // Last Measured Mode3A code
      if( last_updating_report.getMode3A().has_value() ) {
         DetectionEntry::ModeX mode_3a = last_updating_report.getMode3A().value();
         std::bitset<16> mode_3a_item( mode_3a.getCode() );
         // Overwrite valid and gabled flag
         mode_3a_item[15] = !mode_3a.isValid();
         mode_3a_item[14] = mode_3a.isGarbled();
         mode_3a_item[13] = false; // L bit not read at the moment

         int encode_3a_item = mode_3a_item.to_ulong();
         meas_info_content.push_back( (encode_3a_item >> 8) & 0xff );
         meas_info_content.push_back( encode_3a_item & 0xffff );

         item_fspec[3] = true;
      }

      // Report type, is always present if parent item is present
      std::bitset<8> report_type( 0 );

      //encode the single bits. The different types of Roll Calls are not stored at the moment
      DetectionEntry::DET_TYPE detection = last_updating_report.getDetectionType();
      report_type[7] =
         (detection == DetectionEntry::DET_TYPE::MDS || detection == DetectionEntry::DET_TYPE::CMB_MDS);
      report_type[6] =
         (detection == DetectionEntry::DET_TYPE::SSR || detection == DetectionEntry::DET_TYPE::CMB_MDS ||
            detection == DetectionEntry::DET_TYPE::CMB);
      report_type[5] = (detection == DetectionEntry::DET_TYPE::PSR || detection == DetectionEntry::DET_TYPE::CMB ||
         detection == DetectionEntry::DET_TYPE::CMB_MDS);

      // SIM
      report_type[4] = false; // Real target

      // RAB bit
      report_type[3] = false; // No FFT

      // TST bit
      report_type[2] = false; // No Test target

      // Bit 6 and 7 are spare bits

      meas_info_content.push_back( report_type.to_ulong() & 0xff );
      item_fspec[2] = true;
   }

   // Write all bytes into the final item to be returned
   meas_info.push_back( item_fspec.to_ulong() & 0xff );
   meas_info.insert( meas_info.end(), meas_info_content.begin(), meas_info_content.end() );

   return meas_info;
}

std::vector<unsigned char> AsterixEncodingHelper::eoncodeAircraftDerivedData(
   std::shared_ptr<TrackTypeIf> track) {

   // Map the ADD item to the sub item fspec. In case the map comparator changes over time one
   // has to create a new one to make sure the order is correct.
   const std::map<unsigned, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES> add_item_mapping =
      {
         { 0, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::ADR },
         { 1, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::ID },
         { 2, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MHG },
         { 3, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::IAS },
         { 4, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TAS },
         { 5, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::SAL },
         { 6, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::FSS },/*FX,*/
         { 7, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TIS },
         { 8, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TID },
         { 9, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::COM },
         { 10, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::SAB },
         { 11, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::ACS },
         { 12, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::BVR },
         { 13, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::GVR },/*FX,*/
         { 14, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::RAN },
         { 15, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TAR },
         { 16, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TAN },
         { 17, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::GSP },
         { 18, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::VUN },
         { 19, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MET },
         { 20, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::EMC }, /*FX,*/
         { 21, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::POS },
         { 22, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::GAL },
         { 23, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::PUN },
         { 24, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MB },
         { 25, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::IAR },
         { 26, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MAC },
         { 27, GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::BPS }
      };

   std::vector<unsigned char> add_info;
   std::vector<unsigned char> add_info_content;

   // reserve one byte per sub item fspec.
   std::bitset<8> first_fspec( 0 );
   std::bitset<8> second_fspec( 0 );
   std::bitset<8> third_fspec( 0 );
   std::bitset<8> fourth_fspec( 0 );

   for( auto add_item : add_item_mapping ) {
      unsigned fspec_pos = 7 - (add_item.first % 7);
      switch( add_item.second ){
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::ADR: { // Aircraft Address
            if( track->isADItemPresent( add_item.second ) ) {
               unsigned addres_value = -track->getADItem( add_item.second )->getIntegerValue();
               // Encode whenever it is clear how the ADR is stored
               add_info_content.push_back( addres_value >> 16 & 0xff );
               add_info_content.push_back( addres_value >> 8 & 0xff );
               add_info_content.push_back( addres_value & 0xff );
               first_fspec[fspec_pos] = true;
            }
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::ID: {
            // Currently skipped
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MHG: {
            if( track->isADItemPresent( add_item.second ) ) {
               double mhg_calue = track->getADItem( add_item.second )->getDoubleValue();
               // convert to the correct LSB
               unsigned encode_value = mhg_calue / 0.0055;
               add_info_content.push_back( encode_value >> 8 & 0xff );
               add_info_content.push_back( encode_value & 0xff );
               first_fspec[fspec_pos] = true;
            }
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::IAS: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TAS: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::SAL: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::FSS: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TIS: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TID: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::COM: {
            if( track->isADItemPresent( add_item.second ) ) {
               std::bitset<8> com_item( track->getADItem( add_item.second )->getIntegerValue() );
               com_item <<= 5; // Shift to the correct position
               bool spi = track->isADItemPresent( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::SPI ) &&
                  track->getADItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::SPI )->getBooleanValue();
               // Set alert and SPI
               com_item[4] = false; // STAT not yet handled
               com_item[3] = false;
               com_item[2] = spi;
               add_info_content.push_back( com_item.to_ulong() & 0xff );
               add_info_content.push_back( 0 );
               second_fspec[fspec_pos] = true;
            }
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::SAB: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::ACS: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::BVR: {
            if( track->isADItemPresent( add_item.second ) ) {
               double rate = track->getADItem( add_item.second )->getDoubleValue();
               std::vector<unsigned char> item = AsterixEncodingHelper::encodeRateCD( rate );
               if( item.size() == 2 ) {
                  add_info_content.insert( add_info_content.end(), item.begin(), item.end() );
                  second_fspec[fspec_pos] = true;
               }
            }
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::GVR: {
            if( track->isADItemPresent( add_item.second ) ) {
               double rate = track->getADItem( add_item.second )->getDoubleValue();
               std::vector<unsigned char> item = AsterixEncodingHelper::encodeRateCD( rate );
               if( item.size() == 2 ) {
                  add_info_content.insert( add_info_content.end(), item.begin(), item.end() );
                  second_fspec[fspec_pos] = true;
               }
            }
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::RAN: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TAR: {
            if( track->isADItemPresent( add_item.second ) ) {
               std::bitset<16> byte_item( track->getADItem( add_item.second )->getDoubleValue() );
               byte_item <<= 1;
               add_info_content.push_back( byte_item.to_ulong() >> 8 & 0xff );
               add_info_content.push_back( byte_item.to_ulong() & 0xff );
               third_fspec[fspec_pos] = true;
            }
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TAN: {
            if( track->isADItemPresent( add_item.second ) ) {
               // Use the track angle from the DAP structure and not the track heading. The track
               // angle might differ from the heading
               double tan_item = track->getADItem( add_item.second )->getDoubleValue();
               // convert to the correct LSB
               unsigned encode_value = tan_item / 0.0055;
               add_info_content.push_back( encode_value >> 8 & 0xff );
               add_info_content.push_back( encode_value & 0xff );
               third_fspec[fspec_pos] = true;
            }
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::GSP: {
            if( track->isADItemPresent( add_item.second ) ) {
               // The GSP from the last report is used instead of the GSP from the track state
               double gsp = track->getADItem( add_item.second )->getDoubleValue();
               // convert to the correct LSB
               unsigned encode_value = gsp / 0.22; // LSB is 0.22 kt
               add_info_content.push_back( encode_value >> 8 & 0xff );
               add_info_content.push_back( encode_value & 0xff );
               third_fspec[fspec_pos] = true;
            }
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::VUN: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MET: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::EMC: {
            if( track->isADItemPresent( add_item.second ) ) {
               int emc = track->getADItem( add_item.second )->getIntegerValue();
               if( emc > 0 && emc < 22 ) { // Ensure ranges
                  add_info_content.push_back( emc & 0xff );
                  third_fspec[fspec_pos] = true;
               }
            }
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::POS: {
            if( track->isADItemPresent( add_item.second ) ) {
               std::vector<double> pos = std::static_pointer_cast<AircraftDerivedDataItemExtended>(
                  track->getADItem( add_item.second ) )->getDoubleValues();

               if( pos.size() != 2 ) {
                  break;
               }

               double lat = pos[0]; // POS_LAT;
               double lng = pos[1]; // POS?LNG

               std::vector<unsigned char> position =
                  AsterixEncodingHelper::encodePositionWGS6Byte( lat, lng );
               if( position.size() == 6 ) {
                  //add_info_content.push_back( emc&0xff );
                  add_info_content.insert( add_info_content.end(), position.begin(),
                     position.end() );
                  fourth_fspec[fspec_pos] = true;
               }
            }
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::GAL: {
            if( track->isADItemPresent( add_item.second ) ) {
               std::vector<unsigned char> gal_encoded =
                  encodeGeoAltitude( track->getADItem( add_item.second )->getDoubleValue() );
               if( gal_encoded.size() == 2 ) { // Ensure size of returned bytes
                  add_info_content.insert( add_info_content.end(), gal_encoded.begin(),
                     gal_encoded.end() );
                  fourth_fspec[fspec_pos] = true;
               }
            }
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::PUN: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MB: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::IAR: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MAC: {
            // Currently not encoded
            break;
         }
         case GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::BPS: {
            // Currently not encoded
            break;
         }
         default: {
            // Sink for all ADD items not part of this Asterix item
            break;
         }
      }
      // end switch
   } // end loop

   // Encode the sub item FSPEC FX bits
   third_fspec[0] = fourth_fspec.any();
   second_fspec[0] = third_fspec.any();
   first_fspec[0] = second_fspec.any();

   // Add everything to the message
   if( first_fspec.any() ) {
      add_info.push_back( first_fspec.to_ulong() & 0xff );
   }
   if( second_fspec.any() ) {
      add_info.push_back( second_fspec.to_ulong() & 0xff );
   }
   if( third_fspec.any() ) {
      add_info.push_back( third_fspec.to_ulong() & 0xff );
   }
   if( fourth_fspec.any() ) {
      add_info.push_back( fourth_fspec.to_ulong() & 0xff );
   }

   add_info.insert( add_info.end(), add_info_content.begin(), add_info_content.end() );
   return add_info;
}
