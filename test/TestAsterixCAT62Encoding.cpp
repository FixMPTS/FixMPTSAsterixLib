/**
 * @file TestAsterixCAT62Encoding.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 13 May 2016
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
 * See description of the corresponding header file
 */

//local includes
#include "TestAsterixCAT62Encoding.h"
#include "TimeRelated.h"
#include "TrackDetectionAges.h"
#include "AircraftDerivedDataItemExtended.h"
#include "TrackTypeIf.h"
#include "MathConstants.h"
#include "Cat062ItemNames.h"

// global includes
#include <bitset>
#include <memory>
#include <cmath>

void TestAsterixCAT62Encoding::setUp() {
   // Define the detection ages
   max_ages = std::make_shared<AsterixItemMaxAges>();
   max_ages->setMaxAgePerType( DetectionEntry::DET_TYPE::ADS_B, 10.0 );
   max_ages->setMaxAgePerType( DetectionEntry::DET_TYPE::PSR, 10.0 );
   max_ages->setMaxAgePerType( DetectionEntry::DET_TYPE::SSR, 10.0 );
   max_ages->setMaxAgePerType( DetectionEntry::DET_TYPE::CMB, 10.0 );
   max_ages->setMaxAgePerType( DetectionEntry::DET_TYPE::MDS, 10.0 );
   max_ages->setMaxAgePerType( DetectionEntry::DET_TYPE::TRACK, 40.0 );
}

void TestAsterixCAT62Encoding::tearDown() {
}


void TestAsterixCAT62Encoding::testI062_010(){
   // Define an item selector which just contains the SDPS identification item. Note the mandatory
   // items will be included in the final message anyway.
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_010] = true;

   // Define as basic track although it is not directly needed for this special test case
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>();

   AsterixCategory062 cat_62_msg = AsterixCategory062();

   // Setup all items needed for the message encoding
   std::map<std::string, unsigned char> non_track_values;
   non_track_values[Cat062ItemNames::I062_010_SAC] = (unsigned char) 11;
   non_track_values[Cat062ItemNames::I062_010_SIC] = (unsigned char) 255;

   cat_62_msg.setNonTrackRelatedValues( non_track_values );
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Test the bytes of the message. Only CAT, length, FSPEC, and I062/010 are tested here
   CPPUNIT_ASSERT( std::to_string( msg[0] )=="62" ); // Category

   CPPUNIT_ASSERT( std::to_string( msg[1] )=="0" ); // length
   CPPUNIT_ASSERT( std::to_string( msg[2] )=="15" ); // length

   CPPUNIT_ASSERT( std::to_string( msg[5] )=="11" ); // SAC
   CPPUNIT_ASSERT( std::to_string( msg[6] )=="255" ); // SIC

   // Make sure the correct fpsec bit is set
   std::bitset<8>fspec_byte( (unsigned int) msg[3] );
   CPPUNIT_ASSERT (fspec_byte[7]); // first fspec bit

   //Test several values for SAC/SIC pairs
   std::vector<unsigned char> sac_sic_1 = AsterixEncodingHelper::encodeSACSIC16Bit( 0, 0 );
   CPPUNIT_ASSERT( std::to_string( sac_sic_1[0] )=="0" ); // SAC
   CPPUNIT_ASSERT( std::to_string( sac_sic_1[1] )=="0" ); // SIC

   std::vector<unsigned char> sac_sic_2 = AsterixEncodingHelper::encodeSACSIC16Bit( 255, 255 );
   CPPUNIT_ASSERT( std::to_string( sac_sic_2[0] )=="255" ); // SAC
   CPPUNIT_ASSERT( std::to_string( sac_sic_2[1] )=="255" ); // SIC

   std::vector<unsigned char> sac_sic_3 = AsterixEncodingHelper::encodeSACSIC16Bit( 200, 1 );
   CPPUNIT_ASSERT( std::to_string( sac_sic_3[0] )=="200" ); // SAC
   CPPUNIT_ASSERT( std::to_string( sac_sic_3[1] )=="1" ); // SIC
}

void TestAsterixCAT62Encoding::testI062_015(){

   // Define an item selector which just contains the SDPS identification item. Note the mandatory
   // items will be included in the final message anyway.
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_015] = true;

   // Define as basic track although it is not directly needed for this special test case
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>();
   AsterixCategory062 cat_62_msg = AsterixCategory062();

   // Setup all items needed for the message encoding
   std::map<std::string, unsigned char> non_track_values;
   non_track_values[Cat062ItemNames::I062_015] = (unsigned char) 0;

   cat_62_msg.setNonTrackRelatedValues( non_track_values );

   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Test the service id and fpsec
   CPPUNIT_ASSERT( std::to_string( msg[7] )=="0" ); // service id
   std::bitset<8>fspec_byte( (unsigned int) msg[3] );
   CPPUNIT_ASSERT (fspec_byte[5]); // first fspec bit

   non_track_values[Cat062ItemNames::I062_015] = (unsigned char) 255;
   cat_62_msg.setNonTrackRelatedValues( non_track_values );
   msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );
   CPPUNIT_ASSERT( std::to_string( msg[7] )=="255" ); // service id

   non_track_values[Cat062ItemNames::I062_015] = (unsigned char) 33;
   cat_62_msg.setNonTrackRelatedValues( non_track_values );
   msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );
   CPPUNIT_ASSERT( std::to_string( msg[7] )=="33" ); // service id
}

void TestAsterixCAT62Encoding::testI062_070(){
   // items will be included in the final message anyway.
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_070] = true;

   // Define the report to initiate the track from. By doing so the time can be influenced
   uint64_t test_time = getCurrentTimeMS();
   ReportRecordType report( test_time, 1, 1 );
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>( 1 );
   track->addDetection( report.getDetectionType() );
   track->setLastUpdateTime( report.getDetectionTime() );

   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   std::bitset<8>byte_1( (unsigned int) msg[8] );
   std::bitset<8>byte_2( (unsigned int) msg[9] );
   std::bitset<8>byte_3( (unsigned int) msg[10] );
   //Re-build the time
   std::bitset<24>encoded_time( byte_1.to_string()+byte_2.to_string()+byte_3.to_string() );

   CPPUNIT_ASSERT( (encoded_time.to_ulong() / 128) == convertToTimeSinceMidnightMS( test_time ) / 1000 );
   std::bitset<8>fspec_byte( (unsigned int) msg[3] );
   CPPUNIT_ASSERT (fspec_byte[4]); // fspec

   // Test the encoding function
   uint64_t time_1 = getCurrentTimeMS()+20000;
   std::vector<unsigned char> msg_time_1 = AsterixEncodingHelper::encodeTimeOfTrackInfo24Bit(
      time_1 );

   std::bitset<8>tst_1_byte_1( (unsigned int) msg_time_1[0] );
   std::bitset<8>tst_1_byte_2( (unsigned int) msg_time_1[1] );
   std::bitset<8>tst_1_byte_3( (unsigned int) msg_time_1[2] );
   std::bitset<24>test_1_encoded_time(
      tst_1_byte_1.to_string()+tst_1_byte_2.to_string()+tst_1_byte_3.to_string() );
   CPPUNIT_ASSERT(
      ( test_1_encoded_time.to_ulong()/128 )==convertToTimeSinceMidnightMS( time_1 )/1000 );
}

