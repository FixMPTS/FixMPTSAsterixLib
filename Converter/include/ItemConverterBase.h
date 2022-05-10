/**
 * @file ItemConverterBase.h
 * @author  Felix Kreuter <felix.kreuter@lordcentury.net>
 * @version 1.0
 * Created on: 17 Apr 2022
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
 * TODO
 */
#ifndef ITEMCONVERTERBASE_H_
#define ITEMCONVERTERBASE_H_

#include <string>
#include <vector>
#include <cstdint>
#include <memory>

class ItemConverterBase {
private:

public:
   ItemConverterBase();
   virtual ~ItemConverterBase();

   std::shared_ptr<ItemConverterBase> get() {
      return nullptr;
   }
   virtual uint64_t toExternal(std::string value, unsigned int value_length) = 0;
   virtual std::string fromExternal(char *value, unsigned int value_length) = 0;
};

#endif /* ITEMCONVERTERBASE_H_ */
