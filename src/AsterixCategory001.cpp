/**
 * @file AsterixCategory001.cpp
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
 * see .h file for more information
 */

// Asterix includes
#include "AsterixCategory001.h"
#include "AsterixCommonDef.h"
#include "AsterixItemFixedLength.h"
#include "AsterixItemVariableLength.h"
#include "AsterixSubitemUnsigned.h"
#include "AsterixSubitemBitNamed.h"
#include "Cat001ItemNames.h"
#include "AsterixEncodingHelper.h"

// Converter
#include "CommonConverter.h"
#include "IntegerConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

#include "DetectionEntry.h"

#include <bitset>

AsterixCategory001::AsterixCategory001() :
   AsterixCategory( 1 ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory001::AsterixCategory001( int length ) :
   AsterixCategory( 1, length ) {
   // Init the calling Asterix Category
   initCategory();
}

AsterixCategory001::AsterixCategory001( int length, std::deque<char>& m_queue ) :
   AsterixCategory( 1, length, m_queue ) {
   // Init the calling Asterix Category
   initCategory();
}

void AsterixCategory001::setUAP() {
   //Define the Cat 001 Track UAP
   uap.clear();
   uap.insert( UAP_Item_T( 1, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_010, 2 ) ) );
   uap.insert( UAP_Item_T( 2, std::make_shared<AsterixItemVariableLength>( Cat001ItemNames::I001_020 ) ) );
   uap.insert( UAP_Item_T( 3, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_161, 2 ) ) );
   uap.insert( UAP_Item_T( 4, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_040, 4 ) ) );
   uap.insert( UAP_Item_T( 5, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_042, 4 ) ) );
   uap.insert( UAP_Item_T( 6, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_200, 4 ) ) );
   uap.insert( UAP_Item_T( 7, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_070, 2 ) ) );
   uap.insert( UAP_Item_T( 8, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_090, 2 ) ) );
   uap.insert( UAP_Item_T( 9, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_141, 2 ) ) );
   uap.insert( UAP_Item_T( 10, std::make_shared<AsterixItemVariableLength>( Cat001ItemNames::I001_130 ) ) );
   uap.insert( UAP_Item_T( 11, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_131, 1 ) ) );
   uap.insert( UAP_Item_T( 12, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_120, 1 ) ) );
   uap.insert( UAP_Item_T( 13, std::make_shared<AsterixItemVariableLength>( Cat001ItemNames::I001_170 ) ) );
   uap.insert( UAP_Item_T( 14, std::make_shared<AsterixItemVariableLength>( Cat001ItemNames::I001_210 ) ) );
   uap.insert( UAP_Item_T( 15, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_050, 2 ) ) );
   uap.insert( UAP_Item_T( 16, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_080, 2 ) ) );
   uap.insert( UAP_Item_T( 17, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_100, 4 ) ) );
   uap.insert( UAP_Item_T( 18, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_060, 2 ) ) );
   uap.insert( UAP_Item_T( 19, std::make_shared<AsterixItemVariableLength>( Cat001ItemNames::I001_030 ) ) );
   uap.insert( UAP_Item_T( 22, std::make_shared<AsterixItemFixedLength>( Cat001ItemNames::I001_150, 1 ) ) );
}