void TestAsterixCAT62Encoding::testI062_105(){
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_105] = true;
   double lsb = 180.0 / std::pow( 2.0, 25.0 );

   // Define the report to initiate the track from. By doing so the time can be influenced
   //PointXYZ position = PointXYZ( 4260805, 746637, 4673402 ); // Set position to Andelsbuch Austria
   PointXYZ position = PointXYZ( 47.21266, 9.93924, 6361726674.1 ); // Set position to Andelsbuch Austria (GEO)
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>( 2, position );

   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Make sure the FSPEC indicates the presence of this item
   std::bitset<8>fspec_byte( (unsigned int) msg[3] );
   CPPUNIT_ASSERT (fspec_byte[3]);

   // build the lat and lng sub items and convert them with the proper LSB
   std::bitset<8>lat_byte_1( (unsigned int) msg[11] );
   std::bitset<8>lat_byte_2( (unsigned int) msg[12] );
   std::bitset<8>lat_byte_3( (unsigned int) msg[13] );
   std::bitset<8>lat_byte_4( (unsigned int) msg[14] );
   std::bitset<32>encoded_lat(
      lat_byte_1.to_string()+lat_byte_2.to_string()+lat_byte_3.to_string()+lat_byte_4.to_string() );

   std::bitset<8>lng_byte_1( (unsigned int) msg[15] );
   std::bitset<8>lng_byte_2( (unsigned int) msg[16] );
   std::bitset<8>lng_byte_3( (unsigned int) msg[17] );
   std::bitset<8>lng_byte_4( (unsigned int) msg[18] );
   std::bitset<32>encoded_lng(
      lng_byte_1.to_string()+lng_byte_2.to_string()+lng_byte_3.to_string()+lng_byte_4.to_string() );

   double latitude = ( encoded_lat.to_ulong()*lsb );
   double longitude = ( encoded_lng.to_ulong()*lsb );
   // Allow for minor differences because of the LSB and float rounding
   CPPUNIT_ASSERT(// transformtogeo was present
      latitude>=position.getX()-0.1&&latitude<=position.getX()+0.1 );// lat
   CPPUNIT_ASSERT(
      longitude >= position.getY() - 0.1 && longitude <= position.getY() + 0.1 ); // lng

      //PointXYZ position_2 = PointXYZ( 4260805, -746637, -4673402 );
   PointXYZ position_2 = PointXYZ( -47.21266, 350.06076, 6361726674.1 );
   std::shared_ptr<TrackTypeIf> track_2 = std::make_shared<TrackTypeIf>( 3, position_2 );
   std::vector<unsigned char> wgs_pos_1 = AsterixEncodingHelper::encodePositionWG( track_2 );

   std::bitset<8>lat_2_byte_1( (unsigned int) wgs_pos_1[0] );
   std::bitset<8>lat_2_byte_2( (unsigned int) wgs_pos_1[1] );
   std::bitset<8>lat_2_byte_3( (unsigned int) wgs_pos_1[2] );
   std::bitset<8>lat_2_byte_4( (unsigned int) wgs_pos_1[3] );
   std::bitset<32>encoded_lat_2(
      lat_2_byte_1.to_string()+lat_2_byte_2.to_string()+lat_2_byte_3.to_string()+lat_2_byte_4.to_string() );

   std::bitset<8>lng_2_byte_1( (unsigned int) wgs_pos_1[4] );
   std::bitset<8>lng_2_byte_2( (unsigned int) wgs_pos_1[5] );
   std::bitset<8>lng_2_byte_3( (unsigned int) wgs_pos_1[6] );
   std::bitset<8>lng_2_byte_4( (unsigned int) wgs_pos_1[7] );
   std::bitset<32>encoded_lng_2(
      lng_2_byte_1.to_string()+lng_2_byte_2.to_string()+lng_2_byte_3.to_string()+lng_2_byte_4.to_string() );

   // negative lat/lng pair. COnvert back to signed with same data type size
   int32_t decoded_lat_bytes = static_cast<int32_t>( encoded_lat_2.to_ulong() );
   int32_t decoded_lng_bytes = static_cast<int32_t>( encoded_lng_2.to_ulong() );

   double decoded_lat = decoded_lat_bytes*lsb;
   double decoded_lng = decoded_lng_bytes*lsb;

   // transformtogeo was here
   CPPUNIT_ASSERT( decoded_lat >= position_2.getX() - 0.1 &&
      decoded_lat <= position_2.getX() + 0.1 );
   CPPUNIT_ASSERT( decoded_lng >= position_2.getY() - 0.1 &&
      decoded_lng <= position_2.getY() + 0.1 );
}

void TestAsterixCAT62Encoding::testI062_060(){
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_060] = true;

   // Define the report to initiate the track from. By doing so the time can be influenced
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>();
   track->setMode3A( 1000, true, false ); // Set the mode 3A code

   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Make sure the FSPEC indicates the presence of this item
   std::bitset<8>fspec_byte( (unsigned int) msg[4] );
   CPPUNIT_ASSERT (fspec_byte[6]);

   // Decimal Mode3A 1000 is 1750 octal. With the code being not garbled and valid the bytes are
   // expected to read 3 and 232
   CPPUNIT_ASSERT( std::to_string( msg[11] )=="3" );
   CPPUNIT_ASSERT( std::to_string( msg[12] )=="232" );

   // Test valid and garbled flags as well
   std::vector<unsigned char> encoded_code_1 = AsterixEncodingHelper::encodeTrackMode3A(
      1000, true, false );

   CPPUNIT_ASSERT( std::to_string( encoded_code_1[0] )=="3" );
   CPPUNIT_ASSERT( std::to_string( encoded_code_1[1] )=="232" );

   std::vector<unsigned char> encoded_code_2 = AsterixEncodingHelper::encodeTrackMode3A(
      1000, false, false );

   CPPUNIT_ASSERT( std::to_string( encoded_code_2[0] )=="131" );
   CPPUNIT_ASSERT( std::to_string( encoded_code_2[1] )=="232" );

   std::vector<unsigned char> encoded_code_3 = AsterixEncodingHelper::encodeTrackMode3A(
      1000, false, true );

   CPPUNIT_ASSERT( std::to_string( encoded_code_3[0] )=="195" );
   CPPUNIT_ASSERT( std::to_string( encoded_code_3[1] )=="232" );

   // Test one additional code with less than four digits
   std::vector<unsigned char> encoded_code_4 = AsterixEncodingHelper::encodeTrackMode3A(
      77, true, false );

   CPPUNIT_ASSERT( std::to_string( encoded_code_4[0] )=="0" );
   CPPUNIT_ASSERT( std::to_string( encoded_code_4[1] )=="77" ); // 115 digit of size 3 wise encoded is 77
}

void TestAsterixCAT62Encoding::testI062_040(){
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_040] = true;

   // Define the report to initiate the track from. By doing so the time can be influenced
   PointXYZ position = PointXYZ( 4059717, 608617, 4865251 ); // Set position to EDDF RWY 18
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>( 20, position );

   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Maker sure the fpsec is properly set
   std::bitset<8>fspec_byte( (unsigned int) msg[4] );
   CPPUNIT_ASSERT (fspec_byte[3]);

   // Check for the expected track number
   CPPUNIT_ASSERT( std::to_string( msg[11] )=="0" );
   CPPUNIT_ASSERT( std::to_string( msg[12] )=="20" );

   // Check some corner cases
   std::vector<unsigned char> track_number_1 = AsterixEncodingHelper::encodeTrackNumber16Bit( 0 );
   CPPUNIT_ASSERT( std::to_string( track_number_1[0] )=="0" );
   CPPUNIT_ASSERT( std::to_string( track_number_1[1] )=="0" );

   // Make sure that invalid track numbers are not encoded
   std::vector<unsigned char> track_number_2 = AsterixEncodingHelper::encodeTrackNumber16Bit(
      65536 );
   CPPUNIT_ASSERT( track_number_2.size()==0 );

   std::vector<unsigned char> track_number_3 = AsterixEncodingHelper::encodeTrackNumber16Bit(
      65535 );
   CPPUNIT_ASSERT( std::to_string( track_number_3[0] )=="255" );
   CPPUNIT_ASSERT( std::to_string( track_number_3[1] )=="255" );
}

