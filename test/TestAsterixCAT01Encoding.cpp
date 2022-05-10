/**
 * @file TestAsterixCAT01Encoding.cpp
 * @author  Felix Kreuter <felix.kreuter@lordcentury.net>
 * @version 1.0
 * Created on: 6 Feb 2022
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
 * See .h file for more details
 */
#include "TestAsterixCAT01Encoding.h"
#include "AsterixCategory001.h"
#include "Cat001ItemNames.h"

#include <bitset>

void TestAsterixCAT01Encoding::setUp() {
   // nothing to do
}

void TestAsterixCAT01Encoding::tearDown() {
   // nothing to do
}

void TestAsterixCAT01Encoding::testCAT001Mandatory() {
   AsterixCategory001 cat;
   std::shared_ptr<ReportRecordType> record = std::make_shared<ReportRecordType>();
   std::map<std::string, bool> items_to_be_served; // none set -> only mandatory items served

   // set up the data
   record->setSource( 10, 20 );
   record->setDetectionType( DetectionEntry::DET_TYPE::CMB );
   record->setLocalTrackNumber( 7654 );

   std::vector<unsigned char> msg = cat.getEncodedMessage( record, items_to_be_served );

   // Test the FSPEC
   CPPUNIT_ASSERT( std::to_string( msg[0] ) == "1" ); // Category

   CPPUNIT_ASSERT( std::to_string( msg[1] ) == "0" ); // length
   CPPUNIT_ASSERT( std::to_string( msg[2] ) == "9" ); // length

   std::bitset<8> fspec_byte( (unsigned int) msg[3] );
   CPPUNIT_ASSERT( fspec_byte.to_string() == "11100000" ); // first fspec byte

   CPPUNIT_ASSERT( std::to_string( msg[4] ) == "10" ); // SAC
   CPPUNIT_ASSERT( std::to_string( msg[5] ) == "20" ); // SIC

   std::bitset<8> target_report( (unsigned int) msg[6] );
   CPPUNIT_ASSERT( target_report.to_string() == "10110000" ); // target report descriptor

   std::bitset<8> byte_1( (unsigned int) msg[7] );
   std::bitset<8> byte_2( (unsigned int) msg[8] );
   std::bitset<16> track_number( byte_1.to_string() + byte_2.to_string() );
   CPPUNIT_ASSERT( track_number.to_ullong() == 7654 );
}

