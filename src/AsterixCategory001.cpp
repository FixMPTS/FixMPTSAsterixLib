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

// Converter
#include "CommonConverter.h"
#include "IntegerConverter.h"
#include "DoubleConverter.h"
#include "UnsignedDoubleConverter.h"

#include "DetectionEntry.h"

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
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );
   sensor_identification.push_back(
      subitem_t( Cat001ItemNames::I001_010_SIC,
         std::make_shared<AsterixSubitemUnsigned>( 8, CommonConverter::NoneConverter ) ) );

   // Target Report descriptor
   subitem_map_t target_report_descriptor;
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_TYP,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Plot" }, { 1, "Track" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_SIM,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Actual Plot" },
               { 1, "Simulated Plot" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_DET,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "No Detection" }, { 1, "PSR" }, { 2,
               "SSR" }, { 3, "CMB" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_ANT,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Antenna 1" }, { 1, "Antenna 2" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_SPI,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "SPI set" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_RAB,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "RAB set" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_TST,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Test Target" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_DS1,
         std::make_shared<AsterixSubitemBitNamed>( 2, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1, "Code 7500" }, { 2,
               "Code 7600" }, { 3, "Code 7700" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_ME,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" },
               { 1, "Military Emergency" } } ) ) ) );
   target_report_descriptor.push_back(
      subitem_t( Cat001ItemNames::I001_020_MI,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1,
               "Military Identification" } } ) ) ) );

   subitem_map_t track_plot_number;
   track_plot_number.push_back(
      subitem_t( Cat001ItemNames::I001_161_TPN,
         std::make_shared<AsterixSubitemUnsigned>( 16, CommonConverter::NoneConverter ) ) );

   //Measured Position in Polar Coordinates
   subitem_map_t measure_pos_polar;
   measure_pos_polar.push_back(
      subitem_t( Cat001ItemNames::I001_040_RHO,
         std::make_shared<AsterixSubitemUnsigned>( 16, DoubleConverter::fraction128th ) ) );
   measure_pos_polar.push_back(
      subitem_t( Cat001ItemNames::I001_040_THETA,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::circleSegment16Bit ) ) );

   //Calculated Position in Cartesian Coordinates
   subitem_map_t measure_pos_cart;
   measure_pos_cart.push_back(
      subitem_t( Cat001ItemNames::I001_042_Y,
         std::make_shared<AsterixSubitemBase>( 16, CommonConverter::NoneConverter ) ) );
   measure_pos_cart.push_back(
      subitem_t( Cat001ItemNames::I001_042_X,
         std::make_shared<AsterixSubitemBase>( 16, CommonConverter::NoneConverter ) ) );

   //Calculated Track Velocity in Polar Coordinates
   subitem_map_t calc_vel_polar;
   calc_vel_polar.push_back(
      subitem_t( Cat001ItemNames::I001_200_GS,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::speedNMToKt ) ) );
   calc_vel_polar.push_back(
      subitem_t( Cat001ItemNames::I001_200_HEAD,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::circleSegment16Bit ) ) );

   //Mode 3A Code
   subitem_map_t mode_3a_code;
   mode_3a_code.push_back(
      subitem_t( Cat001ItemNames::I001_070_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // valid flag
   mode_3a_code.push_back(
      subitem_t( Cat001ItemNames::I001_070_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // garbled flag
   mode_3a_code.push_back(
      subitem_t( Cat001ItemNames::I001_070_L,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); //locally tracked flag
   mode_3a_code.push_back(
      subitem_t( Cat001ItemNames::I001_070_SPARE,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // Not used
   mode_3a_code.push_back(
      subitem_t( Cat001ItemNames::I001_070_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 12, CommonConverter::NoneConverter ) ) ); // code in octal representation

   //Mode C Code
   subitem_map_t mode_c_code;
   mode_c_code.push_back(
      subitem_t( Cat001ItemNames::I001_090_V,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // valid flag
   mode_c_code.push_back(
      subitem_t( Cat001ItemNames::I001_090_G,
         std::make_shared<AsterixSubitemUnsigned>( 1, CommonConverter::NoneConverter ) ) ); // garbled flag
   mode_c_code.push_back(
      subitem_t( Cat001ItemNames::I001_090_CODE,
         std::make_shared<AsterixSubitemUnsigned>( 14, IntegerConverter::lBitsToQuarter ) ) ); // code in binary representation

   //Truncated Time of Day
   subitem_map_t tod;
   tod.push_back(
      subitem_t( Cat001ItemNames::I001_141_TOD,
         std::make_shared<AsterixSubitemUnsigned>( 16, UnsignedDoubleConverter::fraction128th ) ) ); // Time since midnight in s

   //Radar Plot Characteristics
   subitem_map_t radar_plot_char;
   radar_plot_char.push_back(
      subitem_t( Cat001ItemNames::I001_130_CHAR,
         std::make_shared<AsterixSubitemBase>( 8, CommonConverter::NoneConverter ) ) ); // Application dependent

   //Received Power
   subitem_map_t received_power;
   received_power.push_back(
      subitem_t( Cat001ItemNames::I001_131_POW,
         std::make_shared<AsterixSubitemBase>( 8, CommonConverter::NoneConverter ) ) );

   //Measured Radial Doppler Speed
   subitem_map_t dopppler_speed;
   dopppler_speed.push_back(
      subitem_t( Cat001ItemNames::I001_120_DS,
         std::make_shared<AsterixSubitemBase>( 8, CommonConverter::NoneConverter ) ) );

   //Track Status
   subitem_map_t track_status;
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_CON,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Confirmed" }, { 1, "Tentative" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_RAD,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Primary" }, { 1, "SSR CMB" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_MAN,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1,
               "Aircraft manoeuvring" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_DOU,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Doubtful" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_RDCP,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "RDP Chain 1" }, { 1, "RDP Chain 2" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_SPARE,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_GHO,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t( { { 0, "Default" }, { 1, "Ghost" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_TRE,
         std::make_shared<AsterixSubitemBitNamed>( 1, CommonConverter::NoneConverter,
            AsterixSubitemBitNamed::value_names_t(
               { { 0, "Default" }, { 1, "Last Report" } } ) ) ) );
   track_status.push_back(
      subitem_t( Cat001ItemNames::I001_170_SPARE,
         std::make_shared<AsterixSubitemBase>( 7, CommonConverter::NoneConverter ) ) );

   //Track Quality
   subitem_map_t track_quality;
   track_quality.push_back(
      subitem_t( Cat001ItemNames::I001_210_QL,
         std::make_shared<AsterixSubitemUnsigned>( 7, CommonConverter::NoneConverter ) ) ); // Quality indicator

   //Mode 2 Code
   subitem_map_t mode_2_code;
   mode_2_code.push_back(
      subitem_t( Cat001ItemNames::I001_050_CODE,
         std::make_shared<AsterixSubitemBase>( 12, CommonConverter::NoneConverter ) ) ); // code in octal representation
   mode_2_code.push_back(
      subitem_t( Cat001ItemNames::I001_050_SPARE,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter ) ) ); // Not used
   mode_2_code.push_back(
      subitem_t( Cat001ItemNames::I001_050_L,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter ) ) ); //locally tracked flag
   mode_2_code.push_back(
      subitem_t( Cat001ItemNames::I001_050_G,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter ) ) ); // garbled flag
   mode_2_code.push_back(
      subitem_t( Cat001ItemNames::I001_050_V,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter ) ) ); // valid flag

   //Mode-3/A Code Confidence Indicator
   subitem_map_t m3a_conf_ind;
   m3a_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_080_QX,
         std::make_shared<AsterixSubitemBase>( 12, CommonConverter::NoneConverter ) ) ); // Quality per M3A Code bit
   m3a_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_080_SPARE,
         std::make_shared<AsterixSubitemBase>( 4, CommonConverter::NoneConverter ) ) ); // Not used

   //Mode-C Code and Code Confidence Indicator
   subitem_map_t mc_conf_ind;
   mc_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_100_QX,
         std::make_shared<AsterixSubitemBase>( 12, CommonConverter::NoneConverter ) ) ); // Quality per MC Code bit
   mc_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_100_SPARE,
         std::make_shared<AsterixSubitemBase>( 4, CommonConverter::NoneConverter ) ) ); // Not used
   mc_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_100_CODE,
         std::make_shared<AsterixSubitemBase>( 12, CommonConverter::NoneConverter ) ) ); // code in gray representation
   mc_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_100_SPARE,
         std::make_shared<AsterixSubitemBase>( 2, CommonConverter::NoneConverter ) ) ); // Not used
   mc_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_100_G,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter ) ) ); // garbled flag
   mc_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_100_V,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter ) ) ); // valid flag

   // Mode-2 Code Confidence Indicator
   subitem_map_t m2_conf_ind;
   m2_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_060_QX,
         std::make_shared<AsterixSubitemBase>( 12, CommonConverter::NoneConverter ) ) ); // Quality per M2 Code bit
   m2_conf_ind.push_back(
      subitem_t( Cat001ItemNames::I001_060_SPARE,
         std::make_shared<AsterixSubitemBase>( 4, CommonConverter::NoneConverter ) ) ); // Not used

   //Warning/Error Conditions
   subitem_map_t warning_err;
   warning_err.push_back(
      subitem_t( Cat001ItemNames::I001_030_ME,
         std::make_shared<AsterixSubitemBase>( 8, CommonConverter::NoneConverter ) ) );

   //Presence of X-Pulse
   subitem_map_t x_pulse;
   x_pulse.push_back(
      subitem_t( Cat001ItemNames::I001_150_XA,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter ) ) ); // Mode 3A impulse
   x_pulse.push_back(
      subitem_t( Cat001ItemNames::I001_150_SPARE,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter ) ) ); // Not used
   x_pulse.push_back(
      subitem_t( Cat001ItemNames::I001_150_XC,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter ) ) ); // Mode C impulse
   x_pulse.push_back(
      subitem_t( Cat001ItemNames::I001_150_SPARE,
         std::make_shared<AsterixSubitemBase>( 2, CommonConverter::NoneConverter ) ) ); // Not used
   x_pulse.push_back(
      subitem_t( Cat001ItemNames::I001_150_X2,
         std::make_shared<AsterixSubitemBase>( 1, CommonConverter::NoneConverter ) ) ); // Mode 2 impulse
   x_pulse.push_back(
      subitem_t( Cat001ItemNames::I001_150_SPARE,
         std::make_shared<AsterixSubitemBase>( 2, CommonConverter::NoneConverter ) ) ); // Not used

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
