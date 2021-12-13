/**
 * @file AsterixItemFixedLength.h
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
 * Implementation of the Asterix item with fixed length. This class provides the method for reading
 * the item and returning the bytes belonging to this item.
 */

#ifndef ASTERIXITEMFIXEDLENGTH_H_
#define ASTERIXITEMFIXEDLENGTH_H_

#include "AsterixItem.h"

class AsterixItemFixedLength: public AsterixItem {
private:

public:
   AsterixItemFixedLength( std::string name, int l );
   virtual ~AsterixItemFixedLength();

   /**
    * Read 'length' bytes from the input buffer. After calling this method the input buffer will be
    * reduced by the bytes read. The returned new buffer can be passed to the decoding function.
    *
    * @param buffer The input buffer to read the bytes belonging to this item from
    * @return a new buffer which is filled only with the bytes belonging to this item.
    * @throw None
    */
   virtual std::deque<char> readItem(std::deque<char>& buffer) override;

};

#endif /* ASTERIXITEMFIXEDLENGTH_H_ */
