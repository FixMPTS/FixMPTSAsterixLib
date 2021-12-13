/**
 * @file AircraftDerivedDataItemExtended.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 9 Jun 2016
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
 * Class representing an extended ADD item. This item can store an unlimited number of ADD values
 * which must be all of the same type.
 */
#ifndef AIRCRAFTDERIVEDDATAITEMEXTENDED_H_
#define AIRCRAFTDERIVEDDATAITEMEXTENDED_H_

#include "AircraftDerivedDataItemBase.h"

#include <vector>

class AircraftDerivedDataItemExtended: public AircraftDerivedDataItemBase {
private:
   std::map<unsigned, std::string> values;

public:
   AircraftDerivedDataItemExtended();
   AircraftDerivedDataItemExtended( std::string name, std::string value, VALUE_TYPES type );
   virtual ~AircraftDerivedDataItemExtended();

   /**
    * Get a list of the values stored within this ADD item converted to double. Note: The original
    * type needs to support the conversion to double.
    *
    * @return a map containing the index and value of data stored in the item.
    * @throws NOt yet decided
    */
   std::vector<double> getDoubleValues();

   /**
    * Update the complete list of values currently stored. It is expected that the new values are
    * given as a comma separated list. If there are more values in the list as currently stored, those
    * are added the the store.
    *
    * @param value a comma separated list containing the new values
    * @time the time of last update
    * @return None
    * @throws NOt yet decided
    */
   virtual void updateItem( std::string value, uint64_t time ) override;
};

#endif /* AIRCRAFTDERIVEDDATAITEMEXTENDED_H_ */
