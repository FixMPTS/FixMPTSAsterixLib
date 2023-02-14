/**
 * @file TestAsterixCAT10Encoding.cpp
 * @author  Felix Kreuter <felix.kreuter@lordcentury.net>
 * @version 1.0
 * Created on: 6 Nov 2022
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * See .h file for more details
 */
#include "TestAsterixCAT10Encoding.h"
#include "AsterixCategory010.h"
#include "Cat010ItemNames.h"

#include <bitset>

void TestAsterixCAT10Encoding::setUp() {
   // nothing to do
}

void TestAsterixCAT10Encoding::tearDown() {
   // nothing to do
}

void TestAsterixCAT10Encoding::testCAT010MandatoryTargetReport() {
   AsterixCategory010 cat;
   TrackTypeIf track;
   ReportRecordType record;
   std::map<std::string, bool> items_to_be_served; // none set -> only mandatory items served

   // set up the data
   record.setSource( 90, 21 );
   record.setDetectionTimeFromTOD( 3210 );

   cat.setMessageType( 1 );
   cat.setTargetReportDescriptor( AsterixCategory010::TARGET_REPPORT_DESCRIPTOR::TYPE, 1 );
   cat.setTargetReportDescriptor( AsterixCategory010::TARGET_REPPORT_DESCRIPTOR::CHN, 1 );
   cat.setTargetReportDescriptor( AsterixCategory010::TARGET_REPPORT_DESCRIPTOR::TOT, 1 );

   std::vector<char> msg = cat.getEncodedMessage( track, record, items_to_be_served );
   CPPUNIT_ASSERT( msg.size() == 12 );

   CPPUNIT_ASSERT( std::to_string( msg[0] ) == "10" ); // Category

   CPPUNIT_ASSERT( std::to_string( msg[1] ) == "0" ); // length
   CPPUNIT_ASSERT( std::to_string( msg[2] ) == "12" ); // length

   // One fspec byte only
   std::bitset<8> fspec_byte_1( (unsigned int) msg[3] );
   CPPUNIT_ASSERT( fspec_byte_1.to_string() == "11110000" ); // first fspec byte

   // Check the mandatory items: 010, 000, 020, 140
   CPPUNIT_ASSERT( std::to_string( msg[4] ) == "90" ); // SAC
   CPPUNIT_ASSERT( std::to_string( msg[5] ) == "21" ); // SIC
   CPPUNIT_ASSERT( std::to_string( msg[6] ) == "1" ); // 000: Message type

   std::bitset<8> target_report_des_1( (unsigned int) msg[7] );
   std::bitset<8> target_report_des_2( (unsigned int) msg[8] );
   CPPUNIT_ASSERT( target_report_des_1.to_string() == "00101001" ); // TYPE and CHN and FX
   CPPUNIT_ASSERT( target_report_des_2.to_string() == "00000010" ); // TOT and no FX

   // I010/140 Time of day
   uint64_t tod = (unsigned char) msg[9];
   tod <<= 8;
   tod |= ((unsigned char) msg[10] & 0xff);
   tod <<= 8;
   tod |= ((unsigned char) msg[11] & 0xff);
   CPPUNIT_ASSERT( tod == 410880 ); // 3210 * 128 (LSB) = 410880
}

void TestAsterixCAT10Encoding::testCAT010MandatoryStartUpdatCycle() {
   AsterixCategory010 cat;
   TrackTypeIf track;
   ReportRecordType record;
   std::map<std::string, bool> items_to_be_served; // none set -> only mandatory items served

   // set up the data
   record.setSource( 90, 22 );
   record.setDetectionTimeFromTOD( 3211 );

   cat.setMessageType( 2 );
   // Will  not be delivered as it is not mandatory
   cat.setSystemStatus( 1, false, true, false, true );

   std::vector<char> msg = cat.getEncodedMessage( track, record, items_to_be_served );
   CPPUNIT_ASSERT( msg.size() == 10 );

   CPPUNIT_ASSERT( std::to_string( msg[0] ) == "10" ); // Category

   CPPUNIT_ASSERT( std::to_string( msg[1] ) == "0" ); // length
   CPPUNIT_ASSERT( std::to_string( msg[2] ) == "10" ); // length


   // One fspec byte only
   std::bitset<8> fspec_byte_1( (unsigned int) msg[3] );
   CPPUNIT_ASSERT( fspec_byte_1.to_string() == "11010000" ); // first fspec byte

   // Check the mandatory items: 010, 000, 020, 140
   CPPUNIT_ASSERT( std::to_string( msg[4] ) == "90" ); // SAC
   CPPUNIT_ASSERT( std::to_string( msg[5] ) == "22" ); // SIC
   CPPUNIT_ASSERT( std::to_string( msg[6] ) == "2" ); // 000: Message type

   // I010/140 Time of day
   uint64_t tod = (unsigned char) msg[7];
   tod <<= 8;
   tod |= ((unsigned char) msg[8] & 0xff);
   tod <<= 8;
   tod |= ((unsigned char) msg[9] & 0xff);
   CPPUNIT_ASSERT( tod == 411008 ); // 3211 * 128 (LSB) = 411008
}

void TestAsterixCAT10Encoding::testCAT010MandatoryPeriodicStatus() {
   AsterixCategory010 cat;
   TrackTypeIf track;
   ReportRecordType record;
   std::map<std::string, bool> items_to_be_served; // none set -> only mandatory items served

   // set up the data
   record.setSource( 90, 23 );
   record.setDetectionTimeFromTOD( 3212 );
   cat.setMessageType( 3 );
   cat.setSystemStatus( 1, false, true, false, true );

   std::vector<char> msg = cat.getEncodedMessage( track, record, items_to_be_served );
   std::cout << "MSG SIZE= " << msg.size() << std::endl;
   CPPUNIT_ASSERT( msg.size() == 13 );

   CPPUNIT_ASSERT( std::to_string( msg[0] ) == "10" ); // Category

   CPPUNIT_ASSERT( std::to_string( msg[1] ) == "0" ); // length
   CPPUNIT_ASSERT( std::to_string( msg[2] ) == "13" ); // length

   // Three fspec bytes
   std::bitset<8> fspec_byte_1( (unsigned int) msg[3] );
   std::bitset<8> fspec_byte_2( (unsigned int) msg[4] );
   std::bitset<8> fspec_byte_3( (unsigned int) msg[5] );
   CPPUNIT_ASSERT( fspec_byte_1.to_string() == "11010001" ); // first fspec byte
   CPPUNIT_ASSERT( fspec_byte_2.to_string() == "00000001" ); // second fspec byte
   CPPUNIT_ASSERT( fspec_byte_3.to_string() == "00000100" ); // third fspec byte

   CPPUNIT_ASSERT( std::to_string( msg[6] ) == "90" ); // SAC
   CPPUNIT_ASSERT( std::to_string( msg[7] ) == "23" ); // SIC
   CPPUNIT_ASSERT( std::to_string( msg[8] ) == "3" ); // 000: Message type
   // I010/140 Time of day
   uint64_t tod = (unsigned char) msg[9];
   tod <<= 8;
   tod |= ((unsigned char) msg[10] & 0xff);
   tod <<= 8;
   tod |= ((unsigned char) msg[11] & 0xff);
   CPPUNIT_ASSERT( tod == 411136 ); // 3212 * 128 (LSB) = 411136

   //I010/550, System Status
   std::bitset<8> system_status( (unsigned int) msg[12] );
   CPPUNIT_ASSERT( system_status.to_string() == "01010100" );
}
