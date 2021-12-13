/**
 * @file AsterixItemCompoundLI.h
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
 * This class represents a compound item with an addition length indicator field right at the
 * beginning of the item. The first byte of the item is considered to be the length indicator field
 * and only after that the sub fspec is expected.
 */
#ifndef ASTERIXITEMCOMPOUNDLI_H_
#define ASTERIXITEMCOMPOUNDLI_H_

#include "AsterixItemCompound.h"

class AsterixItemCompoundLI: public AsterixItemCompound {
public:
   AsterixItemCompoundLI( std::string name, AsterixItemCompound::subUap_T sub_uap );
   virtual ~AsterixItemCompoundLI();

   /**
    * Read all bytes which comprise this item from the input buffer. All bytes used by this item
    * are removed from the input buffer,
    *
    * @param buffer the byte buffer from which to read the bytes of this item
    * @return a buffer containing just the bytes comprising this item
    * @throws Not yet decided
    */
   virtual std::deque<char> readItem(std::deque<char>& buffer) override;
};

#endif /* ASTERIXITEMCOMPOUNDLI_H_ */
