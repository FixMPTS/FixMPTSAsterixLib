/**
 * @file AsterixCategory019.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 11 Dec 2017
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

#include "AsterixCategory019.h"
#include "Cat019ItemNames.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemRepetetive.h"
#include "AsterixItemVariableLength.h"
#include "AsterixSubitemUnsigned.h"
#include "AsterixSubitemSigned.h"
#include "AsterixSubitemBitNamed.h"

// Converter
#include "CommonConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory019::AsterixCategory019() :
   AsterixCategory( 19 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory019::AsterixCategory019( int length ) :
   AsterixCategory( 19, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory019::AsterixCategory019( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 19, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory019::~AsterixCategory019() {
}

void AsterixCategory019::setUAP() {
   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat019ItemNames::I019_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat019ItemNames::I019_000, 1 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat019ItemNames::I019_140, 3 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat019ItemNames::I019_550, 1 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat019ItemNames::I019_551, 1 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemRepetetive>( Cat019ItemNames::I019_552, 2 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemVariableLength>( Cat019ItemNames::I019_553 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat019ItemNames::I019_600, 8 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat019ItemNames::I019_610, 2 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat019ItemNames::I019_620, 1 ) ) );
   // RE and SP items are not yet specified by the Asterix Board
}

void AsterixCategory019::setSubitems() {

   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat019ItemNames::I019_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   sensor_identification.push_back(
      subitem_t( Cat019ItemNames::I019_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t message_type;
   message_type.push_back(
      subitem_t( Cat019ItemNames::I019_000_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t time_of_day;
   time_of_day.push_back(
      subitem_t( Cat019ItemNames::I019_140_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::Fraction128th::get() ) ) );

   subitem_map_t system_status;
   system_status.push_back(
      subitem_t( Cat019ItemNames::I019_550_NOGO,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Operational" }, { 1, "Degraded" }, {
               2, "NOGO" }, { 3, "Undefined" } } ) ) ) );
   system_status.push_back(
      subitem_t( Cat019ItemNames::I019_550_OVL,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   system_status.push_back(
      subitem_t( Cat019ItemNames::I019_550_TSV,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   system_status.push_back(
      subitem_t( Cat019ItemNames::I019_550_TTF,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   // Remianing bits are spare

   subitem_map_t tracking_processor_status;
   tracking_processor_status.push_back(
      subitem_t( Cat019ItemNames::I019_551_STAT,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t remote_sensor_status;
   remote_sensor_status.push_back(
      subitem_t( Cat019ItemNames::I019_552_RSI,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   remote_sensor_status.push_back(
      subitem_t( Cat019ItemNames::I019_552_RST,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   remote_sensor_status.push_back(
      subitem_t( Cat019ItemNames::I019_552_STAT,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t reference_transponder_stat;
   reference_transponder_stat.push_back(
      subitem_t( Cat019ItemNames::I019_553_RT1,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   reference_transponder_stat.push_back(
      subitem_t( Cat019ItemNames::I019_553_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   reference_transponder_stat.push_back(
      subitem_t( Cat019ItemNames::I019_553_RT2,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   reference_transponder_stat.push_back(
      subitem_t( Cat019ItemNames::I019_553_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   reference_transponder_stat.push_back(
      subitem_t( Cat019ItemNames::I019_553_RT3,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   reference_transponder_stat.push_back(
      subitem_t( Cat019ItemNames::I019_553_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   reference_transponder_stat.push_back(
      subitem_t( Cat019ItemNames::I019_553_RT4,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   reference_transponder_stat.push_back(
      subitem_t( Cat019ItemNames::I019_553_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t mlt_ref_pos;
   mlt_ref_pos.push_back(
      subitem_t( Cat019ItemNames::I019_600_LAT,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution30Bit::get() ) ) );
   mlt_ref_pos.push_back(
      subitem_t( Cat019ItemNames::I019_600_LNG,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution30Bit::get() ) ) );

   subitem_map_t mlt_ref_alt;
   mlt_ref_alt.push_back(
      subitem_t( Cat019ItemNames::I019_610_ALT,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::WGS84AltQuarter::get() ) ) );

   subitem_map_t wgs84_undulation;
   wgs84_undulation.push_back(
      subitem_t( Cat019ItemNames::I019_620_U,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, message_type ) );
   subitems.insert( subitem_map_item_t( 3, time_of_day ) );
   subitems.insert( subitem_map_item_t( 4, system_status ) );
   subitems.insert( subitem_map_item_t( 5, tracking_processor_status ) );
   subitems.insert( subitem_map_item_t( 6, remote_sensor_status ) );
   subitems.insert( subitem_map_item_t( 7, reference_transponder_stat ) );
   subitems.insert( subitem_map_item_t( 8, mlt_ref_pos ) );
   subitems.insert( subitem_map_item_t( 9, mlt_ref_alt ) );
   subitems.insert( subitem_map_item_t( 10, wgs84_undulation ) );
}

void AsterixCategory019::fillRecord(std::shared_ptr<ReportRecordType> record) {
}

