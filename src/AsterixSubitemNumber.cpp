/**
 * @file AsterixSubitemNumber.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 6 Nov 2017
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

#include "AsterixSubitemNumber.h"

#include <bitset>
#include <cmath>
#include <iostream>

AsterixSubitemNumber::AsterixSubitemNumber( int length,
   std::shared_ptr<ItemConverterBase> converter) :
   AsterixSubitemBase( length, converter ) {
}

AsterixSubitemNumber::~AsterixSubitemNumber() {
}

std::vector<bool> AsterixSubitemNumber::readBits( std::deque<char>& input_buffer,
   unsigned bit_position ) {
   //read length number of bits
   bool all_bytes_read = false;
   int bits_read = 0;
   std::vector<bool> result;

   // Read all bytes belonging to this item
   while (!all_bytes_read) {
      //convert the natural signed char to unsigned
      unsigned char byte = static_cast<unsigned char>( input_buffer.front() );
      input_buffer.pop_front();
      std::bitset<8> byte_bits( byte );

      // Temporary item to store the individual bits of this sub item
      std::vector<bool> sub_result;
      for( unsigned short i = (bit_position % 8); i < byte_bits.size(); i++ ) {
         sub_result.push_back( byte_bits[byte_bits.size() - 1 - i] );
         bits_read++;

         // In case all bits of this item have been read, terminate further reading
         if( bits_read >= length ) {

            // In case not all bits of the current byte have been processed, write them back for
            // further processing
            if( /*bits_read % 8 != 0*/i < byte_bits.size() - 1 ) {
               input_buffer.push_front( byte_bits.to_ulong() );
            }

            all_bytes_read = true;
            break;
         }
      }

      // reset the starting position since it is only of relevance while reading the first byte
      bit_position = 0;

      // Add the sub results in reverse order to the results
      for( unsigned short i = 0; i < sub_result.size(); i++ ) {
         result.push_back( sub_result.at( i ) );
      }
   }

   return result;
}

long AsterixSubitemNumber::getRawValue(std::vector<bool> result) {
   long int raw_value = 0;
   for( unsigned short i = 0; i < result.size(); i++ ) {
      raw_value = (raw_value << 1) + (result.at( i ) ? 1 : 0);
   }
   return raw_value;
}

std::string AsterixSubitemNumber::getConvertedValue( char* value, unsigned int value_length ) {
   return converter->fromExternal( value, (int) std::ceil( length / 8.0 ) );
}

std::vector<char> AsterixSubitemNumber::encode(std::string value) {
   uint64_t raw_value = converter->toExternal( value, length );
   unsigned short num_bytes = length / 8;
   if( (length % 8) != 0 ) {
      num_bytes++;
   }
   //      num_bytes = num_bytes > 0 ? num_bytes : 1;
   std::vector<char> item = std::vector<char>( num_bytes, 0 );
   for( int i = num_bytes; i > 0; i-- ) {
      unsigned char byte_value = ((raw_value >> ((num_bytes - i) * 8)) & 0xFF);
      item[i - 1] = byte_value;
   }
   return item;
}
