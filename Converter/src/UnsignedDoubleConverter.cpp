/**
 * @file UnsignedDoubleConverter.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
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
 * See .h file for more information
 */

#include <math.h>
#include <bitset>

#include "UnsignedDoubleConverter.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////     CircleSegment8Bit     ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::CircleSegment8Bit::CircleSegment8Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::CircleSegment8Bit::get() {
   static std::shared_ptr<CircleSegment8Bit> instance = std::make_shared<CircleSegment8Bit>( CircleSegment8Bit() );
   return instance;
}
uint64_t UnsignedDoubleConverter::CircleSegment8Bit::toExternal(std::string value, unsigned int value_length) {
   return std::round( std::atof( value.c_str() ) / 1.41 );
}
std::string UnsignedDoubleConverter::CircleSegment8Bit::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted / pow( 2, 8 )) * 360.0 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////     CircleSegment16Bit     //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::CircleSegment16Bit::CircleSegment16Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::CircleSegment16Bit::get() {
   static std::shared_ptr<CircleSegment16Bit> instance = std::make_shared<CircleSegment16Bit>( CircleSegment16Bit() );
   return instance;
}
uint64_t UnsignedDoubleConverter::CircleSegment16Bit::toExternal(std::string value, unsigned int value_length) {
   return std::round( std::atof( value.c_str() ) / 0.0055 );
}
std::string UnsignedDoubleConverter::CircleSegment16Bit::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted / pow( 2, 16 )) * 360.0 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////     Direction14Bit     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Direction13Bit::Direction13Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Direction13Bit::get() {
   static std::shared_ptr<Direction13Bit> instance = std::make_shared<Direction13Bit>( Direction13Bit() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Direction13Bit::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::Direction13Bit::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (360.0 / pow( 2, 13 ) * value_converted) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////     Direction14Bit     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Direction14Bit::Direction14Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Direction14Bit::get() {
   static std::shared_ptr<Direction14Bit> instance = std::make_shared<Direction14Bit>( Direction14Bit() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Direction14Bit::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::Direction14Bit::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (360.0 / pow( 2, 14 ) * value_converted) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////     Direction16Bit     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Direction16Bit::Direction16Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Direction16Bit::get() {
   static std::shared_ptr<Direction16Bit> instance = std::make_shared<Direction16Bit>( Direction16Bit() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Direction16Bit::toExternal(std::string value, unsigned int value_length) {
   return std::round( std::atof( value.c_str() ) / (360.0 / pow( 2, 16 )) );
}
std::string UnsignedDoubleConverter::Direction16Bit::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (360.0 / pow( 2, 16 ) * value_converted) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////     Direction128th     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Direction128th::Direction128th() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Direction128th::get() {
   static std::shared_ptr<Direction128th> instance = std::make_shared<Direction128th>( Direction128th() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Direction128th::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::Direction128th::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * (360.0 / 128.0) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////     DirectionHalfCircle8Bit     /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::DirectionHalfCircle8Bit::DirectionHalfCircle8Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::DirectionHalfCircle8Bit::get() {
   static std::shared_ptr<DirectionHalfCircle8Bit> instance = std::make_shared<DirectionHalfCircle8Bit>(
      DirectionHalfCircle8Bit() );
   return instance;
}
uint64_t UnsignedDoubleConverter::DirectionHalfCircle8Bit::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::DirectionHalfCircle8Bit::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted * (180 / pow( 2, 8 ))) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////     Fraction4th     /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Fraction4th::Fraction4th() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Fraction4th::get() {
   static std::shared_ptr<Fraction4th> instance = std::make_shared<Fraction4th>( Fraction4th() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Fraction4th::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::Fraction4th::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 4.0 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////     Fraction10th     /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Fraction10th::Fraction10th() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Fraction10th::get() {
   static std::shared_ptr<Fraction10th> instance = std::make_shared<Fraction10th>( Fraction10th() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Fraction10th::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::Fraction10th::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 0.1 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////     Fraction100th     ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Fraction32nd::Fraction32nd() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Fraction32nd::get() {
   static std::shared_ptr<Fraction32nd> instance = std::make_shared<Fraction32nd>( Fraction32nd() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Fraction32nd::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::Fraction32nd::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 32.0 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////     Fraction100th     ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Fraction100th::Fraction100th() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Fraction100th::get() {
   static std::shared_ptr<Fraction100th> instance = std::make_shared<Fraction100th>( Fraction100th() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Fraction100th::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::Fraction100th::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 0.01 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////     Fraction128th     ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Fraction128th::Fraction128th() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Fraction128th::get() {
   static std::shared_ptr<Fraction128th> instance = std::make_shared<Fraction128th>( Fraction128th() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Fraction128th::toExternal(std::string value, unsigned int value_length) {
   return std::round( std::atof( value.c_str() ) * 128.0 );
}
std::string UnsignedDoubleConverter::Fraction128th::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 128.0 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////     Fraction360th     ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Fraction360th::Fraction360th() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Fraction360th::get() {
   static std::shared_ptr<Fraction360th> instance = std::make_shared<Fraction360th>( Fraction360th() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Fraction360th::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::Fraction360th::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / 360.0 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////     Fraction30Bit     ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Fraction30Bit::Fraction30Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Fraction30Bit::get() {
   static std::shared_ptr<Fraction30Bit> instance = std::make_shared<Fraction30Bit>( Fraction30Bit() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Fraction30Bit::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::Fraction30Bit::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted / pow( 2, 30 ) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////     SelectedHeading     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::SelectedHeading::SelectedHeading() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::SelectedHeading::get() {
   static std::shared_ptr<SelectedHeading> instance = std::make_shared<SelectedHeading>( SelectedHeading() );
   return instance;
}
uint64_t UnsignedDoubleConverter::SelectedHeading::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::SelectedHeading::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 0.703125 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////     GroundTrackHeading     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::GroundTrackHeading::GroundTrackHeading() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::GroundTrackHeading::get() {
   static std::shared_ptr<GroundTrackHeading> instance = std::make_shared<GroundTrackHeading>( GroundTrackHeading() );
   return instance;
}
uint64_t UnsignedDoubleConverter::GroundTrackHeading::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::GroundTrackHeading::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 2.8125 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////    SpeedNMToKt     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::SpeedNMToKt::SpeedNMToKt() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::SpeedNMToKt::get() {
   static std::shared_ptr<SpeedNMToKt> instance = std::make_shared<SpeedNMToKt>( SpeedNMToKt() );
   return instance;
}
uint64_t UnsignedDoubleConverter::SpeedNMToKt::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::SpeedNMToKt::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted * pow( 2, -14 )) * 3600.0 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////    SpeedVelToKt     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::SpeedVelToKt::SpeedVelToKt() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::SpeedVelToKt::get() {
   static std::shared_ptr<SpeedVelToKt> instance = std::make_shared<SpeedVelToKt>( SpeedVelToKt() );
   return instance;
}
uint64_t UnsignedDoubleConverter::SpeedVelToKt::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::SpeedVelToKt::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted * 0.125) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////    Airspeed14Bit     /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Airspeed14Bit::Airspeed14Bit() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Airspeed14Bit::get() {
   static std::shared_ptr<Airspeed14Bit> instance = std::make_shared<Airspeed14Bit>( Airspeed14Bit() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Airspeed14Bit::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::Airspeed14Bit::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   std::bitset<16> converted_value( value_converted );

   if( !converted_value.test( converted_value.size() - 1 ) ) { // IM not set
      return std::to_string( (converted_value.to_ulong() * pow( 2, -14 )) * 3600.0 );
   } else {
      converted_value[converted_value.size() - 1] = 0; // Reset the IM Bit
      return std::to_string( (converted_value.to_ulong() * 0.001) );
   }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////    Fact10     /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::Fact10::Fact10() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::Fact10::get() {
   static std::shared_ptr<Fact10> instance = std::make_shared<Fact10>( Fact10() );
   return instance;
}
uint64_t UnsignedDoubleConverter::Fact10::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::Fact10::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( value_converted * 10.0 );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////    ERange     /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
UnsignedDoubleConverter::ERange::ERange() :
   ItemConverterBase() {
}
std::shared_ptr<ItemConverterBase> UnsignedDoubleConverter::ERange::get() {
   static std::shared_ptr<ERange> instance = std::make_shared<ERange>( ERange() );
   return instance;
}
uint64_t UnsignedDoubleConverter::ERange::toExternal(std::string value, unsigned int value_length) {
   return 0; // TODO implement
}
std::string UnsignedDoubleConverter::ERange::fromExternal(char *value, unsigned int value_length) {
   unsigned long int value_converted = std::stoull( value );
   return std::to_string( (value_converted * (500.0 / pow( 2, 16 ))) );
}

