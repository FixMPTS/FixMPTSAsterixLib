/**
 * @file TestAsterixCAT19Decoding.cpp
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
#include "TestAsterixCAT19Decoding.h"

#include "AsterixCategory019.h"
#include "BinaryHelper.h"
#include "Cat019ItemNames.h"

void TestAsterixCAT19Decoding::setUp() {

}

void TestAsterixCAT19Decoding::tearDown() {

}

void TestAsterixCAT19Decoding::testCAT019Start() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat019Start", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 19 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 31 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory019* cat019_message = new AsterixCategory019( remaining_length, message );

   //cat019_message->printMessage();

   CPPUNIT_ASSERT( cat019_message->getFspecString() == "11111111110000" );

   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_010_SAC ) == "98" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_010_SIC ) == "250" );

   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_000_TYP ) == "1" );

   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_140_TOD ) == "8269.734375" );

   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_550_NOGO ) == "0" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_550_OVL ) == "0" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_550_TSV ) == "0" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_550_TTF ) == "1" );

   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_551_STAT ) == "240" );

   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_552_RSI + ".0" ) == "2" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_552_RST + ".0" ) == "2" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_552_STAT + ".0" ) == "12" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_552_RSI + ".1" ) == "3" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_552_RST + ".1" ) == "2" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_552_STAT + ".1" ) == "4" );

   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_553_RT1 ) == "3" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_553_RT2 ) == "3" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_553_RT3 ) == "3" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_553_RT4 ) == "1" );

   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_600_LAT ) == "5.658133" );
   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_600_LNG ) == "-0.626087" );

   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_610_ALT ) == "230.000000" );

   CPPUNIT_ASSERT( cat019_message->getValue( Cat019ItemNames::I019_620_U ) == "54" );
}