void TestAsterixCAT62Encoding::testI062_080(){

   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_080] = true;

   // Define the report to initiate the track from. By doing so the time can be influenced
   uint64_t test_time = getCurrentTimeMS();
   ReportRecordType report( test_time, 2, 3 );
   report.setDetectionType( DetectionEntry::DET_TYPE::SSR );

   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>( 22 );
   DetectionEntry detection;
   detection.setDetectionType( report.getDetectionType() );
   //detection.setDetectionTime();
   track->addDetection( detection );
   track->setLastUpdateTime( report.getDetectionTime() );
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_SSR,
      (int) (getCurrentTimeMS() - report.getDetectionTime()) );

   AsterixCategory062 cat_62_msg = AsterixCategory062();

   // Set detection max ages for testing
   cat_62_msg.setServiceRelatedValue(
      Cat062ItemNames::I062_080_AGE + "_"
         + std::to_string( static_cast<int>( GenericEnumerations::AGE_ITEMS::DET_PSR ) ), "20.0" ); // seconds
   cat_62_msg.setServiceRelatedValue(
      Cat062ItemNames::I062_080_AGE+"_" + std::to_string( static_cast<int>( GenericEnumerations::AGE_ITEMS::DET_SSR ) ), "20.0" ); // seconds
   cat_62_msg.setServiceRelatedValue(
      Cat062ItemNames::I062_080_AGE + "_"
         + std::to_string( static_cast<int>( GenericEnumerations::AGE_ITEMS::DET_ADS_B ) ), "30.0" ); // seconds
   cat_62_msg.setServiceRelatedValue( Cat062ItemNames::I062_080_CNF, "0.8" );

   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );
   // Maker sure the fpsec is properly set
   std::bitset<8>fspec_byte( (unsigned int) msg[4] );
   CPPUNIT_ASSERT (fspec_byte[2]);

   // Check for the expected track number
   CPPUNIT_ASSERT( std::to_string( msg[13] )=="131" );
   CPPUNIT_ASSERT( std::to_string( msg[14] )=="1" ); // only FX bit set
   CPPUNIT_ASSERT( std::to_string( msg[15] )=="1" ); // only FX bit set
   CPPUNIT_ASSERT( std::to_string( msg[16] )=="88" ); // Just SSR detection

   // Check that although the track was updated by two reports, it is still marked as mono sensor track
   // because both reports where from the same sensor
   ReportRecordType report_1( test_time, 2, 4 );
   ReportRecordType report_1u( test_time, 2, 4 );
   report_1.setDetectionLink( DetectionEntry::DET_LINK::ADS_B_ES );
   report_1u.setDetectionType( DetectionEntry::DET_TYPE::PSR );
   DetectionEntry first_detection( DetectionEntry::DET_TYPE::ADS_B );
   first_detection.addContributingSensor( report_1.getSourceID() );
   DetectionEntry second_detection( DetectionEntry::DET_TYPE::PSR );
   second_detection.addContributingSensor( report_1u.getSourceID() );

   std::shared_ptr<TrackTypeIf> track_1 = std::make_shared<TrackTypeIf>( 23 );
   track_1->setLastUpdateTime( report.getDetectionTime() );
   track_1->addDetection( first_detection );
   track_1->addDetection( second_detection ); // still mono sensor track
   track_1->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_ADS_B,
      (int) (getCurrentTimeMS() - report.getDetectionTime()) );
   track_1->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_PSR,
      (int) (getCurrentTimeMS() - report.getDetectionTime()) );

   std::map<std::string, bool> track_live;
   track_live["TSB"] = true;
   double track_confirmation_weight = 0.7;

   std::vector<unsigned char> track_status_1 = AsterixEncodingHelper::encodeTrackStatus( track_1,
      track_confirmation_weight, max_ages, track_live );

   CPPUNIT_ASSERT( std::to_string( track_status_1[0] )=="131" ); // mono sensor
   CPPUNIT_ASSERT( std::to_string( track_status_1[1] )=="33" ); // TSB set,
   CPPUNIT_ASSERT( std::to_string( track_status_1[2] )=="1" ); // FX only
   CPPUNIT_ASSERT( std::to_string( track_status_1[3] )=="48" ); // PSR, ADS-B

   ReportRecordType report_2u( test_time, 2, 5 );
   DetectionEntry third_detection( DetectionEntry::DET_TYPE::PSR );
   third_detection.addContributingSensor( report.getSourceID() );
   report_2u.setDetectionType( DetectionEntry::DET_TYPE::PSR );
   track_1->addDetection( third_detection ); // make it a multi sensor track

   std::vector<unsigned char> track_status_1a = AsterixEncodingHelper::encodeTrackStatus(
      track_1, track_confirmation_weight, max_ages, track_live );

   // fails every now and then. Why???
   CPPUNIT_ASSERT( std::to_string( track_status_1a[0] )=="3" ); // multi sensor
   CPPUNIT_ASSERT( std::to_string( track_status_1a[1] )=="33" ); // TSB set,
   CPPUNIT_ASSERT( std::to_string( track_status_1a[2] )=="1" ); // FX only
   CPPUNIT_ASSERT( std::to_string( track_status_1a[3] )=="48" ); // PSR, ADS-B

   // use same track but reduce ADS_B max age so far as to have it removed from the track state
   max_ages->setMaxAgePerType( DetectionEntry::DET_TYPE::ADS_B, -0.001 );
   std::vector<unsigned char> track_status_2 = AsterixEncodingHelper::encodeTrackStatus( track_1,
      track_confirmation_weight, max_ages, track_live );

   CPPUNIT_ASSERT( std::to_string( track_status_2[0] )=="3" ); // multi sensor
   CPPUNIT_ASSERT( std::to_string( track_status_2[1] )=="33" ); // TSB set,
   CPPUNIT_ASSERT( std::to_string( track_status_2[2] )=="1" ); // FX only
   CPPUNIT_ASSERT( std::to_string( track_status_2[3] )=="56" ); //Only PSR left

   // Check termination and confirmed flags
   track_live["TSB"] = false;
   track_live["TSE"] = true;
   std::vector<unsigned char> track_status_3 = AsterixEncodingHelper::encodeTrackStatus( track_1, -0.01, max_ages,
      track_live );

   CPPUNIT_ASSERT( std::to_string( track_status_3[0] )=="1" ); // multi sensor and not confirmed
   CPPUNIT_ASSERT( std::to_string( track_status_3[1] )=="65" ); // Changed from TSB to TSE
   CPPUNIT_ASSERT( std::to_string( track_status_3[2] )=="1" ); // FX only
   CPPUNIT_ASSERT( std::to_string( track_status_3[3] )=="56" );
}

