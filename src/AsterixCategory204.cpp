/**
 * @file AsterixCategory204.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 30 Jan 2018
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

#include "AsterixCategory204.h"
#include "AsterixItemRepetetive.h"
#include "AsterixItemCompound.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemExtendible.h"
#include "AsterixSubitemSigned.h"
#include "AsterixSubitemCompound.h"
#include "AsterixSubItemRep.h"
#include "AsterixSubitemBytes.h"
#include "AsterixSubitemUnsigned.h"
#include "Cat204ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "StringConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"
#include "IntegerConverter.h"

AsterixCategory204::AsterixCategory204() :
   AsterixCategory( 204 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory204::AsterixCategory204( int length ) :
   AsterixCategory( 204, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory204::AsterixCategory204( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 204, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory204::~AsterixCategory204() {
}

void AsterixCategory204::setUAP() {

   // Define the sub UAPs from the compound items
   AsterixItemCompound::subUap_T item_291_sub_uap;
   item_291_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_291_UPD, 1 ) ) );
   item_291_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_291_AMSL, 1 ) ) );
   item_291_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_291_IFF1, 1 ) ) );
   item_291_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_291_IFF2, 1 ) ) );
   item_291_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_291_IFF3, 1 ) ) );
   item_291_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_291_IFF4, 1 ) ) );
   item_291_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_291_IFFC, 1 ) ) );
   item_291_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_291_COM, 1 ) ) );
   item_291_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 9,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_291_ACS, 1 ) ) );
   item_291_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 10,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_291_POS, 1 ) ) );
   item_291_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 11,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_291_GAL, 1 ) ) );
   item_291_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 12,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_291_MB, 1 ) ) );

   AsterixItemCompound::subUap_T item_094_sub_uap;
   item_094_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_094_SUM, 1 ) ) );
   item_094_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_094_PMN, 4 ) ) );
   item_094_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_094_POS, 6 ) ) );
   item_094_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_094_GA, 2 ) ) );
   item_094_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_094_EM1, 2 ) ) );
   item_094_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_094_TOS, 2 ) ) );
   item_094_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_094_XP, 1 ) ) );

   AsterixItemCompound::subUap_T item_101_sub_uap;
   item_101_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_101_ADR, 3 ) ) );
   item_101_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_101_ID, 6 ) ) );
   item_101_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_101_COM, 2 ) ) );
   item_101_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_101_ACS, 7 ) ) );
   item_101_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_101_POS, 6 ) ) );
   item_101_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_101_GAL, 2 ) ) );
   item_101_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemRepetetive>( Cat204ItemNames::I204_101_MB, 8 ) ) );

   AsterixItemCompound::subUap_T item_130_sub_uap;
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_130_CONF, 1 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_130_ACT, 1 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_130_TYP, 1 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_130_STYP, 1 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_130_NAT, 2 ) ) );

   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemRepetetive>( Cat204ItemNames::I204_012, 2 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_000, 2 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_001, 3 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_700, 6 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_003, 2 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_260, 1 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_280, 8 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_020, 8 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_030, 1 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_060, 8 ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_070, 2 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_080, 1 ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_040, 4 ) ) );
   uap.insert( UAP_Item_T( 15, std::make_shared<AsterixItemCompound>( Cat204ItemNames::I204_291, item_291_sub_uap ) ) );
   uap.insert( UAP_Item_T( 16, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_050, 2 ) ) );
   uap.insert( UAP_Item_T( 17, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_081, 1 ) ) );
   uap.insert( UAP_Item_T( 18, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_082, 1 ) ) );
   uap.insert( UAP_Item_T( 19, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_083, 1 ) ) );
   uap.insert( UAP_Item_T( 20, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_084, 3 ) ) );
   uap.insert( UAP_Item_T( 21, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_090, 1 ) ) );
   uap.insert( UAP_Item_T( 22, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_091, 2 ) ) );
   uap.insert( UAP_Item_T( 23, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_092, 2 ) ) );
   uap.insert( UAP_Item_T( 24, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_093, 1 ) ) );
   uap.insert( UAP_Item_T( 25, std::make_shared<AsterixItemCompound>( Cat204ItemNames::I204_094, item_094_sub_uap ) ) );
   uap.insert( UAP_Item_T( 26, std::make_shared<AsterixItemCompound>( Cat204ItemNames::I204_101, item_101_sub_uap ) ) );
   uap.insert( UAP_Item_T( 27, std::make_shared<AsterixItemCompound>( Cat204ItemNames::I204_130, item_130_sub_uap ) ) );
   uap.insert( UAP_Item_T( 28, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_170, 4 ) ) );
   uap.insert( UAP_Item_T( 29, std::make_shared<AsterixItemRepetetive>( Cat204ItemNames::I204_620, 12 ) ) );
   uap.insert( UAP_Item_T( 30, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_245, 7 ) ) );
   uap.insert( UAP_Item_T( 31, std::make_shared<AsterixItemRepetetive>( Cat204ItemNames::I204_630, 2 ) ) );
   uap.insert( UAP_Item_T( 32, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_690, 1 ) ) );
   uap.insert( UAP_Item_T( 33, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_085, 3 ) ) );
   uap.insert( UAP_Item_T( 34, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_400, 12 ) ) );
   uap.insert( UAP_Item_T( 35, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_710, 1 ) ) );
   uap.insert( UAP_Item_T( 36, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_720, 1 ) ) );
   uap.insert( UAP_Item_T( 37, std::make_shared<AsterixItemExtendible>( Cat204ItemNames::I204_730, 3 ) ) );
   uap.insert( UAP_Item_T( 38, std::make_shared<AsterixItemFixedLength>( Cat204ItemNames::I204_740, 2 ) ) );
}

void AsterixCategory204::setSubitems() {

   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat204ItemNames::I204_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sensor_identification.push_back(
      subitem_t( Cat204ItemNames::I204_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t data_destination_identifier;
   data_destination_identifier.push_back(
      subitem_t( Cat204ItemNames::I204_012_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   data_destination_identifier.push_back(
      subitem_t( Cat204ItemNames::I204_012_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t message_type;
   message_type.push_back(
      subitem_t( Cat204ItemNames::I204_000_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );

   subitem_map_t nato_track_number;
   nato_track_number.push_back(
      subitem_t( Cat204ItemNames::I204_001_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   nato_track_number.push_back(
      subitem_t( Cat204ItemNames::I204_001_TN,
         std::make_shared<AsterixSubitemUnsigned>( 19, StringConverter::BitsToNATOtn19Bit ) ) );
   nato_track_number.push_back(
      subitem_t( Cat204ItemNames::I204_001_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );

   subitem_map_t order_identification;
   order_identification.push_back(
      subitem_t( Cat204ItemNames::I204_700_ACK,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   order_identification.push_back(
      subitem_t( Cat204ItemNames::I204_700_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 15, CommonConverter::NoneConverter ) ) );
   order_identification.push_back(
      subitem_t( Cat204ItemNames::I204_700_ID,
         std::make_shared<AsterixSubitemUnsigned>( 32, CommonConverter::NoneConverter ) ) );

   subitem_map_t track_point;
   track_point.push_back(
      subitem_t( Cat204ItemNames::I204_003_ID,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );

   subitem_map_t object_status;
   object_status.push_back(
      subitem_t( Cat204ItemNames::I204_260_STS,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t update_time;
   update_time.push_back(
      subitem_t( Cat204ItemNames::I204_280_TIME,
         std::make_shared<AsterixSubitemUnsigned>( 64, CommonConverter::NoneConverter ) ) );

   subitem_map_t position_wgs;
   position_wgs.push_back(
      subitem_t( Cat204ItemNames::I204_020_LAT,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution30Bit ) ) );
   position_wgs.push_back(
      subitem_t( Cat204ItemNames::I204_020_LNG,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution30Bit ) ) );

   subitem_map_t track_quality;
   track_quality.push_back(
      subitem_t( Cat204ItemNames::I204_030_TQ,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t speed_heading;
   speed_heading.push_back(
      subitem_t( Cat204ItemNames::I204_060_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   speed_heading.push_back(
      subitem_t( Cat204ItemNames::I204_060_VSP,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   speed_heading.push_back(
      subitem_t( Cat204ItemNames::I204_060_CLIM,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   speed_heading.push_back(
      subitem_t( Cat204ItemNames::I204_060_VSPEED,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::speedVelToKt ) ) );
   speed_heading.push_back(
      subitem_t( Cat204ItemNames::I204_060_MACH,
         std::make_shared<AsterixSubitemUnsigned>( 12, UnsignedDoubleConverter::fraction10th ) ) );
   speed_heading.push_back(
      subitem_t( Cat204ItemNames::I204_060_HDG,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );
   speed_heading.push_back(
      subitem_t( Cat204ItemNames::I204_060_HSPEED,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::fraction10th ) ) );

   subitem_map_t primary_identity;
   primary_identity.push_back(
      subitem_t( Cat204ItemNames::I204_070_EID,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   primary_identity.push_back(
      subitem_t( Cat204ItemNames::I204_070_MID,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t environment_category;
   environment_category.push_back(
      subitem_t( Cat204ItemNames::I204_080_ECAT,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t amsl_altitude;
   amsl_altitude.push_back(
      subitem_t( Cat204ItemNames::I204_040_ALT,
         std::make_shared<AsterixSubitemSigned>( 32, CommonConverter::NoneConverter ) ) );

   subitem_map_t track_data_ages;
   track_data_ages.push_back(
      subitem_t( Cat204ItemNames::I204_291_UPD,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat204ItemNames::I204_291_AMSL,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat204ItemNames::I204_291_IFF1,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat204ItemNames::I204_291_IFF2,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat204ItemNames::I204_291_IFF3,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat204ItemNames::I204_291_IFF4,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat204ItemNames::I204_291_IFFC,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat204ItemNames::I204_291_COM,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat204ItemNames::I204_291_ACS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat204ItemNames::I204_291_POS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat204ItemNames::I204_291_GAL,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat204ItemNames::I204_291_MB,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );

   subitem_map_t iffc;
   iffc.push_back(
      subitem_t( Cat204ItemNames::I204_050_IFFFC,
         std::make_shared<AsterixSubitemSigned>( 16, IntegerConverter::alt25ft ) ) );

   subitem_map_t object_type;
   object_type.push_back(
      subitem_t( Cat204ItemNames::I204_081_SRP,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   object_type.push_back(
      subitem_t( Cat204ItemNames::I204_081_TYPE,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );

   subitem_map_t track_mode;
   track_mode.push_back(
      subitem_t( Cat204ItemNames::I204_082_MODE,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t detection_kind;
   detection_kind.push_back(
      subitem_t( Cat204ItemNames::I204_083_KIND,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t strength;
   strength.push_back(
      subitem_t( Cat204ItemNames::I204_084_FORMAT,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   strength.push_back(
      subitem_t( Cat204ItemNames::I204_084_MAX,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   strength.push_back(
      subitem_t( Cat204ItemNames::I204_084_MIN,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t iff1;
   iff1.push_back(
      subitem_t( Cat204ItemNames::I204_090_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   iff1.push_back(
      subitem_t( Cat204ItemNames::I204_090_IFF1,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter ) ) );

   subitem_map_t iff2;
   iff2.push_back(
      subitem_t( Cat204ItemNames::I204_091_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   iff2.push_back(
      subitem_t( Cat204ItemNames::I204_091_IFF2,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   subitem_map_t iff3;
   iff3.push_back(
      subitem_t( Cat204ItemNames::I204_092_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   iff3.push_back(
      subitem_t( Cat204ItemNames::I204_092_IFF3,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   subitem_map_t iff4;
   iff4.push_back(
      subitem_t( Cat204ItemNames::I204_093_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter ) ) );
   iff4.push_back(
      subitem_t( Cat204ItemNames::I204_093_IFF4,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );

   // Subitem 094 compound sub item definitions
   subitem_map_t sub_sub_item_094_sum;
   sub_sub_item_094_sum.push_back(
      subitem_t( Cat204ItemNames::I204_094_SUM_M5,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_sum.push_back(
      subitem_t( Cat204ItemNames::I204_094_SUM_ID,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_sum.push_back(
      subitem_t( Cat204ItemNames::I204_094_SUM_DA,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_sum.push_back(
      subitem_t( Cat204ItemNames::I204_094_SUM_M1,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_sum.push_back(
      subitem_t( Cat204ItemNames::I204_094_SUM_M2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_sum.push_back(
      subitem_t( Cat204ItemNames::I204_094_SUM_M3,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_sum.push_back(
      subitem_t( Cat204ItemNames::I204_094_SUM_MC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_sum.push_back(
      subitem_t( Cat204ItemNames::I204_094_SUM_X,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   subitem_map_t sub_sub_item_094_pmn;
   sub_sub_item_094_pmn.push_back(
      subitem_t( Cat204ItemNames::I204_094_PMN_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_pmn.push_back(
      subitem_t( Cat204ItemNames::I204_094_PMN_PIN,
         std::make_shared<AsterixSubitemUnsigned>( 14, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_pmn.push_back(
      subitem_t( Cat204ItemNames::I204_094_PMN_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_pmn.push_back(
      subitem_t( Cat204ItemNames::I204_094_PMN_NAT,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_pmn.push_back(
      subitem_t( Cat204ItemNames::I204_094_PMN_SPARE3,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_pmn.push_back(
      subitem_t( Cat204ItemNames::I204_094_PMN_MIS,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );

   subitem_map_t sub_sub_item_094_pos;
   sub_sub_item_094_pos.push_back(
      subitem_t( Cat204ItemNames::I204_094_POS_LAT,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );
   sub_sub_item_094_pos.push_back(
      subitem_t( Cat204ItemNames::I204_094_POS_LNG,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );

   subitem_map_t sub_sub_item_094_ga;
   sub_sub_item_094_ga.push_back(
      subitem_t( Cat204ItemNames::I204_094_GA_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_ga.push_back(
      subitem_t( Cat204ItemNames::I204_094_GA_RES,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_ga.push_back(
      subitem_t( Cat204ItemNames::I204_094_GA_ALT,
         std::make_shared<AsterixSubitemSigned>( 14, IntegerConverter::alt25ft ) ) );

   subitem_map_t sub_sub_item_094_em1;
   sub_sub_item_094_em1.push_back(
      subitem_t( Cat204ItemNames::I204_094_EM1_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_em1.push_back(
      subitem_t( Cat204ItemNames::I204_094_EM1_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   subitem_map_t sub_sub_item_094_x;
   sub_sub_item_094_x.push_back(
      subitem_t( Cat204ItemNames::I204_094_XP_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_x.push_back(
      subitem_t( Cat204ItemNames::I204_094_XP_X5,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_x.push_back(
      subitem_t( Cat204ItemNames::I204_094_XP_XC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_x.push_back(
      subitem_t( Cat204ItemNames::I204_094_XP_X3,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_x.push_back(
      subitem_t( Cat204ItemNames::I204_094_XP_X2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_094_x.push_back(
      subitem_t( Cat204ItemNames::I204_094_XP_X1,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   // Add all sub sub items to the master sub item
   subitem_map_t mode5;
   mode5.push_back(
      subitem_t( Cat204ItemNames::I204_094_SUM,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer,
            sub_sub_item_094_sum ) ) );
   mode5.push_back(
      subitem_t( Cat204ItemNames::I204_094_PMN,
         std::make_shared<AsterixSubitemCompound>( 32, CommonConverter::NoneConverterBuffer,
            sub_sub_item_094_pmn ) ) );
   mode5.push_back(
      subitem_t( Cat204ItemNames::I204_094_POS,
         std::make_shared<AsterixSubitemCompound>( 48, CommonConverter::NoneConverterBuffer,
            sub_sub_item_094_pos ) ) );
   mode5.push_back(
      subitem_t( Cat204ItemNames::I204_094_GA,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            sub_sub_item_094_ga ) ) );
   mode5.push_back(
      subitem_t( Cat204ItemNames::I204_094_EM1,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            sub_sub_item_094_em1 ) ) );
   mode5.push_back(
      subitem_t( Cat204ItemNames::I204_094_TOS,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );
   mode5.push_back(
      subitem_t( Cat204ItemNames::I204_094_XP,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer,
            sub_sub_item_094_x ) ) );

   // Sub item 101 compound sub items definitions
   subitem_map_t sub_sub_item_101_com;
   sub_sub_item_101_com.push_back(
      subitem_t( Cat204ItemNames::I204_101_COM_COM,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   sub_sub_item_101_com.push_back(
      subitem_t( Cat204ItemNames::I204_101_COM_STAT,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   sub_sub_item_101_com.push_back(
      subitem_t( Cat204ItemNames::I204_101_COM_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   sub_sub_item_101_com.push_back(
      subitem_t( Cat204ItemNames::I204_101_COM_SCC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_101_com.push_back(
      subitem_t( Cat204ItemNames::I204_101_COM_ARC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_101_com.push_back(
      subitem_t( Cat204ItemNames::I204_101_COM_AIC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_101_com.push_back(
      subitem_t( Cat204ItemNames::I204_101_COM_B1A,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_101_com.push_back(
      subitem_t( Cat204ItemNames::I204_101_COM_B1B,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   subitem_map_t sub_sub_item_101_pos;
   sub_sub_item_101_pos.push_back(
      subitem_t( Cat204ItemNames::I204_101_POS_LAT,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );
   sub_sub_item_101_pos.push_back(
      subitem_t( Cat204ItemNames::I204_101_POS_LNG,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );

   subitem_map_t sub_sub_item_101_mb;
   sub_sub_item_101_mb.push_back(
      subitem_t( Cat204ItemNames::I204_101_MB_DATA,
         std::make_shared<AsterixSubitemSigned>( 56, CommonConverter::NoneConverter ) ) );
   sub_sub_item_101_mb.push_back(
      subitem_t( Cat204ItemNames::I204_101_MB_BDS1,
         std::make_shared<AsterixSubitemSigned>( 4, CommonConverter::NoneConverter ) ) );
   sub_sub_item_101_mb.push_back(
      subitem_t( Cat204ItemNames::I204_101_MB_BDS2,
         std::make_shared<AsterixSubitemSigned>( 4, CommonConverter::NoneConverter ) ) );

   // Add all sub sub items to the master sub item
   subitem_map_t aircraft_derived_data;
   aircraft_derived_data.push_back(
      subitem_t( Cat204ItemNames::I204_101_ADR,
         std::make_shared<AsterixSubitemUnsigned>( 24, CommonConverter::NoneConverter ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat204ItemNames::I204_101_ID,
         std::make_shared<AsterixSubitemUnsigned>( 48, StringConverter::to6BitChar ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat204ItemNames::I204_101_COM,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            sub_sub_item_101_com ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat204ItemNames::I204_101_ACS,
         std::make_shared<AsterixSubitemUnsigned>( 56, CommonConverter::NoneConverter ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat204ItemNames::I204_101_POS,
         std::make_shared<AsterixSubitemCompound>( 48, CommonConverter::NoneConverterBuffer,
            sub_sub_item_101_pos ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat204ItemNames::I204_101_GAL,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::geoAltitudeFt ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat204ItemNames::I204_101_MB,
         std::make_shared<AsterixSubItemRep>( 64, CommonConverter::NoneConverterBuffer,
            sub_sub_item_101_mb ) ) );

   // Add all sub sub items to the master sub item
   subitem_map_t secondary_identity_information;
   secondary_identity_information.push_back(
      subitem_t( Cat204ItemNames::I204_130_CONF,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   secondary_identity_information.push_back(
      subitem_t( Cat204ItemNames::I204_130_ACT,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   secondary_identity_information.push_back(
      subitem_t( Cat204ItemNames::I204_130_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   secondary_identity_information.push_back(
      subitem_t( Cat204ItemNames::I204_130_STYP,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );
   secondary_identity_information.push_back(
      subitem_t( Cat204ItemNames::I204_130_NAT,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t indicators_block;
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_IFFC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_IFF3,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_IFF2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_IFF1,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_FIX,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_C2,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_JAM,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_EMER,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_ENG,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_EXER,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_INT,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_SPI,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_SIF,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_TN,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_SIM,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   indicators_block.push_back(
      subitem_t( Cat204ItemNames::I204_170_FTEL,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );

   subitem_map_t mission_weapon_engagement;
   mission_weapon_engagement.push_back(
      subitem_t( Cat204ItemNames::I204_620_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mission_weapon_engagement.push_back(
      subitem_t( Cat204ItemNames::I204_620_ENV,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   mission_weapon_engagement.push_back(
      subitem_t( Cat204ItemNames::I204_620_ROLE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mission_weapon_engagement.push_back(
      subitem_t( Cat204ItemNames::I204_620_TYPE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   mission_weapon_engagement.push_back(
      subitem_t( Cat204ItemNames::I204_620_CNTN,
         std::make_shared<AsterixSubitemBytes>( 72, StringConverter::toASCII ) ) );
   mission_weapon_engagement.push_back(
      subitem_t( Cat204ItemNames::I204_620_STS,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   mission_weapon_engagement.push_back(
      subitem_t( Cat204ItemNames::I204_620_WS,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t target_identification;
   target_identification.push_back(
      subitem_t( Cat204ItemNames::I204_245_STI,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   target_identification.push_back(
      subitem_t( Cat204ItemNames::I204_245_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   target_identification.push_back(
      subitem_t( Cat204ItemNames::I204_245_ID,
         std::make_shared<AsterixSubitemUnsigned>( 48, StringConverter::to6BitChar ) ) );

   subitem_map_t sensor_list;
   sensor_list.push_back(
      subitem_t( Cat204ItemNames::I204_630_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sensor_list.push_back(
      subitem_t( Cat204ItemNames::I204_630_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t resource_available;
   resource_available.push_back(
      subitem_t( Cat204ItemNames::I204_690_AV,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t track_size;
   track_size.push_back(
      subitem_t( Cat204ItemNames::I204_085_FORMAT,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   track_size.push_back(
      subitem_t( Cat204ItemNames::I204_085_MAX,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   track_size.push_back(
      subitem_t( Cat204ItemNames::I204_085_MIN,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t strobe_data;
   strobe_data.push_back(
      subitem_t( Cat204ItemNames::I204_400_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );
   strobe_data.push_back(
      subitem_t( Cat204ItemNames::I204_400_SIM,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   strobe_data.push_back(
      subitem_t( Cat204ItemNames::I204_400_DESC,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   strobe_data.push_back(
      subitem_t( Cat204ItemNames::I204_400_ORI,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   strobe_data.push_back(
      subitem_t( Cat204ItemNames::I204_400_ACCUR,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   strobe_data.push_back(
      subitem_t( Cat204ItemNames::I204_400_ERANGE,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::eRange ) ) );
   strobe_data.push_back(
      subitem_t( Cat204ItemNames::I204_400_AZIM,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );
   strobe_data.push_back(
      subitem_t( Cat204ItemNames::I204_400_AZIMW,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );
   strobe_data.push_back(
      subitem_t( Cat204ItemNames::I204_400_AZRATE,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::direction16Bit ) ) );
   strobe_data.push_back(
      subitem_t( Cat204ItemNames::I204_400_ELEV,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::elevation16Bit ) ) );

   subitem_map_t acknowledgement_desiggnator;
   acknowledgement_desiggnator.push_back(
      subitem_t( Cat204ItemNames::I204_710_AD,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t track_filter_designator;
   track_filter_designator.push_back(
      subitem_t( Cat204ItemNames::I204_720_SS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_filter_designator.push_back(
      subitem_t( Cat204ItemNames::I204_720_RS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_filter_designator.push_back(
      subitem_t( Cat204ItemNames::I204_720_NTN,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_filter_designator.push_back(
      subitem_t( Cat204ItemNames::I204_720_ID,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_filter_designator.push_back(
      subitem_t( Cat204ItemNames::I204_720_RTT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_filter_designator.push_back(
      subitem_t( Cat204ItemNames::I204_720_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );

   subitem_map_t ntn_specifier;
   ntn_specifier.push_back(
      subitem_t( Cat204ItemNames::I204_730_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   ntn_specifier.push_back(
      subitem_t( Cat204ItemNames::I204_730_ID,
         std::make_shared<AsterixSubitemUnsigned>( 19, StringConverter::BitsToNATOtn19Bit ) ) );
   ntn_specifier.push_back(
      subitem_t( Cat204ItemNames::I204_730_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   subitem_map_t relayed_data_source_identifier;
   relayed_data_source_identifier.push_back(
      subitem_t( Cat204ItemNames::I204_740_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   relayed_data_source_identifier.push_back(
      subitem_t( Cat204ItemNames::I204_740_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, data_destination_identifier ) );
   subitems.insert( subitem_map_item_t( 3, message_type ) );
   subitems.insert( subitem_map_item_t( 4, nato_track_number ) );
   subitems.insert( subitem_map_item_t( 5, order_identification ) );
   subitems.insert( subitem_map_item_t( 6, track_point ) );
   subitems.insert( subitem_map_item_t( 7, object_status ) );
   subitems.insert( subitem_map_item_t( 8, update_time ) );
   subitems.insert( subitem_map_item_t( 9, position_wgs ) );
   subitems.insert( subitem_map_item_t( 10, track_quality ) );
   subitems.insert( subitem_map_item_t( 11, speed_heading ) );
   subitems.insert( subitem_map_item_t( 12, primary_identity ) );
   subitems.insert( subitem_map_item_t( 13, environment_category ) );
   subitems.insert( subitem_map_item_t( 14, amsl_altitude ) );
   subitems.insert( subitem_map_item_t( 15, track_data_ages ) );
   subitems.insert( subitem_map_item_t( 16, iffc ) );
   subitems.insert( subitem_map_item_t( 17, object_type ) );
   subitems.insert( subitem_map_item_t( 18, track_mode ) );
   subitems.insert( subitem_map_item_t( 19, detection_kind ) );
   subitems.insert( subitem_map_item_t( 20, strength ) );
   subitems.insert( subitem_map_item_t( 21, iff1 ) );
   subitems.insert( subitem_map_item_t( 22, iff2 ) );
   subitems.insert( subitem_map_item_t( 23, iff3 ) );
   subitems.insert( subitem_map_item_t( 24, iff4 ) );
   subitems.insert( subitem_map_item_t( 25, mode5 ) );
   subitems.insert( subitem_map_item_t( 26, aircraft_derived_data ) );
   subitems.insert( subitem_map_item_t( 27, secondary_identity_information ) );
   subitems.insert( subitem_map_item_t( 28, indicators_block ) );
   subitems.insert( subitem_map_item_t( 29, mission_weapon_engagement ) );
   subitems.insert( subitem_map_item_t( 30, target_identification ) );
   subitems.insert( subitem_map_item_t( 31, sensor_list ) );
   subitems.insert( subitem_map_item_t( 32, resource_available ) );
   subitems.insert( subitem_map_item_t( 33, track_size ) );
   subitems.insert( subitem_map_item_t( 34, strobe_data ) );
   subitems.insert( subitem_map_item_t( 35, acknowledgement_desiggnator ) );
   subitems.insert( subitem_map_item_t( 36, track_filter_designator ) );
   subitems.insert( subitem_map_item_t( 37, ntn_specifier ) );
   subitems.insert( subitem_map_item_t( 38, relayed_data_source_identifier ) );
}

void AsterixCategory204::fillRecord(std::shared_ptr<ReportRecordType> record) {
}


