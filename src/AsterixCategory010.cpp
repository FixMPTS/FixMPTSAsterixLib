/**
 * @file AsterixCategory010.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 15 Dec 2017
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
 * See .h file for more informations
 */

// Asterix include
#include "AsterixCategory010.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemRepetetive.h"
#include "AsterixItemVariableLength.h"
#include "AsterixSubitemSigned.h"
#include "AsterixSubitemUnsigned.h"
#include "AsterixSubitemBitNamed.h"
#include "Cat010ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "StringConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory010::AsterixCategory010() :
   AsterixCategory( 10 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory010::AsterixCategory010( int length ) :
   AsterixCategory( 10, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory010::AsterixCategory010( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 10, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory010::~AsterixCategory010() {
}

void AsterixCategory010::setUAP() {
   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_000, 1 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemVariableLength>( Cat010ItemNames::I010_020 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_140, 3 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_041, 8 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_040, 4 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_042, 4 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_200, 4 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_202, 4 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_161, 2 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemVariableLength>( Cat010ItemNames::I010_170 ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_060, 2 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_220, 3 ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_245, 7 ) ) );
   uap.insert( UAP_Item_T( 15, std::make_shared<AsterixItemRepetetive>( Cat010ItemNames::I010_250, 8 ) ) );
   uap.insert( UAP_Item_T( 16, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_300, 1 ) ) );
   uap.insert( UAP_Item_T( 17, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_090, 2 ) ) );
   uap.insert( UAP_Item_T( 18, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_091, 2 ) ) );
   uap.insert( UAP_Item_T( 19, std::make_shared<AsterixItemVariableLength>( Cat010ItemNames::I010_270 ) ) );
   uap.insert( UAP_Item_T( 20, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_550, 1 ) ) );
   uap.insert( UAP_Item_T( 21, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_310, 1 ) ) );
   uap.insert( UAP_Item_T( 22, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_500, 4 ) ) );
   uap.insert( UAP_Item_T( 23, std::make_shared<AsterixItemRepetetive>( Cat010ItemNames::I010_280, 2 ) ) );
   uap.insert( UAP_Item_T( 24, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_131, 1 ) ) );
   uap.insert( UAP_Item_T( 25, std::make_shared<AsterixItemFixedLength>( Cat010ItemNames::I010_210, 2 ) ) );
   // RE and SP items are not yet specified by the Asterix Board
}

