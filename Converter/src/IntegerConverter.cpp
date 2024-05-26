/**
 * @file IntegerConverter.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 2 Feb 2018
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

#include "IntegerConverter.h"

IntegerConverter::IntegerConverter() {
}

IntegerConverter::~IntegerConverter() {
}

std::string IntegerConverter::lBitsToQuarter( char* value, unsigned int value_length ) {
   long int value_converted = std::stoll( value );
   return std::to_string( (int) (value_converted / 4.0) );
}

std::string IntegerConverter::alt25ft( char* value, unsigned int value_length ) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (int) (value_converted * 25) );
}

std::string IntegerConverter::alt10ft(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (int) (value_converted * 10) );
}

