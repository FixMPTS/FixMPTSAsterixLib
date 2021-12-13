/**
 * @file AsterixItemVariableLength.cpp
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
 * See .h file for more information
 */

//project includes
#include "AsterixItemVariableLength.h"

//general includes
#include <bitset>
#include <vector>

AsterixItemVariableLength::AsterixItemVariableLength( std::string name ) :
   AsterixItem( name ) {
}

AsterixItemVariableLength::~AsterixItemVariableLength() {/*Nothing to do at the moment*/
}

std::deque<char> AsterixItemVariableLength::readItem( std::deque<char>& buffer ) {
   std::deque<char> return_buffer;

   bool item_finished = false;
   std::vector<bool> return_bits;
   while (!item_finished) {
      //read the FX bit and remove it from the message
      //For proper handling of the items and removal of the FX bit this need to be unsigned
      unsigned char byte = static_cast<unsigned char>( buffer.front() );
      std::bitset<8> item_byte( byte );

      buffer.pop_front();

      if (item_byte[0] == 0) {      //FX bit not set
         item_finished = true;
      }

      //item without FX bit
      for (unsigned int i = item_byte.size() - 1; i > 0; i--) { //Just copy the remaining bits to the new bitset
         return_bits.push_back( item_byte[i] );
      }
   }

   // Convert the Bits to bytes again but this time the FX bit is removed in the above loop
   // Basically this is just shifting the FX bits to the end where they will be ignored in further
   // decoding steps
   std::bitset<8> current_byte( 0 );
   for (unsigned int i = 0; i < return_bits.size(); i++) {
      unsigned int byte_pos = i % 8;
      // Ordering of bit sets begins at the opposite direction
      current_byte[current_byte.size() - 1 - byte_pos] = return_bits[i];

      if (byte_pos == 7) {
         return_buffer.push_back( current_byte.to_ulong() );
         current_byte = std::bitset<8>( 0 );
      }
   }

   // Store the remaining bits
   if (return_bits.size() % 8 < 7) {
      return_buffer.push_back( current_byte.to_ulong() );
   }

   return_buffer.push_back( current_byte.to_ulong() );

   return return_buffer;
}
