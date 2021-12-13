/**
 * @file AsterixCategory020.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 11 Nov 2017
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

#include "AsterixCategory020.h"
#include "AsterixItemCompound.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemVariableLength.h"
#include "AsterixItemRepetetive.h"
#include "AsterixSubitemSigned.h"
#include "AsterixSubitemCompound.h"
#include "AsterixSubitemUnsigned.h"
#include "AsterixSubitemBitNamed.h"
#include "Cat020ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "StringConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory020::AsterixCategory020() :
   AsterixCategory( 20 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory020::AsterixCategory020( int length ) :
   AsterixCategory( 20, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory020::AsterixCategory020( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 20, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory020::~AsterixCategory020() {
}

void AsterixCategory020::setUAP() {

   // Sub UAPs for compound data items
   AsterixItemCompound::subUap_T item_500_sub_uap;
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_500_DOP, 6 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_500_SDP, 6 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_500_SDH, 2 ) ) );

   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemVariableLength>( Cat020ItemNames::I020_020 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_140, 3 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_041, 8 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_042, 6 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_161, 2 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemVariableLength>( Cat020ItemNames::I020_170 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_070, 2 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_202, 4 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_090, 2 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_100, 4 ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_220, 3 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_245, 7 ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_110, 2 ) ) );
   uap.insert( UAP_Item_T( 15, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_105, 2 ) ) );
   uap.insert( UAP_Item_T( 16, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_210, 2 ) ) );
   uap.insert( UAP_Item_T( 17, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_300, 1 ) ) );
   uap.insert( UAP_Item_T( 18, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_310, 1 ) ) );
   uap.insert( UAP_Item_T( 19, std::make_shared<AsterixItemCompound>( Cat020ItemNames::I020_500, item_500_sub_uap ) ) );
   uap.insert( UAP_Item_T( 20, std::make_shared<AsterixItemRepetetive>( Cat020ItemNames::I020_400, 1 ) ) );
   uap.insert( UAP_Item_T( 21, std::make_shared<AsterixItemRepetetive>( Cat020ItemNames::I020_250, 8 ) ) );
   uap.insert( UAP_Item_T( 22, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_230, 2 ) ) );
   uap.insert( UAP_Item_T( 23, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_260, 7 ) ) );
   uap.insert( UAP_Item_T( 24, std::make_shared<AsterixItemVariableLength>( Cat020ItemNames::I020_030 ) ) );
   uap.insert( UAP_Item_T( 25, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_055, 1 ) ) );
   uap.insert( UAP_Item_T( 26, std::make_shared<AsterixItemFixedLength>( Cat020ItemNames::I020_050, 2 ) ) );
}

void AsterixCategory020::setSubitems() {
   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat020ItemNames::I020_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sensor_identification.push_back(
      subitem_t( Cat020ItemNames::I020_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t target_report_descriptor;
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_SSR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_MS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_HF,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_VDL4,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_UAT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_DME,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_OT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_RAB,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_SPI,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_CHN,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_GBS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_CRT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_SIM,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat020ItemNames::I020_020_TST,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   subitem_map_t time_of_day;
   time_of_day.push_back(
      subitem_t( Cat020ItemNames::I020_140_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   subitem_map_t position_wgs84;
   position_wgs84.push_back(
      subitem_t( Cat020ItemNames::I020_041_LAT,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution25Bit ) ) );
   position_wgs84.push_back(
      subitem_t( Cat020ItemNames::I020_041_LNG,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution25Bit ) ) );

   subitem_map_t position_cartesian;
   position_cartesian.push_back(
      subitem_t( Cat020ItemNames::I020_042_X,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::fractionHalf ) ) );
   position_cartesian.push_back(
      subitem_t( Cat020ItemNames::I020_042_Y,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::fractionHalf ) ) );

   subitem_map_t track_number;
   track_number.push_back(
      subitem_t( Cat020ItemNames::I020_161_SPARE,
         std::make_shared<AsterixSubitemSigned>( 4, CommonConverter::NoneConverter ) ) );
   track_number.push_back(
      subitem_t( Cat020ItemNames::I020_161_TRK,
         std::make_shared<AsterixSubitemSigned>( 12, CommonConverter::NoneConverter ) ) );

   subitem_map_t track_status;
   track_status.push_back(
      subitem_t( Cat020ItemNames::I020_170_CNF,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_status.push_back(
      subitem_t( Cat020ItemNames::I020_170_TRE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_status.push_back(
      subitem_t( Cat020ItemNames::I020_170_CST,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_status.push_back(
      subitem_t( Cat020ItemNames::I020_170_CDM,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   track_status.push_back(
      subitem_t( Cat020ItemNames::I020_170_MAH,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_status.push_back(
      subitem_t( Cat020ItemNames::I020_170_STH,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_status.push_back(
      subitem_t( Cat020ItemNames::I020_170_GHO,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   subitem_map_t m3a_oct;
   m3a_oct.push_back(
      subitem_t( Cat020ItemNames::I020_070_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   m3a_oct.push_back(
      subitem_t( Cat020ItemNames::I020_070_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   m3a_oct.push_back(
      subitem_t( Cat020ItemNames::I020_070_L,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   m3a_oct.push_back(
      subitem_t( Cat020ItemNames::I020_070_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   m3a_oct.push_back(
      subitem_t( Cat020ItemNames::I020_070_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   subitem_map_t calc_track_vel_cartesian;
   calc_track_vel_cartesian.push_back(
      subitem_t( Cat020ItemNames::I020_202_VX,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction4th ) ) );
   calc_track_vel_cartesian.push_back(
      subitem_t( Cat020ItemNames::I020_202_VY,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction4th ) ) );

   subitem_map_t flightlevel_bin;
   flightlevel_bin.push_back(
      subitem_t( Cat020ItemNames::I020_090_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   flightlevel_bin.push_back(
      subitem_t( Cat020ItemNames::I020_090_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   flightlevel_bin.push_back(
      subitem_t( Cat020ItemNames::I020_090_FL,
         std::make_shared<AsterixSubitemSigned>( 14, DoubleConverter::fraction4th ) ) );

   subitem_map_t mode_c_code;
   mode_c_code.push_back(
      subitem_t( Cat020ItemNames::I020_100_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_c_code.push_back(
      subitem_t( Cat020ItemNames::I020_100_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_c_code.push_back(
      subitem_t( Cat020ItemNames::I020_100_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   mode_c_code.push_back(
      subitem_t( Cat020ItemNames::I020_100_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );
   mode_c_code.push_back(
      subitem_t( Cat020ItemNames::I020_100_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   mode_c_code.push_back(
      subitem_t( Cat020ItemNames::I020_100_PULSE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   subitem_map_t target_addr;
   target_addr.push_back(
      subitem_t( Cat020ItemNames::I020_220_ADDR,
         std::make_shared<AsterixSubitemUnsigned>( 24, CommonConverter::NoneConverter ) ) );

   subitem_map_t target_id;
   target_id.push_back(
      subitem_t( Cat020ItemNames::I020_245_STI,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   target_id.push_back(
      subitem_t( Cat020ItemNames::I020_245_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   target_id.push_back(
      subitem_t( Cat020ItemNames::I020_245_ID,
         std::make_shared<AsterixSubitemUnsigned>( 48, StringConverter::to6BitChar ) ) );

   subitem_map_t measured_height;
   measured_height.push_back(
      subitem_t( Cat020ItemNames::I020_110_ALT,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::geoAltitudeFt ) ) );

   subitem_map_t geometric_height;
   geometric_height.push_back(
      subitem_t( Cat020ItemNames::I020_105_ALT,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::geoAltitudeFt ) ) );

   subitem_map_t calculated_acceleration;
   calculated_acceleration.push_back(
      subitem_t( Cat020ItemNames::I020_210_AX,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fraction4th ) ) );
   calculated_acceleration.push_back(
      subitem_t( Cat020ItemNames::I020_210_AY,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fraction4th ) ) );

   subitem_map_t vehicle_fleet_information;
   vehicle_fleet_information.push_back(
      subitem_t( Cat020ItemNames::I020_300_VFI,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t pre_programmed_message;
   pre_programmed_message.push_back(
      subitem_t( Cat020ItemNames::I020_310_TRB,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   pre_programmed_message.push_back(
      subitem_t( Cat020ItemNames::I020_310_MSG,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );

   subitem_map_t position_accuracy;

   subitem_map_t sub_sub_item_500_dop;
   sub_sub_item_500_dop.push_back(
      subitem_t( Cat020ItemNames::I020_500_DOP_X,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction4th ) ) );
   sub_sub_item_500_dop.push_back(
      subitem_t( Cat020ItemNames::I020_500_DOP_Y,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction4th ) ) );
   sub_sub_item_500_dop.push_back(
      subitem_t( Cat020ItemNames::I020_500_DOP_XY,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction4th ) ) );

   subitem_map_t sub_sub_item_500_std;
   sub_sub_item_500_std.push_back(
      subitem_t( Cat020ItemNames::I020_500_STD_X,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction4th ) ) );
   sub_sub_item_500_std.push_back(
      subitem_t( Cat020ItemNames::I020_500_STD_Y,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction4th ) ) );
   sub_sub_item_500_std.push_back(
      subitem_t( Cat020ItemNames::I020_500_STD_XY,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction4th ) ) );

   position_accuracy.push_back(
      subitem_t( Cat020ItemNames::I020_500_DOP,
         std::make_shared<AsterixSubitemCompound>( 6, CommonConverter::NoneConverterBuffer,
            sub_sub_item_500_dop ) ) );
   position_accuracy.push_back(
      subitem_t( Cat020ItemNames::I020_500_STD,
         std::make_shared<AsterixSubitemCompound>( 6, CommonConverter::NoneConverterBuffer,
            sub_sub_item_500_std ) ) );
   position_accuracy.push_back(
      subitem_t( Cat020ItemNames::I020_500_ALT,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fractionHalf ) ) );

   subitem_map_t contributing_devices;
   contributing_devices.push_back(
      subitem_t( Cat020ItemNames::I020_400_TU,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t mode_s_mb_data;
   mode_s_mb_data.push_back(
      subitem_t( Cat020ItemNames::I020_250_DATA,
         std::make_shared<AsterixSubitemUnsigned>( 56, CommonConverter::NoneConverter ) ) );
   mode_s_mb_data.push_back(
      subitem_t( Cat020ItemNames::I020_250_BDS1,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   mode_s_mb_data.push_back(
      subitem_t( Cat020ItemNames::I020_250_BDS2,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   // ACAS Capability
   subitem_map_t acas_cap;
   acas_cap.push_back(
      subitem_t( Cat020ItemNames::I020_230_COM,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   acas_cap.push_back(
      subitem_t( Cat020ItemNames::I020_230_STAT,
         std::make_shared<AsterixSubitemBitNamed>( 3, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "AC airborne" },
               { 1, "AC on ground" }, { 2, "Alert, AC airborne" }, { 3, "Alarm AC on ground" }, { 4,
                  "Alert, SPI, AC on ground" }, { 5, "Alert, SPI, AC on ground" }, { 6, "No used" },
               { 7, "Not used" } } ) ) ) );
   acas_cap.push_back(
      subitem_t( Cat020ItemNames::I020_230_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   acas_cap.push_back(
      subitem_t( Cat020ItemNames::I020_230_MSSC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   acas_cap.push_back(
      subitem_t( Cat020ItemNames::I020_230_ARC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   acas_cap.push_back(
      subitem_t( Cat020ItemNames::I020_230_AIC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   acas_cap.push_back(
      subitem_t( Cat020ItemNames::I020_230_B1A,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   acas_cap.push_back(
      subitem_t( Cat020ItemNames::I020_230_B1B,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   // ACAS Resolution Advisory
   subitem_map_t acas_ra;
   acas_ra.push_back(
      subitem_t( Cat020ItemNames::I020_260_DATA,
         std::make_shared<AsterixSubitemUnsigned>( 56, CommonConverter::NoneConverter ) ) );

   // Warning Error Conditions
   subitem_map_t error_conditions;
   error_conditions.push_back(
      subitem_t( Cat020ItemNames::I020_030_ERR,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );

   subitem_map_t mode_one_oct;
   mode_one_oct.push_back(
      subitem_t( Cat020ItemNames::I020_055_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_one_oct.push_back(
      subitem_t( Cat020ItemNames::I020_055_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_one_oct.push_back(
      subitem_t( Cat020ItemNames::I020_055_L,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_one_oct.push_back(
      subitem_t( Cat020ItemNames::I020_055_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter ) ) );

   subitem_map_t mode_two_oct;
   mode_two_oct.push_back(
      subitem_t( Cat020ItemNames::I020_050_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_two_oct.push_back(
      subitem_t( Cat020ItemNames::I020_050_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_two_oct.push_back(
      subitem_t( Cat020ItemNames::I020_050_L,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_two_oct.push_back(
      subitem_t( Cat020ItemNames::I020_050_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_two_oct.push_back(
      subitem_t( Cat020ItemNames::I020_050_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, target_report_descriptor ) );
   subitems.insert( subitem_map_item_t( 3, time_of_day ) );
   subitems.insert( subitem_map_item_t( 4, position_wgs84 ) );
   subitems.insert( subitem_map_item_t( 5, position_cartesian ) );
   subitems.insert( subitem_map_item_t( 6, track_number ) );
   subitems.insert( subitem_map_item_t( 7, track_status ) );
   subitems.insert( subitem_map_item_t( 8, m3a_oct ) );
   subitems.insert( subitem_map_item_t( 9, calc_track_vel_cartesian ) );
   subitems.insert( subitem_map_item_t( 10, flightlevel_bin ) );
   subitems.insert( subitem_map_item_t( 11, mode_c_code ) );
   subitems.insert( subitem_map_item_t( 12, target_addr ) );
   subitems.insert( subitem_map_item_t( 13, target_id ) );
   subitems.insert( subitem_map_item_t( 14, measured_height ) );
   subitems.insert( subitem_map_item_t( 15, geometric_height ) );
   subitems.insert( subitem_map_item_t( 16, calculated_acceleration ) );
   subitems.insert( subitem_map_item_t( 17, vehicle_fleet_information ) );
   subitems.insert( subitem_map_item_t( 18, pre_programmed_message ) );
   subitems.insert( subitem_map_item_t( 19, position_accuracy ) );
   subitems.insert( subitem_map_item_t( 20, contributing_devices ) );
   subitems.insert( subitem_map_item_t( 21, mode_s_mb_data ) );
   subitems.insert( subitem_map_item_t( 22, acas_cap ) );
   subitems.insert( subitem_map_item_t( 23, acas_ra ) );
   subitems.insert( subitem_map_item_t( 24, error_conditions ) );
   subitems.insert( subitem_map_item_t( 25, mode_one_oct ) );
   subitems.insert( subitem_map_item_t( 26, mode_two_oct ) );
}

void AsterixCategory020::fillRecord(std::shared_ptr<ReportRecordType> record) {
}
