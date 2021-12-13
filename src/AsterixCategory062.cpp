/**
 * @file AsterixCategory062.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 20 Mar 2016
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
 * See description of header file for more details
 */

// project includes
#include "AsterixCategory062.h"
#include "AsterixEncodingHelper.h"
#include "AsterixExceptions.h"
#include "AsterixItemCompound.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemVariableLength.h"
#include "AsterixItemExtendible.h"
#include "AsterixItemRepetetive.h"
#include "Cat062ItemNames.h"

// Converter
#include "CommonConverter.h"

// general includes
#include <bitset>
#include <string>

AsterixCategory062::AsterixCategory062() :
   AsterixCategory( 62 ) {
   // Init the calling Asterix Category
   initCategory();

   // initiate the service related stuff already known
   service_related_values["I062/080#DET_AGE"] = std::to_string( DETECTION_TYPE_MAX_AGE );
}

AsterixCategory062::~AsterixCategory062() {
}

void AsterixCategory062::setUAP() {
   // Define the sub UAPs from the compound items
   AsterixItemCompound::subUap_T item_380_sub_uap;
   AsterixItemCompound::subUap_T item_290_sub_uap;
   AsterixItemCompound::subUap_T item_295_sub_uap;
   AsterixItemCompound::subUap_T item_390_sub_uap;
   AsterixItemCompound::subUap_T item_110_sub_uap;
   AsterixItemCompound::subUap_T item_500_sub_uap;
   AsterixItemCompound::subUap_T item_340_sub_uap;

   //Define the Cat 062 UAP
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_010, 2 ) ) );
   // FRN two is not used
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_015, 1 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_070, 3 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_105, 8 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_100, 6 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_185, 4 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_210, 2 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_060, 2 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_245, 7 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_380, item_380_sub_uap ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_040, 2 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemVariableLength>( Cat062ItemNames::I062_080 ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_290, item_290_sub_uap ) ) );
   uap.insert( UAP_Item_T( 15, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_200, 1 ) ) );
   uap.insert( UAP_Item_T( 16, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_295, item_295_sub_uap ) ) );
   uap.insert( UAP_Item_T( 17, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_136, 2 ) ) );
   uap.insert( UAP_Item_T( 18, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_130, 2 ) ) );
   uap.insert( UAP_Item_T( 19, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_135, 2 ) ) );
   uap.insert( UAP_Item_T( 20, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_220, 2 ) ) );
   uap.insert( UAP_Item_T( 21, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_390, item_390_sub_uap ) ) );
   uap.insert( UAP_Item_T( 22, std::make_shared<AsterixItemVariableLength>( Cat062ItemNames::I062_270 ) ) );
   uap.insert( UAP_Item_T( 23, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_300, 1 ) ) );
   uap.insert( UAP_Item_T( 24, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_110, item_110_sub_uap ) ) );
   uap.insert( UAP_Item_T( 25, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_120, 2 ) ) );
   uap.insert( UAP_Item_T( 26, std::make_shared<AsterixItemExtendible>( Cat062ItemNames::I062_510, 3 ) ) );
   uap.insert( UAP_Item_T( 27, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_500, item_500_sub_uap ) ) );
   uap.insert( UAP_Item_T( 28, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_340, item_340_sub_uap ) ) );
   // FRN 29 to 33 not used
   uap.insert( UAP_Item_T( 34, std::make_shared<AsterixItemRepetetive>( Cat062ItemNames::I062_RE, 3 ) ) );
   uap.insert( UAP_Item_T( 35, std::make_shared<AsterixItemRepetetive>( Cat062ItemNames::I062_SP, 1 ) ) );
}

void AsterixCategory062::setSubitems() {

}

