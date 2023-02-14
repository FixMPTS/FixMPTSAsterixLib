/**
 * @file DoubleConverter.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
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
 * See .h file for more information
 */

#include <math.h>

#include "DoubleConverter.h"

namespace DoubleConverter {
// Set of Fraction converter
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    FractionHalf     ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
FractionHalf::FractionHalf() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> FractionHalf::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<FractionHalf>( FractionHalf() );
   return instance;
}
uint64_t FractionHalf::toExternal(std::string value, unsigned int value_length) {
   float lsb = 1.0 / 2.0;
   return std::llround( std::atof( value.c_str() ) / lsb );
}
std::string FractionHalf::fromExternal(char *value, unsigned int value_length) {
   long int value_converted = std::stoll( value );
   return std::to_string( value_converted * 0.5 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    Fraction4th     /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
Fraction4th::Fraction4th() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> Fraction4th::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<Fraction4th>( Fraction4th() );
   return instance;
}
uint64_t Fraction4th::toExternal(std::string value, unsigned int value_length) {
   float lsb = 1.0 / 4.0;
   return std::llround( std::atof( value.c_str() ) / lsb );
}
std::string Fraction4th::fromExternal(char *value, unsigned int value_length) {
   long int value_converted = std::stoll( value );
   return std::to_string( (value_converted / 4.0) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    Fraction8th     /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
Fraction8th::Fraction8th() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> Fraction8th::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<Fraction8th>( Fraction8th() );
   return instance;
}
uint64_t Fraction8th::toExternal(std::string value, unsigned int value_length) {
   float lsb = 1.0 / 8.0;
   return std::llround( std::atof( value.c_str() ) / lsb );
}
std::string Fraction8th::fromExternal(char *value, unsigned int value_length) {
   long int value_converted = std::stoll( value );
   return std::to_string( (value_converted / 8.0) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    Fraction16th     ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
Fraction16th::Fraction16th() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> Fraction16th::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<Fraction16th>( Fraction16th() );
   return instance;
}
uint64_t Fraction16th::toExternal(std::string value, unsigned int value_length) {
   float lsb = 1.0 / 16.0;
   return std::llround( std::atof( value.c_str() ) / lsb );
}
std::string Fraction16th::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted / 16.0) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    Fraction64th     ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
Fraction64th::Fraction64th() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> Fraction64th::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<Fraction64th>( Fraction64th() );
   return instance;
}
uint64_t Fraction64th::toExternal(std::string value, unsigned int value_length) {
   float lsb = 1.0 / 64.0;
   return std::llround( std::atof( value.c_str() ) / lsb );
}
std::string Fraction64th::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 64 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    Fraction128th     ///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
Fraction128th::Fraction128th() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> Fraction128th::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<Fraction128th>( Fraction128th() );
   return instance;
}
uint64_t Fraction128th::toExternal(std::string value, unsigned int value_length) {
   return std::llround( std::atof( value.c_str() ) * 128.0 );
}

std::string Fraction128th::fromExternal(char *value, unsigned int value_length) {
   long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( value_converted / 128.0 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////    Fraction256th     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
Fraction256th::Fraction256th() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> Fraction256th::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<Fraction256th>( Fraction256th() );
   return instance;
}
uint64_t Fraction256th::toExternal(std::string value, unsigned int value_length) {
   return std::llround( std::atof( value.c_str() ) * 256.0 );
}
std::string Fraction256th::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 256.0 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    Fraction10ToPower5     //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
Fraction10ToPower5::Fraction10ToPower5() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> Fraction10ToPower5::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<Fraction10ToPower5>( Fraction10ToPower5() );
   return instance;
}
uint64_t Fraction10ToPower5::toExternal(std::string value, unsigned int value_length) {
   return std::llround( std::atof( value.c_str() ) / pow( 10, -5 ) );
}
std::string Fraction10ToPower5::fromExternal(char *value, unsigned int value_length) {
   long int value_converted = std::stoll( value );
   return std::to_string( value_converted * pow( 10, -5 ) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    Fraction10ToPower6     //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
Fraction10ToPower6::Fraction10ToPower6() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> Fraction10ToPower6::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<Fraction10ToPower6>( Fraction10ToPower6() );
   return instance;
}
uint64_t Fraction10ToPower6::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string Fraction10ToPower6::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * pow( 10, -6 ) );
}

