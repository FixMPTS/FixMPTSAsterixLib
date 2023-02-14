/**
 * @file AsterixCategory063.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 3 Jan 2018
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
 * Class representing an Asterix CAT 63 message taking care of the decoding and encoding process.
 */

#ifndef ASTERIXCATEGORY063_H_
#define ASTERIXCATEGORY063_H_

#include "AsterixCategory.h"
#include "SensorServiceRecordType.h"

class AsterixCategory063: public AsterixCategory {
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

   // Just for convenience
   std::map<unsigned, std::string, cmpByFRN> fpsec_item_name_map =
      { { 1, "I063/010" }, { 2, "I063/015" }, { 3, "I063/030" }, { 4, "I063/050" }, { 5, "I063/060" }, { 6, "I063/070" },
         { 7, "I063/080" }, { 8, "I063/081" }, { 9, "I063/090" }, { 10, "I063/091" }, { 11, "I063/092" },
         /* gap */{ 13, "I063/RE" }, { 14, "I063/SP" } };

public:

   enum SENSOR_CONFIGURATION {
      CON, PSR, SSR, MDS, ADS, MLT, OPS, ODP, OXT, MSC, TSV, NPW
   };

   AsterixCategory063();
   AsterixCategory063( int length );
   AsterixCategory063( int length, std::deque<char>& m_queue );
   virtual ~AsterixCategory063();

   /**
    * Store the values of the received Asterix message in the internal record transferred between
    * the different modules.
    *
    * @param record the pointer to the address where to store the values
    * @throws Not yet decided
    */
   void fillRecord(std::shared_ptr<ReportRecordType> record) override;

   /**
    * Encode the CAT 063 message based on the values provided
    *
    * @param record the record to take the values from. In case values are set via the dedicated setter those values
    *    will get priority over those set in the record.
    * @param items_to_be_served list of booleans indicating which values shall be served
    * @return the binary representation of the message
    */
   std::vector<char> getEncodedMessage(SensorServiceRecordType record, std::map<std::string, bool> items_to_be_served);

   // Getter and setter for the items in this category
   void setSourceId(unsigned short sac, unsigned short sic);
   void setServiceId(unsigned short id);
   void setTod(double time_of_day);
   void setSensorId(unsigned short sac, unsigned short sic);
   void setSensorConfiguration(SENSOR_CONFIGURATION config, unsigned short value);
   void setTimestampingBias(double value);
   void setSSRRangeGainBias(double srg, double srb);
   void setSSRAzimuthBias(double value);
   void setPSRRangeGainBias(double prg, double prb);
   void setPSRAzimuthBias(double value);
   void setPSRElevationBias(double value);
};

#endif /* ASTERIXCATEGORY063_H_ */
