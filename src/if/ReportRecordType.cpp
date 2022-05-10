/**
 * @file ReportRecordType.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
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

#include "ReportRecordType.h"
#include "MathConstants.h"
//#include "../Core/Math/CoordinateTransformations.h"

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    Internal Structs     ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
ReportRecordType::source_id::source_id( int sac, int sic ) :
   sensor_sac( sac ), sensor_sic( sic ) {
}
ReportRecordType::source_id::source_id() :
   sensor_sac( 0 ), sensor_sic( 0 ) {
}

ReportRecordType::geo_position::geo_position( double lat, double lng, bool l_l_present,
   bool elev_present, double elev ) :
   latitude( lat ), longitude( lng ), lat_lng_present( l_l_present ), elevation( elev ), elevation_present(
      elev_present ) {
}
ReportRecordType::geo_position::geo_position() :
   latitude( 0.0 ), longitude( 0.0 ), lat_lng_present( false ), elevation( 0.0 ), elevation_present(
      false ) {
}

ReportRecordType::rng_azim::rng_azim( double r, double a, bool p ) :
   range( r ), azimuth( a ), rng_azim_present( p ) {
}
ReportRecordType::rng_azim::rng_azim() :
   range( 0.0 ), azimuth( 0.0 ), rng_azim_present( false ) {
}

ReportRecordType::baro_geo_height::baro_geo_height( double baro_alt, bool baro_alt_present,
   double geo_h, bool geo_h_present ) :
   baro_altitude( baro_alt ), baro_altitude_present( baro_alt_present ), geo_height( geo_h ), geo_height_present(
      geo_h_present ) {
}

ReportRecordType::double_t::double_t( double v, bool p ) :
   value( v ), value_present( p ) {
}
ReportRecordType::double_t::double_t() :
   value( 0.0 ), value_present( false ) {
}

ReportRecordType::mode_3aC::mode_3aC( int code, bool g, bool v, bool p ) :
   code( code ), garbled( g ), valid( v ), present( p ) {
}
ReportRecordType::mode_3aC::mode_3aC() :
   code( 0 ), garbled( false ), valid( false ), present( false ) {
}

ReportRecordType::aircraft_id::aircraft_id( std::string id, bool present ) {
   snprintf( ac_id, 9, "        " ); // Default
   ac_id[8] = '\0'; // add explicitly the null character
   if( id.length() > 8 ) {
      ac_id_present = false;
      //ac_id = "";
      //LogManager logger = LogManager( "RecordType" );
      //logger.debug( "ReportRecordType: Aircraft ID exceeds max number of allowed characters." );
   } else {
      ac_id_present = present;
      snprintf( ac_id, 9, id.c_str() );
   }
}
ReportRecordType::aircraft_id::aircraft_id() :
   ac_id_present( false ) {
}

ReportRecordType::aircraft_address::aircraft_address( unsigned long ac_address, bool present ) :
   address( ac_address ), address_present( present ) {
}
ReportRecordType::aircraft_address::aircraft_address() :
   address( 0 ), address_present( false ) {
}

ReportRecordType::local_track_number::local_track_number( int nr, bool present ) :
   l_track_nr( nr ), l_track_nr_present( present ) {
}
ReportRecordType::local_track_number::local_track_number() :
   l_track_nr( 0 ), l_track_nr_present( false ) {
}

ReportRecordType::configured_acc::configured_acc() :
   range_acc( 0.0 ), azimuth_acc( 0.0 ) {
}

ReportRecordType::add_data::add_data() :
   item_name( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::NONE_ADD ), item_present( false ) {
}
ReportRecordType::add_data::add_data( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES i,
   std::string v ) :
   item_name( i ), item_present( true ) {
   v.copy( value, 20, 0 );
}
std::string ReportRecordType::add_data::getValue() {
   return std::string( &value[0] );
}
GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES ReportRecordType::add_data::getItemID() {
   return item_name;
}

bool ReportRecordType::add_data::isItemPresent() {
   return item_present;
}
void ReportRecordType::add_data::setItemValue( std::string v ) {
   v.copy( value, MAX_ADD_ITEM_LENGTH, 0 );
}
void ReportRecordType::add_data::setPresense( bool p ) {
   item_present = p;
}

ReportRecordType::report_record::report_record() {
   det_time = 0;
   source = source_id();
   geo_pos = geo_position();
   heading = double_t();
   ground_speed = double_t();
   range_azimuth = rng_azim();
   height = baro_geo_height();
   mc = mode_3aC();
   meas_3D_height = double_t();
   m3a = mode_3aC();
   aircraft_ident = aircraft_id();
   icao_address = aircraft_address();
   local_trk_no = local_track_number();
   detection_type = DetectionEntry::DET_TYPE::NONE;
   link = DetectionEntry::DET_LINK::NO_LINK;
   configured_accuracies = configured_acc();
   //aircraft_derived_data = std::vector<add_data>();
   radar_pos = geo_position();
}

void ReportRecordType::report_record::updateADDItem(
   GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item,
   std::string value, bool present = true ) {
   // Update the value of the given item. In case the item is not yet contained in the store,
   // it will be added
   bool found = false;
   for( auto &i : aircraft_derived_data ) {
      if( i.getItemID() == item ) {
         found = true;
         i.setItemValue( value );
         //std::cout<<" REPORT set DAP "<<value<<std::endl;
         i.setPresense( present );
         break;
      }
   }
   if( !found ) {
      // add the item
      aircraft_derived_data.push_back( add_data( item, value ) );
   }
}
std::string ReportRecordType::report_record::getADDItemValue(
   GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item ) {
   for( auto i : aircraft_derived_data ) {
      if( i.getItemID() == item ) {
         return i.getValue();
      }
   }
   throw ElementNotFound( "ReportRecordType::getADDItemValue", std::to_string( static_cast<int>( item ) ) );
}
ReportRecordType::add_data ReportRecordType::report_record::getADDItem(
   GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item ) {
   for( auto i : aircraft_derived_data ) {
      if( i.getItemID() == item ) {
         return i;
      }
   }
   return add_data();
}

ReportRecordType::report_record_resp_t::report_record_resp_t() :
   hash( 0 ), rank( -1 ) {
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    ReportRecordType     ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
ReportRecordType::ReportRecordType( uint64_t det_time, int sac, int sic ) :
   ReportRecordType(){
   current_record.source.sensor_sac = sac;
   current_record.source.sensor_sic = sic;

   current_record.det_time = det_time;

   //preset all other items to not present
   current_record.geo_pos.elevation_present = false;
   current_record.geo_pos.lat_lng_present = false;
   current_record.range_azimuth.rng_azim_present = false;
   current_record.height.baro_altitude_present = false;
   current_record.height.geo_height_present = false;
   current_record.meas_3D_height.value_present = false;
   current_record.m3a.present = false;
   current_record.aircraft_ident.ac_id_present = false;
   current_record.icao_address.address_present = false;
   current_record.local_trk_no.l_track_nr_present = false;
   empty_report = false;
}

ReportRecordType::ReportRecordType() {
   current_record = report_record();
   empty_report = true;
   position_in_world_coordinates = PointXYZ();
   current_record.detection_type = DetectionEntry::DET_TYPE::NONE;
   current_record.link = DetectionEntry::DET_LINK::NO_LINK;

   detTypeMapping =
      std::map<DetectionEntry::DET_TYPE, std::string>( { { DetectionEntry::DET_TYPE::PSR, "PSR" },
         { DetectionEntry::DET_TYPE::SSR, "SSR" }, { DetectionEntry::DET_TYPE::CMB, "CMB" },
         { DetectionEntry::DET_TYPE::MDS, "MDS" }, { DetectionEntry::DET_TYPE::CMB_MDS, "CMB_MDS" },
         { DetectionEntry::DET_TYPE::ADS_B, "ADS_B" }, { DetectionEntry::DET_TYPE::ADS_C, "ADS_C" },
         { DetectionEntry::DET_TYPE::MLAT, "MLAT" }, { DetectionEntry::DET_TYPE::TRACK, "TRACK" },
         { DetectionEntry::DET_TYPE::NONE, "NONE" } } );
}

ReportRecordType::ReportRecordType( const ReportRecordType& other_report ) :
   ReportRecordType() {
   current_record.aircraft_derived_data = other_report.current_record.aircraft_derived_data;
   current_record.aircraft_ident = other_report.current_record.aircraft_ident;
   current_record.configured_accuracies = other_report.current_record.configured_accuracies;
   current_record.det_time = other_report.current_record.det_time;
   current_record.detection_type = other_report.current_record.detection_type;
   current_record.link = other_report.current_record.link;
   current_record.geo_pos = other_report.current_record.geo_pos;
   current_record.ground_speed = other_report.current_record.ground_speed;
   current_record.heading = other_report.current_record.heading;
   current_record.height = other_report.current_record.height;
   current_record.mc = other_report.current_record.mc;
   current_record.meas_3D_height = other_report.current_record.meas_3D_height;
   current_record.icao_address = other_report.current_record.icao_address;
   current_record.local_trk_no = other_report.current_record.local_trk_no;
   current_record.m3a = other_report.current_record.m3a;
   current_record.radar_pos = other_report.current_record.radar_pos;
   current_record.range_azimuth = other_report.current_record.range_azimuth;
   current_record.source = other_report.current_record.source;

   //Set position
   position_in_world_coordinates = other_report.position_in_world_coordinates;

   currently_reponsible_process = other_report.currently_reponsible_process;

   // copy the hash as well if present
   if( other_report.report_hash != 0 ) {
      report_hash = other_report.report_hash;
   }

   empty_report = other_report.empty_report;

}

ReportRecordType::ReportRecordType(const ReportRecord_T& other_record) :
   ReportRecordType() {
   current_record = other_record;
   empty_report = false;
}

ReportRecordType::~ReportRecordType() {
   //   delete current_record;
}

void ReportRecordType::setReportHash( std::size_t h ) {
   report_hash = h;
}
void ReportRecordType::setSource( int sac, int sic ) {
   current_record.source.sensor_sac = sac;
   current_record.source.sensor_sic = sic;
}
void ReportRecordType::setGeoPosLatLng( double lat, double lng, bool lat_lng_present ) {
   current_record.geo_pos.latitude = lat;
   current_record.geo_pos.longitude = lng;
   current_record.geo_pos.lat_lng_present = lat_lng_present;

   // This might have an influence on the world position
   //transformPosCoordinatesToWorld3D( true );
}
void ReportRecordType::setGeoPosElevation( double elev, bool elev_present ) {
   current_record.geo_pos.elevation = elev;
   current_record.geo_pos.elevation_present = elev_present;

   // This might have an influence on the world position
   //transformPosCoordinatesToWorld3D( true );
}
void ReportRecordType::setHeading( double h, bool p ) {
   current_record.heading.value = h;
   current_record.heading.value_present = p;
}
void ReportRecordType::setGroundSpeed( double s, bool p ) {
   current_record.ground_speed.value = s;
   current_record.ground_speed.value_present = p;
}
void ReportRecordType::setRangeAzimuth( double range, double azim, bool present ) {
   current_record.range_azimuth.range = range;
   current_record.range_azimuth.azimuth = azim;
   current_record.range_azimuth.rng_azim_present = present;
}
void ReportRecordType::setBaroHeight( double height, bool present ) {
   current_record.height.baro_altitude = height;
   current_record.height.baro_altitude_present = present;

   // This might have an influence on the world position
   //transformPosCoordinatesToWorld3D( true );
}
void ReportRecordType::setGeoHeight(double height, bool present) {
   current_record.height.geo_height = height;
   current_record.height.geo_height_present = present;

   // This might have an influence on the world position
   //transformPosCoordinatesToWorld3D( true );
}
void ReportRecordType::setMode3A( int code, bool present, bool garbled, bool valid ) {
   if( code < 00000 || code > 07777 ) {
      current_record.m3a.code = 00000;
      current_record.m3a.present = false;
   } else {
      current_record.m3a.code = code;
      current_record.m3a.garbled = garbled;
      current_record.m3a.valid = valid;
      current_record.m3a.present = present;
   }
}
void ReportRecordType::setMode2(int code, bool present, bool garbled, bool valid) {
   if( code < 00000 || code > 07777 ) {
      current_record.mode2.code = 00000;
      current_record.mode2.present = false;
   } else {
      current_record.mode2.code = code;
      current_record.mode2.garbled = garbled;
      current_record.mode2.valid = valid;
      current_record.mode2.present = present;
   }
}
void ReportRecordType::setModeC( int code, bool present, bool garbled, bool valid ) {
   if( code < 00000 || code > 07777 ) {
      current_record.mc.code = 00000;
      current_record.mc.present = false;
   } else {
      current_record.mc.code = code;
      current_record.mc.garbled = garbled;
      current_record.mc.valid = valid;
      current_record.mc.present = present;
   }
}
void ReportRecordType::setAircraftIdent( std::string id, bool present ) {
   //if( id.length() > 8 )
   //   current_record->airccraft_ident = aircraft_id( id, false );
   //else
   current_record.aircraft_ident = aircraft_id( id, present );
}
void ReportRecordType::setAircraftAddress( unsigned long address, bool present ) {
   if( address < 0x000000 || address > 0xffffff ) {
      current_record.icao_address = aircraft_address();
   } else {
      current_record.icao_address = aircraft_address( address, present );
   }
}
void ReportRecordType::setLocalTrackNumber( int number, bool present ) {
   current_record.local_trk_no = local_track_number( number, present );
}
void ReportRecordType::setDetectionType(DetectionEntry::DET_TYPE detection) {
   current_record.detection_type = detection;
}
void ReportRecordType::setDetectionLink(DetectionEntry::DET_LINK l) {
   current_record.link = l;
}
void ReportRecordType::setRadarPosition( double lat, double lng, double elev, bool p ) {
   current_record.radar_pos.latitude = lat;
   current_record.radar_pos.longitude = lng;
   current_record.radar_pos.lat_lng_present = p;
   current_record.radar_pos.elevation = elev;
   current_record.radar_pos.elevation_present = p;
}

void ReportRecordType::setDetectionTimePoint( std::chrono::system_clock::time_point t ) {
   current_record.det_time =
      std::chrono::duration_cast<std::chrono::milliseconds>( t.time_since_epoch() ).count();
}

void ReportRecordType::setDetectionTimeFromTOD( uint64_t tod ) {
   //transform time since midnight to time_point in ms
   time_t now = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
   tm *midnight = std::gmtime( &now );
   midnight->tm_hour = 0;
   midnight->tm_min = 0;
   midnight->tm_sec = 0;
   std::chrono::system_clock::time_point d_time = std::chrono::system_clock::from_time_t(
      std::mktime( midnight ) );

   if( d_time - std::chrono::system_clock::now() > std::chrono::hours( 23 ) ) {
      // the measurement is from yesterday
      d_time -= std::chrono::hours( 24 );
   }
   current_record.det_time = std::chrono::duration_cast<std::chrono::milliseconds>( d_time.time_since_epoch() ).count();
   current_record.det_time = tod;   // TODO removed +=
}

void ReportRecordType::setRecord( ReportRecord_T& record ) {
   current_record = record;
}

void ReportRecordType::setResponsibleRank( int rank ) {
   currently_reponsible_process.rank = rank;
   currently_reponsible_process.hash = getReportHash();
}

void ReportRecordType::setEmpty( bool empty ) {
   empty_report = empty;
}

void ReportRecordType::setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item,
   std::string value ) {
   current_record.updateADDItem( item, value );
}

/*void ReportRecordType::transformPosCoordinatesToWorld3D( bool force ) {
   //Convert only if not done or forced to do so
 if( !force && !(position_in_world_coordinates == PointXYZ()) ) {
      return;
   }

   //The report was received with lat/lng instead of range/azim
   Point3D radar_position = Point3D(
      current_record.radar_pos.latitude,
      current_record.radar_pos.longitude,
      current_record.radar_pos.elevation,
      Point3D::COORD_TYPE::GEO ).transformToECEF();

   //For the GEO position just a transformation to ECEF is required. No shift whatsoever, since
   //the geo position is already a global one.
   if( current_record.geo_pos.lat_lng_present ) {

      double height = 0.0;
      // This if defines the order of importance for the altitude
      if( current_record.geo_pos.elevation_present ) {
         height = current_record.geo_pos.elevation;
      } else if( current_record.height.baro_altitude_present ) {
         height = current_record.height.baro_altitude * FEET_TO_METER_FACTOR;
      } else if( current_record.height.geo_height_present ) {
         height = current_record.height.geo_height;
      }
      position_in_world_coordinates = Point3D( current_record.geo_pos.latitude, current_record.geo_pos.longitude,
         height, Point3D::COORD_TYPE::GEO ).transformToECEF();
   }
   else if( current_record.range_azimuth.rng_azim_present ) {
      double const range_in_m = current_record.range_azimuth.range * NM_TO_METER_FACTOR;
      double altitude =
         current_record.height.baro_altitude_present ? current_record.height.baro_altitude : 0.0;

      position_in_world_coordinates = CoordinateTransformations::RangeAzimElev2ECEF(
         radar_position, Point3D( range_in_m, current_record.range_azimuth.azimuth, altitude ) );
   }
 }*/

