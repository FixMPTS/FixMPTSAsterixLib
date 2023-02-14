/**
 * @file Exceptions.h
 * @author Felix Kreuter <felix@fixmpts.org>
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
 * A list of classes for all exceptions to be added by core of this software.
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

//global includes
#include <iostream>
#include <exception>
#include <string>
#include <map>

/**
 * Exception to be raised in case the type of the parameter could not be properly processed because
 * it is not known to the system.
 */
class InvalidParameterType: public std::runtime_error {
public:
   InvalidParameterType();
   InvalidParameterType(std::string msg);
};

/**
 * Exceptions to be raised in case value currently read is not expected for this type of parameter.
 */
class InvalidParameterValue: public std::runtime_error {
public:
   InvalidParameterValue();
};

/**
 * This exception shall be raised in case the value currently read exceeds the predefined limits.
 * Either upper or lower limit.
 */
class InvalidParameterLimit: public std::runtime_error {
public:
   InvalidParameterLimit();
};

/**
 * This error will be raised in case the value of a parameter does not meet the configuration constrains.
 */
class ConfigurationConstrainedError: public std::runtime_error {

public:
   ConfigurationConstrainedError( std::string msg );
};

/**
 * This exception shall be raised if the given configuration file is not readable or does not exist.
 */
class InvalidConfigurationFile: public std::runtime_error {
public:
   InvalidConfigurationFile();
};

/**
 * This exception shall be raised if the given configuration file is not readable or does not exist.
 */
class ElementNotFound: public std::runtime_error {
public:
   ElementNotFound( std::string caller, std::string item );
};

/**
 * Runtime error to be thrown during tracking atcivities
 */
class TrackRuntimeError: public std::runtime_error {
public:
   /**
    * Runtime error caused during tracking
    *
    * @param originator name of the class/module throwing the exception
    * @param msg the message that goes with the exception
    */
   TrackRuntimeError(std::string originator, std::string msg);
};

/**
 * Runtime error to be thrown in case the initialisation failed
 */
class InitialisationError: public std::runtime_error {
public:
   /**
    * Runtime error caused during tracking
    *
    * @param originator name of the class/module throwing the exception
    * @param msg the message that goes with the exception
    */
   InitialisationError(std::string originator, std::string msg);
};

/**
 * Runtime error to be thrown in case a generic error on the network occurred.
 */
class NetworkError: public std::runtime_error {
public:
   /**
    * Runtime error caused during network related operation
    *
    * @param originator name of the class/module throwing the exception
    * @param msg the message that goes with the exception
    */
   NetworkError(std::string originator, std::string msg);
};

/**
 * General encoding error
 */
class EncodingError: std::runtime_error {
public:
   EncodingError(std::string originator, std::string msg);
};

#endif /* EXCEPTIONS_H_ */
