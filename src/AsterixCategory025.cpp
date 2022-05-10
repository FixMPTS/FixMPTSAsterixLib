/**
 * @file AsterixCategory025.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 31 Dec 2017
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
 * See .h file for more information
 */

#include "AsterixCategory025.h"

#include "AsterixItemRepetetive.h"
#include "AsterixItemVariableLength.h"
#include "AsterixItemFixedLength.h"
#include "AsterixSubitemBitNamed.h"
#include "AsterixSubitemUnsigned.h"
#include "Cat025ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "StringConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory025::AsterixCategory025() :
   AsterixCategory( 25 ) {
   initCategory();
}

AsterixCategory025::AsterixCategory025( int length ) :
   AsterixCategory( 25, length ) {
   initCategory();
}

AsterixCategory025::AsterixCategory025( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 25, length, m_queue ) {
   initCategory();
}

AsterixCategory025::~AsterixCategory025() {
}

void AsterixCategory025::setUAP() {
   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat025ItemNames::I025_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat025ItemNames::I025_000, 1 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat025ItemNames::I025_200, 3 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat025ItemNames::I025_015, 1 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat025ItemNames::I025_020, 6 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat025ItemNames::I025_070, 3 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemVariableLength>( Cat025ItemNames::I025_100 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemRepetetive>( Cat025ItemNames::I025_105, 1 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemRepetetive>( Cat025ItemNames::I025_120, 3 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemRepetetive>( Cat025ItemNames::I025_140, 6 ) ) );
}

void AsterixCategory025::setSubitems() {
   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat025ItemNames::I025_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   sensor_identification.push_back(
      subitem_t( Cat025ItemNames::I025_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t report_type;
   report_type.push_back(
      subitem_t( Cat025ItemNames::I025_000_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter::get() ) ) );
   report_type.push_back(
      subitem_t( Cat025ItemNames::I025_000_RG,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t message_identification;
   message_identification.push_back(
      subitem_t( Cat025ItemNames::I025_200_MIN,
         std::make_shared<AsterixSubitemUnsigned>( 24, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t service_identification;
   service_identification.push_back(
      subitem_t( Cat025ItemNames::I025_015_SID,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t service_designator;
   service_designator.push_back(
      subitem_t( Cat025ItemNames::I025_020_SD,
         std::make_shared<AsterixSubitemUnsigned>( 48, StringConverter::To6BitChar::get() ) ) );

   subitem_map_t time_of_day;
   time_of_day.push_back(
      subitem_t( Cat025ItemNames::I025_070_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::Fraction128th::get() ) ) );

   subitem_map_t system_status;
   system_status.push_back(
      subitem_t( Cat025ItemNames::I025_100_NOGO,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "GO" }, { 1, "NOGO" } } ) ) ) );
   system_status.push_back(
      subitem_t( Cat025ItemNames::I025_100_OPS,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Operational" }, { 1,
               "Operational Standby" }, { 2, "Maintenance" }, { 3, "None" } } ) ) ) );
   system_status.push_back(
      subitem_t( Cat025ItemNames::I025_100_STAT,
         std::make_shared<AsterixSubitemBitNamed>( 4, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Running" }, { 1, "Failed" }, { 2,
               "Degraded" }, { 3, "Undefined" } } ) ) ) );

   subitem_map_t system_error_codes;
   system_error_codes.push_back(
      subitem_t( Cat025ItemNames::I025_105_ERR,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t component_status;
   component_status.push_back(
      subitem_t( Cat025ItemNames::I025_120_CID,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter::get() ) ) );
   component_status.push_back(
      subitem_t( Cat025ItemNames::I025_120_EC,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter::get() ) ) );
   component_status.push_back(
      subitem_t( Cat025ItemNames::I025_120_CS,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Running" }, { 1, "Failed" }, { 2,
               "Maintenance" }, { 3, "None" } } ) ) ) );

   subitem_map_t service_statistics;
   service_statistics.push_back(
      subitem_t( Cat025ItemNames::I025_140_TYPE,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   service_statistics.push_back(
      subitem_t( Cat025ItemNames::I025_140_REF,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   service_statistics.push_back(
      subitem_t( Cat025ItemNames::I025_140_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter::get() ) ) );
   service_statistics.push_back(
      subitem_t( Cat025ItemNames::I025_140_COUNTER,
         std::make_shared<AsterixSubitemUnsigned>( 32, CommonConverter::NoneConverter::get() ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, report_type ) );
   subitems.insert( subitem_map_item_t( 3, message_identification ) );
   subitems.insert( subitem_map_item_t( 4, service_identification ) );
   subitems.insert( subitem_map_item_t( 5, service_designator ) );
   subitems.insert( subitem_map_item_t( 6, time_of_day ) );
   subitems.insert( subitem_map_item_t( 7, system_status ) );
   subitems.insert( subitem_map_item_t( 8, system_error_codes ) );
   subitems.insert( subitem_map_item_t( 9, component_status ) );
   subitems.insert( subitem_map_item_t( 10, service_statistics ) );
}

void AsterixCategory025::fillRecord(std::shared_ptr<ReportRecordType> record) {
}
