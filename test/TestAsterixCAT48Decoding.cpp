/**
 * @file TestAsterixCAT48Decoding.cpp
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
#include "TestAsterixCAT48Decoding.h"
#include "BinaryHelper.h"
#include "Cat048ItemNames.h"
#include "AsterixCategory048.h"

void TestAsterixCAT48Decoding::setUp() {

}

void TestAsterixCAT48Decoding::tearDown() {

}

void TestAsterixCAT48Decoding::testCAT048() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat048_1", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 48 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 48 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory048* cat048_message = new AsterixCategory048( remaining_length, message );

   //cat048_message->printMessage();

   CPPUNIT_ASSERT( cat048_message->getFspecString() == "1111110111101100000010000000" );

   // Check for all values present in this single message
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_010_SAC ) == "25" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_010_SIC ) == "201" );

   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_140_TOD ) == "27354.601562" );

   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_020_TYP ) == "5" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_020_SIM ) == "0" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_020_RDP ) == "0" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_020_SPI ) == "0" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_020_RAB ) == "0" );

   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_040_RHO ) == "197.683594" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_040_THETA ) == "340.136719" );

   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_070_V ) == "0" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_070_G ) == "0" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_070_L ) == "0" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_070_CODE ) == "512" );

   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_090_V ) == "0" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_090_G ) == "0" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_090_CODE ) == "330" );

   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_220_ADR ) == "3958284" );

   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_240_AID ) == "18426329569312" );

   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_250_DATA + ".0" ) == "54175137758183424" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_250_BDS1 + ".0" ) == "4" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_250_BDS2 + ".0" ) == "0" );

   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_161_TRK ) == "3563" );

   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_200_GSP ) == "434.399414" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_200_HDG ) == "124.002686" );

   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_170_CNF ) == "0" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_170_RAD ) == "2" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_170_DOU ) == "0" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_170_MAH ) == "0" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_170_CDM ) == "0" );

   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_230_COM ) == "1" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_230_STAT ) == "0" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_230_ARC ) == "1" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_230_MSSC ) == "1" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_230_AIC ) == "1" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_230_B1A ) == "1" );
   CPPUNIT_ASSERT( cat048_message->getValue( Cat048ItemNames::I048_230_B1B ) == "5" );
}
