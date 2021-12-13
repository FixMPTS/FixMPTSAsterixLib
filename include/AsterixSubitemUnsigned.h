/**
 * @file AsterixSubitemUnsigned.h
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
 * Asterix sub item implementation where the item consists only of one unsigned integer value.
 */

#ifndef ASTERIXSUBITEMUNSIGNED_H_
#define ASTERIXSUBITEMUNSIGNED_H_

#include "AsterixSubitemNumber.h"

class AsterixSubitemUnsigned: public AsterixSubitemNumber {
public:
   /**
    * Initialise a new Asterix sub item object of length bits where the raw value is converted to the
    * internal value by calling the converter function.
    *
    * @param length The length of the sub item in bits
    * @converter_function The converter function returning the converted value as string taking as
    * input an unsigned long integer.
    * @return None
    * @throw None
    */
   AsterixSubitemUnsigned( int length,
      std::function<std::string( char*, unsigned int )> converterFunction );

   /**
    * Initialise a new Asterix sub item object of length bits where the raw value is converted to the
    * internal value by calling the converter function.
    *
    * @param length The length of the sub item in bits
    * @converter_function The converter function returning the converted value as string taking as
    * input an unsigned long integer and an output buffer of doubles.
    * @return None
    * @throw None
    */
   AsterixSubitemUnsigned( int length,
      std::function<std::string( char*, unsigned int, double& dest_buffer )> converterFunction );

   virtual ~AsterixSubitemUnsigned();

   /**
    * Read all bits needed from the input buffer and decode them to the required unsigned value.
    *
    * @param input_buffer The buffer to read the bits from
    * @param bit_position position within the first to be read byte at which this sub item starts
    * @return None
    * @throw None
    */
   virtual void decode( std::deque<char>& input_buffer, unsigned bit_position = 0 ) override;
};

#endif /* ASTERIXSUBITEMUNSIGNED_H_ */
