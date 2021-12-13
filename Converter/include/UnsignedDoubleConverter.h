/**
 * @file UnsignedDoubleConverter.h
 * @author  Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 5 Feb 2018
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
 * Set of converter converting from and to values represented in Asterix as unsigned double.
 *
 * NOTE! All names indication a size in bit (e.g. fraction10Bit ) have no bit constrained at the
 * input or output, but rather indicate that 2 to the power of X, in this case 10, will be used
 * for the conversion. The above example will result in the following conversion
 *
 * ' value / 2**10'
 *
 */

#ifndef UNSIGNEDDOUBLECONVERTER_H_
#define UNSIGNEDDOUBLECONVERTER_H_

#include <string>

class UnsignedDoubleConverter {
public:
   UnsignedDoubleConverter();
   virtual ~UnsignedDoubleConverter();

   /**
    * Convert the given 8 Bit number into degrees with a resolution of 360/2^8
    *
    * @param value the bits to be converted
    * @parame dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return The string representation of the converted value
    * @throws Not yet decided
    */
   static std::string circleSegment8Bit( char* value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Convert the input to a angle representation in degrees, where the input is 16 bit and the
    * angle is between 0 and 360 deg.
    *
    * @param value The value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the angle in range 0 and 360 degree derived from the 16 bit input
    * @throw None
    */
   static std::string circleSegment16Bit( char* value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Converts the given 8 Bit values to a segment of circle, with all values evenly distributed.
    * Thus the resolution is 360.0 / 2^14 = 0.044 deg.
    *
    * @param value the value to be converted
    * qparam dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted value as string
    * @throws Not yet decided
    */
   static std::string direction13Bit( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Converts the given 8 Bit values to a segment of circle, with all values evenly distributed.
    * Thus the resolution is 360.0 / 2^13 = 0.022 deg.
    *
    * @param value the value to be converted
    * qparam dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted value as string
    * @throws Not yet decided
    */
   static std::string direction14Bit( char* value, unsigned int value_length, double& dest_buffer );

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
    * Converts the given raw values to a segment of circle, with all values evenly distributed.
    * Thus the resolution is 360.0 / 128..
    *
    * @param value the value to be converted
    * qparam dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted value as string
    * @throws Not yet decided
    */
   static std::string direction128th( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Converts the given raw values to a segment of a half circle, with all values evenly distributed.
    * Thus the resolution is 180 / 2**8..
    *
    * @param value the value to be converted
    * qparam dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted value as string
    * @throws Not yet decided
    */
   static std::string directionHalfCircle8Bit( char* value, unsigned int value_length,
      double& dest_buffer );

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
    * Covert the input value by dividing it by ten
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
   static std::string fraction10th( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Covert the input value to a track angle rate with a resolution of 1/32 degree
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
   static std::string fraction32nd( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Covert the input value by dividing it by a hundred
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
   static std::string fraction100th( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the input time to the TOD in 1/128 sec resolution.
    *
    * @param value The value to be converted to the time of day
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted TOD
    * @throw None
    */
   static std::string fraction128th( char* value, unsigned int value_length );

   /**
    * Covert the input value to an output value being 1/360  degree of the input
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
   static std::string fraction360th( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the input time to the TOD in 1/2**30 sec (0.9313 ns) resolution.
    *
    * @param value The value to be converted to the time of day
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted time
    * @throw None
    */
   static std::string fraction30Bit( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Covert the input value to selected heading with a resolution of 0.703125 degree
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
   static std::string selectedHeading( char* value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Covert the input value to ground track heading with a resolution of 2.8125 degree
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
   static std::string groundTrackHeading( char* value, unsigned int value_length,
      double& dest_buffer );

   /**
    * Convert the raw value of NM/s to kt.
    *
    * @param value The value to be converted to kt
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted 14 bit input
    * @throw None
    */
   static std::string speedNMToKt( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the ground vector GSP input value to kt with a resolution of 0.125 kt.
    *
    * @param value The value to be converted to kt
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted 14 bit input
    * @throw None
    */
   static std::string speedVelToKt( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the give value to the correct Airspedd depending on the IM bit. IN case IM is set to
    * 0, the LSB will be 2**-14 else it will be 0.001.
    *
    * @param value The value to be converted to kt
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted 14 bit input
    * @throw None
    */
   static std::string airspeed14Bit( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Covert the input value by multiplying it by ten
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
   static std::string fact10( char* value, unsigned int value_length, double& dest_buffer );

   /**
    * Convert the value to an estimated range value with resolution of 500/2**16
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted value
    * @throw None
    */
   static std::string eRange( char* value, unsigned int value_length, double& dest_buffer );

};

#endif /* UNSIGNEDDOUBLECONVERTER_H_ */
