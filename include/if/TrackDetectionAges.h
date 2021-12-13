/**
 * @file TrackDetectionAges.h
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
 * Classes providing helper to determine how long a report shall be associated to a track and at which point
 * a track can be terminated based on its detection characteristics.
 */

#ifndef TRACKDETECTIONAGES_H_
#define TRACKDETECTIONAGES_H_

#include "DetectionEntry.h"
#include "AsterixEnumerations.h"

#include <map>

class TrackDetectionAges {
public:
   TrackDetectionAges();
   virtual ~TrackDetectionAges();
};

/**
 * Class providing the mapping between the maximum detection age and the corresponding type. The tracker will
 * remove the report from the report list and may terminate the track after the provided time has passed.
 */
class TrackMaxDetectionAgeMapping {
private:
   std::map<DetectionEntry::DET_TYPE, double> type_age_mapping; // Age in seconds

public:
   TrackMaxDetectionAgeMapping();
   TrackMaxDetectionAgeMapping(double age);
   virtual ~TrackMaxDetectionAgeMapping();

   /**
    * Set and get the maximum age for each report type defined in the ReportRecord data type
    */
   double getMaxAgePerType(DetectionEntry::DET_TYPE type);
   void setMaxAgePerType(DetectionEntry::DET_TYPE type, double age);

};

/**
 * Class providing the mapping of the maximum allowed ages per detection type. This allows for
 * individual configuration/handling of the timeout for the various detection technologies.
 */
class AsterixItemMaxAges: public TrackMaxDetectionAgeMapping {
private:
   std::map<AsterixEnumerations::ASTERIXAGEITEMS, double> item_age_mapping; // Age in seconds

public:
   AsterixItemMaxAges();
   virtual ~AsterixItemMaxAges();

   /**
    * Set and get the maximum age for each report type defined in the ReportRecord data type
    */
   double getMaxItemAge(AsterixEnumerations::ASTERIXAGEITEMS item);
   void setMaxItemAge(AsterixEnumerations::ASTERIXAGEITEMS item, double age);

};

#endif /* TRACKDETECTIONAGES_H_ */
