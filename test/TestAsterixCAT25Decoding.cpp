/**
 * @file TestAsterixCAT25Decoding.cpp
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
 * see .h file for more information
 */
#include "TestAsterixCAT25Decoding.h"
#include "BinaryHelper.h"
#include "Cat025ItemNames.h"
#include "AsterixCategory025.h"

void TestAsterixCAT25Decoding::setUp() {

}

void TestAsterixCAT25Decoding::tearDown() {

}

void TestAsterixCAT25Decoding::testCAT025Status() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat025Status", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 25 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 38 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory025* cat025_message = new AsterixCategory025( remaining_length, message );

   //cat025_message->printMessage();

   CPPUNIT_ASSERT( cat025_message->getFspecString() == "11111111100000" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_010_SAC ) == "104" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_010_SIC ) == "31" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_000_TYP ) == "1" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_000_RG ) == "1" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_200_MIN ) == "1012018" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_015_SID ) == "11" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_020_SD ) == "ALLNBR02" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_070_TOD ) == "4.492188" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_100_NOGO ) == "0" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_100_OPS ) == "0" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_100_STAT ) == "1" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_105_ERR + ".0" ) == "4" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_105_ERR + ".1" ) == "9" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_120_CID + ".0" ) == "5" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_120_EC + ".0" ) == "0" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_120_CS + ".0" ) == "0" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_120_CID + ".1" ) == "9" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_120_EC + ".1" ) == "0" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_120_CS + ".1" ) == "0" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_120_CID + ".2" ) == "11" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_120_EC + ".2" ) == "2" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_120_CS + ".2" ) == "2" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_120_CID + ".3" ) == "1" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_120_EC + ".3" ) == "0" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_120_CS + ".3" ) == "0" );

   // Check the item 020/140 which is not supposed to be present in this type of report is not there
   CPPUNIT_ASSERT_THROW( cat025_message->getValue( Cat025ItemNames::I025_140_TYPE ), std::out_of_range );
   CPPUNIT_ASSERT_THROW( cat025_message->getValue( Cat025ItemNames::I025_140_REF ), std::out_of_range );
   CPPUNIT_ASSERT_THROW( cat025_message->getValue( Cat025ItemNames::I025_140_COUNTER ), std::out_of_range );
}

void TestAsterixCAT25Decoding::testCAT025Statistic() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat025Statistics", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 25 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 34 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory025* cat025_message = new AsterixCategory025( remaining_length, message );

   //cat025_message->printMessage();

   CPPUNIT_ASSERT( cat025_message->getFspecString() == "11111100010000" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_010_SAC ) == "104" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_010_SIC ) == "32" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_000_TYP ) == "3" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_000_RG ) == "0" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_200_MIN ) == "66048" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_015_SID ) == "18" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_020_SD ) == "MPTS01  " );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_070_TOD ) == "23.750000" );

   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_140_TYPE + ".0" ) == "1" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_140_REF + ".0" ) == "1" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_140_COUNTER + ".0" ) == "20" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_140_TYPE + ".1" ) == "3" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_140_REF + ".1" ) == "1" );
   CPPUNIT_ASSERT( cat025_message->getValue( Cat025ItemNames::I025_140_COUNTER + ".1" ) == "93" );

   // CHeck item not supposed to be in the message are not there
   CPPUNIT_ASSERT_THROW( cat025_message->getValue( Cat025ItemNames::I025_100_NOGO ), std::out_of_range );
   CPPUNIT_ASSERT_THROW( cat025_message->getValue( Cat025ItemNames::I025_100_OPS ), std::out_of_range );
   CPPUNIT_ASSERT_THROW( cat025_message->getValue( Cat025ItemNames::I025_100_STAT ), std::out_of_range );

   CPPUNIT_ASSERT_THROW( cat025_message->getValue( Cat025ItemNames::I025_105_ERR + ".0" ), std::out_of_range );
}

