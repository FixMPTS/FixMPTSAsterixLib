/**
 * @file AsterixCategory061.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 19 Jan 2018
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
 * See .h File for more information
 */

#include "AsterixCategory061.h"
#include "AsterixItemRepetetive.h"
#include "AsterixItemCompound.h"
#include "AsterixItemVariableLength.h"
#include "AsterixItemExtendible.h"
#include "AsterixItemVariableLength.h"
#include "AsterixItemFixedLength.h"
#include "AsterixSubitemSigned.h"
#include "AsterixSubItemRep.h"
#include "AsterixSubitemCompound.h"
#include "AsterixSubitemBytes.h"
#include "AsterixSubitemUnsigned.h"
#include "Cat061ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "StringConverter.h"
#include "IntegerConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory061::AsterixCategory061() :
   AsterixCategory( 61 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory061::AsterixCategory061(int length) :
   AsterixCategory( 61, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory061::AsterixCategory061(int length, std::deque<char> &m_queue) :
   AsterixCategory( 61, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory061::~AsterixCategory061() {
}

void AsterixCategory061::setUAP() {
   // Sub UAPs for compound data items
   AsterixItemCompound::subUap_T item_130_sub_uap;
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemRepetetive>( Cat061ItemNames::I061_130_TNS, 2 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemRepetetive>( Cat061ItemNames::I061_130_AAS, 3 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemRepetetive>( Cat061ItemNames::I061_130_AIS, 6 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemRepetetive>( Cat061ItemNames::I061_130_CFS, 2 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemRepetetive>( Cat061ItemNames::I061_130_DPS, 4 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemRepetetive>( Cat061ItemNames::I061_130_DTS, 4 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemRepetetive>( Cat061ItemNames::I061_130_ATS, 4 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemRepetetive>( Cat061ItemNames::I061_130_CCS, 2 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 9,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_130_TCS, 4 ) ) );

   // Sub UAPs for compound data items
   AsterixItemCompound::subUap_T item_240_sub_uap;
   item_240_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_240_DPF, 1 ) ) );
   item_240_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_240_SP1, 0 ) ) );
   item_240_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_240_RCT, 2 ) ) );
   item_240_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_240_PT, 1 ) ) );
   item_240_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_240_RTT, 1 ) ) );
   item_240_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_240_TAT, 1 ) ) );
   item_240_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_240_GST, 1 ) ) );
   item_240_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_240_LAT, 1 ) ) );
   item_240_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 9,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_240_AT, 1 ) ) );
   item_240_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 10,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_240_FK, 1 ) ) );
   item_240_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 11,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_240_RP, 1 ) ) );
   item_240_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 12,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_240_MNP, 1 ) ) );

   // Sub UAPs for compound data items
   AsterixItemCompound::subUap_T item_280_sub_uap;
   item_280_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_380_RP, 2 ) ) );
   item_280_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_380_DP, 1 ) ) );
   item_280_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_380_TSB, 2 ) ) );
   item_280_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_380_SRB, 2 ) ) );
   item_280_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_380_SGB, 2 ) ) );
   item_280_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_380_SAB, 2 ) ) );
   item_280_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_380_PRB, 2 ) ) );
   item_280_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_380_PGB, 2 ) ) );
   item_280_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 9,
         std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_380_PAB, 2 ) ) );

   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_000, 1 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_012, 1 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_015, 1 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_020, 3 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_030, 1 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_045, 1 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_050, 1 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemRepetetive>( Cat061ItemNames::I061_060, 8 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_070, 2 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_080, 2 ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemRepetetive>( Cat061ItemNames::I061_100, 1 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemCompound>( Cat061ItemNames::I061_130, item_130_sub_uap ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemVariableLength>( Cat061ItemNames::I061_210 ) ) );
   uap.insert( UAP_Item_T( 15, std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_220, 5 ) ) );
   uap.insert( UAP_Item_T( 16, std::make_shared<AsterixItemExtendible>( Cat061ItemNames::I061_230, 3 ) ) );
   uap.insert( UAP_Item_T( 17, std::make_shared<AsterixItemCompound>( Cat061ItemNames::I061_240, item_240_sub_uap ) ) );
   uap.insert( UAP_Item_T( 18, std::make_shared<AsterixItemRepetetive>( Cat061ItemNames::I061_330, 2 ) ) );
   uap.insert( UAP_Item_T( 19, std::make_shared<AsterixItemRepetetive>( Cat061ItemNames::I061_350, 2 ) ) );
   uap.insert( UAP_Item_T( 20, std::make_shared<AsterixItemVariableLength>( Cat061ItemNames::I061_360 ) ) );
   uap.insert( UAP_Item_T( 21, std::make_shared<AsterixItemFixedLength>( Cat061ItemNames::I061_370, 2 ) ) );
   uap.insert( UAP_Item_T( 22, std::make_shared<AsterixItemCompound>( Cat061ItemNames::I061_380, item_280_sub_uap ) ) );
}

