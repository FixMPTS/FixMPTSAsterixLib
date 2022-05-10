/**
 * @file ReportRecordType.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 *
 ** @section LICENSE
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
 * This class represents the CPP type for the incoming measurement report. It contains all necessary
 * getter and setter methods, along with a present flag per not mandatory item. If applicable metric
 * units shall be used as arguments.
 */

#ifndef REPORTRECORDTYPE_H_
#define REPORTRECORDTYPE_H_

#include "PointXYZ.h"
#include "TimeRelated.h"
#include "GeneralEnumerations.h"
#include "Constants.h"
#include "Exceptions.h"
#include "DetectionEntry.h"

//global includes
#include <chrono>
#include <ctime>
#include <string>
#include <tuple>
#include <vector>
#include <cstdint>
#include <iostream>
#include <functional>

class ReportRecordType {
public:
   static std::string getDetectionStringFromEnum(DetectionEntry::DET_TYPE d);

protected:
   //Detection time of the measurement retrieved from the sensor
   std::chrono::time_point<std::chrono::system_clock, std::chrono::microseconds> detection_time;

   // SAC/SIC of the sensor from which the detection is received
   struct source_id {
      int sensor_sac;
      int sensor_sic;
      source_id( int sac, int sic );
      source_id();
   };

   //Position of the measurement in lat/long/elev. The position needs to be converted to WGS84 from
   //the actual measurement in the input modules. This is to have the conversion at a place where
   //everything like the system centre, sensor position is known. In order to determine if the
   //elevation was measured a presence flag is present.
   struct geo_position {
      double latitude;
      double longitude;
      bool lat_lng_present;
      double elevation;
      bool elevation_present;

      geo_position( double lat, double lng, bool l_l_present, bool elev_present = false,
         double elev = 0 );
      geo_position();
   };

   //Range azimuth measurement, if sensor is capable of such measurement
   struct rng_azim {
      double range;
      double azimuth;
      bool rng_azim_present;
      rng_azim( double r, double a, bool p );
      rng_azim();
   };

   //The measured barometric and/or geometric height. To determine the which height was actually
   // measured, this structure comes with presence flags for its entries.
   //DO WE NEED THE GARBLED FLAG HERE????
   struct baro_geo_height {
      double baro_altitude; // in feet
      bool baro_altitude_present;
      double geo_height; // in meters
      bool geo_height_present;
      baro_geo_height( double baro_alt = 0.0, bool baro_alt_present = false, double geo_h = 0.0,
         bool geo_h_present = false );
   };

   //Generic type to represent a double value with corresponding presence flag
   struct double_t {
      double value;
      bool value_present;

      double_t( double v, bool p = false );
      double_t();
   };

   //The mode 3a/c code with corresponding flags
   struct mode_3aC {
      int code;
      bool garbled;
      bool valid;
      bool present;
      mode_3aC( int code, bool g, bool v, bool p = false );
      mode_3aC();
   };

   //The call sign as received for example by mode-s
   struct aircraft_id {
      char ac_id[9]; // one additional character for the 0 termination
      bool ac_id_present;
      aircraft_id( std::string id, bool present = false );
      aircraft_id();
   };

   //The 24 ICAO aircraft address
   struct aircraft_address {
      unsigned long address;
      bool address_present;
      aircraft_address( unsigned long ac_address, bool present = false );
      aircraft_address();
   };

   //The track number of the local tracker on sensor side
   struct local_track_number {
      int l_track_nr;
      bool l_track_nr_present;
      local_track_number( int nr, bool present = false );
      local_track_number();
   };

   //Configured accuracies for the measurement, constant per sensor but convenient in distributed
   //environments where the information is not distributed at start or where the setup can change over time
   struct configured_acc {
      double range_acc;
      double azimuth_acc;
      configured_acc();
   };

   //Aircraft derived data with presence flag per item
   struct add_data {
      GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item_name;
      bool item_present;
      char value[MAX_ADD_ITEM_LENGTH] = { 0 };

      add_data();
      add_data( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES i, std::string v );

      std::string getValue();
      GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES getItemID();
      bool isItemPresent();
      void setItemValue( std::string v );
      void setPresense( bool p );
   };

   //Pack everything into one struct for easy access.
   struct report_record {
      uint64_t det_time; // Will be translated to the proper time if needed to be
      source_id source;
      geo_position geo_pos;
      double_t heading;
      double_t ground_speed;
      rng_azim range_azimuth;
      baro_geo_height height;
      mode_3aC mc;
      double_t meas_3D_height;
      mode_3aC m3a;
      mode_3aC mode2;
      aircraft_id aircraft_ident;
      aircraft_address icao_address;
      local_track_number local_trk_no;
      DetectionEntry::DET_TYPE detection_type;
      DetectionEntry::DET_LINK link;
      configured_acc configured_accuracies;
      std::vector<add_data> aircraft_derived_data;
      geo_position radar_pos; //For enhanced flexibility

      report_record();

      /**
       * Some procedures to manage the aircraft derived data. As of now this is the only entry not
       * entirely handled by the item itself, because of the vector, which is only known here.
       *
       * @throws ElementNotFound exception in case the required item is not in the list but was
       * requested for reading.
       */
      void updateADDItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item,
         std::string value, bool present );
      std::string getADDItemValue( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item );
      add_data getADDItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item );
   };

   report_record current_record;

   PointXYZ position_in_world_coordinates = PointXYZ();

   struct report_record_resp_t {
      std::size_t hash;
      int rank;
      report_record_resp_t();
   };
   report_record_resp_t currently_reponsible_process;

   std::size_t report_hash = 0;

