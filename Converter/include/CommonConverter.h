/**
 * @file CommonConverter.cpp
 * @author  Felix Kreuter <felix@fixmpts.org>
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
 * This class provides the short and commonly used converter functions need to convert the binary
 * input value to the correct internally used value.
 */

#ifndef COMMONCONVERTER_H_
#define COMMONCONVERTER_H_

#include "ItemConverterBase.h"
//global includes
#include <string>
//#include <math.h>
//#include <bitset>
//#include <iostream>
//#include <sstream>
#include <memory>

namespace CommonConverter {
   /**
    * Empty converter. This converter does nothing as to return the input value as string.
    *
    * @param value The value to be converted
    * @return the string representation of the input value.
    * @throw None
    */
//static std::string NoneConverter( char* value, unsigned int value_length );
class NoneConverter: public ItemConverterBase, public std::enable_shared_from_this<NoneConverter> {
private:
   NoneConverter();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

//static std::string NoneConverterBuffer(char *value, unsigned int value_length, double &dest_buffer);
class NoneConverterBuffer: public ItemConverterBase, public std::enable_shared_from_this<NoneConverterBuffer> {
private:
   NoneConverterBuffer();

public:
   static std::shared_ptr<ItemConverterBase> get();
   virtual uint64_t toExternal(std::string value, unsigned int value_length) override;
   virtual std::string fromExternal(char *value, unsigned int value_length) override;
};

} // end namespace

#endif /* COMMONCONVERTER_H_ */