std::size_t ReportRecordType::getReportHash(){

   if( report_hash == 0 ) {
      std::string value = "";
      value += std::to_string( current_record.source.sensor_sac );
      value += std::to_string( current_record.source.sensor_sic );
      value += std::to_string( current_record.m3a.code );
      value += std::to_string( current_record.radar_pos.latitude );
      value += std::to_string( current_record.radar_pos.longitude );
      value += std::to_string( current_record.range_azimuth.range );
      value += std::to_string( current_record.range_azimuth.azimuth );
      value += std::to_string( static_cast<int>( current_record.detection_type ) );

      std::hash < std::string > return_hash;
      report_hash = return_hash( value );
   }
   return report_hash;
}

std::tuple<int, int> ReportRecordType::getSourceID() const {
   return std::make_tuple( current_record.source.sensor_sac,
      current_record.source.sensor_sic );
}
uint64_t ReportRecordType::getDetectionTime() const {
   return current_record.det_time;
}
uint64_t ReportRecordType::getDetectionTimeUTC() const {
   return convertTODtoUTC( current_record.det_time );
}
std::tuple<double, double> ReportRecordType::getGeoPos() {
   return std::make_tuple( current_record.geo_pos.latitude, current_record.geo_pos.longitude );
}
double ReportRecordType::getHeading() {
   return current_record.heading.value;
}
double ReportRecordType::getGroundSpeed() {
   return current_record.ground_speed.value;
}
double ReportRecordType::getElevation() {
   return current_record.geo_pos.elevation;
}
std::tuple<double, double> ReportRecordType::getRangeAzimuth() {
   return std::make_tuple( current_record.range_azimuth.range,
      current_record.range_azimuth.azimuth );
}
double ReportRecordType::getBarometricHeight() {
   return current_record.height.baro_altitude;
}
double ReportRecordType::getGeometricHeight() {
   return current_record.height.geo_height;
}
double ReportRecordType::get3DHeight() {
   return current_record.meas_3D_height.value;
}
int ReportRecordType::getModeCCode() {
   return current_record.mc.code;
}
int ReportRecordType::getMode3ACode() {
   return current_record.m3a.code;
}
int ReportRecordType::getMode2Code() {
   return current_record.mode2.code;
}
std::string ReportRecordType::getAircraftIdent() {
   return std::string( current_record.aircraft_ident.ac_id );
}
unsigned long ReportRecordType::getAircraftAddress() {
   return current_record.icao_address.address;
}
int ReportRecordType::getLocalTrackNumber() {
   return current_record.local_trk_no.l_track_nr;
}
DetectionEntry::DET_TYPE ReportRecordType::getDetectionType() {
   return current_record.detection_type;
}
DetectionEntry::DET_LINK ReportRecordType::getDetectionLink() {
   return current_record.link;
}
ReportRecordType::geo_position ReportRecordType::getRadarPosition() {
   return current_record.radar_pos;
}
bool ReportRecordType::getSPI() {
   add_data spi = current_record.getADDItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES::SPI );
   return spi.isItemPresent() && spi.getValue() == "1";
}
std::string ReportRecordType::getDAP(
   GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item_name ) {
   return std::string( current_record.getADDItem( item_name ).value );
}

