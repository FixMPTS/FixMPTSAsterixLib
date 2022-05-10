/**
 * @file SensorServiceRecordType.h
 * @author  Felix Kreuter <felix.kreuter@lordcentury.net>
 * @version 1.0
 * Created on: 13 Mar 2022
 *
 @section LICENSE
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
 * Data type holding the information of a sensor service record
 */
#ifndef SENSORSERVICERECORDTYPE_H_
#define SENSORSERVICERECORDTYPE_H_

#include <vector>
#include <optional>
#include <tuple>

class SensorServiceRecordType {
public:

   /**
    * Inner class representing the plot/report count data type
    */
   class PlotCount {
   private:
      unsigned short antenna_nr;
      unsigned short ident;
      unsigned int counter;

   public:
      PlotCount();
      PlotCount(unsigned short antenna, unsigned short id, unsigned int count);

      // set
      void setAntenna(unsigned short antenna);
      void setIdent(unsigned short id);
      void setCounter(unsigned int count);

      // get
      unsigned short getAntenna();
      unsigned short getIdent();
      unsigned int getCounter();
   };

private:
   unsigned int sac;
   unsigned int sic;
   std::optional<unsigned short> message_type;
   std::optional<float> sector_number;
   std::optional<double> tod;
   std::optional<double> antenna_speed;
   std::vector<PlotCount> plot_count;

public:
   enum class MESSAGETYPE {
      NORTH_MARKER = 1, SECTOR_MARKER = 2, SOUTH_MARKER = 3, START_BLIND_ZONE = 8, STOP_BLIND_ZONE = 9
   };

   SensorServiceRecordType();
   SensorServiceRecordType(unsigned int sac, unsigned int sic);
   virtual ~SensorServiceRecordType();

   // set
   void setSensorIdentifier(unsigned int sac, unsigned int sic);
   void setMessageType(unsigned short type);
   void setSectorNumber(float sector);
   void setTimeOfDay(double tod);
   void setAntennaSpeed(double speed);

   // handle plot count
   void resetPlotCount();
   void addPlotCount(PlotCount entry);

   // presence
   bool isMessageTypePresent();
   bool isSectorNumberPresent();
   bool isAntennaSpeedPresent();

   // get
   std::tuple<unsigned int, unsigned int> getSensorId();
   unsigned short getMessageType();
   float getSectorNumber();
   double getTimeOfDay();
   double getAntennaSpeed();
   std::vector<PlotCount> getPlotCount();
};

#endif /* SENSORSERVICERECORDTYPE_H_ */
