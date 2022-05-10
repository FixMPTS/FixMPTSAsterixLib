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
      subitem_t( Cat010ItemNames::I010_020_CBT,
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
      subitem_t( Cat010ItemNames::I010_020_LOOP,
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


