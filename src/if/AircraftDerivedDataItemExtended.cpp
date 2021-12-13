/**
 * @file AircraftDerivedDataItemExtended.cpp
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
 * See header file for more informations
 */

// project includes
#include "AircraftDerivedDataItemExtended.h"
#include "StringRelated.h"

// global includes
#include<iostream>

AircraftDerivedDataItemExtended::AircraftDerivedDataItemExtended() {
}

AircraftDerivedDataItemExtended::AircraftDerivedDataItemExtended( std::string name,
   std::string value, VALUE_TYPES type ) :
   AircraftDerivedDataItemBase( name, value, type ) {
}

AircraftDerivedDataItemExtended::~AircraftDerivedDataItemExtended() {
}

void AircraftDerivedDataItemExtended::updateItem( std::string value, uint64_t time ){
   // The item is expected to be a comma separated list
   unsigned pos = 0;
   while (value.find( "," ) != value.npos) {
      unsigned split_at = value.find( "," );
      values[pos] = trim( value.substr( 0, split_at ) );
      value = value.substr( split_at + 1 );
      pos++;

   }
   values[pos] = trim( value );

   // Only change the age if it is not in the past compared with the currently stored age
   if( last_update_time < time ) {
      last_update_time = time;
   }
}

std::vector<double> AircraftDerivedDataItemExtended::getDoubleValues() {
   std::vector<double> mapped_items;
   if( item_type == VALUE_TYPES::DOUBLE ) {
      for( auto item : values ) {
         mapped_items.push_back( std::atof( item.second.c_str() ) );
      }
   }

   return mapped_items;
}
