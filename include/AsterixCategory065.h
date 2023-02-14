/**
 * @file AsterixCategory065.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 8 Jan 2018
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
 * Representation class for Asterix Cat 65 (SDPS Status) messages
 */

#ifndef ASTERIXCATEGORY065_H_
#define ASTERIXCATEGORY065_H_

#include "AsterixCategory.h"
#include "SensorServiceRecordType.h"

class AsterixCategory065: public AsterixCategory {
private:

   // Just for convenience
   std::map<unsigned, std::string, cmpByFRN> fpsec_item_name_map =
      { { 1, "I065/010" }, { 2, "I065/000" }, { 3, "I065/015" }, { 4, "I065/030" }, { 5, "I065/020" }, { 6, "I065/040" },
         { 7, "I065/050" }/*8 to 111 not in use*/, { 12, "I065/RE" }, { 13, "I065/SP" } };

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
   enum SDPS_CONFIGURATION {
      NOGO, OVL, TSV, PSS, STTN
   };

   enum CAT_065_MESSAGE_TYPE {
      SDPS_STATUS = 1, END_OF_BATCH = 2, SERVICE_STATUS = 3
   };

   AsterixCategory065();
   AsterixCategory065( int length );
   AsterixCategory065( int length, std::deque<char>& m_queue );
   virtual ~AsterixCategory065();

   /**
    * Encode the CAT 065 message based on the values provided
    *
    * @param record the record to take the values from. In case values are set via the dedicated setter those values
    *    will get priority over those set in the record.
    * @param items_to_be_served list of booleans indicating which values shall be served
    * @return the binary representation of the message
    */
   std::vector<char> getEncodedMessage(SensorServiceRecordType record, std::map<std::string, bool> items_to_be_served);

   /**
    * Store the values of the received Asterix message in the internal record transferred between
    * the different modules.
    *
    * @param record the pointer to the address where to store the values
    * @throws Not yet decided
    */
   void fillRecord(std::shared_ptr<ReportRecordType> record) override;

   // Getter and Setter
   void setMessageType(unsigned short type);
   void setDataSourceId(unsigned short sac, unsigned short sic);
   void setServiceIdentification(unsigned int id);
   void setBatchNumber(unsigned short nr);
   void setTod(double time_of_day);
   void setSDPSConfiguration(SDPS_CONFIGURATION config, unsigned short value);
   void setReport(int report);
   void setReLatLng(double lat, double lng);
   void setSrp(int srp);
   void setArl(int arl);
};

#endif /* ASTERIXCATEGORY065_H_ */
