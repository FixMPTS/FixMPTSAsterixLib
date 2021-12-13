/**
 * @file GeneralEnumerations.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 19 Apr 2016
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
 * This header is supposed to provide a set of enumerators shared between different classes/processes.
 * Complex structures which make use of enumerators that are shared between different objects
 * of the SDPS system shall relay on enumerators specified within this header.
 */
#ifndef GENERALENUMERATIONS_H_
#define GENERALENUMERATIONS_H_

// global includes
#include <map>

class GenericEnumerations {
public:
   // List of Aircraft Derived Data items
   enum class AIRCRAFT_DERIVED_DATA_ITEM_NAMES
      : unsigned int {
      NONE_ADD, SPI, ADR, ID, TIS, MB, BPS, MAC, IAR, MD, PUN, GAL, POS, EMC, MET, VUN, GSP, TAN,
      TAR, RAN, GVR, BVR, ACS, SAB, COM, TID, FSS, SAL, TAS, IAS, MHG, MD5, MD4, MDA, MD2, MD1, MFL
   };
   enum class AIRCRAFT_DERIVED_DATA_SUB_ITEM_NAMES {
      DAP_POS_LAT, DAP_POS_LNG
   };

   // Enumeration of all available age items
   enum class AGE_ITEMS {
      DET_PSR, DET_SSR, DET_CMB, DET_MDS, DET_CMB_MDS, DET_ADS_B, DET_ADS_C, DET_MLAT, DET_TRACK,
      /*ADS-B link technology ages*/
      DET_ADS_B_UAT, DET_ADS_B_VDL, DET_ADS_B_ES,
      /* LIST of available DAP AGES all starting with DAP*/
      DAP_MEAS_FL, DAP_MODE_1, DAP_MODE_2, DAP_MODE_3A, DAP_MODE_4, DAP_MODE_5, DAP_MHG, DAP_IAS,
      DAP_TAS, DAP_SAL, DAP_FSG, DAP_FSS, DAP_TID, DAP_COM, DAP_SAB, DAP_ACS, DAP_BVR, DAP_GVR,
      DAP_RAN, DAP_TAR, DAP_TAN, DAP_GSP, DAP_VUN, DAP_MET, DAP_EMC, DAP_POS, DAP_GAL, DAP_PUN,
      DAP_MB, DAP_IAR, DAP_MAC, DAP_BPS, NO_AGE
   };

private:
   const std::map<GenericEnumerations::AIRCRAFT_DERIVED_DATA_ITEM_NAMES, GenericEnumerations::AGE_ITEMS> add2age = { {
      AIRCRAFT_DERIVED_DATA_ITEM_NAMES::BPS, AGE_ITEMS::DAP_BPS },
      { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MAC, AGE_ITEMS::DAP_MAC }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TAR,
         AGE_ITEMS::DAP_TAR }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::PUN, AGE_ITEMS::DAP_PUN }, {
         AIRCRAFT_DERIVED_DATA_ITEM_NAMES::GAL, AGE_ITEMS::DAP_GAL }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::POS,
         AGE_ITEMS::DAP_POS },
      { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::EMC, AGE_ITEMS::DAP_EMC }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MET,
         AGE_ITEMS::DAP_MET }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::VUN, AGE_ITEMS::DAP_VUN }, {
         AIRCRAFT_DERIVED_DATA_ITEM_NAMES::GSP, AGE_ITEMS::DAP_GSP }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TAN,
         AGE_ITEMS::DAP_TAN },
      { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::RAN, AGE_ITEMS::DAP_RAN }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::GVR,
         AGE_ITEMS::DAP_GVR }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::BVR, AGE_ITEMS::DAP_BVR }, {
         AIRCRAFT_DERIVED_DATA_ITEM_NAMES::ACS, AGE_ITEMS::DAP_ACS }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::SAB,
         AGE_ITEMS::DAP_SAB },
      { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::COM, AGE_ITEMS::DAP_COM }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TID,
         AGE_ITEMS::DAP_TID }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::FSS, AGE_ITEMS::DAP_FSS }, {
         AIRCRAFT_DERIVED_DATA_ITEM_NAMES::SAL, AGE_ITEMS::DAP_SAL }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::TAS,
         AGE_ITEMS::DAP_TAS },
      { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::IAS, AGE_ITEMS::DAP_IAS }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MHG,
         AGE_ITEMS::DAP_MHG }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MD5, AGE_ITEMS::DAP_MODE_5 }, {
         AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MD4, AGE_ITEMS::DAP_MODE_4 },
      { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MDA, AGE_ITEMS::DAP_MODE_3A }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MD2,
         AGE_ITEMS::DAP_MODE_2 }, { AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MD1, AGE_ITEMS::DAP_MODE_1 }, {
         AIRCRAFT_DERIVED_DATA_ITEM_NAMES::MFL, AGE_ITEMS::DAP_MEAS_FL } };

   std::map<AGE_ITEMS, AIRCRAFT_DERIVED_DATA_ITEM_NAMES> createAge2Add(){
      std::map<AGE_ITEMS, AIRCRAFT_DERIVED_DATA_ITEM_NAMES> return_map;
      for( auto key_value : add2age ) {
         return_map[key_value.second] = key_value.first;
      }
      return return_map;
   }
   const std::map<AGE_ITEMS, AIRCRAFT_DERIVED_DATA_ITEM_NAMES> age2add = createAge2Add();

public:

   AIRCRAFT_DERIVED_DATA_ITEM_NAMES translateAddToAge( AGE_ITEMS item ){
      if( age2add.find( item )!=age2add.end() ) {
         return age2add.at( item );
      }
      return AIRCRAFT_DERIVED_DATA_ITEM_NAMES::NONE_ADD;
   }
   AGE_ITEMS translateAgeToAdd( AIRCRAFT_DERIVED_DATA_ITEM_NAMES item ){
      if( add2age.find( item )!=add2age.end() ) {
         return add2age.at( item );
      }
      return AGE_ITEMS::NO_AGE;
   }
};

#endif /* GENERALENUMERATIONS_H_ */