void TestAsterixCAT01Encoding::testCAT001Common() {
   AsterixCategory001 cat;
   std::shared_ptr<ReportRecordType> record = std::make_shared<ReportRecordType>();
   std::map<std::string, bool> items_to_be_served;
   // set the items to be served in the test
   items_to_be_served[Cat001ItemNames::I001_040] = true;
   items_to_be_served[Cat001ItemNames::I001_042] = true;
   items_to_be_served[Cat001ItemNames::I001_200] = true;
   items_to_be_served[Cat001ItemNames::I001_070] = true;
   items_to_be_served[Cat001ItemNames::I001_090] = true;
   items_to_be_served[Cat001ItemNames::I001_141] = true;
   items_to_be_served[Cat001ItemNames::I001_170] = true;
   items_to_be_served[Cat001ItemNames::I001_080] = true;
   items_to_be_served[Cat001ItemNames::I001_030] = true;

   // set up the data
   record->setSource( 20, 10 );
   record->setDetectionType( DetectionEntry::DET_TYPE::SSR );
   record->setLocalTrackNumber( 531 );
   record->setRangeAzimuth( 122.2, 34.1 );
   record->setGeoPosLatLng( 40.2, -10.4 );
   record->setGroundSpeed( 432.0 );
   record->setHeading( 236.7 );
   record->setMode3A( 03456, true, false, true ); // leading 0 makes it octal
   record->setModeC( 01122, true, true, false );
   record->setDetectionTimeFromTOD( 9976 );

   // Set items not transfered via the record
   cat.setValue( Cat001ItemNames::I001_170_CON, "1" );
   cat.setValue( Cat001ItemNames::I001_170_MAN, "1" );
   cat.setValue( Cat001ItemNames::I001_170_TRE, "1" );
   cat.setValue( Cat001ItemNames::I001_080, "573" );
   cat.setValue( Cat001ItemNames::I001_030, "56" );

   std::vector<unsigned char> msg = cat.getEncodedMessage( record, items_to_be_served );

   // Test the FSPEC
   CPPUNIT_ASSERT( std::to_string( msg[0] ) == "1" ); // Category

   CPPUNIT_ASSERT( std::to_string( msg[1] ) == "0" ); // length
   CPPUNIT_ASSERT( std::to_string( msg[2] ) == "34" ); // length

   std::bitset<8> fspec_byte( (unsigned int) msg[3] );
   CPPUNIT_ASSERT( fspec_byte.to_string() == "11111111" ); // first fspec byte
   std::bitset<8> fspec_byte2( (unsigned int) msg[4] );
   CPPUNIT_ASSERT( fspec_byte2.to_string() == "11000101" ); // second fspec byte
   std::bitset<8> fspec_byte3( (unsigned int) msg[5] );
   CPPUNIT_ASSERT( fspec_byte3.to_string() == "01001000" ); // third fspec byte

   CPPUNIT_ASSERT( std::to_string( msg[6] ) == "20" ); // SAC
   CPPUNIT_ASSERT( std::to_string( msg[7] ) == "10" ); // SIC

   std::bitset<8> target_report( (unsigned int) msg[8] );
   CPPUNIT_ASSERT( target_report.to_string() == "10100000" ); // Track and SSR

   std::bitset<8> byte_1( (unsigned int) msg[9] );
   std::bitset<8> byte_2( (unsigned int) msg[10] );
   std::bitset<16> track_number( byte_1.to_string() + byte_2.to_string() );
   CPPUNIT_ASSERT( track_number.to_ullong() == 531 );

   // I001/040 Measured position
   std::bitset<8> rho_1( (unsigned int) msg[11] );
   std::bitset<8> rho_2( (unsigned int) msg[12] );
   std::bitset<16> rho( rho_1.to_string() + rho_2.to_string() );
   CPPUNIT_ASSERT( rho.to_ullong() == 15641 );

   std::bitset<8> theta_1( (unsigned int) msg[13] );
   std::bitset<8> theta_2( (unsigned int) msg[14] );
   std::bitset<16> theta( theta_1.to_string() + theta_2.to_string() );
   CPPUNIT_ASSERT( theta.to_ullong() == 6200 );

   // I001/042 Calculated Position in Cartesian Coordinates
   std::bitset<8> pos_x_1( (unsigned int) msg[15] );
   std::bitset<8> pos_x_2( (unsigned int) msg[16] );
   std::bitset<16> pos_x( pos_x_1.to_string() + pos_x_2.to_string() );
   CPPUNIT_ASSERT( pos_x.to_ullong() == 2572 );

   std::bitset<8> pos_y_1( (unsigned int) msg[17] );
   std::bitset<8> pos_y_2( (unsigned int) msg[18] );
   std::bitset<16> pos_y( pos_y_1.to_string() + pos_y_2.to_string() );
   CPPUNIT_ASSERT( pos_y.to_ullong() == 64871 );

   // I001/200 Calculated Track Velocity in polar Coordinates
   std::bitset<8> gsp_1( (unsigned int) msg[19] );
   std::bitset<8> gsp_2( (unsigned int) msg[20] );
   std::bitset<16> gsp( gsp_1.to_string() + gsp_2.to_string() );
   CPPUNIT_ASSERT( gsp.to_ullong() == 1963 );

   std::bitset<8> heading_1( (unsigned int) msg[21] );
   std::bitset<8> heading_2( (unsigned int) msg[22] );
   std::bitset<16> heading( heading_1.to_string() + heading_2.to_string() );
   CPPUNIT_ASSERT( heading.to_ullong() == 43036 );

   // I001/070 Mode-3/A Code in Octal Representation
   // Code 03456 not garbled but valid
   CPPUNIT_ASSERT( std::to_string( msg[23] ) == "7" );
   CPPUNIT_ASSERT( std::to_string( msg[24] ) == "46" );

   // I001/090 Mode-C Code in Binary Representation

   // code 01122 not valid but garbled
   std::bitset<8> mode_c( (unsigned int) msg[25] );
   CPPUNIT_ASSERT( mode_c[7] == true ); // not valid
   CPPUNIT_ASSERT( mode_c[6] == true ); // garbled
   CPPUNIT_ASSERT( std::to_string( msg[25] ) == "192" );
   CPPUNIT_ASSERT( std::to_string( msg[26] ) == "23" );

   // I001/141, Truncated Time of Day
   std::bitset<8> tod_1( (unsigned int) msg[27] );
   std::bitset<8> tod_2( (unsigned int) msg[28] );
   std::bitset<16> tod( tod_1.to_string() + tod_2.to_string() );
   std::cout << "CAT 001 TOD " << tod.to_ullong() << std::endl;
   CPPUNIT_ASSERT( tod.to_ullong() == 31744 );

   // I001/170, Track Status
   std::bitset<8> status_1( (unsigned int) msg[29] );
   std::bitset<8> status_2( (unsigned int) msg[30] );
   CPPUNIT_ASSERT( status_1.to_string() == "10100001" ); // CON, MAN, FX
   CPPUNIT_ASSERT( status_2.to_string() == "10000000" ); // TRE

   // I001/080 Mode-3/A Code Confidence Indicator
   std::bitset<8> mode_3a_conf_1( (unsigned int) msg[31] );
   std::bitset<8> mode_3a_conf_2( (unsigned int) msg[32] );
   std::bitset<16> mode_3a_conf( mode_3a_conf_1.to_string() + mode_3a_conf_2.to_string() );
   CPPUNIT_ASSERT( mode_3a_conf.to_ullong() == 573 );

   // I001/030 Warning/Error Conditions
   std::bitset<8> warn( (unsigned int) msg[33] );
   CPPUNIT_ASSERT( warn.to_ullong() == 112 ); // 56 shifted by one bit for the FX bit
}
