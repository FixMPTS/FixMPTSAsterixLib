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

class AsterixCategory010: public AsterixCategory {
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
};

#endif /* ASTERIXCATEGORY010_H_ */
