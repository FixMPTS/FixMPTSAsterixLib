/**
 * @file DetectionEntry.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 5 Apr 2021
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
 * Helper class providing the storage and access to detection related attributes.
 */
#ifndef DETECTIONENTRY_H_
#define DETECTIONENTRY_H_

#include "PointXYZ.h"

#include <optional>
#include <vector>
#include <tuple>

class DetectionEntry {
public:
   //Basically the sensor type, except for CMB where the detection type must not match the sensor type
   enum class DET_TYPE {
      PSR, SSR, CMB, MDS, CMB_MDS, ADS_B, ADS_C, MLAT, TRACK, NONE
   };

   // Enumerate the possible link types. Currently only used for ADS-B
   enum class DET_LINK {
      NO_LINK, ADS_B_ES, ADS_B_UAT, ADS_B_VDL
   };

   /*
    * Class to store codes like the M3A or Mode C
    */
   class ModeX {
   private:
      int code;
      bool valid;
      bool garbled;

   public:
      ModeX();
      ModeX(int code, bool valid, bool garbled);

      int getCode();
      bool isValid();
      bool isGarbled();
   };

private:
   DET_TYPE detection_type;
   std::vector<std::tuple<unsigned short, unsigned short>> sensor_list;
   bool valid;
   PointXYZ measurement;

   // Modes
   std::optional<ModeX> mode_3A;
   std::optional<ModeX> mode_c;

public:
   DetectionEntry();
   DetectionEntry(DET_TYPE t);
   virtual ~DetectionEntry();

   // GET
   DET_TYPE getDetectionType();
   unsigned short getSourceIDSacAt(unsigned int pos);
   unsigned short getSourceIDSicAt(unsigned int pos);

   bool isDummyDetection();

   double getMeasuredRange();
   double getMeasuredAzimuth();

   std::optional<double> get3DHeight();
   std::optional<ModeX> getModeC();
   std::optional<ModeX> getMode3A();

   // SET
   void setDetectionType(DET_TYPE t);
   void addContributingSensor(std::tuple<unsigned short, unsigned short> sensor);
   void setMeasurement(PointXYZ measurement);
   void setMode3A(ModeX mode);
   void setModeC(ModeX mode);

   /**
    * Remove the given sensor from the list of sensors contributing to the track,
    */
   void removeContributingSensor(std::tuple<unsigned short, unsigned short> ssensor, bool single = false);
   void removeContributingSensorAt(size_t pos);
};

#endif /* DETECTIONENTRY_H_ */
