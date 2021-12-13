/**
 * @file TrackTypeIf.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 4 Apr 2021
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
 * Interface datatype to translate between the structure required in the Asterix library and the outside worl.
 */
#ifndef TRACKTYPEIF_H_
#define TRACKTYPEIF_H_

#include "DetectionEntry.h"
#include "GeneralEnumerations.h"
#include "AircraftDerivedDataItemBase.h"
#include "PointXYZ.h"

#include <vector>
#include <map>
#include <cstdint>
#include <string>
#include <memory>

class TrackTypeIf {
public:
   enum class TRACK_MOF {
      UNDEFINED,
      CONSTANT_COURSE,
      RIGHT_TURN,
      LEFT_TURN,
      CONSTANT_GDSP,
      ACCELERATION,
      DECELERATION,
      LEVEL,
      CLIMB,
      DESCENT
   };

private:
   unsigned int track_number;
   std::optional<DetectionEntry::ModeX> mode_3A;
   std::optional<DetectionEntry::ModeX> mode_C;
   uint64_t time_last_update;
   double track_weight;
   PointXYZ position;
   double baro_alt;
   double rate_cd;

   TRACK_MOF trans_mof;
   TRACK_MOF long_mof;
   TRACK_MOF vert_mof;

   std::map<GenericEnumerations::AGE_ITEMS, double> detection_ages;
   std::map<GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES, std::shared_ptr<AircraftDerivedDataItemBase>> addItems;

   std::vector<DetectionEntry> detections;

public:
   TrackTypeIf();
   TrackTypeIf(unsigned int number);
   TrackTypeIf(unsigned int number, PointXYZ pos);
   virtual ~TrackTypeIf();

   // GET
   unsigned int getTrackNumber();

   std::optional<DetectionEntry::ModeX> getMode3A();
   std::optional<DetectionEntry::ModeX> getModeC();

   uint64_t getLastUpdatingTime();
   size_t getDetectionListSize();
   DetectionEntry getDetectionAt(size_t pos);

   bool isADItemPresent(GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item);
   std::shared_ptr<AircraftDerivedDataItemBase> getADItem(GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item);

   double getTrackWeight();

   double getDetectionAge(GenericEnumerations::AGE_ITEMS item);

   // Position related get
   double getPositionLat();
   double getPositionLng();
   double getPositionAltGeo();
   double getBaroAltitude();

   //Mode of movement. There is only one mof type meaning these split in different kinds of mof is just for convenience
   TRACK_MOF getTransversalMof();
   TRACK_MOF getLongitudinalMof();
   TRACK_MOF getVerticalMof();

   double getRateOfCD();


   // SET
   void setTrackNumber(unsigned int no);
   void setMode3A(int code, bool valid, bool garbled);
   void setModeC(int code, bool valid, bool garbled);
   void setLastUpdateTime(uint64_t time);
   void addDetection(DetectionEntry entry);
   void addADItem(GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item, std::string value);
   void addADItem(GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item,
      std::shared_ptr<AircraftDerivedDataItemBase> entry);
   void setTrackWeight(double weight);
   void setDetectionAgeFor(GenericEnumerations::AGE_ITEMS det_type, double age);
   void setDetectionAgeFor(GenericEnumerations::AGE_ITEMS det_type, int age);
   void setGeoPosition(double lat, double lng, double alt);
   void setBaroAltitude(double alt);
   void setRateOfCD(double rate);
   void setTransversalMof(TRACK_MOF mof);
   void setLongitudinalMof(TRACK_MOF mof);
   void setVerticalMof(TRACK_MOF mof);
};

#endif /* TRACKTYPEIF_H_ */