void TestAsterixCAT62Encoding::testI062_290(){

   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_290] = true;

   // Define the report to initiate the track from. By doing so the time can be influenced
   uint64_t test_time = getCurrentTimeMS()-2000; // Move the track into the past
   ReportRecordType report( test_time, 2, 3 );
   report.setDetectionType( DetectionEntry::DET_TYPE::CMB_MDS );

   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>( 32 );
   DetectionEntry first_detection( DetectionEntry::DET_TYPE::CMB_MDS );
   first_detection.addContributingSensor( report.getSourceID() );
   track->addDetection( first_detection );

   // Update the track with different reports where each report comes with another time stamp
   ReportRecordType report_u1( test_time+500, 2, 4 );
   ReportRecordType report_u2( test_time+1200, 2, 5 );
   report_u1.setDetectionType( DetectionEntry::DET_TYPE::CMB );
   report_u2.setDetectionType( DetectionEntry::DET_TYPE::MLAT );
   DetectionEntry second_detection( DetectionEntry::DET_TYPE::CMB );
   second_detection.addContributingSensor( report.getSourceID() );
   track->addDetection( second_detection );
   DetectionEntry third_detection( DetectionEntry::DET_TYPE::MLAT );
   third_detection.addContributingSensor( report_u2.getSourceID() );
   track->addDetection( third_detection );

   // Track age
   double track_age = ((getCurrentTimeMS() - report_u2.getDetectionTime()) / 1000.0);
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_TRACK, track_age );

   // DET_CMB_MDS
   double mds_age = ((getCurrentTimeMS() - test_time) / 1000.0);
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_PSR, mds_age );
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_SSR, mds_age );
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_MDS, mds_age );

   // CMB
   double cmb_age = ((getCurrentTimeMS() - report_u1.getDetectionTime()) / 1000.0);
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_PSR, cmb_age );
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_SSR, cmb_age );

   double mlat_time = ((getCurrentTimeMS() - report_u2.getDetectionTime()) / 1000.0);
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_MLAT, mlat_time );

   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Verify the message FSPEC is set correctly
   std::bitset<8>fspec_byte( (unsigned int) msg[4] );
   CPPUNIT_ASSERT (fspec_byte[1]);

   // verify the item sub fspec is as expected
   CPPUNIT_ASSERT( std::to_string( msg[17] )=="241" );
   CPPUNIT_ASSERT( std::to_string( msg[18] )=="32" );

   // Verify the ages of the track and the updating technologies are as expected, within the LSB
   CPPUNIT_ASSERT( std::to_string( msg[19] )=="3"||std::to_string( msg[19] )=="4" ); // Track age
   CPPUNIT_ASSERT( std::to_string( msg[20] )=="6"||std::to_string( msg[20] )=="7" ); // PSR age from CMB report
   CPPUNIT_ASSERT( std::to_string( msg[21] )=="6"||std::to_string( msg[21] )=="7" ); // SSR age from CMB report
   CPPUNIT_ASSERT( std::to_string( msg[22] )=="8"||std::to_string( msg[22] )=="9" ); // MDS age from CMB_MDS report
   CPPUNIT_ASSERT( std::to_string( msg[23] )=="3"||std::to_string( msg[23] )=="4" ); // MLAT age

   // Test the stand alone encoding
   // Same track as in the first test, but with updated ages more in the past than previous update => no change
   ReportRecordType report_u3( test_time, 2, 4 );
   report_u3.setDetectionType( DetectionEntry::DET_TYPE::CMB );
   DetectionEntry fith( DetectionEntry::DET_TYPE::CMB );
   track->addDetection( fith );
   double cmb_age_2 = ((getCurrentTimeMS() - report_u3.getDetectionTime()) / 1000.0);
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_CMB, cmb_age_2 );

   std::vector<unsigned char> track_ages_1 = AsterixEncodingHelper::encodeSystemTrackAges(
      track );
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[2] )=="3"||std::to_string( track_ages_1[2] )=="4" ); // Track age
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[3] )=="6"||std::to_string( track_ages_1[3] )=="7" ); // PSR age from CMB report
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[4] )=="6"||std::to_string( track_ages_1[4] )=="7" ); // SSR age from CMB report
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[5] )=="8"||std::to_string( track_ages_1[5] )=="9" ); // MDS age from CMB_MDS report
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[6] )=="3"||std::to_string( track_ages_1[6] )=="4" ); // MLAT age

   ReportRecordType report_u4( test_time-100, 2, 5 );
   report_u4.setDetectionType( DetectionEntry::DET_TYPE::PSR );
   track->addDetection( report_u4.getDetectionType() );
   track_ages_1 = AsterixEncodingHelper::encodeSystemTrackAges( track );

   // PSR age reduced because of recent update
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[2] )=="3"||std::to_string( track_ages_1[2] )=="4" ); // Track age
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[3] )=="5"||std::to_string( track_ages_1[3] )=="6" ); // PSR age from CMB report
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[4] )=="6"||std::to_string( track_ages_1[4] )=="7" ); // SSR age from CMB report
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[5] )=="8"||std::to_string( track_ages_1[5] )=="9" ); // MDS age from CMB_MDS report
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[6] )=="3"||std::to_string( track_ages_1[6] )=="4" ); // MLAT age

      // ADS-B link technology
   ReportRecordType report_u5( test_time, 2, 6 );
   report_u5.setDetectionType( DetectionEntry::DET_TYPE::ADS_B );
   report_u5.setDetectionLink( DetectionEntry::DET_LINK::ADS_B_ES );
   DetectionEntry seventh( DetectionEntry::DET_TYPE::ADS_B );
   seventh.addContributingSensor( report_u5.getSourceID() );
   double ads_time = ((getCurrentTimeMS() - test_time) / 1000.0);
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_ADS_B, ads_time );
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_ADS_B_ES, ads_time );
   track->addDetection( seventh );
   track_ages_1 = AsterixEncodingHelper::encodeSystemTrackAges( track );

   // Check the item sub fspec too because of added ADS-B update
   CPPUNIT_ASSERT( std::to_string( track_ages_1[0] )=="245" );
   CPPUNIT_ASSERT( std::to_string( track_ages_1[1] )=="32" );

   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[2] )=="3"||std::to_string( track_ages_1[2] )=="4" ); // Track age
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[3] )=="5"||std::to_string( track_ages_1[3] )=="6" ); // PSR age from CMB report
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[4] )=="6"||std::to_string( track_ages_1[4] )=="7" ); // SSR age from CMB report
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[5] )=="8"||std::to_string( track_ages_1[5] )=="9" ); // MDS age from CMB_MDS report
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[6] )=="8"||std::to_string( track_ages_1[6] )=="9" ); // ADS-B ESt
   CPPUNIT_ASSERT(
      std::to_string( track_ages_1[7] )=="3"||std::to_string( track_ages_1[7] )=="4" ); // MLAT age

}

void TestAsterixCAT62Encoding::testI062_200(){
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_200] = true;

   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>();
   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Verify the message FSPEC is set correctly
   std::bitset<8>fspec_byte( (unsigned int) msg[5] );
   CPPUNIT_ASSERT (fspec_byte[7]);

   // Everything set to default
   CPPUNIT_ASSERT( std::to_string( msg[16] )=="252" );

   //Set transversal MOF to right turn
   track->setTransversalMof( TrackTypeIf::TRACK_MOF::RIGHT_TURN );
   std::vector<unsigned char> mof_1 = AsterixEncodingHelper::encodeMOF8Bit( track );
   CPPUNIT_ASSERT( std::to_string( mof_1[0] )=="124" ); // Only right turn is set

   // Set to left turn and acceleration
   track->setTransversalMof( TrackTypeIf::TRACK_MOF::LEFT_TURN );
   track->setLongitudinalMof( TrackTypeIf::TRACK_MOF::ACCELERATION );
   std::vector<unsigned char> mof_2 = AsterixEncodingHelper::encodeMOF8Bit( track );
   CPPUNIT_ASSERT( std::to_string( mof_2[0] )=="156" );

   // Set to constant course, deceleration and climb
   track->setTransversalMof( TrackTypeIf::TRACK_MOF::CONSTANT_COURSE );
   track->setLongitudinalMof( TrackTypeIf::TRACK_MOF::DECELERATION );
   track->setVerticalMof( TrackTypeIf::TRACK_MOF::CLIMB );
   std::vector<unsigned char> mof_3 = AsterixEncodingHelper::encodeMOF8Bit( track );
   CPPUNIT_ASSERT( std::to_string( mof_3[0] )=="36" );

   // Set to constant course, constant ground speed and level flight
   track->setLongitudinalMof( TrackTypeIf::TRACK_MOF::CONSTANT_GDSP );
   track->setVerticalMof( TrackTypeIf::TRACK_MOF::LEVEL );
   std::vector<unsigned char> mof_4 = AsterixEncodingHelper::encodeMOF8Bit( track );
   CPPUNIT_ASSERT( std::to_string( mof_4[0] )=="0" );

   // Now only change vertical mode to descent
   track->setVerticalMof( TrackTypeIf::TRACK_MOF::DESCENT );
   std::vector<unsigned char> mof_5 = AsterixEncodingHelper::encodeMOF8Bit( track );
   CPPUNIT_ASSERT( std::to_string( mof_5[0] )=="8" );
}

