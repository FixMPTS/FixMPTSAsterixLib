/**
 * @file AsterixSubitemCompound.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 1 Aug 2017
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
 * See H file for more informations
 */

#include "AsterixSubitemCompound.h"

#include <bitset>

AsterixSubitemCompound::AsterixSubitemCompound(int length, std::shared_ptr<ItemConverterBase> converter,
   subitem_map_t subitem_list ) :
   AsterixSubitemBase( length, converter ) {

   subitems = subitem_list;
}

AsterixSubitemCompound::~AsterixSubitemCompound(){
}

void AsterixSubitemCompound::decode(std::deque<char>& input_buffer, unsigned bit_position) {
   // Iterate over all sub items and delegate the decoding

   for (auto item : subitems) {

      // Delegate the decoding to the sub item type. This should also remove all completely read bytes
      item.second->decode( input_buffer, bit_position );
      std::string value = item.second->getValue();

      // Save the encoded value
      unrolled_values.insert( std::make_pair( item.first, value ) );

      bit_position += item.second->getLength();
      bit_position = bit_position % 8; // Ensure offset stayes within 8 bit boundary
   }
}

std::vector<char> AsterixSubitemCompound::encode(std::string value) {
   return std::vector<char>( );
}

std::string AsterixSubitemCompound::getValue(){
   return "Compound Item only list of items can be returned";
}

std::map<std::string, std::string> AsterixSubitemCompound::gerUnrolledValues() {
   return unrolled_values;
}