void AsterixCategory001::setSubitems() {

   //Sensor Identification
   subitem_map_t sensor_identification;
   sensor_identification.push_back(
      subitem_t( Cat001ItemNames::I001_010_SAC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );
   sensor_identification.push_back(
      subitem_t( Cat001ItemNames::I001_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter::get() ) ) );

   // Target Report descriptor
   subitem_map_t target_report_descriptor;
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_TYP,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Plot" }, { 1, "Track" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_SIM,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Actual Plot" },
               { 1, "Simulated Plot" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_DET,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "No Detection" }, { 1, "PSR" }, { 2,
               "SSR" }, { 3, "CMB" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_ANT,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Antenna 1" }, { 1, "Antenna 2" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_SPI,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "SPI set" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_RAB,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "RAB set" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_TST,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Test Target" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_DS1,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1, "Code 7500" }, { 2,
               "Code 7600" }, { 3, "Code 7700" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_ME,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" },
               { 1, "Military Emergency" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_MI,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1,
               "Military Identification" } } ) ) ) );

   subitem_map_t track_plot_number;
   track_plot_number.push_back(
      subitem_t( Cat001ItemNames::I001_161_TPN,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter::get() ) ) );

   //Measured Position in Polar Coordinates
   subitem_map_t measure_pos_polar;
   measure_pos_polar.push_back(
      subitem_t( Cat001ItemNames::I001_040_RHO,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::Fraction128th::get() ) ) );
   measure_pos_polar.push_back(
      subitem_t( Cat001ItemNames::I001_040_THETA,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::CircleSegment16Bit::get() ) ) );

   //Calculated Position in Cartesian Coordinates
   subitem_map_t measure_pos_cart;
   measure_pos_cart.push_back(
      subitem_t( Cat001ItemNames::I001_042_Y,
         std::make_shared<AsterixSubitemBase>( 16, CommonConverter::NoneConverter::get() ) ) );
   measure_pos_cart.push_back(
      subitem_t( Cat001ItemNames::I001_042_X,
         std::make_shared<AsterixSubitemBase>( 16, CommonConverter::NoneConverter::get() ) ) );

   //Calculated Track Velocity in Polar Coordinates
   subitem_map_t calc_vel_polar;
   calc_vel_polar.push_back(
      subitem_t( Cat001ItemNames::I001_200_GS,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::SpeedNMToKt::get() ) ) );
   calc_vel_polar.push_back(
      subitem_t( Cat001ItemNames::I001_200_HEAD,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::CircleSegment16Bit::get() ) ) );

   //Mode 3A Code
   subitem_map_t mode_3a_code;
   mode_3a_code.push_back(
      subitem_t( Cat001ItemNames::I001_070_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) ); // valid flag
   mode_3a_code.push_back(
      subitem_t( Cat001ItemNames::I001_070_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) ); // garbled flag
   mode_3a_code.push_back(
      subitem_t( Cat001ItemNames::I001_070_L,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) ); //locally tracked flag
   mode_3a_code.push_back(
      subitem_t( Cat001ItemNames::I001_070_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) ); // Not used
   mode_3a_code.push_back(
      subitem_t( Cat001ItemNames::I001_070_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter::get() ) ) ); // code in octal representation

   //Mode C Code
   subitem_map_t mode_c_code;
   mode_c_code.push_back(
      subitem_t( Cat001ItemNames::I001_090_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) ); // valid flag
   mode_c_code.push_back(
      subitem_t( Cat001ItemNames::I001_090_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter::get() ) ) ); // garbled flag
   mode_c_code.push_back(
      subitem_t( Cat001ItemNames::I001_090_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 14, IntegerConverter::LBitsToQuarter::get() ) ) ); // code in binary representation

   //Truncated Time of Day
   subitem_map_t tod;
   tod.push_back(
      subitem_t( Cat001ItemNames::I001_141_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::Fraction128th::get() ) ) ); // Time since midnight in s

   //Radar Plot Characteristics
   subitem_map_t radar_plot_char;
   radar_plot_char.push_back(
      subitem_t( Cat001ItemNames::I001_130_CHAR,
         std::make_shared<AsterixSubitemBase>( 8, CommonConverter::NoneConverter::get() ) ) ); // Application dependent

   //Received Power
   subitem_map_t received_power;
   received_power.push_back(
      subitem_t( Cat001ItemNames::I001_131_POW,
         std::make_shared<AsterixSubitemBase>( 8, CommonConverter::NoneConverter::get() ) ) );

   //Measured Radial Doppler Speed
   subitem_map_t dopppler_speed;
   dopppler_speed.push_back(
      subitem_t( Cat001ItemNames::I001_120_DS,
         std::make_shared<AsterixSubitemBase>( 8, CommonConverter::NoneConverter::get() ) ) );

   //Track Status
   subitem_map_t track_status;
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_CON,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Confirmed" }, { 1, "Tentative" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_RAD,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Primary" }, { 1, "SSR CMB" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_MAN,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1,
               "Aircraft manoeuvring" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_DOU,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Doubtful" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_RDPC,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "RDP Chain 1" }, { 1, "RDP Chain 2" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_SPARE,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter::get() ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_GHO,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1, "Ghost" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_TRE,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter::get(),
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Last Report" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_SPARE,
         std::make_shared<AsterixSubitemBase>( 7, CommonConverter::NoneConverter::get() ) ) );

   //Track Quality
   subitem_map_t track_quality;
   track_quality.push_back(
      subitem_t( Cat001ItemNames::I001_210_QL,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter::get() ) ) ); // Quality indicator

   //Mode 2 Code
   subitem_map_t mode_2_code;
   mode_2_code.push_back(
      subitem_t( Cat001ItemNames::I001_050_CODE,
         std::make_shared<AsterixSubitemBase>( 12, CommonConverter::NoneConverter::get() ) ) ); // code in octal representation
   mode_2_code.push_back(
      subitem_t( Cat001ItemNames::I001_050_SPARE,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter::get() ) ) ); // Not used
   mode_2_code.push_back(
      subitem_t( Cat001ItemNames::I001_050_L,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter::get() ) ) ); //locally tracked flag
   mode_2_code.push_back(
      subitem_t( Cat001ItemNames::I001_050_G,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter::get() ) ) ); // garbled flag
   mode_2_code.push_back(
      subitem_t( Cat001ItemNames::I001_050_V,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter::get() ) ) ); // valid flag

   //Mode-3/A Code Confidence Indicator
   subitem_map_t m3a_conf_ind;
   m3a_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_080_QX,
         std::make_shared<AsterixSubitemBase>( 12, CommonConverter::NoneConverter::get() ) ) ); // Quality per M3A Code bit
   m3a_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_080_SPARE,
         std::make_shared<AsterixSubitemBase>( 4, CommonConverter::NoneConverter::get() ) ) ); // Not used

   //Mode-C Code and Code Confidence Indicator
   subitem_map_t mc_conf_ind;
   mc_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_100_QX,
         std::make_shared<AsterixSubitemBase>( 12, CommonConverter::NoneConverter::get() ) ) ); // Quality per MC Code bit
   mc_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_100_SPARE,
         std::make_shared<AsterixSubitemBase>( 4, CommonConverter::NoneConverter::get() ) ) ); // Not used
   mc_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_100_CODE,
         std::make_shared<AsterixSubitemBase>( 12, CommonConverter::NoneConverter::get() ) ) ); // code in gray representation
   mc_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_100_SPARE,
         std::make_shared<AsterixSubitemBase>( 2, CommonConverter::NoneConverter::get() ) ) ); // Not used
   mc_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_100_G,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter::get() ) ) ); // garbled flag
   mc_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_100_V,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter::get() ) ) ); // valid flag

   // Mode-2 Code Confidence Indicator
   subitem_map_t m2_conf_ind;
   m2_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_060_QX,
         std::make_shared<AsterixSubitemBase>( 12, CommonConverter::NoneConverter::get() ) ) ); // Quality per M2 Code bit
   m2_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_060_SPARE,
         std::make_shared<AsterixSubitemBase>( 4, CommonConverter::NoneConverter::get() ) ) ); // Not used

   //Warning/Error Conditions
   subitem_map_t warning_err;
   warning_err.push_back(
      subitem_t( Cat001ItemNames::I001_030_ME,
         std::make_shared<AsterixSubitemBase>( 8, CommonConverter::NoneConverter::get() ) ) );

   //Presence of X-Pulse
   subitem_map_t x_pulse;
   x_pulse.push_back(
      subitem_t( Cat001ItemNames::I001_150_XA,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter::get() ) ) ); // Mode 3A impulse
   x_pulse.push_back(
      subitem_t( Cat001ItemNames::I001_150_SPARE,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter::get() ) ) ); // Not used
   x_pulse.push_back(
      subitem_t( Cat001ItemNames::I001_150_XC,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter::get() ) ) ); // Mode C impulse
   x_pulse.push_back(
      subitem_t( Cat001ItemNames::I001_150_SPARE,
         std::make_shared<AsterixSubitemBase>( 2, CommonConverter::NoneConverter::get() ) ) ); // Not used
   x_pulse.push_back(
      subitem_t( Cat001ItemNames::I001_150_X2,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter::get() ) ) ); // Mode 2 impulse
   x_pulse.push_back(
      subitem_t( Cat001ItemNames::I001_150_SPARE,
         std::make_shared<AsterixSubitemBase>( 2, CommonConverter::NoneConverter::get() ) ) ); // Not used

   //Add all the sub items to the category sub item map
   subitems.insert( subitem_map_item_t( 1, sensor_identification ) );
   subitems.insert( subitem_map_item_t( 2, target_report_descriptor ) );
   subitems.insert( subitem_map_item_t( 3, track_plot_number ) );
   subitems.insert( subitem_map_item_t( 4, measure_pos_polar ) );
   subitems.insert( subitem_map_item_t( 5, measure_pos_cart ) );
   subitems.insert( subitem_map_item_t( 6, calc_vel_polar ) );
   subitems.insert( subitem_map_item_t( 7, mode_3a_code ) );
   subitems.insert( subitem_map_item_t( 8, mode_c_code ) );
   subitems.insert( subitem_map_item_t( 9, tod ) );
   subitems.insert( subitem_map_item_t( 10, radar_plot_char ) );
   subitems.insert( subitem_map_item_t( 11, received_power ) );
   subitems.insert( subitem_map_item_t( 12, dopppler_speed ) );
   subitems.insert( subitem_map_item_t( 13, track_status ) );
   subitems.insert( subitem_map_item_t( 14, track_quality ) );
   subitems.insert( subitem_map_item_t( 15, mode_2_code ) );
   subitems.insert( subitem_map_item_t( 16, m3a_conf_ind ) );
   subitems.insert( subitem_map_item_t( 17, mc_conf_ind ) );
   subitems.insert( subitem_map_item_t( 18, m2_conf_ind ) );
   subitems.insert( subitem_map_item_t( 19, warning_err ) );
   subitems.insert( subitem_map_item_t( 22, x_pulse ) );
}

