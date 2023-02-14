/**
 * @file AsterixSubitemBitNamed.cpp
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
 * see .h file for more information
 */

//project includes
#include "AsterixSubitemBitNamed.h"

//general includes
#include <bitset>
#include <sstream>
#include <iomanip>
#include <cstring>

AsterixSubitemBitNamed::AsterixSubitemBitNamed( int length,
   std::shared_ptr<ItemConverterBase> converter,
   value_names_t names) :
   AsterixSubitemBase( length, converter ), value_names( names ) {
}

AsterixSubitemBitNamed::~AsterixSubitemBitNamed() {
}

void AsterixSubitemBitNamed::decode( std::deque<char>& input_buffer, unsigned bit_position ) {
   std::vector<bool>* result = new std::vector<bool>();

   //The bits are decoded in byte steps
   unsigned char byte = static_cast<unsigned char>( input_buffer.front() );
   input_buffer.pop_front();

   std::bitset<8> byte_bits( byte );

   //use only the bits required for this item and put the remaining bits back into the queue
   std::vector<bool> sub_result;

   // Keep track at which position the sub item is located
   unsigned start = (bit_position % 8);

   // Read all bytes of the sub item
   for (unsigned short i = start; (i < byte_bits.size() && i < length + start); i++) {
      sub_result.push_back( byte_bits[byte_bits.size() - 1 - i] );
   }

   byte_bits = std::bitset<8>( byte_bits.to_ullong() );

   // If this sub item is not the last within the current byte, write back the byte for further deciding
   if ((length + start) < byte_bits.size()) {
      input_buffer.push_front( byte_bits.to_ulong() );
   }

   // Reverse order of read bits for further processing
   for (unsigned short i = 0; i < sub_result.size(); i++) {
      result->push_back( sub_result.at( i ) );
   }

   // convert the bool array to the corresponding number. The bit are ordered in the wrong order
   unsigned int bit_value = 0;
   for (unsigned short i = 0; i < result->size(); i++) {
      bit_value = (bit_value << 1) + (result->at( i ) ? 1 : 0);
   }

   // save the original value according to the data type provided by the parent class
   std::string value_string = std::to_string( bit_value );
   raw_value = new char[value_string.length() + 1];
   //raw_value = (char*) std::to_string( bit_value ).c_str();
   std::strcpy( raw_value, value_string.c_str() );

   encoded_value = std::to_string( bit_value );
}

std::vector<char> AsterixSubitemBitNamed::encode(std::string value) {
   uint64_t raw_value = converter->toExternal( value, length );
   unsigned short num_bytes = length / 8;
   num_bytes = num_bytes > 0 ? num_bytes : 1;
   std::vector<char> item = std::vector<char>( num_bytes, 0 );
   for( int i = num_bytes; i > 0; i-- ) {
      unsigned char byte_value = ((raw_value >> ((num_bytes - i) * 8)) & 0xFF);
      item[i - 1] = byte_value;
   }
   return item;
}
