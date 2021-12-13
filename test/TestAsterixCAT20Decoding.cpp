/**
 * @file TestAsterixCAT20Decoding.cpp
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
#include "TestAsterixCAT20Decoding.h"

#include "AsterixCategory020.h"
#include "BinaryHelper.h"
#include "Cat020ItemNames.h"

void TestAsterixCAT20Decoding::setUp() {

}

void TestAsterixCAT20Decoding::tearDown() {

}

void TestAsterixCAT20Decoding::testCAT020() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat020_1", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 20 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 93 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);
   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory020* cat020_message = new AsterixCategory020( remaining_length, message );

   //cat020_message->printMessage();

   CPPUNIT_ASSERT( cat020_message->getFspecString() == "1111111111111111001111111100" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_010_SAC ) == "98" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_010_SIC ) == "102" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_SSR ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_MS ) == "1" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_HF ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_VDL4 ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_UAT ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_DME ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_OT ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_RAB ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_SPI ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_CHN ) == "1" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_GBS ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_CRT ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_SIM ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_020_TST ) == "1" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_140_TOD ) == "50432.265625" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_041_LAT ) == "-21.131601" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_041_LNG ) == "55.303572" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_042_X ) == "-299.500000" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_042_Y ) == "684.000000" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_161_TRK ) == "374" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_170_CNF ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_170_TRE ) == "1" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_170_CST ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_170_CDM ) == "2" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_170_MAH ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_170_STH ) == "0" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_070_V ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_070_G ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_070_L ) == "1" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_070_CODE ) == "70" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_202_VX ) == "101.000000" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_202_VY ) == "9.000000" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_090_V ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_090_G ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_090_FL ) == "340.000000" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_100_V ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_100_G ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_100_CODE ) == "2180" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_100_PULSE ) == "2724" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_220_ADDR ) == "5116898" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_245_STI ) == "2" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_245_ID ) == "DLH510" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_110_ALT ) == "33800.000000" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_105_ALT ) == "33850.000000" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_210_AX ) == "12.000000" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_210_AY ) == "0.000000" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_500_DOP_X ) == "0.500000" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_500_DOP_Y ) == "25.000000" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_500_DOP_XY ) == "0.250000" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_400_TU + ".0" ) == "10" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_400_TU + ".1" ) == "2" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_400_TU + ".2" ) == "3" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_400_TU + ".3" ) == "5" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_250_DATA + ".0" ) == "9042521065783810" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_250_BDS1 + ".0" ) == "4" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_250_BDS2 + ".0" ) == "2" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_230_COM ) == "1" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_230_STAT ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_230_MSSC ) == "1" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_230_ARC ) == "1" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_230_AIC ) == "1" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_230_B1A ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_230_B1B ) == "3" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_260_DATA ) == "4521260536235904" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_030_ERR ) == "15" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_055_V ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_055_G ) == "1" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_055_L ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_055_CODE ) == "10" );

   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_050_V ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_050_G ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_050_L ) == "0" );
   CPPUNIT_ASSERT( cat020_message->getValue( Cat020ItemNames::I020_050_CODE ) == "1176" );
}