void AsterixCategory001::fillRecord(std::shared_ptr<ReportRecordType> record) {
   int sac, sic;
   try {
      sac = atoi( getValue( Cat001ItemNames::I001_010_SAC ).c_str() );
      sic = atoi( getValue( Cat001ItemNames::I001_010_SIC ).c_str() );
   } catch (const std::out_of_range& e) {
      sac = 0; //not valid
      sic = 0; // not valid
   }
   record->setSource( sac, sic );

   uint64_t det_time;
   try {
      det_time = atoi( getValue( Cat001ItemNames::I001_141_TOD ).c_str() );
   } catch (const std::out_of_range& e) {
      det_time = MAX_INVALID_ASTX_TOD_MS; //not valid >> midnight
   }
   record->setDetectionTimeFromTOD( det_time );

   //iterate over all values and sort them into the correct structure
   if( isItemPresent( Cat001ItemNames::I001_040_RHO ) && isItemPresent( Cat001ItemNames::I001_040_THETA ) ) {
      double rho = atof( getValue( Cat001ItemNames::I001_040_RHO ).c_str() );
      double theta = atof( getValue( Cat001ItemNames::I001_040_THETA ).c_str() );
      record->setRangeAzimuth( rho, theta, true );
   }

   if( isItemPresent( Cat001ItemNames::I001_090_CODE ) || isItemPresent( Cat001ItemNames::I001_100_CODE ) ) {
      //if both are set find out which is the better one (e.g. not garbled or valid, else use item 090 )
      double height_ft;
      bool v;
      if( isItemPresent( Cat001ItemNames::I001_090_CODE ) && !isItemPresent( Cat001ItemNames::I001_100_CODE ) ) {
         height_ft = atof( getValue( Cat001ItemNames::I001_090_CODE ).c_str() ) * 100.0; // convert from FL to ft
         v = atoi( getValue( Cat001ItemNames::I001_090_V ).c_str() );
         record->setModeC( atof( getValue( Cat001ItemNames::I001_090_CODE ).c_str() ), true, false, v );

      } else if( !isItemPresent( Cat001ItemNames::I001_090_CODE ) && isItemPresent( Cat001ItemNames::I001_100_CODE ) ) {
         //not decoded yet
         v = true;
         height_ft = 0.0;
      } else { //find the "best" code
         bool v090 = atoi( getValue( Cat001ItemNames::I001_090_V ).c_str() );
         bool v100 = atoi( getValue( Cat001ItemNames::I001_100_V ).c_str() );
         //flipped logic. 090 wins over 100
         height_ft =
            (!v100 && v090) ?
                              atof( getValue( Cat001ItemNames::I001_100_CODE ).c_str() ) :
                              atof( getValue( Cat001ItemNames::I001_090_CODE ).c_str() );
         height_ft *= 100;
         v = false;
      }

      record->setBaroHeight( height_ft, !v );
   }

   if( isItemPresent( Cat001ItemNames::I001_070_CODE ) ) {
      record->setMode3A( atoi( getValue( Cat001ItemNames::I001_070_CODE ).c_str() ), true,
         atoi( getValue( Cat001ItemNames::I001_070_G ).c_str() ),
         (atoi( getValue( Cat001ItemNames::I001_070_V ).c_str() ) == 0) );
   }

   if( isItemPresent( Cat001ItemNames::I001_161_TPN ) ) {
      record->setLocalTrackNumber( atoi( getValue( Cat001ItemNames::I001_161_TPN ).c_str() ), true );
   }

   if( isItemPresent( Cat001ItemNames::I001_020_DET ) ) { //luckily the enum matches the Asterix order at this point
      record->setDetectionType(
         static_cast<DetectionEntry::DET_TYPE>( atoi( getValue( Cat001ItemNames::I001_020_DET ).c_str() ) - 1 ) ); //-1 because Asterix counts from one
   }
}