void TestAsterixCAT62Encoding::testI062_295(){
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_295] = true;

   // Get starting time in past
   uint64_t test_time = getCurrentTimeMS()-3000;

   // Set the Emitter Category Age to 2 so at least have one entry to be encoded
   ReportRecordType report_1( test_time, 5, 15 );
   report_1.setDetectionType( DetectionEntry::DET_TYPE::ADS_B );
   report_1.setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::EMC, "2" );
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>( 40 );

   DetectionEntry first_detection( DetectionEntry::DET_TYPE::ADS_B );
   first_detection.addContributingSensor( report_1.getSourceID() );
   track->addDetection( first_detection );
   double ads_time = ((getCurrentTimeMS() - test_time) / 1000.0);
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_ADS_B, ads_time );
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DAP_EMC, ads_time );

   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Maker sure the fpsec is properly set
   std::bitset<8>fspec_byte( (unsigned int) msg[5] );
   CPPUNIT_ASSERT (fspec_byte[6]);

   // Check for the item fspec
   CPPUNIT_ASSERT( std::to_string( msg[18] )=="1" ); // only FX bit set
   CPPUNIT_ASSERT( std::to_string( msg[19] )=="1" ); // only FX bit set
   CPPUNIT_ASSERT( std::to_string( msg[20] )=="1" ); // only FX bit set
   CPPUNIT_ASSERT( std::to_string( msg[21] )=="32" ); // Just EMC is set

   // Test the EMC age
   CPPUNIT_ASSERT( std::to_string( msg[22] )=="12" ); // Just EMC is set

   // Test COM ( Communications / ACAS
   ReportRecordType report_2( test_time-2500, 5, 15 );
   report_2.setDetectionType( DetectionEntry::DET_TYPE::ADS_B );
   report_2.setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::COM, "1" );
   DetectionEntry second_detection( DetectionEntry::DET_TYPE::ADS_B );
   second_detection.addContributingSensor( report_2.getSourceID() );
   track->addDetection( second_detection );

   double ads_time_2 = ((getCurrentTimeMS() - report_2.getDetectionTime()) / 1000.0);
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_ADS_B, ads_time_2 );
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DAP_COM, ads_time_2 );

   std::vector<unsigned char> add_ages_1 = AsterixEncodingHelper::encodeTrackDataAges( track );

   // Test the item internal fpsec for prsence of the EMC and COM data ages
   CPPUNIT_ASSERT( std::to_string( add_ages_1[0] )=="1" );
   CPPUNIT_ASSERT( std::to_string( add_ages_1[1] )=="5" );
   CPPUNIT_ASSERT( std::to_string( add_ages_1[2] )=="1" );
   CPPUNIT_ASSERT( std::to_string( add_ages_1[3] )=="32" );

   // TEst the presence of the COM and EMC item. Allowe for one LSB difference
   // The age is 5.5s. This is the initial 3 seconds plus an additional 2.5 seconds
   CPPUNIT_ASSERT( std::to_string( add_ages_1[4] )=="22"||std::to_string( add_ages_1[4] )=="23" );
   CPPUNIT_ASSERT( std::to_string( add_ages_1[5] )=="12"||std::to_string( add_ages_1[5] )=="13" );

   // Test MHG
   ReportRecordType report_3( test_time-2300, 5, 15 );
   report_3.setDetectionType( DetectionEntry::DET_TYPE::ADS_B );
   report_3.setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MHG, "1" );

   DetectionEntry third_detection( DetectionEntry::DET_TYPE::ADS_B );
   third_detection.addContributingSensor( report_3.getSourceID() );
   track->addDetection( third_detection );

   double ads_time_3 = ((getCurrentTimeMS() - report_3.getDetectionTime()) / 1000.0);
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DET_ADS_B, ads_time_3 );
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DAP_MHG, ads_time_3 );

   std::vector<unsigned char> add_ages_2 = AsterixEncodingHelper::encodeTrackDataAges( track );

   // Test the item internal FPSEC for presence of EMC, COM and MHG items
   CPPUNIT_ASSERT( std::to_string( add_ages_2[0] )=="3" ); // MHG present
   CPPUNIT_ASSERT( std::to_string( add_ages_2[1] )=="5" ); // COM present
   CPPUNIT_ASSERT( std::to_string( add_ages_2[2] )=="1" );
   CPPUNIT_ASSERT( std::to_string( add_ages_2[3] )=="32" ); // EMC present

   // The age of the MHG item is 5.3. This is the original 3 seconds plus an additional 2.3 seconds
   CPPUNIT_ASSERT( std::to_string( add_ages_2[4] )=="21"||std::to_string( add_ages_2[4] )=="22" );
   CPPUNIT_ASSERT( std::to_string( add_ages_2[5] )=="22"||std::to_string( add_ages_2[5] )=="23" );
   CPPUNIT_ASSERT( std::to_string( add_ages_2[6] )=="12"||std::to_string( add_ages_2[6] )=="13" );

   // Test EMC again. But this time with an age even more in the past. No change of the age is expected
   ReportRecordType report_4( test_time-500, 5, 15 );
   report_4.setDetectionType( DetectionEntry::DET_TYPE::ADS_B );
   report_4.setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::EMC, "1" );

   DetectionEntry fourth_detection( DetectionEntry::DET_TYPE::ADS_B );
   fourth_detection.addContributingSensor( report_4.getSourceID() );
   track->addDetection( fourth_detection );

   // No age update since it would be older than the existing one
   std::vector<unsigned char> add_ages_3 = AsterixEncodingHelper::encodeTrackDataAges( track );

   // Test the item internal fpsec. It should not have changed since the previous test since no new
   // item was added
   CPPUNIT_ASSERT( std::to_string( add_ages_3[0] )=="3" ); // MHG present
   CPPUNIT_ASSERT( std::to_string( add_ages_3[1] )=="5" ); // COM present
   CPPUNIT_ASSERT( std::to_string( add_ages_3[2] )=="1" );
   CPPUNIT_ASSERT( std::to_string( add_ages_3[3] )=="32" ); // EMC present

   // Due to the EMC update even more in the past then the original one, nothing is changed for the
   // ages as well.
   CPPUNIT_ASSERT( std::to_string( add_ages_3[4] )=="21"||std::to_string( add_ages_3[4] )=="22" );
   CPPUNIT_ASSERT( std::to_string( add_ages_3[5] )=="22"||std::to_string( add_ages_3[5] )=="23" );
   CPPUNIT_ASSERT( std::to_string( add_ages_3[6] )=="12"||std::to_string( add_ages_3[6] )=="13" );

   // Test IAS
   ReportRecordType report_5( test_time-1000, 5, 15 );
   report_5.setDetectionType( DetectionEntry::DET_TYPE::ADS_B );
   report_5.setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::IAS, "0" );
   track->addDetection( report_5.getDetectionType() );

   double ads_time_4 = ((getCurrentTimeMS() - report_5.getDetectionTime()) / 1000.0);
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DAP_IAS, ads_time_4 );
   std::vector<unsigned char> add_ages_4 = AsterixEncodingHelper::encodeTrackDataAges( track );

   // Test the item internal fpsec for additional presence of the IAS item
   CPPUNIT_ASSERT( std::to_string( add_ages_4[0] )=="3" ); // MHG present
   CPPUNIT_ASSERT( std::to_string( add_ages_4[1] )=="133" ); // IAS and COM present
   CPPUNIT_ASSERT( std::to_string( add_ages_4[2] )=="1" );
   CPPUNIT_ASSERT( std::to_string( add_ages_4[3] )=="32" ); // EMC present

   // Verify the ages are encoded as expewcted
   CPPUNIT_ASSERT( std::to_string( add_ages_4[4] )=="21"||std::to_string( add_ages_4[4] )=="22" );
   // check the IAS age. It should be 4 seconds.
   CPPUNIT_ASSERT( std::to_string( add_ages_4[5] )=="16"||std::to_string( add_ages_4[5] )=="17" );
   CPPUNIT_ASSERT( std::to_string( add_ages_4[6] )=="22"||std::to_string( add_ages_4[6] )=="23" );
   CPPUNIT_ASSERT( std::to_string( add_ages_4[7] )=="12"||std::to_string( add_ages_4[7] )=="13" );

   // Test BVR
   ReportRecordType report_6( test_time-2000, 5, 15 );
   report_6.setDetectionType( DetectionEntry::DET_TYPE::ADS_B );
   report_6.setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::BVR, "5" );
   track->addDetection( report_6.getDetectionType() );

   double ads_time_5 = ((getCurrentTimeMS() - report_6.getDetectionTime()) / 1000.0);
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DAP_BVR, ads_time_5 );
   std::vector<unsigned char> add_ages_5 = AsterixEncodingHelper::encodeTrackDataAges( track );

   // The the additional presence of the BVR item in te item internal fspec
   CPPUNIT_ASSERT( std::to_string( add_ages_5[0] )=="3" ); // MHG present
   CPPUNIT_ASSERT( std::to_string( add_ages_5[1] )=="133" ); // COM present
   CPPUNIT_ASSERT( std::to_string( add_ages_5[2] )=="65" ); // BVR and FX
   CPPUNIT_ASSERT( std::to_string( add_ages_5[3] )=="32" ); // EMC present

   // Nothing has changed for the existing items
   CPPUNIT_ASSERT( std::to_string( add_ages_5[4] )=="21"||std::to_string( add_ages_5[4] )=="22" );
   CPPUNIT_ASSERT( std::to_string( add_ages_5[5] )=="16"||std::to_string( add_ages_5[5] )=="17" );
   CPPUNIT_ASSERT( std::to_string( add_ages_5[6] )=="22"||std::to_string( add_ages_5[6] )=="23" );
   // The expected BVR age is 5 seconds
   CPPUNIT_ASSERT( std::to_string( add_ages_5[7] )=="20"||std::to_string( add_ages_5[7] )=="21" );
   CPPUNIT_ASSERT( std::to_string( add_ages_5[8] )=="12"||std::to_string( add_ages_5[8] )=="13" );
}