std::vector<unsigned char> AsterixCategory062::getEncodedMessage(std::shared_ptr<TrackTypeIf> track,
   std::map<std::string, bool> items_to_be_served, std::shared_ptr<AsterixItemMaxAges> max_ages) {

   std::vector<unsigned char> message;
   std::vector<unsigned char> header;

   // Encode all items. Note that the order of the items is of importance and must match the UAP
   for( auto item : fpsec_item_name_map ) {
      // Reset the FSPEC for this item
      fspec[item.first] = false;

      if( item.second == Cat062ItemNames::I062_010 ) { // Mandatory. Maybe force transmission of this item
         std::vector<unsigned char> sac_sic = AsterixEncodingHelper::encodeSACSIC16Bit(
         non_track_related_values[Cat062ItemNames::I062_010_SAC],
         non_track_related_values[Cat062ItemNames::I062_010_SIC] );

         // item is present
         if( sac_sic.size() == 2 ) {
            fspec[item.first] = true;
            message.insert( message.end(), sac_sic.begin(), sac_sic.end() );
         }
      }

      // I062/015 Service Identification
      if( item.second == Cat062ItemNames::I062_015 ) {
         // This item must be present
      message.push_back( non_track_related_values[Cat062ItemNames::I062_015] );
         fspec[item.first] = true;
      }

      // I062/040 Track number
      if( item.second == Cat062ItemNames::I062_040 ) { // This item is present since it is mandatory
         std::vector<unsigned char> track_number = AsterixEncodingHelper::encodeTrackNumber16Bit(
            track->getTrackNumber() );

         if( track_number.size() == 2 ) {
            message.insert( message.end(), track_number.begin(), track_number.end() );
            fspec[item.first] = true;
         }
      }

      // I062/060 Track Mode 3A code
      if( item.second == Cat062ItemNames::I062_060
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         if( track->getMode3A().has_value() ) {
            DetectionEntry::ModeX mode_3A = track->getMode3A().value();
            // 2 Byte
            std::vector<unsigned char> track_m3A = AsterixEncodingHelper::encodeTrackMode3A(
               mode_3A.getCode(), mode_3A.isValid(), mode_3A.isGarbled() );

            if( track_m3A.size() == 2 ) {
               message.insert( message.end(), track_m3A.begin(), track_m3A.end() );
               fspec[item.first] = true;
            }
         }
      }

      // I062/070 Time of track information
      if( item.second == Cat062ItemNames::I062_070 ) { // mandatory item

         std::vector<unsigned char> track_time = AsterixEncodingHelper::encodeTimeOfTrackInfo24Bit(
            track->getLastUpdatingTime() );

         if( track_time.size() == 3 ) {
            message.insert( message.end(), track_time.begin(), track_time.end() );
            fspec[item.first] = true;
         }
         else {
            throw MandatoryItemMissing( "AsterixCategory062::getEncodedMessage", "I062/070" );
         }
      }

      // I062/080 Track Status
      if( item.second == Cat062ItemNames::I062_080 ) { // This item is mandatory

         std::map<std::string, bool> track_live;
         track_live["TSE"] = service_related_values[Cat062ItemNames::I062_080_TSE] == "1";
         track_live["TSB"] = service_related_values[Cat062ItemNames::I062_080_TSB] == "1";

         std::vector<unsigned char> track_status = AsterixEncodingHelper::encodeTrackStatus( track,
            atof( service_related_values[Cat062ItemNames::I062_080_CNF].c_str() ), max_ages, track_live );

         message.insert( message.end(), track_status.begin(), track_status.end() );
         fspec[item.first] = true;
      }

      // We skip the Cartesian items since those are too small to properly store the information

      // I062/105 Calculated Position In WGS-84 Co-ordinates
      if( item.second == Cat062ItemNames::I062_105
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> position_wgs = AsterixEncodingHelper::encodePositionWG( track );

         if( position_wgs.size() == 8 ) {
            message.insert( message.end(), position_wgs.begin(), position_wgs.end() );
            fspec[item.first] = true;
         }
      }

      // Items I062/110 Mode 5 Data, I062/120 Mode 3 data are skipped

      // I062/130 Calculated Track Geometric Altitude
      if( item.second == Cat062ItemNames::I062_130
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> geometric_alt =
            AsterixEncodingHelper::encodeGeoAltitude( track );

         if( geometric_alt.size() == 2 ) {
            message.insert( message.end(), geometric_alt.begin(), geometric_alt.end() );
            fspec[item.first] = true;
         }
      }

      // Item I062/135 Calculated Track Barometric Altitude
      if( item.second == Cat062ItemNames::I062_135
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> baro_alt =
            AsterixEncodingHelper::encodeBaroAltitude( track->getBaroAltitude(), 0 );
         if( baro_alt.size() == 2 ) {
            message.insert( message.end(), baro_alt.begin(), baro_alt.end() );
            fspec[item.first] = true;
         }
      }
      // Item I062/136, Measured Flight Level
      if( item.second == Cat062ItemNames::I062_136
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         if( track->getModeC().has_value() ) {
            std::vector<unsigned char> baro_alt =
               AsterixEncodingHelper::encodeBaroAltitude( (track->getModeC().value().getCode() * 25) / 100, -1 );

            if( baro_alt.size() == 2 ) {
               message.insert( message.end(), baro_alt.begin(), baro_alt.end() );
               fspec[item.first] = true;
            }
         }
      }

      // Items I062/185 Cartesian Velocity not encoded

      // Item I062/200 Mode of Movement
      if( item.second == Cat062ItemNames::I062_200
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> mof =
            AsterixEncodingHelper::encodeMOF8Bit( track );

         if( mof.size() == 1 ) {
            message.insert( message.end(), mof.begin(), mof.end() );
            fspec[item.first] = true;
         }
      }

      // Item I062/210, Calculated Acceleration (Cartesian) not encoded

      // Item I062/220, Calculated Rate Of Climb/Descent
      if( item.second == Cat062ItemNames::I062_220
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> rate_cd =
            AsterixEncodingHelper::encodeRateCD( track->getRateOfCD() );

         if( rate_cd.size() == 2 ) {
            message.insert( message.end(), rate_cd.begin(), rate_cd.end() );
            fspec[item.first] = true;
         }
      }

      // Item I062/245, Target Identification. This item shall not be encoded

      // Item I062/270, Target Size & Orientation. This item is currently not decoded

      // Item I062/290, System Track Update Ages
      if( item.second == Cat062ItemNames::I062_290
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> track_ages =
            AsterixEncodingHelper::encodeSystemTrackAges( track );

         if( track_ages.size() > 1 ) { // one byte compound item fpsec and at least one data item
            message.insert( message.end(), track_ages.begin(), track_ages.end() );
            fspec[item.first] = true;
         }
      }

      // Item I062/295, Track Data Ages
      if( item.second == Cat062ItemNames::I062_295
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> data_ages =
            AsterixEncodingHelper::encodeTrackDataAges( track );

         if( data_ages.size() > 1 ) { // one byte compound item fpsec and at least one data item
            message.insert( message.end(), data_ages.begin(), data_ages.end() );
            fspec[item.first] = true;
         }
      }

      // I062/300, Vehicle Fleet Identification. NOt encoded at the moment

      //Item I062/340, Measured Information
      if( item.second == Cat062ItemNames::I062_340
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> measured_info = AsterixEncodingHelper::encodeMeasuredItems( track );

         if( measured_info.size() > 1 ) { // one byte compound item fpsec and at least one data item
            message.insert( message.end(), measured_info.begin(), measured_info.end() );
            fspec[item.first] = true;
         }

      }

      // Item I062/380, Aircraft Derived Data
      if( item.second == Cat062ItemNames::I062_380
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> add_data = AsterixEncodingHelper::eoncodeAircraftDerivedData( track );

         if( add_data.size() > 1 ) { // one byte compound item fpsec and at least one data item
            message.insert( message.end(), add_data.begin(), add_data.end() );
            fspec[item.first] = true;
         }

      }

      // Item I062/390, Flight Plan Related Data NOt encoded at the moment

      // Item I062/500, Estimated Accuracies TOBE DONE as soon as the accuracies are available

      // Item I062/510, Composed Track Number. This item makes no sense currently

      // Item I062/RE

      // Item I062/SP list of TRIs of sensor contributed since last transmission
      if( item.second == Cat062ItemNames::I062_SP
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {

      }
   }

   // add header to message
   getHeader( header, message.size() );
   message.insert( message.begin(), header.begin(), header.end() );

   return message;
}

void AsterixCategory062::setNonTrackRelatedValues(std::map<std::string, unsigned char> v) {
   non_track_related_values = v;
}

void AsterixCategory062::setServiceRelatedValue(std::string name, std::string value) {
   service_related_values[name] = value;
}

void AsterixCategory062::fillRecord(std::shared_ptr<ReportRecordType> record) {

}
