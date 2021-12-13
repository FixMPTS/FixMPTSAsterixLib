/**
 * @file AsterixItemVariableLengthFlex.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 29 Oct 2017
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
 * Representation of an Asterix Item which is a variable length item but with the first subitem
 * having a different size and thus the FX bit is at a different location.
 */

#ifndef ASTERIXITEMVARIABLELENGTHFLEX_H_
#define ASTERIXITEMVARIABLELENGTHFLEX_H_

#include "AsterixItemVariableLength.h"

class AsterixItemVariableLengthFlex: public AsterixItemVariableLength {
private:
   // Number of bytes after which the first FX bit is to be expected. It is expected to be the last
   // bit in the length_of_first_item th byte
   unsigned int length_of_first_item;

   AsterixItemVariableLengthFlex() = delete;

public:
   /**
    * Construct the AsterixItemVariableLengthFlex Asterix Item.
    *
    * @param name the name of the item
    * @param length the length in byte of the first item. After that all items are expected of size one byte
    */
   AsterixItemVariableLengthFlex( std::string name, unsigned int length );

   virtual ~AsterixItemVariableLengthFlex();

   /**
    * Read bytes from the input buffer and store them in the  output buffer as long as the FX bit is
    * set to one. After reading the input buffer is reduced by the bytes read.
    *
    * @param buffer The input buffer to read the bytes from
    * @return the new buffer containing only the bytes belonging to this item
    * @throw None
    */
   virtual std::deque<char> readItem(std::deque<char>& buffer) override;
};

#endif /* ASTERIXITEMVARIABLELENGTHFLEX_H_ */
