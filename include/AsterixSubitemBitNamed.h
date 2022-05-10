/**
 * @file AsterixSubitemBitNamed.h
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
 * Purpose of this class is to provide a mapping of an encoded unsigned integer value to a human
 * readable representation. Usually the length of this item is very small.
 */

#ifndef ASTERIXSUBITEMBITNAMED_H_
#define ASTERIXSUBITEMBITNAMED_H_

#include "AsterixSubitemBase.h"

#include <map>
#include <string>
#include <memory>

class AsterixSubitemBitNamed: public AsterixSubitemBase {
private:
   //List of integers being the decoded value and the corresponding name need for human readable printing.
   std::map<int, std::string> value_names;

public:
   typedef std::map<int, std::string> value_names_t;
   typedef std::pair<int, std::string> value_name_pair_t;

   /**
    * Initialise a new named sub item object by providing the converter function and names of the item.
    * The provided converter function must return a string and have an integer as parameter.
    *
    * @param length The length of the item in bits
    * @param converter_function The function to be called to convert the raw input to the required
    * unsigned integer output.
    * @param names A list of unsigned integers and their corresponding verbal representation
    * @throw None
    */
   AsterixSubitemBitNamed(int length, std::shared_ptr<ItemConverterBase> converter, value_names_t names);
   virtual ~AsterixSubitemBitNamed();

   /**
    * Read as many bits as required for this item. Convert those bytes to an unsigned number.
    *
    * @param input_buffer The buffer to read the bits from. The remaining bits are not touched but
    * the buffer will be reduced by the bits read.
    *
    * @param input_buffer The buffer to read the bits from
    * @param bit_position of this item within the first byte
    * @return None
    * @throw None
    */
   virtual void decode( std::deque<char>& input_buffer, unsigned bit_position = 0 ) override;
};

#endif /* ASTERIXSUBITEMBITNAMED_H_ */
