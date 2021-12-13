/**
 * @file AsterixItemVariableLengthFlex.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 29 Oct 2017
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
 * See .h file for more informations
 */

#include "AsterixItemVariableLengthFlex.h"

#include <bitset>
#include <iostream>

AsterixItemVariableLengthFlex::~AsterixItemVariableLengthFlex() {
}

AsterixItemVariableLengthFlex::AsterixItemVariableLengthFlex( std::string name,
   unsigned int length ) :
   AsterixItemVariableLength( name ), length_of_first_item( length ) {
}

std::deque<char> AsterixItemVariableLengthFlex::readItem( std::deque<char>& buffer ) {
   std::deque<char> return_value;
   // The last byte has to be handled with special care because of the FX bit and with respect to
   // remaining bytes
   for( unsigned i = 0; i < length_of_first_item - 1; i++ ) {
      return_value.push_back( buffer.front() );
      buffer.pop_front();
   }

   // if the FX is set, read the rest like the conventional extended item
   std::bitset<8> item_end( buffer.front() );
   if( item_end[0] == 1 ) {

      // The last byte of the first set will be handled by the parent class in order to remove
      // the FX bit and keep the rest consistent
      std::deque<char> reminder = AsterixItemVariableLength::readItem( buffer );

      return_value.insert( return_value.end(), reminder.begin(), reminder.end() );
   }

   return return_value;
}
