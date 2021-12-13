/**
 * @file TestAsterixCAT244Decoding.cpp
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
#include "TestAsterixCAT244Decoding.h"
#include "BinaryHelper.h"
#include "Cat244ItemNames.h"
#include "AsterixCategory244.h"

void TestAsterixCAT244Decoding::setUp() {

}

void TestAsterixCAT244Decoding::tearDown() {

}

void TestAsterixCAT244Decoding::testCAT244() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat244", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 244 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 77 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory244* cat244_message = new AsterixCategory244( remaining_length, message );

   //cat244_message->printMessage();

   CPPUNIT_ASSERT( cat244_message->getFspecString() == "1111111111111111111111100000" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_010_TID ) == "53123" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_020_TOD ) == "24607.500000" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_030_LAT ) == "10.123400" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_030_LNG ) == "-25.172500" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_040_FL ) == "41000.000000" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_045_ALT ) == "400.000000" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_050_GSP ) == "389.355469" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_055_SPEED ) == "384.521484" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_060_TA ) == "211.997681" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_065_HDG ) == "215.996704" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_070_VR ) == "-3000.000000" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_075_VR ) == "-3093.750000" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_080_ALONG ) == "23.208000" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_080_ACROSS ) == "0.072000" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_080_VERTICAL ) == "0.024000" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_095_RATE ) == "-1.500000" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_100_ALT + ".0" ) == "10.200000" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_100_LAT + ".0" ) == "10.530996" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_100_LNG + ".0" ) == "-49.786327" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_100_TTA + ".0" ) == "0" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_100_TTG + ".0" ) == "908.000000" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_100_TCA + ".0" ) == "0" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_100_TCN + ".0" ) == "16" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_115_V ) == "0" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_115_FL ) == "410.000000" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_120_ADR ) == "5413042" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_130_V ) == "1" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_130_CODE ) == "358" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_140_TID ) == "SAA261  " );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_150_ACT ) == "A343" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_160_ECAT ) == "5" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_170_TS ) == "1" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_180_NAC ) == "2" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_180_NIC ) == "3" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_180_B ) == "0" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_180_SIL ) == "1" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_190_ES ) == "1" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_190_VDL4 ) == "0" );
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_190_UAT ) == "0" );
}

void TestAsterixCAT244Decoding::testCAT244Mach() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat244Mach", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 244 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 13 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory244* cat244_message = new AsterixCategory244( remaining_length, message );

   //cat244_message->printMessage();

   CPPUNIT_ASSERT( cat244_message->getFspecString() == "11000110000000000000000" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_010_TID ) == "1094" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_020_TOD ) == "518.937500" );

   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_050_GSP ) == "389.355469" );
   // Test the handling of the air speed in case the IM flag is set
   CPPUNIT_ASSERT( cat244_message->getValue( Cat244ItemNames::I244_055_SPEED ) == "0.870000" );
}
