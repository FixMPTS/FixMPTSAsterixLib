/**
 * @file StringConverter.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 31 Jan 2018
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

#include <bitset>

#include "AsterixStdDefinitions.h"
#include "StringConverter.h"
#include "AsterixExceptions.h"

StringConverter::StringConverter() {
}

StringConverter::~StringConverter() {
}

std::string StringConverter::to6BitChar( char* value, unsigned int value_length,
   double& dest_buffer ) {

   unsigned long int value_converted = std::stoull( value );
   std::bitset<48> bin_id( value_converted );
   std::string return_str = "";


   for( unsigned int byte_pos = 0; byte_pos < (bin_id.size() / 6); byte_pos++ ) {
      std::bitset<6> character( bin_id.to_ulong() & 0x3f );
      bin_id >>= 6; // Shift by six bits which is the size of one character

      if( AIRCRAFT_ID_CHAR_MAP.find( character.to_ulong() ) != AIRCRAFT_ID_CHAR_MAP.end() ) {
         // Store in reverse order
         return_str = AIRCRAFT_ID_CHAR_MAP.at( character.to_ulong() ) + return_str;
      } else if( character.to_ulong() != 0 ) { // Not all bits might be set
         throw ConverterError( "StringConverter", std::to_string( value_converted ), "Not allowed character" );
      }
   }

   return return_str;
}

std::string StringConverter::toASCII( char* value, unsigned int value_length,
   double& dest_buffer ) {
   if( value == nullptr ) {
      return "Value is not a string";
   }
   return std::string( value );
}

std::string StringConverter::BitsToNATOtn19Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   std::bitset<19> bin_id( value_converted );
   std::string return_str = "";
   std::string raw_string = "";

   // First the three 3 bit characters since bit sets being ordered the other way round
   for( unsigned i = 0; i < 3; i++ ) {
      std::bitset<3> char_3( bin_id.to_ulong() & 0x07 );
      raw_string += NATO_ID_3BIT.at( char_3.to_ulong() );
      bin_id >>= 3;
   }

   for( unsigned i = 0; i < 2; i++ ) {
      std::bitset<5> char_5( bin_id.to_ulong() & 0x1f );
      raw_string += NATO_ID_5BIT.at( char_5.to_ulong() );
      bin_id >>= 5;
   }

   // Reverse the string to compensate for the bitset order
   for( auto s : raw_string ) {
      return_str = s + return_str;
   }

   return return_str;
}

