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
