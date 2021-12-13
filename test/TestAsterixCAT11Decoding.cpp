/**
 * @file TestAsterixCAT11Decoding.cpp
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
#include "TestAsterixCAT11Decoding.h"

#include "AsterixCategory011.h"
#include "BinaryHelper.h"
#include "Cat011ItemNames.h"

void TestAsterixCAT11Decoding::setUp() {

}

void TestAsterixCAT11Decoding::tearDown() {

}

void TestAsterixCAT11Decoding::testCAT011Status() {
   std::ifstream inFile;
   inFile.open( "TestData/test_data_cat011Status", std::ios::in | std::ios::binary | std::ios::in );

   char cat[1];
   inFile.read( cat, sizeof(cat) / sizeof(*cat) );

   CPPUNIT_ASSERT( charToULIntBE( cat, 1 ) == 11 );

   char length[2];
   inFile.read( length, sizeof(length) / sizeof(*length) );

   CPPUNIT_ASSERT( charToULIntBE( length, 2 ) == 159 );

   // the 3 is because the length counts itself and the cat along with the rest of the message
   unsigned long int block_length = charToULIntBE( length, 2 ) - 3;

   char astx_block[block_length];
   inFile.read( astx_block, block_length );
   int remaining_length = sizeof(astx_block);

   std::deque<char> message( astx_block, astx_block + sizeof(astx_block) / sizeof(char) );
   AsterixCategory011 *cat011_message = new AsterixCategory011( remaining_length, message );

   //cat011_message->printMessage();

   CPPUNIT_ASSERT( cat011_message->getFspecString() == "1111111111111111111111111110" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_010_SAC ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_010_SIC ) == "42" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_000_TYP ) == "1" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_015_SID ) == "82" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_140_TOD ) == "547.765625" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_041_LAT ) == "47.673200" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_041_LNG ) == "9.522370" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_042_X ) == "1824" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_042_Y ) == "551" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_202_VX ) == "-45.000000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_202_VY ) == "590.000000" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_210_AX ) == "12.000000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_210_AY ) == "23.000000" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_060_CODE ) == "576" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_245_ID ) == "DLH001" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_MBS_DATA + ".0" ) == "282574496776281" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_MBS_BDS1 + ".0" ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_MBS_BDS2 + ".0" ) == "2" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_ADDR ) == "11184810" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_ACAS_COM ) == "2" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_ACAS_STAT ) == "4" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_ACAS_SSC ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_ACAS_ARC ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_ACAS_AIC ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_ACAS_B1A ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_ACAS_B1B ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_ACAS_AC ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_ACAS_MN ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_ACAS_DC ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_ACT ) == "A321" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_EC ) == "3" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_380_AT ) == "64" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_161_TRK ) == "1982" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_MON ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_GBS ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_MRH ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_SRC ) == "7" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_CNF ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_SIM ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_TSE ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_TSB ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_FRI ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_ME ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_MI ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_AMA ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_SPI ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_CST ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_FPC ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_AFF ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_PSR ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_SSR ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_MDS ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_ADS ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_SUC ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_170_ACC ) == "0" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_290_MDA ) == "60.000000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_290_MFL ) == "22.500000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_290_MDS ) == "5.000000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_290_ADB ) == "1.250000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_290_LOP ) == "10.000000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_290_TRK ) == "8.500000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_290_MUL ) == "0.250000" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_430_FLS ) == "2" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_090_FL ) == "10.000000" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_093_QNH ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_093_ALT ) == "0.750000" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_092_FL ) == "75.000000" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_215_CD ) == "-6.250000" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_270_L ) == "77" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_270_O ) == "239.062500" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_270_W ) == "69" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_TAG_SAC ) == "48" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_TAG_SIC ) == "3" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_CSN ) == "DHL001 " );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_IFI_TYP ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_IFI_NBR ) == "734" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_FCT_GAT ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_FCT_FR1 ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_FCT_RVSM ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_FCT_HPR ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_TAC ) == "A321" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_WTC ) == "M" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_DEP ) == "EDNY" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_DST ) == "EDDF" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_AST ) == "B13   " );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_STS_EMP ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_390_STS_AVL ) == "0" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_300_VFI ) == "9" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_310_TRB ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_310_MSG ) == "2" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_500_APC_X ) == "5.000000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_500_APC_Y ) == "48.000000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_500_APW_LAT ) == "0.000346" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_500_APW_LNG ) == "0.002061" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_500_AVC_X ) == "11.200000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_500_AVC_Y ) == "6.900000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_500_AAC_X ) == "1.800000" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_500_AAC_Y ) == "0.180000" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_600_ACK ) == "0" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_600_SVR ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_600_AT ) == "5" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_600_AN ) == "2" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_605_TRK + ".0" ) == "22" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_605_TRK + ".1" ) == "1864" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_605_TRK + ".2" ) == "4001" );

   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_610_BKN + ".0" ) == "1" );
   CPPUNIT_ASSERT( cat011_message->getValue( Cat011ItemNames::I011_610_BKI + ".0" ) == "1632" );
}

