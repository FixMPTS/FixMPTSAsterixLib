/**
 * @file AsterixCategory062.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 20 Mar 2016
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
 * Representation of an Asterix CAT 62 message. This includes de- and encoding of such messages.
 */

#ifndef ASTERIXCATEGORY062_H_
#define ASTERIXCATEGORY062_H_

#include "AsterixCategory.h"
#include "TrackDetectionAges.h"

#include <memory>

class AsterixCategory062: public AsterixCategory {

private:
   struct cmpByFRN {
      bool operator()( const unsigned a, const unsigned b ) const{
         return a < b;
      }
   };
   // Just for convenience
   std::map<unsigned, std::string, cmpByFRN> fpsec_item_name_map = { { 0, "I062/010" }, { 1, "I062/SPARE1" },
   { 2, "I062/015" }, { 3, "I062/070" }, { 4, "I062/105" }, { 5, "I062/100" }, { 6, "I062/185" }, { 7, "I062/210" },
      { 8, "I062/060" }/*, { 9, "I062/245" } Not encoded*/, { 10, "I062/380" },
      { 11, "I062/040" }, { 12, "I062/080" }, { 13, "I062/290" }, { 14, "I062/200" },
      { 15, "I062/295" }, { 16, "I062/136" }, { 17, "I062/130" }, { 18, "I062/135" },
      { 19, "I062/220" }, { 20, "I062/390" }, { 21, "I062/270" }, { 22, "I062/300" }, { 23, "I062/110" },
      { 24, "I062/120" }, { 25, "I062/510" }, { 26, "I062/500" }, { 27, "I062/340" } };

   //
   std::map<std::string, unsigned char> non_track_related_values;
   std::map<std::string, std::string> service_related_values;

   /**
    * Definition of the CAT 062  track message UAP.
    *
    * @param None
    * @return None
    * @throw None
    */
   void setUAP() override;

   /**
    * Definition of the sub items. At this point it also specified how the raw value will be decoded
    * in order to fit to the internally used record structure.
    *
    * @param None
    * @return None
    * @throw None
    */
   void setSubitems() override;

public:
   // The maximum age of the most detection types encoded within the message type
   double const DETECTION_TYPE_MAX_AGE = 63.75; // in seconds

   AsterixCategory062();
   virtual ~AsterixCategory062();

   /**
    * There are some values not part of the track to be encoded. An example are the service ID or
    * the SDPS identifications. But those values are part of the message. Therefore those values have
    * to be announced to the encoding.
    *
    * @param v a list of values to be encoded but not part of the track structure
    * @throws Not yet decided
    */
   void setNonTrackRelatedValues(std::map<std::string, unsigned char> v);

   /**
    * Add a value not contained in the track structure but related to the service the category is
    * encoded for, to the internal list of such items.
    *
    * @param name the name of the item. This name has to match the name expected by the service. See
    * the ICD for details on all allowed names
    * @param value the string representation of the value to be encoded.
    * @throws Not yet decided
    */
   void setServiceRelatedValue( std::string name, std::string value );

   /**
    * Get the encoded message based on the given track and all values known. This includes also
    * some values not directly related to the track like the service id and SDPS identification
    *
    * @param track the track to be encoded
    * @param items_to_be_served the list of items configured to be served. The mandatory items are sned
    * anyway no matter what is configured.
    * @param max_ages the maximum detection ages for all Asterix items that have timeouts for their value
    * @return the encoded message
    * @throws MandatoryItemMissing
    */
   virtual std::vector<unsigned char> getEncodedMessage(std::shared_ptr<TrackTypeIf> track,
      std::map<std::string, bool> items_to_be_served, std::shared_ptr<AsterixItemMaxAges> max_ages);

   /**
    * Store the values of the received Asterix message in the internal record transferred between
    * the different modules.
    *
    * @param record the pointer to the address where to store the values
    * @throws Not yet decided
    */
   void fillRecord(std::shared_ptr<ReportRecordType> record) override;

};

#endif /* ASTERIXCATEGORY062_H_ */
