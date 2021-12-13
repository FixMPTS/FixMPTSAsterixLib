/**
 * @file AsterixCategory048.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 23 Jul 2017
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
 * See H file for more details
 */
#include "AsterixCategory048.h"
#include "AsterixCommonDef.h"
#include "AsterixItemCompoundLI.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemVariableLength.h"
#include "AsterixItemRepetetive.h"
#include "AsterixSubitemCompound.h"
#include "AsterixSubitemBitNamed.h"
#include "AsterixSubItemRep.h"
#include "AsterixSubitemUnsigned.h"
#include "Cat048ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "IntegerConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory048::AsterixCategory048() :
   AsterixCategory( 48 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory048::AsterixCategory048( int length ) :
   AsterixCategory( 48, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory048::AsterixCategory048( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 48, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory048::~AsterixCategory048() {
}

void AsterixCategory048::setUAP() {
   // Define the sub UAPs from the compound items
   AsterixItemCompound::subUap_T item_120_sub_uap;
   item_120_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_120_CAL, 2 ) ) );
   item_120_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_120_RDS, 7 ) ) );

   AsterixItemCompound::subUap_T item_130_sub_uap;
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_130_SRLL, 1 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_130_SRR, 1 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_130_SAM, 1 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_130_PRL, 1 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_130_PAM, 1 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_130_RPD, 1 ) ) );
   item_130_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_130_APD, 1 ) ) );

   AsterixItemCompound::subUap_T item_sp_sub_uap;
   item_sp_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_SP_1, 1 ) ) );

   // RE item is a compound item of compound items
   AsterixItemCompound::subUap_T item_re_md5_sub_uap;
   item_re_md5_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_RE_MD5_SUM, 2 ) ) );
   item_re_md5_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_RE_MD5_PIN, 4 ) ) );
   item_re_md5_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_RE_MD5_POS, 8 ) ) );
   item_re_md5_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_RE_MD5_GA, 2 ) ) );
   item_re_md5_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_RE_MD5_EM1, 2 ) ) );
   item_re_md5_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_RE_MD5_TOS, 1 ) ) );
   item_re_md5_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_RE_MD5_XP, 2 ) ) );


   AsterixItemCompound::subUap_T item_re_m5n_sub_uap;
   AsterixItemCompound::subUap_T item_re_m4e_sub_uap;
   AsterixItemCompound::subUap_T item_re_rpc_sub_uap;


   AsterixItemCompound::subUap_T item_re_sub_uap;
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemCompound>( Cat048ItemNames::I048_RE_MD5, item_re_md5_sub_uap ) ) );
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemCompound>( Cat048ItemNames::I048_RE_M5N, item_re_m5n_sub_uap ) ) );
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemCompound>( Cat048ItemNames::I048_RE_M4E, item_re_m4e_sub_uap ) ) );
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemCompound>( Cat048ItemNames::I048_RE_RPC, item_re_rpc_sub_uap ) ) );

   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_140, 3 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemVariableLength>( Cat048ItemNames::I048_020 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_040, 4 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_070, 2 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_090, 2 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemCompound>( Cat048ItemNames::I048_130, item_130_sub_uap ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_220, 3 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_240, 6 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemRepetetive>( Cat048ItemNames::I048_250, 8 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_161, 2 ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_042, 4 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_200, 4 ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemVariableLength>( Cat048ItemNames::I048_170 ) ) );
   uap.insert( UAP_Item_T( 15, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_210, 4 ) ) );
   uap.insert( UAP_Item_T( 16, std::make_shared<AsterixItemVariableLength>( Cat048ItemNames::I048_030 ) ) );
   uap.insert( UAP_Item_T( 17, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_080, 2 ) ) );
   uap.insert( UAP_Item_T( 18, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_100, 4 ) ) );
   uap.insert( UAP_Item_T( 19, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_110, 2 ) ) );
   uap.insert( UAP_Item_T( 20, std::make_shared<AsterixItemCompound>( Cat048ItemNames::I048_120, item_120_sub_uap ) ) );
   uap.insert( UAP_Item_T( 21, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_230, 2 ) ) );
   uap.insert( UAP_Item_T( 22, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_260, 7 ) ) );
   uap.insert( UAP_Item_T( 23, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_055, 1 ) ) );
   uap.insert( UAP_Item_T( 24, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_060, 2 ) ) );
   uap.insert( UAP_Item_T( 25, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_065, 1 ) ) );
   uap.insert( UAP_Item_T( 26, std::make_shared<AsterixItemFixedLength>( Cat048ItemNames::I048_060, 2 ) ) );
   uap.insert( UAP_Item_T( 27, std::make_shared<AsterixItemCompound>( Cat048ItemNames::I048_SP, item_sp_sub_uap ) ) );
   uap.insert( UAP_Item_T( 28, std::make_shared<AsterixItemCompoundLI>( Cat048ItemNames::I048_RE, item_re_sub_uap ) ) );
}