// WGS 84 related converter
////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////    WGS84resolution23Bit     //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
WGS84resolution23Bit::WGS84resolution23Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> WGS84resolution23Bit::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<WGS84resolution23Bit>(
      WGS84resolution23Bit() );
   return instance;
}
uint64_t WGS84resolution23Bit::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string WGS84resolution23Bit::fromExternal(char *value, unsigned int value_length) {
   long long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( (180.0 / pow( 2, 23 )) * value_converted );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////    WGS84resolution25Bit     //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
WGS84resolution25Bit::WGS84resolution25Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> WGS84resolution25Bit::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<WGS84resolution25Bit>(
      WGS84resolution25Bit() );
   return instance;
}
uint64_t WGS84resolution25Bit::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string WGS84resolution25Bit::fromExternal(char *value, unsigned int value_length) {
   long long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( (180.0 / pow( 2, 25 )) * value_converted );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////    WGS84resolution30Bit     //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
WGS84resolution30Bit::WGS84resolution30Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> WGS84resolution30Bit::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<WGS84resolution30Bit>(
      WGS84resolution30Bit() );
   return instance;
}
uint64_t WGS84resolution30Bit::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string WGS84resolution30Bit::fromExternal(char *value, unsigned int value_length) {
   long long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( (180.0 / pow( 2, 30 )) * value_converted );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////    WGS84resolution31Bit     //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
WGS84resolution31Bit::WGS84resolution31Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> WGS84resolution31Bit::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<WGS84resolution31Bit>(
      WGS84resolution31Bit() );
   return instance;
}
uint64_t WGS84resolution31Bit::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string WGS84resolution31Bit::fromExternal(char *value, unsigned int value_length) {
   long long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( (180.0 / pow( 2, 31 )) * value_converted );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////    WGS8490degResolution31Bit     /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
WGS8490degResolution31Bit::WGS8490degResolution31Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> WGS8490degResolution31Bit::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<WGS8490degResolution31Bit>(
      WGS8490degResolution31Bit() );
   return instance;
}
uint64_t WGS8490degResolution31Bit::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string WGS8490degResolution31Bit::fromExternal(char *value, unsigned int value_length) {
   long long int value_converted = std::stoll( value );

   // Apply the LSB
   return std::to_string( (90.0 / pow( 2, 31 )) * value_converted );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////    WGS84AltQuarter     /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
WGS84AltQuarter::WGS84AltQuarter() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> WGS84AltQuarter::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<WGS84AltQuarter>( WGS84AltQuarter() );
   return instance;
}
uint64_t WGS84AltQuarter::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string WGS84AltQuarter::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );

   // Apply the LSB
   return std::to_string( value_converted * 0.25 );
}

// Misc converter
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////    GroundVectorAcceleration     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
GroundVectorAcceleration::GroundVectorAcceleration() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> GroundVectorAcceleration::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<GroundVectorAcceleration>(
      GroundVectorAcceleration() );
   return instance;
}
uint64_t GroundVectorAcceleration::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string GroundVectorAcceleration::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 0.012 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    GeoAltitudeFt     ///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
GeoAltitudeFt::GeoAltitudeFt() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> GeoAltitudeFt::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<GeoAltitudeFt>( GeoAltitudeFt() );
   return instance;
}
uint64_t GeoAltitudeFt::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string GeoAltitudeFt::fromExternal(char *value, unsigned int value_length) {
   long int value_converted = std::stoll( value );
   return std::to_string( value_converted * 6.25 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    VerticalRate     ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
VerticalRate::VerticalRate() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> VerticalRate::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<VerticalRate>( VerticalRate() );
   return instance;
}
uint64_t VerticalRate::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string VerticalRate::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 6.25 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    Factor015     ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
Factor015::Factor015() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> Factor015::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<Factor015>( Factor015() );
   return instance;
}
uint64_t Factor015::toExternal(std::string value, unsigned int value_length) {
   float lsb = 0.15;
   return std::llround( std::atof( value.c_str() ) / lsb );
}
std::string Factor015::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted * 0.15) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    Direction16Bit     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
Direction16Bit::Direction16Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> Direction16Bit::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<Direction16Bit>( Direction16Bit() );
   return instance;
}
uint64_t Direction16Bit::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string Direction16Bit::fromExternal(char *value, unsigned int value_length) {
   long int value_converted = std::stoll( value );
   return std::to_string( (360.0 / (pow( 2, 16 ) / 2.0) * value_converted) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////    Elevation16Bit     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
Elevation16Bit::Elevation16Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> Elevation16Bit::get() {
   static std::shared_ptr<ItemConverterBase> instance = std::make_shared<Elevation16Bit>( Elevation16Bit() );
   return instance;
}
uint64_t Elevation16Bit::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string Elevation16Bit::fromExternal(char *value, unsigned int value_length) {
   long int value_converted = std::stoll( value );
   return std::to_string( (180.0 / (pow( 2, 16 ) / 2.0) * value_converted) );
}
}
