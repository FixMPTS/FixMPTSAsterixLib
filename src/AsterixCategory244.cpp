/**
 * @file AsterixCategory244.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 12 Jan 2018
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

#include "AsterixCategory244.h"
#include "AsterixItemRepetetive.h"
#include "AsterixItemFixedLength.h"
#include "AsterixSubitemSigned.h"
#include "AsterixSubitemBytes.h"
#include "AsterixSubitemUnsigned.h"
#include "Cat244ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "StringConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory244::AsterixCategory244() :
   AsterixCategory( 244 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory244::AsterixCategory244( int length ) :
   AsterixCategory( 244, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory244::AsterixCategory244( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 244, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory244::~AsterixCategory244() {
}

void AsterixCategory244::setUAP() {
   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_020, 3 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_030, 8 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_040, 2 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_045, 2 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_050, 2 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_055, 2 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_060, 2 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_065, 2 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_070, 2 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_075, 2 ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_080, 6 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_095, 1 ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemRepetetive>( Cat244ItemNames::I244_100, 11 ) ) );
   uap.insert( UAP_Item_T( 15, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_115, 2 ) ) );
   uap.insert( UAP_Item_T( 16, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_120, 3 ) ) );
   uap.insert( UAP_Item_T( 17, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_130, 2 ) ) );
   uap.insert( UAP_Item_T( 18, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_140, 6 ) ) );
   uap.insert( UAP_Item_T( 19, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_150, 4 ) ) );
   uap.insert( UAP_Item_T( 20, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_160, 1 ) ) );
   uap.insert( UAP_Item_T( 21, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_170, 1 ) ) );
   uap.insert( UAP_Item_T( 22, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_180, 2 ) ) );
   uap.insert( UAP_Item_T( 23, std::make_shared<AsterixItemFixedLength>( Cat244ItemNames::I244_190, 1 ) ) );
   // SP and RE item not defined in the Asterix Spec yet and are terefore not handled
}

void AsterixCategory244::setSubitems() {
   subitem_map_t trajectory_identifioer;
   trajectory_identifioer.push_back(
      subitem_t( Cat244ItemNames::I244_010_TID,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );

   subitem_map_t time_of_day;
   time_of_day.push_back(
      subitem_t( Cat244ItemNames::I244_020_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::fraction128th ) ) );

   subitem_map_t position_wgs84;
   position_wgs84.push_back(
      subitem_t( Cat244ItemNames::I244_030_LAT,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS8490degResolution31Bit ) ) );
   position_wgs84.push_back(
      subitem_t( Cat244ItemNames::I244_030_LNG,
         std::make_shared<AsterixSubitemSigned>( 32, DoubleConverter::WGS8490degResolution31Bit ) ) );

   subitem_map_t geometric_altitude;
   geometric_altitude.push_back(
      subitem_t( Cat244ItemNames::I244_040_FL,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::geoAltitudeFt ) ) );

   subitem_map_t flight_level;
   flight_level.push_back(
      subitem_t( Cat244ItemNames::I244_045_ALT,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction4th ) ) );

   subitem_map_t ground_Speed;
   ground_Speed.push_back(
      subitem_t( Cat244ItemNames::I244_050_GSP,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::speedNMToKt ) ) );

   subitem_map_t air_speed;
   air_speed.push_back(
      subitem_t( Cat244ItemNames::I244_055_SPEED,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::airspeed14Bit ) ) );

   subitem_map_t course;
   course.push_back(
      subitem_t( Cat244ItemNames::I244_060_TA,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );

   subitem_map_t magnetic_heading;
   magnetic_heading.push_back(
      subitem_t( Cat244ItemNames::I244_065_HDG,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::direction16Bit ) ) );

   subitem_map_t vertical_rate;
   vertical_rate.push_back(
      subitem_t( Cat244ItemNames::I244_070_VR,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::geoAltitudeFt ) ) );

   subitem_map_t barometric_vertical_rate;
   barometric_vertical_rate.push_back(
      subitem_t( Cat244ItemNames::I244_075_VR,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::geoAltitudeFt ) ) );

   subitem_map_t accelerations;
   accelerations.push_back(
      subitem_t( Cat244ItemNames::I244_080_ALONG,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::groundVectorAcceleration ) ) );
   accelerations.push_back(
      subitem_t( Cat244ItemNames::I244_080_ACROSS,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::groundVectorAcceleration ) ) );
   accelerations.push_back(
      subitem_t( Cat244ItemNames::I244_080_VERTICAL,
         std::make_shared<AsterixSubitemSigned>( 16, DoubleConverter::groundVectorAcceleration ) ) );

   subitem_map_t turn_rate;
   turn_rate.push_back(
      subitem_t( Cat244ItemNames::I244_095_RATE,
         std::make_shared<AsterixSubitemSigned>( 8, DoubleConverter::fraction8th ) ) );

   subitem_map_t ads_b_profile;
   ads_b_profile.push_back(
      subitem_t( Cat244ItemNames::I244_100_ALT,
         std::make_shared<AsterixSubitemSigned>( 16, UnsignedDoubleConverter::fraction10th ) ) );
   ads_b_profile.push_back(
      subitem_t( Cat244ItemNames::I244_100_LAT,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );
   ads_b_profile.push_back(
      subitem_t( Cat244ItemNames::I244_100_LNG,
         std::make_shared<AsterixSubitemSigned>( 24, DoubleConverter::WGS84resolution23Bit ) ) );
   ads_b_profile.push_back(
      subitem_t( Cat244ItemNames::I244_100_TTA,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   ads_b_profile.push_back(
      subitem_t( Cat244ItemNames::I244_100_TTG,
         std::make_shared<AsterixSubitemUnsigned>( 15, UnsignedDoubleConverter::speedVelToKt ) ) );
   ads_b_profile.push_back(
      subitem_t( Cat244ItemNames::I244_100_TCA,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   ads_b_profile.push_back(
      subitem_t( Cat244ItemNames::I244_100_NC,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   ads_b_profile.push_back(
      subitem_t( Cat244ItemNames::I244_100_TCN,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter ) ) );

   subitem_map_t selected_altitude;
   selected_altitude.push_back(
      subitem_t( Cat244ItemNames::I244_115_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   selected_altitude.push_back(
      subitem_t( Cat244ItemNames::I244_115_FL,
         std::make_shared<AsterixSubitemSigned>( 15, DoubleConverter::fraction4th ) ) );

   subitem_map_t aircraft_address;
   aircraft_address.push_back(
      subitem_t( Cat244ItemNames::I244_120_ADR,
         std::make_shared<AsterixSubitemUnsigned>( 24, CommonConverter::NoneConverter ) ) );

   subitem_map_t mode_3A_code;
   mode_3A_code.push_back(
      subitem_t( Cat244ItemNames::I244_130_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   mode_3A_code.push_back(
      subitem_t( Cat244ItemNames::I244_130_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   mode_3A_code.push_back(
      subitem_t( Cat244ItemNames::I244_130_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) );

   subitem_map_t target_id;
   target_id.push_back(
      subitem_t( Cat244ItemNames::I244_140_TID,
         std::make_shared<AsterixSubitemUnsigned>( 48, StringConverter::to6BitChar ) ) );

   subitem_map_t aicraft_type;
   aicraft_type.push_back(
      subitem_t( Cat244ItemNames::I244_150_ACT,
         std::make_shared<AsterixSubitemBytes>( 32, StringConverter::toASCII ) ) );

   subitem_map_t adsb_emitter_cat;
   adsb_emitter_cat.push_back(
      subitem_t( Cat244ItemNames::I244_160_ECAT,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t target_status;
   target_status.push_back(
      subitem_t( Cat244ItemNames::I244_170_TS,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   subitem_map_t accuracy;
   accuracy.push_back(
      subitem_t( Cat244ItemNames::I244_180_NAC,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   accuracy.push_back(
      subitem_t( Cat244ItemNames::I244_180_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter ) ) );
   accuracy.push_back(
      subitem_t( Cat244ItemNames::I244_180_NIC,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter ) ) );
   accuracy.push_back(
      subitem_t( Cat244ItemNames::I244_180_B,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   accuracy.push_back(
      subitem_t( Cat244ItemNames::I244_180_SIL,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );
   accuracy.push_back(
      subitem_t( Cat244ItemNames::I244_180_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter ) ) );

   subitem_map_t link_status;
   link_status.push_back(
      subitem_t( Cat244ItemNames::I244_190_ES,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   link_status.push_back(
      subitem_t( Cat244ItemNames::I244_190_VDL4,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   link_status.push_back(
      subitem_t( Cat244ItemNames::I244_190_UAT,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) );
   link_status.push_back(
      subitem_t( Cat244ItemNames::I244_190_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, trajectory_identifioer ) );
   subitems.insert( subitem_map_item_t( 2, time_of_day ) );
   subitems.insert( subitem_map_item_t( 3, position_wgs84 ) );
   subitems.insert( subitem_map_item_t( 4, geometric_altitude ) );
   subitems.insert( subitem_map_item_t( 5, flight_level ) );
   subitems.insert( subitem_map_item_t( 6, ground_Speed ) );
   subitems.insert( subitem_map_item_t( 7, air_speed ) );
   subitems.insert( subitem_map_item_t( 8, course ) );
   subitems.insert( subitem_map_item_t( 9, magnetic_heading ) );
   subitems.insert( subitem_map_item_t( 10, vertical_rate ) );
   subitems.insert( subitem_map_item_t( 11, barometric_vertical_rate ) );
   subitems.insert( subitem_map_item_t( 12, accelerations ) );
   subitems.insert( subitem_map_item_t( 13, turn_rate ) );
   subitems.insert( subitem_map_item_t( 14, ads_b_profile ) );
   subitems.insert( subitem_map_item_t( 15, selected_altitude ) );
   subitems.insert( subitem_map_item_t( 16, aircraft_address ) );
   subitems.insert( subitem_map_item_t( 17, mode_3A_code ) );
   subitems.insert( subitem_map_item_t( 18, target_id ) );
   subitems.insert( subitem_map_item_t( 19, aicraft_type ) );
   subitems.insert( subitem_map_item_t( 20, adsb_emitter_cat ) );
   subitems.insert( subitem_map_item_t( 21, target_status ) );
   subitems.insert( subitem_map_item_t( 22, accuracy ) );
   subitems.insert( subitem_map_item_t( 23, link_status ) );
}

void AsterixCategory244::fillRecord(std::shared_ptr<ReportRecordType> record) {
}
