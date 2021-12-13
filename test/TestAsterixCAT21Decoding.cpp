/**
 * @file TestAsterixCAT21Decoding.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 28 Feb 2019
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
#include "TestAsterixCAT21Decoding.h"

#include "AsterixCategory021.h"
#include "BinaryHelper.h"
#include "Cat021ItemNames.h"

void TestAsterixCAT21Decoding::setUp() {

}

void TestAsterixCAT21Decoding::tearDown() {

}

void TestAsterixCAT21Decoding::testCAT021() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat021_1", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 21 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 282 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory021* cat021_message = new AsterixCategory021( remaining_length, message );

   //cat021_message->printMessage();

   // Verify the message content
   CPPUNIT_ASSERT(
      cat021_message->getFspecString() == "1111101111101001111111111111111111110111110000010" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_010_SAC ) == "99" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_010_SIC ) == "3" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_ATP ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_ARC ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_RC ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_RAB ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_DCR ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_GBS ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_SIM ) == "0" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_TST ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_SAA ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_CL ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_LLC ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_IPC ) == "0" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_NOGO ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_CPR ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_LDPJ ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_040_RCF ) == "1" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_161_TRKNR ) == "260" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_015_SI ) == "5" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_071_TIME ) == "13186.117188" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_131_LAT ) == "47.402650" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_131_LNG ) == "9.940522" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_072_TIME ) == "5121.804688" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_150_IM ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_150_SPEED ) == "1911" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_151_RE ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_151_SPEED ) == "380" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_080_ADDR ) == "1222279" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_074_FSI ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_074_TIME ) == "0.062519" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_140_GH ) == "33000.000000" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_090_NUCR ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_090_NUCP ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_090_NICB ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_090_SIL ) == "2" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_090_NACP ) == "10" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_210_SPARE ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_210_VNS ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_210_VN ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_210_LTT ) == "2" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_070_SPARE ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_070_CODE ) == "1428" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_230_RA ) == "2.300000" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_145_FL ) == "331" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_152_HDG ) == "109.995117" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_200_ICF ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_200_LNAV ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_200_ME ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_200_PS ) == "3" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_200_SS ) == "0" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_155_RE ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_155_RATE ) == "656.960000" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_157_RE ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_157_RATE ) == "728.000000" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_160_RE ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_160_GSP ) == "409.350586" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_160_TA ) == "110.994873" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_165_TAR ) == "0.750000" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_077_TIME ) == "512.750000" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_170_ID ) == "35218799460868" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_020_ECAT ) == "15" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_220_WS ) == "60" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_220_TMP ) == "-30" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_148_MV ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_148_AH ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_148_AM ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_148_ALT ) == "20000" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_146_SAS ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_146_SRC ) == "3" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_146_ALT ) == "33000" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TIS_NVA ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TIS_NVB ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TID_TCA + ".0" ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TID_NC + ".0" ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TID_TCP + ".0" ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TID_ALT + ".0" ) == "16000.000000" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TID_LAT + ".0" ) == "47.999997" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TID_LNG + ".0" ) == "10.099998" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TID_PT + ".0" ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TID_TD + ".0" ) == "3" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TID_TRA + ".0" ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TID_TOA + ".0" ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TID_TOV + ".0" ) == "518" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_110_TID_TTR + ".0" ) == "0.220000" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_016_RP ) == "10.000000" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_008_RA ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_008_TC ) == "2" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_008_TS ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_008_ARV ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_008_CDT ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_008_TCAS ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_008_SA ) == "0" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_132_MAM ) == "35" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_250_DATA + ".0" ) == "18084836243677314" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_250_BDS1 + ".0" ) == "2" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_250_BDS2 + ".0" ) == "4" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_260_TYP ) == "28" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_260_STYP ) == "2" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_260_ARA ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_260_RAC ) == "5" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_260_RAT ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_260_MTE ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_260_TTI ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_260_TID ) == "4129" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_400_ID ) == "4" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_295_AOS ) == "12.800000" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_295_TRD ) == "1.000000" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_295_M3A ) == "25.000000" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_295_TI ) == "2.300000" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_295_GH ) == "0.500000" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_295_FL ) == "1.200000" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_295_MH ) == "0.300000" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_295_GVR ) == "13.500000" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_295_ARA ) == "0.200000" );

   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_RE_BPS_VAL ) == "234.000000" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_RE_GAO_OFFSET ) == "36" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_RE_SGV_STP ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_RE_SGV_HTS ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_RE_SGV_HTT ) == "0" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_RE_SGV_HRD ) == "1" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_RE_SGV_GSS ) == "7.750000" );
   CPPUNIT_ASSERT( cat021_message->getValue( Cat021ItemNames::I021_RE_SGV_HGT ) == "92.812500" );

}
