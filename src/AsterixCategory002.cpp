/**
 * @file AsterixCategory002.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 23 Jun 2017
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
 * See .h file for more informations
 */

// Asterix includes
#include "AsterixCategory002.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemVariableLength.h"
#include "AsterixItemRepetetive.h"
#include "AsterixSubitemUnsigned.h"
#include "AsterixSubitemBitNamed.h"
#include "Cat002ItemNames.h"
#include "AsterixEncodingHelper.h"

// Converter
#include "CommonConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

#include <cstdint>
#include <cmath>

AsterixCategory002::~AsterixCategory002() {
}

AsterixCategory002::AsterixCategory002() :
   AsterixCategory( 2 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory002::AsterixCategory002( int length ) :
   AsterixCategory( 2, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory002::AsterixCategory002( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 2, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

void AsterixCategory002::setUAP() {
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat002ItemNames::I002_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat002ItemNames::I002_000, 1 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat002ItemNames::I002_020, 1 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat002ItemNames::I002_030, 3 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat002ItemNames::I002_041, 2 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemVariableLength>( Cat002ItemNames::I002_050 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemVariableLength>( Cat002ItemNames::I002_060 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemRepetetive>( Cat002ItemNames::I002_070, 2 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat002ItemNames::I002_100, 8 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat002ItemNames::I002_090, 2 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemVariableLength>( Cat002ItemNames::I002_080 ) ) );
   // FRN 12, 13, and 14 are spare
}

void AsterixCategory002::setSubitems() {
   //Sensor Identification
   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat002ItemNames::I002_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   sensor_identification.push_back(
      subitem_t( Cat002ItemNames::I002_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   // Message Type
   subitem_map_t report_typr;
   report_typr.push_back(
      subitem_t( Cat002ItemNames::I002_000_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   // Sector Number
   subitem_map_t sector_number;
   sector_number.push_back(
      subitem_t( Cat002ItemNames::I002_020_SCT,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::CircleSegment8Bit::get() ) ) );

   // Time of Day
   subitem_map_t time_of_day;
   time_of_day.push_back(
      subitem_t( Cat002ItemNames::I002_030_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::Fraction128th::get() ) ) );

   // Antenna Rotation Period
   subitem_map_t antenna_rotation;
   antenna_rotation.push_back(
      subitem_t( Cat002ItemNames::I002_041_ROT,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::Fraction128th::get() ) ) );

   // Station Configuration
   subitem_map_t station_configuration;
   station_configuration.push_back(
      subitem_t( Cat002ItemNames::I002_050_CNF,
         std::make_shared<AsterixSubitemBase>( 8, CommonConverter::NoneConverter::get() ) ) );

   // Station Configuration
   subitem_map_t plot_count;
   plot_count.push_back(
      subitem_t( Cat002ItemNames::I002_070_A,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Antenna 1" }, { 1,
               "Antenna 2" } } ) ) ) );
   plot_count.push_back(
      subitem_t( Cat002ItemNames::I002_070_ID,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter::get() ) ) );
   plot_count.push_back(
      subitem_t( Cat002ItemNames::I002_070_CNT,
         std::make_shared<AsterixSubitemUnsigned>( 10, CommonConverter::NoneConverter::get() ) ) );

   // Collimation Error
   subitem_map_t error;
   // Only 8 bit but spec calculates with 16 bit ???????
   error.push_back(
      subitem_t( Cat002ItemNames::I002_090_AZM,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::CircleSegment16Bit::get() ) ) );
   error.push_back(
      subitem_t( Cat002ItemNames::I002_090_RNG,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction128th::get() ) ) );

   // Dynamic Window
   subitem_map_t window;
   window.push_back(
      subitem_t( Cat002ItemNames::I002_100_RHS,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::Fraction128th::get() ) ) );
   window.push_back(
      subitem_t( Cat002ItemNames::I002_100_RHE,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::Fraction128th::get() ) ) );
   window.push_back(
      subitem_t( Cat002ItemNames::I002_100_THS,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::CircleSegment16Bit::get() ) ) );
   window.push_back(
      subitem_t( Cat002ItemNames::I002_100_THE,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::CircleSegment16Bit::get() ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, report_typr ) );
   subitems.insert( subitem_map_item_t( 3, sector_number ) );
   subitems.insert( subitem_map_item_t( 4, time_of_day ) );
   subitems.insert( subitem_map_item_t( 5, antenna_rotation ) );
   subitems.insert( subitem_map_item_t( 6, station_configuration ) );
   subitems.insert( subitem_map_item_t( 8, plot_count ) );
   subitems.insert( subitem_map_item_t( 9, window ) );
   subitems.insert( subitem_map_item_t( 10, error ) );
}

