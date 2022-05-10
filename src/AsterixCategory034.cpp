/**
 * @file AsterixCategory034.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 04 Sept 2017
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

#include "AsterixCategory034.h"

// Include (sub) item relevant header
#include "AsterixItemFixedLength.h"
#include "AsterixItemCompound.h"
#include "AsterixItemRepetetive.h"
#include "AsterixCommonDef.h"
#include "AsterixSubItemRep.h"
#include "AsterixSubitemCompound.h"
#include "AsterixSubitemUnsigned.h"
#include "AsterixSubitemBitNamed.h"
#include "Cat034ItemNames.h"

// Converter
#include "CommonConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

AsterixCategory034::AsterixCategory034() :
   AsterixCategory( 34 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory034::AsterixCategory034( int length ) :
   AsterixCategory( 34, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory034::AsterixCategory034( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 34, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory034::~AsterixCategory034() {
}

void AsterixCategory034::setUAP() {
   // Define the sub UAPs from the compound items
   AsterixItemCompound::subUap_T item_050_sub_uap;
   item_050_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_050_COM, 1 ) ) );
   item_050_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_050_SPARE1, 0 ) ) );
   item_050_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_050_SPARE2, 0 ) ) );
   item_050_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_050_PSR, 1 ) ) );
   item_050_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_050_SSR, 1 ) ) );
   item_050_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_050_MDS, 1 ) ) );
   // Item 7 is spare and 8 is the FX bit

   AsterixItemCompound::subUap_T item_060_sub_uap;
   item_060_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 1,
         std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_060_COM, 1 ) ) );
   item_060_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 2,
         std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_060_SPARE1, 0 ) ) );
   item_060_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 3,
         std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_060_SPARE2, 0 ) ) );
   item_060_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 4,
         std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_060_PSR, 1 ) ) );
   item_060_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 5,
         std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_060_SSR, 1 ) ) );
   item_060_sub_uap.insert(
      AsterixItemCompound::SubUAP_Item_T( 6,
         std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_060_MDS, 1 ) ) );

   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_000, 1 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_030, 3 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_020, 1 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_041, 2 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemCompound>( Cat034ItemNames::I034_050, item_050_sub_uap ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemCompound>( Cat034ItemNames::I034_060, item_060_sub_uap ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemRepetetive>( Cat034ItemNames::I034_070, 2 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_100, 8 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_110, 1 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_120, 8 ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemFixedLength>( Cat034ItemNames::I034_090, 2 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemRepetetive>( Cat034ItemNames::I034_RE, 1 ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemRepetetive>( Cat034ItemNames::I034_SP, 1 ) ) );
}

void AsterixCategory034::setSubitems() {

   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat034ItemNames::I034_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   sensor_identification.push_back(
      subitem_t( Cat034ItemNames::I034_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t message_type;
   message_type.push_back(
      subitem_t( Cat034ItemNames::I034_000_TYPE,
         std::make_shared<AsterixSubitemBitNamed>( 8, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Invalid" }, { 1, "North Marker" }, {
               2, "Sector crossing" }, { 3, "Geo filtering" }, { 4, "Jamming strobe" } } ) ) ) );

   subitem_map_t time_of_day;
   time_of_day.push_back(
      subitem_t( Cat034ItemNames::I034_030_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 24, UnsignedDoubleConverter::Fraction128th::get() ) ) );

   subitem_map_t sector_number;
   sector_number.push_back(
      subitem_t( Cat034ItemNames::I034_020_SCT,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::CircleSegment8Bit::get() ) ) );

   subitem_map_t antenna_rotation_speed;
   time_of_day.push_back(
      subitem_t( Cat034ItemNames::I034_041_ROT,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::Fraction128th::get() ) ) );

   subitem_map_t sys_config_state;

   subitem_map_t sub_sub_item_050_com;
   sub_sub_item_050_com.push_back(
      subitem_t( Cat034ItemNames::I034_050_COM_NOG,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "GO" }, { 1, "NOGO" } } ) ) ) );
   sub_sub_item_050_com.push_back(
      subitem_t( Cat034ItemNames::I034_050_COM_RDPC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "RDPC 0" }, { 1, "RDPC 1" } } ) ) ) );
   sub_sub_item_050_com.push_back(
      subitem_t( Cat034ItemNames::I034_050_COM_RDPR,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "RDPC Reset" } } ) ) ) );
   sub_sub_item_050_com.push_back(
      subitem_t( Cat034ItemNames::I034_050_COM_ORDP,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Overload" } } ) ) ) );
   sub_sub_item_050_com.push_back(
      subitem_t( Cat034ItemNames::I034_050_COM_OXMT,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Overload XMT" } } ) ) ) );
   sub_sub_item_050_com.push_back(
      subitem_t( Cat034ItemNames::I034_050_COM_MSC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Connected" }, { 1, "Disconnected" } } ) ) ) );
   sub_sub_item_050_com.push_back(
      subitem_t( Cat034ItemNames::I034_050_COM_TSV,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Valid" }, { 1, "Invalid" } } ) ) ) );
   sub_sub_item_050_com.push_back(
      subitem_t( Cat034ItemNames::I034_050_COM_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   // Store the sub sub items in the COM item
   sys_config_state.push_back(
      subitem_t( Cat034ItemNames::I034_050_COM,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_050_com ) ) );

   subitem_map_t sub_sub_item_050_psr;
   sub_sub_item_050_psr.push_back(
      subitem_t( Cat034ItemNames::I034_050_PSR_SANT,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Antenna 1" }, { 1, "Antenna 2" } } ) ) ) );
   sub_sub_item_050_psr.push_back(
      subitem_t( Cat034ItemNames::I034_050_PSR_SCH,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "No Channel" }, { 1, "Channel A" }, {
               1, "Channel B" }, { 1, "Channel A+B" } } ) ) ) );
   sub_sub_item_050_psr.push_back(
      subitem_t( Cat034ItemNames::I034_050_PSR_POVL,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Overload" } } ) ) ) );
   sub_sub_item_050_psr.push_back(
      subitem_t( Cat034ItemNames::I034_050_PSR_PMSC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Connected" }, { 1, "Disconnected" } } ) ) ) );
   sub_sub_item_050_psr.push_back(
      subitem_t( Cat034ItemNames::I034_050_PSR_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sys_config_state.push_back(
      subitem_t( Cat034ItemNames::I034_050_PSR,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_050_psr ) ) );

   subitem_map_t sub_sub_item_050_ssr;
   sub_sub_item_050_ssr.push_back(
      subitem_t( Cat034ItemNames::I034_050_SSR_ANT,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Antenna 1" }, { 1, "Antenna 2" } } ) ) ) );
   sub_sub_item_050_ssr.push_back(
      subitem_t( Cat034ItemNames::I034_050_SSR_CH,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "No Channel" }, { 1, "Channel A" }, {
               1, "Channel B" }, { 1, "Channel A+B" } } ) ) ) );
   sub_sub_item_050_ssr.push_back(
      subitem_t( Cat034ItemNames::I034_050_SSR_OVL,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Overload" } } ) ) ) );
   sub_sub_item_050_ssr.push_back(
      subitem_t( Cat034ItemNames::I034_050_SSR_MSC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Connected" }, { 1, "Disconnected" } } ) ) ) );
   sub_sub_item_050_ssr.push_back(
      subitem_t( Cat034ItemNames::I034_050_SSR_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sys_config_state.push_back(
      subitem_t( Cat034ItemNames::I034_050_SSR,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_050_ssr ) ) );

   subitem_map_t sub_sub_item_050_ms;
   sub_sub_item_050_ms.push_back(
      subitem_t( Cat034ItemNames::I034_050_MDS_MANT,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Antenna 1" }, { 1, "Antenna 2" } } ) ) ) );
   sub_sub_item_050_ms.push_back(
      subitem_t( Cat034ItemNames::I034_050_MDS_MCH,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "No Channel" }, { 1, "Channel A" }, {
               1, "Channel B" }, { 1, "Channel A+B" } } ) ) ) );
   sub_sub_item_050_ms.push_back(
      subitem_t( Cat034ItemNames::I034_050_MDS_MOVL,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Overload" } } ) ) ) );
   sub_sub_item_050_ms.push_back(
      subitem_t( Cat034ItemNames::I034_050_MDS_MMSC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Connected" }, { 1, "Disconnected" } } ) ) ) );
   sub_sub_item_050_ms.push_back(
      subitem_t( Cat034ItemNames::I034_050_MDS_SCF,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Channel A" }, { 1, "Channel B" } } ) ) ) );
   sub_sub_item_050_ms.push_back(
      subitem_t( Cat034ItemNames::I034_050_MDS_DLF,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Channel A" }, { 1, "Channel B" } } ) ) ) );
   sub_sub_item_050_ms.push_back(
      subitem_t( Cat034ItemNames::I034_050_MDS_OSCF,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Overload" } } ) ) ) );
   sub_sub_item_050_ms.push_back(
      subitem_t( Cat034ItemNames::I034_050_MDS_ODLF,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Overload" } } ) ) ) );
   sub_sub_item_050_ms.push_back(
      subitem_t( Cat034ItemNames::I034_050_MDS_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter::get() ) ) );
   sys_config_state.push_back(
      subitem_t( Cat034ItemNames::I034_050_MDS,
         std::make_shared<AsterixSubitemCompound>( 16, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_050_ms ) ) );

   subitem_map_t system_processing_mode;

   subitem_map_t sub_sub_item_060_com;
   sub_sub_item_060_com.push_back(
      subitem_t( Cat034ItemNames::I034_060_COM_SPARE1,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_060_com.push_back(
      subitem_t( Cat034ItemNames::I034_060_COM_REDR,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_060_com.push_back(
      subitem_t( Cat034ItemNames::I034_060_COM_REDX,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_060_com.push_back(
      subitem_t( Cat034ItemNames::I034_060_COM_SPARE2,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) );
   system_processing_mode.push_back(
      subitem_t( Cat034ItemNames::I034_060_COM,
         std::make_shared<AsterixSubitemCompound>( 8, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_060_com ) ) );

   // Add the spare items needed to ensure the ordeing
   system_processing_mode.push_back(
      subitem_t( Cat034ItemNames::I034_060_SP1,
         std::make_shared<AsterixSubitemCompound>( 0, CommonConverter::NoneConverter::get() ) ) );
   system_processing_mode.push_back(
      subitem_t( Cat034ItemNames::I034_060_SP1,
         std::make_shared<AsterixSubitemCompound>( 0, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t sub_sub_item_060_psr;
   sub_sub_item_060_psr.push_back(
      subitem_t( Cat034ItemNames::I034_060_PSR_PPOL,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Linear" }, { 1, "Circular" } } ) ) ) );
   system_processing_mode.push_back(
      subitem_t( Cat034ItemNames::I034_060_PSR_PRED,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter::get() ) ) );
   system_processing_mode.push_back(
      subitem_t( Cat034ItemNames::I034_060_PSR_PSTC,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   system_processing_mode.push_back(
      subitem_t( Cat034ItemNames::I034_060_PSR_PSPARE,
         std::make_shared<AsterixSubitemUnsigned>( 2, CommonConverter::NoneConverter::get() ) ) );
   system_processing_mode.push_back(
      subitem_t( Cat034ItemNames::I034_060_PSR,
         std::make_shared<AsterixSubItemRep>( 8, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_060_psr ) ) );

   subitem_map_t sub_sub_item_060_ssr;
   sub_sub_item_060_ssr.push_back(
      subitem_t( Cat034ItemNames::I034_060_SSR_SRED,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_060_ssr.push_back(
      subitem_t( Cat034ItemNames::I034_060_SSR_SSPARE,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter::get() ) ) );
   system_processing_mode.push_back(
      subitem_t( Cat034ItemNames::I034_060_SSR,
         std::make_shared<AsterixSubItemRep>( 8, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_060_ssr ) ) );

   subitem_map_t sub_sub_item_060_mds;
   sub_sub_item_060_mds.push_back(
      subitem_t( Cat034ItemNames::I034_060_MDS_MRED,
         std::make_shared<AsterixSubitemUnsigned>( 3, CommonConverter::NoneConverter::get() ) ) );
   sub_sub_item_060_mds.push_back(
      subitem_t( Cat034ItemNames::I034_060_MDS_MCLU,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Autonomous" },
               { 1, "Not Autonomous" } } ) ) ) );
   sub_sub_item_060_mds.push_back(
      subitem_t( Cat034ItemNames::I034_060_MDS_MSPARE,
         std::make_shared<AsterixSubitemUnsigned>( 4, CommonConverter::NoneConverter::get() ) ) );
   system_processing_mode.push_back(
      subitem_t( Cat034ItemNames::I034_060_MDS,
         std::make_shared<AsterixSubItemRep>( 8, CommonConverter::NoneConverterBuffer::get(),
            sub_sub_item_060_mds ) ) );

   subitem_map_t message_count;
   message_count.push_back(
      subitem_t( Cat034ItemNames::I034_070_TYPE,
         std::make_shared<AsterixSubitemUnsigned>( 5, CommonConverter::NoneConverter::get() ) ) );
   message_count.push_back(
      subitem_t( Cat034ItemNames::I034_070_COUNTER,
         std::make_shared<AsterixSubitemUnsigned>( 11, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t polar_window;
   polar_window.push_back(
      subitem_t( Cat034ItemNames::I034_100_RHOS,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::CircleSegment16Bit::get() ) ) );
   polar_window.push_back(
      subitem_t( Cat034ItemNames::I034_100_RHOE,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::CircleSegment16Bit::get() ) ) );
   polar_window.push_back(
      subitem_t( Cat034ItemNames::I034_100_THETAS,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::Fraction256th::get() ) ) );
   polar_window.push_back(
      subitem_t( Cat034ItemNames::I034_100_THETAE,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::Fraction256th::get() ) ) );

   subitem_map_t data_filter;
   data_filter.push_back(
      subitem_t( Cat034ItemNames::I034_110_TYP,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   subitem_map_t position_3d;
   position_3d.push_back(
      subitem_t( Cat034ItemNames::I034_120_H,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter::get() ) ) );
   position_3d.push_back(
      subitem_t( Cat034ItemNames::I034_120_LAT,
         std::make_shared<AsterixSubitemUnsigned>( 24, DoubleConverter::WGS84resolution23Bit::get() ) ) );
   position_3d.push_back(
      subitem_t( Cat034ItemNames::I034_120_LNG,
         std::make_shared<AsterixSubitemUnsigned>( 24, DoubleConverter::WGS84resolution23Bit::get() ) ) );

   subitem_map_t collimation_err;
   collimation_err.push_back(
      subitem_t( Cat034ItemNames::I034_090_RNG,
         std::make_shared<AsterixSubitemUnsigned>( 8, DoubleConverter::Fraction128th::get() ) ) );
   collimation_err.push_back(
      subitem_t( Cat034ItemNames::I034_090_AZM,
         std::make_shared<AsterixSubitemUnsigned>( 8, UnsignedDoubleConverter::Direction14Bit::get() ) ) );

   // Add all items
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, message_type ) );
   subitems.insert( subitem_map_item_t( 3, time_of_day ) );
   subitems.insert( subitem_map_item_t( 4, sector_number ) );
   subitems.insert( subitem_map_item_t( 5, antenna_rotation_speed ) );
   subitems.insert( subitem_map_item_t( 6, sys_config_state ) );
   subitems.insert( subitem_map_item_t( 7, system_processing_mode ) );
   subitems.insert( subitem_map_item_t( 8, message_count ) );
   subitems.insert( subitem_map_item_t( 9, polar_window ) );
   subitems.insert( subitem_map_item_t( 10, data_filter ) );
   subitems.insert( subitem_map_item_t( 11, position_3d ) );
   subitems.insert( subitem_map_item_t( 12, collimation_err ) );
}

void AsterixCategory034::fillRecord(std::shared_ptr<ReportRecordType> record) {
}
