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

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////     LBitsToQuarter     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
IntegerConverter::LBitsToQuarter::LBitsToQuarter() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> IntegerConverter::LBitsToQuarter::get() {
   static std::shared_ptr<LBitsToQuarter> instance = std::make_shared<LBitsToQuarter>( LBitsToQuarter() );
   return instance;
}
uint64_t IntegerConverter::LBitsToQuarter::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string IntegerConverter::LBitsToQuarter::fromExternal(char *value, unsigned int value_length) {
   long int value_converted = std::stoll( value );
   return std::to_string( (int) (value_converted / 4.0) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////     Alt25ft     ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
IntegerConverter::Alt25ft::Alt25ft() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> IntegerConverter::Alt25ft::get() {
   static std::shared_ptr<Alt25ft> instance = std::make_shared<Alt25ft>( Alt25ft() );
   return instance;
}
uint64_t IntegerConverter::Alt25ft::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string IntegerConverter::Alt25ft::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (int) (value_converted * 25) );
}

