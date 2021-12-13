/**
 * @file AsterixItemCompoundLI.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 1 Aug 2017
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
 * See H file for more informations
 */

#include "AsterixItemCompoundLI.h"
#include "AsterixExceptions.h"

#include <bitset>

AsterixItemCompoundLI::AsterixItemCompoundLI( std::string name,
   AsterixItemCompound::subUap_T sub_uap ) :
   AsterixItemCompound( name, sub_uap ) {
}

AsterixItemCompoundLI::~AsterixItemCompoundLI(){
}

std::deque<char> AsterixItemCompoundLI::readItem( std::deque<char>& buffer ){
   // Read the length indicator first
   std::bitset<8> length_indicator( buffer.front() );

   if( buffer.size() < length_indicator.to_ulong() ) {
      throw MessageSizeMissmatch( "AsterixItemCompoundLI", getName(),
         " Length Indicator(" + std::to_string( length_indicator.to_ulong() )
            + ") but buffer length " + std::to_string( buffer.size() ) );
   }

   buffer.pop_front(); // Remove the length indication

   // Now read the rest of the item including the sub fspec
   return AsterixItemCompound::readItem( buffer );
}
