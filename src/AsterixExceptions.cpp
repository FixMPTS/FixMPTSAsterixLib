/**
 * @file AsterixExceptions.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 28 Nov 2018
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
 * See .h file for more information
 */

// Project includes
#include "AsterixExceptions.h"

MandatoryItemMissing::MandatoryItemMissing( std::string source, std::string item ) :
   std::runtime_error( source + " Mandatory item " + item + " is missing." ) {
}

/*****
 *
 */
MessageSizeMissmatch::MessageSizeMissmatch( std::string source, std::string item, std::string info ) :
      std::runtime_error(
         source + " item " + item + +" the size of the buffer is less than what is expected by the length "
            "indicator." + info ) {
}

/*****
 *
 */
ConverterError::ConverterError( std::string converter_name, std::string value, std::string info ) :
      std::runtime_error(
      "Converter " + converter_name + " raised the following error " + info + " while trying to convert value "
            + value ) {
}

