/**
 * @file AsterixItemCompound.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
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
 * See .h file fore more information
 */

#include "AsterixItemCompound.h"
#include "AsterixItemRepetetive.h"
#include "AsterixItemVariableLengthFlex.h"

#include <bitset>

AsterixItemCompound::AsterixItemCompound( std::string name, AsterixItemCompound::subUap_T sub_uap ) :
   AsterixItem( name, -1 ) {
   subitem_uap = sub_uap;
}

AsterixItemCompound::~AsterixItemCompound() {
}

std::deque<char> AsterixItemCompound::readItem( std::deque<char>& buffer ) {
   if( buffer.size() <= 0 ) {
      throw "No Subfspec present";
   }

   std::deque<char> return_buffer;

   // Parse sub pseudo fspec
   bool fpsec_end = false;

   unsigned int current_position = 0;
   while (!fpsec_end) {
      unsigned char fspec_byte = static_cast<unsigned char>( buffer.front() );
      buffer.pop_front();

      std::bitset<8> f_byte( fspec_byte );
      if( f_byte[0] == 0 ) { //FX bit not set
         fpsec_end = true;
      }

      //append fpsec to existing fspec definition
      for( unsigned int i = f_byte.size() - 1; i > 0; i-- ) { //Respect the endianes
         //FRN counting starts at 1
         sub_fspec.push_back( f_byte[i] == 1 ? true : false );
         current_position++;
      }
   }

   // Read all present sub items
   for( unsigned int i = 0; i < subitem_uap.size(); i++ ) {
      if( sub_fspec[i] == false ) {
         continue; // item not present
      }

      unsigned int current_frn = i + 1;

      // Delegate reading to repetitive item
      if( std::dynamic_pointer_cast<AsterixItemRepetetive>( subitem_uap.at( current_frn ) )
         != nullptr
         || std::dynamic_pointer_cast<AsterixItemVariableLengthFlex>(
            subitem_uap.at( current_frn ) ) != nullptr ) {

         std::deque<char> rep_buffer = subitem_uap.at( current_frn )->readItem( buffer );

         return_buffer.insert( return_buffer.end(), rep_buffer.begin(), rep_buffer.end() );
      } else {
         for( int byte_number = 0; byte_number < subitem_uap.at( current_frn )->getItemLength();
            byte_number++ ) {
            return_buffer.push_back( buffer.front() );
            buffer.pop_front();
         }
      }
   }
   return return_buffer;
}

std::map<std::string, bool> AsterixItemCompound::getItemPresenceMap() {
   std::map<std::string, bool> result_map;
   unsigned uap_position = 0;
   for( auto item : subitem_uap ) {
      result_map[item.second->getName()] = sub_fspec[uap_position];
      uap_position++;
   }
   return result_map;
}

bool AsterixItemCompound::isPresent( std::string item_name ) {
   unsigned uap_position = 0;
   for( auto item : subitem_uap ) {
      if( item_name == item.second->getName() ) {
         return sub_fspec[uap_position];
      }
      uap_position++;
   }
   return false;
}
