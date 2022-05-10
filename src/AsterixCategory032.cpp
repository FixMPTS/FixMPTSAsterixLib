/**
 * @file AsterixCategory032.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 1 Jan 2018
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
 * See .h file for more information.
 */

#include "AsterixCategory032.h"

#include "AsterixItemVariableLength.h"
#include "AsterixItemCompound.h"
#include "AsterixItemRepetetive.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemExtendible.h"
#include "AsterixSubitemCompound.h"
#include "AsterixSubItemRep.h"
#include "AsterixSubitemBytes.h"
#include "AsterixSubitemUnsigned.h"
#include "Cat032ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "StringConverter.h"
#include "IntegerConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory032::AsterixCategory032() :
   AsterixCategory( 32 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory032::AsterixCategory032( int length ) :
   AsterixCategory( 32, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory032::AsterixCategory032( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 32, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory032::~AsterixCategory032() {
}

void AsterixCategory032::setUAP() {
   // Definition of the Compound items
   AsterixItemCompound::subUap_T item_500_sub_uap;
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_500_IFI, 4 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_500_RVP, 1 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_500_RDS, 3 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemRepetetive>( Cat032ItemNames::I032_500_TOD, 4 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_500_AST, 6 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_500_STS, 1 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 7,
         std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_500_STD, 7 ) ) );
   item_500_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 8,
         std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_500_STA, 7 ) ) );

   // Set up the UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_015, 2 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_018, 2 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_035, 1 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_020, 3 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_040, 2 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemExtendible>( Cat032ItemNames::I032_050, 3 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_060, 2 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_400, 7 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_410, 2 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_420, 1 ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_440, 4 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_450, 4 ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_480, 2 ) ) );
   uap.insert( UAP_Item_T( 15, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_490, 2 ) ) );
   uap.insert( UAP_Item_T( 16, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_430, 4 ) ) );
   uap.insert( UAP_Item_T( 17, std::make_shared<AsterixItemFixedLength>( Cat032ItemNames::I032_435, 1 ) ) );
   uap.insert( UAP_Item_T( 18, std::make_shared<AsterixItemRepetetive>( Cat032ItemNames::I032_460, 2 ) ) );
   uap.insert( UAP_Item_T( 19, std::make_shared<AsterixItemCompound>( Cat032ItemNames::I032_500, item_500_sub_uap ) ) );

   // There is no coding rule currently for the RE item
}

