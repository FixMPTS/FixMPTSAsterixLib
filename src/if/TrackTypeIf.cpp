/**
 * @file TrackTypeIf.cpp
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
 * See .h file for more information
 */
#include "TrackTypeIf.h"

#include "AircraftDerivedDataItemExtended.h"

#include <iostream>

TrackTypeIf::TrackTypeIf() {
   track_number = std::numeric_limits<unsigned int>::max();
   time_last_update = 0;
   track_weight = 0.0;
   position = PointXYZ();
   baro_alt = std::numeric_limits<double>::max();
   trans_mof = TrackTypeIf::TRACK_MOF::UNDEFINED;
   long_mof = TrackTypeIf::TRACK_MOF::UNDEFINED;
   vert_mof = TrackTypeIf::TRACK_MOF::UNDEFINED;
   rate_cd = std::numeric_limits<double>::max();

   detection_ages = std::map<GenericEnumerations::AGE_ITEMS, double>();
   addItems = std::map<GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES,
      std::shared_ptr<AircraftDerivedDataItemBase>>();
}

TrackTypeIf::TrackTypeIf(unsigned int number) :
   TrackTypeIf() {
   track_number = number;
}
TrackTypeIf::TrackTypeIf(unsigned int number, PointXYZ pos) :
   TrackTypeIf() {
   track_number = number;
   position = pos;
}

TrackTypeIf::~TrackTypeIf() {
   detection_ages.clear();
   addItems.clear();
}

unsigned int TrackTypeIf::getTrackNumber() {
   return track_number;
}

std::optional<DetectionEntry::ModeX> TrackTypeIf::getMode3A() {
   return mode_3A;
}

std::optional<DetectionEntry::ModeX> TrackTypeIf::getModeC() {
   return mode_C;
}

uint64_t TrackTypeIf::getLastUpdatingTime() {
   return time_last_update;
}

size_t TrackTypeIf::getDetectionListSize() {
   return detections.size();
}

DetectionEntry TrackTypeIf::getDetectionAt(size_t pos) {
   if( detections.size() <= pos ) {
      return DetectionEntry();
   }
   return detections.at( pos );
}

bool TrackTypeIf::isADItemPresent(GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item) {
   return addItems.find( item ) != addItems.end();
}

std::shared_ptr<AircraftDerivedDataItemBase> TrackTypeIf::getADItem(
   GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item) {
   if( isADItemPresent( item ) ) {
      return addItems.at( item );
   }
   return nullptr;
}

double TrackTypeIf::getTrackWeight() {
   return track_weight;
}

double TrackTypeIf::getDetectionAge(GenericEnumerations::AGE_ITEMS item) {
   if( detection_ages.find( item ) != detection_ages.end() ) {
      return detection_ages.at( item );
   }
   return std::numeric_limits<double>::max();
}

double TrackTypeIf::getPositionLat() {
   return position.getX();
}

double TrackTypeIf::getPositionLng() {
   return position.getY();
}

double TrackTypeIf::getPositionAltGeo() {
   return position.getZ();
}

double TrackTypeIf::getBaroAltitude() {
   return baro_alt;
}

TrackTypeIf::TRACK_MOF TrackTypeIf::getTransversalMof() {
   return trans_mof;
}

TrackTypeIf::TRACK_MOF TrackTypeIf::getLongitudinalMof() {
   return long_mof;
}

TrackTypeIf::TRACK_MOF TrackTypeIf::getVerticalMof() {
   return vert_mof;
}

double TrackTypeIf::getRateOfCD() {
   return rate_cd;
}

void TrackTypeIf::setTrackNumber(unsigned int no) {
   track_number = no;
}

void TrackTypeIf::setMode3A(int code, bool valid, bool garbled) {
   mode_3A = DetectionEntry::ModeX( code, valid, garbled );
}

void TrackTypeIf::setModeC(int code, bool valid, bool garbled) {
   mode_C = DetectionEntry::ModeX( code, valid, garbled );
}

void TrackTypeIf::setLastUpdateTime(uint64_t time) {
   time_last_update = time;
}

void TrackTypeIf::addDetection(DetectionEntry entry) {
   detections.push_back( entry );
}

void TrackTypeIf::addADItem(GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item, std::string value) {
   addItems[item] = std::make_shared<AircraftDerivedDataItemExtended>( "", value,
      AircraftDerivedDataItemBase::VALUE_TYPES::STRING );
}
void TrackTypeIf::addADItem(GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES item,
   std::shared_ptr<AircraftDerivedDataItemBase> entry) {
   addItems[item] = entry;
}

void TrackTypeIf::setTrackWeight(double weight) {
   track_weight = weight;
}

void TrackTypeIf::setDetectionAgeFor(GenericEnumerations::AGE_ITEMS det_type, double age) {
   detection_ages[det_type] = age;
}

void TrackTypeIf::setDetectionAgeFor(GenericEnumerations::AGE_ITEMS det_type, int age) {
   detection_ages[det_type] = static_cast<double>( age );
}


void TrackTypeIf::setGeoPosition(double lat, double lng, double alt) {
   position = PointXYZ( lat, lng, alt );
}

void TrackTypeIf::setBaroAltitude(double alt) {
   baro_alt = alt;
}

void TrackTypeIf::setRateOfCD(double rate) {
   rate_cd = rate;
}

void TrackTypeIf::setTransversalMof(TRACK_MOF mof) {
   trans_mof = mof;
}

void TrackTypeIf::setLongitudinalMof(TRACK_MOF mof) {
   long_mof = mof;
}

void TrackTypeIf::setVerticalMof(TRACK_MOF mof) {
   vert_mof = mof;
}
