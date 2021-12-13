/**
 * @file AsterixCategory023.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 7 Nov 2017
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

#include "AsterixCategory023.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemVariableLength.h"
#include "AsterixItemVariableLengthFlex.h"
#include "AsterixItemRepetetive.h"
#include "AsterixSubitemUnsigned.h"
#include "AsterixSubitemBitNamed.h"
#include "Cat023ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory023::AsterixCategory023() :
   AsterixCategory( 23 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory023::AsterixCategory023( int length ) :
   AsterixCategory( 23, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory023::AsterixCategory023( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 23, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory023::~AsterixCategory023() {
}

void AsterixCategory023::setUAP() {
   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat023ItemNames::I023_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat023ItemNames::I023_000, 1 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat023ItemNames::I023_015, 1 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat023ItemNames::I023_070, 3 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemVariableLength>( Cat023ItemNames::I023_100 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemVariableLengthFlex>( Cat023ItemNames::I023_101, 2 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat023ItemNames::I023_200, 1 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemVariableLength>( Cat023ItemNames::I023_110 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemRepetetive>( Cat023ItemNames::I023_120, 6 ) ) );

   // RE and SP items not yet contained in any CAT 23 message type
}

void AsterixCategory023::setSubitems() {
   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat023ItemNames::I023_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sensor_identification.push_back(
      subitem_t( Cat023ItemNames::I023_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t report_type;
   report_type.push_back(
      subitem_t( Cat023ItemNames::I023_000_TYPE,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t service_type;
   service_type.push_back(
      subitem_t( Cat023ItemNames::I023_015_SID,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   service_type.push_back(
      subitem_t( Cat023ItemNames::I023_015_STYP,
         std::make_shared<AsterixSubitemBitNamed>( 4, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 1, "ADS-B VDL4" }, { 2, "ADS-B ES" }, {
               3, "ADS-B UAT" }, { 4, "TIS-B VDL4" }, { 5, "TIS-B ES" }, { 6, "TIS-B UAT" }, { 7,
               "FIS-B VDL" }, { 8, "GRAS VDL4" }, { 9, "MLT" } } ) ) ) );

   subitem_map_t time_of_fay;
   time_of_fay.push_back(
      subitem_t( Cat023ItemNames::I023_070_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   subitem_map_t gs_status;
   gs_status.push_back(
      subitem_t( Cat023ItemNames::I023_100_NOGO,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   gs_status.push_back(
      subitem_t( Cat023ItemNames::I023_100_ODP,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   gs_status.push_back(
      subitem_t( Cat023ItemNames::I023_100_OXT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   gs_status.push_back(
      subitem_t( Cat023ItemNames::I023_100_MSC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   gs_status.push_back(
      subitem_t( Cat023ItemNames::I023_100_TSV,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   gs_status.push_back(
      subitem_t( Cat023ItemNames::I023_100_SPO,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   gs_status.push_back(
      subitem_t( Cat023ItemNames::I023_100_RN,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   gs_status.push_back(
      subitem_t( Cat023ItemNames::I023_100_GSSP,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );

   subitem_map_t service_configuration;
   service_configuration.push_back(
      subitem_t( Cat023ItemNames::I023_101_RP,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fractionHalf ) ) );
   service_configuration.push_back(
      subitem_t( Cat023ItemNames::I023_101_SC,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   service_configuration.push_back(
      subitem_t( Cat023ItemNames::I023_101_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   service_configuration.push_back(
      subitem_t( Cat023ItemNames::I023_101_SSRP,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );

   subitem_map_t operational_range;
   operational_range.push_back(
      subitem_t( Cat023ItemNames::I023_200_RNG,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t service_status;
   service_status.push_back(
      subitem_t( Cat023ItemNames::I023_110_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   service_status.push_back(
      subitem_t( Cat023ItemNames::I023_110_STATUS,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );

   subitem_map_t service_stat;
   service_stat.push_back(
      subitem_t( Cat023ItemNames::I023_120_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   service_stat.push_back(
      subitem_t( Cat023ItemNames::I023_120_REF,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   service_stat.push_back(
      subitem_t( Cat023ItemNames::I023_120_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );
   service_stat.push_back(
      subitem_t( Cat023ItemNames::I023_120_COUNTER,
         std::make_shared<AsterixSubitemUnsigned>( 32, CommonConverter::NoneConverter ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, report_type ) );
   subitems.insert( subitem_map_item_t( 3, service_type ) );
   subitems.insert( subitem_map_item_t( 4, time_of_fay ) );
   subitems.insert( subitem_map_item_t( 5, gs_status ) );
   subitems.insert( subitem_map_item_t( 6, service_configuration ) );
   subitems.insert( subitem_map_item_t( 7, operational_range ) );
   subitems.insert( subitem_map_item_t( 8, service_status ) );
   subitems.insert( subitem_map_item_t( 9, service_stat ) );
}

void AsterixCategory023::fillRecord(std::shared_ptr<ReportRecordType> record) {
}
