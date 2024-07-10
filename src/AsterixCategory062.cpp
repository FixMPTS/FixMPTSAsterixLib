/**
 * @file AsterixCategory062.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 20 Mar 2016
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
 * See description of header file for more details
 */

// project includes
#include "AsterixCategory062.h"
#include "AsterixEncodingHelper.h"
#include "AsterixExceptions.h"
#include "AsterixItemCompound.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemVariableLength.h"
#include "AsterixItemExtendible.h"
#include "AsterixItemRepetetive.h"
#include "AsterixSubitemCompound.h"
#include "AsterixSubitemUnsigned.h"
#include "AsterixSubitemSigned.h"
#include "AsterixSubitemBitNamed.h"
#include "AsterixSubItemRep.h"
#include "Cat062ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "StringConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"
#include "IntegerConverter.h"

// general includes
#include <bitset>
#include <string>

AsterixCategory062::AsterixCategory062() :
   AsterixCategory( 62 ) {
   // Init the calling Asterix Category
   initCategory();

   // initiate the service related stuff already known
   service_related_values["I062/080#DET_AGE"] = std::to_string( DETECTION_TYPE_MAX_AGE );
}

AsterixCategory062::AsterixCategory062(int length) :
   AsterixCategory( 62, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory062::AsterixCategory062(int length, std::deque<char> &m_queue) :
   AsterixCategory( 62, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory062::~AsterixCategory062() {
}

void AsterixCategory062::setUAP() {
   // Define the sub UAPs from the compound items
   AsterixItemCompound::subUap_T item_380_sub_uap;
   AsterixItemCompound::subUap_T item_290_sub_uap;
   AsterixItemCompound::subUap_T item_295_sub_uap;
   AsterixItemCompound::subUap_T item_390_sub_uap;
   AsterixItemCompound::subUap_T item_110_sub_uap;
   AsterixItemCompound::subUap_T item_500_sub_uap;
   AsterixItemCompound::subUap_T item_340_sub_uap;

   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_ADR, 3 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_ID, 6 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_MHG, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_IAS, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_TAS, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_SAL, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_FSS, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemVariableLength>( Cat062ItemNames::I062_380_TIS ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 9,
         std::make_shared<AsterixItemRepetetive>( Cat062ItemNames::I062_380_TID, 15 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 10,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_COM, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 11,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_SAB, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 12,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_ACS, 7 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 13,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_BVR, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 14,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_GVR, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 15,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_RAN, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 16,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_TAR, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 17,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_TAN, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 18,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_GSP, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 19,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_VUN, 1 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 20,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_MET, 8 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 21,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_EMC, 1 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 22,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_POS, 6 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 23,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_GAL, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 24,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_PUN, 1 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 25,
         std::make_shared<AsterixItemRepetetive>( Cat062ItemNames::I062_380_MB, 8 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 26,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_IAR, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 27,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_MAC, 2 ) ) );
   item_380_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 28,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_380_BPS, 2 ) ) );

   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_290_TRK, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_290_PSR, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_290_SSR, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_290_MDS, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_290_ADS, 2 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_290_ES, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_290_VDL, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_290_UAT, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 9,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_290_LOP, 1 ) ) );
   item_290_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 10,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_290_MLT, 1 ) ) );

   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_MFL, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_MD1, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_MD2, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_MDA, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_MD4, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_MD5, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_MHG, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_IAS, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 9,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_TAS, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 10,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_SAL, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 11,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_FSS, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 12,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_TID, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 13,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_COM, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 14,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_SAB, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 15,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_ACS, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 16,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_BVR, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 17,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_GVR, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 18,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_RAN, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 19,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_TAR, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 20,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_TAN, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 21,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_GSP, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 22,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_VUN, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 23,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_MET, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 24,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_EMC, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 25,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_POS, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 26,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_GAL, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 27,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_PUN, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 28,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_MB, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 29,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_IAR, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 30,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_MAC, 1 ) ) );
   item_295_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 31,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_295_BPS, 1 ) ) );

   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_TAG, 2 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_CSN, 7 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_IFI, 4 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_FCT, 1 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_TAC, 4 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_WTC, 1 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_DEP, 4 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_DES, 4 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 9,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_RDS, 3 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 10,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_CFL, 2 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 11,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_CTL, 2 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 12,
         std::make_shared<AsterixItemRepetetive>( Cat062ItemNames::I062_390_TOD, 4 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 13,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_AST, 6 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 14,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_STS, 1 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 15,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_STD, 7 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 16,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_STA, 7 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 17,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_PEM, 2 ) ) );
   item_390_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 18,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_390_PEC, 7 ) ) );

   item_110_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_110_SUM, 1 ) ) );
   item_110_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_110_PMN, 4 ) ) );
   item_110_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_110_POS, 6 ) ) );
   item_110_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_110_GA, 2 ) ) );
   item_110_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_110_EM1, 2 ) ) );
   item_110_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_110_TOS, 1 ) ) );
   item_110_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_110_XP, 1 ) ) );

   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_500_APC, 4 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_500_COV, 2 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_500_APW, 4 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_500_AGA, 1 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_500_ABA, 1 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_500_ATV, 2 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_500_AA, 2 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_500_ARC, 1 ) ) );

   item_340_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_340_SID, 2 ) ) );
   item_340_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_340_POS, 4 ) ) );
   item_340_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_340_HEI, 2 ) ) );
   item_340_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_340_MDC, 2 ) ) );
   item_340_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_340_MDA, 2 ) ) );
   item_340_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_340_TYP, 1 ) ) );

   //Define the Cat 062 UAP
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_010, 2 ) ) );
   // FRN two is not used
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_015, 1 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_070, 3 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_105, 8 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_100, 6 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_185, 4 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_210, 2 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_060, 2 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_245, 7 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_380, item_380_sub_uap ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_040, 2 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemVariableLength>( Cat062ItemNames::I062_080 ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_290, item_290_sub_uap ) ) );
   uap.insert( UAP_Item_T( 15, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_200, 1 ) ) );
   uap.insert( UAP_Item_T( 16, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_295, item_295_sub_uap ) ) );
   uap.insert( UAP_Item_T( 17, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_136, 2 ) ) );
   uap.insert( UAP_Item_T( 18, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_130, 2 ) ) );
   uap.insert( UAP_Item_T( 19, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_135, 2 ) ) );
   uap.insert( UAP_Item_T( 20, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_220, 2 ) ) );
   uap.insert( UAP_Item_T( 21, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_390, item_390_sub_uap ) ) );
   uap.insert( UAP_Item_T( 22, std::make_shared<AsterixItemVariableLength>( Cat062ItemNames::I062_270 ) ) );
   uap.insert( UAP_Item_T( 23, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_300, 1 ) ) );
   uap.insert( UAP_Item_T( 24, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_110, item_110_sub_uap ) ) );
   uap.insert( UAP_Item_T( 25, std::make_shared<AsterixItemFixedLength>( Cat062ItemNames::I062_120, 2 ) ) );
   uap.insert( UAP_Item_T( 26, std::make_shared<AsterixItemExtendible>( Cat062ItemNames::I062_510, 3 ) ) );
   uap.insert( UAP_Item_T( 27, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_500, item_500_sub_uap ) ) );
   uap.insert( UAP_Item_T( 28, std::make_shared<AsterixItemCompound>( Cat062ItemNames::I062_340, item_340_sub_uap ) ) );
   // FRN 29 to 33 not used
   uap.insert( UAP_Item_T( 34, std::make_shared<AsterixItemRepetetive>( Cat062ItemNames::I062_RE, 3 ) ) );
   uap.insert( UAP_Item_T( 35, std::make_shared<AsterixItemRepetetive>( Cat062ItemNames::I062_SP, 1 ) ) );
}