void AsterixCategory002::fillRecord(std::shared_ptr<ReportRecordType> record) {
   int sac, sic;
   try {
      sac = atoi( getValue( "I001/010#SAC" ).c_str() );
      sic = atoi( getValue( "I001/010#SIC" ).c_str() );
   } catch (const std::out_of_range& e) {
      sac = 0; //not valid
      sic = 0; // not valid
   }
   record->setSource( sac, sic );
}

void AsterixCategory002::setDataSource(unsigned short sac, unsigned short sic) {
   unrolled_values[Cat002ItemNames::I002_010_SAC] = std::to_string( sac );
   unrolled_values[Cat002ItemNames::I002_010_SIC] = std::to_string( sic );
}

void AsterixCategory002::setMessageType(SensorServiceRecordType::MESSAGETYPE type) {
   unrolled_values[Cat002ItemNames::I002_000_TYP] = std::to_string( static_cast<unsigned int>( type ) );
}

void AsterixCategory002::setSectorNumber(unsigned short number) {
   unrolled_values[Cat002ItemNames::I002_020_SCT] = std::to_string( number );
}

void AsterixCategory002::setTimeOfDay(double time) {
   float lsb = 1.0 / 128.0;
   unrolled_values[Cat002ItemNames::I002_030_TOD] = std::to_string( time * lsb );
}

void AsterixCategory002::setAntennaRotationPeriod(double period) {
   float lsb = 1.0 / 128.0;
   unrolled_values[Cat002ItemNames::I002_041_ROT] = std::to_string( period * lsb );
}

void AsterixCategory002::setDynamicWindow(double rho_start, double rho_end, double theta_start, double theta_end) {
   float rho_lsb = 1.0 / 128.0;
   float theta_lsb = 0.0055;
   unrolled_values[Cat002ItemNames::I002_100_RHS] = std::to_string( rho_start / rho_lsb );
   unrolled_values[Cat002ItemNames::I002_100_RHE] = std::to_string( rho_end / rho_lsb );
   unrolled_values[Cat002ItemNames::I002_100_THS] = std::to_string( theta_start / theta_lsb );
   unrolled_values[Cat002ItemNames::I002_100_THE] = std::to_string( theta_end / theta_lsb );
}

void AsterixCategory002::setCollimationError(double range, double azimuth) {
   float rho_lsb = 1.0 / 128.0;
   float theta_lsb = 0.0055;
   unrolled_values[Cat002ItemNames::I002_090_RNG] = std::to_string( range / rho_lsb );
   unrolled_values[Cat002ItemNames::I002_090_AZM] = std::to_string( azimuth / theta_lsb );
}

void AsterixCategory002::setWarningError(unsigned int value) {
   unrolled_values[Cat002ItemNames::I002_080] = std::to_string( value );
}

void AsterixCategory002::resetPlotCount() {
   // TODO not implemented yet
}

void AsterixCategory002::addPlotCount(bool antenna1, unsigned short identifier, unsigned short counter) {
   // TODO not implemented yet
}

