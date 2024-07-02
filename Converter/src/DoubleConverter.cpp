/**
 * @file DoubleConverter.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 4 Feb 2018
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

#include "DoubleConverter.h"

DoubleConverter::DoubleConverter() {
}

DoubleConverter::~DoubleConverter() {
}

// Set of Fraction converter
std::string DoubleConverter::fractionHalf( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long int value_converted = std::stoll( value );
   return std::to_string( value_converted * 0.5 );
}

std::string DoubleConverter::fraction4th( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long int value_converted = std::stoll( value );
   return std::to_string( (value_converted / 4.0) );
}

std::string DoubleConverter::fraction8th( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long int value_converted = std::stoll( value );
   return std::to_string( (value_converted / 8.0) );
}

std::string DoubleConverter::fraction16th( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted / 16.0) );
}

std::string DoubleConverter::fraction64th( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 64 );
}

std::string DoubleConverter::fraction100th(char *value, unsigned int value_length,
   double &dest_buffer) {
   long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( value_converted / 100.0 );
}

std::string DoubleConverter::fraction128th( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( value_converted / 128.0 );
}

std::string DoubleConverter::fraction256th( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 256.0 );
}

// Converter for devision with 10 to the power of x
std::string DoubleConverter::fraction10ToPower5( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long int value_converted = std::stoll( value );
   return std::to_string( value_converted * pow( 10, -5 ) );
}

std::string DoubleConverter::fraction10ToPower6( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoll( value );
   return std::to_string( value_converted * pow( 10, -6 ) );
}

// WGS 84 related converter
std::string DoubleConverter::WGS84resolution23Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( (180.0 / pow( 2, 23 )) * value_converted );
}

std::string DoubleConverter::WGS84resolution25Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( (180.0 / pow( 2, 25 )) * value_converted );
}

std::string DoubleConverter::WGS84resolution30Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( (180.0 / pow( 2, 30 )) * value_converted );
}

std::string DoubleConverter::WGS84resolution31Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( (180.0 / pow( 2, 31 )) * value_converted );
}
std::string DoubleConverter::WGS8490degResolution31Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( (90.0 / pow( 2, 31 )) * value_converted );
}

std::string DoubleConverter::WGS84AltQuarter( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );

   // Apply the LSB
   return std::to_string( value_converted * 0.25 );
}

// Misc converter
std::string DoubleConverter::groundVectorAcceleration(char *value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 0.012 );
}

std::string DoubleConverter::groundSpeedKt(char *value, unsigned int value_length,
   double &dest_buffer) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 0.22 );
}

std::string DoubleConverter::geoAltitudeFt( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long int value_converted = std::stoll( value );
   return std::to_string( value_converted * 6.25 );
}

std::string DoubleConverter::verticalRate( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 6.25 );
}

std::string DoubleConverter::factor015( char* value, unsigned int value_length,
   double& dest_buffer ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted * 0.15) );
}

std::string DoubleConverter::direction16Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long int value_converted = std::stoll( value );
   return std::to_string( (360.0 / (pow( 2, 16 ) / 2.0) * value_converted) );
}

std::string DoubleConverter::elevation16Bit( char* value, unsigned int value_length,
   double& dest_buffer ) {
   long int value_converted = std::stoll( value );
   return std::to_string( (180.0 / (pow( 2, 16 ) / 2.0) * value_converted) );
}
