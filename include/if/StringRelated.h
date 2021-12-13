/**
 * @file StringRElated.h
 * @author  Felix Kreuter <felix.kreuter@lordcentury.net>
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * Purpose of this file is to provide some useful functions and procedures related to std strings
 * and that are not already provided by the std package.
 *
 * + std::string strToUpper( std::string s ) returns the given string into upper case
 */

#ifndef STRINGRELATED_H_
#define STRINGRELATED_H_

#include <string.h>
#include <algorithm>
#include <iostream>

/**
 *
 *@param s The string to be converted to upper case
 *@return The input string transformed to upper case
 */
inline std::string strToUpper( std::string s ){
   std::transform( s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>( std::toupper ) );
   return s;
}

/**
 * Convert a eight bit char to an unsigned integer using big endian encoding.
 *
 * @param value The input value to be converted
 * @param len The number of bits used for the conversion
 * @return the unsigned integer taking len bits from the input char
 */
inline unsigned long int charToULIntBE( char* value, int len ){
   unsigned long int return_value = 0;
   for( int i = 0; i<=len-1; i++ ) {
      return_value = ( return_value<<8 )+static_cast<unsigned char>( value[i] );
   }

   return return_value;
}

/**
 * Convert a eight bit char to an unsigned integer using little endian encoding.
 *
 * @param value The input value to be converted
 * @param len The number of bits used for the conversion
 * @return the unsigned integer taking len bits from the input char
 */
inline unsigned long int charToULIntLE( char* value, int len ){
   unsigned long int return_value = 0;
   for( int i = len-1; i>=0; i-- ) {
      return_value = ( return_value<<8 )+static_cast<unsigned char>( value[i] );
   }

   return return_value;
}

/**
 * Remove all leading white spaces of the given string.
 *
 * @param old_string the string to be trimmed
 * @return a new string with all leading white spaces being removed
 * @throws Not yet decided
 */
inline std::string left_trim( std::string old_string ){
   return old_string.substr( old_string.find_first_not_of( " " ) );
}

/**
 * Remove all trailing white spaces of the given string
 *
 * @param old_string the string from which the trailing white spaces re removed
 * @return a new string without the trailing white spaces of the original string
 * @throws Not yet decided
 */
inline std::string right_trim( std::string old_string ){
   old_string.erase( std::find_if(
      old_string.rbegin(),
      old_string.rend(),
      std::bind1st( std::not_equal_to<char>(), ' ' ) ).base(),
      old_string.end() );

   return old_string;
}

/**
 * Remove all leading and trailing white spaces of the given string.
 *
 * @param old_string the string to be trimmed
 * @return a new string without leading and trailing white spaces
 * @throws Not yet decided
 */
inline std::string trim( std::string old_string ){
   return left_trim( right_trim( old_string ) );
}

#endif /* STRINGRELATED_H_ */
