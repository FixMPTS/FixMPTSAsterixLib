/**
 * @file AsterixSubitemBase.h
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
 * Base class representing the sub items. Each Asterix item is described by one or more sub items.
 * These sub items also store the information on how to decoded the item. The raw as well as the
 * decoded item will be stored inside this object.
 */

#ifndef ASTERIXSUBITEMBASE_H_
#define ASTERIXSUBITEMBASE_H_

#include "ItemConverterBase.h"

//general includes
#include <string>
#include <vector>
//#include <functional>
#include <deque>
#include <memory>

class AsterixSubitemBase {
protected:
   //the decoded value as string
   std::string encoded_value;

   //The raw not decoded value
   char* raw_value;
   unsigned int raw_value_length;

   //Length of the item in bits
   int length;

   //Variables storing the converter functions to get the encoded value from the raw value
   //typedef std::function<std::string( char*, unsigned int )> simpleConverter_T;
   std::shared_ptr<ItemConverterBase> converter;

   // More complex converter function
   //std::function<std::string( char*, unsigned int, double& dest_buffer )> double_conveter;

public:
   AsterixSubitemBase() = delete;

   /**
    * Initialise a new sub item object with specified length in bits and corresponding converter
    * function. In this case the converter function will return a string with the encoded value,
    * taking as input an unsigned integer.
    *
    * @param length The length of the item in bits
    * @param converter_function The function to convert the raw value to the encoded one
    * @throw None
    */
   AsterixSubitemBase(int length, std::shared_ptr<ItemConverterBase> converter);

   /**
    * Initialise a new sub item object with specified length in bits and corresponding converter
    * function. In this case the converter function will return a string with the encoded value,
    * taking as input an unsigned integer and a destination buffer storing the decoded value as double.
    *
    * @param length The length of the item in bits
    * @param converter_function The function to convert the raw value to the encoded one
    * @throw None
    */
   //AsterixSubitemBase( int length,
   //   std::function<std::string( char*, unsigned int, double& dest_buffer )> converterFunction );

   virtual ~AsterixSubitemBase();

   /**
    * Decode the bits belonging to this sub item from the surrounding Asterix item. The remaining
    * bits will be put back into the input buffer.
    *
    * @param input_buffer The buffer to read the bits from
    * @throw None
    */
   virtual void decode(std::deque<char> &input_buffer, unsigned int bit_position = 0);

   /**
    * Encode the value of this item and return the bits representing this item as byte.
    *
    * @return encoded the bits representing this item
    * @throw None
    */
   virtual std::vector<char> encode();

   /**
    * @return the encoded value as string
    * @throw None
    */
   virtual std::string getValue();

   /**
    * Get the length of the item.
    *
    * @return the length in bits used up by this item
    * @throw No throw
    */
   int getLength();
};

#endif /* ASTERIXSUBITEMBASE_H_ */
