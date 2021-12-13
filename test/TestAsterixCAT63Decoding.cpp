/**
 * @file TestAsterixCAT63Decoding.cpp
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
#include "TestAsterixCAT63Decoding.h"
#include "BinaryHelper.h"
#include "AsterixCategory063.h"
#include "Cat063ItemNames.h"

void TestAsterixCAT63Decoding::setUp() {

}

void TestAsterixCAT63Decoding::tearDown() {

}

void TestAsterixCAT63Decoding::testCAT063() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat063", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 63 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 30 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory063* cat063_message = new AsterixCategory063( remaining_length, message );

   //cat063_message->printMessage();

   CPPUNIT_ASSERT( cat063_message->getFspecString() == "11111111111000" );

   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_010_SAC ) == "10" );
   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_010_SIC ) == "123" );

   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_015_SID ) == "85" );

   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_030_TOD ) == "32798.062500" );

   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_050_SAC ) == "10" );
   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_050_SIC ) == "11" );

   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_060_CON ) == "0" );
   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_060_PSR ) == "0" );
   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_060_SSR ) == "0" );
   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_060_MDS ) == "0" );
   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_060_ADS ) == "1" );
   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_060_MLT ) == "0" );

   // Check the second extend is not decoded, since it is not contained in the message
   CPPUNIT_ASSERT_THROW( cat063_message->getValue( Cat063ItemNames::I063_060_OPS ), std::out_of_range );
   CPPUNIT_ASSERT_THROW( cat063_message->getValue( Cat063ItemNames::I063_060_ODP ), std::out_of_range );

   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_070_TSB ) == "4112" );

   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_080_SRG ) == "0.129160" );
   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_080_SRB ) == "-193.375000" );

   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_081_SAB ) == "1.395264" );

   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_090_PRG ) == "-0.002400" );
   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_090_PRB ) == "2.890625" );

   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_091_PAB ) == "25.043335" );

   CPPUNIT_ASSERT( cat063_message->getValue( Cat063ItemNames::I063_092_PEB ) == "0.527344" );
}

