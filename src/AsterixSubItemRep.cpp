/**
 * @file AsterixSubItemRep.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 27 Jul 2017
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
#include "AsterixSubItemRep.h"
#include "BinaryHelper.h"

AsterixSubItemRep::AsterixSubItemRep( int length,
   std::function<std::string( char*, unsigned int )> converterFunction ) :
   AsterixSubitemBase( length, converterFunction ) {
   repetition_factor = 0;
}

AsterixSubItemRep::AsterixSubItemRep( int length,
   std::function<std::string( char*, unsigned int, double& dest_buffer )> converterFunction ) :
   AsterixSubitemBase( length, converterFunction ) {
   repetition_factor = 0;
}

AsterixSubItemRep::AsterixSubItemRep( int length,
   std::function<std::string( char*, unsigned int, double& dest_buffer )> converterFunction,
   subitem_map_t subitem_list ) :
   AsterixSubitemBase( length, converterFunction ) {

   subitems = subitem_list;
   repetition_factor = 0;
}

AsterixSubItemRep::~AsterixSubItemRep() {
}

void AsterixSubItemRep::decode( std::deque<char>& input_buffer, unsigned bit_position ) {
   // The repetition factor is supposed to be the first item
   repetition_factor = charToULIntBE( &input_buffer.front(), 1 );
   input_buffer.pop_front();

   // Duplicate the sub item list according to the repetition factor
   subitem_map_t old_subitems = subitems;
   subitems.clear();
   for( unsigned short pos = 0; pos < repetition_factor; pos++ ) {
      for( auto item : old_subitems ) {
         std::string new_name = item.first;
         new_name += ".";
         new_name += std::to_string( pos );
         subitem_t new_item( new_name, item.second );
         subitems.push_back( new_item );
      }
   }

   // Go though the buffer and read all items
   for( auto item : subitems ) {

      // Delegate the decoding to the sub item type. This should also remove all completely read bytes
      item.second->decode( input_buffer, bit_position );
      std::string value = item.second->getValue();

      // Save the encoded value
      unrolled_values.insert( std::make_pair( item.first, value ) );

      bit_position += item.second->getLength();
      bit_position = bit_position % 8; // Ensure offset stayes within 8 bit boundary
   }
}

std::vector<char> AsterixSubItemRep::encode() {
   return {'N','o','t',' ', 'I','m','p','l','e','m','n','t','e','d'};
}

std::string AsterixSubItemRep::getValue() {
   return "Not implemented";
}

std::map<std::string, std::string> AsterixSubItemRep::gerUnrolledValues() {
   return unrolled_values;
}
