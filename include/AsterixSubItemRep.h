/**
 * @file AsterixSubItemRep.h
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
 * Class representing a repetitive sub item. Like the regular repetitive item, this one has the
 * first byte denominate the number of repetitions.
 */
#ifndef ASTERIXSUBITEMREP_H_
#define ASTERIXSUBITEMREP_H_

#include "AsterixSubitemBase.h"
#include "AsterixCommonDef.h"

#include <map>

class AsterixSubItemRep: public AsterixSubitemBase {
private:
   // List of sub items contained within this repetetive item
   subitem_map_t subitems;

   // printable list of decided values of all subitems present
   std::map<std::string, std::string> unrolled_values;
   unsigned short repetition_factor;

public:

   /*(
    * Construct a new repetitive sub item with the length indicating the length without the
    * repetition factor.
    *
    * @param length in bits specifies the length of the repeated subfield. The first byte which gives the
    * number of repetitions shall not be included in this number
    */
   AsterixSubItemRep( int length,
      std::function<std::string( char*, unsigned int )> converterFunction );

   AsterixSubItemRep( int length,
      std::function<std::string( char*, unsigned int, double& dest_buffer )> converterFunction );

   AsterixSubItemRep( int length,
      std::function<std::string( char*, unsigned int, double& dest_buffer )> converterFunction,
      subitem_map_t subitem_list );

   virtual ~AsterixSubItemRep();

   /**
    * Decode the item based on the input buffer given. All bits needed for this item shall be
    * removed from the input buffer.
    *
    * @param input_buffer the buffer to read all bits required for this item from.
    * @param bit_bosition the position within the first byte at which this sub items starts
    * @throw No throw
    */
   virtual void decode( std::deque<char>& input_buffer, unsigned bit_position = 0 ) override;

   /**
    * Encode the content of this item into a byte stream.
    *
    * @return the bytes comprising this item
    * @throw Not yet decided
    */
   virtual std::vector<char> encode() override;

   /**
    * Get the encoded value in string representation.
    *
    * @return the encoded value as string
    * @throw No throw
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

#endif /* ASTERIXSUBITEMREP_H_ */
