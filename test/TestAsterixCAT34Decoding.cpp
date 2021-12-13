/**
 * @file TestAsterixCAT34Decoding.cpp
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
#include "TestAsterixCAT34Decoding.h"
#include "Cat034ItemNames.h"
#include "BinaryHelper.h"
#include "AsterixCategory034.h"

void TestAsterixCAT34Decoding::setUp() {

}

void TestAsterixCAT34Decoding::tearDown() {

}

void TestAsterixCAT34Decoding::testCAT034() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat034_1", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 34 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 16 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory034* cat034_message = new AsterixCategory034( remaining_length, message );

   // Verify the message content
   CPPUNIT_ASSERT( cat034_message->getFspecString() == "11110110000000" );

   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_000_TYPE ) == "2" );

   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_010_SAC ) == "25" );
   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_010_SIC ) == "14" );

   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_030_TOD ) == "29906.335938" );

   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_020_SCT ) == "90.000000" );

   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_050_COM_MSC ) == "0" );
   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_050_COM_NOG ) == "0" );
   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_050_COM_ORDP ) == "0" );
   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_050_COM_OXMT ) == "0" );
   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_050_COM_RDPC ) == "1" );
   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_050_COM_RDPR ) == "0" );
   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_050_COM_TSV ) == "0" );

   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_050_SSR_ANT ) == "0" );
   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_050_SSR_CH ) == "2" );
   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_050_SSR_MSC ) == "0" );

   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_060_COM_REDR ) == "0" );
   CPPUNIT_ASSERT( cat034_message->getValue( Cat034ItemNames::I034_060_COM_REDX ) == "0" );
}
