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

#include "ItemConverterBase.h"

#include <string>
#include <memory>

namespace DoubleConverter {

   /**
    * Covert the input value by multiplying it with 0.5
    *
    * @param value the value to be converted
    * @param dest_buffer not needed and only present for distinguishing purposes during generic call
    * @return the string representation of the converted value
    * @throw No throw
    */
class FractionHalf: public ItemConverterBase, public std::enable_shared_from_this<FractionHalf> {
private:
   FractionHalf();

public:
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
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the given raw value by dividing it by 16
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted value
    * @throw None
    */
class Fraction8th: public ItemConverterBase, public std::enable_shared_from_this<Fraction8th> {
private:
   Fraction8th();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the given raw value by dividing it by 16
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted value
    * @throw None
    */
class Fraction16th: public ItemConverterBase, public std::enable_shared_from_this<Fraction16th> {
private:
   Fraction16th();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the given value to the new value with a resolution of 1/64.
    *
    * @param value the raw value to be converted
    * @param dest_buffer bugger to write the result to. Not used
    * @return the converted value as string
    * @throw No throw
    */
class Fraction64th: public ItemConverterBase, public std::enable_shared_from_this<Fraction64th> {
private:
   Fraction64th();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the input value to the output being 1/128 nautical mile of the input.
    *
    * @param value The value which should be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return double representation of the input value as 1/128th nautical miles
    * @throw None
    */
class Fraction128th: public ItemConverterBase, public std::enable_shared_from_this<Fraction128th> {
private:
   Fraction128th();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};
   /** Convert the input value to the output being 1/256 nautical mile of the input.
    *
    * @param value The value which should be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return double representation of the input value as 1/256th nautical miles
    * @throw None
    */
class Fraction256th: public ItemConverterBase, public std::enable_shared_from_this<Fraction256th> {
private:
   Fraction256th();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the given value by dividing it by 10 to the power of 5
    *
    * @param value the raw value to be converted
    * @param dest_buffer Buffer to store the converted value in. Not used
    * @return the converted value in string representation
    * @throw No throw
    */
class Fraction10ToPower5: public ItemConverterBase, public std::enable_shared_from_this<Fraction10ToPower5> {
private:
   Fraction10ToPower5();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the given value by dividing it by 10 to the power of 6
    *
    * @param value the raw value to be converted
    * @param dest_buffer Buffer to store the converted value in. Not used
    * @return the converted value in string representation
    * @throw No throw
    */
class Fraction10ToPower6: public ItemConverterBase, public std::enable_shared_from_this<Fraction10ToPower6> {
private:
   Fraction10ToPower6();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the input value to a WGS84 height with a resolution of 0.25 meters
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw No throw
    */
class WGS84AltQuarter: public ItemConverterBase, public std::enable_shared_from_this<WGS84AltQuarter> {
private:
   WGS84AltQuarter();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the 24 bit value into a double with resolution is 180/2^23 (deg).
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw No throw
    */
class WGS84resolution23Bit: public ItemConverterBase, public std::enable_shared_from_this<WGS84resolution23Bit> {
private:
   WGS84resolution23Bit();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the 24 bit value into a double with resolution is 180/2^25 (deg).
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw No throw
    */
class WGS84resolution25Bit: public ItemConverterBase, public std::enable_shared_from_this<WGS84resolution25Bit> {
private:
   WGS84resolution25Bit();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the 32 bit value into a double with resolution is 180/2**30 (deg).
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw No throw
    */
class WGS84resolution30Bit: public ItemConverterBase, public std::enable_shared_from_this<WGS84resolution30Bit> {
private:
   WGS84resolution30Bit();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the 32 bit value into a double with resolution is 180/2**31 (deg).
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw No throw
    */
class WGS84resolution31Bit: public ItemConverterBase, public std::enable_shared_from_this<WGS84resolution31Bit> {
private:
   WGS84resolution31Bit();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the 32 bit value into a double with resolution is 90/2**31 (deg).
    *
    * @param value the value to be converted
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the value converted to the specified resolution
    * @throw No throw
    */
class WGS8490degResolution31Bit: public ItemConverterBase,
   public std::enable_shared_from_this<WGS8490degResolution31Bit> {
private:
   WGS8490degResolution31Bit();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert value altitude with a resolution of 0.012 kt/s
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted altitude
    * @throw None
    */
class GroundVectorAcceleration: public ItemConverterBase, public std::enable_shared_from_this<GroundVectorAcceleration> {
private:
   GroundVectorAcceleration();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert value altitude with a resolution of 6.25 ft
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted altitude
    * @throw None
    */
class GeoAltitudeFt: public ItemConverterBase, public std::enable_shared_from_this<GeoAltitudeFt> {
private:
   GeoAltitudeFt();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert value into a vertical rate with a resolution of 6.25 feet per minute
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted vertical rate
    * @throw None
    */
class VerticalRate: public ItemConverterBase, public std::enable_shared_from_this<VerticalRate> {
private:
   VerticalRate();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the given raw value by multiplying it with an LSB of 0.15
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted value
    * @throw None
    */
class Factor015: public ItemConverterBase, public std::enable_shared_from_this<Factor015> {
private:
   Factor015();

public:
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
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Converts the given 16 Bit values to a segment of a half circle, with all values evenly distributed.
    * Thus the resolution is 180 / 2^16 = 0.0055 deg.
    *
    * @param value the value to be converted
    * qparam dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return the converted value as string
    * @throws Not yet decided
    */
class Elevation16Bit: public ItemConverterBase, public std::enable_shared_from_this<Elevation16Bit> {
private:
   Elevation16Bit();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};


} // end namespace DoubleCOonverter

#endif /* DOUBLECONVERTER_H_ */
