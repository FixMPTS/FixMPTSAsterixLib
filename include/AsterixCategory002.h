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
};

#endif /* ASTERIXCATEGORY002_H_ */