ReportRecordType::ReportRecord_T& ReportRecordType::getRecordBufferAccess() {
   return current_record;
}

/*Point3D ReportRecordType::getWorldPosition() {
   if( position_in_world_coordinates == Point3D() ) {
      transformPosCoordinatesToWorld3D();
   }

   return position_in_world_coordinates;
 }*/
int ReportRecordType::getRank() {
   return currently_reponsible_process.rank;
}
ReportRecordType::ReportRecordResponsible_T ReportRecordType::getResponsibleRecord() {
   return currently_reponsible_process;
}

bool ReportRecordType::isGeoPosPresent() {
   return current_record.geo_pos.lat_lng_present;
}
bool ReportRecordType::isHeadingPresent() {
   return current_record.heading.value_present;
}
bool ReportRecordType::isGroundSpeedPresent() {
   return current_record.ground_speed.value_present;
}
bool ReportRecordType::isEleveationPresent() {
   return current_record.geo_pos.elevation_present;
}
bool ReportRecordType::isRangeAzimuthPresent() {
   return current_record.range_azimuth.rng_azim_present;
}
bool ReportRecordType::isBarometricHeightPresent() {
   return current_record.height.baro_altitude_present;
}
bool ReportRecordType::isModeCPresent() {
   return current_record.mc.present;
}
bool ReportRecordType::isModeCValid() {
   return current_record.mc.valid;
}
bool ReportRecordType::isModeCGarbled() {
   return current_record.mc.garbled;
}
bool ReportRecordType::isGeometricHeightPresent() {
   return current_record.height.geo_height_present;
}
bool ReportRecordType::isMode3APresent() {
   return current_record.m3a.present;
}
bool ReportRecordType::isMode3AValidNotGarbled() {
   return current_record.m3a.valid && !current_record.m3a.garbled;
}
bool ReportRecordType::isMode3AValid() {
   return current_record.m3a.valid;
}
bool ReportRecordType::isMode3AGarbled() {
   return current_record.m3a.garbled;
}
bool ReportRecordType::isMode2Present() {
   return current_record.mode2.present;
}
bool ReportRecordType::isMode2ValidNotGarbled() {
   return current_record.mode2.valid && !current_record.m3a.garbled;
}
bool ReportRecordType::isMode2Valid() {
   return current_record.mode2.valid;
}
bool ReportRecordType::isMode2Garbled() {
   return current_record.mode2.garbled;
}
bool ReportRecordType::isAircraftIdentPresent() {
   return current_record.aircraft_ident.ac_id_present;
}
bool ReportRecordType::isAircraftAddressPresent() {
   return current_record.icao_address.address_present;
}
bool ReportRecordType::isAircraftDerivedItemPresent(
   GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item_name ) {
   return current_record.getADDItem( item_name ).isItemPresent();
}
bool ReportRecordType::isLocalTrackNumberPresent() {
   return current_record.local_trk_no.l_track_nr_present;
}
bool ReportRecordType::isEmptyReport() {
   return empty_report;
}
bool ReportRecordType::is3DHeightPresent() {
   return current_record.meas_3D_height.value_present;
}

