/**
 * @file AsterixCategory001.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
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
 * Representation of the Asterix CAT 001 message block. Purpose of this derived class is to provide
 * the correct UAP and sub item list. This class will also implement the fillRecord method. The UAP
 * is the one for CAT 001 track messages.
 */

#ifndef ASTERIXCATEGORY001_H_
#define ASTERIXCATEGORY001_H_

#include "AsterixCategory.h"

#include <iostream>
#include <algorithm>

class AsterixCategory001: public AsterixCategory {

private:

   /**
    * Definition of the cat 001 track message UAP.
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

   /**
    * Initialise the Asterix Cat 001 block by setting the specific UAP and sub item list. At this point
    * the message buffer still need to be provided.
    *
    * @param None
    * @return None
    * @throw None
    */
   AsterixCategory001();

   /**
    * Initialise the Asterix Cat 001 block by setting the specific UAP and sub item list. At this point
    * the message buffer still need to be provided.
    *
    * @param None
    * @return None
    * @throw None
    */
   AsterixCategory001( int length );

   /**
    * Initialise the Asterix Cat 001 block by setting the specific UAP and sub item list.
    *
    * @param None
    * @return None
    * @throw None
    */
   AsterixCategory001( int length, std::deque<char>& m_queue );

   /**
    * Fill the generic message record. This record can then be used internally by other processes or
    * modules. In order to fill the record the semantic of the message need to be known.
    *
    * @param record The record to be filled
    * @return None
    * @throw None
    */
   void fillRecord(std::shared_ptr<ReportRecordType> record) override;

   /**
    * TODO
    */
   std::vector<unsigned char> getEncodedMessage(std::shared_ptr<ReportRecordType> record,
      std::map<std::string, bool> items_to_be_served);
};

#endif /* ASTERIXCATEGORY001_H_ */