void TestAsterixCAT62Encoding::testI062_136(){
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_136] = true;

   // Get starting time in past
   uint64_t test_time = getCurrentTimeMS();

   // Initiate the track with a report with positional information (range, azim, mode c)
   ReportRecordType report_1( test_time, 5, 30 );
   report_1.setDetectionType( DetectionEntry::DET_TYPE::SSR );
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>( 60 );
   DetectionEntry first_detection( DetectionEntry::DET_TYPE::SSR );
   first_detection.addContributingSensor( report_1.getSourceID() );
   track->addDetection( first_detection );
   track->setModeC( 400, true, false );

   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Maker sure the fpsec is properly set
   std::bitset<8>fspec_byte( (unsigned int) msg[5] );
   CPPUNIT_ASSERT (fspec_byte[5]);

   // Test for FL 10
   CPPUNIT_ASSERT( std::to_string( msg[18] )=="1" );
   CPPUNIT_ASSERT( std::to_string( msg[19] )=="144" );

   // Test the encoding function directly
   track->setModeC( 1360, true, false ); // FL 340
   std::vector<unsigned char> baro_alt_1 =
      AsterixEncodingHelper::encodeBaroAltitude( (track->getModeC()->getCode() * 25) / 100, -1 ); // was getModeCFL

   CPPUNIT_ASSERT( std::to_string( baro_alt_1[0] )=="5" );
   CPPUNIT_ASSERT( std::to_string( baro_alt_1[1] )=="80" );

   // Test negative flight level
   track->setModeC( -40, true, false ); // FL -10
   std::vector<unsigned char> baro_alt_2 =
      AsterixEncodingHelper::encodeBaroAltitude( (track->getModeC()->getCode() * 25) / 100, -1 );

   CPPUNIT_ASSERT( std::to_string( baro_alt_2[0] )=="255" );
   CPPUNIT_ASSERT( std::to_string( baro_alt_2[1] )=="216" );
}

void TestAsterixCAT62Encoding::testI062_130(){
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_130] = true;

   // Get starting time in past
   uint64_t test_time = getCurrentTimeMS();

   // Initiate the track with a report with positional information (range, azim)
   ReportRecordType report_1( test_time, 5, 30 );
   report_1.setDetectionType( DetectionEntry::DET_TYPE::SSR );
   report_1.setRadarPosition( 45.791999, 6.219124, 200.0 ); // Camping Campéole La Nublière
   report_1.setRangeAzimuth( 30.0, 90.0 );
   report_1.setBaroHeight( 1000.0 );
   //report_1.transformPosCoordinatesToWorld3D();
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>( 50 );
   DetectionEntry first_detection( DetectionEntry::DET_TYPE::SSR );
   first_detection.addContributingSensor( report_1.getSourceID() );
   track->addDetection( first_detection );

   track->setGeoPosition( 0, 0, 443 );

   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Maker sure the fpsec is properly set
   std::bitset<8>fspec_byte( (unsigned int) msg[5] );
   CPPUNIT_ASSERT (fspec_byte[4]);

   // Set track position directly via the track constructor. The not LSB corrected value is 232.462
   // which is 1 for the first and 8 for the second byte
   CPPUNIT_ASSERT( std::to_string( msg[18] ) == "0" );
   CPPUNIT_ASSERT( std::to_string( msg[19] ) == "232" );

   // Set the position for the track directly to a height of 11000 meter
   std::shared_ptr<TrackTypeIf> track_1 =
      std::make_shared<TrackTypeIf>( 51, PointXYZ( 20.8, -12.3, 11000 ) );
   std::vector<unsigned char> geometric_alt_1 = AsterixEncodingHelper::encodeGeoAltitude( track_1 );

   CPPUNIT_ASSERT( std::to_string( geometric_alt_1[0] )=="22" );
   CPPUNIT_ASSERT( std::to_string( geometric_alt_1[1] )=="142" );

   // Test negative altitude as well
   std::shared_ptr<TrackTypeIf> track_2 =
      std::make_shared<TrackTypeIf>( 51, PointXYZ( 20.8, -12.3, -400 ) );
   std::vector<unsigned char> geometric_alt_2 = AsterixEncodingHelper::encodeGeoAltitude( track_2 );

   CPPUNIT_ASSERT( geometric_alt_2.size()==2 );
   CPPUNIT_ASSERT( std::to_string( geometric_alt_2[0] )=="255" );
   CPPUNIT_ASSERT( std::to_string( geometric_alt_2[1] )=="47" );

   // Altitude autside the range will not be encoded
   std::shared_ptr<TrackTypeIf> track_3 =
      std::make_shared<TrackTypeIf>( 51, PointXYZ( 20.8, -12.3, -500 ) );
   std::vector<unsigned char> geometric_alt_3 = AsterixEncodingHelper::encodeGeoAltitude( track_3 );
   CPPUNIT_ASSERT( geometric_alt_3.size()==0 );

}

