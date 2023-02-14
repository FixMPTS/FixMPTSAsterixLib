/**
 * @file SensorServiceRecordType.cpp
 * @author  Felix Kreuter <felix.kreuter@lordcentury.net>
 * @version 1.0
 * Created on: 13 Mar 2022
 *
 @section LICENSE
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
#include "SensorServiceRecordType.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    PlotCount     ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
SensorServiceRecordType::PlotCount::PlotCount() :
   antenna_nr( 2 ), ident( 0 ), counter( 0 ) {
}

SensorServiceRecordType::PlotCount::PlotCount(unsigned short antenna, unsigned short id, unsigned int count) :
   antenna_nr( antenna ), ident( id ), counter( count ) {
}

void SensorServiceRecordType::PlotCount::setAntenna(unsigned short antenna) {
   antenna_nr = antenna;
}

void SensorServiceRecordType::PlotCount::setIdent(unsigned short id) {
   ident = id;
}

void SensorServiceRecordType::PlotCount::setCounter(unsigned int count) {
   counter = count;
}

unsigned short SensorServiceRecordType::PlotCount::getAntenna() {
   return antenna_nr;
}

unsigned short SensorServiceRecordType::PlotCount::getIdent() {
   return ident;
}

unsigned int SensorServiceRecordType::PlotCount::getCounter() {
   return counter;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////    SensorServiceRecordType    ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
SensorServiceRecordType::SensorServiceRecordType() :
   sac( 0 ), sic( 0 ), message_type(), sector_number(), tod( 0 ), antenna_speed(), plot_count() {
}

SensorServiceRecordType::~SensorServiceRecordType() {
   plot_count.clear();
}

SensorServiceRecordType::SensorServiceRecordType(unsigned int sac, unsigned int sic) :
   SensorServiceRecordType() {
   this->sac = sac;
   this->sic = sic;
}

void SensorServiceRecordType::setSensorIdentifier(unsigned int sac, unsigned int sic) {
   this->sac = sac;
   this->sic = sic;
}

void SensorServiceRecordType::setMessageType(unsigned short type) {
   message_type = type;
}

void SensorServiceRecordType::setSectorNumber(float sector) {
   sector_number = sector;
}

void SensorServiceRecordType::setTimeOfDay(double tod) {
   this->tod = tod;
}

void SensorServiceRecordType::setAntennaSpeed(double speed) {
   antenna_speed = speed;
}

void SensorServiceRecordType::resetPlotCount() {
   plot_count.clear();
}

void SensorServiceRecordType::addPlotCount(SensorServiceRecordType::PlotCount entry) {
   plot_count.push_back( entry );
}

bool SensorServiceRecordType::isMessageTypePresent() {
   return message_type.has_value();
}

bool SensorServiceRecordType::isSectorNumberPresent() {
   return sector_number.has_value();
}

bool SensorServiceRecordType::isAntennaSpeedPresent() {
   return antenna_speed.has_value();
}

std::tuple<unsigned int, unsigned int> SensorServiceRecordType::getSensorId() {
   return std::make_tuple( sac, sic );
}

unsigned short SensorServiceRecordType::getMessageType() {
   return message_type.value();
}

float SensorServiceRecordType::getSectorNumber() {
   return sector_number.value();
}

double SensorServiceRecordType::getTimeOfDay() {
   return tod.value();
}

double SensorServiceRecordType::getAntennaSpeed() {
   return antenna_speed.value();
}

std::vector<SensorServiceRecordType::PlotCount> SensorServiceRecordType::getPlotCount() {
   return plot_count;
}
