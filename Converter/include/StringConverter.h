/**
 * @file StringConverter.h
 * @author  Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 31 Jan 2018
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
 * Class providing a set of Asterix converter. All converter within this class convert either from
 * or to strings
 */

#ifndef STRINGCONVERTER_H_
#define STRINGCONVERTER_H_

#include <string>

class StringConverter {
public:
   StringConverter();
   virtual ~StringConverter();

   /**
    * Convert the given bytes into six bit characters in accordance to ICAO Annex 10.
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw ConverterError in case the input cannot be converted
    */
   static std::string to6BitChar( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the given bytes to ASICC characters.
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted characters
    * @throw No throw
    */
   static std::string toASCII( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the given 19 Bits comprised of two 5 bit and 3 three bit characters into a NATO
    * track number
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted characters
    * @throw No throw
    */
   static std::string BitsToNATOtn19Bit( char* value, unsigned int value_length,
      double& dest_buffer );
};

#endif /* STRINGCONVERTER_H_ */
