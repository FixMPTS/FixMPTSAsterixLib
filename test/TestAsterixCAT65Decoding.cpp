/**
 * @file TestAsterixCAT65Decoding.cpp
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
 * See h file for more information
 */
#include "TestAsterixCAT65Decoding.h"
#include "BinaryHelper.h"
#include "AsterixCategory065.h"
#include "Cat065ItemNames.h"

void TestAsterixCAT65Decoding::setUp() {

}

void TestAsterixCAT65Decoding::tearDown() {

}

void TestAsterixCAT65Decoding::testCAT065() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat065", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 65 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 27 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory065 *cat065_message = new AsterixCategory065( remaining_length, message );

   //cat065_message->printMessage();

   CPPUNIT_ASSERT( cat065_message->getFspecString() == "11111110000010" );

   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_010_SAC ) == "120" );
   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_010_SIC ) == "100" );

   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_000_TYP ) == "1" );

   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_015_SID ) == "255" );

   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_030_TOD ) == "638.406250" );

   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_020_BTN ) == "55" );
   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_040_NOGO ) == "0" );
   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_040_OVL ) == "0" );
   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_040_TSV ) == "0" );
   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_040_PSS ) == "1" );
   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_040_STTN ) == "1" );
   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_050_REPORT ) == "6" );
   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_RE_SRP_LAT ) == "47.618590" );
   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_RE_SRP_LNG ) == "9.409594" );
   CPPUNIT_ASSERT( cat065_message->getValue( Cat065ItemNames::I065_RE_ARL ) == "17473" );

}
