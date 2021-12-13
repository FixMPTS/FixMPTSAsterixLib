/**
 * @file AsterixItem.cpp
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
 * See .h file fore more details
 */

#include "AsterixItem.h"

AsterixItem::AsterixItem( std::string name ) :
   name( name ), length( 0 ) {
}

AsterixItem::~AsterixItem() {
   /*Nothing to do at the moment */
}

std::deque<char> AsterixItem::readItem( std::deque<char>& buffer ) {
   return std::deque<char>();
}

std::string AsterixItem::getName() {
   return name;
}

int AsterixItem::getItemLength() {
   return length;
}
