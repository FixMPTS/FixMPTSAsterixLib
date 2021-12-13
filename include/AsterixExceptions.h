/**
 * @file AsterixExceptions.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 27 Apr 2017
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
 * This file provides the exceptions raised during Asterix De/Encoding.
 */
#ifndef ASTERIXEXCEPTIONS_H_
#define ASTERIXEXCEPTIONS_H_

//general includes
#include <iostream>
#include <exception>

/**
 * Exception to be thrown in case the encode encounters a missing mandatory item in the received
 * Asterix message.
 */
class MandatoryItemMissing: public std::runtime_error {

public:
   MandatoryItemMissing( std::string source, std::string item );
};

/**
 * Exception to be thrown in case the remaining buffer size is less than what is expected by the
 * length indicator.
 */
class MessageSizeMissmatch: public std::runtime_error {

public:
   MessageSizeMissmatch( std::string source, std::string item, std::string info );
};

/**
 * Error to be raised during conversion of Asterix items.
 */
class ConverterError: public std::runtime_error {

public:
   ConverterError( std::string converter_name, std::string value, std::string info );

};

#endif /* ASTERIXEXCEPTIONS_H_ */
