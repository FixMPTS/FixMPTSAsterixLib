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
   std::shared_ptr<AsterixCategory063> cat063_message = std::make_shared<AsterixCategory063>( remaining_length,
      message );

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

void TestAsterixCAT63Decoding::testCAT063EnAndDecoding() {
   AsterixCategory063 cat;
   SensorServiceRecordType record;
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat063ItemNames::I063_010] = true;
   items_to_be_served[Cat063ItemNames::I063_015] = true;
   items_to_be_served[Cat063ItemNames::I063_030] = true;
   items_to_be_served[Cat063ItemNames::I063_050] = true;
   items_to_be_served[Cat063ItemNames::I063_060] = true;
   items_to_be_served[Cat063ItemNames::I063_070] = true;
   items_to_be_served[Cat063ItemNames::I063_080] = true;
   items_to_be_served[Cat063ItemNames::I063_081] = true;
   items_to_be_served[Cat063ItemNames::I063_090] = true;
   items_to_be_served[Cat063ItemNames::I063_091] = true;
   items_to_be_served[Cat063ItemNames::I063_092] = true;

   // set up the data
   cat.setSourceId( 200, 10 );
   record.setSensorIdentifier( 200, 2 );
   record.setMessageType( 3 );
   record.setTimeOfDay( 234.4 );
   cat.setSensorConfiguration( AsterixCategory063::SENSOR_CONFIGURATION::SSR, 1 );
   cat.setSensorConfiguration( AsterixCategory063::SENSOR_CONFIGURATION::CON, 1 );
   cat.setSensorConfiguration( AsterixCategory063::SENSOR_CONFIGURATION::PSR, 0 );
   cat.setSensorConfiguration( AsterixCategory063::SENSOR_CONFIGURATION::TSV, 1 );
   cat.setTimestampingBias( 4 );
   cat.setSSRRangeGainBias( 0.3, 10 );
   cat.setSSRAzimuthBias( 12 );
   cat.setPSRRangeGainBias( 0.21, 2 );
   cat.setPSRAzimuthBias( 6 );
   cat.setPSRElevationBias( 7.1 );

   std::vector<char> msg = cat.getEncodedMessage( record, items_to_be_served );

   // Check the encoded and decoded result
   std::deque<char> input = std::deque<char>();
   input.insert( input.end(), msg.begin() + 3, msg.end() ); // discard category and length bytes

   AsterixCategory063 decoded_cat = AsterixCategory063( msg.size(), input );

   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_010_SAC ) == "200" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_010_SIC ) == "10" );
   CPPUNIT_ASSERT( std::to_string( record.getMessageType() ) == decoded_cat.getValue( Cat063ItemNames::I063_015_SID ) );
   float tod = std::atof( decoded_cat.getValue( Cat063ItemNames::I063_030_TOD ).c_str() );
   CPPUNIT_ASSERT( tod >= (record.getTimeOfDay() - 0.1) && tod <= (record.getTimeOfDay() + 0.1) );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_050_SAC ) == "200" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_050_SIC ) == "2" );

   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_060_SSR ) == "1" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_060_CON ) == "1" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_060_PSR ) == "0" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_060_TSV ) == "1" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_070_TSB ) == "4" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_080_SRB ) == "10.000000" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_080_SRG ) == "0.300000" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_081_SAB ) == "12.002563" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_090_PRG ) == "0.210000" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_090_PRB ) == "2.000000" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_091_PAB ) == "5.998535" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat063ItemNames::I063_092_PEB ) == "7.102661" );
}