void AsterixCategory010::setSubitems() {
   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat010ItemNames::I010_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   sensor_identification.push_back(
      subitem_t( Cat010ItemNames::I010_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t message_type;
   message_type.push_back(
      subitem_t( Cat010ItemNames::I010_000_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t target_report_descriptor;
   target_report_descriptor.push_back(
      subitem_t( Cat010ItemNames::I010_020_TYP,
         std::make_shared<AsterixSubitemBitNamed>( 3, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "SSR MLT" }, { 1, "Mode S MLT" }, { 2,
               "ADS-B" }, { 3, "PSR" }, { 4, "MLOOP" }, { 5, "HF MLT" }, { 6, "Not Defined" }, { 7,
               "Other" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat010ItemNames::I010_020_DCR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat010ItemNames::I010_020_CHN,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat010ItemNames::I010_020_GBS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat010ItemNames::I010_020_CRT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat010ItemNames::I010_020_SIM,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat010ItemNames::I010_020_TST,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat010ItemNames::I010_020_RAB,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat010ItemNames::I010_020_LOP,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat010ItemNames::I010_020_TOT,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat010ItemNames::I010_020_SPI,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t time_of_day;
   time_of_day.push_back(
      subitem_t( Cat010ItemNames::I010_140_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::Fraction128th::get() ) ) );

   subitem_map_t position_wgs84;
   position_wgs84.push_back(
      subitem_t( Cat010ItemNames::I010_041_LAT,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution31Bit::get() ) ) );
   position_wgs84.push_back(
      subitem_t( Cat010ItemNames::I010_041_LNG,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS84resolution31Bit::get() ) ) );

   subitem_map_t position_polar;
   position_polar.push_back(
      subitem_t( Cat010ItemNames::I010_040_RHO,
         std::make_shared<AsterixSubitemSigned>( 16, CommonConverter::NoneConverter::get() ) ) );
   position_polar.push_back(
      subitem_t( Cat010ItemNames::I010_040_THETA,
         std::make_shared<AsterixSubitemSigned>( 16,
            UnsignedDoubleConverter::Direction16Bit::get() ) ) );

   subitem_map_t position_cartesian;
   position_cartesian.push_back(
      subitem_t( Cat010ItemNames::I010_042_X,
         std::make_shared<AsterixSubitemSigned>( 16, CommonConverter::NoneConverter::get() ) ) );
   position_cartesian.push_back(
      subitem_t( Cat010ItemNames::I010_042_Y,
         std::make_shared<AsterixSubitemSigned>( 16, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t track_velocity_polar;
   track_velocity_polar.push_back(
      subitem_t( Cat010ItemNames::I010_200_GSP,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::SpeedNMToKt::get() ) ) );
   track_velocity_polar.push_back(
      subitem_t( Cat010ItemNames::I010_200_TA,
         std::make_shared<AsterixSubitemUnsigned>( 16,
            UnsignedDoubleConverter::Direction16Bit::get() ) ) );

   subitem_map_t track_velocity_cartesian;
   track_velocity_cartesian.push_back(
      subitem_t( Cat010ItemNames::I010_202_VX,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::Fraction4th::get() ) ) );
   track_velocity_cartesian.push_back(
      subitem_t( Cat010ItemNames::I010_202_VY,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::Fraction4th::get() ) ) );

   subitem_map_t track_number;
   track_number.push_back(
      subitem_t( Cat010ItemNames::I010_161_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   track_number.push_back(
      subitem_t( Cat010ItemNames::I010_161_TRK,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t track_status;
   track_status.push_back(
      subitem_t( Cat010ItemNames::I010_170_CNF,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat010ItemNames::I010_170_TRE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat010ItemNames::I010_170_CST,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat010ItemNames::I010_170_MAH,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat010ItemNames::I010_170_TCC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat010ItemNames::I010_170_STH,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat010ItemNames::I010_170_TOM,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat010ItemNames::I010_170_DOU,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat010ItemNames::I010_170_MRS,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat010ItemNames::I010_170_GHO,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t m3a_oct;
   m3a_oct.push_back(
      subitem_t( Cat010ItemNames::I010_060_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   m3a_oct.push_back(
      subitem_t( Cat010ItemNames::I010_060_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   m3a_oct.push_back(
      subitem_t( Cat010ItemNames::I010_060_L,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   m3a_oct.push_back(
      subitem_t( Cat010ItemNames::I010_060_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   m3a_oct.push_back(
      subitem_t( Cat010ItemNames::I010_060_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t target_addr;
   target_addr.push_back(
      subitem_t( Cat010ItemNames::I010_220_ADDR,
         std::make_shared<AsterixSubitemUnsigned>( 24, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t target_id;
   target_id.push_back(
      subitem_t( Cat010ItemNames::I010_245_STI,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   target_id.push_back(
      subitem_t( Cat010ItemNames::I010_245_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter::get() ) ) );
   target_id.push_back(
      subitem_t( Cat010ItemNames::I010_245_ID,
         std::make_shared<AsterixSubitemUnsigned>( 48, StringConverter::To6BitChar::get() ) ) );

   subitem_map_t mode_s_mb_data;
   mode_s_mb_data.push_back(
      subitem_t( Cat010ItemNames::I010_250_DATA,
         std::make_shared<AsterixSubitemUnsigned>( 56, CommonConverter::NoneConverter::get() ) ) );
   mode_s_mb_data.push_back(
      subitem_t( Cat010ItemNames::I010_250_BDS1,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   mode_s_mb_data.push_back(
      subitem_t( Cat010ItemNames::I010_250_BDS2,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t vehicle_fleet_information;
   vehicle_fleet_information.push_back(
      subitem_t( Cat010ItemNames::I010_300_VFI,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t flightlevel_bin;
   flightlevel_bin.push_back(
      subitem_t( Cat010ItemNames::I010_090_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   flightlevel_bin.push_back(
      subitem_t( Cat010ItemNames::I010_090_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   flightlevel_bin.push_back(
      subitem_t( Cat010ItemNames::I010_090_FL,
         std::make_shared<AsterixSubitemSigned>( 14, DoubleConverter::Fraction4th::get() ) ) );

   subitem_map_t measured_height;
   measured_height.push_back(
      subitem_t( Cat010ItemNames::I010_091_ALT,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::GeoAltitudeFt::get() ) ) );

   subitem_map_t target_size;
   target_size.push_back(
      subitem_t( Cat010ItemNames::I010_270_L,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter::get() ) ) );
   target_size.push_back(
      subitem_t( Cat010ItemNames::I010_270_O,
         std::make_shared<AsterixSubitemUnsigned>( 7, UnsignedDoubleConverter::Direction128th::get() ) ) );
   target_size.push_back(
      subitem_t( Cat010ItemNames::I010_270_W,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t system_status;
   system_status.push_back(
      subitem_t( Cat010ItemNames::I010_550_NOGO,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   system_status.push_back(
      subitem_t( Cat010ItemNames::I010_550_OVL,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   system_status.push_back(
      subitem_t( Cat010ItemNames::I010_550_TSV,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   system_status.push_back(
      subitem_t( Cat010ItemNames::I010_550_DIV,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   system_status.push_back(
      subitem_t( Cat010ItemNames::I010_550_TTF,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t preprogrammed_msg;
   preprogrammed_msg.push_back(
      subitem_t( Cat010ItemNames::I010_310_TRB,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   preprogrammed_msg.push_back(
      subitem_t( Cat010ItemNames::I010_310_MSG,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t std_dev_position;
   std_dev_position.push_back(
      subitem_t( Cat010ItemNames::I010_500_DX,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   std_dev_position.push_back(
      subitem_t( Cat010ItemNames::I010_500_DY,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   std_dev_position.push_back(
      subitem_t( Cat010ItemNames::I010_500_DXY,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::Fraction4th::get() ) ) );

   subitem_map_t presence;
   presence.push_back(
      subitem_t( Cat010ItemNames::I010_280_DRHO,
         std::make_shared<AsterixSubitemSigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   presence.push_back(
      subitem_t( Cat010ItemNames::I010_280_DTHETA,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::Factor015::get() ) ) );

   subitem_map_t psr_aplitude;
   psr_aplitude.push_back(
      subitem_t( Cat010ItemNames::I010_131_AMP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t calculated_acc;
   calculated_acc.push_back(
      subitem_t( Cat010ItemNames::I010_210_AX,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::Fraction4th::get() ) ) );
   calculated_acc.push_back(
      subitem_t( Cat010ItemNames::I010_210_AY,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::Fraction4th::get() ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, message_type ) );
   subitems.insert( subitem_map_item_t( 3, target_report_descriptor ) );
   subitems.insert( subitem_map_item_t( 4, time_of_day ) );
   subitems.insert( subitem_map_item_t( 5, position_wgs84 ) );
   subitems.insert( subitem_map_item_t( 6, position_polar ) );
   subitems.insert( subitem_map_item_t( 7, position_cartesian ) );
   subitems.insert( subitem_map_item_t( 8, track_velocity_polar ) );
   subitems.insert( subitem_map_item_t( 9, track_velocity_cartesian ) );
   subitems.insert( subitem_map_item_t( 10, track_number ) );
   subitems.insert( subitem_map_item_t( 11, track_status ) );
   subitems.insert( subitem_map_item_t( 12, m3a_oct ) );
   subitems.insert( subitem_map_item_t( 13, target_addr ) );
   subitems.insert( subitem_map_item_t( 14, target_id ) );
   subitems.insert( subitem_map_item_t( 15, mode_s_mb_data ) );
   subitems.insert( subitem_map_item_t( 16, vehicle_fleet_information ) );
   subitems.insert( subitem_map_item_t( 17, flightlevel_bin ) );
   subitems.insert( subitem_map_item_t( 18, measured_height ) );
   subitems.insert( subitem_map_item_t( 19, target_size ) );
   subitems.insert( subitem_map_item_t( 20, system_status ) );
   subitems.insert( subitem_map_item_t( 21, preprogrammed_msg ) );
   subitems.insert( subitem_map_item_t( 22, std_dev_position ) );
   subitems.insert( subitem_map_item_t( 23, presence ) );
   subitems.insert( subitem_map_item_t( 24, psr_aplitude ) );
   subitems.insert( subitem_map_item_t( 25, calculated_acc ) );
}

void AsterixCategory010::fillRecord(std::shared_ptr<ReportRecordType> record) {
}

std::vector<char> AsterixCategory010::getEncodedMessage(TrackTypeIf track, ReportRecordType record,
   std::map<std::string, bool> items_to_be_served) {

   // activate encoding of mandatory items
   items_to_be_served[Cat010ItemNames::I010_000] = true;
   items_to_be_served[Cat010ItemNames::I010_010] = true;
   items_to_be_served[Cat010ItemNames::I010_140] = true;
   // Mandatory items depending on the message type
   CAT_010_MESSAGE_TYPE type = TARGET_REPORT; // default type
   if( isItemPresent( Cat010ItemNames::I010_000_TYP ) ) {
      type = static_cast<CAT_010_MESSAGE_TYPE>( std::atoi( getValue( Cat010ItemNames::I010_000_TYP ).c_str() ) );
   }

   switch( type ){
      case TARGET_REPORT:
         items_to_be_served[Cat010ItemNames::I010_020] = true;
         items_to_be_served[Cat010ItemNames::I010_550] = false; // Never present
         break;
      case PERIODIC_STATUS_MSG: // fall through because same as EVENT_TRIGGERED_STATUS_MSG
      case EVENT_TRIGGERED_STATUS_MSG:
         items_to_be_served[Cat010ItemNames::I010_550] = true;
         // fall trough because disabled items are the same as in START_UPDATE_CYLE
      case START_UPDATE_CYLE: //
         items_to_be_served[Cat010ItemNames::I010_020] = false; // Never present
         items_to_be_served[Cat010ItemNames::I010_040] = false;
         items_to_be_served[Cat010ItemNames::I010_041] = false;
         items_to_be_served[Cat010ItemNames::I010_042] = false;
         items_to_be_served[Cat010ItemNames::I010_060] = false;
         items_to_be_served[Cat010ItemNames::I010_090] = false;
         items_to_be_served[Cat010ItemNames::I010_091] = false;
         items_to_be_served[Cat010ItemNames::I010_131] = false;
         items_to_be_served[Cat010ItemNames::I010_161] = false;
         items_to_be_served[Cat010ItemNames::I010_170] = false;
         items_to_be_served[Cat010ItemNames::I010_200] = false;
         items_to_be_served[Cat010ItemNames::I010_202] = false;
         items_to_be_served[Cat010ItemNames::I010_210] = false;
         items_to_be_served[Cat010ItemNames::I010_220] = false;
         items_to_be_served[Cat010ItemNames::I010_245] = false;
         items_to_be_served[Cat010ItemNames::I010_250] = false;
         items_to_be_served[Cat010ItemNames::I010_270] = false;
         items_to_be_served[Cat010ItemNames::I010_280] = false;
         items_to_be_served[Cat010ItemNames::I010_300] = false;
         items_to_be_served[Cat010ItemNames::I010_310] = false;
         items_to_be_served[Cat010ItemNames::I010_500] = false;
         break;
      default:
         throw EncodingError( "AsterixCategory010::getEncodedMessage",
            "Unsupported message type " + std::to_string( (int) type ) );
         break;
   }

   // set items to be encoded from input type if not set already
   if( !isItemPresent( Cat010ItemNames::I010_010_SAC ) || !isItemPresent( Cat010ItemNames::I010_010_SIC ) ) {
      setDataSourceIdentifier( std::get<0>( record.getSourceID() ), std::get<1>( record.getSourceID() ) );
   }
   if( (!isItemPresent( Cat010ItemNames::I010_040_RHO ) || !isItemPresent( Cat010ItemNames::I010_040_THETA ))
      && record.isRangeAzimuthPresent() ) {
      setMeasuredPosition( std::get<0>( record.getRangeAzimuth() ), std::get<1>( record.getRangeAzimuth() ) );
   }
   if( (!isItemPresent( Cat010ItemNames::I010_041_LAT ) || !isItemPresent( Cat010ItemNames::I010_041_LNG ))
      && record.isGeoPosPresent() ) {
      setWGSPosition( std::get<0>( record.getGeoPos() ), std::get<1>( record.getGeoPos() ) );
   }
   if( !isItemPresent( Cat010ItemNames::I010_060_CODE ) && record.isMode3APresent() ) {
      setMode3A( record.isMode3AValid(), record.isMode3AGarbled(), false, record.getMode3ACode() );
   }
   if( !isItemPresent( Cat010ItemNames::I010_140_TOD ) ) { // TOD is mandatory in the report
      setTod( record.getDetectionTime() );
   }

   return encode( fpsec_item_name_map, items_to_be_served );
}

void AsterixCategory010::setDataSourceIdentifier(unsigned short sac, unsigned short sic) {
   unrolled_values[Cat010ItemNames::I010_010_SAC] = std::to_string( sac );
   unrolled_values[Cat010ItemNames::I010_010_SIC] = std::to_string( sic );
}

void AsterixCategory010::setMessageType(unsigned short type) {
   unrolled_values[Cat010ItemNames::I010_000_TYP] = std::to_string( type );
}

void AsterixCategory010::setTod(double tod) {
   unrolled_values[Cat010ItemNames::I010_140_TOD] = std::to_string( tod );
}

void AsterixCategory010::setTargetReportDescriptor(TARGET_REPPORT_DESCRIPTOR item, unsigned short value) {
   std::string final_value = std::to_string( value );
   switch( item ){
      case TYPE:
         unrolled_values[Cat010ItemNames::I010_020_TYP] = final_value;
         break;
      case DCR:
         unrolled_values[Cat010ItemNames::I010_020_DCR] = final_value;
         break;
      case CHN:
         unrolled_values[Cat010ItemNames::I010_020_CHN] = final_value;
         break;
      case GBS:
         unrolled_values[Cat010ItemNames::I010_020_GBS] = final_value;
         break;
      case CRT:
         unrolled_values[Cat010ItemNames::I010_020_CRT] = final_value;
         break;
      case SIM:
         unrolled_values[Cat010ItemNames::I010_020_SIM] = final_value;
         break;
      case TST:
         unrolled_values[Cat010ItemNames::I010_020_TST] = final_value;
         break;
      case RAB:
         unrolled_values[Cat010ItemNames::I010_020_RAB] = final_value;
         break;
      case LOP:
         unrolled_values[Cat010ItemNames::I010_020_LOP] = final_value;
         break;
      case TOT:
         unrolled_values[Cat010ItemNames::I010_020_TOT] = final_value;
         break;
      case SPI:
         unrolled_values[Cat010ItemNames::I010_020_SPI] = final_value;
         break;
      default:
         throw EncodingError( "AsterixCategory010::getEncodedMessage",
            "Unsupported target report descriptor type " + std::to_string( (int) item ) );
   }
}

void AsterixCategory010::setMeasuredPosition(double rho, double theta) {
   unrolled_values[Cat010ItemNames::I010_040_RHO] = std::to_string( rho );
   unrolled_values[Cat010ItemNames::I010_040_THETA] = std::to_string( theta );
}

void AsterixCategory010::setWGSPosition(double lat, double lng) {
   unrolled_values[Cat010ItemNames::I010_041_LAT] = std::to_string( lat );
   unrolled_values[Cat010ItemNames::I010_041_LNG] = std::to_string( lng );
}

void AsterixCategory010::setCartesianPosition(double x, double y) {
   unrolled_values[Cat010ItemNames::I010_042_X] = std::to_string( x );
   unrolled_values[Cat010ItemNames::I010_042_Y] = std::to_string( y );
}

void AsterixCategory010::setMode3A(bool v, bool g, bool l, int code) {
   unrolled_values[Cat010ItemNames::I010_060_V] = std::to_string( v );
   unrolled_values[Cat010ItemNames::I010_060_G] = std::to_string( g );
   unrolled_values[Cat010ItemNames::I010_060_L] = std::to_string( l );
   unrolled_values[Cat010ItemNames::I010_060_CODE] = std::to_string( code );
}

void AsterixCategory010::setFlightLevel(bool v, bool g, float level) {
   unrolled_values[Cat010ItemNames::I010_090_V] = std::to_string( v );
   unrolled_values[Cat010ItemNames::I010_090_G] = std::to_string( g );
   unrolled_values[Cat010ItemNames::I010_090_FL] = std::to_string( level );
}

void AsterixCategory010::setMeasuredHeight(float height) {
   unrolled_values[Cat010ItemNames::I010_091_ALT] = std::to_string( height );
}

void AsterixCategory010::setPRAmplitude(int amplitude) {
   unrolled_values[Cat010ItemNames::I010_131_AMP] = std::to_string( amplitude );
}

void AsterixCategory010::setToD(double tod) {
   unrolled_values[Cat010ItemNames::I010_140_TOD] = std::to_string( tod );
}

void AsterixCategory010::setTrackNumber(unsigned int nr) {
   unrolled_values[Cat010ItemNames::I010_161_TRK] = std::to_string( nr );
}

void AsterixCategory010::setTrackStatus(TRACK_STATUS status, unsigned short value) {
   switch( status ){
      case TRACK_STATUS::CNF:
         unrolled_values[Cat010ItemNames::I010_170_CNF] = std::to_string( value );
         break;
      case TRACK_STATUS::CST:
         unrolled_values[Cat010ItemNames::I010_170_CST] = std::to_string( value );
         break;
      case TRACK_STATUS::DOU:
         unrolled_values[Cat010ItemNames::I010_170_DOU] = std::to_string( value );
         break;
      case TRACK_STATUS::GHO:
         unrolled_values[Cat010ItemNames::I010_170_GHO] = std::to_string( value );
         break;
      case TRACK_STATUS::MAH:
         unrolled_values[Cat010ItemNames::I010_170_MAH] = std::to_string( value );
         break;
      case TRACK_STATUS::MRS:
         unrolled_values[Cat010ItemNames::I010_170_MRS] = std::to_string( value );
         break;
      case TRACK_STATUS::STH:
         unrolled_values[Cat010ItemNames::I010_170_STH] = std::to_string( value );
         break;
      case TRACK_STATUS::TCC:
         unrolled_values[Cat010ItemNames::I010_170_TCC] = std::to_string( value );
         break;
      case TRACK_STATUS::TOM:
         unrolled_values[Cat010ItemNames::I010_170_TOM] = std::to_string( value );
         break;
      case TRACK_STATUS::TRE:
         unrolled_values[Cat010ItemNames::I010_170_TRE] = std::to_string( value );
         break;
   }
}

void AsterixCategory010::setCaculatedVelocityPolar(double speed, double angle) {
   unrolled_values[Cat010ItemNames::I010_200_GSP] = std::to_string( speed );
   unrolled_values[Cat010ItemNames::I010_200_TA] = std::to_string( angle );
}

void AsterixCategory010::setCalculatedVelocityCartesian(double vx, double vy) {
   unrolled_values[Cat010ItemNames::I010_202_VX] = std::to_string( vx );
   unrolled_values[Cat010ItemNames::I010_202_VY] = std::to_string( vy );
}

void AsterixCategory010::setCalculatedAcceleration(double ax, double ay) {
   unrolled_values[Cat010ItemNames::I010_210_AX] = std::to_string( ax );
   unrolled_values[Cat010ItemNames::I010_210_AY] = std::to_string( ay );
}

void AsterixCategory010::setTargetAddress(unsigned long addr) {
   unrolled_values[Cat010ItemNames::I010_220_ADDR] = std::to_string( addr );
}

void AsterixCategory010::setTargetIdentification(short sti, char id[8]) {
   unrolled_values[Cat010ItemNames::I010_245_STI] = std::to_string( sti );
   unrolled_values[Cat010ItemNames::I010_245_ID] = id;
}

void AsterixCategory010::addModeSMBData(unsigned long mbd, short bds1, short bds2) {
   // get last index
   unsigned short index = 0;
   for( ;; index++ ) {
      std::string key = Cat010ItemNames::I010_250_DATA + "." + std::to_string( index );
      if( !isItemPresent( key ) ) {
         break; // First index not in use found
      }
   }
   std::string str_index = "." + std::to_string( index );
   unrolled_values[Cat010ItemNames::I010_250_DATA + str_index] = std::to_string( mbd );
   unrolled_values[Cat010ItemNames::I010_250_BDS1 + str_index] = std::to_string( bds1 );
   unrolled_values[Cat010ItemNames::I010_250_BDS2 + str_index] = std::to_string( bds2 );
}

void AsterixCategory010::removeModeSMBData(unsigned long mbd) {
   unsigned short index = 0;
   bool found = false;
   for( ;; index++ ) {
      std::string key = Cat010ItemNames::I010_250_DATA + "." + std::to_string( index );
      if( !isItemPresent( key ) ) {
         break; //End found
      } else if( getValue( key ) == std::to_string( mbd ) ) {
         found = true;
         std::string str_index = "." + std::to_string( index );
         unrolled_values.erase( Cat010ItemNames::I010_250_DATA + str_index );
         unrolled_values.erase( Cat010ItemNames::I010_250_BDS1 + str_index );
         unrolled_values.erase( Cat010ItemNames::I010_250_BDS2 + str_index );
      } else if( found ) {
         // set index -1
         std::string str_index = "." + std::to_string( index );
         std::string str_prev_index = "." + std::to_string( index - 1 );
         unrolled_values[Cat010ItemNames::I010_250_DATA + str_prev_index] = unrolled_values.at(
            Cat010ItemNames::I010_250_DATA + str_index );
         unrolled_values[Cat010ItemNames::I010_250_BDS1 + str_prev_index] = unrolled_values.at(
            Cat010ItemNames::I010_250_BDS1 + str_index );
         unrolled_values[Cat010ItemNames::I010_250_BDS2 + str_prev_index] = unrolled_values.at(
            Cat010ItemNames::I010_250_BDS2 + str_index );
         unrolled_values.erase( Cat010ItemNames::I010_250_DATA + str_index );
         unrolled_values.erase( Cat010ItemNames::I010_250_BDS1 + str_index );
         unrolled_values.erase( Cat010ItemNames::I010_250_BDS2 + str_index );
      }
   }
}

void AsterixCategory010::clearModeSMBData() {
   unsigned short index = 0;
   for( ;; index++ ) {
      std::string key = Cat010ItemNames::I010_250_DATA + "." + std::to_string( index );
      if( !isItemPresent( key ) ) {
         break; //End found
      } else {
         std::string str_index = "." + std::to_string( index );
         unrolled_values.erase( Cat010ItemNames::I010_250_DATA + str_index );
         unrolled_values.erase( Cat010ItemNames::I010_250_BDS1 + str_index );
         unrolled_values.erase( Cat010ItemNames::I010_250_BDS2 + str_index );
      }
   }
}

void AsterixCategory010::setTargetSizeOrientation(short length, double orientation, short width) {
   unrolled_values[Cat010ItemNames::I010_270_L] = std::to_string( length );
   unrolled_values[Cat010ItemNames::I010_270_O] = std::to_string( orientation );
   unrolled_values[Cat010ItemNames::I010_270_W] = std::to_string( width );
}

void AsterixCategory010::addPresence(double drho, double dtheta) {
   // get last index
   unsigned short index = 0;
   for( ;; index++ ) { // TODO put loop in static method
      std::string key = Cat010ItemNames::I010_280_DRHO + "." + std::to_string( index );
      if( !isItemPresent( key ) ) {
         break; // First index not in use found
      }
   }
   std::string str_index = "." + std::to_string( index );
   unrolled_values[Cat010ItemNames::I010_280_DRHO + str_index] = std::to_string( drho );
   unrolled_values[Cat010ItemNames::I010_280_DTHETA + str_index] = std::to_string( dtheta );
}

void AsterixCategory010::removePresence(double drho, double dtheta) {
   unsigned short index = 0;
   bool found = false;
   for( ;; index++ ) {
      std::string key = Cat010ItemNames::I010_280_DRHO + "." + std::to_string( index );
      if( !isItemPresent( key ) ) {
         break; //End found
      } else if( getValue( key ) == std::to_string( drho )
         && getValue( Cat010ItemNames::I010_280_DTHETA + "." + std::to_string( index ) ) == std::to_string( dtheta ) ) {
         found = true;
         std::string str_index = "." + std::to_string( index );
         unrolled_values.erase( Cat010ItemNames::I010_280_DRHO + str_index );
         unrolled_values.erase( Cat010ItemNames::I010_280_DTHETA + str_index );
      } else if( found ) {
         // set index -1
         std::string str_index = "." + std::to_string( index );
         std::string str_prev_index = "." + std::to_string( index - 1 );
         unrolled_values[Cat010ItemNames::I010_280_DRHO + str_prev_index] = unrolled_values.at(
            Cat010ItemNames::I010_280_DRHO + str_index );
         unrolled_values[Cat010ItemNames::I010_280_DTHETA + str_prev_index] = unrolled_values.at(
            Cat010ItemNames::I010_280_DTHETA + str_index );
         unrolled_values.erase( Cat010ItemNames::I010_280_DRHO + str_index );
         unrolled_values.erase( Cat010ItemNames::I010_280_DTHETA + str_index );
      }
   }
}

void AsterixCategory010::clearPresence() {
   unsigned short index = 0;
   for( ;; index++ ) {
      std::string key = Cat010ItemNames::I010_280_DRHO + "." + std::to_string( index );
      if( !isItemPresent( key ) ) {
         break; //End found
      } else {
         std::string str_index = "." + std::to_string( index );
         unrolled_values.erase( Cat010ItemNames::I010_280_DRHO + str_index );
         unrolled_values.erase( Cat010ItemNames::I010_280_DTHETA + str_index );
      }
   }
}

void AsterixCategory010::setVehicleFleet(VEHICLE_FLEET_ID vfid) {
   unrolled_values[Cat010ItemNames::I010_300_VFI] = std::to_string( (unsigned short) vfid );
}

void AsterixCategory010::setProgrammedMsg(bool trb, unsigned short msg) {
   unrolled_values[Cat010ItemNames::I010_310_TRB] = std::to_string( trb );
   unrolled_values[Cat010ItemNames::I010_310_MSG] = std::to_string( msg );
}

void AsterixCategory010::setStdDeviationPos(double dx, double dy, double dxz) {
   unrolled_values[Cat010ItemNames::I010_500_DX] = std::to_string( dx );
   unrolled_values[Cat010ItemNames::I010_500_DY] = std::to_string( dy );
   unrolled_values[Cat010ItemNames::I010_500_DXY] = std::to_string( dxz );
}

void AsterixCategory010::setSystemStatus(short nogo, bool ovl, bool tsv, bool div, bool ttf) {
   unrolled_values[Cat010ItemNames::I010_550_NOGO] = std::to_string( nogo );
   unrolled_values[Cat010ItemNames::I010_550_OVL] = std::to_string( ovl );
   unrolled_values[Cat010ItemNames::I010_550_TSV] = std::to_string( tsv );
   unrolled_values[Cat010ItemNames::I010_550_DIV] = std::to_string( div );
   unrolled_values[Cat010ItemNames::I010_550_TTF] = std::to_string( ttf );
}
