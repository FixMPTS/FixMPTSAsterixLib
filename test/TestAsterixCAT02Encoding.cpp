/**
 * @file TestAsterixCAT02Encoding.cpp
 * @author  Felix Kreuter <felix.kreuter@lordcentury.net>
 * @version 1.0
 * Created on: 31 Mar 2022
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
 * Test cases verifying the encoding of Asterix CAt 002 messages
 */

#include "TestAsterixCAT02Encoding.h"
#include "AsterixCategory002.h"
#include "Cat002ItemNames.h"

#include <bitset>
#include <deque>

void TestAsterixCAT02Encoding::setUp() {
   // Nothing to do
}

void TestAsterixCAT02Encoding::tearDown() {
   // Nothing to do
}

void TestAsterixCAT02Encoding::testCAT002Mandatory() {
   AsterixCategory002 cat;
   SensorServiceRecordType record;
   std::map<std::string, bool> items_to_be_served; // none set -> only mandatory items served

   // set up the data
   record.setSensorIdentifier( 100, 101 );
   record.setMessageType( 3 );

   std::vector<unsigned char> msg = cat.getEncodedMessage( record, items_to_be_served );

   // Test the FSPEC
   CPPUNIT_ASSERT( std::to_string( msg[0] ) == "2" ); // Category

   CPPUNIT_ASSERT( std::to_string( msg[1] ) == "0" ); // length
   CPPUNIT_ASSERT( std::to_string( msg[2] ) == "7" ); // length

   std::bitset<8> fspec_byte( (unsigned int) msg[3] );
   CPPUNIT_ASSERT( fspec_byte.to_string() == "11000000" ); // first fspec byte

   CPPUNIT_ASSERT( std::to_string( msg[4] ) == "100" ); // SAC
   CPPUNIT_ASSERT( std::to_string( msg[5] ) == "101" ); // SIC

   CPPUNIT_ASSERT( std::to_string( msg[6] ) == "3" ); // Message Type

   // Test mandatory items if information is not coming from the report but has been set in the data type beforehand
   AsterixCategory002 cat2;
   SensorServiceRecordType record2;

   // set up the data
   record2.setSensorIdentifier( 102, 103 );
   record2.setMessageType( 2 );

   // Set the mandatory items directly
   cat2.setDataSource( 104, 105 );
   cat2.setMessageType( SensorServiceRecordType::MESSAGETYPE::START_BLIND_ZONE );

   std::vector<unsigned char> msg2 = cat2.getEncodedMessage( record2, items_to_be_served );
   std::bitset<8> fspec_byte2( (unsigned int) msg2[3] );
   CPPUNIT_ASSERT( fspec_byte2.to_string() == "11000000" ); // first fspec byte

   CPPUNIT_ASSERT( std::to_string( msg2[4] ) == "104" ); // SAC
   CPPUNIT_ASSERT( std::to_string( msg2[5] ) == "105" ); // SIC

   CPPUNIT_ASSERT( std::to_string( msg2[6] ) == "8" ); // Message Type
}

