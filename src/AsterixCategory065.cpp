/**
 * @file AsterixCategory065.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 8 Jan 2018
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

#include "AsterixCategory065.h"
#include "AsterixItemCompoundLI.h"
#include "AsterixItemFixedLength.h"
#include "AsterixSubitemSigned.h"
#include "AsterixSubitemCompound.h"
#include "AsterixSubitemUnsigned.h"
#include "AsterixSubitemBitNamed.h"
#include "Cat065ItemNames.h"
#include "Exceptions.h"

// Converter
#include "CommonConverter.h"
#include "StringConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory065::AsterixCategory065() :
   AsterixCategory( 65 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory065::AsterixCategory065( int length ) :
   AsterixCategory( 65, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory065::AsterixCategory065( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 65, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory065::~AsterixCategory065() {
}

void AsterixCategory065::setUAP() {

   // Definition of the compound items
   // RE item is a compound item of compound items
   AsterixItemCompound::subUap_T item_re_sub_uap;
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_RE_SRP, 8 ) ) );
   item_re_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_RE_ARL, 2 ) ) );

   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_000, 1 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_015, 1 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_030, 3 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_020, 1 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_040, 1 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat065ItemNames::I065_050, 1 ) ) );
   // FRN 8 to 12 are spare
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemCompoundLI>( Cat065ItemNames::I065_RE, item_re_sub_uap ) ) );
   //SP item not encoded since it is application dependent
}

void AsterixCategory065::setSubitems() {

   subitem_map_t data_Source_identifier;
   data_Source_identifier.push_back(
      subitem_t( Cat065ItemNames::I065_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   data_Source_identifier.push_back(
      subitem_t( Cat065ItemNames::I065_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t message_type;
   message_type.push_back(
      subitem_t( Cat065ItemNames::I065_000_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t service_identification;
   service_identification.push_back(
      subitem_t( Cat065ItemNames::I065_015_SID,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t time_of_mesage;
   time_of_mesage.push_back(
      subitem_t( Cat065ItemNames::I065_030_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::Fraction128th::get() ) ) );

   subitem_map_t batch_number;
   batch_number.push_back(
      subitem_t( Cat065ItemNames::I065_020_BTN,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t sdps_configuration;
   sdps_configuration.push_back(
      subitem_t( Cat065ItemNames::I065_040_NOGO,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Operational" }, { 1, "Degraded" }, {
               2, "Not Connected" }, { 3, "Unknowen" } } ) ) ) );
   sdps_configuration.push_back(
      subitem_t( Cat065ItemNames::I065_040_OVL,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sdps_configuration.push_back(
      subitem_t( Cat065ItemNames::I065_040_TSV,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sdps_configuration.push_back(
      subitem_t( Cat065ItemNames::I065_040_PSS,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Not Applicable" }, { 1, "SDPS 1" }, {
               2, "SDPS 2" }, { 3, "SDPS 3" } } ) ) ) );
   sdps_configuration.push_back(
      subitem_t( Cat065ItemNames::I065_040_STTN,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sdps_configuration.push_back(
      subitem_t( Cat065ItemNames::I065_040_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t service_status_report;
   service_status_report.push_back(
      subitem_t( Cat065ItemNames::I065_050_REPORT,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t reserved_expansion;
   subitem_map_t sub_sub_item_re_srp;
   sub_sub_item_re_srp.push_back(
      subitem_t( Cat065ItemNames::I065_RE_SRP_LAT,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution30Bit::get() ) ) );
   sub_sub_item_re_srp.push_back(
      subitem_t( Cat065ItemNames::I065_RE_SRP_LNG,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution30Bit::get() ) ) );

   // Add all items to the reserved expansion sub item
   reserved_expansion.push_back(
      subitem_t( Cat065ItemNames::I065_RE_SRP,
         std::make_shared<AsterixSubitemCompound>( 64, StringConverter::BitsToNATOtn19Bit::get(),
            sub_sub_item_re_srp ) ) );
   reserved_expansion.push_back(
      subitem_t( Cat065ItemNames::I065_RE_ARL,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter::get() ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, data_Source_identifier ) );
   subitems.insert( subitem_map_item_t( 2, message_type ) );
   subitems.insert( subitem_map_item_t( 3, service_identification ) );
   subitems.insert( subitem_map_item_t( 4, time_of_mesage ) );
   subitems.insert( subitem_map_item_t( 5, batch_number ) );
   subitems.insert( subitem_map_item_t( 6, sdps_configuration ) );
   subitems.insert( subitem_map_item_t( 7, service_status_report ) );
   subitems.insert( subitem_map_item_t( 13, reserved_expansion ) );
}

std::vector<char> AsterixCategory065::getEncodedMessage(SensorServiceRecordType record,
   std::map<std::string, bool> items_to_be_served) {

   // activate all mandatory items for the corresponding message type
   CAT_065_MESSAGE_TYPE type = SDPS_STATUS; // default type
   if( isItemPresent( Cat065ItemNames::I065_000_TYP ) ) {
      type = (CAT_065_MESSAGE_TYPE) std::atoi( unrolled_values[Cat065ItemNames::I065_000_TYP].c_str() );
   }
   items_to_be_served[Cat065ItemNames::I065_000] = true;
   items_to_be_served[Cat065ItemNames::I065_010] = true;
   items_to_be_served[Cat065ItemNames::I065_015] = true;
   items_to_be_served[Cat065ItemNames::I065_030] = true;
   switch( type ){
      case SDPS_STATUS:
         items_to_be_served[Cat065ItemNames::I065_020] = false; // Never present in this type of message
         items_to_be_served[Cat065ItemNames::I065_040] = true;
         items_to_be_served[Cat065ItemNames::I065_050] = false; // Never present
      break;
      case END_OF_BATCH:
         items_to_be_served[Cat065ItemNames::I065_020] = true;
         items_to_be_served[Cat065ItemNames::I065_040] = false;
         items_to_be_served[Cat065ItemNames::I065_050] = false; // Never present
         break;
      case SERVICE_STATUS:
         items_to_be_served[Cat065ItemNames::I065_020] = false; // Never present in this type of message
         items_to_be_served[Cat065ItemNames::I065_040] = false; // Never present
         items_to_be_served[Cat065ItemNames::I065_050] = true;
         break;
      default:
         throw EncodingError( "AsterixCategory065::getEncodedMessage",
            "Unsupported message type " + std::to_string( (int) type ) );
   }

   // set items to be encoded from the input if not set already
   if( !isItemPresent( Cat065ItemNames::I065_030_TOD ) ) {
      setTod( record.getTimeOfDay() );
   }
   return encode( fpsec_item_name_map, items_to_be_served );
}

void AsterixCategory065::fillRecord(std::shared_ptr<ReportRecordType> record) {
}

void AsterixCategory065::setMessageType(unsigned short type) {
   unrolled_values[Cat065ItemNames::I065_000_TYP] = std::to_string( type );
}

void AsterixCategory065::setDataSourceId(unsigned short sac, unsigned short sic) {
   unrolled_values[Cat065ItemNames::I065_010_SAC] = std::to_string( sac );
   unrolled_values[Cat065ItemNames::I065_010_SIC] = std::to_string( sic );
}

void AsterixCategory065::setServiceIdentification(unsigned int id) {
   unrolled_values[Cat065ItemNames::I065_015_SID] = std::to_string( id );
}

void AsterixCategory065::setBatchNumber(unsigned short nr) {
   unrolled_values[Cat065ItemNames::I065_020_BTN] = std::to_string( nr );
}

void AsterixCategory065::setTod(double time_of_day) {
   unrolled_values[Cat065ItemNames::I065_030_TOD] = std::to_string( time_of_day );
}

void AsterixCategory065::setSDPSConfiguration(SDPS_CONFIGURATION config, unsigned short value) {
   std::string converted_value = std::to_string( value );
   switch( config ){
      case NOGO:
         unrolled_values[Cat065ItemNames::I065_040_NOGO] = converted_value;
         break;
      case OVL:
         unrolled_values[Cat065ItemNames::I065_040_OVL] = converted_value;
         break;
      case TSV:
         unrolled_values[Cat065ItemNames::I065_040_TSV] = converted_value;
         break;
      case PSS:
         unrolled_values[Cat065ItemNames::I065_040_PSS] = converted_value;
         break;
      case STTN:
         unrolled_values[Cat065ItemNames::I065_040_STTN] = converted_value;
         break;
   }
}

void AsterixCategory065::setReport(int report) {
   unrolled_values[Cat065ItemNames::I065_050_REPORT] = std::to_string( report );
}

void AsterixCategory065::setReLatLng(double lat, double lng) {
   unrolled_values[Cat065ItemNames::I065_RE_SRP_LAT] = std::to_string( lat );
   unrolled_values[Cat065ItemNames::I065_RE_SRP_LNG] = std::to_string( lng );
}

void AsterixCategory065::setSrp(int srp) {
   unrolled_values[Cat065ItemNames::I065_RE_SRP] = std::to_string( srp );
}

void AsterixCategory065::setArl(int arl) {
   unrolled_values[Cat065ItemNames::I065_RE_ARL] = std::to_string( arl );
}
