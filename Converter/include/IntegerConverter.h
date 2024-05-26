/**
 * @file IntegerConverter.h
 * @author  Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 2 Feb 2018
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
 * Set of Asterix converter converting from and to values represented in Asterix as signed integer..
 *
 * NOTE! All names indication a size in bit (e.g. fraction10Bit ) have no bit constrained at the
 * input or output, but rather indicate that 2 to the power of X, in this case 10, will be used
 * for the conversion. The above example will result in the following conversion
 *
 * ' value / 2**10'
 *
 */

#ifndef INTEGERCONVERTER_H_
#define INTEGERCONVERTER_H_

#include <string>

class IntegerConverter {
public:
   IntegerConverter();
   virtual ~IntegerConverter();

   /**
    * Convert the value to quarter of what is has been before.
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted value
    * @throw None
    */
   static std::string lBitsToQuarter( char* value, unsigned int value_length );

   /**
    * Convert the value to FL with a resolution of 25ft
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted FL
    * @throw None
    */
   static std::string alt25ft( char* value, unsigned int value_length );

   /**
    * Convert the value to altitude with a 10ft resolution
    *
    * @param value The value to be converted to the correct flight level with 10 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted FL
    * @throw None
    */
   static std::string alt10ft(char *value, unsigned int value_length);

};

#endif /* INTEGERCONVERTER_H_ */
