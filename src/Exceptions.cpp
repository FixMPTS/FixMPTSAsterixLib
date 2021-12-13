/**
 * @file Exceptions.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 7 Aug 2018
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

#include "Exceptions.h"

InvalidParameterType::InvalidParameterType() :
   std::runtime_error( "The parameter type must be one of STRING, BOOL, NUMBER, or DOUBLE" ) {
}

InvalidParameterType::InvalidParameterType(std::string msg) :
   std::runtime_error( "Unexpected parameter type: " + msg ) {
}

//////////
InvalidParameterValue::InvalidParameterValue() :
   std::runtime_error( "Invalid parameter value" ) {
}

//////////
InvalidParameterLimit::InvalidParameterLimit() :
   std::runtime_error( "Invalid parameter limit" ) {
}

//////////
ConfigurationConstrainedError::ConfigurationConstrainedError(std::string msg) :
   std::runtime_error( std::string( "Evaluating the parameter constrained resulted in the following error:" + msg ) ) {
}

//////////
InvalidConfigurationFile::InvalidConfigurationFile() :
   std::runtime_error( "Invalid configuration file. Could not read file." ) {
}

//////////
ElementNotFound::ElementNotFound( std::string caller, std::string item ) :
   std::runtime_error( std::string( caller + ": reported item " + item + " not found in structure" ) ) {
}

//////////
TrackRuntimeError::TrackRuntimeError(std::string originator, std::string msg) :
   std::runtime_error( std::string( originator + ": " + msg ) ) {
}
//////////

InitialisationError::InitialisationError(std::string originator, std::string msg) :
   std::runtime_error( std::string( originator + " failed initialisation: " + msg ) ) {

}
//////////
NetworkError::NetworkError(std::string originator, std::string msg) :
   std::runtime_error( std::string( originator + " encountered the following network error: " + msg ) ) {

}


