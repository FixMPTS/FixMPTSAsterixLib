/**
 * @file AsterixSubitemNumber.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 6 Nov 2017
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
 * Base class for all signed and unsigned number sub items. This class will provide the basic
 * de/encoding for such items.
 */

#ifndef ASTERIXSUBITEMNUMBER_H_
#define ASTERIXSUBITEMNUMBER_H_

#include "AsterixSubitemBase.h"

class AsterixSubitemNumber: public AsterixSubitemBase {
protected:
   /**
    * Read all bits belonging to this item from the input buffer.
    *
    * @param input_buffer the bytes buffer to read the value from
    * @param bit_position the position of the first bit within the first byte which belongs to the item
    * @return bit vector containing the bits of this item
    * @throws No throw
    */
   std::vector<bool> readBits(std::deque<char> &input_buffer, unsigned int bit_position);

   /**
    * Take the bits from the input vector and convert them into a signed number value.
    *
    * @param result the bit representation of the value to be converted
    * @return the signed interpretation of the given value
    * @throws No throw
    */
   long getRawValue(std::vector<bool> result);

   /**
    * Apply the defined converter to the given value and return the converted value as string
    *
    * @param value the value to be converted
    * @return the string representation of the converted value
    * @throws No throw
    */
   std::string getConvertedValue( char* value, unsigned int value_length );

public:
   AsterixSubitemNumber(int length, std::shared_ptr<ItemConverterBase> converter);
   virtual ~AsterixSubitemNumber();

   virtual void decode( std::deque<char>& input_buffer, unsigned bit_position = 0 ) override = 0;

   /**
    * Encode the value of this item and return the bits representing this item as byte.
    *
    * @return encoded the bits representing this item
    * @throw None
    */
   virtual std::vector<char> encode() override;
};

#endif /* ASTERIXSUBITEMNUMBER_H_ */
