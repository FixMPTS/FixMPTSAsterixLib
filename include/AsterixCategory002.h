/**
 * @file AsterixCategory002.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 23 Jun 2017
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
 * Class responsible for the decoding and encoding of Asterix category 002 messages.
 */

#ifndef ASTERIXCATEGORY002_H_
#define ASTERIXCATEGORY002_H_

#include "AsterixCategory.h"
#include "SensorServiceRecordType.h"

class AsterixCategory002: public AsterixCategory {
private:

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
   virtual ~AsterixCategory002();
   AsterixCategory002();
   AsterixCategory002( int length );
   AsterixCategory002( int length, std::deque<char>& m_queue );

   /**
    * Store the information received in the given message into the internal report structure. Since
    * this message type carries only sensor related information, this method is not implemented.
    *
    * @param record the address of the record inside which the information shall be stored
    * @throws Not yet decided
    */
   void fillRecord(std::shared_ptr<ReportRecordType> record) override;

   /**
    * Encode the CAT 002 message based on the values provided
    *
    * @param record the record to take the values from. In case values are set via the dedicated setter those values
    *    will get priority over those set in the record.
    * @param items_to_be_served list of booleans indicating which values shall be served
    * @return the binary representation of the message
    */
   std::vector<unsigned char> getEncodedMessage(SensorServiceRecordType record,
      std::map<std::string, bool> items_to_be_served);

   /**
    * Setter for the various items. LSB calculation will be handled by the function
    */
   void setDataSource(unsigned short sac, unsigned short sic);
   void setMessageType(SensorServiceRecordType::MESSAGETYPE type);
   void setSectorNumber(unsigned short number);
   void setTimeOfDay(double time);
   void setAntennaRotationPeriod(double period);
   void setDynamicWindow(double rho_start, double rho_end, double theta_start, double theta_end);
   void setCollimationError(double range, double azimuth);
   void setWarningError(unsigned int value);

   /**
    * TODO
    */
   void resetPlotCount();
   void addPlotCount(bool antenna1, unsigned short identifier, unsigned short counter);
};

#endif /* ASTERIXCATEGORY002_H_ */
