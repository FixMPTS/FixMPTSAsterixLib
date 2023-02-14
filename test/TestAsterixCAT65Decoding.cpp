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

void TestAsterixCAT65Decoding::testCAT065EnAndDecodingSDPS() {
   AsterixCategory065 cat;
   SensorServiceRecordType record;
   std::map<std::string, bool> items_to_be_served; // none set -> only mandatory items served

   // Setup the message
   cat.setDataSourceId( 200, 10 );
   cat.setBatchNumber( 21 );
   cat.setSDPSConfiguration( AsterixCategory065::SDPS_CONFIGURATION::OVL, 1 );
   cat.setSDPSConfiguration( AsterixCategory065::SDPS_CONFIGURATION::NOGO, 0 );
   cat.setSDPSConfiguration( AsterixCategory065::SDPS_CONFIGURATION::STTN, 1 );
   cat.setReLatLng( 40.3, 13.87 );
   cat.setReport( 2 );
   cat.setSrp( 4 );
   cat.setArl( 6 );
   cat.setMessageType( 1 );
   cat.setServiceIdentification( 33 );
   record.setSensorIdentifier( 200, 2 );
   record.setTimeOfDay( 2341.3 );

   std::vector<char> msg = cat.getEncodedMessage( record, items_to_be_served );

   // Check the encoded and decoded result
   std::deque<char> input = std::deque<char>();
   input.insert( input.end(), msg.begin() + 3, msg.end() ); // discard category and length bytes

   AsterixCategory065 decoded_cat = AsterixCategory065( msg.size(), input );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_010_SAC ) == "200" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_010_SIC ) == "10" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_000_TYP ) == "1" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_015_SID ) == "33" );
   double tod = std::atof( decoded_cat.getValue( Cat065ItemNames::I065_030_TOD ).c_str() );
   CPPUNIT_ASSERT( tod > 2341.29 && tod < 2341.31 );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_040_NOGO ) == "0" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_040_OVL ) == "1" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_040_STTN ) == "1" );

   // Although the batch number is set it is not part of the message
   if( decoded_cat.isItemPresent( Cat065ItemNames::I065_020_BTN ) ) {
      CPPUNIT_ASSERT( false );
   }

   if( decoded_cat.isItemPresent( Cat065ItemNames::I065_050_REPORT ) ) {
      CPPUNIT_ASSERT( false );
   }
}

void TestAsterixCAT65Decoding::testCAT065EnAndDecodingEoBatch() {
   AsterixCategory065 cat;
   SensorServiceRecordType record;
   std::map<std::string, bool> items_to_be_served; // none set -> only mandatory items served

   // Setup the message
   cat.setDataSourceId( 200, 21 );
   cat.setBatchNumber( 13 );
   cat.setMessageType( 2 );
   cat.setServiceIdentification( 78 );
   cat.setSDPSConfiguration( AsterixCategory065::SDPS_CONFIGURATION::PSS, 1 );

   record.setSensorIdentifier( 200, 22 );
   record.setTimeOfDay( 502.7 );

   std::vector<char> msg = cat.getEncodedMessage( record, items_to_be_served );

   // Check the encoded and decoded result
   std::deque<char> input = std::deque<char>();
   input.insert( input.end(), msg.begin() + 3, msg.end() ); // discard category and length bytes

   AsterixCategory065 decoded_cat = AsterixCategory065( msg.size(), input );

   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_010_SAC ) == "200" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_010_SIC ) == "21" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_000_TYP ) == "2" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_020_BTN ) == "13" );
   double tod = std::atof( decoded_cat.getValue( Cat065ItemNames::I065_030_TOD ).c_str() );
   CPPUNIT_ASSERT( tod > 502.69 && tod < 502.71 );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_015_SID ) == "78" );

   // Verify the items not supposed to be encoded in the message are indeed not there
   if( decoded_cat.isItemPresent( Cat065ItemNames::I065_040_PSS ) ) {
      CPPUNIT_ASSERT( false );
   }

   if( decoded_cat.isItemPresent( Cat065ItemNames::I065_050_REPORT ) ) {
      CPPUNIT_ASSERT( false );
   }
}

void TestAsterixCAT65Decoding::testCAT065EnAndDecodingService() {
   AsterixCategory065 cat;
   SensorServiceRecordType record;
   std::map<std::string, bool> items_to_be_served; // none set -> only mandatory items served

   // Setup the message
   cat.setDataSourceId( 200, 31 );
   cat.setMessageType( 3 );
   cat.setServiceIdentification( 4 );
   cat.setBatchNumber( 13 );
   cat.setSDPSConfiguration( AsterixCategory065::SDPS_CONFIGURATION::OVL, 1 );
   cat.setReport( 2 );

   record.setTimeOfDay( 3021.0 );

   std::vector<char> msg = cat.getEncodedMessage( record, items_to_be_served );

   // Check the encoded and decoded result
   std::deque<char> input = std::deque<char>();
   input.insert( input.end(), msg.begin() + 3, msg.end() ); // discard category and length bytes

   AsterixCategory065 decoded_cat = AsterixCategory065( msg.size(), input );

   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_010_SAC ) == "200" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_010_SIC ) == "31" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_000_TYP ) == "3" );
   double tod = std::atof( decoded_cat.getValue( Cat065ItemNames::I065_030_TOD ).c_str() );
   CPPUNIT_ASSERT( tod > 3020.9 && tod < 3021.1 );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_050_REPORT ) == "2" );
   CPPUNIT_ASSERT( decoded_cat.getValue( Cat065ItemNames::I065_015_SID ) == "4" );

   // Verify the items not supposed to be encoded in the message are indeed not there
   if( decoded_cat.isItemPresent( Cat065ItemNames::I065_020_BTN ) ) {
      CPPUNIT_ASSERT( false );
   }

   if( decoded_cat.isItemPresent( Cat065ItemNames::I065_040_OVL ) ) {
      CPPUNIT_ASSERT( false );
   }
}

void TestAsterixCAT65Decoding::testCAT065EnAndDecodingError() {
   AsterixCategory065 cat;
   SensorServiceRecordType record;
   std::map<std::string, bool> items_to_be_served; // none set -> only mandatory items served

   // Setup the message
   cat.setDataSourceId( 200, 31 );
   cat.setMessageType( 4 );

   bool error_raised = false;
   try {
      std::deque<char> input = std::deque<char>();
      std::vector<char> msg = cat.getEncodedMessage( record, items_to_be_served );
      input.insert( input.end(), msg.begin() + 3, msg.end() ); // discard category and length bytes

      AsterixCategory065 decoded_cat = AsterixCategory065( msg.size(), input );
   } catch( EncodingError &e ) {
      error_raised = true;
   }
   CPPUNIT_ASSERT( error_raised );
}