void AsterixCategory061::setSubitems() {
   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat061ItemNames::I061_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sensor_identification.push_back(
      subitem_t( Cat061ItemNames::I061_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t message_type;
   message_type.push_back(
      subitem_t( Cat061ItemNames::I061_000_FAM,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   message_type.push_back(
      subitem_t( Cat061ItemNames::I061_000_NAT,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   subitem_map_t user_identyfication;
   user_identyfication.push_back(
      subitem_t( Cat061ItemNames::I061_012_UID,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t service_identification;
   service_identification.push_back(
      subitem_t( Cat061ItemNames::I061_015_SID,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t time_of_message;
   time_of_message.push_back(
      subitem_t( Cat061ItemNames::I061_020_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   subitem_map_t batch_number;
   batch_number.push_back(
      subitem_t( Cat061ItemNames::I061_030_BTN,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t application_version_number;
   application_version_number.push_back(
      subitem_t( Cat061ItemNames::I061_045_AVN,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t default_geographical_vol;
   default_geographical_vol.push_back(
      subitem_t( Cat061ItemNames::I061_050_DGA,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   default_geographical_vol.push_back(
      subitem_t( Cat061ItemNames::I061_050_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );

   subitem_map_t geographical_area;
   geographical_area.push_back(
      subitem_t( Cat061ItemNames::I061_060_LAT,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution25Bit ) ) );
   geographical_area.push_back(
      subitem_t( Cat061ItemNames::I061_060_LNG,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution25Bit ) ) );

   subitem_map_t lower_limit;
   lower_limit.push_back(
      subitem_t( Cat061ItemNames::I061_070_LL,
         std::make_shared<AsterixSubitemSigned>( 16, IntegerConverter::lBitsToQuarter ) ) );

   subitem_map_t upper_limit;
   upper_limit.push_back(
      subitem_t( Cat061ItemNames::I061_080_UL,
         std::make_shared<AsterixSubitemSigned>( 16, IntegerConverter::lBitsToQuarter ) ) );

   subitem_map_t connection_related_report;
   connection_related_report.push_back(
      subitem_t( Cat061ItemNames::I061_100_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t track_no_selector;
   track_no_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TNS_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_no_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TNS_TRK,
         std::make_shared<AsterixSubitemUnsigned>( 15, CommonConverter::NoneConverter ) ) );

   subitem_map_t aa_selector;
   aa_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_AAS_AA,
         std::make_shared<AsterixSubitemUnsigned>( 24, CommonConverter::NoneConverter ) ) );

   subitem_map_t aircraft_identification_selector;
   aircraft_identification_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_AIS_AI,
         std::make_shared<AsterixSubitemUnsigned>( 48, StringConverter::to6BitChar ) ) );

   subitem_map_t code_faily_selector;
   code_faily_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_CFS_WC,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   code_faily_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_CFS_M3A,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   subitem_map_t departuer_airport_selector;
   departuer_airport_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_DPS_ID,
         std::make_shared<AsterixSubitemBytes>( 32, StringConverter::toASCII ) ) );

   subitem_map_t destination_airport_selector;
   destination_airport_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_DTS_ID,
         std::make_shared<AsterixSubitemBytes>( 32, StringConverter::toASCII ) ) );

   subitem_map_t Aircraft_type_selector;
   Aircraft_type_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_ATS_AT,
         std::make_shared<AsterixSubitemBytes>( 32, StringConverter::toASCII ) ) );

   subitem_map_t control_position_selector;
   control_position_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_CCS_CENTER,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   control_position_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_CCS_POSITION,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t track_category_selector;
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_SIM,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_CSR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_PSR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_SSR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_MDS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_ADS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_VALT,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_FPC,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_CNF,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_SPI,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_GAT,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_IFR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_VFR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_CFR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_RVSM,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_FRI,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_ME,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_MI,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_category_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );

   // Add all sub items to the compound sub item
   subitem_map_t track_selector;
   track_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TNS,
         std::make_shared<AsterixSubItemRep>( 16, CommonConverter::NoneConverterBuffer,
            track_no_selector ) ) );
   track_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_AAS,
         std::make_shared<AsterixSubItemRep>( 24, CommonConverter::NoneConverterBuffer, aa_selector ) ) );
   track_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_AIS,
         std::make_shared<AsterixSubItemRep>( 48, CommonConverter::NoneConverterBuffer,
            aircraft_identification_selector ) ) );
   track_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_CFS,
         std::make_shared<AsterixSubItemRep>( 16, CommonConverter::NoneConverterBuffer,
            code_faily_selector ) ) );
   track_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_DPS,
         std::make_shared<AsterixSubItemRep>( 32, CommonConverter::NoneConverterBuffer,
            departuer_airport_selector ) ) );
   track_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_DTS,
         std::make_shared<AsterixSubItemRep>( 32, CommonConverter::NoneConverterBuffer,
            destination_airport_selector ) ) );
   track_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_ATS,
         std::make_shared<AsterixSubItemRep>( 32, CommonConverter::NoneConverterBuffer,
            Aircraft_type_selector ) ) );
   track_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_CCS,
         std::make_shared<AsterixSubItemRep>( 16, CommonConverter::NoneConverterBuffer,
            control_position_selector ) ) );
   track_selector.push_back(
      subitem_t( Cat061ItemNames::I061_130_TCS,
         std::make_shared<AsterixSubitemCompound>( 32, CommonConverter::NoneConverterBuffer,
            track_category_selector ) ) );

   subitem_map_t item_selector;
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N1,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N3,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N4,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N5,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N6,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N7,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N8,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N9,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N10,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N11,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N12,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N13,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N14,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N15,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N16,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N17,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N18,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N19,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N20,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N21,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N22,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N23,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N24,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N25,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N26,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N27,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_210_N28,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   subitem_map_t cyclical_update_characteristic;
   cyclical_update_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_220_SD,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   cyclical_update_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_220_SP,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   cyclical_update_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_220_BP,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   cyclical_update_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_220_UP,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );
   cyclical_update_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_220_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   cyclical_update_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_220_ED,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   cyclical_update_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_220_MF,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t radar_sync_characteristic;
   radar_sync_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_230_MSAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   radar_sync_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_230_MSIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   radar_sync_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_230_NOP,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   radar_sync_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_230_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   radar_sync_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_230_BSAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   radar_sync_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_230_BSIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   radar_sync_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_230_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );

   // I061/240 sub sub items definitions
   subitem_map_t discrete_parameter_flags;
   discrete_parameter_flags.push_back(
      subitem_t( Cat061ItemNames::I061_240_DPF_TLF,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   discrete_parameter_flags.push_back(
      subitem_t( Cat061ItemNames::I061_240_DPF_TNB,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   discrete_parameter_flags.push_back(
      subitem_t( Cat061ItemNames::I061_240_DPF_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   discrete_parameter_flags.push_back(
      subitem_t( Cat061ItemNames::I061_240_DPF_PLN,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   discrete_parameter_flags.push_back(
      subitem_t( Cat061ItemNames::I061_240_DPF_M3A,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   discrete_parameter_flags.push_back(
      subitem_t( Cat061ItemNames::I061_240_DPF_COR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   discrete_parameter_flags.push_back(
      subitem_t( Cat061ItemNames::I061_240_DPF_SPE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   discrete_parameter_flags.push_back(
      subitem_t( Cat061ItemNames::I061_240_DPF_MOF,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   // Add all sub items to the compound sub item
   subitem_map_t triggering_criteria;
   triggering_criteria.push_back(
      subitem_t( Cat061ItemNames::I061_240_DPF,
         std::make_shared<AsterixSubItemRep>( 16, CommonConverter::NoneConverterBuffer,
            discrete_parameter_flags ) ) );
   triggering_criteria.push_back(
      subitem_t( Cat061ItemNames::I061_240_RCT,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::geoAltitudeFt ) ) );
   triggering_criteria.push_back(
      subitem_t( Cat061ItemNames::I061_240_PT,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fraction64th ) ) );
   triggering_criteria.push_back(
      subitem_t( Cat061ItemNames::I061_240_RTT,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction4th ) ) );
   triggering_criteria.push_back(
      subitem_t( Cat061ItemNames::I061_240_TAT,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::directionHalfCircle8Bit ) ) );
   triggering_criteria.push_back(
      subitem_t( Cat061ItemNames::I061_240_GST,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   triggering_criteria.push_back(
      subitem_t( Cat061ItemNames::I061_240_LAT,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fraction16th ) ) );
   triggering_criteria.push_back(
      subitem_t( Cat061ItemNames::I061_240_AT,
         std::make_shared<AsterixSubitemUnsigned>( 8, IntegerConverter::lBitsToQuarter ) ) );
   triggering_criteria.push_back(
      subitem_t( Cat061ItemNames::I061_240_FK,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fraction8th ) ) );
   triggering_criteria.push_back(
      subitem_t( Cat061ItemNames::I061_240_RP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   triggering_criteria.push_back(
      subitem_t( Cat061ItemNames::I061_240_MNP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t service_related_report;
   service_related_report.push_back(
      subitem_t( Cat061ItemNames::I061_330_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );

   subitem_map_t sensor_selector;
   sensor_selector.push_back(
      subitem_t( Cat061ItemNames::I061_350_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sensor_selector.push_back(
      subitem_t( Cat061ItemNames::I061_350_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t sensor_item_selector;
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N1,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N3,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N4,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N5,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N6,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N7,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N8,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N9,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N10,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N11,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N12,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N13,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N14,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N15,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N16,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N17,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N18,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N19,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N20,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_item_selector.push_back(
      subitem_t( Cat061ItemNames::I061_360_N21,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   subitem_map_t periodical_update_period;
   periodical_update_period.push_back(
      subitem_t( Cat061ItemNames::I061_370_UP,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );

   // 061/380 sub sub item definitions
   subitem_map_t sensor_discrete_parameters;
   sensor_discrete_parameters.push_back(
      subitem_t( Cat061ItemNames::I061_380_DP_SSC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sensor_discrete_parameters.push_back(
      subitem_t( Cat061ItemNames::I061_380_DP_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );

   // Add all sub items to the compound sub item
   subitem_map_t aperiodical_characteristic;
   aperiodical_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_380_RP,
         std::make_shared<AsterixSubitemSigned>( 16, CommonConverter::NoneConverter ) ) );
   aperiodical_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_380_DP,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer,
            sensor_discrete_parameters ) ) );
   aperiodical_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_380_TSB,
         std::make_shared<AsterixSubitemSigned>( 16, CommonConverter::NoneConverter ) ) );
   aperiodical_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_380_SRB,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction128th ) ) );
   aperiodical_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_380_SGB,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction10ToPower6 ) ) );
   aperiodical_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_380_SAB,
         std::make_shared<AsterixSubitemSigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );
   aperiodical_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_380_PRB,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction128th ) ) );
   aperiodical_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_380_PGB,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction10ToPower6 ) ) );
   aperiodical_characteristic.push_back(
      subitem_t( Cat061ItemNames::I061_380_PAB,
         std::make_shared<AsterixSubitemSigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, message_type ) );
   subitems.insert( subitem_map_item_t( 3, user_identyfication ) );
   subitems.insert( subitem_map_item_t( 4, service_identification ) );
   subitems.insert( subitem_map_item_t( 5, time_of_message ) );
   subitems.insert( subitem_map_item_t( 6, batch_number ) );
   subitems.insert( subitem_map_item_t( 7, application_version_number ) );
   subitems.insert( subitem_map_item_t( 8, default_geographical_vol ) );
   subitems.insert( subitem_map_item_t( 9, geographical_area ) );
   subitems.insert( subitem_map_item_t( 10, lower_limit ) );
   subitems.insert( subitem_map_item_t( 11, upper_limit ) );
   subitems.insert( subitem_map_item_t( 12, connection_related_report ) );
   subitems.insert( subitem_map_item_t( 13, track_selector ) );
   subitems.insert( subitem_map_item_t( 14, item_selector ) );
   subitems.insert( subitem_map_item_t( 15, cyclical_update_characteristic ) );
   subitems.insert( subitem_map_item_t( 16, radar_sync_characteristic ) );
   subitems.insert( subitem_map_item_t( 17, triggering_criteria ) );
   subitems.insert( subitem_map_item_t( 18, service_related_report ) );
   subitems.insert( subitem_map_item_t( 19, sensor_selector ) );
   subitems.insert( subitem_map_item_t( 20, sensor_item_selector ) );
   subitems.insert( subitem_map_item_t( 21, periodical_update_period ) );
   subitems.insert( subitem_map_item_t( 22, aperiodical_characteristic ) );
}

void AsterixCategory061::fillRecord(std::shared_ptr<ReportRecordType> record) {
}
