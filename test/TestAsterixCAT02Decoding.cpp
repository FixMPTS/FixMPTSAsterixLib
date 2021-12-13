/**
 * @file TestAsterixCAT02Decoding.cpp
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
#include "TestAsterixCAT02Decoding.h"

#include "AsterixCategory002.h"
#include "BinaryHelper.h"
#include "Cat002ItemNames.h"

void TestAsterixCAT02Decoding::setUp() {

}

void TestAsterixCAT02Decoding::tearDown() {

}

void TestAsterixCAT02Decoding::testCAT002() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat002", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 2 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   switch( charToULIntBE( cat, 1 ) ){
      case 2: {
         std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
         AsterixCategory002* cat002_message = new AsterixCategory002( remaining_length, message );

         CPPUNIT_ASSERT( cat002_message->getValue( Cat002ItemNames::I002_000_TYP ) == "2" );

         CPPUNIT_ASSERT( cat002_message->getValue( Cat002ItemNames::I002_010_SAC ) == "8" );
         CPPUNIT_ASSERT( cat002_message->getValue( Cat002ItemNames::I002_010_SIC ) == "24" );

         CPPUNIT_ASSERT( cat002_message->getValue( Cat002ItemNames::I002_020_SCT ) == "168.750000" );
         CPPUNIT_ASSERT( cat002_message->getValue( Cat002ItemNames::I002_030_TOD ) == "40133.632812" );
         break;
      }
      default: {
         CPPUNIT_ASSERT( false );
         break;
      }
   }
}

void TestAsterixCAT02Decoding::test2CAT002() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat002_2", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 2 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   switch( charToULIntBE( cat, 1 ) ){
      case 2: {
         std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
         AsterixCategory002* cat002_message = new AsterixCategory002( remaining_length, message );

         CPPUNIT_ASSERT( cat002_message->getValue( Cat002ItemNames::I002_000_TYP ) == "2" );

         CPPUNIT_ASSERT( cat002_message->getValue( Cat002ItemNames::I002_010_SAC ) == "8" );
         CPPUNIT_ASSERT( cat002_message->getValue( Cat002ItemNames::I002_010_SIC ) == "24" );

         CPPUNIT_ASSERT( cat002_message->getValue( Cat002ItemNames::I002_020_SCT ) == "180.000000" );
         CPPUNIT_ASSERT( cat002_message->getValue( Cat002ItemNames::I002_030_TOD ) == "40133.789062" );

         break;
      }
      default: {
         CPPUNIT_ASSERT( false );
         break;
      }
   }
}
