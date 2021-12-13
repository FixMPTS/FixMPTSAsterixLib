/**
 * @file TrackDetectionAges.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 11 Jan 2019
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

#include "TrackDetectionAges.h"

#include <limits>

TrackDetectionAges::TrackDetectionAges() {

}

TrackDetectionAges::~TrackDetectionAges() {
}

//*******************************************************************************************
//****************** TrackMaxDetectionAgeMapping Implementation *****************************
//*******************************************************************************************
TrackMaxDetectionAgeMapping::TrackMaxDetectionAgeMapping() :
   TrackMaxDetectionAgeMapping( 0.0 ) {
}

TrackMaxDetectionAgeMapping::TrackMaxDetectionAgeMapping(double age) {
   for( unsigned int item = static_cast<unsigned int>( DetectionEntry::DET_TYPE::PSR );
      item <= static_cast<unsigned int>( DetectionEntry::DET_TYPE::TRACK ); item++ ) {
      type_age_mapping[static_cast<DetectionEntry::DET_TYPE>( item )] = age;
   }
   type_age_mapping[DetectionEntry::DET_TYPE::NONE] = std::numeric_limits<double>::max();
}

TrackMaxDetectionAgeMapping::~TrackMaxDetectionAgeMapping() {

}

double TrackMaxDetectionAgeMapping::getMaxAgePerType(DetectionEntry::DET_TYPE type) {
   return type_age_mapping.at( type );
}

void TrackMaxDetectionAgeMapping::setMaxAgePerType(DetectionEntry::DET_TYPE type, double age) {
   type_age_mapping[type] = age;
}

//*******************************************************************************************
//****************** AsterixItemMaxAges Implementation **************************************
//*******************************************************************************************
AsterixItemMaxAges::AsterixItemMaxAges() {

}

AsterixItemMaxAges::~AsterixItemMaxAges() {

}

double AsterixItemMaxAges::getMaxItemAge(AsterixEnumerations::ASTERIXAGEITEMS item) {
   return item_age_mapping.at( item );
}

void AsterixItemMaxAges::setMaxItemAge(AsterixEnumerations::ASTERIXAGEITEMS item, double age) {
   item_age_mapping[item] = age;
}