void TestAsterixCAT02Encoding::testCAT002Common() {
   AsterixCategory002 cat;
   SensorServiceRecordType record;
   std::map<std::string, bool> items_to_be_served; // none set -> only mandatory items served
   items_to_be_served[Cat002ItemNames::I002_010] = true;
   items_to_be_served[Cat002ItemNames::I002_000] = true;
   items_to_be_served[Cat002ItemNames::I002_020] = true;
   items_to_be_served[Cat002ItemNames::I002_030] = true;
   items_to_be_served[Cat002ItemNames::I002_041] = true;
   items_to_be_served[Cat002ItemNames::I002_070] = true;
   items_to_be_served[Cat002ItemNames::I002_100] = true;
   items_to_be_served[Cat002ItemNames::I002_090] = true;
   // Error conditionnotf part of the message

   // set up the data
   record.setSensorIdentifier( 108, 109 );
   record.setMessageType( 7 );
   record.setSectorNumber( 176.2 );
   record.setTimeOfDay( 12345 );
   record.setAntennaSpeed( 23.4 );

   // set up the plot count item
   SensorServiceRecordType::PlotCount pc1;
   pc1.setAntenna( 0 );
   pc1.setCounter( 10 );
   pc1.setIdent( 30 );
   record.addPlotCount( pc1 );

   SensorServiceRecordType::PlotCount pc2;
   pc2.setAntenna( 1 );
   pc2.setCounter( 23 );
   pc2.setIdent( 21 );
   record.addPlotCount( pc2 );

   // Setup item only to be set via the dedicated category header
   cat.setDynamicWindow( 12.4, 24.5, 354.1, 400 );
   cat.setCollimationError( 3.1, 0.2 );

   std::vector<unsigned char> msg = cat.getEncodedMessage( record, items_to_be_served );

   // Test the FSPEC
   CPPUNIT_ASSERT( std::to_string( msg[0] ) == "2" ); // Category

   CPPUNIT_ASSERT( std::to_string( msg[1] ) == "0" ); // length
   CPPUNIT_ASSERT( std::to_string( msg[2] ) == "29" ); // length

   std::bitset<8> fspec_byte1( (unsigned int) msg[3] );
   std::bitset<8> fspec_byte2( (unsigned int) msg[4] );
   CPPUNIT_ASSERT( fspec_byte1.to_string() == "11111001" ); // first fspec byte
   CPPUNIT_ASSERT( fspec_byte2.to_string() == "11100000" ); // first fspec byte

   CPPUNIT_ASSERT( std::to_string( msg[5] ) == "108" ); // SAC
   CPPUNIT_ASSERT( std::to_string( msg[6] ) == "109" ); // SIC

   CPPUNIT_ASSERT( std::to_string( msg[7] ) == "7" ); // MSG type
   CPPUNIT_ASSERT( std::to_string( msg[8] ) == "125" ); // Sector number

   // I002/030 Time of day
   uint64_t tod = (unsigned int) msg[9];
   tod <<= 8;
   tod |= ((unsigned int) msg[10] & 0xff);
   tod <<= 8;
   tod |= ((unsigned int) msg[11] & 0xff);
   CPPUNIT_ASSERT( tod == 1580160 );

   // I002/041 Antenna Rotation Period
   uint16_t rotation = (unsigned int) msg[12];
   rotation <<= 8;
   rotation |= ((unsigned int) msg[13] & 0xff);
   CPPUNIT_ASSERT( rotation == 2995 );

   //I002/070 Plot Count Values
   CPPUNIT_ASSERT( std::to_string( msg[14] ) == "2" );
   std::bitset<16> first_plot_count( (unsigned int) msg[15] );
   first_plot_count <<= 8;
   first_plot_count |= ((unsigned int) msg[16] & 0xff);
   CPPUNIT_ASSERT( first_plot_count[15] == 0 ); // Antenna
   std::bitset<5> ident1( first_plot_count.to_string(), 1, 5 );
   std::bitset<10> count1( first_plot_count.to_string(), 6, 10 );

   CPPUNIT_ASSERT( ident1.to_ulong() == 30 );
   CPPUNIT_ASSERT( count1.to_ulong() == 10 );

   std::bitset<16> second_plot_count( (unsigned int) msg[17] );
   second_plot_count <<= 8;
   second_plot_count |= ((unsigned int) msg[18] & 0xff);
   CPPUNIT_ASSERT( second_plot_count[15] == 1 ); // Antenna
   std::bitset<5> ident2( second_plot_count.to_string(), 1, 5 );
   std::bitset<10> count2( second_plot_count.to_string(), 6, 10 );

   // I002/100 Dynamic Window
   std::bitset<16> rho_start( (unsigned) msg[19] );
   rho_start <<= 8;
   rho_start |= ((unsigned) msg[20] & 0xff);
   std::bitset<16> rho_end( (unsigned) msg[21] );
   rho_end <<= 8;
   rho_end |= ((unsigned) msg[22] & 0xff);
   std::bitset<16> theta_start( (unsigned) msg[23] );
   theta_start <<= 8;
   theta_start |= ((unsigned) msg[24] & 0xff);
   std::bitset<16> theta_end( (unsigned) msg[25] );
   theta_end <<= 8;
   theta_end |= ((unsigned) msg[26] & 0xff);
   CPPUNIT_ASSERT( rho_start.to_ulong() == 1587 );
   CPPUNIT_ASSERT( rho_end.to_ulong() == 3136 );
   CPPUNIT_ASSERT( theta_start.to_ulong() == 64381 );
   CPPUNIT_ASSERT( theta_end.to_ulong() == 7191 );

   //I002/090 Collimation Error
   std::bitset<8> range_error( (unsigned int) msg[27] );
   std::bitset<8> azimuth_error( (unsigned int) msg[28] );
   CPPUNIT_ASSERT( range_error.to_ulong() == 140 );
   CPPUNIT_ASSERT( azimuth_error.to_ulong() == 36 );
}

