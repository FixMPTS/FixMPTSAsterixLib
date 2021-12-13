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
#include "Cat002ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

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
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sensor_identification.push_back(
      subitem_t( Cat002ItemNames::I002_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   // Message Type
   subitem_map_t report_typr;
   report_typr.push_back(
      subitem_t( Cat002ItemNames::I002_000_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   // Sector Number
   subitem_map_t sector_number;
   sector_number.push_back(
      subitem_t( Cat002ItemNames::I002_020_SCT,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::circleSegment8Bit ) ) );

   // Time of Day
   subitem_map_t time_of_day;
   time_of_day.push_back(
      subitem_t( Cat002ItemNames::I002_030_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   // Antenna Rotation Period
   subitem_map_t antenna_rotation;
   antenna_rotation.push_back(
      subitem_t( Cat002ItemNames::I002_041_ROT,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::fraction128th ) ) );

   // Station Configuration
   subitem_map_t station_configuration;
   station_configuration.push_back(
      subitem_t( Cat002ItemNames::I002_050_CNF,
         std::make_shared<AsterixSubitemBase>( 8, CommonConverter::NoneConverter ) ) );

   // Collimation Error
   subitem_map_t error;
   // Only 8 bit but spec calculates with 16 bit ???????
   error.push_back(
      subitem_t( Cat002ItemNames::I002_090_AZM,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::circleSegment16Bit ) ) );
   error.push_back(
      subitem_t( Cat002ItemNames::I002_090_RNG,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fraction128th ) ) );

   // Dynamic Window
   subitem_map_t window;
   window.push_back(
      subitem_t( Cat002ItemNames::I002_100_THE,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::circleSegment16Bit ) ) );
   window.push_back(
      subitem_t( Cat002ItemNames::I002_100_THS,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::circleSegment16Bit ) ) );
   window.push_back(
      subitem_t( Cat002ItemNames::I002_100_RHE,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction128th ) ) );
   window.push_back(
      subitem_t( Cat002ItemNames::I002_100_RHS,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction128th ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, report_typr ) );
   subitems.insert( subitem_map_item_t( 3, sector_number ) );
   subitems.insert( subitem_map_item_t( 4, time_of_day ) );
   subitems.insert( subitem_map_item_t( 5, antenna_rotation ) );
   subitems.insert( subitem_map_item_t( 6, station_configuration ) );
   subitems.insert( subitem_map_item_t( 10, error ) );
   subitems.insert( subitem_map_item_t( 11, window ) );
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
