/**
 * @file DetectionEntry.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 5 Apr 2021
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
#include "DetectionEntry.h"

#include <limits>

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    Internal classes     ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
DetectionEntry::ModeX::ModeX() :
   code( 0 ), valid( false ), garbled( false ) {
}

DetectionEntry::ModeX::ModeX(int code, bool valid, bool garbled) {
   this->code = code;
   this->valid = valid;
   this->garbled = garbled;
}

int DetectionEntry::ModeX::getCode() {
   return code;
}

bool DetectionEntry::ModeX::isValid() {
   return valid;
}

bool DetectionEntry::ModeX::isGarbled() {
   return garbled;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////     DetectionEntry      ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
DetectionEntry::DetectionEntry() {
   detection_type = DET_TYPE::NONE;
   sensor_list = std::vector<std::tuple<unsigned short, unsigned short>>();
   valid = false;
   measurement = PointXYZ( std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(),
      std::numeric_limits<double>::infinity() );
   //mode_3A = DetectionEntry::ModeX();
   //mode_c = DetectionEntry::ModeX();
}

DetectionEntry::DetectionEntry(DET_TYPE t) :
   DetectionEntry() {
   detection_type = t;
   valid = true;
}

DetectionEntry::~DetectionEntry() {
}

DetectionEntry::DET_TYPE DetectionEntry::getDetectionType() {
   return detection_type;
}

unsigned short DetectionEntry::getSourceIDSacAt(unsigned int pos) {
   if( sensor_list.size() <= pos ) {
      return std::numeric_limits<unsigned short>::infinity();
   }
   return std::get<0>( sensor_list.at( pos ) );
}

unsigned short DetectionEntry::getSourceIDSicAt(unsigned int pos) {
   if( sensor_list.size() <= pos ) {
      return std::numeric_limits<unsigned short>::infinity();
   }
   return std::get<1>( sensor_list.at( pos ) );
}

bool DetectionEntry::isDummyDetection() {
   return !valid;
}

double DetectionEntry::getMeasuredRange() {
   return measurement.getX();
}

double DetectionEntry::getMeasuredAzimuth() {
   return measurement.getY();
}

std::optional<double> DetectionEntry::get3DHeight() {
   std::optional<double> height;
   if( measurement.getZ() != std::numeric_limits<double>::infinity() ) {
      height = std::optional<double>( measurement.getZ() );
   }
   return height;
}

std::optional<DetectionEntry::ModeX> DetectionEntry::getModeC() {
   return mode_c;
}

std::optional<DetectionEntry::ModeX> DetectionEntry::getMode3A() {
   return mode_3A;
}


void DetectionEntry::setDetectionType(DET_TYPE t) {
   detection_type = t;
   valid = true;
}

void DetectionEntry::addContributingSensor(std::tuple<unsigned short, unsigned short> sensor) {
   sensor_list.push_back( sensor );
   valid = true;
}

void DetectionEntry::setMeasurement(PointXYZ measurement) {
   this->measurement = measurement;
   valid = true;
}

void DetectionEntry::setMode3A(ModeX mode) {
   mode_3A = mode;
   valid = true;
}

void DetectionEntry::setModeC(ModeX mode) {
   mode_c = mode;
   valid = true;
}

void DetectionEntry::removeContributingSensor(std::tuple<unsigned short, unsigned short> sensor, bool single) {
   auto sensor_iter = sensor_list.begin();
   while( sensor_iter != sensor_list.end() ) {
      if( *(sensor_iter) == sensor ) {
         sensor_iter = sensor_list.erase( sensor_iter );
         if( single ) {
            break;
         }
      } else {
         ++sensor_iter;
      }
   }
}

void DetectionEntry::removeContributingSensorAt(size_t pos) {
   if( pos >= sensor_list.size() ) {
      return;
   }
   removeContributingSensor( sensor_list.at( pos ), true );
}
