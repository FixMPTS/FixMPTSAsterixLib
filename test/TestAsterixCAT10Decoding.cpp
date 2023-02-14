/**
 * @file TestAsterixCAT10Decoding.cpp
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
#include "TestAsterixCAT10Decoding.h"

#include "AsterixCategory010.h"
#include "BinaryHelper.h"
#include "Cat010ItemNames.h"

void TestAsterixCAT10Decoding::setUp() {

}

void TestAsterixCAT10Decoding::tearDown() {

}

void TestAsterixCAT10Decoding::testCAT010Report() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat010Report", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 10 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 87 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory010* cat010_message = new AsterixCategory010( remaining_length, message );

   //cat010_message->printMessage();

   CPPUNIT_ASSERT( cat010_message->getFspecString() == "1111111111111111111011111000" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_010_SAC ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_010_SIC ) == "10" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_000_TYP ) == "1" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_020_TYP ) == "5" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_020_DCR ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_020_CHN ) == "1" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_020_GBS ) == "1" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_020_CRT ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_020_SIM ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_020_TST ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_020_RAB ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_020_LOP ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_020_TOT ) == "1" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_140_TOD ) == "513.992188" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_041_LAT ) == "50.044147" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_041_LNG ) == "8.526995" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_040_RHO ) == "259" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_040_THETA ) == "24.098511" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_042_X ) == "142" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_042_Y ) == "2865" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_200_GSP ) == "15.380859" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_200_TA ) == "121.997681" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_202_VX ) == "3.000000" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_202_VY ) == "-10.000000" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_161_TRK ) == "2095" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_170_CNF ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_170_TRE ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_170_CST ) == "2" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_170_MAH ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_170_TCC ) == "1" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_170_STH ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_170_TOM ) == "3" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_170_DOU ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_170_MRS ) == "0" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_060_V ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_060_G ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_060_L ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_060_CODE ) == "744" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_220_ADDR ) == "2369312" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_245_STI ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_245_ID ) == "REU974" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_250_DATA + ".0" ) == "9007474172565568" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_250_BDS1 + ".0" ) == "5" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_250_BDS2 + ".0" ) == "1" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_300_VFI ) == "14" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_090_V ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_090_G ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_090_FL ) == "0.000000" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_091_ALT ) == "31.250000" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_270_L ) == "74" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_270_O ) == "180.000000" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_270_W ) == "61" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_310_TRB ) == "0" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_310_MSG ) == "1" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_500_DX ) == "2.000000" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_500_DY ) == "5.500000" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_500_DXY ) == "1.250000" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_280_DRHO + ".0" ) == "10" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_280_DRHO + ".1" ) == "2" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_280_DRHO + ".2" ) == "7" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_280_DTHETA + ".0" ) == "1.650000" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_280_DTHETA + ".1" ) == "0.450000" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_280_DTHETA + ".2" ) == "3.750000" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_131_AMP ) == "199" );

   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_210_AX ) == "17.000000" );
   CPPUNIT_ASSERT( cat010_message->getValue( Cat010ItemNames::I010_210_AY ) == "21.000000" );
}