std::vector<unsigned char> AsterixCategory002::getEncodedMessage(SensorServiceRecordType record,
   std::map<std::string, bool> items_to_be_served) {
   std::vector<unsigned char> message;
   std::vector<unsigned char> header;

   // The track UAP is in use here
   for( auto item : fpsec_item_name_map ) {
      // Reset the FSPEC for this item
      fspec[item.first] = false;

      // I002/010 Data Source Identifier
      if( item.second == Cat002ItemNames::I002_010 ) { // Mandatory.
         std::tuple<unsigned int, unsigned int> sensor_id = record.getSensorId();
         unsigned int sac = std::get<0>( sensor_id );
         unsigned int sic = std::get<1>( sensor_id );
         // check if items have been set via the dedicated setter which have priority
         if( isItemPresent( Cat002ItemNames::I002_010_SAC ) && isItemPresent( Cat002ItemNames::I002_010_SIC ) ) {
            sac = std::atoi( getValue( Cat002ItemNames::I002_010_SAC ).c_str() );
            sic = std::atoi( getValue( Cat002ItemNames::I002_010_SIC ).c_str() );
         }
         std::vector<unsigned char> sac_sic = AsterixEncodingHelper::encodeSACSIC16Bit( sac, sic );

         // item is present
         if( sac_sic.size() == 2 ) {
            fspec[item.first] = true;
            message.insert( message.end(), sac_sic.begin(), sac_sic.end() );
         }
      }

      // I002/000 Message Type
      if( item.second == Cat002ItemNames::I002_000 ) { // Mandatory.
         unsigned short type = std::numeric_limits<unsigned short>::infinity();
         if( isItemPresent( Cat002ItemNames::I002_000_TYP ) ) {
            type = std::atoi( getValue( Cat002ItemNames::I002_000_TYP ).c_str() );
         } else if( record.isMessageTypePresent() ) {
            type = record.getMessageType();
         } else {
            // error
            continue;
         }
         fspec[item.first] = true;
         message.push_back( type & 0xff );
      }

      // I002/020 Sector Number
      if( item.second == Cat002ItemNames::I002_020
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         float lsb = 1.41;
         float sector_number = std::numeric_limits<float>::infinity();
         if( isItemPresent( Cat002ItemNames::I002_020_SCT ) ) {
            sector_number = std::atof( getValue( Cat002ItemNames::I002_020_SCT ).c_str() );
         } else if( record.isSectorNumberPresent() ) {
            sector_number = record.getSectorNumber();
         } else {
            // error
            continue;
         }
         sector_number = sector_number / lsb;
         fspec[item.first] = true;
         message.push_back( std::lround( sector_number ) & 0xff );
      }

      // I002/030 Time of Day
      if( item.second == Cat002ItemNames::I002_030
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         float lsb = 1.0 / 128.0;
         double tod = std::numeric_limits<float>::infinity();
         if( isItemPresent( Cat002ItemNames::I002_030_TOD ) ) {
            tod = std::atof( getValue( Cat002ItemNames::I002_030_TOD ).c_str() );
         } else {
            tod = record.getTimeOfDay() / lsb;
         }

         fspec[item.first] = true;
         uint_fast64_t tod_out = tod;
         message.push_back( (tod_out >> 16) & 0xff );
         message.push_back( (tod_out >> 8) & 0xff );
         message.push_back( tod_out & 0xff );
      }

      // I002/041 Antenna Rotation Period
      if( item.second == Cat002ItemNames::I002_041
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         float lsb = 1.0 / 128.0;
         double rotation = std::numeric_limits<float>::infinity();
         if( isItemPresent( Cat002ItemNames::I002_041_ROT ) ) {
            rotation = std::atof( getValue( Cat002ItemNames::I002_041_ROT ).c_str() );
         } else if( record.isAntennaSpeedPresent() ) {
            rotation = record.getAntennaSpeed();
            rotation /= lsb;
         } else {
            // error
            continue;
         }

         fspec[item.first] = true;
         uint_fast64_t rot = rotation;
         message.push_back( (rot >> 8) & 0xff );
         message.push_back( rot & 0xff );
      }

      // Items I002/050 and I002/060 are not encoded
      // I002/070 Plot Count Values
      if( item.second == Cat002ItemNames::I002_070
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         // Add the repetition counter to the message
         message.push_back( record.getPlotCount().size() & 0xff );
         for( auto plot_count : record.getPlotCount() ) {
            uint16_t value = plot_count.getAntenna();
            value <<= 5;
            value |= (plot_count.getIdent() & 0x1f);
            value <<= 10;
            value |= (plot_count.getCounter() & 0x3ff);
            message.push_back( (value >> 8) & 0xff );
            message.push_back( value & 0xff );
         }
         fspec[item.first] = true;
      }

      // I002/100 Dynamic Window
      if( item.second == Cat002ItemNames::I002_100
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         //
         std::vector<unsigned char> tmp_item;
         if( isItemPresent( Cat002ItemNames::I002_100_RHS ) ) {
            uint16_t rhs = std::atoi( getValue( Cat002ItemNames::I002_100_RHS ).c_str() );
            tmp_item.push_back( (rhs >> 8) & 0xff );
            tmp_item.push_back( rhs & 0xff );
         }
         if( isItemPresent( Cat002ItemNames::I002_100_RHE ) ) {
            uint16_t rhe = std::atoi( getValue( Cat002ItemNames::I002_100_RHE ).c_str() );
            tmp_item.push_back( (rhe >> 8) & 0xff );
            tmp_item.push_back( rhe & 0xff );
         }
         if( isItemPresent( Cat002ItemNames::I002_100_THS ) ) {
            uint16_t theta_s = std::atoi( getValue( Cat002ItemNames::I002_100_THS ).c_str() );
            tmp_item.push_back( (theta_s >> 8) & 0xff );
            tmp_item.push_back( theta_s & 0xff );
         }
         if( isItemPresent( Cat002ItemNames::I002_100_THE ) ) {
            uint16_t theta_e = std::atoi( getValue( Cat002ItemNames::I002_100_THE ).c_str() );
            tmp_item.push_back( (theta_e >> 8) & 0xff );
            tmp_item.push_back( theta_e & 0xff );
         }

         // write item to message only if all bytes have been set
         if( tmp_item.size() == 8 ) {
            message.insert( message.end(), tmp_item.begin(), tmp_item.end() );
            fspec[item.first] = true;
         }
      }

      //I002/090 Collimation Error
      if( item.second == Cat002ItemNames::I002_090
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         std::vector<unsigned char> tmp_item;

         if( isItemPresent( Cat002ItemNames::I002_090_RNG ) ) {
            uint8_t range = std::atoi( getValue( Cat002ItemNames::I002_090_RNG ).c_str() );
            tmp_item.push_back( range & 0xff );
         }
         if( isItemPresent( Cat002ItemNames::I002_090_AZM ) ) {
            uint8_t azimuth = std::atoi( getValue( Cat002ItemNames::I002_090_AZM ).c_str() );
            tmp_item.push_back( azimuth & 0xff );
         }

         if( tmp_item.size() == 2 ) {
            message.insert( message.end(), tmp_item.begin(), tmp_item.end() );
            fspec[item.first] = true;
         }
      }

      //I002/080 Warning/Error Conditions
      if( item.second == Cat002ItemNames::I002_080
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( isItemPresent( Cat002ItemNames::I002_080 ) ) {
            uint8_t error = std::atoi( getValue( Cat002ItemNames::I002_080 ).c_str() );
            // Set the FX bit to 0
            error <<= 1;
            error |= (1 & 0x01);
            message.push_back( error & 0xff );
            fspec[item.first] = true;
         }
      }
   }

   // add header to message
   getHeader( header, message.size() );
   message.insert( message.begin(), header.begin(), header.end() );
   return message;
}
