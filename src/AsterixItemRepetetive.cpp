/**
 * @file AsterixItemRepetetive.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 20 Mar 2016
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
 * See description of header file
 */
#include "AsterixItemRepetetive.h"
#include "BinaryHelper.h"

AsterixItemRepetetive::AsterixItemRepetetive( std::string name, unsigned length ) :
   AsterixItem( name, length ) {
   item_length = length;
   repetition_factor = 0;
}

AsterixItemRepetetive::~AsterixItemRepetetive(){
}

std::deque<char> AsterixItemRepetetive::readItem( std::deque<char>& buffer ){
   std::deque<char> return_buffer;
   if( buffer.size() < (unsigned int) (1 + getItemLength()) ) {
      return return_buffer; // Item is too short
   }

   // Read the repetition factor
   repetition_factor = charToULIntBE( &buffer.front( ), 1 );

   return_buffer.push_back( buffer.front() );
   buffer.pop_front( );

   setItemLength( 1 + (repetition_factor * item_length) );

   // Read all bytes and store them in the output buffer
   for( unsigned int i = 0; i < ( repetition_factor * item_length ); i++){
	   return_buffer.push_back( buffer.front() );
	   buffer.pop_front();
   }

   return return_buffer;
}

unsigned int AsterixItemRepetetive::getRepetitionFactor() {
	return repetition_factor;
}
