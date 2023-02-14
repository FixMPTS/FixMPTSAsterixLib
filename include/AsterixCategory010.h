/**
 * @file AsterixCategory010.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 15 Dec 2017
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
 * Class representing 'Transmission of Monosensor Surface Movement Data' messages in Asterix CAT010
 */

#ifndef ASTERIXCATEGORY010_H_
#define ASTERIXCATEGORY010_H_

#include "AsterixCategory.h"
#include "TrackTypeIf.h"
#include "ReportRecordType.h"

class AsterixCategory010: public AsterixCategory {
private:
   // Just for convenience
   std::map<unsigned, std::string, cmpByFRN> fpsec_item_name_map =
      { { 1, "I010/010" }, { 2, "I010/000" }, { 3, "I010/020" }, { 4, "I010/140" }, { 5, "I010/041" }, { 6, "I010/040" },
         { 7, "I010/042" }, { 8, "I010/200" }, { 9, "I010/202" }, { 10, "I010/161" }, { 11, "I010/170" }, { 12, "I010/060" },
         { 13, "I010/220" }, { 14, "I010/245" }, { 15, "I010/250" }, { 16, "I010/300" }, { 17, "I010/090" }, { 18, "I010/091" },
         { 19, "I010/270" }, { 20, "I010/550" }, { 21, "I010/310" }, { 22, "I010/500" }, { 23, "I010/280" }, { 24, "I010/131" },
         { 25, "I010/210" }, /*one spare*/{ 27, "I010/SP" }, { 28, "I010/RE" } };
   /**
    * Initiate the UAP representing a single Asterix message. This defines the mapping
    * between the binary data and the information contained within the message.
    *
    * @throws Not yet decided
    */
   void setUAP() override;

   /**
    * Setup the detailed definition of all individual Asterix items.
    *
    * @throws Not yet decided
    */
   void setSubitems() override;

public:
   enum CAT_010_MESSAGE_TYPE {
      TARGET_REPORT = 1, START_UPDATE_CYLE = 2, PERIODIC_STATUS_MSG = 3, EVENT_TRIGGERED_STATUS_MSG = 4
   };

   enum TARGET_REPPORT_DESCRIPTOR {
      TYPE, DCR, CHN, GBS, CRT, SIM, TST, RAB, LOP, TOT, SPI
   };

   enum TRACK_STATUS {
      CNF, TRE, CST, MAH, TCC, STH, TOM, DOU, MRS, GHO
   };

   enum VEHICLE_FLEET_ID {
      UNKNOWN,
      ATC_MAIN,
      AIRPORT_MAIN,
      FIRE,
      BIRD_CTL,
      SNOW_PLG,
      RWY_SWEEP,
      EMERGENCY,
      POLICE,
      BUS,
      TUG,
      GRASS_CUTTER,
      FUEL,
      BAGGAGE,
      CATERING,
      AIRCRAFT_MAIN,
      FLYCO
   };

   AsterixCategory010();
   AsterixCategory010( int length );
   AsterixCategory010( int length, std::deque<char>& m_queue );
   virtual ~AsterixCategory010();

   /**
    * Store the values of the received Asterix message in the internal record transferred between
    * the different modules.
    *
    * @param record the pointer to the address where to store the values
    * @throws Not yet decided
    */
   void fillRecord(std::shared_ptr<ReportRecordType> record) override;

   /**
    * Encode the CAT 065 message based on the values provided
    *
    * @param record the record to take the values from. In case values are set via the dedicated setter those values
    *    will get priority over those set in the record.
    * @param items_to_be_served list of booleans indicating which values shall be served
    * @return the binary representation of the message
    */
   std::vector<char> getEncodedMessage(TrackTypeIf track, ReportRecordType record,
      std::map<std::string, bool> items_to_be_served);

   // Setter
   void setDataSourceIdentifier(unsigned short sac, unsigned short sic);
   void setMessageType(unsigned short type);
   void setTod(double tod);
   void setTargetReportDescriptor(TARGET_REPPORT_DESCRIPTOR item, unsigned short value);
   void setMeasuredPosition(double rho, double theta);
   void setWGSPosition(double lat, double lng);
   void setCartesianPosition(double x, double y);
   void setMode3A(bool v, bool g, bool l, int code);
   void setFlightLevel(bool v, bool g, float level);
   void setMeasuredHeight(float height);
   void setPRAmplitude(int amplitude);
   void setToD(double tod);
   void setTrackNumber(unsigned int nr);
   void setTrackStatus(TRACK_STATUS status, unsigned short value);
   void setCaculatedVelocityPolar(double speed, double angle);
   void setCalculatedVelocityCartesian(double vx, double vy);
   void setCalculatedAcceleration(double ax, double ay);
   void setTargetAddress(unsigned long addr);
   void setTargetIdentification(short sti, char id[8]);
   void addModeSMBData(unsigned long mbd, short bds1, short bds2);
   void removeModeSMBData(unsigned long mbd);
   void clearModeSMBData();
   void setTargetSizeOrientation(short length, double orientation, short width);
   void addPresence(double drho, double dtheta);
   void removePresence(double drho, double dtheta);
   void clearPresence();
   void setVehicleFleet(VEHICLE_FLEET_ID vfid);
   void setProgrammedMsg(bool trb, unsigned short msg);
   void setStdDeviationPos(double dx, double dy, double dxz);
   void setSystemStatus(short nogo, bool ovl, bool tsv, bool div, bool ttf);
};

#endif /* ASTERIXCATEGORY010_H_ */