void TestAsterixCAT02Encoding::testCAT002EnAndDecoding() {
   AsterixCategory002 cat;
   SensorServiceRecordType record;
   std::map<std::string, bool> items_to_be_served; // none set -> only mandatory items served
   items_to_be_served[Cat002ItemNames::I002_010] = true;
   items_to_be_served[Cat002ItemNames::I002_000] = true;
   items_to_be_served[Cat002ItemNames::I002_020] = true;
   items_to_be_served[Cat002ItemNames::I002_030] = true;
   items_to_be_served[Cat002ItemNames::I002_041] = true;
   items_to_be_served[Cat002ItemNames::I002_070] = true;
   items_to_be_served[Cat002ItemNames::I002_100] = true;
   items_to_be_served[Cat002ItemNames::I002_090] = true;
   // Error conditionnotf part of the message

   // set up the data
   record.setSensorIdentifier( 111, 112 );
   record.setMessageType( 9 );
   record.setSectorNumber( 15.3 );
   record.setTimeOfDay( 12345 );
   record.setAntennaSpeed( 54.65 );

   // set up the plot count item
   SensorServiceRecordType::PlotCount pc1;
   pc1.setAntenna( 0 );
   pc1.setIdent( 11 );
   pc1.setCounter( 258 );
   record.addPlotCount( pc1 );

   cat.setDynamicWindow( 12.4, 24.5, 354.1, 400 );
   cat.setCollimationError( 3.1, 0.2 );

   std::vector<unsigned char> msg = cat.getEncodedMessage( record, items_to_be_served );

   std::deque<char> input = std::deque<char>();
   input.insert( input.end(), msg.begin() + 3, msg.end() ); // discard category and length bytes

   AsterixCategory002 decodedCat = AsterixCategory002( msg.size(), input );
   decodedCat.decode();

   CPPUNIT_ASSERT( std::to_string( std::get<0>( record.getSensorId() ) ) ==
      decodedCat.getValue( Cat002ItemNames::I002_010_SAC ) );
   CPPUNIT_ASSERT( std::to_string( std::get<1>( record.getSensorId() ) ) ==
      decodedCat.getValue( Cat002ItemNames::I002_010_SIC ) );
   CPPUNIT_ASSERT( std::to_string( record.getMessageType() ) ==
      decodedCat.getValue( Cat002ItemNames::I002_000_TYP ) );

   float sector = std::atof( decodedCat.getValue( Cat002ItemNames::I002_020_SCT ).c_str() );
   CPPUNIT_ASSERT( sector >= (record.getSectorNumber() - 0.2) && sector <= (record.getSectorNumber() + 0.2) );

   CPPUNIT_ASSERT( std::to_string( record.getTimeOfDay() ) == decodedCat.getValue( Cat002ItemNames::I002_030_TOD ) );

   float rotation = std::atof( decodedCat.getValue( Cat002ItemNames::I002_041_ROT ).c_str() );
   CPPUNIT_ASSERT( rotation >= (record.getAntennaSpeed() - 0.1) && rotation <= (record.getAntennaSpeed() + 0.1) );

   CPPUNIT_ASSERT( decodedCat.getValue( Cat002ItemNames::I002_070_A + ".0" ) == "0" );
   CPPUNIT_ASSERT( decodedCat.getValue( Cat002ItemNames::I002_070_ID + ".0" ) == "11" );
   CPPUNIT_ASSERT( decodedCat.getValue( Cat002ItemNames::I002_070_CNT + ".0" ) == "258" );

   float rhs = std::atof( decodedCat.getValue( Cat002ItemNames::I002_100_RHS ).c_str() );
   float rhe = std::atof( decodedCat.getValue( Cat002ItemNames::I002_100_RHE ).c_str() );
   float ths = std::atof( decodedCat.getValue( Cat002ItemNames::I002_100_THS ).c_str() );
   float the = std::atof( decodedCat.getValue( Cat002ItemNames::I002_100_THE ).c_str() );
   CPPUNIT_ASSERT( rhs > 12.38 && rhs < 12.41 );
   CPPUNIT_ASSERT( rhe > 24.48 && rhe < 24.51 );
   CPPUNIT_ASSERT( ths > 353.64 && ths < 353.66 );
   CPPUNIT_ASSERT( the > 39.48 && the < 39.51 );

   float col_azim = std::atof( decodedCat.getValue( Cat002ItemNames::I002_090_AZM ).c_str() );
   float col_rng = std::atof( decodedCat.getValue( Cat002ItemNames::I002_090_RNG ).c_str() );
   CPPUNIT_ASSERT( col_azim > 0.76 && col_azim < 0.78 );
   CPPUNIT_ASSERT( col_rng > 0.28 && col_rng < 0.29 );
}
