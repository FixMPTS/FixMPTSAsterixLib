/**
 * @file TestAsterixCAT01Decoding.cpp
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

#include "TestAsterixCAT01Decoding.h"
#include "BinaryHelper.h"
#include "Cat001ItemNames.h"

// class under test
#include "AsterixCategory001.h"

void TestAsterixCAT01Decoding::setUp() {
}

void TestAsterixCAT01Decoding::tearDown() {
}

void TestAsterixCAT01Decoding::testCAT001() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat001", std::ios::in | std::ios::binary | std::ios::in );

   //read CAT
   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );
   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 1 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   //read all messages in the block
   char astx_block[block_length];
   inFile.read( astx_block, block_length );

   int remaining_length = sizeof(astx_block);
   switch( charToULIntBE( cat, 1 ) ){
      case 1: {
         std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
         AsterixCategory001* cat001_message = new AsterixCategory001( remaining_length, message );

         //cat001_message->printMessage();

         //test the fspec is read correctly
         CPPUNIT_ASSERT( cat001_message->getFspecString() == "1111011100001001000000" );

         //Test the values of the items contained in the message under test
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_010_SIC ) == "24" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_010_SAC ) == "8" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_020_TYP ) == "1" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_020_SIM ) == "0" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_020_DET ) == "2" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_161_TPN ) == "475" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_040_THETA ) == "167.717285" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_040_RHO ) == "73.109375" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_200_HEAD ) == "132.758789" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_200_GS ) == "397.924805" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_070_CODE ) == "3495" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_070_L ) == "0" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_070_G ) == "0" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_070_V ) == "1" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_090_CODE ) == "179" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_090_V ) == "0" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_090_G ) == "0" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_170_CON ) == "0" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_170_RAD ) == "1" );

         //Test length of remaining message
         remaining_length = cat001_message->getRemainingLength();
         CPPUNIT_ASSERT( remaining_length >= 0 ); // Probably a second message left

         break;
      }
      default: {
         CPPUNIT_ASSERT( false );
         break;
      }
   }
}

void TestAsterixCAT01Decoding::test2CAT001() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat001_2", std::ios::in | std::ios::binary | std::ios::in );

   //read CAT
   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );
   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 1 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   //read all messages in the block
   char astx_block[block_length];
   inFile.read( astx_block, block_length );

   int remaining_length = sizeof(astx_block);
   switch( charToULIntBE( cat, 1 ) ){
      case 1: {
         std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
         AsterixCategory001* cat001_message = new AsterixCategory001( remaining_length, message );

         //test the fspec is read correctly
         CPPUNIT_ASSERT( cat001_message->getFspecString() == "11110111000010000000" );

         //Test the values of the items contained in the message under test
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_010_SIC ) == "23" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_010_SAC ) == "8" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_020_TYP ) == "1" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_020_SIM ) == "0" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_020_DET ) == "2" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_020_ANT ) == "1" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_020_SPI ) == "0" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_161_TPN ) == "346" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_040_THETA ) == "165.058594" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_040_RHO ) == "236.367188" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_200_HEAD ) == "252.180176" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_200_GS ) == "418.798828" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_070_CODE ) == "3578" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_070_L ) == "0" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_070_G ) == "0" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_070_V ) == "0" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_090_CODE ) == "220" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_090_V ) == "0" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_090_G ) == "0" );

         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_170_CON ) == "0" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_170_DOU ) == "0" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_170_MAN ) == "0" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_170_RAD ) == "1" );
         CPPUNIT_ASSERT( cat001_message->getValue( Cat001ItemNames::I001_170_RDPC ) == "1" );

         //Test length of remaining message
         remaining_length = cat001_message->getRemainingLength();
         CPPUNIT_ASSERT( remaining_length >= 0 ); // Probably a second message left

         break;
      }
      default: {
         CPPUNIT_ASSERT( false );
         break;
      }
   }
}
