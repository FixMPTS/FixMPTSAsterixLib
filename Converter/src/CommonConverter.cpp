/**
 * @file CommonConverter.cpp
 * @author  Felix Kreuter <felix@fixmpts.org>
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

#include "CommonConverter.h"
namespace CommonConverter {
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////     NoneConverter     ///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
NoneConverter::NoneConverter() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> NoneConverter::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<NoneConverter>( NoneConverter() );
   return instance;
}
uint64_t NoneConverter::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string NoneConverter::fromExternal(char *value, unsigned int value_length) {
   long int value_converted = std::stoll( value );
   return std::to_string( value_converted );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////     NoneConverterBuffer     ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
NoneConverterBuffer::NoneConverterBuffer() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> NoneConverterBuffer::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<NoneConverterBuffer>( NoneConverterBuffer() );
   return instance;
}
uint64_t NoneConverterBuffer::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string NoneConverterBuffer::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = reinterpret_cast<unsigned long int>( &value );
   return std::to_string( value_converted );
}
}
