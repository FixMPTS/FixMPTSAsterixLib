/**
 * @file AsterixCategory063.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 3 Jan 2018
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
 * See .h file fore more information
 */

#include "AsterixCategory063.h"
#include "AsterixItemVariableLength.h"
#include "AsterixItemFixedLength.h"
#include "AsterixSubitemSigned.h"
#include "AsterixSubitemUnsigned.h"
#include "AsterixSubitemBitNamed.h"
#include "Cat063ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory063::AsterixCategory063() :
   AsterixCategory( 63 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory063::AsterixCategory063( int length ) :
   AsterixCategory( 63, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory063::AsterixCategory063( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 63, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory063::~AsterixCategory063() {
}

void AsterixCategory063::setUAP() {
   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat063ItemNames::I063_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat063ItemNames::I063_015, 1 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat063ItemNames::I063_030, 3 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat063ItemNames::I063_050, 2 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemVariableLength>( Cat063ItemNames::I063_060 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat063ItemNames::I063_070, 2 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat063ItemNames::I063_080, 4 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat063ItemNames::I063_081, 2 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat063ItemNames::I063_090, 4 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat063ItemNames::I063_091, 2 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemFixedLength>( Cat063ItemNames::I063_092, 2 ) ) );
   // SP and RE item not yet part of teh Asterix definition
}

void AsterixCategory063::setSubitems() {

   subitem_map_t system_identification;
   system_identification.push_back(
      subitem_t( Cat063ItemNames::I063_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   system_identification.push_back(
      subitem_t( Cat063ItemNames::I063_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t service_identification;
   service_identification.push_back(
      subitem_t( Cat063ItemNames::I063_015_SID,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t time_of_report;
   time_of_report.push_back(
      subitem_t( Cat063ItemNames::I063_030_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat063ItemNames::I063_050_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sensor_identification.push_back(
      subitem_t( Cat063ItemNames::I063_050_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t sensor_configuration;
   sensor_configuration.push_back(
      subitem_t( Cat063ItemNames::I063_060_CON,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Operational" }, { 1, "Degraded" }, {
               2, "Initialization" }, { 3, "Not Connected" } } ) ) ) );
   sensor_configuration.push_back(
      subitem_t( Cat063ItemNames::I063_060_PSR,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "GO" }, { 1, "NOGO" } } ) ) ) );
   sensor_configuration.push_back(
      subitem_t( Cat063ItemNames::I063_060_SSR,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "GO" }, { 1, "NOGO" } } ) ) ) );
   sensor_configuration.push_back(
      subitem_t( Cat063ItemNames::I063_060_MDS,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "GO" }, { 1, "NOGO" } } ) ) ) );
   sensor_configuration.push_back(
      subitem_t( Cat063ItemNames::I063_060_ADS,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "GO" }, { 1, "NOGO" } } ) ) ) );
   sensor_configuration.push_back(
      subitem_t( Cat063ItemNames::I063_060_MLT,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "GO" }, { 1, "NOGO" } } ) ) ) );
   sensor_configuration.push_back(
      subitem_t( Cat063ItemNames::I063_060_OPS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_configuration.push_back(
      subitem_t( Cat063ItemNames::I063_060_ODP,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_configuration.push_back(
      subitem_t( Cat063ItemNames::I063_060_OXT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_configuration.push_back(
      subitem_t( Cat063ItemNames::I063_060_MSC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_configuration.push_back(
      subitem_t( Cat063ItemNames::I063_060_TSV,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_configuration.push_back(
      subitem_t( Cat063ItemNames::I063_060_NPW,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   subitem_map_t time_stamping_bias;
   time_stamping_bias.push_back(
      subitem_t( Cat063ItemNames::I063_070_TSB,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );

   subitem_map_t ssr_range_gain_bias;
   ssr_range_gain_bias.push_back(
      subitem_t( Cat063ItemNames::I063_080_SRG,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction10ToPower5 ) ) );
   ssr_range_gain_bias.push_back(
      subitem_t( Cat063ItemNames::I063_080_SRB,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction128th ) ) );

   subitem_map_t ssr_azimuth_bias;
   ssr_azimuth_bias.push_back(
      subitem_t( Cat063ItemNames::I063_081_SAB,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );

   subitem_map_t psr_range_gain_bias;
   psr_range_gain_bias.push_back(
      subitem_t( Cat063ItemNames::I063_090_PRG,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction10ToPower5 ) ) );
   psr_range_gain_bias.push_back(
      subitem_t( Cat063ItemNames::I063_090_PRB,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction128th ) ) );

   subitem_map_t psr_azimuth_bias;
   psr_azimuth_bias.push_back(
      subitem_t( Cat063ItemNames::I063_091_PAB,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );

   subitem_map_t psr_elevatiion_bias;
   psr_elevatiion_bias.push_back(
      subitem_t( Cat063ItemNames::I063_092_PEB,
         std::make_shared<AsterixSubitemSigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, system_identification ) );
   subitems.insert( subitem_map_item_t( 2, service_identification ) );
   subitems.insert( subitem_map_item_t( 3, time_of_report ) );
   subitems.insert( subitem_map_item_t( 4, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 5, sensor_configuration ) );
   subitems.insert( subitem_map_item_t( 6, time_stamping_bias ) );
   subitems.insert( subitem_map_item_t( 7, ssr_range_gain_bias ) );
   subitems.insert( subitem_map_item_t( 8, ssr_azimuth_bias ) );
   subitems.insert( subitem_map_item_t( 9, psr_range_gain_bias ) );
   subitems.insert( subitem_map_item_t( 10, psr_azimuth_bias ) );
   subitems.insert( subitem_map_item_t( 11, psr_elevatiion_bias ) );
}

void AsterixCategory063::fillRecord(std::shared_ptr<ReportRecordType> record) {
}

