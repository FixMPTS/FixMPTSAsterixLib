/**
 * @file AsterixItemExtendible.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 20 Mar 2016
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
 * See description of the header files.
 */
#include "AsterixItemExtendible.h"

#include <bitset>
#include <vector>

AsterixItemExtendible::~AsterixItemExtendible() {
}

AsterixItemExtendible::AsterixItemExtendible( std::string name, unsigned length ) :
   AsterixItem( name ) {
   repeated_length = length;
}

std::deque<char> AsterixItemExtendible::readItem( std::deque<char>& buffer ) {
   std::deque<char> return_value;
   bool end_reached = false;

   // The bytes read within the current block
   unsigned int bytes_read_block = 0;
   std::vector<bool> item_bits;

   while (!end_reached) {
      bytes_read_block++;

      std::bitset<8> item_byte( buffer.front() );
      unsigned short byte_end = 1;
      // If end of block is reached, check the FX bit
      if( bytes_read_block == repeated_length ) {

         end_reached = (item_byte[0] == 0);
         bytes_read_block = 0;

         byte_end = 2; // Remove the FX bit
      }

      for( unsigned int i = 0; i <= item_byte.size() - byte_end; i++ ) {
         item_bits.push_back( item_byte[item_byte.size() - 1 - i] );
      }

      buffer.pop_front();

   }

   // Write the bits back to bytes
   for( unsigned int byte = 0; byte <= item_bits.size() / 8; byte++ ) {
      std::bitset<8> current_byte( 0 );
      for( unsigned int i = byte * 8; (i < item_bits.size() && i < (byte * 8) + 8); i++ ) {
         current_byte[current_byte.size() - 1 - (i % 8)] = item_bits[i] == true;
      }
      return_value.push_back( current_byte.to_ulong() );
   }

   return return_value;
}
