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

#include "ItemConverterBase.h"
#include <string>

namespace UnsignedDoubleConverter {

   /**
    * Convert the given 8 Bit number into degrees with a resolution of 360/2^8
    *
    * @param value the bits to be converted
    * @parame dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return The string representation of the converted value
    * @throws Not yet decided
    */
class CircleSegment8Bit: public ItemConverterBase, public std::enable_shared_from_this<CircleSegment8Bit> {
private:
   CircleSegment8Bit();

public:
   void operator=(const CircleSegment8Bit&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the input to a angle representation in degrees, where the input is 16 bit and the
    * angle is between 0 and 360 deg.
    *
    * @param value The value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the angle in range 0 and 360 degree derived from the 16 bit input
    * @throw None
    */
class CircleSegment16Bit: public ItemConverterBase, public std::enable_shared_from_this<CircleSegment16Bit> {
private:
   CircleSegment16Bit();

public:
   void operator=(const CircleSegment16Bit&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Converts the given 8 Bit values to a segment of circle, with all values evenly distributed.
    * Thus the resolution is 360.0 / 2^14 = 0.044 deg.
    *
    * @param value the value to be converted
    * qparam dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted value as string
    * @throws Not yet decided
    */
class Direction13Bit: public ItemConverterBase, public std::enable_shared_from_this<Direction13Bit> {
private:
   Direction13Bit();

public:
   void operator=(const Direction13Bit&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Converts the given 8 Bit values to a segment of circle, with all values evenly distributed.
    * Thus the resolution is 360.0 / 2^13 = 0.022 deg.
    *
    * @param value the value to be converted
    * qparam dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted value as string
    * @throws Not yet decided
    */
class Direction14Bit: public ItemConverterBase, public std::enable_shared_from_this<Direction14Bit> {
private:
   Direction14Bit();

public:
   void operator=(const Direction14Bit&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Converts the given 16 Bit values to a segment of circle, with all values evenly distributed.
    * Thus the resolution is 360.0 / 2^16 = 0.0055 deg.
    *
    * @param value the value to be converted
    * qparam dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted value as string
    * @throws Not yet decided
    */
class Direction16Bit: public ItemConverterBase, public std::enable_shared_from_this<Direction16Bit> {
private:
   Direction16Bit();

public:
   void operator=(const Direction14Bit&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Converts the given raw values to a segment of circle, with all values evenly distributed.
    * Thus the resolution is 360.0 / 128..
    *
    * @param value the value to be converted
    * qparam dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted value as string
    * @throws Not yet decided
    */
class Direction128th: public ItemConverterBase, public std::enable_shared_from_this<Direction128th> {
private:
   Direction128th();

public:
   void operator=(const Direction128th&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Converts the given raw values to a segment of a half circle, with all values evenly distributed.
    * Thus the resolution is 180 / 2**8..
    *
    * @param value the value to be converted
    * qparam dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted value as string
    * @throws Not yet decided
    */
class DirectionHalfCircle8Bit: public ItemConverterBase, public std::enable_shared_from_this<DirectionHalfCircle8Bit> {
private:
   DirectionHalfCircle8Bit();

public:
   void operator=(const DirectionHalfCircle8Bit&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the value to quarter of the given raw value
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted value
    * @throw None
    */
class Fraction4th: public ItemConverterBase, public std::enable_shared_from_this<Fraction4th> {
private:
   Fraction4th();

public:
   void operator=(const Fraction4th&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Covert the input value by dividing it by ten
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
class Fraction10th: public ItemConverterBase, public std::enable_shared_from_this<Fraction10th> {
private:
   Fraction10th();

public:
   void operator=(const Fraction10th&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Covert the input value to a track angle rate with a resolution of 1/32 degree
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
class Fraction32nd: public ItemConverterBase, public std::enable_shared_from_this<Fraction32nd> {
private:
   Fraction32nd();

public:
   void operator=(const Fraction32nd&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Covert the input value by dividing it by a hundred
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
class Fraction100th: public ItemConverterBase, public std::enable_shared_from_this<Fraction100th> {
private:
   Fraction100th();

public:
   void operator=(const Fraction100th&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the input time to the TOD in 1/128 sec resolution.
    *
    * @param value The value to be converted to the time of day
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted TOD
    * @throw None
    */
class Fraction128th: public ItemConverterBase, public std::enable_shared_from_this<Fraction128th> {
private:
   Fraction128th();

public:
   void operator=(const Fraction128th&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Covert the input value to an output value being 1/360  degree of the input
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
class Fraction360th: public ItemConverterBase, public std::enable_shared_from_this<Fraction360th> {
private:
   Fraction360th();

public:
   void operator=(const Fraction360th&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the input time to the TOD in 1/2**30 sec (0.9313 ns) resolution.
    *
    * @param value The value to be converted to the time of day
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted time
    * @throw None
    */
class Fraction30Bit: public ItemConverterBase, public std::enable_shared_from_this<Fraction30Bit> {
private:
   Fraction30Bit();

public:
   void operator=(const Fraction30Bit&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Covert the input value to selected heading with a resolution of 0.703125 degree
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
class SelectedHeading: public ItemConverterBase, public std::enable_shared_from_this<SelectedHeading> {
private:
   SelectedHeading();

public:
   void operator=(const SelectedHeading&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Covert the input value to ground track heading with a resolution of 2.8125 degree
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
class GroundTrackHeading: public ItemConverterBase, public std::enable_shared_from_this<GroundTrackHeading> {
private:
   GroundTrackHeading();

public:
   void operator=(const GroundTrackHeading&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the raw value of NM/s to kt.
    *
    * @param value The value to be converted to kt
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted 14 bit input
    * @throw None
    */
class SpeedNMToKt: public ItemConverterBase, public std::enable_shared_from_this<SpeedNMToKt> {
private:
   SpeedNMToKt();

public:
   void operator=(const SpeedNMToKt&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the ground vector GSP input value to kt with a resolution of 0.125 kt.
    *
    * @param value The value to be converted to kt
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted 14 bit input
    * @throw None
    */
class SpeedVelToKt: public ItemConverterBase, public std::enable_shared_from_this<SpeedVelToKt> {
private:
   SpeedVelToKt();

public:
   void operator=(const SpeedVelToKt&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the give value to the correct Airspedd depending on the IM bit. IN case IM is set to
    * 0, the LSB will be 2**-14 else it will be 0.001.
    *
    * @param value The value to be converted to kt
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted 14 bit input
    * @throw None
    */
class Airspeed14Bit: public ItemConverterBase, public std::enable_shared_from_this<Airspeed14Bit> {
private:
   Airspeed14Bit();

public:
   void operator=(const Airspeed14Bit&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Covert the input value by multiplying it by ten
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw Not yet decided
    */
class Fact10: public ItemConverterBase, public std::enable_shared_from_this<Fact10> {
private:
   Fact10();

public:
   void operator=(const Fact10&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the value to an estimated range value with resolution of 500/2**16
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted value
    * @throw None
    */
class ERange: public ItemConverterBase, public std::enable_shared_from_this<ERange> {
private:
   ERange();

public:
   void operator=(const ERange&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

} // end namespace

#endif /* UNSIGNEDDOUBLECONVERTER_H_ */
