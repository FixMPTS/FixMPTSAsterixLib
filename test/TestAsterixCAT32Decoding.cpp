/**
 * @file TestAsterixCAT32Decoding.cpp
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
#include "TestAsterixCAT32Decoding.h"

#include "BinaryHelper.h"
#include "AsterixCategory032.h"
#include "Cat032ItemNames.h"

void TestAsterixCAT32Decoding::setUp() {

}

void TestAsterixCAT32Decoding::tearDown() {

}

void TestAsterixCAT32Decoding::testCAT032() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat032", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 32 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 99 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory032* cat032_message = new AsterixCategory032( remaining_length, message );

   //cat032_message->printMessage();

   std::cout << "1" << std::endl;
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_010_SAC ) == "8" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_010_SIC ) == "200" );

   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_015_UN ) == "65530" );

   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_018_SAC ) == "8" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_018_SIC ) == "250" );

   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_035_FAM ) == "1" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_035_NAT ) == "1" );

   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_020_TOD ) == "16609.382812" );

   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_040_TRK ) == "4096" );

   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_050_MSU ) == "1" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_050_MTN ) == "4096" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_050_SSU ) == "2" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_050_STN ) == "309" );

   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_060_CODE ) == "3904" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_400_CS ) == "SWR188 " );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_410_PNU ) == "7" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_420_GAT ) == "1" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_420_FR1 ) == "0" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_420_SP3 ) == "0" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_420_SP2 ) == "0" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_420_SP1 ) == "0" );

   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_440_DEP ) == "LSZH" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_450_DST ) == "ZSPD" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_480_FL ) == "32000" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_490_CENTRE ) == "1" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_490_POS ) == "10" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_430_AT ) == "A343" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_435_WTC ) == "H" );

   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_460_CODE + ".0" ) == "1112" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_460_CODE + ".1" ) == "72" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_460_CODE + ".2" ) == "3649" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_460_CODE + ".3" ) == "2064" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_460_CODE + ".4" ) == "8" );

   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_IFI_TYP ) == "0" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_IFI_NBR ) == "1040" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_RVP_RVSM ) == "1" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_RVP_HPR ) == "0" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_RDS ) == "16 " );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_TOD_TYP + ".0" ) == "6" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_TOD_DAY + ".0" ) == "0" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_TOD_HOR + ".0" ) == "13" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_TOD_MIN + ".0" ) == "21" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_TOD_AVS + ".0" ) == "0" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_TOD_SEC + ".0" ) == "36" );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_AST ) == "C27   " );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_STD ) == "SID1   " );
   CPPUNIT_ASSERT( cat032_message->getValue( Cat032ItemNames::I032_500_STA ) == "DEGES  " );
}