void AsterixCategory032::setSubitems() {

   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat032ItemNames::I032_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   sensor_identification.push_back(
      subitem_t( Cat032ItemNames::I032_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t user_number;
   user_number.push_back(
      subitem_t( Cat032ItemNames::I032_015_UN,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t fpps_identification;
   fpps_identification.push_back(
      subitem_t( Cat032ItemNames::I032_018_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   fpps_identification.push_back(
      subitem_t( Cat032ItemNames::I032_018_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t type_of_message;
   type_of_message.push_back(
      subitem_t( Cat032ItemNames::I032_035_FAM,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   type_of_message.push_back(
      subitem_t( Cat032ItemNames::I032_035_NAT,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t time_of_report;
   time_of_report.push_back(
      subitem_t( Cat032ItemNames::I032_020_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::Fraction128th::get() ) ) );

   subitem_map_t track_number;
   track_number.push_back(
      subitem_t( Cat032ItemNames::I032_040_TRK,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t composed_track_number;
   composed_track_number.push_back(
      subitem_t( Cat032ItemNames::I032_050_MSU,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   composed_track_number.push_back(
      subitem_t( Cat032ItemNames::I032_050_MTN,
         std::make_shared<AsterixSubitemUnsigned>( 15, CommonConverter::NoneConverter::get() ) ) );
   composed_track_number.push_back(
      subitem_t( Cat032ItemNames::I032_050_SSU,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   composed_track_number.push_back(
      subitem_t( Cat032ItemNames::I032_050_STN,
         std::make_shared<AsterixSubitemUnsigned>( 15, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t mode_3a;
   mode_3a.push_back(
      subitem_t( Cat032ItemNames::I032_060_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   mode_3a.push_back(
      subitem_t( Cat032ItemNames::I032_060_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t call_sign;
   call_sign.push_back(
      subitem_t( Cat032ItemNames::I032_400_CS,
         std::make_shared<AsterixSubitemBytes>( 56, StringConverter::ToASCII::get() ) ) );

   subitem_map_t plan_number;
   plan_number.push_back(
      subitem_t( Cat032ItemNames::I032_410_PNU,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t flight_category;
   flight_category.push_back(
      subitem_t( Cat032ItemNames::I032_420_GAT,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   flight_category.push_back(
      subitem_t( Cat032ItemNames::I032_420_FR1,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   flight_category.push_back(
      subitem_t( Cat032ItemNames::I032_420_SP3,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   flight_category.push_back(
      subitem_t( Cat032ItemNames::I032_420_SP2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   flight_category.push_back(
      subitem_t( Cat032ItemNames::I032_420_SP1,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t departure_airport;
   departure_airport.push_back(
      subitem_t( Cat032ItemNames::I032_440_DEP,
         std::make_shared<AsterixSubitemBytes>( 32, StringConverter::ToASCII::get() ) ) );

   subitem_map_t destination_airport;
   destination_airport.push_back(
      subitem_t( Cat032ItemNames::I032_450_DST,
         std::make_shared<AsterixSubitemBytes>( 32, StringConverter::ToASCII::get() ) ) );

   subitem_map_t cleared_flight_level;
   cleared_flight_level.push_back(
      subitem_t( Cat032ItemNames::I032_480_FL,
         std::make_shared<AsterixSubitemUnsigned>( 16, IntegerConverter::Alt25ft::get() ) ) );

   subitem_map_t control_position;
   control_position.push_back(
      subitem_t( Cat032ItemNames::I032_490_CENTRE,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   control_position.push_back(
      subitem_t( Cat032ItemNames::I032_490_POS,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t type_of_aircraft;
   type_of_aircraft.push_back(
      subitem_t( Cat032ItemNames::I032_430_AT,
         std::make_shared<AsterixSubitemBytes>( 32, StringConverter::ToASCII::get() ) ) );

   subitem_map_t wake_turbulence_category;
   wake_turbulence_category.push_back(
      subitem_t( Cat032ItemNames::I032_435_WTC,
         std::make_shared<AsterixSubitemBytes>( 8, StringConverter::ToASCII::get() ) ) );

   subitem_map_t allocated_ssr_codes;
   allocated_ssr_codes.push_back(
      subitem_t( Cat032ItemNames::I032_460_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   allocated_ssr_codes.push_back(
      subitem_t( Cat032ItemNames::I032_460_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t supplementary_data;
   subitem_map_t sub_sub_item_500_ifi;
   sub_sub_item_500_ifi.push_back(
      subitem_t( Cat032ItemNames::I032_500_IFI_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_ifi.push_back(
      subitem_t( Cat032ItemNames::I032_500_IFI_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_ifi.push_back(
      subitem_t( Cat032ItemNames::I032_500_IFI_NBR,
         std::make_shared<AsterixSubitemUnsigned>( 27, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t sub_sub_item_500_rvp;
   sub_sub_item_500_rvp.push_back(
      subitem_t( Cat032ItemNames::I032_500_RVP_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_rvp.push_back(
      subitem_t( Cat032ItemNames::I032_500_RVP_RVSM,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_rvp.push_back(
      subitem_t( Cat032ItemNames::I032_500_RVP_HPR,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t sub_sub_item_500_tod;
   sub_sub_item_500_tod.push_back(
      subitem_t( Cat032ItemNames::I032_500_TOD_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_tod.push_back(
      subitem_t( Cat032ItemNames::I032_500_TOD_DAY,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_tod.push_back(
      subitem_t( Cat032ItemNames::I032_500_TOD_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_tod.push_back(
      subitem_t( Cat032ItemNames::I032_500_TOD_HOR,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_tod.push_back(
      subitem_t( Cat032ItemNames::I032_500_TOD_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_tod.push_back(
      subitem_t( Cat032ItemNames::I032_500_TOD_MIN,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_tod.push_back(
      subitem_t( Cat032ItemNames::I032_500_TOD_AVS,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_tod.push_back(
      subitem_t( Cat032ItemNames::I032_500_TOD_SPARE3,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_tod.push_back(
      subitem_t( Cat032ItemNames::I032_500_TOD_SEC,
         std::make_shared<AsterixSubitemUnsigned>( 6, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t sub_sub_item_500_sts;
   sub_sub_item_500_sts.push_back(
      subitem_t( Cat032ItemNames::I032_500_STS_EMP,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_sts.push_back(
      subitem_t( Cat032ItemNames::I032_500_STS_AVL,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_500_sts.push_back(
      subitem_t( Cat032ItemNames::I032_500_STS_SPAE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );

   // Add all sub items to the 500er sub item
   supplementary_data.push_back(
      subitem_t( Cat032ItemNames::I032_500_IFI,
         std::make_shared<AsterixSubitemCompound>( 32, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_500_ifi ) ) );
   supplementary_data.push_back(
      subitem_t( Cat032ItemNames::I032_500_RVP,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_500_rvp ) ) );
   supplementary_data.push_back(
      subitem_t( Cat032ItemNames::I032_500_RDS,
         std::make_shared<AsterixSubitemBytes>( 24, StringConverter::ToASCII::get() ) ) );
   supplementary_data.push_back(
      subitem_t( Cat032ItemNames::I032_500_TOD,
         std::make_shared<AsterixSubItemRep>( 32, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_500_tod ) ) );
   supplementary_data.push_back(
      subitem_t( Cat032ItemNames::I032_500_AST,
         std::make_shared<AsterixSubitemBytes>( 48, StringConverter::ToASCII::get() ) ) );
   supplementary_data.push_back(
      subitem_t( Cat032ItemNames::I032_500_STS,
         std::make_shared<AsterixSubItemRep>( 8, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_500_sts ) ) );
   supplementary_data.push_back(
      subitem_t( Cat032ItemNames::I032_500_STD,
         std::make_shared<AsterixSubitemBytes>( 56, StringConverter::ToASCII::get() ) ) );
   supplementary_data.push_back(
      subitem_t( Cat032ItemNames::I032_500_STA,
         std::make_shared<AsterixSubitemBytes>( 56, StringConverter::ToASCII::get() ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, user_number ) );
   subitems.insert( subitem_map_item_t( 3, fpps_identification ) );
   subitems.insert( subitem_map_item_t( 4, type_of_message ) );
   subitems.insert( subitem_map_item_t( 5, time_of_report ) );
   subitems.insert( subitem_map_item_t( 6, track_number ) );
   subitems.insert( subitem_map_item_t( 7, composed_track_number ) );
   subitems.insert( subitem_map_item_t( 8, mode_3a ) );
   subitems.insert( subitem_map_item_t( 9, call_sign ) );
   subitems.insert( subitem_map_item_t( 10, plan_number ) );
   subitems.insert( subitem_map_item_t( 11, flight_category ) );
   subitems.insert( subitem_map_item_t( 12, departure_airport ) );
   subitems.insert( subitem_map_item_t( 13, destination_airport ) );
   subitems.insert( subitem_map_item_t( 14, cleared_flight_level ) );
   subitems.insert( subitem_map_item_t( 15, control_position ) );
   subitems.insert( subitem_map_item_t( 16, type_of_aircraft ) );
   subitems.insert( subitem_map_item_t( 17, wake_turbulence_category ) );
   subitems.insert( subitem_map_item_t( 18, allocated_ssr_codes ) );
   subitems.insert( subitem_map_item_t( 19, supplementary_data ) );
}

void AsterixCategory032::fillRecord(std::shared_ptr<ReportRecordType> record) {
}