void TestAsterixCAT62Encoding::testI062_135(){
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_135] = true;

   // Get starting time in past
   uint64_t test_time = getCurrentTimeMS();

   // Initiate the track with a report with positional information (range, azimuth, baro altitude)
   ReportRecordType report_1( test_time, 5, 30 );
   report_1.setDetectionType( DetectionEntry::DET_TYPE::SSR );
   report_1.setBaroHeight( 200.0 ); // in FL
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>( 60 );
   DetectionEntry first_detection( DetectionEntry::DET_TYPE::SSR );
   first_detection.addContributingSensor( report_1.getSourceID() );
   track->addDetection( first_detection );
   track->setBaroAltitude( report_1.getBarometricHeight() );

   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Maker sure the fpsec is properly set
   std::bitset<8>fspec_byte( (unsigned int) msg[5] );
   CPPUNIT_ASSERT (fspec_byte[3]);

   // FL 200 is 800 encoded which is 3 and 32 in binary
   CPPUNIT_ASSERT( std::to_string( msg[18] )=="3" );
   CPPUNIT_ASSERT( std::to_string( msg[19] )=="32" );

   // Test the stand alone encoding
   track->setBaroAltitude( 450 );
   std::vector<unsigned char> baro_alt =
      AsterixEncodingHelper::encodeBaroAltitude( track->getBaroAltitude() );

   CPPUNIT_ASSERT( std::to_string( baro_alt[0] )=="7" );
   CPPUNIT_ASSERT( std::to_string( baro_alt[1] )=="8" );

   // Test maximum value
   track->setBaroAltitude( 1500 );
   std::vector<unsigned char> baro_alt_2 =
      AsterixEncodingHelper::encodeBaroAltitude( track->getBaroAltitude() );

   CPPUNIT_ASSERT( std::to_string( baro_alt_2[0] )=="23" );
   CPPUNIT_ASSERT( std::to_string( baro_alt_2[1] )=="112" );

   // Test negative value
   track->setBaroAltitude( -15 );
   std::vector<unsigned char> baro_alt_3 =
      AsterixEncodingHelper::encodeBaroAltitude( track->getBaroAltitude() );

   CPPUNIT_ASSERT( std::to_string( baro_alt_3[0] )=="255" );
   CPPUNIT_ASSERT( std::to_string( baro_alt_3[1] )=="196" );

}

void TestAsterixCAT62Encoding::testI062_220(){
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_220] = true;

   // Get starting time in past
   uint64_t test_time = getCurrentTimeMS();

   // Initiate the track with a report
   ReportRecordType report_1( test_time, 5, 30 );
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>( 70 );
   track->addDetection( report_1.getDetectionType() );

   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Maker sure the fpsec is properly set
   std::bitset<8> fspec_byte( (unsigned int) msg[5] );
   CPPUNIT_ASSERT (fspec_byte[2]);

   // C/D of 0 because only one report present
   CPPUNIT_ASSERT( std::to_string( msg[18] )=="0" );
   CPPUNIT_ASSERT( std::to_string( msg[19] )=="0" );

   track->setRateOfCD( 3000.0 );
   std::vector<unsigned char> rate_cd_1 =
      AsterixEncodingHelper::encodeRateCD( track->getRateOfCD() );

   CPPUNIT_ASSERT( std::to_string( rate_cd_1[0] )=="73" );
   CPPUNIT_ASSERT( std::to_string( rate_cd_1[1] )=="62" );

   // Test descent
   track->setRateOfCD( -2300.0 );
   std::vector<unsigned char> rate_cd_2 = AsterixEncodingHelper::encodeRateCD( track->getRateOfCD() );

   CPPUNIT_ASSERT( std::to_string( rate_cd_2[0] )=="199" );
   CPPUNIT_ASSERT( std::to_string( rate_cd_2[1] )=="217" );

   // Test huge values
   track->setRateOfCD( 8000.0 );
   std::vector<unsigned char> rate_cd_3 = AsterixEncodingHelper::encodeRateCD( track->getRateOfCD() );

   CPPUNIT_ASSERT( std::to_string( rate_cd_3[0] )=="195" );
   CPPUNIT_ASSERT( std::to_string( rate_cd_3[1] )=="80" );

   track->setRateOfCD( -15500.0 );
   std::vector<unsigned char> rate_cd_4 = AsterixEncodingHelper::encodeRateCD( track->getRateOfCD() );

   CPPUNIT_ASSERT( std::to_string( rate_cd_4[0] )=="133" );
   CPPUNIT_ASSERT( std::to_string( rate_cd_4[1] )=="149" );
}

void TestAsterixCAT62Encoding::testI062_340(){
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_340] = true;

   // Get starting time in past
   uint64_t test_time = getCurrentTimeMS();

   // Initiate the track with a report
   ReportRecordType report_1( test_time, 23, 1 );
   report_1.setDetectionType( DetectionEntry::DET_TYPE::PSR );
   report_1.setRangeAzimuth( 80.0, 110.0 );
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>( 80 );
   DetectionEntry first_detection( DetectionEntry::DET_TYPE::PSR );
   first_detection.addContributingSensor( report_1.getSourceID() );
   first_detection.setMeasurement( PointXYZ( 80.0, 110.0, std::numeric_limits<double>::infinity() ) );
   track->addDetection( first_detection );

   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Maker sure the fpsec is properly set
   std::bitset<8> fspec_byte( (unsigned int) msg[6] );
   CPPUNIT_ASSERT( fspec_byte[1] );

   // Test the item internal fspec
   CPPUNIT_ASSERT( std::to_string( msg[19] )=="196" );

   // Test SAC/SIC
   CPPUNIT_ASSERT( std::to_string( msg[20] )=="23" );
   CPPUNIT_ASSERT( std::to_string( msg[21] )=="1" );

   // Rho. 80NM * 265 is 80 00
   CPPUNIT_ASSERT( std::to_string( msg[22] )=="80" );
   CPPUNIT_ASSERT( std::to_string( msg[23] )=="0" );

   // Theta. 110 deg is 78 32
   CPPUNIT_ASSERT( std::to_string( msg[24] )=="78" );
   CPPUNIT_ASSERT( std::to_string( msg[25] )=="32" );

   // Type
   CPPUNIT_ASSERT( std::to_string( msg[26] )=="32" );

   // Test of the stand alone encoding function with an additional measured M3A and MC
   ReportRecordType report_2( test_time, 24, 2 );
   report_2.setDetectionType( DetectionEntry::DET_TYPE::MDS );
   report_2.setMode3A( 2000 );
   report_2.setModeC( 3456 );
   DetectionEntry second_detection( DetectionEntry::DET_TYPE::MDS );
   second_detection.addContributingSensor( report_2.getSourceID() );
   second_detection.setMode3A( DetectionEntry::ModeX( 2000, true, false ) );
   second_detection.setModeC( DetectionEntry::ModeX( 3456, true, false ) );
   track->addDetection( second_detection );

   std::vector<unsigned char> measured_info_1 = AsterixEncodingHelper::encodeMeasuredItems( track );

   // Item internal FPSEC
   CPPUNIT_ASSERT( std::to_string( measured_info_1[0] )=="220" );

   // SAC/SIC now 24/2
   CPPUNIT_ASSERT( std::to_string( measured_info_1[1] )=="24" );
   CPPUNIT_ASSERT( std::to_string( measured_info_1[2] )=="2" );

   // Test MC is 3456
   CPPUNIT_ASSERT( std::to_string( measured_info_1[7] )=="13" );
   CPPUNIT_ASSERT( std::to_string( measured_info_1[8] )=="128" );

   // Test the Mode 3A is 2000
   CPPUNIT_ASSERT( std::to_string( measured_info_1[9] )=="7" );
   CPPUNIT_ASSERT( std::to_string( measured_info_1[10] )=="208" );

   // Test type is single Mode S call
   CPPUNIT_ASSERT( std::to_string( measured_info_1[11] )=="128" );
}

