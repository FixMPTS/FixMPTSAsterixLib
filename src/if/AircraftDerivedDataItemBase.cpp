/**
 * @file AircraftDerivedDataItemBase.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 19 Apr 2016
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
 * see .h file for more information
 */

// project includes
#include "AircraftDerivedDataItemBase.h"

// global includes
#include <iostream>

AircraftDerivedDataItemBase::AircraftDerivedDataItemBase() :
   item_type( VALUE_TYPES::NONE ), last_update_time( 0 ) {
}

AircraftDerivedDataItemBase::AircraftDerivedDataItemBase( std::string name, std::string value,
   VALUE_TYPES type ) :
   item_name( name ), item_value( value ), item_type( type ), last_update_time( 0 ) {
}

AircraftDerivedDataItemBase::AircraftDerivedDataItemBase(
   const AircraftDerivedDataItemBase& other_item ) {
   item_name = other_item.item_name;
   item_type = other_item.item_type;
   last_update_time = other_item.last_update_time;
}

AircraftDerivedDataItemBase::~AircraftDerivedDataItemBase() {
}

void AircraftDerivedDataItemBase::updateItem( std::string value ){
   updateItem( value, getCurrentTimeMS() );
}

void AircraftDerivedDataItemBase::updateItem( std::string value, uint64_t time ){
   item_value = value;
   // Only change the age if it is not in the past compared with the currently stored age
   if( last_update_time<time ) {
      last_update_time = time;
   }
}

void AircraftDerivedDataItemBase::setUpdateTime( uint64_t t ) {
   last_update_time = t;
}

std::string AircraftDerivedDataItemBase::getItemAsString() {
   return item_value;
}
std::string AircraftDerivedDataItemBase::getName() {
   return item_name;
}
AircraftDerivedDataItemBase::VALUE_TYPES AircraftDerivedDataItemBase::getType() {
   return item_type;
}
uint64_t AircraftDerivedDataItemBase::getLastUpdateTime() {
   return last_update_time;
}

bool AircraftDerivedDataItemBase::getBooleanValue() {
   return item_type == VALUE_TYPES::BOOLEAN && item_value == "1";
}

int AircraftDerivedDataItemBase::getIntegerValue() {
   return item_type == VALUE_TYPES::NUMBER ? atoi( item_value.c_str() ) : std::numeric_limits<int>::max();
}

double AircraftDerivedDataItemBase::getDoubleValue() {
   return item_type == VALUE_TYPES::DOUBLE ? atof( item_value.c_str() ) : std::numeric_limits<int>::max();
}

double AircraftDerivedDataItemBase::getItemAgeS() {
   return (double) (getCurrentTimeMS() - last_update_time) / 1000.0;
}
