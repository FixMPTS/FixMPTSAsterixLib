/**
 * @file DoubleConverter.h
 * @author  Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 4 Feb 2018
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
 * Set of converter which convert to and from Asterix signed double types.
 *
 * NOTE! All names indication a size in bit (e.g. fraction10Bit ) have no bit constrained at the
 * input or output, but rather indicate that 2 to the power of X, in this case 10, will be used
 * for the conversion. The above example will result in the following conversion
 *
 * ' value / 2**10'
 *
 */

#ifndef DOUBLECONVERTER_H_
#define DOUBLECONVERTER_H_

#include <string>

class DoubleConverter {
public:
   DoubleConverter();
   virtual ~DoubleConverter();

   /**
    * Covert the input value by multiplying it with 0.5
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw No throw
    */
   static std::string fractionHalf( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the value to quarter of the given raw value
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted value
    * @throw None
    */
   static std::string fraction4th( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the given raw value by dividing it by 16
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted value
    * @throw None
    */
   static std::string fraction8th( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the given raw value by dividing it by 16
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted value
    * @throw None
    */
   static std::string fraction16th( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the given value to the new value with a resolution of 1/64.
    *
    * @param value the raw value to be converted
    * @param dest_buffer bugger to write the result to. Not used
    * @return the converted value as string
    * @throw No throw
    */
   static std::string fraction64th( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the input value to the output being 1/128 nautical mile of the input.
    *
    * @param value The value which should be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return double representation of the input value as 1/128th nautical miles
    * @throw None
    */
   static std::string fraction128th( char* value, unsigned int value_length, double& dest_buffer );

   /** Convert the input value to the output being 1/256 nautical mile of the input.
    *
    * @param value The value which should be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return double representation of the input value as 1/256th nautical miles
    * @throw None
    */
   static std::string fraction256th( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the given value by dividing it by 10 to the power of 5
    *
    * @param value the raw value to be converted
    * @param dest_buffer Buffer to store the converted value in. Not used
    * @return the converted value in string representation
    * @throw No throw
    */
   static std::string fraction10ToPower5( char* value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Convert the given value by dividing it by 10 to the power of 6
    *
    * @param value the raw value to be converted
    * @param dest_buffer Buffer to store the converted value in. Not used
    * @return the converted value in string representation
    * @throw No throw
    */
   static std::string fraction10ToPower6( char* value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Convert the input value to a WGS84 height with a resolution of 0.25 meters
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw No throw
    */
   static std::string WGS84AltQuarter( char* value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Convert the 24 bit value into a double with resolution is 180/2^23 (deg).
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw No throw
    */
   static std::string WGS84resolution23Bit( char* value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Convert the 24 bit value into a double with resolution is 180/2^25 (deg).
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw No throw
    */
   static std::string WGS84resolution25Bit( char* value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Convert the 32 bit value into a double with resolution is 180/2**30 (deg).
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw No throw
    */
   static std::string WGS84resolution30Bit( char* value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Convert the 32 bit value into a double with resolution is 180/2**31 (deg).
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw No throw
    */
   static std::string WGS84resolution31Bit( char* value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Convert the 32 bit value into a double with resolution is 90/2**31 (deg).
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw No throw
    */
   static std::string WGS8490degResolution31Bit( char* value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Convert value altitude with a resolution of 0.012 kt/s
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted altitude
    * @throw None
    */
   static std::string groundVectorAcceleration(char *value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Convert value altitude with a resolution of 6.25 ft
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted altitude
    * @throw None
    */
   static std::string geoAltitudeFt( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert value into a vertical rate with a resolution of 6.25 feet per minute
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted vertical rate
    * @throw None
    */
   static std::string verticalRate( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the given raw value by multiplying it with an LSB of 0.15
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted value
    * @throw None
    */
   static std::string factor015( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Converts the given 16 Bit values to a segment of circle, with all values evenly distributed.
    * Thus the resolution is 360.0 / 2^16 = 0.0055 deg.
    *
    * @param value the value to be converted
    * qparam dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted value as string
    * @throws Not yet decided
    */
   static std::string direction16Bit( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Converts the given 16 Bit values to a segment of a half circle, with all values evenly distributed.
    * Thus the resolution is 180 / 2^16 = 0.0055 deg.
    *
    * @param value the value to be converted
    * qparam dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted value as string
    * @throws Not yet decided
    */
   static std::string elevation16Bit( char* value, unsigned int value_length, double& dest_buffer );


};

#endif /* DOUBLECONVERTER_H_ */