private:
   bool empty_report = false;

   // Mapping of detection type to corresponding string
   std::map<DetectionEntry::DET_TYPE, std::string> detTypeMapping;

public:
   typedef report_record ReportRecord_T;
   typedef report_record_resp_t ReportRecordResponsible_T;

   /**
    * Create a new nearly empty ReportRecord. Only the absolutely necessary mandatory attributes
    * are required for this one. For simplicity, no other contructor is given. Thus all other attributes
    * need to be set by there setter method.
    *
    * @param det_time. The detection time in milliseconds.
    * @param sac. Sensor area code
    * @param sic. Sensor identification code
    * @return None
    * @throws None
    */
   ReportRecordType( uint64_t det_time, int sac, int sic );

   //Needed for default assignment
   ReportRecordType();
   ReportRecordType( const ReportRecordType& other_report );
   ReportRecordType( const ReportRecord_T& other_record );

   virtual ~ReportRecordType();

   //SET
   void setReportHash( std::size_t h );
   void setSource( int sac, int sic );
   void setGeoPosLatLng( double lat, double lng, bool lat_lng_present = true );
   void setGeoPosElevation( double elev, bool elev_present = true );
   void setHeading( double h, bool p = true );
   void setGroundSpeed( double s, bool p = true );
   void setRangeAzimuth( double range, double azim, bool present = true );
   void setBaroHeight( double height, bool present = true );
   void setGeoHeight(double height, bool present = true);
   void setMode3A( int code, bool present = true, bool garbled = false, bool valid = true );
   void setMode2(int code, bool present = true, bool garbled = false, bool valid = true);
   void setModeC( int code, bool present = true, bool garbled = false, bool valid = true );
   void setAircraftIdent( std::string id, bool present = true );
   void setAircraftAddress( unsigned long address, bool present = true );
   void setLocalTrackNumber( int number, bool present = true );
   void setDetectionType(DetectionEntry::DET_TYPE detection);
   void setDetectionLink(DetectionEntry::DET_LINK l);
   void setRadarPosition( double lat, double lng, double elev, bool p = true );
   void setDetectionTimePoint( std::chrono::system_clock::time_point t );
   void setDetectionTimeFromTOD( uint64_t tod );
   void setRecord( ReportRecord_T& record );
   void setResponsibleRank( int rank );
   void setEmpty( bool empty );
   void setDAPItem( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item, std::string value );

   /**
    * In order to keep the report consistent it is only allowed to set the base values (e.g. Range)
    * from which the position is calculated, but not the position itself.
    */
   void setWorldPosition(PointXYZ position) = delete;

   /**
    * @param force if set to true a re-calculation is done in any case. If set to false a re-calculation
    * is only done if it has not run before.
    */
   //void transformPosCoordinatesToWorld3D( bool force = false );

   // GET
   std::size_t getReportHash();
   std::tuple<int, int> getSourceID() const;
   uint64_t getDetectionTime() const;
   uint64_t getDetectionTimeUTC() const;
   std::tuple<double, double> getGeoPos();
   double getHeading();
   double getGroundSpeed();
   double getElevation();
   std::tuple<double, double> getRangeAzimuth();
   double getBarometricHeight();
   double getGeometricHeight();
   double get3DHeight();
   int getModeCCode();
   int getMode3ACode();
   int getMode2Code();
   std::string getAircraftIdent();
   unsigned long getAircraftAddress();
   int getLocalTrackNumber();
   DetectionEntry::DET_TYPE getDetectionType();
   DetectionEntry::DET_LINK getDetectionLink();
   geo_position getRadarPosition();
   bool getSPI();
   std::string getDAP( GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item_name );
   ReportRecord_T& getRecordBufferAccess();
   //PointXYZ getWorldPosition();
   int getRank();
   ReportRecordResponsible_T getResponsibleRecord();

   //IS
   bool isGeoPosPresent();
   bool isHeadingPresent();
   bool isGroundSpeedPresent();
   bool isEleveationPresent();
   bool isRangeAzimuthPresent();
   bool isBarometricHeightPresent();
   bool isModeCPresent();
   bool isModeCValid();
   bool isModeCGarbled();
   bool isGeometricHeightPresent();
   bool isMode3APresent();
   bool isMode3AValidNotGarbled();
   bool isMode3AValid();
   bool isMode3AGarbled();
   bool isMode2Present();
   bool isMode2ValidNotGarbled();
   bool isMode2Valid();
   bool isMode2Garbled();
   bool isAircraftIdentPresent();
   bool isAircraftAddressPresent();
   bool isAircraftDerivedItemPresent(
      GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item_name );
   bool isLocalTrackNumberPresent();
   bool isEmptyReport();
   bool is3DHeightPresent();

   /**
    * Convert the provided detection type to a string.
    *
    * @param det_type enumerated version of the detection type
    * @return the detetction type converted to string
    */
   std::string detTypeToString(DetectionEntry::DET_TYPE det_type);

   /**
    * Iterator allowing to easily access the different age items that can be present in the report
    */
   class ageItemIterator: public std::map<DetectionEntry::DET_TYPE, std::string>::iterator {
   public:

      typedef ageItemIterator self_type;
   };
   std::map<DetectionEntry::DET_TYPE, std::string>::iterator detAgeIterBegin();
   std::map<DetectionEntry::DET_TYPE, std::string>::iterator detAgeIterEnd();
};

#endif /* REPORTRECORDTYPE_H_ */
