/**
 * @file AircraftDerivedDataItemBase.h
 * @author Felix Kreuter <felix@fixmpts.org>
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with FixMPTS Asterix Library. If not, see <https://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * The purpose of this class is to provide the means of representing an aircraft derived data item.
 * Those items are meant to be just forwarded from the received report which allows them to be
 * transmitted directly to the connected service.
 *
 * Not managed representation of an aircraft derived data item.
 */
#ifndef AIRCRAFTDERIVEDDATAITEMBASE_H_
#define AIRCRAFTDERIVEDDATAITEMBASE_H_

// project includes
#include "GeneralEnumerations.h"
#include "TimeRelated.h"

// global includes
#include <string>

class AircraftDerivedDataItemBase {
public:
   enum class VALUE_TYPES {
      NONE, BOOLEAN, NUMBER, DOUBLE, STRING
   };

private:
   // Name of the item
   std::string item_name;

   // string representation of the value
   std::string item_value;

protected:
   // type of the item required for proper return value if asked for
   VALUE_TYPES item_type;

   // Time pf last update of this item in ms
   uint64_t last_update_time;

   /**
    * Modify the time of last update of the item to the time given. No checks are run whether this
    * time is in the past or future given the previously stored time.
    *
    * @param t the new time
    * @throws Not yet decided
    */
   void setUpdateTime( uint64_t t );

public:
   AircraftDerivedDataItemBase();
   AircraftDerivedDataItemBase( std::string name, std::string value, VALUE_TYPES type );
   AircraftDerivedDataItemBase( const AircraftDerivedDataItemBase& other_item );

   virtual ~AircraftDerivedDataItemBase();

   /**
    * Update the given value with the new value provided. This item will be overwritten without
    * any management or sanity checks.
    *
    * @param value the new value received from the aircraft
    * @throws Not yet decided
    */
   virtual void updateItem( std::string value );
   virtual void updateItem( std::string value, uint64_t time );

   /**
    * Get the currently stored value as string no matter what type it currently has.
    *
    * @return the string representaton of the item
    * @throws Not yet decided
    */
   std::string getItemAsString();
   std::string getName();
   VALUE_TYPES getType();
   uint64_t getLastUpdateTime();

   // GET
   bool getBooleanValue();
   int getIntegerValue();
   double getDoubleValue();

   /**
    * Get the age since last update in seconds.
    */
   double getItemAgeS();
};

#endif /* AIRCRAFTDERIVEDDATAITEMBASE_H_ */
