/**
 * @file TestAsterixCAT204Decoding.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 1 Mar 2019
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
#include "TestAsterixCAT204Decoding.h"
#include "BinaryHelper.h"
#include "AsterixCategory204.h"
#include "Cat204ItemNames.h"

void TestAsterixCAT204Decoding::setUp() {

}

void TestAsterixCAT204Decoding::tearDown() {

}

void TestAsterixCAT204Decoding::testCAT204() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat204All", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 204 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 186 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory204* cat204_message = new AsterixCategory204( remaining_length, message );

   //cat204_message->printMessage();

   CPPUNIT_ASSERT(
      cat204_message->getFspecString() == "111111111111111111111111111111111111110000" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_010_SAC ) == "99" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_010_SIC ) == "167" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_012_SAC + ".0" ) == "98" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_012_SIC + ".0" ) == "15" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_000_CODE ) == "11531" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_001_TN ) == "AA145" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_700_ACK ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_700_TYP ) == "50" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_700_ID ) == "3902865410" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_003_ID ) == "2311" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_260_STS ) == "4" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_280_TIME ) == "1516901788000000" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_020_LAT ) == "47.259400" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_020_LNG ) == "11.345800" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_030_TQ ) == "13" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_060_VSP ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_060_CLIM ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_060_VSPEED ) == "421.000000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_060_MACH ) == "3.500000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_060_HDG ) == "189.761353" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_060_HSPEED ) == "2300.000000" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_070_EID ) == "3" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_070_MID ) == "2" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_080_ECAT ) == "2" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_040_ALT ) == "14532" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_291_UPD ) == "10.250000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_291_AMSL ) == "5.000000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_291_IFF1 ) == "34.000000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_291_IFF2 ) == "25.250000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_291_IFF3 ) == "25.250000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_291_IFF4 ) == "25.250000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_291_IFFC ) == "12.250000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_291_COM ) == "10.250000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_291_ACS ) == "2.000000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_291_POS ) == "0.250000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_291_GAL ) == "63.750000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_291_MB ) == "0.000000" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_050_IFFFC ) == "45000" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_081_SRP ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_081_TYPE ) == "8" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_082_MODE ) == "2" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_083_KIND ) == "2" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_084_FORMAT ) == "2" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_084_MAX ) == "170" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_084_MIN ) == "1" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_090_IFF1 ) == "13" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_091_IFF2 ) == "3627" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_092_IFF3 ) == "2560" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_093_IFF4 ) == "3" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_SUM_M5 ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_SUM_ID ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_SUM_DA ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_SUM_M1 ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_SUM_M2 ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_SUM_M3 ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_SUM_MC ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_SUM_X ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_PMN_PIN ) == "8434" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_PMN_NAT ) == "10" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_PMN_MIS ) == "7" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_POS_LAT ) == "46.765430" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_POS_LNG ) == "4.972000" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_GA_RES ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_GA_ALT ) == "47500" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_EM1_CODE ) == "1767" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_TOS ) == "65416" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_XP_X5 ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_XP_XC ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_XP_X3 ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_XP_X2 ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_094_XP_X1 ) == "1" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_101_ADR ) == "10715313" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_101_ID ) == "AAF2001 " );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_101_COM_COM ) == "2" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_101_COM_STAT ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_101_COM_SCC ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_101_COM_ARC ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_101_COM_AIC ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_101_COM_B1A ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_101_COM_B1B ) == "3" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_101_POS_LAT ) == "45.456684" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_101_POS_LNG ) == "-8.765395" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_101_GAL ) == "47000.000000" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_130_CONF ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_130_ACT ) == "14" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_130_TYP ) == "5" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_130_STYP ) == "490" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_130_NAT ) == "51" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_IFFC ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_IFF3 ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_IFF2 ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_IFF1 ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_FIX ) == "2" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_C2 ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_JAM ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_EMER ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_ENG ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_EXER ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_INT ) == "2" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_SPI ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_SIF ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_TN ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_SIM ) == "2" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_170_FTEL ) == "2" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_620_ENV + ".0" ) == "2" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_620_ROLE + ".0" ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_620_TYPE + ".0" ) == "2" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_620_CNTN + ".0" ) == "CNTN001  " );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_620_STS + ".0" ) == "2" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_620_WS + ".0" ) == "3" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_245_STI ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_245_ID ) == "AAFLEAD " );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_630_SAC + ".0" ) == "60" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_630_SIC + ".0" ) == "50" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_630_SAC + ".1" ) == "71" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_630_SIC + ".1" ) == "82" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_690_AV ) == "3" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_085_FORMAT ) == "2" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_085_MAX ) == "146" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_085_MIN ) == "67" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_400_SIM ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_400_DESC ) == "5" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_400_ORI ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_400_ACCUR ) == "9" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_400_ERANGE ) == "399.993896" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_400_AZIM ) == "210.997925" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_400_AZIMW ) == "1.999512" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_400_AZRATE ) == "4.998779" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_400_ELEV ) == "-10.997314" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_710_AD ) == "2" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_720_SS ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_720_RS ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_720_NTN ) == "0" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_720_ID ) == "1" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_720_RTT ) == "1" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_730_ID ) == "03145" );

   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_740_SAC ) == "102" );
   CPPUNIT_ASSERT( cat204_message->getValue( Cat204ItemNames::I204_740_SIC ) == "4" );
}

