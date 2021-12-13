/**
 * @file AsterixSubitemBytes.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 5 Mar 2018
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

#include "AsterixSubitemBytes.h"

#include <bitset>
#include <string>
#include <cstring>
#include <cmath>

AsterixSubitemBytes::AsterixSubitemBytes( int length,
   std::function<std::string( char*, unsigned int )> converterFunction ) :
   AsterixSubitemBase( length, converterFunction ) {
}

AsterixSubitemBytes::AsterixSubitemBytes( int length,
   std::function<std::string( char*, unsigned int, double& dest_buffer )> converterFunction ) :
   AsterixSubitemBase( length, converterFunction ) {
}

AsterixSubitemBytes::~AsterixSubitemBytes() {
}

void AsterixSubitemBytes::decode( std::deque<char>& input_buffer, unsigned bit_position ) {
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
         result.push_back( byte_bits[byte_bits.size() - 1 - i] );
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
   }

   // convert the bool array to the corresponding number. The bit are ordered in the wrong order
   std::bitset<8> byte_value;
   std::string value_string;
   for( unsigned short i = 0; i < result.size(); i++ ) {
      byte_value[byte_value.size() - 1 - (i % 8)] = result.at( i );

      if( i > 0 && i % 8 == 0 ) {
         value_string += (char) byte_value.to_ulong();
         byte_value.reset();
      }
   }
   if( result.size() % 8 == 0 ) {
      value_string += (char) byte_value.to_ulong();
   }

   // save the original value according to the data type provided by the parent class
   raw_value = new char[value_string.length() + 1];
   //raw_value = (char*) std::to_string( bit_value ).c_str();
   std::strcpy( raw_value, value_string.c_str() );

   encoded_value = value_string;
   if( simple_converter != nullptr ) {
      encoded_value = simple_converter( raw_value, raw_value_length );
   } else if( double_conveter != nullptr ) {
      double converted_value;
      encoded_value = double_conveter( raw_value, (int) std::ceil( length / 8.0 ),
         converted_value );
   } else {
      encoded_value = std::string( raw_value ); // Default convert
   }

}

