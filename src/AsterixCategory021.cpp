/**
 * @file AsterixCategory021.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 19 Sep 2017
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
 * See H file for more informations
 */

#include "AsterixCategory021.h"
#include "AsterixItemCompoundLI.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemRepetetive.h"
#include "AsterixItemVariableLengthFlex.h"
#include "AsterixSubitemSigned.h"
#include "AsterixSubitemCompound.h"
#include "AsterixSubItemRep.h"
#include "AsterixSubitemUnsigned.h"
#include "AsterixSubitemBitNamed.h"
#include "Cat021ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "IntegerConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory021::AsterixCategory021() :
   AsterixCategory( 21 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory021::AsterixCategory021( int length ) :
   AsterixCategory( 21, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory021::AsterixCategory021( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 21, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory021::~AsterixCategory021() {
}

void AsterixCategory021::setUAP() {
   // Sub UAPs for compound data items
   AsterixItemCompound::subUap_T item_220_sub_uap;
   item_220_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_220_WS, 2 ) ) );
   item_220_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_220_WD, 2 ) ) );
   item_220_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_220_TMP, 2 ) ) );
   item_220_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_220_TRB, 1 ) ) );

   AsterixItemCompound::subUap_T item_110_sub_uap;
   item_110_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_110_TIS, 1 ) ) );
   item_110_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemRepetetive>( Cat021ItemNames::I021_110_TID, 15 ) ) );

   AsterixItemCompound::subUap_T item_296_sub_uap;
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_AOS, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_TRD, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_M3A, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_QI, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_TI, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_MAM, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_GH, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_FL, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 9,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_ISA, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 10,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_FSA, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 11,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_AS, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 12,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_TAS, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 13,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_MH, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 14,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_BVR, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 15,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_GVR, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 16,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_GV, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 17,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_TAR, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 18,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_TIA, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 19,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_TS, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 20,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_MET, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 21,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_ROA, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 22,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_ARA, 1 ) ) );
   item_296_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 23,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_295_SCC, 1 ) ) );

   AsterixItemCompound::subUap_T item_re_mes_sub_uap;
   item_re_mes_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_RE_MES_SUM, 1 ) ) );
   item_re_mes_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_RE_MES_PNO, 4 ) ) );
   item_re_mes_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_RE_MES_EM1, 2 ) ) );
   item_re_mes_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_RE_MES_XP, 1 ) ) );
   item_re_mes_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_RE_MES_FOM, 1 ) ) );
   item_re_mes_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_RE_MES_M2, 2 ) ) );

   AsterixItemCompound::subUap_T item_re_sub_uap;
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_RE_BPS, 2 ) ) );
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_RE_SELH, 2 ) ) );
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_RE_NAV, 1 ) ) );
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_RE_GAO, 1 ) ) );
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemVariableLengthFlex>( Cat021ItemNames::I021_RE_SGV, 2 ) ) );
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemVariableLength>( Cat021ItemNames::I021_RE_STA ) ) );
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemCompound>( Cat021ItemNames::I021_RE_MES, item_re_mes_sub_uap ) ) );

   AsterixItemCompound::subUap_T item_sp_sub_uap;

   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemVariableLength>( Cat021ItemNames::I021_040 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_161, 2 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_015, 1 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_071, 3 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_130, 6 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_131, 8 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_072, 3 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_150, 2 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_151, 2 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_080, 3 ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_073, 3 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_074, 4 ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_075, 3 ) ) );
   uap.insert( UAP_Item_T( 15, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_076, 4 ) ) );
   uap.insert( UAP_Item_T( 16, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_140, 3 ) ) );
   uap.insert( UAP_Item_T( 17, std::make_shared<AsterixItemVariableLength>( Cat021ItemNames::I021_090 ) ) );
   uap.insert( UAP_Item_T( 18, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_210, 1 ) ) );
   uap.insert( UAP_Item_T( 19, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_070, 2 ) ) );
   uap.insert( UAP_Item_T( 20, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_230, 2 ) ) );
   uap.insert( UAP_Item_T( 21, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_145, 2 ) ) );
   uap.insert( UAP_Item_T( 22, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_152, 2 ) ) );
   uap.insert( UAP_Item_T( 23, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_200, 1 ) ) );
   uap.insert( UAP_Item_T( 24, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_155, 2 ) ) );
   uap.insert( UAP_Item_T( 25, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_157, 2 ) ) );
   uap.insert( UAP_Item_T( 26, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_160, 4 ) ) );
   uap.insert( UAP_Item_T( 27, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_165, 2 ) ) );
   uap.insert( UAP_Item_T( 28, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_077, 3 ) ) );
   uap.insert( UAP_Item_T( 29, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_170, 6 ) ) );
   uap.insert( UAP_Item_T( 30, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_020, 1 ) ) );
   uap.insert( UAP_Item_T( 31, std::make_shared<AsterixItemCompound>( Cat021ItemNames::I021_220, item_220_sub_uap ) ) );
   uap.insert( UAP_Item_T( 32, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_146, 2 ) ) );
   uap.insert( UAP_Item_T( 33, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_148, 2 ) ) );
   uap.insert( UAP_Item_T( 34, std::make_shared<AsterixItemCompound>( Cat021ItemNames::I021_110, item_110_sub_uap ) ) );
   uap.insert( UAP_Item_T( 35, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_016, 1 ) ) );
   uap.insert( UAP_Item_T( 36, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_008, 1 ) ) );
   uap.insert( UAP_Item_T( 37, std::make_shared<AsterixItemVariableLength>( Cat021ItemNames::I021_271 ) ) );
   uap.insert( UAP_Item_T( 38, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_132, 1 ) ) );
   uap.insert( UAP_Item_T( 39, std::make_shared<AsterixItemRepetetive>( Cat021ItemNames::I021_250, 8 ) ) );
   uap.insert( UAP_Item_T( 40, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_260, 7 ) ) );
   uap.insert( UAP_Item_T( 41, std::make_shared<AsterixItemFixedLength>( Cat021ItemNames::I021_400, 1 ) ) );
   uap.insert( UAP_Item_T( 42, std::make_shared<AsterixItemCompound>( Cat021ItemNames::I021_295, item_296_sub_uap ) ) );
   // FRN 43 to 47 are spare
   uap.insert( UAP_Item_T( 48, std::make_shared<AsterixItemCompoundLI>( Cat021ItemNames::I021_RE, item_re_sub_uap ) ) );
   uap.insert( UAP_Item_T( 49, std::make_shared<AsterixItemCompound>( Cat021ItemNames::I021_SP, item_sp_sub_uap ) ) );
}

