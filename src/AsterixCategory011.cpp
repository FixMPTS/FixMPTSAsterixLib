/**
 * @file AsterixCategory011.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 18 Dec 2017
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

#include "AsterixCategory011.h"

#include "AsterixSubitemSigned.h"
#include "AsterixSubitemCompound.h"
#include "AsterixItemCompound.h"
#include "AsterixItemVariableLength.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemRepetetive.h"
#include "AsterixSubItemRep.h"
#include "AsterixSubitemBytes.h"
#include "AsterixSubitemUnsigned.h"
#include "Cat011ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "StringConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory011::AsterixCategory011() :
   AsterixCategory( 11 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory011::AsterixCategory011( int length ) :
   AsterixCategory( 11, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory011::AsterixCategory011( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 11, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory011::~AsterixCategory011() {
}

void AsterixCategory011::setUAP() {

   // Sub UAPs for compound data items
   AsterixItemCompound::subUap_T item_380_sub_uap;
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemRepetetive>( Cat011ItemNames::I011_380_MBS, 8 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_380_ADDR, 3 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_380_NUG, 0 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_380_ACAS, 3 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_380_NU1, 0 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_380_NU2, 0 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_380_NU3, 0 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_380_ACT, 4 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 9,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_380_EC, 1 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 10,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_380_NU4, 0 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 11,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_380_AT, 1 ) ) );

   AsterixItemCompound::subUap_T item_290_sub_uap;
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_290_PSR, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_290_SSR, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_290_MDA, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_290_MFL, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_290_MDS, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_290_ADS, 2 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_290_ADB, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_290_MD1, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 9,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_290_MD2, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 10,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_290_LOP, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 11,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_290_TRK, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 12,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_290_MUL, 1 ) ) );

   AsterixItemCompound::subUap_T item_390_sub_uap;
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_TAG, 2 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_CSN, 7 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_IFI, 4 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_FCT, 1 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_TAC, 4 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_WTC, 1 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_DEP, 4 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_DST, 4 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 9,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_RDS, 3 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 10,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_CFL, 2 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 11,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_CTL, 2 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 12,
         std::make_shared<AsterixItemRepetetive>( Cat011ItemNames::I011_390_TOD, 4 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 13,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_AST, 6 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 14,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_390_STS, 1 ) ) );

   AsterixItemCompound::subUap_T item_500_sub_uap;
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_500_APC, 2 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_500_APW, 4 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_500_ATH, 2 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_500_AVC, 2 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_500_ARC, 1 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_500_AAC, 2 ) ) );

   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_000, 1 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_015, 1 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_140, 3 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_041, 8 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_042, 4 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_202, 4 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_210, 2 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_060, 2 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_245, 7 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemCompound>( Cat011ItemNames::I011_380, item_380_sub_uap ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_161, 2 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemVariableLength>( Cat011ItemNames::I011_170 ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemCompound>( Cat011ItemNames::I011_290, item_290_sub_uap ) ) );
   uap.insert( UAP_Item_T( 15, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_430, 1 ) ) );
   uap.insert( UAP_Item_T( 16, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_090, 2 ) ) );
   uap.insert( UAP_Item_T( 17, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_093, 2 ) ) );
   uap.insert( UAP_Item_T( 18, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_092, 2 ) ) );
   uap.insert( UAP_Item_T( 19, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_215, 2 ) ) );
   uap.insert( UAP_Item_T( 20, std::make_shared<AsterixItemVariableLength>( Cat011ItemNames::I011_270 ) ) );
   uap.insert( UAP_Item_T( 21, std::make_shared<AsterixItemCompound>( Cat011ItemNames::I011_390, item_390_sub_uap ) ) );
   uap.insert( UAP_Item_T( 22, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_300, 1 ) ) );
   uap.insert( UAP_Item_T( 23, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_310, 1 ) ) );
   uap.insert( UAP_Item_T( 24, std::make_shared<AsterixItemCompound>( Cat011ItemNames::I011_500, item_500_sub_uap ) ) );
   uap.insert( UAP_Item_T( 25, std::make_shared<AsterixItemFixedLength>( Cat011ItemNames::I011_600, 3 ) ) );
   uap.insert( UAP_Item_T( 26, std::make_shared<AsterixItemRepetetive>( Cat011ItemNames::I011_605, 2 ) ) );
   uap.insert( UAP_Item_T( 27, std::make_shared<AsterixItemRepetetive>( Cat011ItemNames::I011_610, 2 ) ) );
}

void AsterixCategory011::setSubitems() {

   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat011ItemNames::I011_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   sensor_identification.push_back(
      subitem_t( Cat011ItemNames::I011_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t message_type;
   message_type.push_back(
      subitem_t( Cat011ItemNames::I011_000_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t service_identification;
   service_identification.push_back(
      subitem_t( Cat011ItemNames::I011_015_SID,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t time_of_track_information;
   time_of_track_information.push_back(
      subitem_t( Cat011ItemNames::I011_140_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::Fraction128th::get() ) ) );

   subitem_map_t position_wgs84;
   position_wgs84.push_back(
      subitem_t( Cat011ItemNames::I011_041_LAT,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution31Bit::get() ) ) );
   position_wgs84.push_back(
      subitem_t( Cat011ItemNames::I011_041_LNG,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution31Bit::get() ) ) );

   subitem_map_t position_cartesian;
   position_cartesian.push_back(
      subitem_t( Cat011ItemNames::I011_042_X,
         std::make_shared<AsterixSubitemSigned>( 16, CommonConverter::NoneConverter::get() ) ) );
   position_cartesian.push_back(
      subitem_t( Cat011ItemNames::I011_042_Y,
         std::make_shared<AsterixSubitemSigned>( 16, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t calculated_track_velocity;
   calculated_track_velocity.push_back(
      subitem_t( Cat011ItemNames::I011_202_VX,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::Fraction4th::get() ) ) );
   calculated_track_velocity.push_back(
      subitem_t( Cat011ItemNames::I011_202_VY,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::Fraction4th::get() ) ) );

   subitem_map_t calculated_accelaeration;
   calculated_accelaeration.push_back(
      subitem_t( Cat011ItemNames::I011_210_AX,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   calculated_accelaeration.push_back(
      subitem_t( Cat011ItemNames::I011_210_AY,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::Fraction4th::get() ) ) );

   subitem_map_t mode_3a_code_oct;
   mode_3a_code_oct.push_back(
      subitem_t( Cat011ItemNames::I011_060_SPARE,
         std::make_shared<AsterixSubitemSigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   mode_3a_code_oct.push_back(
      subitem_t( Cat011ItemNames::I011_060_CODE,
         std::make_shared<AsterixSubitemSigned>( 12, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t target_id;
   target_id.push_back(
      subitem_t( Cat011ItemNames::I011_245_STI,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   target_id.push_back(
      subitem_t( Cat011ItemNames::I011_245_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter::get() ) ) );
   target_id.push_back(
      subitem_t( Cat011ItemNames::I011_245_ID,
         std::make_shared<AsterixSubitemUnsigned>( 48, StringConverter::To6BitChar::get() ) ) );

   subitem_map_t mode_s_data;
   subitem_map_t sub_sub_item_380_mbs;
   sub_sub_item_380_mbs.push_back(
      subitem_t( Cat011ItemNames::I011_380_MBS_DATA,
         std::make_shared<AsterixSubitemUnsigned>( 56, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_mbs.push_back(
      subitem_t( Cat011ItemNames::I011_380_MBS_BDS1,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_mbs.push_back(
      subitem_t( Cat011ItemNames::I011_380_MBS_BDS2,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t sub_sub_item_380_acas;
   sub_sub_item_380_acas.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS_COM,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_acas.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS_STAT,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_acas.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_acas.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS_SSC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_acas.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS_ARC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_acas.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS_AIC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_acas.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS_B1A,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_acas.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS_B1B,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_acas.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS_AC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_acas.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS_MN,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_acas.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS_DC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_380_acas.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter::get() ) ) );

   // Add all items to the Mode S Data Compound sub item
   mode_s_data.push_back(
      subitem_t( Cat011ItemNames::I011_380_MBS,
         std::make_shared<AsterixSubItemRep>( 64, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_380_mbs ) ) );
   mode_s_data.push_back(
      subitem_t( Cat011ItemNames::I011_380_ADDR,
         std::make_shared<AsterixSubitemUnsigned>( 24, CommonConverter::NoneConverter::get() ) ) );
   mode_s_data.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACAS,
         std::make_shared<AsterixSubitemCompound>( 24, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_380_acas ) ) );
   mode_s_data.push_back(
      subitem_t( Cat011ItemNames::I011_380_ACT,
         std::make_shared<AsterixSubitemBytes>( 32, StringConverter::ToASCII::get() ) ) );
   mode_s_data.push_back(
      subitem_t( Cat011ItemNames::I011_380_EC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   mode_s_data.push_back(
      subitem_t( Cat011ItemNames::I011_380_AT,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t track_number;
   track_number.push_back(
      subitem_t( Cat011ItemNames::I011_161_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_number.push_back(
      subitem_t( Cat011ItemNames::I011_161_TRK,
         std::make_shared<AsterixSubitemUnsigned>( 15, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t track_status;
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_MON,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_GBS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_MRH,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_SRC,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_CNF,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_SIM,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_TSE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_TSB,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_FRI,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_ME,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_MI,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_AMA,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_SPI,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_CST,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_FPC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_AFF,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_PSR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_SSR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_MDS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_ADS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_SUC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat011ItemNames::I011_170_ACC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t track_update_ages;
   track_update_ages.push_back(
      subitem_t( Cat011ItemNames::I011_290_PSR,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   track_update_ages.push_back(
      subitem_t( Cat011ItemNames::I011_290_SSR,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   track_update_ages.push_back(
      subitem_t( Cat011ItemNames::I011_290_MDA,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   track_update_ages.push_back(
      subitem_t( Cat011ItemNames::I011_290_MFL,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   track_update_ages.push_back(
      subitem_t( Cat011ItemNames::I011_290_MDS,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   track_update_ages.push_back(
      subitem_t( Cat011ItemNames::I011_290_ADS,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::Fraction4th::get() ) ) );
   track_update_ages.push_back(
      subitem_t( Cat011ItemNames::I011_290_ADB,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   track_update_ages.push_back(
      subitem_t( Cat011ItemNames::I011_290_MD1,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   track_update_ages.push_back(
      subitem_t( Cat011ItemNames::I011_290_MD2,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   track_update_ages.push_back(
      subitem_t( Cat011ItemNames::I011_290_LOP,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   track_update_ages.push_back(
      subitem_t( Cat011ItemNames::I011_290_TRK,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   track_update_ages.push_back(
      subitem_t( Cat011ItemNames::I011_290_MUL,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );

   subitem_map_t phase_of_flight;
   phase_of_flight.push_back(
      subitem_t( Cat011ItemNames::I011_430_FLS,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t measure_fl;
   measure_fl.push_back(
      subitem_t( Cat011ItemNames::I011_090_FL,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::Fraction4th::get() ) ) );

   subitem_map_t calculated_geo_alt;
   calculated_geo_alt.push_back(
      subitem_t( Cat011ItemNames::I011_093_QNH,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   calculated_geo_alt.push_back(
      subitem_t( Cat011ItemNames::I011_093_ALT,
         std::make_shared<AsterixSubitemSigned>( 15, DoubleConverter::Fraction4th::get() ) ) );

   subitem_map_t baro_alt;
   baro_alt.push_back(
      subitem_t( Cat011ItemNames::I011_092_FL,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::GeoAltitudeFt::get() ) ) );

   subitem_map_t rate_cd;
   rate_cd.push_back(
      subitem_t( Cat011ItemNames::I011_215_CD,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::GeoAltitudeFt::get() ) ) );

   subitem_map_t target_size;
   target_size.push_back(
      subitem_t( Cat011ItemNames::I011_270_L,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter::get() ) ) );
   target_size.push_back(
      subitem_t( Cat011ItemNames::I011_270_O,
         std::make_shared<AsterixSubitemUnsigned>( 7, UnsignedDoubleConverter::Direction128th::get() ) ) );
   target_size.push_back(
      subitem_t( Cat011ItemNames::I011_270_W,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t flight_plan_data;

   subitem_map_t sub_sub_item_390_tag;
   sub_sub_item_390_tag.push_back(
      subitem_t( Cat011ItemNames::I011_390_TAG_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_tag.push_back(
      subitem_t( Cat011ItemNames::I011_390_TAG_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t sub_sub_item_390_ifi;
   sub_sub_item_390_ifi.push_back(
      subitem_t( Cat011ItemNames::I011_390_IFI_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_ifi.push_back(
      subitem_t( Cat011ItemNames::I011_390_IFI_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_ifi.push_back(
      subitem_t( Cat011ItemNames::I011_390_IFI_NBR,
         std::make_shared<AsterixSubitemUnsigned>( 27, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t sub_sub_item_390_fct;
   sub_sub_item_390_fct.push_back(
      subitem_t( Cat011ItemNames::I011_390_FCT_GAT,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_fct.push_back(
      subitem_t( Cat011ItemNames::I011_390_FCT_FR1,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_fct.push_back(
      subitem_t( Cat011ItemNames::I011_390_FCT_RVSM,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_fct.push_back(
      subitem_t( Cat011ItemNames::I011_390_FCT_HPR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_fct.push_back(
      subitem_t( Cat011ItemNames::I011_390_FCT_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t sub_sub_item_390_rds;
   sub_sub_item_390_rds.push_back(
      subitem_t( Cat011ItemNames::I011_390_RDS_NU1,
         std::make_shared<AsterixSubitemBytes>( 8, StringConverter::ToASCII::get() ) ) );
   sub_sub_item_390_rds.push_back(
      subitem_t( Cat011ItemNames::I011_390_RDS_NU2,
         std::make_shared<AsterixSubitemBytes>( 8, StringConverter::ToASCII::get() ) ) );
   sub_sub_item_390_rds.push_back(
      subitem_t( Cat011ItemNames::I011_390_RDS_LTR,
         std::make_shared<AsterixSubitemBytes>( 8, StringConverter::ToASCII::get() ) ) );

   subitem_map_t sub_sub_item_390_ctl;
   sub_sub_item_390_ctl.push_back(
      subitem_t( Cat011ItemNames::I011_390_CTL_C,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_ctl.push_back(
      subitem_t( Cat011ItemNames::I011_390_CTL_P,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t sub_sub_item_390_tod;
   sub_sub_item_390_tod.push_back(
      subitem_t( Cat011ItemNames::I011_390_TOD_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_tod.push_back(
      subitem_t( Cat011ItemNames::I011_390_TOD_DAY,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_tod.push_back(
      subitem_t( Cat011ItemNames::I011_390_TOD_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_tod.push_back(
      subitem_t( Cat011ItemNames::I011_390_TOD_HOR,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_tod.push_back(
      subitem_t( Cat011ItemNames::I011_390_TOD_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_tod.push_back(
      subitem_t( Cat011ItemNames::I011_390_TOD_TMIN,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_tod.push_back(
      subitem_t( Cat011ItemNames::I011_390_TOD_AVS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_tod.push_back(
      subitem_t( Cat011ItemNames::I011_390_TOD_SPARE3,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_tod.push_back(
      subitem_t( Cat011ItemNames::I011_390_TOD_SEC,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t sub_sub_item_390_sts;
   sub_sub_item_390_sts.push_back(
      subitem_t( Cat011ItemNames::I011_390_STS_EMP,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_sts.push_back(
      subitem_t( Cat011ItemNames::I011_390_STS_AVL,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_390_sts.push_back(
      subitem_t( Cat011ItemNames::I011_390_STS_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );


   // Add all flight plan sub-sub items
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_TAG,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_390_tag ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_CSN,
         std::make_shared<AsterixSubitemBytes>( 56, StringConverter::ToASCII::get() ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_IFI,
         std::make_shared<AsterixSubitemCompound>( 32, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_390_ifi ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_FCT,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_390_fct ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_TAC,
         std::make_shared<AsterixSubitemBytes>( 32, StringConverter::ToASCII::get() ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_WTC,
         std::make_shared<AsterixSubitemBytes>( 8, StringConverter::ToASCII::get() ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_DEP,
         std::make_shared<AsterixSubitemBytes>( 32, StringConverter::ToASCII::get() ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_DST,
         std::make_shared<AsterixSubitemBytes>( 32, StringConverter::ToASCII::get() ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_RDS,
         std::make_shared<AsterixSubitemCompound>( 24, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_390_rds ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_CFL,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::Fraction4th::get() ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_CTL,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_390_ctl ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_TOD,
         std::make_shared<AsterixSubItemRep>( 32, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_390_tod ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_AST,
         std::make_shared<AsterixSubitemBytes>( 48, StringConverter::ToASCII::get() ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat011ItemNames::I011_390_STS,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_390_sts ) ) );

   subitem_map_t vehicle_fleet;
   vehicle_fleet.push_back(
      subitem_t( Cat011ItemNames::I011_300_VFI,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t preprogrammed_msg;
   preprogrammed_msg.push_back(
      subitem_t( Cat011ItemNames::I011_310_TRB,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   preprogrammed_msg.push_back(
      subitem_t( Cat011ItemNames::I011_310_MSG,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t estimated_acc;
   subitem_map_t sub_sub_item_500_apc;
   sub_sub_item_500_apc.push_back(
      subitem_t( Cat011ItemNames::I011_500_APC_X,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   sub_sub_item_500_apc.push_back(
      subitem_t( Cat011ItemNames::I011_500_APC_Y,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );

   subitem_map_t sub_sub_item_500_apw;
   sub_sub_item_500_apw.push_back(
      subitem_t( Cat011ItemNames::I011_500_APW_LAT,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::WGS84resolution31Bit::get() ) ) );
   sub_sub_item_500_apw.push_back(
      subitem_t( Cat011ItemNames::I011_500_APW_LNG,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::WGS84resolution31Bit::get() ) ) );

   subitem_map_t sub_sub_item_500_avc;
   sub_sub_item_500_avc.push_back(
      subitem_t( Cat011ItemNames::I011_500_AVC_X,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::Fraction10th::get() ) ) );
   sub_sub_item_500_avc.push_back(
      subitem_t( Cat011ItemNames::I011_500_AVC_Y,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::Fraction10th::get() ) ) );

   subitem_map_t sub_sub_item_500_aac;
   sub_sub_item_500_aac.push_back(
      subitem_t( Cat011ItemNames::I011_500_AAC_X,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::Fraction100th::get() ) ) );
   sub_sub_item_500_aac.push_back(
      subitem_t( Cat011ItemNames::I011_500_AAC_Y,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::Fraction100th::get() ) ) );

   // Add all estimated accuracies to the sub item
   estimated_acc.push_back(
      subitem_t( Cat011ItemNames::I011_500_APC,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_500_apc ) ) );
   estimated_acc.push_back(
      subitem_t( Cat011ItemNames::I011_500_APW,
         std::make_shared<AsterixSubitemCompound>( 32, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_500_apw ) ) );
   estimated_acc.push_back(
      subitem_t( Cat011ItemNames::I011_500_ATH,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::Fraction4th::get() ) ) );
   estimated_acc.push_back(
      subitem_t( Cat011ItemNames::I011_500_AVC,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_500_avc ) ) );
   estimated_acc.push_back(
      subitem_t( Cat011ItemNames::I011_500_ARC,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::Fraction10th::get() ) ) );
   estimated_acc.push_back(
      subitem_t( Cat011ItemNames::I011_500_AAC,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_500_aac ) ) );

   subitem_map_t allert_msg;
   allert_msg.push_back(
      subitem_t( Cat011ItemNames::I011_600_ACK,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   allert_msg.push_back(
      subitem_t( Cat011ItemNames::I011_600_SVR,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   allert_msg.push_back(
      subitem_t( Cat011ItemNames::I011_600_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter::get() ) ) );
   allert_msg.push_back(
      subitem_t( Cat011ItemNames::I011_600_AT,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   allert_msg.push_back(
      subitem_t( Cat011ItemNames::I011_600_AN,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t alert_trk;
   alert_trk.push_back(
      subitem_t( Cat011ItemNames::I011_605_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   alert_trk.push_back(
      subitem_t( Cat011ItemNames::I011_605_TRK,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t holtbar_status;
   holtbar_status.push_back(
      subitem_t( Cat011ItemNames::I011_610_BKN,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   holtbar_status.push_back(
      subitem_t( Cat011ItemNames::I011_610_BKI,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter::get() ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, message_type ) );
   subitems.insert( subitem_map_item_t( 3, service_identification ) );
   subitems.insert( subitem_map_item_t( 4, time_of_track_information ) );
   subitems.insert( subitem_map_item_t( 5, position_wgs84 ) );
   subitems.insert( subitem_map_item_t( 6, position_cartesian ) );
   subitems.insert( subitem_map_item_t( 7, calculated_track_velocity ) );
   subitems.insert( subitem_map_item_t( 8, calculated_accelaeration ) );
   subitems.insert( subitem_map_item_t( 9, mode_3a_code_oct ) );
   subitems.insert( subitem_map_item_t( 10, target_id ) );
   subitems.insert( subitem_map_item_t( 11, mode_s_data ) );
   subitems.insert( subitem_map_item_t( 12, track_number ) );
   subitems.insert( subitem_map_item_t( 13, track_status ) );
   subitems.insert( subitem_map_item_t( 14, track_update_ages ) );
   subitems.insert( subitem_map_item_t( 15, phase_of_flight ) );
   subitems.insert( subitem_map_item_t( 16, measure_fl ) );
   subitems.insert( subitem_map_item_t( 17, calculated_geo_alt ) );
   subitems.insert( subitem_map_item_t( 18, baro_alt ) );
   subitems.insert( subitem_map_item_t( 19, rate_cd ) );
   subitems.insert( subitem_map_item_t( 20, target_size ) );
   subitems.insert( subitem_map_item_t( 21, flight_plan_data ) );
   subitems.insert( subitem_map_item_t( 22, vehicle_fleet ) );
   subitems.insert( subitem_map_item_t( 23, preprogrammed_msg ) );
   subitems.insert( subitem_map_item_t( 24, estimated_acc ) );
   subitems.insert( subitem_map_item_t( 25, allert_msg ) );
   subitems.insert( subitem_map_item_t( 26, alert_trk ) );
   subitems.insert( subitem_map_item_t( 27, holtbar_status ) );
}

void AsterixCategory011::fillRecord(std::shared_ptr<ReportRecordType> record) {
}