void AsterixCategory048::setSubitems() {
   //Sensor Identification
   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat048ItemNames::I048_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sensor_identification.push_back(
      subitem_t( Cat048ItemNames::I048_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   // Time of Day
   subitem_map_t tod;
   tod.push_back(
      subitem_t( Cat048ItemNames::I048_140_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   // Target Report Descriptor
   subitem_map_t target_report_descriptor;
   target_report_descriptor.push_back(
      subitem_t( Cat048ItemNames::I048_020_TYP,
         std::make_shared<AsterixSubitemBitNamed>( 3, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "no detection" }, { 1,
               "Single PSR detection" }, { 2, "Single SSR detection" },
               { 3, "PSR + SSR detection" }, { 4, "Mode S All-Call" }, { 5, "Mode S Roll=Call" }, {
                  6, "Mode S All-Call + PSR" }, { 7, "Mode S Roll-Call + PSR" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat048ItemNames::I048_020_SIM,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Actual Plot" },
               { 1, "Simulated Plot" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat048ItemNames::I048_020_RDP,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Chain 1" }, { 1, "Chain 2" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat048ItemNames::I048_020_SPI,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "SPI set" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat048ItemNames::I048_020_RAB,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Aircraft Transponder" }, { 1,
               "Field Transponder" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat048ItemNames::I048_020_TST,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Real Target" }, { 1, "Test Target" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat048ItemNames::I048_020_SPARE,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Spare" }, { 1, "Spare" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat048ItemNames::I048_020_XPP,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "X-Pulse present" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat048ItemNames::I048_020_ME,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" },
               { 1, "Military Emergency" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat048ItemNames::I048_020_MI,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1,
               "Military Identification" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat048ItemNames::I048_020_FOE,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Spare" }, { 1, "Friend" }, { 2,
               "Unknown" }, { 3, "No replay" } } ) ) ) );

   // Measured Position
   subitem_map_t measured_position;
   measured_position.push_back(
      subitem_t( Cat048ItemNames::I048_040_RHO,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction256th ) ) );
   measured_position.push_back(
      subitem_t( Cat048ItemNames::I048_040_THETA,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );

   // Mode 3A Code
   subitem_map_t mode_3a_code;
   mode_3a_code.push_back(
      subitem_t( Cat048ItemNames::I048_070_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // valid flag
   mode_3a_code.push_back(
      subitem_t( Cat048ItemNames::I048_070_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // garbled flag
   mode_3a_code.push_back(
      subitem_t( Cat048ItemNames::I048_070_L,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); //locally tracked flag
   mode_3a_code.push_back(
      subitem_t( Cat048ItemNames::I048_070_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // Not used
   mode_3a_code.push_back(
      subitem_t( Cat048ItemNames::I048_070_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) ); // code in octal representation

   // Flight Level in Binary (Mode C)
   subitem_map_t mode_c_code_bin;
   mode_c_code_bin.push_back(
      subitem_t( Cat048ItemNames::I048_090_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // valid flag
   mode_c_code_bin.push_back(
      subitem_t( Cat048ItemNames::I048_090_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // garbled flag
   mode_c_code_bin.push_back(
      subitem_t( Cat048ItemNames::I048_090_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 14, IntegerConverter::lBitsToQuarter ) ) ); // code in binary representation

   // Radar Plot Characteristics
   subitem_map_t radar_characteristics;
   radar_characteristics.push_back( subitem_t( Cat048ItemNames::I048_130_SRLL, // SSR Plot Runlength
      std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::direction13Bit ) ) );
   radar_characteristics.push_back( subitem_t( Cat048ItemNames::I048_130_SRR, // Number of Received Replies (M(SSR
      std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   radar_characteristics.push_back( subitem_t( Cat048ItemNames::I048_130_SAM, // Amplitude of (M(SSR Replay
      std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   radar_characteristics.push_back( subitem_t( Cat048ItemNames::I048_130_PRL, // Primary PLot Runlength
      std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::direction13Bit ) ) );
   radar_characteristics.push_back( subitem_t( Cat048ItemNames::I048_130_PAM, // Amplitude of Primary Plot
      std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   radar_characteristics.push_back( subitem_t( Cat048ItemNames::I048_130_RPD, // Difference in Range between PSR and SSR Plot
      std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fraction256th ) ) );
   radar_characteristics.push_back( subitem_t( Cat048ItemNames::I048_130_APD, // Difference in Amplitude between PSR and SSR Plot
      std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction360th ) ) );

   // Aircraft Address
   subitem_map_t aircraft_address;
   aircraft_address.push_back(
      subitem_t( Cat048ItemNames::I048_220_ADR,
         std::make_shared<AsterixSubitemUnsigned>( 24, CommonConverter::NoneConverter ) ) );

   // Aircraft Identification
   subitem_map_t aircraft_identification;
   aircraft_identification.push_back(
      subitem_t( Cat048ItemNames::I048_240_AID,
         std::make_shared<AsterixSubitemUnsigned>( 48, CommonConverter::NoneConverter ) ) );

   // Mode S MB Data
   subitem_map_t mode_s_mb_data;
   mode_s_mb_data.push_back(
      subitem_t( Cat048ItemNames::I048_250_DATA,
         std::make_shared<AsterixSubitemUnsigned>( 56, CommonConverter::NoneConverter ) ) );
   mode_s_mb_data.push_back(
      subitem_t( Cat048ItemNames::I048_250_BDS1,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   mode_s_mb_data.push_back(
      subitem_t( Cat048ItemNames::I048_250_BDS2,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   // Track NUmber
   subitem_map_t track_number;
   // First four bits not used and set to zero
   track_number.push_back(
      subitem_t( Cat048ItemNames::I048_161_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   track_number.push_back(
      subitem_t( Cat048ItemNames::I048_161_TRK,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   // Calculated Position in Cartesian Coordinates
   subitem_map_t cartesion_position;
   cartesion_position.push_back(
      subitem_t( Cat048ItemNames::I048_042_Y,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction128th ) ) );
   cartesion_position.push_back(
      subitem_t( Cat048ItemNames::I048_042_X,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction128th ) ) );

   // Calculated Polar Position
   subitem_map_t polar_position;
   polar_position.push_back(
      subitem_t( Cat048ItemNames::I048_200_GSP,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::speedNMToKt ) ) );
   polar_position.push_back(
      subitem_t( Cat048ItemNames::I048_200_HDG,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::circleSegment16Bit ) ) );

   // Track Status
   subitem_map_t track_status;
   track_status.push_back(
      subitem_t( Cat048ItemNames::I048_170_CNF,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Confirmed Track" }, { 1,
               "Tentative Track" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat048ItemNames::I048_170_RAD,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Combined Track" },
               { 1, "PSR Track" }, { 2, "SSR/MDS Track" }, { 3, "Invalid" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat048ItemNames::I048_170_DOU,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Normal Confidence" }, { 1,
               "Low Confidence" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat048ItemNames::I048_170_MAH,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Manoeuvre" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat048ItemNames::I048_170_CDM,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Maintaining" }, { 1, "Climbing" }, {
               2, "Descending" }, { 3, "Unknown" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat048ItemNames::I048_170_TRE,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Track alive" }, { 1,
               "Track terminated" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat048ItemNames::I048_170_GHO,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "True Track" }, { 1, "Ghost Track" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat048ItemNames::I048_170_SUP,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "No" }, { 1, "Yes" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat048ItemNames::I048_170_TCC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Track Corrected" } } ) ) ) );
   // The remaining bits are spare

   // Track Quality
   subitem_map_t track_quality;
   track_quality.push_back(
      subitem_t( Cat048ItemNames::I048_210_SIX,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fraction128th ) ) );
   track_quality.push_back(
      subitem_t( Cat048ItemNames::I048_210_SIY,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fraction128th ) ) );
   track_quality.push_back(
      subitem_t( Cat048ItemNames::I048_210_SIV,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fraction128th ) ) );
   track_quality.push_back(
      subitem_t( Cat048ItemNames::I048_210_SIH,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fraction128th ) ) );

   // Warning Error Conditions
   subitem_map_t error_conditions;
   error_conditions.push_back(
      subitem_t( Cat048ItemNames::I048_030_ERR,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );

   // Mode 3A Code Confidence Indicator
   subitem_map_t mode_3a_confidence;
   mode_3a_confidence.push_back(
      subitem_t( Cat048ItemNames::I048_080_QXI,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   // Mode C Code and Confidence INdicator
   subitem_map_t mode_c_code;
   mode_c_code.push_back(
      subitem_t( Cat048ItemNames::I048_100_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 14, IntegerConverter::lBitsToQuarter ) ) );
   mode_c_code.push_back( subitem_t( Cat048ItemNames::I048_100_SP1, // Spare
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   mode_c_code.push_back(
      subitem_t( Cat048ItemNames::I048_100_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_c_code.push_back(
      subitem_t( Cat048ItemNames::I048_100_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_c_code.push_back(
      subitem_t( Cat048ItemNames::I048_100_QXI,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );
   mode_c_code.push_back( subitem_t( Cat048ItemNames::I048_100_SP2, // Spare
      std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   // 3D Height Measurement
   subitem_map_t measured_height_3d;
   measured_height_3d.push_back(
      subitem_t( Cat048ItemNames::I048_110_QXI,
         std::make_shared<AsterixSubitemUnsigned>( 14, IntegerConverter::lBitsToQuarter ) ) );

   // Radial Doppler Speed
   subitem_map_t doppler_speed;
   doppler_speed.push_back(
      subitem_t( Cat048ItemNames::I048_120_CAL_D,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   doppler_speed.push_back(
      subitem_t( Cat048ItemNames::I048_120_CAL_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   doppler_speed.push_back(
      subitem_t( Cat048ItemNames::I048_120_CAL_CAL,
         std::make_shared<AsterixSubitemUnsigned>( 10, CommonConverter::NoneConverter ) ) );

   // Define the sub items for the repetitive sub item below
   subitem_map_t sub_sub_item_120_l;
   sub_sub_item_120_l.push_back(
      subitem_t( Cat048ItemNames::I048_120_RDS_DOP,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );
   sub_sub_item_120_l.push_back(
      subitem_t( Cat048ItemNames::I048_120_RDS_AMB,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );
   sub_sub_item_120_l.push_back(
      subitem_t( Cat048ItemNames::I048_120_RDS_FRQ,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );

   doppler_speed.push_back(
      subitem_t( Cat048ItemNames::I048_120_RDS,
         std::make_shared<AsterixSubItemRep>( 48, CommonConverter::NoneConverterBuffer,
            sub_sub_item_120_l ) ) );

   // ACAS Capability
   subitem_map_t acas_cap;
   acas_cap.push_back(
      subitem_t( Cat048ItemNames::I048_230_COM,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   acas_cap.push_back(
      subitem_t( Cat048ItemNames::I048_230_STAT,
         std::make_shared<AsterixSubitemBitNamed>( 3, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "AC airborne" },
               { 1, "AC on ground" }, { 2, "Alert, AC airborne" }, { 3, "Alarm AC on ground" }, { 4,
                  "Alert, SPI, AC on ground" }, { 5, "Alert, SPI, AC on ground" }, { 6, "No used" },
               { 7, "Not used" } } ) ) ) );
   acas_cap.push_back(
      subitem_t( Cat048ItemNames::I048_230_SI,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "SI Code" }, { 1, "II Code" } } ) ) ) );
   acas_cap.push_back(
      subitem_t( Cat048ItemNames::I048_230_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   acas_cap.push_back(
      subitem_t( Cat048ItemNames::I048_230_MSSC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "No" }, { 1, "Yes" } } ) ) ) );
   acas_cap.push_back(
      subitem_t( Cat048ItemNames::I048_230_ARC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "100ft resolution" }, { 1,
               "25ft resolution" } } ) ) ) );
   acas_cap.push_back(
      subitem_t( Cat048ItemNames::I048_230_AIC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "No" }, { 1, "Yes" } } ) ) ) );
   acas_cap.push_back(
      subitem_t( Cat048ItemNames::I048_230_B1A,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "No" }, { 1, "Yes" } } ) ) ) );
   acas_cap.push_back(
      subitem_t( Cat048ItemNames::I048_230_B1B,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   // ACAS Resolution Advisory
   subitem_map_t acas_ra;
   acas_ra.push_back(
      subitem_t( Cat048ItemNames::I048_260_DATA,
         std::make_shared<AsterixSubitemUnsigned>( 56, CommonConverter::NoneConverter ) ) );

   // Mode 1 Code
   subitem_map_t mode_1_code;
   mode_1_code.push_back(
      subitem_t( Cat048ItemNames::I048_055_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter ) ) );
   mode_1_code.push_back(
      subitem_t( Cat048ItemNames::I048_055_L,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_1_code.push_back(
      subitem_t( Cat048ItemNames::I048_055_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_1_code.push_back(
      subitem_t( Cat048ItemNames::I048_055_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   // Mode 2 Code
   subitem_map_t mode_2_code;
   mode_2_code.push_back(
      subitem_t( Cat048ItemNames::I048_050_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );
   mode_2_code.push_back(
      subitem_t( Cat048ItemNames::I048_050_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_2_code.push_back(
      subitem_t( Cat048ItemNames::I048_050_L,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_2_code.push_back(
      subitem_t( Cat048ItemNames::I048_050_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_2_code.push_back(
      subitem_t( Cat048ItemNames::I048_050_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   // Mode 1 COde Confidence
   subitem_map_t mode_1_confidence;
   mode_1_confidence.push_back(
      subitem_t( Cat048ItemNames::I048_065_QXI,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter ) ) );
   mode_1_confidence.push_back(
      subitem_t( Cat048ItemNames::I048_065_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );

   // Mode 2 Code Confidence
   subitem_map_t mode_2_confidence;
   mode_2_confidence.push_back(
      subitem_t( Cat048ItemNames::I048_060_QXI,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );
   mode_2_confidence.push_back(
      subitem_t( Cat048ItemNames::I048_060_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   // SP

   // RE
   // Define subitems of MD5 cpmpound sub item
   subitem_map_t sub_sub_item_re_md5;
   sub_sub_item_re_md5.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_M5,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_md5.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_ID,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_md5.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_DA,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_md5.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_M1,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_md5.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_M2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_md5.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_M3,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_md5.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_MC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   // Define subitems of PIN cpmpound sub item
   subitem_map_t sub_sub_item_re_pin;
   sub_sub_item_re_pin.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MIS,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_pin.push_back(
      subitem_t( Cat048ItemNames::I048_RE_M5SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_pin.push_back(
      subitem_t( Cat048ItemNames::I048_RE_NAT,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_pin.push_back(
      subitem_t( Cat048ItemNames::I048_RE_NAV,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_pin.push_back(
      subitem_t( Cat048ItemNames::I048_RE_M5SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_pin.push_back(
      subitem_t( Cat048ItemNames::I048_RE_PIN,
         std::make_shared<AsterixSubitemUnsigned>( 14, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_pin.push_back(
      subitem_t( Cat048ItemNames::I048_RE_M5SPARE3,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );

   // Define subitems of Position cpmpound sub item
   subitem_map_t sub_sub_item_re_pos;
   sub_sub_item_re_pos.push_back(
      subitem_t( Cat048ItemNames::I048_RE_LON,
         std::make_shared<AsterixSubitemUnsigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );
   sub_sub_item_re_pos.push_back(
      subitem_t( Cat048ItemNames::I048_RE_LAT,
         std::make_shared<AsterixSubitemUnsigned>( 25, DoubleConverter::WGS84resolution23Bit ) ) );

   // Define subitems of Position GNSS derived altitude sub item
   subitem_map_t sub_sub_item_re_ga;
   sub_sub_item_re_pos.push_back(
      subitem_t( Cat048ItemNames::I048_RE_GA,
         std::make_shared<AsterixSubitemUnsigned>( 24, IntegerConverter::lBitsToQuarter ) ) );
   sub_sub_item_re_ga.push_back(
      subitem_t( Cat048ItemNames::I048_RE_RES,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "100ft resolution" }, { 1,
               "25ft resolution" } } ) ) ) );

   // Define subitem Mode 1 Code of RE MD5 field
   subitem_map_t sub_sub_item_re_m1;
   sub_sub_item_re_m1.push_back(
      subitem_t( Cat048ItemNames::I048_RE_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_m1.push_back(
      subitem_t( Cat048ItemNames::I048_RE_M1SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_m1.push_back(
      subitem_t( Cat048ItemNames::I048_RE_L,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_m1.push_back(
      subitem_t( Cat048ItemNames::I048_RE_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_re_m1.push_back(
      subitem_t( Cat048ItemNames::I048_RE_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   // Define subitems TOS of cpmpound MD5 sub item
   subitem_map_t sub_sub_item_re_tos;
   sub_sub_item_re_tos.push_back(
      subitem_t( Cat048ItemNames::I048_RE_TOS,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   // Define subitems X Pulse of cpmpound MD5 sub item
   subitem_map_t sub_sub_item_re_xp;
   sub_sub_item_re_xp.push_back(
      subitem_t( Cat048ItemNames::I048_RE_X1,
         std::make_shared<AsterixSubitemUnsigned>( 1, UnsignedDoubleConverter::fraction128th ) ) );
   sub_sub_item_re_xp.push_back(
      subitem_t( Cat048ItemNames::I048_RE_X2,
         std::make_shared<AsterixSubitemUnsigned>( 1, UnsignedDoubleConverter::fraction128th ) ) );
   sub_sub_item_re_xp.push_back(
      subitem_t( Cat048ItemNames::I048_RE_X3,
         std::make_shared<AsterixSubitemUnsigned>( 1, UnsignedDoubleConverter::fraction128th ) ) );
   sub_sub_item_re_xp.push_back(
      subitem_t( Cat048ItemNames::I048_RE_XC,
         std::make_shared<AsterixSubitemUnsigned>( 1, UnsignedDoubleConverter::fraction128th ) ) );
   sub_sub_item_re_xp.push_back(
      subitem_t( Cat048ItemNames::I048_RE_X5,
         std::make_shared<AsterixSubitemUnsigned>( 1, UnsignedDoubleConverter::fraction128th ) ) );
   // REmaining Bits are spare

   // Add all subitems to the MD5 item
   subitem_map_t reserved_expansion_field;
   reserved_expansion_field.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_SUM,
         std::make_shared<AsterixSubitemCompound>( -1, CommonConverter::NoneConverterBuffer,
            sub_sub_item_re_md5 ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_PIN,
         std::make_shared<AsterixSubitemCompound>( -1, CommonConverter::NoneConverterBuffer,
            sub_sub_item_re_pin ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_POS,
         std::make_shared<AsterixSubitemCompound>( -1, CommonConverter::NoneConverterBuffer,
            sub_sub_item_re_pos ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_GA,
         std::make_shared<AsterixSubitemCompound>( -1, CommonConverter::NoneConverterBuffer,
            sub_sub_item_re_ga ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_EM1,
         std::make_shared<AsterixSubitemCompound>( -1, CommonConverter::NoneConverterBuffer,
            sub_sub_item_re_m1 ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_TOS,
         std::make_shared<AsterixSubitemCompound>( -1, CommonConverter::NoneConverterBuffer,
            sub_sub_item_re_tos ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat048ItemNames::I048_RE_MD5_XP,
         std::make_shared<AsterixSubitemCompound>( -1, CommonConverter::NoneConverterBuffer,
            sub_sub_item_re_xp ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, tod ) );
   subitems.insert( subitem_map_item_t( 3, target_report_descriptor ) );
   subitems.insert( subitem_map_item_t( 4, measured_position ) );
   subitems.insert( subitem_map_item_t( 5, mode_3a_code ) );
   subitems.insert( subitem_map_item_t( 6, mode_c_code_bin ) );
   subitems.insert( subitem_map_item_t( 7, radar_characteristics ) );
   subitems.insert( subitem_map_item_t( 8, aircraft_address ) );
   subitems.insert( subitem_map_item_t( 9, aircraft_identification ) );
   subitems.insert( subitem_map_item_t( 10, mode_s_mb_data ) );
   subitems.insert( subitem_map_item_t( 11, track_number ) );
   subitems.insert( subitem_map_item_t( 12, cartesion_position ) );
   subitems.insert( subitem_map_item_t( 13, polar_position ) );
   subitems.insert( subitem_map_item_t( 14, track_status ) );
   subitems.insert( subitem_map_item_t( 15, track_quality ) );
   subitems.insert( subitem_map_item_t( 16, error_conditions ) );
   subitems.insert( subitem_map_item_t( 17, mode_3a_confidence ) );
   subitems.insert( subitem_map_item_t( 18, mode_c_code ) );
   subitems.insert( subitem_map_item_t( 19, measured_height_3d ) );
   subitems.insert( subitem_map_item_t( 20, doppler_speed ) );
   subitems.insert( subitem_map_item_t( 21, acas_cap ) );
   subitems.insert( subitem_map_item_t( 22, acas_ra ) );
   subitems.insert( subitem_map_item_t( 23, mode_1_code ) );
   subitems.insert( subitem_map_item_t( 24, mode_2_code ) );
   subitems.insert( subitem_map_item_t( 25, mode_1_confidence ) );
   subitems.insert( subitem_map_item_t( 26, mode_2_confidence ) );
   subitems.insert( subitem_map_item_t( 28, reserved_expansion_field ) );
}

void AsterixCategory048::fillRecord(std::shared_ptr<ReportRecordType> record) {
}