void TestAsterixCAT62Encoding::testI062_380(){
   std::map<std::string, bool> items_to_be_served;
   items_to_be_served[Cat062ItemNames::I062_380] = true;

   // Get starting time in past
   uint64_t test_time = getCurrentTimeMS();

   // Initiate the track with a report
   ReportRecordType report_1( test_time, 23, 1 );
   report_1.setDetectionType( DetectionEntry::DET_TYPE::ADS_B );
   // Set The magnetic heading DAP
   report_1.setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MHG, "89.1" );
   std::shared_ptr<TrackTypeIf> track = std::make_shared<TrackTypeIf>( 80 );
   DetectionEntry first_detection( DetectionEntry::DET_TYPE::ADS_B );
   first_detection.addContributingSensor( report_1.getSourceID() );
   track->addDetection( first_detection );

   double dap_time = ((getCurrentTimeMS() - test_time) / 1000.0);
   track->setDetectionAgeFor( GenericEnumerations::AGE_ITEMS::DAP_MHG, dap_time );
   track->addADItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MHG,
      std::make_shared<AircraftDerivedDataItemExtended>( "", "89.1",
         AircraftDerivedDataItemBase::VALUE_TYPES::DOUBLE ) );

   AsterixCategory062 cat_62_msg = AsterixCategory062();
   std::vector<unsigned char> msg = cat_62_msg.getEncodedMessage( track, items_to_be_served, max_ages );

   // Maker sure the fpsec is properly set
   std::bitset<8>fspec_byte( (unsigned int) msg[3] );
   CPPUNIT_ASSERT (fspec_byte[4]);

   // Verify the item sub FSPEC is set properly
   CPPUNIT_ASSERT( std::to_string( msg[11] )=="32" );

   // Verify the value for the MHG item expected 16200 which is 89.1 without the LSB
   CPPUNIT_ASSERT( std::to_string( msg[12] )=="63" );
   CPPUNIT_ASSERT( std::to_string( msg[13] )=="72" );

   // Test the stand alone encoding function

   // Test the COM item
   ReportRecordType report_2( test_time, 23, 1 );
   report_2.setDetectionType( DetectionEntry::DET_TYPE::ADS_B );
   // Set the communication DAP
   report_2.setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::COM, "3" );
   track->addADItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::COM,
      std::make_shared<AircraftDerivedDataItemExtended>( "", "3",
         AircraftDerivedDataItemBase::VALUE_TYPES::NUMBER ) );
   track->addDetection( report_2.getDetectionType() );

   std::vector<unsigned char> add_data_1 =
      AsterixEncodingHelper::eoncodeAircraftDerivedData( track );

   // Test the now two sub item fspec bytes
   CPPUNIT_ASSERT( std::to_string( add_data_1[0] )=="33" ); // FX bit set
   CPPUNIT_ASSERT( std::to_string( add_data_1[1] )=="32" );

   // Verify the MHG is still set and in addition the COM is set to three but the rest of that
   // byte is set to zero
   CPPUNIT_ASSERT( std::to_string( add_data_1[2] )=="63" ); // MHG
   CPPUNIT_ASSERT( std::to_string( add_data_1[3] )=="72" ); // MHG
   CPPUNIT_ASSERT( std::to_string( add_data_1[4] )=="96" ); // COM
   CPPUNIT_ASSERT( std::to_string( add_data_1[5] )=="0" ); // STAT

   // Test the GSP item
   ReportRecordType report_3( test_time, 23, 1 );
   report_3.setDetectionType( DetectionEntry::DET_TYPE::ADS_B );
   // Set the Ground Speed DAP
   report_3.setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::GSP, "-1.2" );
   track->addADItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::GSP,
      std::make_shared<AircraftDerivedDataItemExtended>( "", "-1.2",
         AircraftDerivedDataItemBase::VALUE_TYPES::DOUBLE ) );
   track->addDetection( report_3.getDetectionType() );

   std::vector<unsigned char> add_data_2 =
      AsterixEncodingHelper::eoncodeAircraftDerivedData( track );

   // Test the item sub fspec
   CPPUNIT_ASSERT( std::to_string( add_data_2[0] )=="33" ); // FX bit set
   CPPUNIT_ASSERT( std::to_string( add_data_2[1] )=="33" ); // FX bit set
   CPPUNIT_ASSERT( std::to_string( add_data_2[2] )=="16" );

   // Test the previously existing DAP items are still there
   CPPUNIT_ASSERT( std::to_string( add_data_2[3] )=="63" ); // MHG
   CPPUNIT_ASSERT( std::to_string( add_data_2[4] )=="72" ); // MHG
   CPPUNIT_ASSERT( std::to_string( add_data_2[5] )=="96" ); // COM
   CPPUNIT_ASSERT( std::to_string( add_data_2[6] )=="0" ); // STAT

   // Test the new GSP item
   CPPUNIT_ASSERT( std::to_string( add_data_2[7] )=="255" ); // negative GSP
   CPPUNIT_ASSERT( std::to_string( add_data_2[8] )=="251" ); // GSP -1.1 (less than an LSB away from -1.2)

   // Test the POS item
   ReportRecordType report_4( test_time, 23, 1 );
   report_4.setDetectionType( DetectionEntry::DET_TYPE::ADS_B );
   // Set the communication DAP
   report_4.setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::POS, "32.41, -10.8" );
   std::shared_ptr<AircraftDerivedDataItemExtended> pos_add = std::make_shared<AircraftDerivedDataItemExtended>( "",
      "0", AircraftDerivedDataItemBase::VALUE_TYPES::DOUBLE );
   pos_add->updateItem( "32.41, -10.8", test_time );
   track->addADItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::POS, pos_add );
   track->addDetection( report_4.getDetectionType() );
   std::vector<unsigned char> add_data_3 =
      AsterixEncodingHelper::eoncodeAircraftDerivedData( track );

   // Verify the sub item FSPEc
   CPPUNIT_ASSERT( std::to_string( add_data_3[0] )=="33" ); // FX bit set
   CPPUNIT_ASSERT( std::to_string( add_data_3[1] )=="33" ); // FX bit set
   CPPUNIT_ASSERT( std::to_string( add_data_3[2] )=="17" ); // FX bit set
   CPPUNIT_ASSERT( std::to_string( add_data_3[3] )=="128" );

   // Ensure the position is set correctly
   CPPUNIT_ASSERT( std::to_string( add_data_3[10] )=="23" ); // LAT
   CPPUNIT_ASSERT( std::to_string( add_data_3[11] )=="12" ); // LAT
   CPPUNIT_ASSERT( std::to_string( add_data_3[12] )=="15" ); // LAT

   CPPUNIT_ASSERT( std::to_string( add_data_3[13] )=="248" ); // LNG
   CPPUNIT_ASSERT( std::to_string( add_data_3[14] )=="81" ); // LNG
   CPPUNIT_ASSERT( std::to_string( add_data_3[15] )=="236" ); // LNG

   // Test EMC
   ReportRecordType report_5( test_time, 23, 1 );
   report_5.setDetectionType( DetectionEntry::DET_TYPE::ADS_B );
   // Set the communication DAP
   report_5.setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::EMC, "5" );
   track->addDetection( report_5.getDetectionType() );
   track->addADItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::EMC,
      std::make_shared<AircraftDerivedDataItemExtended>( "", "5",
         AircraftDerivedDataItemBase::VALUE_TYPES::NUMBER ) );
   std::vector<unsigned char> add_data_4 =
      AsterixEncodingHelper::eoncodeAircraftDerivedData( track );

   // Test the sub item FSPEC
   CPPUNIT_ASSERT( std::to_string( add_data_2[0] )=="33" ); // FX bit set
   CPPUNIT_ASSERT( std::to_string( add_data_4[1] )=="33" ); // FX bit set
   CPPUNIT_ASSERT( std::to_string( add_data_4[2] )=="19" ); // EMC plus FX bit set
   CPPUNIT_ASSERT( std::to_string( add_data_4[3] )=="128" );

   // Verify the EMC is set to 5
   CPPUNIT_ASSERT( std::to_string( add_data_4[10] )=="5" );
}