void AsterixCategory021::setSubitems() {
   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat021ItemNames::I021_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sensor_identification.push_back(
      subitem_t( Cat021ItemNames::I021_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t target_report_descriptor;
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_ATP,
         std::make_shared<AsterixSubitemBitNamed>( 3, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "24-Bit ICAO address" }, { 1, "Duplicate address" }, { 2,
                  "Surface vehicle address" }, { 3, "Anonymous address" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_ARC,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "25 ft" }, { 1, "100 ft" }, { 2,
               "Unknown" }, { 3, "Invalid" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_RC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1,
               "Range Check passedt" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_RAB,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1, "FFT" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_DCR,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1,
               "Differential correction" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_GBS,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Ground Bit not set" }, { 1, "Ground Bit set" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_SIM,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Simulated Taregt" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_TST,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Test Target" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_SAA,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1,
               "Not Capable of selected altitude" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_CL,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Valid" }, { 1, "Suspect" }, { 2,
               "No information" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_LLC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1,
               "Lookup failed" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_IPC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Check failed" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_NOGO,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "NOGO Bit set" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_CPR,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1,
               "CPR validation failed" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_LDPJ,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "LDPJ detected" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat021ItemNames::I021_040_RCF,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" },
               { 1, "Range check failed" } } ) ) ) );

   subitem_map_t track_number;
   track_number.push_back(
      subitem_t( Cat021ItemNames::I021_161_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   track_number.push_back(
      subitem_t( Cat021ItemNames::I021_161_TRKNR,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   subitem_map_t service_identification;
   service_identification.push_back(
      subitem_t( Cat021ItemNames::I021_015_SI,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t time_of_position;
   time_of_position.push_back(
      subitem_t( Cat021ItemNames::I021_071_TIME,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   subitem_map_t pos_wgs_low;
   pos_wgs_low.push_back(
      subitem_t( Cat021ItemNames::I021_130_LAT,
         std::make_shared<AsterixSubitemUnsigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );
   pos_wgs_low.push_back(
      subitem_t( Cat021ItemNames::I021_130_LNG,
         std::make_shared<AsterixSubitemUnsigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );

   subitem_map_t pos_wgs_high;
   pos_wgs_high.push_back(
      subitem_t( Cat021ItemNames::I021_131_LAT,
         std::make_shared<AsterixSubitemUnsigned>( 32, DoubleConverter::WGS84resolution30Bit ) ) );
   pos_wgs_high.push_back(
      subitem_t( Cat021ItemNames::I021_131_LNG,
         std::make_shared<AsterixSubitemUnsigned>( 32, DoubleConverter::WGS84resolution30Bit ) ) );

   subitem_map_t time_of_velocity;
   time_of_velocity.push_back(
      subitem_t( Cat021ItemNames::I021_072_TIME,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   subitem_map_t air_speed;
   air_speed.push_back(
      subitem_t( Cat021ItemNames::I021_150_IM,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   air_speed.push_back(
      subitem_t( Cat021ItemNames::I021_150_SPEED,
         std::make_shared<AsterixSubitemUnsigned>( 15, CommonConverter::NoneConverter ) ) );

   subitem_map_t true_air_speed;
   true_air_speed.push_back(
      subitem_t( Cat021ItemNames::I021_151_RE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   true_air_speed.push_back(
      subitem_t( Cat021ItemNames::I021_151_SPEED,
         std::make_shared<AsterixSubitemUnsigned>( 15, CommonConverter::NoneConverter ) ) );

   subitem_map_t target_address;
   target_address.push_back(
      subitem_t( Cat021ItemNames::I021_080_ADDR,
         std::make_shared<AsterixSubitemUnsigned>( 24, CommonConverter::NoneConverter ) ) );

   subitem_map_t time_of_recept_position;
   time_of_recept_position.push_back(
      subitem_t( Cat021ItemNames::I021_073_TIME,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction30Bit ) ) );

   subitem_map_t time_of_recept_position_h;
   time_of_recept_position_h.push_back(
      subitem_t( Cat021ItemNames::I021_074_FSI,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   time_of_recept_position_h.push_back(
      subitem_t( Cat021ItemNames::I021_074_TIME,
         std::make_shared<AsterixSubitemUnsigned>( 30, UnsignedDoubleConverter::fraction30Bit ) ) );

   subitem_map_t time_of_recept_velocity_l;
   time_of_recept_velocity_l.push_back(
      subitem_t( Cat021ItemNames::I021_075_TIME,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   subitem_map_t time_of_recept_velocity_h;
   time_of_recept_velocity_h.push_back(
      subitem_t( Cat021ItemNames::I021_076_FSI,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   time_of_recept_velocity_h.push_back(
      subitem_t( Cat021ItemNames::I021_076_TIME,
         std::make_shared<AsterixSubitemUnsigned>( 30, UnsignedDoubleConverter::fraction30Bit ) ) );

   subitem_map_t geometric_height;
   geometric_height.push_back(
      subitem_t( Cat021ItemNames::I021_140_GH,
         std::make_shared<AsterixSubitemUnsigned>( 24, DoubleConverter::geoAltitudeFt ) ) );

   subitem_map_t quality_indicator;
   quality_indicator.push_back(
      subitem_t( Cat021ItemNames::I021_090_NUCR,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   quality_indicator.push_back(
      subitem_t( Cat021ItemNames::I021_090_NUCP,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   quality_indicator.push_back(
      subitem_t( Cat021ItemNames::I021_090_NICB,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   quality_indicator.push_back(
      subitem_t( Cat021ItemNames::I021_090_SIL,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   quality_indicator.push_back(
      subitem_t( Cat021ItemNames::I021_090_NACP,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   quality_indicator.push_back(
      subitem_t( Cat021ItemNames::I021_090_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   quality_indicator.push_back(
      subitem_t( Cat021ItemNames::I021_090_SILS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   quality_indicator.push_back(
      subitem_t( Cat021ItemNames::I021_090_SDA,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   quality_indicator.push_back(
      subitem_t( Cat021ItemNames::I021_090_GVA,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   quality_indicator.push_back(
      subitem_t( Cat021ItemNames::I021_090_PIC,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   subitem_map_t mops_version;
   mops_version.push_back(
      subitem_t( Cat021ItemNames::I021_210_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mops_version.push_back(
      subitem_t( Cat021ItemNames::I021_210_VNS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mops_version.push_back(
      subitem_t( Cat021ItemNames::I021_210_VN,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   mops_version.push_back(
      subitem_t( Cat021ItemNames::I021_210_LTT,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );

   subitem_map_t m3a_oct;
   m3a_oct.push_back(
      subitem_t( Cat021ItemNames::I021_070_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   m3a_oct.push_back(
      subitem_t( Cat021ItemNames::I021_070_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   subitem_map_t roll_angle;
   roll_angle.push_back(
      subitem_t( Cat021ItemNames::I021_230_RA,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::fraction100th ) ) );

   subitem_map_t flight_level;
   flight_level.push_back(
      subitem_t( Cat021ItemNames::I021_145_FL,
         std::make_shared<AsterixSubitemUnsigned>( 16, IntegerConverter::lBitsToQuarter ) ) );

   subitem_map_t magnetic_heading;
   magnetic_heading.push_back(
      subitem_t( Cat021ItemNames::I021_152_HDG,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );

   subitem_map_t target_status;
   target_status.push_back(
      subitem_t( Cat021ItemNames::I021_200_ICF,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "No Change" }, { 1, "Intent Change" } } ) ) ) );
   target_status.push_back(
      subitem_t( Cat021ItemNames::I021_200_LNAV,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Engaged" }, { 1, "Not engaged" } } ) ) ) );
   target_status.push_back(
      subitem_t( Cat021ItemNames::I021_200_ME,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "NomMil emergency" }, { 1,
               "Mil emergency" } } ) ) ) );
   target_status.push_back(
      subitem_t( Cat021ItemNames::I021_200_PS,
         std::make_shared<AsterixSubitemBitNamed>( 3, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "No emergency" }, { 1,
               "General emergency" }, { 2, "Lifeguard" }, { 3, "Minimum fuel" }, { 4, "No Comm" }, {
               5, "Unlawful interceptance" }, { 6, "Downed Aircraft" } } ) ) ) );
   target_status.push_back(
      subitem_t( Cat021ItemNames::I021_200_SS,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "No condition reported" }, { 1,
               "Permanent Alert" }, { 2, "Temporary Alert" }, { 3, "SPI set" } } ) ) ) );

   subitem_map_t barp_vertical_rate;
   barp_vertical_rate.push_back(
      subitem_t( Cat021ItemNames::I021_155_RE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   barp_vertical_rate.push_back(
      subitem_t( Cat021ItemNames::I021_155_RATE,
         std::make_shared<AsterixSubitemUnsigned>( 15, DoubleConverter::verticalRate ) ) );

   subitem_map_t geo_vertical_rate;
   geo_vertical_rate.push_back(
      subitem_t( Cat021ItemNames::I021_157_RE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   geo_vertical_rate.push_back(
      subitem_t( Cat021ItemNames::I021_157_RATE,
         std::make_shared<AsterixSubitemUnsigned>( 15, DoubleConverter::verticalRate ) ) );

   subitem_map_t airborn_ground_vector;
   airborn_ground_vector.push_back(
      subitem_t( Cat021ItemNames::I021_160_RE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   airborn_ground_vector.push_back(
      subitem_t( Cat021ItemNames::I021_160_GSP,
         std::make_shared<AsterixSubitemUnsigned>( 15, UnsignedDoubleConverter::speedNMToKt ) ) );
   airborn_ground_vector.push_back(
      subitem_t( Cat021ItemNames::I021_160_TA,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );

   subitem_map_t track_angle_rate;
   track_angle_rate.push_back(
      subitem_t( Cat021ItemNames::I021_165_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   track_angle_rate.push_back(
      subitem_t( Cat021ItemNames::I021_165_TAR,
         std::make_shared<AsterixSubitemUnsigned>( 10, UnsignedDoubleConverter::fraction32nd ) ) );

   subitem_map_t time_of_repor_transmission;
   time_of_repor_transmission.push_back(
      subitem_t( Cat021ItemNames::I021_077_TIME,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   subitem_map_t target_identification;
   target_identification.push_back(
      subitem_t( Cat021ItemNames::I021_170_ID,
         std::make_shared<AsterixSubitemUnsigned>( 48, CommonConverter::NoneConverter ) ) );

   subitem_map_t emitter_cat;
   emitter_cat.push_back(
      subitem_t( Cat021ItemNames::I021_020_ECAT,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t met_information;
   met_information.push_back(
      subitem_t( Cat021ItemNames::I021_220_WS,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );
   met_information.push_back(
      subitem_t( Cat021ItemNames::I021_220_WD,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );
   met_information.push_back(
      subitem_t( Cat021ItemNames::I021_220_TMP,
         std::make_shared<AsterixSubitemSigned>( 16, CommonConverter::NoneConverter ) ) );
   met_information.push_back(
      subitem_t( Cat021ItemNames::I021_220_TRB,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t selected_altitude;
   selected_altitude.push_back(
      subitem_t( Cat021ItemNames::I021_146_SAS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   selected_altitude.push_back(
      subitem_t( Cat021ItemNames::I021_146_SRC,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   selected_altitude.push_back(
      subitem_t( Cat021ItemNames::I021_146_ALT,
         std::make_shared<AsterixSubitemUnsigned>( 13, IntegerConverter::alt25ft ) ) );

   subitem_map_t final_state_selected_alt;
   final_state_selected_alt.push_back(
      subitem_t( Cat021ItemNames::I021_148_MV,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   final_state_selected_alt.push_back(
      subitem_t( Cat021ItemNames::I021_148_AH,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   final_state_selected_alt.push_back(
      subitem_t( Cat021ItemNames::I021_148_AM,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   final_state_selected_alt.push_back(
      subitem_t( Cat021ItemNames::I021_148_ALT,
         std::make_shared<AsterixSubitemUnsigned>( 13, IntegerConverter::alt25ft ) ) );

   subitem_map_t trajectory_intent;

   subitem_map_t sub_sub_item_110_tis;
   sub_sub_item_110_tis.push_back(
      subitem_t( Cat021ItemNames::I021_110_TIS_NVA,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_110_tis.push_back(
      subitem_t( Cat021ItemNames::I021_110_TIS_NVB,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_110_tis.push_back(
      subitem_t( Cat021ItemNames::I021_110_TIS_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );

   subitem_map_t sub_sub_item_110_tid;
   sub_sub_item_110_tid.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID_TCA,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_110_tid.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID_NC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_110_tid.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID_TCP,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   sub_sub_item_110_tid.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID_ALT,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::fact10 ) ) );
   sub_sub_item_110_tid.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID_LAT,
         std::make_shared<AsterixSubitemUnsigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );
   sub_sub_item_110_tid.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID_LNG,
         std::make_shared<AsterixSubitemUnsigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );
   sub_sub_item_110_tid.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID_PT,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   sub_sub_item_110_tid.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID_TD,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   sub_sub_item_110_tid.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID_TRA,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_110_tid.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID_TOA,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_sub_item_110_tid.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID_TOV,
         std::make_shared<AsterixSubitemUnsigned>( 24, CommonConverter::NoneConverter ) ) );
   sub_sub_item_110_tid.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID_TTR,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::fraction100th ) ) );

   trajectory_intent.push_back(
      subitem_t( Cat021ItemNames::I021_110_TIS,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer,
            sub_sub_item_110_tis ) ) );
   trajectory_intent.push_back(
      subitem_t( Cat021ItemNames::I021_110_TID,
         std::make_shared<AsterixSubItemRep>( 120, CommonConverter::NoneConverterBuffer,
            sub_sub_item_110_tid ) ) );

   subitem_map_t service_management;
   service_management.push_back(
      subitem_t( Cat021ItemNames::I021_016_RP,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::fractionHalf ) ) );

   subitem_map_t aircraft_operational_status;
   aircraft_operational_status.push_back(
      subitem_t( Cat021ItemNames::I021_008_RA,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "RA not active" }, { 1, "RA active" } } ) ) ) );
   aircraft_operational_status.push_back(
      subitem_t( Cat021ItemNames::I021_008_TC,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "No capability" }, { 1, "TC+0 only" },
               { 2, "Multiple TC" }, { 3, "Reserved" } } ) ) ) );
   aircraft_operational_status.push_back(
      subitem_t( Cat021ItemNames::I021_008_TS,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "no capability" }, { 1,
               "Supporting target status" } } ) ) ) );
   aircraft_operational_status.push_back(
      subitem_t( Cat021ItemNames::I021_008_ARV,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Np capability" }, { 1,
               "Support ARV generation" } } ) ) ) );
   aircraft_operational_status.push_back(
      subitem_t( Cat021ItemNames::I021_008_CDT,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "CDTI not operational" }, { 1,
               "CDTI operational" } } ) ) ) );
   aircraft_operational_status.push_back(
      subitem_t( Cat021ItemNames::I021_008_TCAS,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "TCAS operatinal" }, { 1,
               "TCAS not operational" } } ) ) ) );
   aircraft_operational_status.push_back(
      subitem_t( Cat021ItemNames::I021_008_SA,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Antenna Diversity" }, { 1,
               "Single Antenna" } } ) ) ) );

   subitem_map_t surface_capabilities;
   surface_capabilities.push_back(
      subitem_t( Cat021ItemNames::I021_271_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   surface_capabilities.push_back(
      subitem_t( Cat021ItemNames::I021_271_POA,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   surface_capabilities.push_back(
      subitem_t( Cat021ItemNames::I021_271_CDTE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   surface_capabilities.push_back(
      subitem_t( Cat021ItemNames::I021_271_B2E,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   surface_capabilities.push_back(
      subitem_t( Cat021ItemNames::I021_271_RAS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   surface_capabilities.push_back(
      subitem_t( Cat021ItemNames::I021_271_IDENT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   surface_capabilities.push_back(
      subitem_t( Cat021ItemNames::I021_271_LW,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   surface_capabilities.push_back(
      subitem_t( Cat021ItemNames::I021_271_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );

   subitem_map_t message_ampltitude;
   message_ampltitude.push_back(
      subitem_t( Cat021ItemNames::I021_132_MAM,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t mode_s_mb_Data;
   mode_s_mb_Data.push_back(
      subitem_t( Cat021ItemNames::I021_250_DATA,
         std::make_shared<AsterixSubitemUnsigned>( 56, CommonConverter::NoneConverter ) ) );
   mode_s_mb_Data.push_back(
      subitem_t( Cat021ItemNames::I021_250_BDS1,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   mode_s_mb_Data.push_back(
      subitem_t( Cat021ItemNames::I021_250_BDS2,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   subitem_map_t acas_resolution;
   acas_resolution.push_back(
      subitem_t( Cat021ItemNames::I021_260_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter ) ) );
   acas_resolution.push_back(
      subitem_t( Cat021ItemNames::I021_260_STYP,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   acas_resolution.push_back(
      subitem_t( Cat021ItemNames::I021_260_ARA,
         std::make_shared<AsterixSubitemUnsigned>( 14, CommonConverter::NoneConverter ) ) );
   acas_resolution.push_back(
      subitem_t( Cat021ItemNames::I021_260_RAC,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   acas_resolution.push_back(
      subitem_t( Cat021ItemNames::I021_260_RAT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   acas_resolution.push_back(
      subitem_t( Cat021ItemNames::I021_260_MTE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   acas_resolution.push_back(
      subitem_t( Cat021ItemNames::I021_260_TTI,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   acas_resolution.push_back(
      subitem_t( Cat021ItemNames::I021_260_TID,
         std::make_shared<AsterixSubitemUnsigned>( 26, CommonConverter::NoneConverter ) ) );

   subitem_map_t receiver_id;
   receiver_id.push_back(
      subitem_t( Cat021ItemNames::I021_400_ID,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t data_ages;
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_AOS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_TRD,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_M3A,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_QI,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_TI,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_MAM,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_GH,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_FL,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_ISA,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_FSA,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_AS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_TAS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_MH,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_BVR,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_GVR,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_GV,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_TAR,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_TIA,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_TS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_MET,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_ROA,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_ARA,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );
   data_ages.push_back(
      subitem_t( Cat021ItemNames::I021_295_SCC,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction10th ) ) );

   subitem_map_t sub_re_bps;
   sub_re_bps.push_back(
      subitem_t( Cat021ItemNames::I021_RE_BPS_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   sub_re_bps.push_back(
      subitem_t( Cat021ItemNames::I021_RE_BPS_VAL,
         std::make_shared<AsterixSubitemUnsigned>( 12, UnsignedDoubleConverter::fraction10th ) ) );

   subitem_map_t sub_re_selh;
   sub_re_selh.push_back(
      subitem_t( Cat021ItemNames::I021_RE_SELH_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   sub_re_selh.push_back(
      subitem_t( Cat021ItemNames::I021_RE_SELH_HRD,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_re_selh.push_back(
      subitem_t( Cat021ItemNames::I021_RE_SELH_STAT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_re_selh.push_back(
      subitem_t( Cat021ItemNames::I021_RE_SELH_VAL,
         std::make_shared<AsterixSubitemUnsigned>( 10, UnsignedDoubleConverter::selectedHeading ) ) );

   subitem_map_t sub_re_nav;
   sub_re_nav.push_back(
      subitem_t( Cat021ItemNames::I021_RE_NAV_AP,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_re_nav.push_back(
      subitem_t( Cat021ItemNames::I021_RE_NAV_VN,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_re_nav.push_back(
      subitem_t( Cat021ItemNames::I021_RE_NAV_AH,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_re_nav.push_back(
      subitem_t( Cat021ItemNames::I021_RE_NAV_AM,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   subitem_map_t sub_re_gao;
   sub_re_gao.push_back(
      subitem_t( Cat021ItemNames::I021_RE_GAO_OFFSET,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t sub_re_sgv;
   sub_re_sgv.push_back(
      subitem_t( Cat021ItemNames::I021_RE_SGV_STP,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_re_sgv.push_back(
      subitem_t( Cat021ItemNames::I021_RE_SGV_HTS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_re_sgv.push_back(
      subitem_t( Cat021ItemNames::I021_RE_SGV_HTT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_re_sgv.push_back(
      subitem_t( Cat021ItemNames::I021_RE_SGV_HRD,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_re_sgv.push_back(
      subitem_t( Cat021ItemNames::I021_RE_SGV_GSS,
         std::make_shared<AsterixSubitemUnsigned>( 11, UnsignedDoubleConverter::speedVelToKt ) ) );
   sub_re_sgv.push_back(
      subitem_t( Cat021ItemNames::I021_RE_SGV_HGT,
         std::make_shared<AsterixSubitemUnsigned>( 7, UnsignedDoubleConverter::groundTrackHeading ) ) );

   subitem_map_t sub_re_sta;
   sub_re_sta.push_back(
      subitem_t( Cat021ItemNames::I021_RE_STA_ES,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   sub_re_sta.push_back(
      subitem_t( Cat021ItemNames::I021_RE_STA_UAT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   subitem_map_t sub_re_mes;
   sub_re_mes.push_back(
      subitem_t( Cat021ItemNames::I021_RE_MES_SUM,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sub_re_mes.push_back(
      subitem_t( Cat021ItemNames::I021_RE_MES_PNO,
         std::make_shared<AsterixSubitemUnsigned>( 32, CommonConverter::NoneConverter ) ) );
   sub_re_mes.push_back(
      subitem_t( Cat021ItemNames::I021_RE_MES_EM1,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );
   sub_re_mes.push_back(
      subitem_t( Cat021ItemNames::I021_RE_MES_XP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sub_re_mes.push_back(
      subitem_t( Cat021ItemNames::I021_RE_MES_FOM,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sub_re_mes.push_back(
      subitem_t( Cat021ItemNames::I021_RE_MES_M2,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );

   subitem_map_t reserved_expansion_field;
   reserved_expansion_field.push_back(
      subitem_t( Cat021ItemNames::I021_RE_BPS,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            sub_re_bps ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat021ItemNames::I021_RE_SELH,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            sub_re_selh ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat021ItemNames::I021_RE_NAV,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer,
            sub_re_nav ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat021ItemNames::I021_RE_GAO,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer,
            sub_re_gao ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat021ItemNames::I021_RE_SGV,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer,
            sub_re_sgv ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat021ItemNames::I021_RE_STA,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer,
            sub_re_sta ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat021ItemNames::I021_RE_TNH,
         std::make_shared<AsterixSubitemSigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );
   reserved_expansion_field.push_back(
      subitem_t( Cat021ItemNames::I021_RE_MES,
         std::make_shared<AsterixSubitemCompound>( 88, CommonConverter::NoneConverterBuffer,
            sub_re_mes ) ) );


   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, target_report_descriptor ) );
   subitems.insert( subitem_map_item_t( 3, track_number ) );
   subitems.insert( subitem_map_item_t( 4, service_identification ) );
   subitems.insert( subitem_map_item_t( 5, time_of_position ) );
   subitems.insert( subitem_map_item_t( 6, pos_wgs_low ) );
   subitems.insert( subitem_map_item_t( 7, pos_wgs_high ) );
   subitems.insert( subitem_map_item_t( 8, time_of_velocity ) );
   subitems.insert( subitem_map_item_t( 9, air_speed ) );
   subitems.insert( subitem_map_item_t( 10, true_air_speed ) );
   subitems.insert( subitem_map_item_t( 11, target_address ) );
   subitems.insert( subitem_map_item_t( 12, time_of_recept_position ) );
   subitems.insert( subitem_map_item_t( 13, time_of_recept_position_h ) );
   subitems.insert( subitem_map_item_t( 14, time_of_recept_velocity_l ) );
   subitems.insert( subitem_map_item_t( 15, time_of_recept_velocity_h ) );
   subitems.insert( subitem_map_item_t( 16, geometric_height ) );
   subitems.insert( subitem_map_item_t( 17, quality_indicator ) );
   subitems.insert( subitem_map_item_t( 18, mops_version ) );
   subitems.insert( subitem_map_item_t( 19, m3a_oct ) );
   subitems.insert( subitem_map_item_t( 20, roll_angle ) );
   subitems.insert( subitem_map_item_t( 21, flight_level ) );
   subitems.insert( subitem_map_item_t( 22, magnetic_heading ) );
   subitems.insert( subitem_map_item_t( 23, target_status ) );
   subitems.insert( subitem_map_item_t( 24, barp_vertical_rate ) );
   subitems.insert( subitem_map_item_t( 25, geo_vertical_rate ) );
   subitems.insert( subitem_map_item_t( 26, airborn_ground_vector ) );
   subitems.insert( subitem_map_item_t( 27, track_angle_rate ) );
   subitems.insert( subitem_map_item_t( 28, time_of_repor_transmission ) );
   subitems.insert( subitem_map_item_t( 29, target_identification ) );
   subitems.insert( subitem_map_item_t( 30, emitter_cat ) );
   subitems.insert( subitem_map_item_t( 31, met_information ) );
   subitems.insert( subitem_map_item_t( 32, selected_altitude ) );
   subitems.insert( subitem_map_item_t( 33, final_state_selected_alt ) );
   subitems.insert( subitem_map_item_t( 34, trajectory_intent ) );
   subitems.insert( subitem_map_item_t( 35, service_management ) );
   subitems.insert( subitem_map_item_t( 36, aircraft_operational_status ) );
   subitems.insert( subitem_map_item_t( 37, surface_capabilities ) );
   subitems.insert( subitem_map_item_t( 38, message_ampltitude ) );
   subitems.insert( subitem_map_item_t( 39, mode_s_mb_Data ) );
   subitems.insert( subitem_map_item_t( 40, acas_resolution ) );
   subitems.insert( subitem_map_item_t( 41, receiver_id ) );
   subitems.insert( subitem_map_item_t( 42, data_ages ) );
   subitems.insert( subitem_map_item_t( 48, reserved_expansion_field ) );
}

void AsterixCategory021::fillRecord(std::shared_ptr<ReportRecordType> record) {
}
