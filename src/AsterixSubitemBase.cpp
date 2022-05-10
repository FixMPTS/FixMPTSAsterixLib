/**
 * @file AsterixSubitemBase.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
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
 * See .h file for more information
 */

//project includes
#include "AsterixSubitemBase.h"

//general includes
#include <bitset>
#include <cmath>

AsterixSubitemBase::AsterixSubitemBase(int length, std::shared_ptr<ItemConverterBase> converter) :
   raw_value( nullptr ), length( length ), converter( converter ) {
   raw_value_length = (unsigned int) std::ceil( (length - 0.5) / 8.0 );
}

//AsterixSubitemBase::AsterixSubitemBase( int length,
///   std::function<std::string( char*, unsigned int, double& dest_buffer )> converterFunction ) :
//   raw_value( nullptr ), length( length ) {
//   simple_converter = nullptr;
//   double_conveter = converterFunction;
//   raw_value_length = (unsigned int) std::ceil( length / 8.0 );
//}


AsterixSubitemBase::~AsterixSubitemBase(){
   if( raw_value != nullptr ) {
      delete raw_value;
   }
}

void AsterixSubitemBase::decode(std::deque<char>& input_buffer, unsigned bit_position) {

}

int AsterixSubitemBase::getLength(){
   return length;
}

std::string AsterixSubitemBase::getValue() {
   return encoded_value;
}

std::vector<char> AsterixSubitemBase::encode() {
   return std::vector<char>();
}
