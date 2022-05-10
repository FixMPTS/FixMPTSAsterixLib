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

#include "ItemConverterBase.h"

#include <string>
#include <memory>

namespace IntegerConverter {
   /**
    * Convert the value to quarter of what is has been before.
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted value
    * @throw None
    */
class LBitsToQuarter: public ItemConverterBase, public std::enable_shared_from_this<LBitsToQuarter> {
private:
   LBitsToQuarter();

public:
   void operator=(const LBitsToQuarter&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

   /**
    * Convert the value to FL with a resolution of 25ft
    *
    * @param value The value to be converted to the correct flight level with 25 ft resolution
    * @param dest_buffer Not needed and only present for distinguishing purposes during generic call
    * @return The converted FL
    * @throw None
    */
class Alt25ft: public ItemConverterBase, public std::enable_shared_from_this<Alt25ft> {
private:
   Alt25ft();

public:
   void operator=(const Alt25ft&) = delete;
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

} // end namespace

#endif /* INTEGERCONVERTER_H_ */
