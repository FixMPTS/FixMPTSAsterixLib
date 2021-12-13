/**
 * @file AsterixSubitemSigned.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 18 Oct 2017
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

#include "AsterixSubitemSigned.h"

#include <string>
#include <cstring>

AsterixSubitemSigned::AsterixSubitemSigned( int length,
   std::function<std::string( char*, unsigned int )> converterFunction ) :
   AsterixSubitemNumber( length, converterFunction ) {
}

AsterixSubitemSigned::AsterixSubitemSigned( int length,
   std::function<std::string( char*, unsigned int, double& dest_buffer )> converterFunction ) :
   AsterixSubitemNumber( length, converterFunction ) {
}

AsterixSubitemSigned::~AsterixSubitemSigned() {
}


void AsterixSubitemSigned::decode( std::deque<char>& input_buffer, unsigned bit_position ) {
   std::vector<bool> result = readBits( input_buffer, bit_position );

   // If the most significant bit is set, the two's complement needs to be calculated
   bool negative = false;
   if( result.front() ) {
      result.flip(); // flip all bits
      negative = true;
   }

   //convert the bits, with correct endianes, to long for better access
   long bit_value = getRawValue( result );

   if (negative) {
      // add one
      bit_value += 1;
      bit_value = 0 - bit_value;
   }

   std::string value_string = std::to_string( bit_value );
   raw_value = new char[value_string.length() + 1];
   //raw_value = (char*) std::to_string( bit_value ).c_str();
   std::strcpy( raw_value, value_string.c_str() );

   encoded_value = getConvertedValue( raw_value, raw_value_length );
}
