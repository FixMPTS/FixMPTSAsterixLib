/**
 * @file AsterixCategory065.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 8 Jan 2018
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

#include "AsterixCategory065.h"
#include "AsterixItemCompoundLI.h"
#include "AsterixItemFixedLength.h"
#include "AsterixSubitemSigned.h"
#include "AsterixSubitemCompound.h"
#include "AsterixSubitemUnsigned.h"
#include "AsterixSubitemBitNamed.h"
#include "Cat065ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "StringConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory065::AsterixCategory065() :
   AsterixCategory( 65 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory065::AsterixCategory065( int length ) :
   AsterixCategory( 65, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory065::AsterixCategory065( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 65, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory065::~AsterixCategory065() {
}

void AsterixCategory065::setUAP() {

   // Definition of the compound items
   // RE item is a compound item of compound items
   AsterixItemCompound::subUap_T item_re_sub_uap;
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_RE_SRP, 8 ) ) );
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_RE_ARL, 2 ) ) );

   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_000, 1 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_015, 1 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_030, 3 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_020, 1 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_040, 1 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_050, 1 ) ) );
   // FRN 8 to 12 are spare
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemCompoundLI>( Cat065ItemNames::I065_RE, item_re_sub_uap ) ) );
   //SP item not encoded since it is application dependent
}

void AsterixCategory065::setSubitems() {

   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat065ItemNames::I065_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   sensor_identification.push_back(
      subitem_t( Cat065ItemNames::I065_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t message_type;
   message_type.push_back(
      subitem_t( Cat065ItemNames::I065_000_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t service_identification;
   service_identification.push_back(
      subitem_t( Cat065ItemNames::I065_015_SID,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t time_of_mesage;
   time_of_mesage.push_back(
      subitem_t( Cat065ItemNames::I065_030_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::Fraction128th::get() ) ) );

   subitem_map_t batch_number;
   batch_number.push_back(
      subitem_t( Cat065ItemNames::I065_020_BTN,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t sdps_configuration;
   sdps_configuration.push_back(
      subitem_t( Cat065ItemNames::I065_040_NOGO,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Operational" }, { 1, "Degraded" }, {
               2, "Not Connected" }, { 3, "Unknowen" } } ) ) ) );
   sdps_configuration.push_back(
      subitem_t( Cat065ItemNames::I065_040_OVL,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sdps_configuration.push_back(
      subitem_t( Cat065ItemNames::I065_040_TSV,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sdps_configuration.push_back(
      subitem_t( Cat065ItemNames::I065_040_PSS,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Not Applicable" }, { 1, "SDPS 1" }, {
               2, "SDPS 2" }, { 3, "SDPS 3" } } ) ) ) );
   sdps_configuration.push_back(
      subitem_t( Cat065ItemNames::I065_040_STTN,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sdps_configuration.push_back(
      subitem_t( Cat065ItemNames::I065_040_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t service_status_report;
   service_status_report.push_back(
      subitem_t( Cat065ItemNames::I065_050_REPORT,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t reserved_expansion;
   subitem_map_t sub_sub_item_re_srp;
   sub_sub_item_re_srp.push_back(
      subitem_t( Cat065ItemNames::I065_RE_SRP_LAT,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution30Bit::get() ) ) );
   sub_sub_item_re_srp.push_back(
      subitem_t( Cat065ItemNames::I065_RE_SRP_LNG,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution30Bit::get() ) ) );

   // Add all items to the reserved expansion sub item
   reserved_expansion.push_back(
      subitem_t( Cat065ItemNames::I065_RE_SRP,
         std::make_shared<AsterixSubitemCompound>( 64, StringConverter::BitsToNATOtn19Bit::get(),
            sub_sub_item_re_srp ) ) );
   reserved_expansion.push_back(
      subitem_t( Cat065ItemNames::I065_RE_ARL,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter::get() ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, message_type ) );
   subitems.insert( subitem_map_item_t( 3, service_identification ) );
   subitems.insert( subitem_map_item_t( 4, time_of_mesage ) );
   subitems.insert( subitem_map_item_t( 5, batch_number ) );
   subitems.insert( subitem_map_item_t( 6, sdps_configuration ) );
   subitems.insert( subitem_map_item_t( 7, service_status_report ) );
   subitems.insert( subitem_map_item_t( 13, reserved_expansion ) );
}

void AsterixCategory065::fillRecord(std::shared_ptr<ReportRecordType> record) {
}

