/**
 * @file TestAsterixCAT61Decoding.cpp
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
#include "TestAsterixCAT61Decoding.h"
#include "BinaryHelper.h"
#include "AsterixCategory061.h"
#include "Cat061ItemNames.h"

void TestAsterixCAT61Decoding::setUp() {

}

void TestAsterixCAT61Decoding::tearDown() {

}

void TestAsterixCAT61Decoding::testCAT061() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat061All", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 61 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 175 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory061* cat061_message = new AsterixCategory061( remaining_length, message );

   //cat061_message->printMessage();

   CPPUNIT_ASSERT( cat061_message->getFspecString() == "1111111111111111111111000000" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_010_SAC ) == "33" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_010_SIC ) == "55" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_000_FAM ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_000_NAT ) == "5" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_012_UID ) == "130" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_015_SID ) == "101" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_020_TOD ) == "32803.500000" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_030_BTN ) == "13" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_045_AVN ) == "2" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_050_DGA ) == "1" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_060_LAT + ".0" ) == "48.889997" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_060_LNG + ".0" ) == "8.217795" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_060_LAT + ".1" ) == "48.861099" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_060_LNG + ".1" ) == "8.595214" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_060_LAT + ".2" ) == "48.985596" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_060_LNG + ".2" ) == "8.875596" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_060_LAT + ".3" ) == "49.113398" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_060_LNG + ".3" ) == "8.512999" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_060_LAT + ".4" ) == "49.090996" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_060_LNG + ".4" ) == "8.242498" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_070_LL ) == "-10" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_080_UL ) == "600" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_100_CODE + ".0" ) == "5" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TNS_TRK + ".0" ) == "32340" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TNS_TRK + ".1" ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_AAS_AA + ".0" ) == "14730135" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_AAS_AA + ".1" ) == "668913" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_AAS_AA + ".2" ) == "8242018" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_AIS_AI + ".0" ) == "GEC8272 " );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_AIS_AI + ".1" ) == "TAM8101 " );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_CFS_WC + ".0" ) == "4" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_CFS_M3A + ".0" ) == "3584" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_DPS_ID + ".0" ) == "EDSB" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_DTS_ID + ".0" ) == "EDDS" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_ATS_AT + ".0" ) == "B772" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_ATS_AT + ".1" ) == "B748" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_ATS_AT + ".2" ) == "A388" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_ATS_AT + ".3" ) == "A346" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_CCS_CENTER + ".0" ) == "2" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_CCS_POSITION + ".0" ) == "10" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_SIM ) == "2" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_CSR ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_PSR ) == "1" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_SSR ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_MDS ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_ADS ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_VALT ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_FPC ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_CNF ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_SPI ) == "0" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_GAT ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_IFR ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_VFR ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_CFR ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_RVSM ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_FRI ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_ME ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_130_TCS_MI ) == "1" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N1 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N2 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N3 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N4 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N5 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N6 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N7 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N8 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N9 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N10 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N11 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N12 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N13 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N14 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N15 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N16 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N17 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N18 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N19 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N20 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N21 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N22 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N23 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N24 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N25 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N26 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N27 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_210_N28 ) == "0" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_220_SD ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_220_SP ) == "10" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_220_BP ) == "10" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_220_UP ) == "400" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_220_ED ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_220_MF ) == "255" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_230_MSAC ) == "33" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_230_MSIC ) == "5" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_230_BSAC ) == "45" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_230_BSIC ) == "102" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_240_RCT ) == "3000.000000" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_240_TAT ) == "2.812500" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_240_GST ) == "50" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_240_AT ) == "26" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_240_FK ) == "1.250000" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_330_CODE + ".0" ) == "4566" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_350_SAC + ".0" ) == "13" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_350_SIC + ".0" ) == "230" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N1 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N2 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N3 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N4 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N5 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N6 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N7 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N8 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N9 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N10 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N11 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N12 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N13 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N14 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N15 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N16 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N17 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N18 ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N19 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N20 ) == "0" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_360_N21 ) == "0" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_370_UP ) == "12" );

   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_380_RP ) == "60" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_380_DP_SSC ) == "1" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_380_SRB ) == "5.000000" );
   CPPUNIT_ASSERT( cat061_message->getValue( Cat061ItemNames::I061_380_PAB ) == "2.493896" );
}

