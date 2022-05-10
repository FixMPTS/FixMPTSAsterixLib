/**
 * @file AsterixSubitemCompound.h
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
 * Representation of a compound sub item. The item is expected to start with the sub fspec before
 * the actual content.
 */
#ifndef ASTERIXSUBITEMCOMPOUND_H_
#define ASTERIXSUBITEMCOMPOUND_H_

#include "AsterixSubitemBase.h"
#include "AsterixCommonDef.h"

#include <map>

class AsterixSubitemCompound: public AsterixSubitemBase {
private:
   // List of sub items contained within the compound item
   subitem_map_t subitems;

   // Printable list of decoded values of this item
   std::map<std::string, std::string> unrolled_values;

public:

   /**
    * Construct a new compound sub item.
    *
    * @param length the length without the starting fspec in bits. Not used for this item
    * @param converter function used to translate the raw value with the correct resolution
    */
   AsterixSubitemCompound(int length, std::shared_ptr<ItemConverterBase> converter, subitem_map_t subitem_list =
      subitem_map_t());

   virtual ~AsterixSubitemCompound();

   /**
    * Decode the item and remove all completely used up bytes from the input buffer
    *
    * @param input_buffer the bytes to read the bits of the item from
    * @param bit_position the position within the first byte at which the item starts
    * @throws Not yet decided
    */
   virtual void decode( std::deque<char>& input_buffer, unsigned bit_position = 0 ) override;

   /**
    * Encode the content of this item into a byte stream
    *
    * @return the raw bytes representing this item
    * @throws Not yet decided
    */
   virtual std::vector<char> encode() override;

   /**
    * Get the string representation of the decoded value in the correct resolution and unit.
    *
    * @return a string representing the value of the item. If the item has not been decoded an empty
    * string will be returned.
    * @throws No throw
    */
   virtual std::string getValue() override;

   /***
    * Get all encoded values for the compound sub item. Like for the AsterixItem this function can
    * only be called after decoding has finished.
    *
    * @return a map of item name and endcoded value
    * @throws Not yet decided
    */
   std::map<std::string, std::string> gerUnrolledValues();
};

#endif /* ASTERIXSUBITEMCOMPOUND_H_ */