void AsterixCategory062::setSubitems() {
   subitem_map_t system_identification;
   system_identification.push_back(
      subitem_t( Cat062ItemNames::I062_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   system_identification.push_back(
      subitem_t( Cat062ItemNames::I062_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t service_identification;
   service_identification.push_back(
      subitem_t( Cat062ItemNames::I062_015_SID,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t time_of_report;
   time_of_report.push_back(
      subitem_t( Cat062ItemNames::I062_070_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   subitem_map_t calc_track_pos_wgs;
   calc_track_pos_wgs.push_back(
      subitem_t( Cat062ItemNames::I062_105_LAT,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution25Bit ) ) );
   calc_track_pos_wgs.push_back(
      subitem_t( Cat062ItemNames::I062_105_LNG,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution25Bit ) ) );

   subitem_map_t cartesion_position;
   cartesion_position.push_back(
      subitem_t( Cat062ItemNames::I062_100_X,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::fractionHalf ) ) );
   cartesion_position.push_back(
      subitem_t( Cat062ItemNames::I062_100_Y,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::fractionHalf ) ) );

   subitem_map_t calc_track_vel_cartesian;
   calc_track_vel_cartesian.push_back(
      subitem_t( Cat062ItemNames::I062_185_VX,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction4th ) ) );
   calc_track_vel_cartesian.push_back(
      subitem_t( Cat062ItemNames::I062_185_VY,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction4th ) ) );

   subitem_map_t calculated_acceleration;
   calculated_acceleration.push_back(
      subitem_t( Cat062ItemNames::I062_210_AX,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::fraction4th ) ) );
   calculated_acceleration.push_back(
      subitem_t( Cat062ItemNames::I062_210_AX,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::fraction4th ) ) );

   subitem_map_t track_m3a;
   track_m3a.push_back(
      subitem_t( Cat062ItemNames::I062_060_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_m3a.push_back(
      subitem_t( Cat062ItemNames::I062_060_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_m3a.push_back(
      subitem_t( Cat062ItemNames::I062_060_CH,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_m3a.push_back(
      subitem_t( Cat062ItemNames::I062_060_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   track_m3a.push_back(
      subitem_t( Cat062ItemNames::I062_060_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   subitem_map_t target_id;
   target_id.push_back(
      subitem_t( Cat062ItemNames::I062_245_STI,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   target_id.push_back(
      subitem_t( Cat062ItemNames::I062_245_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   target_id.push_back(
      subitem_t( Cat062ItemNames::I062_245_ID,
         std::make_shared<AsterixSubitemUnsigned>( 48, StringConverter::to6BitChar ) ) );

   subitem_map_t aircraft_derived_data;
   subitem_map_t subitem_380_sal;
   subitem_380_sal.push_back(
      subitem_t( Cat062ItemNames::I062_380_SAL_SAS,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "No source information" }, { 1, "Source information" } } ) ) ) );
   subitem_380_sal.push_back(
      subitem_t( Cat062ItemNames::I062_380_SAL_SRC,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Unknown" }, { 1, "Aircraft Altitude" }, { 2, "FCU selected alt" }, { 1, "FMS selected" } } ) ) ) );
   subitem_380_sal.push_back(
      subitem_t( Cat062ItemNames::I062_380_SAL_ALT,
         std::make_shared<AsterixSubitemSigned>( 13, IntegerConverter::alt25ft ) ) );

   subitem_map_t subitem_380_fss;
   subitem_380_fss.push_back(
      subitem_t( Cat062ItemNames::I062_380_FSS_MV,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Not active" }, { 1, "Active" } } ) ) ) );
   subitem_380_fss.push_back(
      subitem_t( Cat062ItemNames::I062_380_FSS_AH,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Not active" }, { 1, "Active" } } ) ) ) );
   subitem_380_fss.push_back(
      subitem_t( Cat062ItemNames::I062_380_FSS_AM,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Not active" }, { 1, "Active" } } ) ) ) );
   subitem_380_fss.push_back(
      subitem_t( Cat062ItemNames::I062_380_FSS_ALT,
         std::make_shared<AsterixSubitemSigned>( 13, IntegerConverter::alt25ft ) ) );

   subitem_map_t subitem_380_tis;
   subitem_380_tis.push_back(
      subitem_t( Cat062ItemNames::I062_380_TIS_NAV,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "TI available" }, { 1, "TI not available" } } ) ) ) );
   subitem_380_tis.push_back(
      subitem_t( Cat062ItemNames::I062_380_TIS_NVB,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "TI valid" }, { 1, "TI not valid" } } ) ) ) );
   subitem_380_tis.push_back(
      subitem_t( Cat062ItemNames::I062_380_TIS_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_380_tid;
   subitem_380_tid.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID_TCA,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Available" }, { 1, "Not available" } } ) ) ) );
   subitem_380_tid.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID_NC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Compliant" }, { 1, "Not compliant" } } ) ) ) );
   subitem_380_tid.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID_TCP,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   subitem_380_tid.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID_ALT,
         std::make_shared<AsterixSubitemSigned>( 16, IntegerConverter::alt10ft ) ) );
   subitem_380_tid.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID_LAT,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );
   subitem_380_tid.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID_LNG,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );
   subitem_380_tid.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID_PT,
         std::make_shared<AsterixSubitemBitNamed>( 4, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Unknown" }, { 1, "Fly by waypoint" }, { 2, "Fly over waypoint" }, { 3, "Hold pattern" },
                  { 4, "Procedure hold" }, { 5, "Procedure turn" }, { 6, "RF" }, { 7, "Top of climb" },
                  { 8, "Top of descent" }, { 9, "Start of level" }, { 10, "Cross-over alt" }, { 11, "Transition alt" } } ) ) ) );
   subitem_380_tid.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID_TD,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "N/A" }, { 1, "Turn right" }, { 2, "Turn left" }, { 3, "No turn" } } ) ) ) );
   subitem_380_tid.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID_TRA,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "TRR available" }, { 1, "TRR not available" } } ) ) ) );
   subitem_380_tid.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID_TOA,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "TOV available" }, { 1, "TOV not available" } } ) ) ) );
   subitem_380_tid.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID_TOV,
         std::make_shared<AsterixSubitemUnsigned>( 24, CommonConverter::NoneConverter ) ) );
   subitem_380_tid.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID_TTR,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::fraction100th ) ) );

   subitem_map_t subitem_380_com;
   subitem_380_com.push_back(
      subitem_t( Cat062ItemNames::I062_380_COM_COM,
         std::make_shared<AsterixSubitemBitNamed>( 3, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "No com" }, { 1, "Com A and B" }, { 2, "Com A and B uplink ELM" }, { 3, "Com A and B up and downlink ELM" } } ) ) ) );
   subitem_380_com.push_back(
      subitem_t( Cat062ItemNames::I062_380_COM_STAT,
         std::make_shared<AsterixSubitemBitNamed>( 3, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No alert no SPI airborne" }, { 1, "1 No allert no Spi on ground" }, { 2, "2 Alert no SPI airborne" },
                  { 3, "3 Alert no SPI on ground" }, { 4, "4 Alert SPI" }, { 5, "5 No Alert SPI" } } ) ) ) );
   subitem_380_com.push_back(
      subitem_t( Cat062ItemNames::I062_380_COM_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   subitem_380_com.push_back(
      subitem_t( Cat062ItemNames::I062_380_COM_SSC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No" }, { 1, "1 Yes" } } ) ) ) );
   subitem_380_com.push_back(
      subitem_t( Cat062ItemNames::I062_380_COM_ARC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 100ft" }, { 1, "1 25ft" } } ) ) ) );
   subitem_380_com.push_back(
      subitem_t( Cat062ItemNames::I062_380_COM_AIC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No" }, { 1, "1 Yes" } } ) ) ) );
   subitem_380_com.push_back(
      subitem_t( Cat062ItemNames::I062_380_COM_B1A,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0" }, { 1, "1" } } ) ) ) );
   subitem_380_com.push_back(
      subitem_t( Cat062ItemNames::I062_380_COM_B1B,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_380_sab;
   subitem_380_sab.push_back(
      subitem_t( Cat062ItemNames::I062_380_SAB_AC,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Unknown" }, { 1, "1 ACAS not operational" }, { 2, "2 ACAS operational" }, { 3, "3 Invalid" } } ) ) ) );
   subitem_380_sab.push_back(
      subitem_t( Cat062ItemNames::I062_380_SAB_MN,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Unknown" }, { 1, "1 Multi nav aids no op" }, { 2, "2 Multi nav aids op" }, { 3, "3 Invalid" } } ) ) ) );
   subitem_380_sab.push_back(
      subitem_t( Cat062ItemNames::I062_380_SAB_DC,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Unknown" }, { 1, "1 Differential correlation" }, { 2, "2 No differential correlation" }, { 3, "3 Invalid" } } ) ) ) );
   subitem_380_sab.push_back(
      subitem_t( Cat062ItemNames::I062_380_SAB_GBS,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Ground bit not set" }, { 1, "1 Groundbit set" } } ) ) ) );
   subitem_380_sab.push_back(
      subitem_t( Cat062ItemNames::I062_380_SAB_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   subitem_380_sab.push_back(
      subitem_t( Cat062ItemNames::I062_380_SAB_STAT,
         std::make_shared<AsterixSubitemBitNamed>( 3, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No emergency" }, { 1, "1 General emergency" }, { 2, "2 Lifeguard" }, { 3, "3 Minimum fuel" },
                  { 4, "4 No Communication" }, { 5, "5 Unlawful interference" }, { 6, "6 Downed" }, { 7, "7 Unknown" } } ) ) ) );

   subitem_map_t subitem_380_tar;
   subitem_380_tar.push_back(
      subitem_t( Cat062ItemNames::I062_380_TAR_TI,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 N/A" }, { 1, "1 Left" }, { 2, "2 Right" }, { 3, "3 Straight" } } ) ) ) );
   subitem_380_tar.push_back(
      subitem_t( Cat062ItemNames::I062_380_TAR_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   subitem_380_tar.push_back(
      subitem_t( Cat062ItemNames::I062_380_TAR_RT,
         std::make_shared<AsterixSubitemUnsigned>( 7, DoubleConverter::fraction4th ) ) );
   subitem_380_tar.push_back(
      subitem_t( Cat062ItemNames::I062_380_TAR_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_380_met;
   subitem_380_met.push_back(
      subitem_t( Cat062ItemNames::I062_380_MET_WS,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Not valid" }, { 1, "1 Valid" } } ) ) ) );
   subitem_380_met.push_back(
      subitem_t( Cat062ItemNames::I062_380_MET_WD,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Not valid" }, { 1, "1 Valid" } } ) ) ) );
   subitem_380_met.push_back(
      subitem_t( Cat062ItemNames::I062_380_MET_TMP,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Not valid" }, { 1, "1 Valid" } } ) ) ) );
   subitem_380_met.push_back(
      subitem_t( Cat062ItemNames::I062_380_MET_TRB,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Not valid" }, { 1, "1 Valid" } } ) ) ) );
   subitem_380_met.push_back(
      subitem_t( Cat062ItemNames::I062_380_MET_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   subitem_380_met.push_back(
      subitem_t( Cat062ItemNames::I062_380_MET_WSD,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );
   subitem_380_met.push_back(
      subitem_t( Cat062ItemNames::I062_380_MET_WDD,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );
   subitem_380_met.push_back(
      subitem_t( Cat062ItemNames::I062_380_MET_TMPD,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction4th ) ) );
   subitem_380_met.push_back(
      subitem_t( Cat062ItemNames::I062_380_MET_TUR,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_380_pos;
   subitem_380_pos.push_back(
      subitem_t( Cat062ItemNames::I062_380_POS_LAT,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );
   subitem_380_pos.push_back(
      subitem_t( Cat062ItemNames::I062_380_POS_LNG,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );

   subitem_map_t subitem_380_mb;
   subitem_380_mb.push_back(
      subitem_t( Cat062ItemNames::I062_380_MB_DATA,
         std::make_shared<AsterixSubitemUnsigned>( 56, CommonConverter::NoneConverter ) ) );
   subitem_380_mb.push_back(
      subitem_t( Cat062ItemNames::I062_380_MB_BDS1,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   subitem_380_mb.push_back(
      subitem_t( Cat062ItemNames::I062_380_MB_BDS2,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_380_bps;
   subitem_380_bps.push_back(
      subitem_t( Cat062ItemNames::I062_380_BPS_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   subitem_380_bps.push_back(
      subitem_t( Cat062ItemNames::I062_380_BPS_BPS,
         std::make_shared<AsterixSubitemUnsigned>( 12, UnsignedDoubleConverter::fraction10th ) ) );

   // Add all 380 items
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_ADR,
         std::make_shared<AsterixSubitemUnsigned>( 24, CommonConverter::NoneConverter ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_ID,
         std::make_shared<AsterixSubitemUnsigned>( 48, StringConverter::to6BitChar ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_MHG,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_IAS,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::airspeed14Bit ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_TAS,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_SAL,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            subitem_380_sal ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_FSS,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            subitem_380_fss ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_TIS,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer,
            subitem_380_tis ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_TID,
         std::make_shared<AsterixSubItemRep>( 120, CommonConverter::NoneConverterBuffer,
            subitem_380_tid ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_COM,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            subitem_380_com ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_SAB,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            subitem_380_sab ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_ACS,
         std::make_shared<AsterixSubitemUnsigned>( 56, CommonConverter::NoneConverter ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_BVR,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::verticalRate ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_GVR,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::verticalRate ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_RAN,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fraction100th ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_TAR,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            subitem_380_tar ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_TAN,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_GSP,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::groundSpeedKt ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_VUN,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_MET,
         std::make_shared<AsterixSubitemCompound>( 64, CommonConverter::NoneConverterBuffer,
            subitem_380_met ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_EMC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_POS,
         std::make_shared<AsterixSubitemCompound>( 48, CommonConverter::NoneConverterBuffer,
            subitem_380_pos ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_GAL,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::geoAltitudeFt ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_PUN,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_MB,
         std::make_shared<AsterixSubItemRep>( 64, CommonConverter::NoneConverterBuffer,
            subitem_380_mb ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_IAR,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_MAC,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::speedMach ) ) );
   aircraft_derived_data.push_back(
      subitem_t( Cat062ItemNames::I062_380_BPS,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            subitem_380_bps ) ) );

   subitem_map_t track_number;
   track_number.push_back(
      subitem_t( Cat062ItemNames::I062_040_TRK,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );

   subitem_map_t track_status;
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_MON,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Multisensor" }, { 1, "1 Monosensor" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_SPI,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 SPI present" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_MRH,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Barometric" }, { 1, "1 Geometric" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_SRC,
         std::make_shared<AsterixSubitemBitNamed>( 3, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No source" }, { 1, "1 GNSS" }, { 2, "2 3D radar" }, { 3, "3 Triangulation" }, { 4, "4 hight from cov" },
                  { 5, "5 lookup table" }, { 6, "6 default" }, { 7, "7 multilateration" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_CNF,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Confirmed" }, { 1, "1 tentative" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_SIM,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Actual track" }, { 1, "1 simulated track" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_TSE,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Last message of track" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_TSB,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 First message of track" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_FPC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Not correlated" }, { 1, "1 correlated" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_AFF,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 ADSB inconsistent" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_STP,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Slave track" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_KOS,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Complementary service" }, { 1, "1 Background service" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_AMA,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Not amalgamated" }, { 1, "1 amalgamated" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_MD4,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Friendly target" }, { 2, "2 Unknown" }, { 3, "3 no reply" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_ME,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Military emergency" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_MI,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Military identification present" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_MD5,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No MD5" }, { 1, "1 Friendly target" }, { 2, "2 Unknown target" }, { 3, "3 No reply" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_CST,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Coasting" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_PSR,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 PSR supported" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_SSR,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 SSR supported" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_MDS,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Mode S supported" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_ADS,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 ADS-B supported" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_SUC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Special M3A" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_AAC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 M3A conflict" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_SDS,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Combined" }, { 1, "1 Co-op only" }, { 2, "2 Non co-op" }, { 3, "3 Not defined" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_EMS,
         std::make_shared<AsterixSubitemBitNamed>( 3, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No emergency" }, { 1, "1 General emergency" }, { 2, "2 Lifeguard" }, { 3, "3 Minimum fuel" },
                  { 4, "4 No com" }, { 5, "5 Unlawful" }, { 6, "6 Downed" }, { 7, "7 Undefined" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_PFT,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No indication" }, { 1, "1 Potential false track" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_FPLT,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 FPL supported" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_DUPT,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Duplicate M3A" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_DUPF,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Duplicate FP" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_DUPM,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Duplicate FP man corr" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_SFC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Surface target" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_IDD,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Duplicate Flight-ID" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_IEC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 Inconsistent Emergency code" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat062ItemNames::I062_080_MLAT,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Default" }, { 1, "1 MLAT Age > threshold" } } ) ) ) );

   subitem_map_t track_update_ages;
   track_update_ages.push_back(
      subitem_t( Cat062ItemNames::I062_290_TRK,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_update_ages.push_back(
      subitem_t( Cat062ItemNames::I062_290_PSR,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_update_ages.push_back(
      subitem_t( Cat062ItemNames::I062_290_SSR,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_update_ages.push_back(
      subitem_t( Cat062ItemNames::I062_290_MDS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_update_ages.push_back(
      subitem_t( Cat062ItemNames::I062_290_ADS,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::fraction4th ) ) );
   track_update_ages.push_back(
      subitem_t( Cat062ItemNames::I062_290_ES,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_update_ages.push_back(
      subitem_t( Cat062ItemNames::I062_290_VDL,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_update_ages.push_back(
      subitem_t( Cat062ItemNames::I062_290_UAT,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_update_ages.push_back(
      subitem_t( Cat062ItemNames::I062_290_LOP,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_update_ages.push_back(
      subitem_t( Cat062ItemNames::I062_290_MLT,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );

   subitem_map_t mode_of_movement;
   mode_of_movement.push_back(
      subitem_t( Cat062ItemNames::I062_200_TRANS,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Constant course" }, { 1, "1 Right turn" }, { 2, "2 Left turn" }, { 3, "3 Undetermined" } } ) ) ) );
   mode_of_movement.push_back(
      subitem_t( Cat062ItemNames::I062_200_LONG,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Constant course" }, { 1, "1 Increasing gsp" }, { 2, "2 Decreasing gsp" }, { 3, "3 Undetermined" } } ) ) ) );
   mode_of_movement.push_back(
      subitem_t( Cat062ItemNames::I062_200_VERT,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Level" }, { 1, "1 Climb" }, { 2, "2 Descent" }, { 3, "3 Undetermined" } } ) ) ) );
   mode_of_movement.push_back(
      subitem_t( Cat062ItemNames::I062_200_ADF,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No alt discrepancy" }, { 1, "1 Alt discrepancy" } } ) ) ) );
   mode_of_movement.push_back(
      subitem_t( Cat062ItemNames::I062_200_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t track_data_ages;
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_MFL,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_MD1,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_MD2,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_MDA,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_MD4,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_MD5,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_MHG,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_IAS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_TAS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_SAL,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_FSS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_TID,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_COM,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_SAB,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_ACS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_BVR,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_GVR,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_RAN,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_TAR,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_TAN,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_GSP,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_VUN,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_MET,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_EMC,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_POS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_GAL,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_PUN,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_MB,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_IAR,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_MAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );
   track_data_ages.push_back(
      subitem_t( Cat062ItemNames::I062_295_BPS,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::fraction4th ) ) );

   subitem_map_t meas_flighht_level;
   meas_flighht_level.push_back(
      subitem_t( Cat062ItemNames::I062_136_ALT,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::geoAltitudeFt ) ) );
   subitem_map_t calculated_geo_alt;
   calculated_geo_alt.push_back(
      subitem_t( Cat062ItemNames::I062_130_ALT,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::geoAltitudeFt ) ) );
   subitem_map_t calculated_baro_alt;
   calculated_baro_alt.push_back(
      subitem_t( Cat062ItemNames::I062_135_QNH,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No QNH" }, { 1, "1 QNH" } } ) ) ) );
   calculated_baro_alt.push_back(
      subitem_t( Cat062ItemNames::I062_135_ALT,
         std::make_shared<AsterixSubitemSigned>( 15, DoubleConverter::geoAltitudeFt ) ) );
   subitem_map_t calc_rate_cb;
   calc_rate_cb.push_back(
      subitem_t( Cat062ItemNames::I062_220_RATE,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::geoAltitudeFt ) ) );

   subitem_map_t subitem_390_tag;
   subitem_390_tag.push_back(
      subitem_t( Cat062ItemNames::I062_390_TAG_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   subitem_390_tag.push_back(
      subitem_t( Cat062ItemNames::I062_390_TAG_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );


   subitem_map_t subitem_390_ifi;
   subitem_390_ifi.push_back(
      subitem_t( Cat062ItemNames::I062_390_IFI_TYP,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Plan number" }, { 1, "1 Unit 1" }, { 2, "2 Unit 2" }, { 3, "3 Unit 3" } } ) ) ) );
   subitem_390_ifi.push_back(
      subitem_t( Cat062ItemNames::I062_390_IFI_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   subitem_390_ifi.push_back(
      subitem_t( Cat062ItemNames::I062_390_IFI_NBR,
         std::make_shared<AsterixSubitemUnsigned>( 27, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_390_fct;
   subitem_390_fct.push_back(
      subitem_t( Cat062ItemNames::I062_390_FCT_GAT,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Unknown" }, { 1, "1 General Air Traffic" }, { 2, "2 Operational Air Traffic" }, { 3, "3 N/A" } } ) ) ) );
   subitem_390_fct.push_back(
      subitem_t( Cat062ItemNames::I062_390_FCT_FR,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Instrument Flight Rules" }, { 1, "1 Visual Fllight rules" }, { 2, "2 N/A" }, { 3, "3 Controlled VFR" } } ) ) ) );
   subitem_390_fct.push_back(
      subitem_t( Cat062ItemNames::I062_390_FCT_RVSM,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Unknown" }, { 1, "1 Approved" }, { 2, "2 Exempt" }, { 3, "3 Not approved" } } ) ) ) );
   subitem_390_fct.push_back(
      subitem_t( Cat062ItemNames::I062_390_FCT_HPR,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Normal prio" }, { 1, "1 Heigh prio" } } ) ) ) );
   subitem_390_fct.push_back(
      subitem_t( Cat062ItemNames::I062_390_FCT_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_390_rds;
   subitem_390_rds.push_back(
      subitem_t( Cat062ItemNames::I062_390_RDS_NU1,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   subitem_390_rds.push_back(
      subitem_t( Cat062ItemNames::I062_390_RDS_NU2,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   subitem_390_rds.push_back(
      subitem_t( Cat062ItemNames::I062_390_RDS_LTR,
         std::make_shared<AsterixSubitemUnsigned>( 8, StringConverter::toASCII ) ) );

   subitem_map_t subitem_390_ctl;
   subitem_390_ctl.push_back(
      subitem_t( Cat062ItemNames::I062_390_CTL_C,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   subitem_390_ctl.push_back(
      subitem_t( Cat062ItemNames::I062_390_CTL_P,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_390_tod;
   subitem_390_tod.push_back(
      subitem_t( Cat062ItemNames::I062_390_TOD_TYP,
            std::make_shared<AsterixSubitemBitNamed>( 5, CommonConverter::NoneConverter,
               AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Sched off block" }, { 1, "1 Est off block" }, { 2, "2 Est take off" }, { 3, "3 Act off block" },
                  { 4, "4 Pred rwy hold" }, { 5, "5 Act rwy hold" }, { 6, "6 Act line up" }, { 7, "7 Act take off" },
                  { 8, "8 Est arrival" }, { 9, "9 Pred landing" }, { 10, "10 Act landing" }, { 11, "11 Act off rwy" },
                  { 12, "12 Pred to gate" }, { 13, "13 Act on block" } } ) ) ) );
   subitem_390_tod.push_back(
      subitem_t( Cat062ItemNames::I062_390_TOD_DAY,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Today" }, { 1, "1 Yesterday" }, { 2, "2 Tomorrow" }, { 3, "3 Invalid" } } ) ) ) );
   subitem_390_tod.push_back(
      subitem_t( Cat062ItemNames::I062_390_TOD_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   subitem_390_tod.push_back(
      subitem_t( Cat062ItemNames::I062_390_TOD_HOR,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter ) ) );
   subitem_390_tod.push_back(
      subitem_t( Cat062ItemNames::I062_390_TOD_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   subitem_390_tod.push_back(
      subitem_t( Cat062ItemNames::I062_390_TOD_MIN,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );
   subitem_390_tod.push_back(
      subitem_t( Cat062ItemNames::I062_390_TOD_AVS,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Available" }, { 1, "1 Not available" } } ) ) ) );
   subitem_390_tod.push_back(
      subitem_t( Cat062ItemNames::I062_390_TOD_SPARE3,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   subitem_390_tod.push_back(
      subitem_t( Cat062ItemNames::I062_390_TOD_SEC,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_390_sts;
   subitem_390_sts.push_back(
      subitem_t( Cat062ItemNames::I062_390_STS_EMP,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Enmpty" }, { 1, "1 Occupied" }, { 2, "2 Unknown" }, { 3, "3 Invalid" } } ) ) ) );
   subitem_390_sts.push_back(
      subitem_t( Cat062ItemNames::I062_390_STS_AVL,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Available" }, { 1, "1 Not available" }, { 2, "2 Unknown" }, { 3, "3 Invalid" } } ) ) ) );
   subitem_390_sts.push_back(
      subitem_t( Cat062ItemNames::I062_390_STS_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_390_pem;
   subitem_390_pem.push_back(
      subitem_t( Cat062ItemNames::I062_390_PEM_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   subitem_390_pem.push_back(
      subitem_t( Cat062ItemNames::I062_390_PEM_VA,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Not valid" }, { 1, "1 Valid" } } ) ) ) );
   subitem_390_pem.push_back(
      subitem_t( Cat062ItemNames::I062_390_PEM_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   // Put all items into the compound item
   subitem_map_t flight_plan_data;
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_TAG,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            subitem_390_tag ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_CSN,
         std::make_shared<AsterixSubitemUnsigned>( 56, StringConverter::toASCII ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_IFI,
         std::make_shared<AsterixSubitemCompound>( 32, CommonConverter::NoneConverterBuffer,
            subitem_390_ifi ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_FCT,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer,
            subitem_390_fct ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_TAC,
         std::make_shared<AsterixSubitemUnsigned>( 32, StringConverter::toASCII ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_WTC,
         std::make_shared<AsterixSubitemUnsigned>( 8, StringConverter::toASCII ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_DEP,
         std::make_shared<AsterixSubitemUnsigned>( 32, StringConverter::toASCII ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_DES,
         std::make_shared<AsterixSubitemUnsigned>( 32, StringConverter::toASCII ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_RDS,
         std::make_shared<AsterixSubitemCompound>( 24, CommonConverter::NoneConverterBuffer,
            subitem_390_rds ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_CFL,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::fraction4th ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_CTL,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            subitem_390_ctl ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_TOD,
         std::make_shared<AsterixSubItemRep>( 32, CommonConverter::NoneConverterBuffer,
            subitem_390_tod ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_AST,
         std::make_shared<AsterixSubitemUnsigned>( 48, StringConverter::toASCII ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_STS,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer,
            subitem_390_sts ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_STD,
         std::make_shared<AsterixSubitemUnsigned>( 56, StringConverter::toASCII ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_STA,
         std::make_shared<AsterixSubitemUnsigned>( 56, StringConverter::toASCII ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_PEM,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer,
            subitem_390_pem ) ) );
   flight_plan_data.push_back(
      subitem_t( Cat062ItemNames::I062_390_PEC,
         std::make_shared<AsterixSubitemUnsigned>( 56, StringConverter::toASCII ) ) );

   subitem_map_t size_orientation;
   size_orientation.push_back(
      subitem_t( Cat062ItemNames::I062_270_L,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );
   size_orientation.push_back(
      subitem_t( Cat062ItemNames::I062_270_O,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );
   size_orientation.push_back(
      subitem_t( Cat062ItemNames::I062_270_W,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) );

   subitem_map_t vehicle_fleet;
   vehicle_fleet.push_back(
      subitem_t( Cat062ItemNames::I062_300_VFI,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_110_sum;
   subitem_110_sum.push_back(
      subitem_t( Cat062ItemNames::I062_110_SUM_M5,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No MD5" }, { 1, "1 MD5" } } ) ) ) );
   subitem_110_sum.push_back(
      subitem_t( Cat062ItemNames::I062_110_SUM_ID,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No MD5 ID" }, { 1, "1 Authenticated MD5 ID" } } ) ) ) );
   subitem_110_sum.push_back(
      subitem_t( Cat062ItemNames::I062_110_SUM_DA,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No data reply" }, { 1, "1 Authenticated data reply" } } ) ) ) );
   subitem_110_sum.push_back(
      subitem_t( Cat062ItemNames::I062_110_SUM_M1,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Mode 1 not present" }, { 1, "1 Mode 1 present" } } ) ) ) );
   subitem_110_sum.push_back(
      subitem_t( Cat062ItemNames::I062_110_SUM_M2,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Mode 2 not present" }, { 1, "1 Mode 2 present" } } ) ) ) );
   subitem_110_sum.push_back(
      subitem_t( Cat062ItemNames::I062_110_SUM_M3,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Mode 3 not present" }, { 1, "1 Mode 3 present" } } ) ) ) );
   subitem_110_sum.push_back(
      subitem_t( Cat062ItemNames::I062_110_SUM_MC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Mode C not present" }, { 1, "1 Mode C present" } } ) ) ) );
   subitem_110_sum.push_back(
      subitem_t( Cat062ItemNames::I062_110_SUM_X,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No X pulse" }, { 1, "1 Authenticated X pulse" } } ) ) ) );

   subitem_map_t subitem_110_pmn;
   subitem_110_pmn.push_back(
      subitem_t( Cat062ItemNames::I062_110_PMN_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   subitem_110_pmn.push_back(
      subitem_t( Cat062ItemNames::I062_110_PMN_PIN,
         std::make_shared<AsterixSubitemUnsigned>( 14, CommonConverter::NoneConverter ) ) );
   subitem_110_pmn.push_back(
      subitem_t( Cat062ItemNames::I062_110_PMN_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   subitem_110_pmn.push_back(
      subitem_t( Cat062ItemNames::I062_110_PMN_NAT,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter ) ) );
   subitem_110_pmn.push_back(
      subitem_t( Cat062ItemNames::I062_110_PMN_SPARE3,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   subitem_110_pmn.push_back(
      subitem_t( Cat062ItemNames::I062_110_PMN_MIS,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_110_pos;
   subitem_110_pos.push_back(
      subitem_t( Cat062ItemNames::I062_110_POS_LAT,
         std::make_shared<AsterixSubitemUnsigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );
   subitem_110_pos.push_back(
      subitem_t( Cat062ItemNames::I062_110_POS_LNG,
         std::make_shared<AsterixSubitemUnsigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );

   subitem_map_t subitem_110_ga;
   subitem_110_ga.push_back(
      subitem_t( Cat062ItemNames::I062_110_GA_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   subitem_110_ga.push_back(
      subitem_t( Cat062ItemNames::I062_110_GA_RES,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "0 100 ft" }, { 1, "1 25 ft" } } ) ) ) );
   subitem_110_ga.push_back(
      subitem_t( Cat062ItemNames::I062_110_GA_GA,
         std::make_shared<AsterixSubitemUnsigned>( 14, DoubleConverter::WGS84AltQuarter ) ) );

   subitem_map_t subitem_110_em1;
   subitem_110_em1.push_back(
      subitem_t( Cat062ItemNames::I062_110_EM1_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   subitem_110_em1.push_back(
      subitem_t( Cat062ItemNames::I062_110_EM1_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_110_xp;
   subitem_110_xp.push_back(
      subitem_t( Cat062ItemNames::I062_110_XP_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   subitem_110_xp.push_back(
      subitem_t( Cat062ItemNames::I062_110_XP_X5,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   subitem_110_xp.push_back(
      subitem_t( Cat062ItemNames::I062_110_XP_XC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   subitem_110_xp.push_back(
      subitem_t( Cat062ItemNames::I062_110_XP_X3,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   subitem_110_xp.push_back(
      subitem_t( Cat062ItemNames::I062_110_XP_X2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   subitem_110_xp.push_back(
      subitem_t( Cat062ItemNames::I062_110_XP_X1,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );

   // Add all sub items to I062#110
   subitem_map_t mode_5;
   mode_5.push_back(
      subitem_t( Cat062ItemNames::I062_110_SUM,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer, subitem_110_sum ) ) );
   mode_5.push_back(
      subitem_t( Cat062ItemNames::I062_110_PMN,
         std::make_shared<AsterixSubitemCompound>( 32, CommonConverter::NoneConverterBuffer, subitem_110_pmn ) ) );
   mode_5.push_back(
      subitem_t( Cat062ItemNames::I062_110_POS,
         std::make_shared<AsterixSubitemCompound>( 48, CommonConverter::NoneConverterBuffer, subitem_110_pos ) ) );
   mode_5.push_back(
      subitem_t( Cat062ItemNames::I062_110_GA,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer, subitem_110_ga ) ) );
   mode_5.push_back(
      subitem_t( Cat062ItemNames::I062_110_EM1,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer, subitem_110_em1 ) ) );
   mode_5.push_back(
      subitem_t( Cat062ItemNames::I062_110_TOS,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   mode_5.push_back(
      subitem_t( Cat062ItemNames::I062_110_XP,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer, subitem_110_xp ) ) );

   subitem_map_t mode_2;
   mode_2.push_back(
      subitem_t( Cat062ItemNames::I062_120_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   mode_2.push_back(
      subitem_t( Cat062ItemNames::I062_120_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   // Limitation@ Only 4 slave track numbers are supported. Need to be extended once the need arise
   subitem_map_t composed_track_nr;
   composed_track_nr.push_back(
      subitem_t( Cat062ItemNames::I062_510_MSI,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   composed_track_nr.push_back(
      subitem_t( Cat062ItemNames::I062_510_MST,
         std::make_shared<AsterixSubitemUnsigned>( 15, CommonConverter::NoneConverter ) ) );
   composed_track_nr.push_back(
      subitem_t( Cat062ItemNames::I062_510_SI1,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   composed_track_nr.push_back(
      subitem_t( Cat062ItemNames::I062_510_ST1,
         std::make_shared<AsterixSubitemUnsigned>( 15, CommonConverter::NoneConverter ) ) );
   composed_track_nr.push_back(
      subitem_t( Cat062ItemNames::I062_510_SI2,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   composed_track_nr.push_back(
      subitem_t( Cat062ItemNames::I062_510_ST2,
         std::make_shared<AsterixSubitemUnsigned>( 15, CommonConverter::NoneConverter ) ) );
   composed_track_nr.push_back(
      subitem_t( Cat062ItemNames::I062_510_SI3,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   composed_track_nr.push_back(
      subitem_t( Cat062ItemNames::I062_510_ST3,
         std::make_shared<AsterixSubitemUnsigned>( 15, CommonConverter::NoneConverter ) ) );
   composed_track_nr.push_back(
      subitem_t( Cat062ItemNames::I062_510_SI4,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   composed_track_nr.push_back(
      subitem_t( Cat062ItemNames::I062_510_ST4,
         std::make_shared<AsterixSubitemUnsigned>( 15, CommonConverter::NoneConverter ) ) );


   subitem_map_t subitem_500_apc;
   subitem_500_apc.push_back(
      subitem_t( Cat062ItemNames::I062_500_APC_X,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fractionHalf ) ) );
   subitem_500_apc.push_back(
      subitem_t( Cat062ItemNames::I062_500_APC_Y,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fractionHalf ) ) );

   subitem_map_t subitem_500_apw;
   subitem_500_apw.push_back(
      subitem_t( Cat062ItemNames::I062_500_APW_LAT,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::WGS84resolution25Bit ) ) );
   subitem_500_apw.push_back(
      subitem_t( Cat062ItemNames::I062_500_APW_LAT,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::WGS84resolution25Bit ) ) );

   subitem_map_t subitem_500_atv;
   subitem_500_atv.push_back(
      subitem_t( Cat062ItemNames::I062_500_ATV_X,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::WGS84AltQuarter ) ) );
   subitem_500_atv.push_back(
      subitem_t( Cat062ItemNames::I062_500_ATV_Y,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::WGS84AltQuarter ) ) );

   subitem_map_t subitem_500_aa;
   subitem_500_aa.push_back(
      subitem_t( Cat062ItemNames::I062_500_AA_X,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::WGS84AltQuarter ) ) );
   subitem_500_aa.push_back(
      subitem_t( Cat062ItemNames::I062_500_AA_Y,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::WGS84AltQuarter ) ) );

   // Add all subitems to I062#500
   subitem_map_t estimated_acc;
   estimated_acc.push_back(
      subitem_t( Cat062ItemNames::I062_500_APC,
         std::make_shared<AsterixSubitemCompound>( 32, CommonConverter::NoneConverterBuffer, subitem_500_apc ) ) );
   estimated_acc.push_back(
      subitem_t( Cat062ItemNames::I062_500_COV,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::fractionHalf ) ) );
   estimated_acc.push_back(
      subitem_t( Cat062ItemNames::I062_500_APW,
         std::make_shared<AsterixSubitemCompound>( 32, CommonConverter::NoneConverterBuffer, subitem_500_apw ) ) );
   estimated_acc.push_back(
      subitem_t( Cat062ItemNames::I062_500_AGA,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::geoAltitudeFt ) ) );
   estimated_acc.push_back(
      subitem_t( Cat062ItemNames::I062_500_ABA,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::WGS84AltQuarter ) ) );
   estimated_acc.push_back(
      subitem_t( Cat062ItemNames::I062_500_ATV,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer, subitem_500_atv ) ) );
   estimated_acc.push_back(
      subitem_t( Cat062ItemNames::I062_500_AA,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer, subitem_500_aa ) ) );
   estimated_acc.push_back(
      subitem_t( Cat062ItemNames::I062_500_ARC,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::geoAltitudeFt ) ) );

   subitem_map_t subitem_340_sid;
   subitem_340_sid.push_back(
      subitem_t( Cat062ItemNames::I062_340_SID_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   subitem_340_sid.push_back(
      subitem_t( Cat062ItemNames::I062_340_SID_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t subitem_340_pos;
   subitem_340_pos.push_back(
      subitem_t( Cat062ItemNames::I062_340_POS_RHO,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::fraction128th ) ) );
   subitem_340_pos.push_back(
      subitem_t( Cat062ItemNames::I062_340_POS_THETA,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::circleSegment16Bit ) ) );

   subitem_map_t subitem_340_mdc;
   subitem_340_mdc.push_back(
      subitem_t( Cat062ItemNames::I062_340_MDC_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // valid flag
   subitem_340_mdc.push_back(
      subitem_t( Cat062ItemNames::I062_340_MDC_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // garbled flag
   subitem_340_mdc.push_back(
      subitem_t( Cat062ItemNames::I062_340_MDC_CODE,
         std::make_shared<AsterixSubitemSigned>( 14, IntegerConverter::alt25ft ) ) );

   //Mode 3A Code
   subitem_map_t subitem_340_mda;
   subitem_340_mda.push_back(
      subitem_t( Cat062ItemNames::I062_340_MDA_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // valid flag
   subitem_340_mda.push_back(
      subitem_t( Cat062ItemNames::I062_340_MDA_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // garbled flag
   subitem_340_mda.push_back(
      subitem_t( Cat062ItemNames::I062_340_MDA_L,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); //locally tracked flag
   subitem_340_mda.push_back(
      subitem_t( Cat062ItemNames::I062_340_MDA_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // Not used
   subitem_340_mda.push_back(
      subitem_t( Cat062ItemNames::I062_340_MDA_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) ); // code in octal representation

   subitem_map_t subitem_340_typ;
   subitem_340_typ.push_back(
      subitem_t( Cat062ItemNames::I062_340_TYP_TYP,
         std::make_shared<AsterixSubitemBitNamed>( 3, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 No detection" }, { 1, "1 Single PSR" }, { 2, "2 Single SSR" }, { 3, "3 SSR+PSR" },
                  { 4, "4 Mode S All call" }, { 5, "5 Mode S Roll call" }, { 6, "6 All call + PSR" }, { 7, "7 Roll call + PSR" } } ) ) ) );
   subitem_340_typ.push_back(
      subitem_t( Cat062ItemNames::I062_340_TYP_SIM,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Target report" }, { 1, "1 Simulated report" } } ) ) ) );
   subitem_340_typ.push_back(
      subitem_t( Cat062ItemNames::I062_340_TYP_RAB,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Report from target transponder" }, { 1, "1 Report from field transponder" } } ) ) ) );
   subitem_340_typ.push_back(
      subitem_t( Cat062ItemNames::I062_340_TYP_TST,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "0 Target report" }, { 1, "1 Test report" } } ) ) ) );
   subitem_340_typ.push_back(
      subitem_t( Cat062ItemNames::I062_340_TYP_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );

   // Add all subitems to I062#340
   subitem_map_t measured_info;
   measured_info.push_back(
      subitem_t( Cat062ItemNames::I062_340_SID,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer, subitem_340_sid ) ) );
   measured_info.push_back(
      subitem_t( Cat062ItemNames::I062_340_POS,
         std::make_shared<AsterixSubitemCompound>( 32, CommonConverter::NoneConverterBuffer, subitem_340_pos ) ) );
   measured_info.push_back(
      subitem_t( Cat062ItemNames::I062_340_HEI,
         std::make_shared<AsterixSubitemSigned>( 16, IntegerConverter::alt25ft ) ) );
   measured_info.push_back(
      subitem_t( Cat062ItemNames::I062_340_MDC,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer, subitem_340_mdc ) ) );
   measured_info.push_back(
      subitem_t( Cat062ItemNames::I062_340_MDA,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer, subitem_340_mda ) ) );
   measured_info.push_back(
      subitem_t( Cat062ItemNames::I062_340_TYP,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer, subitem_340_typ ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, system_identification ) );
   // FRN 2 is not used
   subitems.insert( subitem_map_item_t( 3, service_identification ) );
   subitems.insert( subitem_map_item_t( 4, time_of_report ) );
   subitems.insert( subitem_map_item_t( 5, calc_track_pos_wgs ) );
   subitems.insert( subitem_map_item_t( 6, cartesion_position ) );
   subitems.insert( subitem_map_item_t( 7, calc_track_vel_cartesian ) );
   subitems.insert( subitem_map_item_t( 8, calculated_acceleration ) );
   subitems.insert( subitem_map_item_t( 9, track_m3a ) );
   subitems.insert( subitem_map_item_t( 10, target_id ) );
   subitems.insert( subitem_map_item_t( 11, aircraft_derived_data ) );
   subitems.insert( subitem_map_item_t( 12, track_number ) );
   subitems.insert( subitem_map_item_t( 13, track_status ) );
   subitems.insert( subitem_map_item_t( 14, track_update_ages ) );
   subitems.insert( subitem_map_item_t( 15, mode_of_movement ) );
   subitems.insert( subitem_map_item_t( 16, track_data_ages ) );
   subitems.insert( subitem_map_item_t( 17, meas_flighht_level ) );
   subitems.insert( subitem_map_item_t( 18, calculated_geo_alt ) );
   subitems.insert( subitem_map_item_t( 19, calculated_baro_alt ) );
   subitems.insert( subitem_map_item_t( 20, calc_rate_cb ) );
   subitems.insert( subitem_map_item_t( 21, flight_plan_data ) );
   subitems.insert( subitem_map_item_t( 22, size_orientation ) );
   subitems.insert( subitem_map_item_t( 23, vehicle_fleet ) );
   subitems.insert( subitem_map_item_t( 24, mode_5 ) );
   subitems.insert( subitem_map_item_t( 25, mode_2 ) );
   subitems.insert( subitem_map_item_t( 26, composed_track_nr ) );
   subitems.insert( subitem_map_item_t( 27, estimated_acc ) );
   subitems.insert( subitem_map_item_t( 28, measured_info ) );
}

std::vector<unsigned char> AsterixCategory062::getEncodedMessage(std::shared_ptr<TrackTypeIf> track,
   std::map<std::string, bool> items_to_be_served, std::shared_ptr<AsterixItemMaxAges> max_ages) {

   std::vector<unsigned char> message;
   std::vector<unsigned char> header;

   // Encode all items. Note that the order of the items is of importance and must match the UAP
   for( auto item : fpsec_item_name_map ) {
      // Reset the FSPEC for this item
      fspec[item.first] = false;

      if( item.second == Cat062ItemNames::I062_010 ) { // Mandatory. Maybe force transmission of this item
         std::vector<unsigned char> sac_sic = AsterixEncodingHelper::encodeSACSIC16Bit(
         non_track_related_values[Cat062ItemNames::I062_010_SAC],
         non_track_related_values[Cat062ItemNames::I062_010_SIC] );

         // item is present
         if( sac_sic.size() == 2 ) {
            fspec[item.first] = true;
            message.insert( message.end(), sac_sic.begin(), sac_sic.end() );
         }
      }

      // I062/015 Service Identification
      if( item.second == Cat062ItemNames::I062_015 ) {
         // This item must be present
      message.push_back( non_track_related_values[Cat062ItemNames::I062_015] );
         fspec[item.first] = true;
      }

      // I062/040 Track number
      if( item.second == Cat062ItemNames::I062_040 ) { // This item is present since it is mandatory
         std::vector<unsigned char> track_number = AsterixEncodingHelper::encodeTrackNumber16Bit(
            track->getTrackNumber() );

         if( track_number.size() == 2 ) {
            message.insert( message.end(), track_number.begin(), track_number.end() );
            fspec[item.first] = true;
         }
      }

      // I062/060 Track Mode 3A code
      if( item.second == Cat062ItemNames::I062_060
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         if( track->getMode3A().has_value() ) {
            DetectionEntry::ModeX mode_3A = track->getMode3A().value();
            // 2 Byte
            std::vector<unsigned char> track_m3A = AsterixEncodingHelper::encodeTrackMode3A(
               mode_3A.getCode(), mode_3A.isValid(), mode_3A.isGarbled() );

            if( track_m3A.size() == 2 ) {
               message.insert( message.end(), track_m3A.begin(), track_m3A.end() );
               fspec[item.first] = true;
            }
         }
      }

      // I062/070 Time of track information
      if( item.second == Cat062ItemNames::I062_070 ) { // mandatory item

         std::vector<unsigned char> track_time = AsterixEncodingHelper::encodeTimeOfTrackInfo24Bit(
            track->getLastUpdatingTime() );

         if( track_time.size() == 3 ) {
            message.insert( message.end(), track_time.begin(), track_time.end() );
            fspec[item.first] = true;
         }
         else {
            throw MandatoryItemMissing( "AsterixCategory062::getEncodedMessage", "I062/070" );
         }
      }

      // I062/080 Track Status
      if( item.second == Cat062ItemNames::I062_080 ) { // This item is mandatory

         std::map<std::string, bool> track_live;
         track_live["TSE"] = service_related_values[Cat062ItemNames::I062_080_TSE] == "1";
         track_live["TSB"] = service_related_values[Cat062ItemNames::I062_080_TSB] == "1";

         std::vector<unsigned char> track_status = AsterixEncodingHelper::encodeTrackStatus( track,
            atof( service_related_values[Cat062ItemNames::I062_080_CNF].c_str() ), max_ages, track_live );

         message.insert( message.end(), track_status.begin(), track_status.end() );
         fspec[item.first] = true;
      }

      // We skip the Cartesian items since those are too small to properly store the information

      // I062/105 Calculated Position In WGS-84 Co-ordinates
      if( item.second == Cat062ItemNames::I062_105
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> position_wgs = AsterixEncodingHelper::encodePositionWG( track );

         if( position_wgs.size() == 8 ) {
            message.insert( message.end(), position_wgs.begin(), position_wgs.end() );
            fspec[item.first] = true;
         }
      }

      // Items I062/110 Mode 5 Data, I062/120 Mode 3 data are skipped

      // I062/130 Calculated Track Geometric Altitude
      if( item.second == Cat062ItemNames::I062_130
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> geometric_alt =
            AsterixEncodingHelper::encodeGeoAltitude( track );

         if( geometric_alt.size() == 2 ) {
            message.insert( message.end(), geometric_alt.begin(), geometric_alt.end() );
            fspec[item.first] = true;
         }
      }

      // Item I062/135 Calculated Track Barometric Altitude
      if( item.second == Cat062ItemNames::I062_135
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> baro_alt =
            AsterixEncodingHelper::encodeBaroAltitude( track->getBaroAltitude(), 0 );
         if( baro_alt.size() == 2 ) {
            message.insert( message.end(), baro_alt.begin(), baro_alt.end() );
            fspec[item.first] = true;
         }
      }
      // Item I062/136, Measured Flight Level
      if( item.second == Cat062ItemNames::I062_136
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         if( track->getModeC().has_value() ) {
            std::vector<unsigned char> baro_alt =
               AsterixEncodingHelper::encodeBaroAltitude( (track->getModeC().value().getCode() * 25) / 100, -1 );

            if( baro_alt.size() == 2 ) {
               message.insert( message.end(), baro_alt.begin(), baro_alt.end() );
               fspec[item.first] = true;
            }
         }
      }

      // Items I062/185 Cartesian Velocity not encoded

      // Item I062/200 Mode of Movement
      if( item.second == Cat062ItemNames::I062_200
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> mof =
            AsterixEncodingHelper::encodeMOF8Bit( track );

         if( mof.size() == 1 ) {
            message.insert( message.end(), mof.begin(), mof.end() );
            fspec[item.first] = true;
         }
      }

      // Item I062/210, Calculated Acceleration (Cartesian) not encoded

      // Item I062/220, Calculated Rate Of Climb/Descent
      if( item.second == Cat062ItemNames::I062_220
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> rate_cd =
            AsterixEncodingHelper::encodeRateCD( track->getRateOfCD() );

         if( rate_cd.size() == 2 ) {
            message.insert( message.end(), rate_cd.begin(), rate_cd.end() );
            fspec[item.first] = true;
         }
      }

      // Item I062/245, Target Identification. This item shall not be encoded

      // Item I062/270, Target Size & Orientation. This item is currently not decoded

      // Item I062/290, System Track Update Ages
      if( item.second == Cat062ItemNames::I062_290
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> track_ages =
            AsterixEncodingHelper::encodeSystemTrackAges( track );

         if( track_ages.size() > 1 ) { // one byte compound item fpsec and at least one data item
            message.insert( message.end(), track_ages.begin(), track_ages.end() );
            fspec[item.first] = true;
         }
      }

      // Item I062/295, Track Data Ages
      if( item.second == Cat062ItemNames::I062_295
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> data_ages =
            AsterixEncodingHelper::encodeTrackDataAges( track );

         if( data_ages.size() > 1 ) { // one byte compound item fpsec and at least one data item
            message.insert( message.end(), data_ages.begin(), data_ages.end() );
            fspec[item.first] = true;
         }
      }

      // I062/300, Vehicle Fleet Identification. NOt encoded at the moment

      //Item I062/340, Measured Information
      if( item.second == Cat062ItemNames::I062_340
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> measured_info = AsterixEncodingHelper::encodeMeasuredItems( track );

         if( measured_info.size() > 1 ) { // one byte compound item fpsec and at least one data item
            message.insert( message.end(), measured_info.begin(), measured_info.end() );
            fspec[item.first] = true;
         }

      }

      // Item I062/380, Aircraft Derived Data
      if( item.second == Cat062ItemNames::I062_380
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         std::vector<unsigned char> add_data = AsterixEncodingHelper::eoncodeAircraftDerivedData( track );

         if( add_data.size() > 1 ) { // one byte compound item fpsec and at least one data item
            message.insert( message.end(), add_data.begin(), add_data.end() );
            fspec[item.first] = true;
         }

      }

      // Item I062/390, Flight Plan Related Data NOt encoded at the moment

      // Item I062/500, Estimated Accuracies TOBE DONE as soon as the accuracies are available

      // Item I062/510, Composed Track Number. This item makes no sense currently

      // Item I062/RE

      // Item I062/SP list of TRIs of sensor contributed since last transmission
      if( item.second == Cat062ItemNames::I062_SP
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {

      }
   }

   // add header to message
   getHeader( header, message.size() );
   message.insert( message.begin(), header.begin(), header.end() );

   return message;
}

void AsterixCategory062::setNonTrackRelatedValues(std::map<std::string, unsigned char> v) {
   non_track_related_values = v;
}

void AsterixCategory062::setServiceRelatedValue(std::string name, std::string value) {
   service_related_values[name] = value;
}

void AsterixCategory062::fillRecord(std::shared_ptr<ReportRecordType> record) {

}