std::string ReportRecordType::getDetectionStringFromEnum(DetectionEntry::DET_TYPE d) {
   switch( d ){
      case DetectionEntry::DET_TYPE::PSR: {
         return "PSR";
      }
      case DetectionEntry::DET_TYPE::SSR: {
         return "SSR";
      }
      case DetectionEntry::DET_TYPE::CMB: {
         return "CMB";
      }
      case DetectionEntry::DET_TYPE::MDS: {
         return "MDS";
      }
      case DetectionEntry::DET_TYPE::CMB_MDS: {
         return "CMB_MDS";
      }
      case DetectionEntry::DET_TYPE::ADS_B: {
         return "ADS_B";
      }
      case DetectionEntry::DET_TYPE::ADS_C: {
         return "ADS_C";
      }
      case DetectionEntry::DET_TYPE::MLAT: {
         return "MLAT";
      }
      case DetectionEntry::DET_TYPE::TRACK: {
         return "TRACK";
      }
      case DetectionEntry::DET_TYPE::NONE: {
         // No set yet
         break;
      }
   }
   return "PSR";
}

std::string ReportRecordType::detTypeToString(DetectionEntry::DET_TYPE det_type) {
   return detTypeMapping.at( det_type );
}

std::map<DetectionEntry::DET_TYPE, std::string>::iterator ReportRecordType::detAgeIterBegin() {
   return detTypeMapping.begin();
}
std::map<DetectionEntry::DET_TYPE, std::string>::iterator ReportRecordType::detAgeIterEnd() {
   return detTypeMapping.end();
}
