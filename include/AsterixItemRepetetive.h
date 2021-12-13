/**
 * @file AsterixItemRepetetive.h
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
 * Representation of a repetitive Asterix item. This item consists of one byte specifying the repetition
 * of #bytes specified for this item.
 */
#ifndef ASTERIXITEMREPETETIVE_H_
#define ASTERIXITEMREPETETIVE_H_

#include "AsterixItemExtendible.h"

class AsterixItemRepetetive: public AsterixItem {
private:
   // Number of bytes that are repeated
   unsigned int item_length;

   unsigned int repetition_factor;

public:

   /**
    * Construct a new repetitive item consisting of items of *length* bytes.
    *
    * @param name the name of the item
    * @param length the number of bytes of the item which is repeated.
    * @throws Not yet decided
    */
   AsterixItemRepetetive( std::string name, unsigned length );
   virtual ~AsterixItemRepetetive();

   /**
    * Read all bytes from the input buffer belonging to this item. The read bytes can than be
    * passed to the decoding procedure.
    *
    * @param buffer The input buffer to read from
    * @return a buffer containing only the bytes for this item.
    * @throw None
    */
   virtual std::deque<char> readItem(std::deque<char>& buffer) override;

   unsigned int getRepetitionFactor();
};

#endif /* ASTERIXITEMREPETETIVE_H_ */