std::vector<unsigned char> AsterixCategory001::getEncodedMessage(std::shared_ptr<ReportRecordType> record,
   std::map<std::string, bool> items_to_be_served) {

   std::vector<unsigned char> message;
   std::vector<unsigned char> header;

   // The track UAP is in use here
   for( auto item : fpsec_item_name_map ) {

      // Reset the FSPEC for this item
      fspec[item.first] = false;

      // I001/010 Data Source Identifier
      if( item.second == Cat001ItemNames::I001_010 ) { // Mandatory.
         std::tuple<int, int> sensor_id = record->getSourceID();
         std::vector<unsigned char> sac_sic = AsterixEncodingHelper::encodeSACSIC16Bit(
            std::get<0>( sensor_id ), std::get<1>( sensor_id ) );

         // item is present
         if( sac_sic.size() == 2 ) {
            fspec[item.first] = true;
            message.insert( message.end(), sac_sic.begin(), sac_sic.end() );
         }
      }

      // I001/020 Target Report Descriptor
      if( item.second == Cat001ItemNames::I001_020 ) { // Mandatory
         std::bitset<8> first_octet( 0 );
         first_octet[7] = 1; // Track UAP
         first_octet[6] = 0; // Actual plot TODO as input
         first_octet[5] =
            (record->getDetectionType() == DetectionEntry::DET_TYPE::SSR
               || record->getDetectionType() == DetectionEntry::DET_TYPE::CMB) ? 1 : 0;
         first_octet[4] =
            (record->getDetectionType() == DetectionEntry::DET_TYPE::NONE
               || record->getDetectionType() == DetectionEntry::DET_TYPE::PSR
               || record->getDetectionType() == DetectionEntry::DET_TYPE::CMB) ? 1 : 0;
         first_octet[3] = 0; // Antenna 0 TODO make input
         first_octet[2] = record->getSPI();
         first_octet[1] = 0; // RAB TODO make input

         std::bitset<8> first_extent( 0 );
         first_extent[7] = 0; // TST TODO make input
         first_extent[6] = 0;
         first_extent[5] = 0;
         if( record->isMode3APresent() ) {
            int code = record->getMode3ACode();
            first_extent[6] = (code == 3968/*7600*/|| code == 4032/*7700*/) ? 1 : 0;
            first_extent[5] = (code == 3904/*7500*/|| code == 4032/*7700*/) ? 1 : 0;
         }
         first_extent[4] = 0; // ME TODO make setter
         first_extent[3] = 0; // MI TODO mkae setter

         // Bits 3/2 spare

         std::bitset<8> second_extent( 0 ); // Not foreseen in the spec at the moment

         // Finally set the FX bits
         first_extent[0] = second_extent.any();
         first_octet[0] = first_extent.any();
         message.push_back( first_octet.to_ulong() & 0xff );

         if( first_extent.any() ) {
            message.push_back( first_extent.to_ulong() & 0xff );
         }
         if( second_extent.any() ) {
            message.push_back( second_extent.to_ulong() & 0xff );
         }
         fspec[item.first] = true;
      }

      // I001/161 Track/Plot Number
      if( item.second == Cat001ItemNames::I001_161 ) { // Mandatory
         std::vector<unsigned char> track_number = AsterixEncodingHelper::encodeTrackNumber16Bit(
            record->getLocalTrackNumber() );

         if( track_number.size() == 2 ) {
            message.insert( message.end(), track_number.begin(), track_number.end() );
            fspec[item.first] = true;
         }
      }

      // I001/040 ModMeasured Position in Polar Coordinates
      if( item.second == Cat001ItemNames::I001_040
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( record->isRangeAzimuthPresent() ) {
            double rho_lsb = 1.0 / 128.0;
            double theta_lsb = 0.0055;
            uint16_t rho = std::get<0>( record->getRangeAzimuth() ) / rho_lsb;
            uint16_t theta = std::get<1>( record->getRangeAzimuth() ) / theta_lsb;

            message.push_back( (rho >> 8) & 0xff );
            message.push_back( rho & 0xff );
            message.push_back( (theta >> 8) & 0xff );
            message.push_back( theta & 0xff );
            fspec[item.first] = true;
         }
      }

      // I001/042 Calculated Position in Cartesian Coordinates
      if( item.second == Cat001ItemNames::I001_042
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( record->isGeoPosPresent() ) {
            double lsb = 1.0 / 64.0;

            uint16_t pos_x = static_cast<uint16_t>( std::get<0>( record->getGeoPos() ) / lsb );
            uint16_t pos_y = static_cast<uint16_t>( std::get<1>( record->getGeoPos() ) / lsb );
            message.push_back( (pos_x >> 8) & 0xff );
            message.push_back( pos_x & 0xff );
            message.push_back( (pos_y >> 8) & 0xff );
            message.push_back( pos_y & 0xff );

            fspec[item.first] = true;
         }
      }

      // I001/200 Calculated Track Velocity in polar Coordinates
      if( item.second == Cat001ItemNames::I001_200
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( record->isGroundSpeedPresent() && record->isHeadingPresent() ) {
            float gsp_lsb = 0.22;
            float heading_lsb = 0.0055;
            uint16_t gsp = record->getGroundSpeed() / gsp_lsb;
            uint16_t heading = record->getHeading() / heading_lsb;

            message.push_back( (gsp >> 8) & 0xff );
            message.push_back( gsp & 0xff );
            message.push_back( (heading >> 8) & 0xff );
            message.push_back( heading & 0xff );

            fspec[item.first] = true;
         }
      }

      // I001/070 Mode-3/A Code in Octal Representation
      if( item.second == Cat001ItemNames::I001_070
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( record->isMode3APresent() ) {
            // 2 Byte
            std::vector<unsigned char> m3A = AsterixEncodingHelper::encodeTrackMode3A(
               record->getMode3ACode(), record->isMode3AValid(), record->isMode3AGarbled() );

            if( m3A.size() == 2 ) {
               message.insert( message.end(), m3A.begin(), m3A.end() );
               fspec[item.first] = true;
            }
         }
      }

      // I001/090 Mode-C Code in Binary Representation
      if( item.second == Cat001ItemNames::I001_090
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( record->isModeCPresent() ) {
            short lsb = 25; // 1/4
            std::bitset<16> mode_c( record->getModeCCode() / lsb );

               // set the valid and garbled flags. Those are located at the end of the bit set
            mode_c[15] = !record->isModeCValid();
            mode_c[14] = record->isModeCGarbled();

               // Write the data structure
            uint16_t complete_code = mode_c.to_ulong();
            message.push_back( (complete_code >> 8) & 0xff );
            message.push_back( complete_code & 0xff );
            fspec[item.first] = true;
         }
      }

      // I001/141 Truncated Time of Day
      if( item.second == Cat001ItemNames::I001_141
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( record->getDetectionTime() > 0 ) {
            // convert delta to seconds
            unsigned long time_since_midnight;
            time_since_midnight = convertToTimeSinceMidnightMS( record->getDetectionTimeUTC() ) / 1000;

            // split into 1/128 seconds
            time_since_midnight *= 128;

            //write the three bytes
            message.push_back( (time_since_midnight >> 8) & 0xff );
            message.push_back( time_since_midnight & 0xff );
            fspec[item.first] = true;
         }
      }

      // I001/130 Radar Plot Characteristics
      if( item.second == Cat001ItemNames::I001_130
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         //not encoded at the moment
      }

      // I001/131 Received Power
      if( item.second == Cat001ItemNames::I001_131
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         if( isItemPresent( Cat001ItemNames::I001_131 ) ) {
            int value = std::atoi( getValue( Cat001ItemNames::I001_131 ).c_str() );
            message.push_back( value & 0xff );
            fspec[item.first] = true;
         }
      }

      // I001/120 Measured Radial Doppler Speed
      if( item.second == Cat001ItemNames::I001_120
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         float lsb = 14.052;
         if( isItemPresent( Cat001ItemNames::I001_120 ) ) {
            uint8_t value = std::atoi( getValue( Cat001ItemNames::I001_120 ).c_str() ) / lsb;
            message.push_back( value & 0xff );
            fspec[item.first] = true;
         }
      }

      // I001/170 Track Status
      if( item.second == Cat001ItemNames::I001_170
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         std::bitset<8> first_octet( 0 );
         first_octet[7] =
            (isItemPresent( Cat001ItemNames::I001_170_CON )
               && std::atoi( getValue( Cat001ItemNames::I001_170_CON ).c_str() ) == 1) ? 1 : 0; // CON
         first_octet[6] =
            (isItemPresent( Cat001ItemNames::I001_170_RAD )
               && std::atoi( getValue( Cat001ItemNames::I001_170_RAD ).c_str() ) == 1) ? 1 : 0; // RAD
         first_octet[5] =
            (isItemPresent( Cat001ItemNames::I001_170_MAN )
               && std::atoi( getValue( Cat001ItemNames::I001_170_MAN ).c_str() ) == 1) ? 1 : 0; // MAN
         first_octet[4] =
            (isItemPresent( Cat001ItemNames::I001_170_DOU )
               && std::atoi( getValue( Cat001ItemNames::I001_170_DOU ).c_str() ) == 1) ? 1 : 0; // DOU
         first_octet[3] =
            (isItemPresent( Cat001ItemNames::I001_170_RDPC )
               && std::atoi( getValue( Cat001ItemNames::I001_170_RDPC ).c_str() ) == 1) ? 1 : 0; // RDPC
         // bit 3 is spare
         first_octet[1] =
            (isItemPresent( Cat001ItemNames::I001_170_GHO )
               && std::atoi( getValue( Cat001ItemNames::I001_170_GHO ).c_str() ) == 1) ? 1 : 0; // GHO

         std::bitset<8> first_extent( 0 );
         first_extent[7] =
            (isItemPresent( Cat001ItemNames::I001_170_TRE )
               && std::atoi( getValue( Cat001ItemNames::I001_170_TRE ).c_str() ) == 1) ? 1 : 0; // TRE
         // remaining bits are spare

         std::bitset<8> second_extent( 0 ); // Not foreseen in the spec at the moment

         // Finally set the FX bits
         first_extent[0] = second_extent.any();
         first_octet[0] = first_extent.any();

         if( first_octet.any() ) {
            message.push_back( first_octet.to_ulong() & 0xff );
            fspec[item.first] = true;
         }
         if( first_extent.any() ) {
            message.push_back( first_extent.to_ulong() & 0xff );
         }
         if( second_extent.any() ) {
            message.push_back( second_extent.to_ulong() & 0xff );
         }
      }

      // I001/210 Track Quality
      if( item.second == Cat001ItemNames::I001_210
         && items_to_be_served.find( item.second ) != items_to_be_served.end() ) {
         // Not encoded at the moment
      }

      // I001/050 Mode-2 Code in Octal Representation
      if( item.second == Cat001ItemNames::I001_050
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( record->isMode2Present() ) {
            // 2 Byte
            std::vector<unsigned char> m2 = AsterixEncodingHelper::encodeTrackMode3A(
               record->getMode2Code(), record->isMode2Valid(), record->isMode2Garbled() );

            if( m2.size() == 2 ) {
               message.insert( message.end(), m2.begin(), m2.end() );
               fspec[item.first] = true;
            }
         }
      }

      // I001/080 Mode-3/A Code Confidence Indicator
      if( item.second == Cat001ItemNames::I001_080
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( isItemPresent( Cat001ItemNames::I001_080 ) ) {
            std::bitset<16> value( std::atoi( getValue( Cat001ItemNames::I001_080 ).c_str() ) );
            // set spare bits to 0
            value[15] = 0;
            value[14] = 0;
            value[13] = 0;
            value[12] = 0;
            message.push_back( (value.to_ulong() >> 8) & 0xff );
            message.push_back( value.to_ulong() & 0xff );
            fspec[item.first] = true;
         }
      }

      // I001/100 Mode-C Code and Code Confidence Indicator
      if( item.second == Cat001ItemNames::I001_100
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( isItemPresent( Cat001ItemNames::I001_100 ) ) {
            std::bitset<16> value( std::atoi( getValue( Cat001ItemNames::I001_100 ).c_str() ) );
            // set spare bits to 0
            value[15] = 0;
            value[14] = 0;
            value[13] = 0;
            value[12] = 0;
            message.push_back( (value.to_ulong() >> 8) & 0xff );
            message.push_back( value.to_ulong() & 0xff );
            fspec[item.first] = true;
         }
      }

      // I001/060 Mode-2 Code Confidence Indicator
      if( item.second == Cat001ItemNames::I001_060
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( isItemPresent( Cat001ItemNames::I001_060 ) ) {
            std::bitset<16> value( std::atoi( getValue( Cat001ItemNames::I001_060 ).c_str() ) );
            // set spare bits to 0
            value[15] = 0;
            value[14] = 0;
            value[13] = 0;
            value[12] = 0;
            message.push_back( (value.to_ulong() >> 8) & 0xff );
            message.push_back( value.to_ulong() & 0xff );
            fspec[item.first] = true;
         }
      }

      // I001/030 Warning/Error Conditions
      if( item.second == Cat001ItemNames::I001_030
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( isItemPresent( Cat001ItemNames::I001_030 ) ) {
            std::bitset<8> value( std::atoi( getValue( Cat001ItemNames::I001_030 ).c_str() ) );
            // set FX bit
            value = (value << 1);
            value[0] = 0;
            message.push_back( value.to_ulong() & 0xff );
            fspec[item.first] = true;
         }
      }

      // I001/150 Presence of X-Pulse
      if( item.second == Cat001ItemNames::I001_150
         && items_to_be_served.find( item.second ) != items_to_be_served.end()
         && items_to_be_served.at( item.second ) ) {
         if( isItemPresent( Cat001ItemNames::I001_150 ) ) {
            std::bitset<8> value( 0 );
            // set the values
            value[7] = (isItemPresent( Cat001ItemNames::I001_150_XA )
               && std::atoi( getValue( Cat001ItemNames::I001_150_XA ).c_str() ) == 1) ? 1 : 0; // XA
            // bit 6 is spare
            value[5] = (isItemPresent( Cat001ItemNames::I001_150_XC )
               && std::atoi( getValue( Cat001ItemNames::I001_150_XC ).c_str() ) == 1) ? 1 : 0; // XC
            // bit 4,3 are spare
            value[2] = (isItemPresent( Cat001ItemNames::I001_150_X2 )
               && std::atoi( getValue( Cat001ItemNames::I001_150_X2 ).c_str() ) == 1) ? 1 : 0; // X2
            // bit 0,1 are spare
            message.push_back( value.to_ulong() & 0xff );
            fspec[item.first] = true;
         }
      }
   }

   // add header to message
   getHeader( header, message.size() );
   message.insert( message.begin(), header.begin(), header.end() );

   return message;
}
