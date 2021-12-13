/**
 * @file BinaryHelper.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 27 Apr 2021
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
 * Helper header file providing some means to convert between binary data and its representation format
 */
#ifndef BINARYHELPER_H_
#define BINARYHELPER_H_

#include <string.h>
#include <algorithm>
#include <iostream>

/**
 * Convert a eight bit char to an unsigned integer using big endian encoding.
 *
 * @param value The input value to be converted
 * @param len The number of bits used for the conversion
 * @return the unsigned integer taking len bits from the input char
 */
inline unsigned long int charToULIntBE(char *value, int len) {
   unsigned long int return_value = 0;
   for( int i = 0; i <= len - 1; i++ ) {
      return_value = (return_value << 8) + static_cast<unsigned char>( value[i] );
   }

   return return_value;
}


#endif /* BINARYHELPER_H_ */
