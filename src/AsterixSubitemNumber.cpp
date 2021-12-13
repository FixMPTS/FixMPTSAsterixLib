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

AsterixSubitemNumber::AsterixSubitemNumber( int length,
   std::function<std::string( char*, unsigned int )> converterFunction ) :
   AsterixSubitemBase( length, converterFunction ) {
}

AsterixSubitemNumber::AsterixSubitemNumber( int length,
   std::function<std::string( char*, unsigned int, double& dest_buffer )> converterFunction ) :
   AsterixSubitemBase( length, converterFunction ) {
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
   std::string return_value;

   //store the decoded value in the corresponding string variable
   /* To do this we unfortunately need to check all converter function pointers until the one
    * which is not zero is found. At the moment there is no better way to store converter functions
    * with different signatures. It would be nice to have only one member variable in which the
    * call able object is stored, independent of the return type or the signature.
    */

   if( simple_converter != nullptr ) {
      return_value = simple_converter( value, value_length );
   } else if( double_conveter != nullptr ) {
      double converted_value;
      return_value = double_conveter( value, (int) std::ceil( length / 8.0 ), converted_value );
   } else {
      return_value = std::string( value ); // Default convert
   }

   return return_value;
}

std::vector<char> AsterixSubitemNumber::encode() {
   return AsterixSubitemBase::encode();
}
