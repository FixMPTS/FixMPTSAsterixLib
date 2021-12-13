/**
 * @file AsterixItemVariableLength.h
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
 * This class provides the implementation of Asterix items with variable length. Meaning that as long
 * as the FX bit for the currently read input buffer is set to one, the next byte will be read as well.
 */

#ifndef ASTERIXITEMVARIABLELENGTH_H_
#define ASTERIXITEMVARIABLELENGTH_H_

#include "AsterixItem.h"

class AsterixItemVariableLength: public AsterixItem {
public:

   AsterixItemVariableLength( std::string name );
   virtual ~AsterixItemVariableLength();

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

#endif /* ASTERIXITEMVARIABLELENGTH_H_ */
