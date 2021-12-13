/**
 * @file UnsignedDoubleConverter.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 5 Feb 2018
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

#include <math.h>
#include <bitset>

#include "UnsignedDoubleConverter.h"

UnsignedDoubleConverter::UnsignedDoubleConverter() {
}

UnsignedDoubleConverter::~UnsignedDoubleConverter() {
}

// Set of Circle/Degree converter
std::string UnsignedDoubleConverter::circleSegment8Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted / pow( 2, 8 )) * 360.0 );
}

std::string UnsignedDoubleConverter::circleSegment16Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted / pow( 2, 16 )) * 360.0 );
}

std::string UnsignedDoubleConverter::direction13Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (360.0 / pow( 2, 13 ) * value_converted) );
}

std::string UnsignedDoubleConverter::direction14Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (360.0 / pow( 2, 14 ) * value_converted) );
}

std::string UnsignedDoubleConverter::direction16Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (360.0 / pow( 2, 16 ) * value_converted) );
}

std::string UnsignedDoubleConverter::direction128th( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * (360.0 / 128.0) );
}

std::string UnsignedDoubleConverter::directionHalfCircle8Bit( char* value,
   unsigned int value_length, double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted * (180 / pow( 2, 8 ))) );
}

// Fraction Converter
std::string UnsignedDoubleConverter::fraction4th( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 4.0 );
}

std::string UnsignedDoubleConverter::fraction10th( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 0.1 );
}

std::string UnsignedDoubleConverter::fraction32nd( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 32.0 );
}

std::string UnsignedDoubleConverter::fraction100th( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 0.01 );
}

std::string UnsignedDoubleConverter::fraction128th( char* value, unsigned int value_length ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 128.0 );
}

std::string UnsignedDoubleConverter::fraction360th( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 360.0 );
}

std::string UnsignedDoubleConverter::fraction30Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / pow( 2, 30 ) );
}

// Heading related converter
std::string UnsignedDoubleConverter::selectedHeading( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 0.703125 );
}

std::string UnsignedDoubleConverter::groundTrackHeading( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 2.8125 );
}

// Speed related converter
std::string UnsignedDoubleConverter::speedNMToKt( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted * pow( 2, -14 )) * 3600.0 );
}

std::string UnsignedDoubleConverter::speedVelToKt( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted * 0.125) );
}

std::string UnsignedDoubleConverter::airspeed14Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   std::bitset<16> converted_value( value_converted );

   if( !converted_value.test( converted_value.size() - 1 ) ) { // IM not set
      return std::to_string( (converted_value.to_ulong() * pow( 2, -14 )) * 3600.0 );
   } else {
      converted_value[converted_value.size() - 1] = 0; // Reset the IM Bit
      return std::to_string( (converted_value.to_ulong() * 0.001) );
   }
}

// Misc converter
std::string UnsignedDoubleConverter::fact10( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 10.0 );
}

std::string UnsignedDoubleConverter::eRange( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted * (500.0 / pow( 2, 16 ))) );
}

