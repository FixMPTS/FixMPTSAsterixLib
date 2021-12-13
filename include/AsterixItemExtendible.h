/**
 * @file AsterixItemExtendible.h
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
 * This class represents the Extensible item in Asterix. The goal of an extensible item is to not
 * have to know the length of the item beforehand. Instead the length is determined during the
 * decoding/ encoding process. For this the least significant bit ( at position 0 ) is set to one,
 * in case there is an additional extent of one byte.
 *
 */
#ifndef ASTERIXITEMEXTENDIBLE_H_
#define ASTERIXITEMEXTENDIBLE_H_

#include "AsterixItem.h"

class AsterixItemExtendible: public AsterixItem {
private:
   // Number of repeated bytes
   unsigned int repeated_length;

public:

   /**
    * Construct an extensible Asterix item. The number of bytes after which the decision is made
    * whether another set of bytes are present or not, can be configured.
    * Note: It is expected that all extends will have the same configurable length in bytes.
    *
    * @param name the name of the item. This name is used for identification only
    * @param length the length in bytes after which the FX bit is expected. All extends will be
    * of *length* bytes size.
    */
   AsterixItemExtendible( std::string name, unsigned length );
   virtual ~AsterixItemExtendible();

   /**
    * Read all bytes from the input buffer belonging to this item. The read bytes can than be
    * passed to the decoding procedure.
    *
    * @param buffer The input buffer to read from
    * @return a buffer containing only the bytes for this item.
    * @throw None
    */
   virtual std::deque<char> readItem(std::deque<char>& buffer) override;
};

#endif /* ASTERIXITEMEXTENDIBLE_H_ */
