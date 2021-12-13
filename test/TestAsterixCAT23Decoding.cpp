/**
 * @file TestAsterixCAT231Decoding.cpp
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
#include "AsterixCategory023.h"
#include "BinaryHelper.h"
#include "Cat023ItemNames.h"
#include "TestAsterixCAT23Decoding.h"

void TestAsterixCAT23Decoding::setUp() {

}

void TestAsterixCAT23Decoding::tearDown() {

}

void TestAsterixCAT23Decoding::testCAT023GS() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat023_GSStatus", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 23 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 12 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory023* cat023_message = new AsterixCategory023( remaining_length, message );

   //cat023_message->printMessage();

   CPPUNIT_ASSERT( cat023_message->getFspecString() == "110110100" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_010_SAC ) == "98" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_010_SIC ) == "5" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_000_TYPE ) == "1" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_070_TOD ) == "34308.250000" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_100_NOGO ) == "0" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_100_ODP ) == "0" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_100_OXT ) == "0" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_100_MSC ) == "1" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_100_TSV ) == "0" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_100_SPO ) == "0" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_100_RN ) == "1" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_200_RNG ) == "170" );
}

void TestAsterixCAT23Decoding::testCAT023SStatus() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat023_ServiceStatus", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 23 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 17 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory023* cat023_message = new AsterixCategory023( remaining_length, message );

   //cat023_message->printMessage();

   CPPUNIT_ASSERT( cat023_message->getFspecString() == "11110111000000" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_010_SAC ) == "98" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_010_SIC ) == "35" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_000_TYPE ) == "2" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_015_SID ) == "6" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_015_STYP ) == "3" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_070_TOD ) == "1088.046875" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_101_RP ) == "3.500000" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_101_SC ) == "1" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_101_SSRP ) == "4" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_200_RNG ) == "126" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_110_STATUS ) == "4" );
}

void TestAsterixCAT23Decoding::testCAT023SStat() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat023_ServiceStat", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 23 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 25 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory023* cat023_message = new AsterixCategory023( remaining_length, message );

   //cat023_message->printMessage();

   CPPUNIT_ASSERT( cat023_message->getFspecString() == "11110000100000" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_010_SAC ) == "98" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_010_SIC ) == "35" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_000_TYPE ) == "3" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_015_SID ) == "10" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_015_STYP ) == "2" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_070_TOD ) == "33282.500000" );

   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_120_TYP + ".0" ) == "3" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_120_REF + ".0" ) == "1" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_120_COUNTER + ".0" ) == "259" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_120_TYP + ".1" ) == "23" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_120_REF + ".1" ) == "1" );
   CPPUNIT_ASSERT( cat023_message->getValue( Cat023ItemNames::I023_120_COUNTER + ".1" ) == "741" );
}
