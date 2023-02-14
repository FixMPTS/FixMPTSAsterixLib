/**
 * @file TestAsterixCAT63Decoding.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 1 Mar 2019
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
 * Test case verifying the Asterix CAT 63 decoding
 */
#ifndef TESTASTERIXCAT63DECODING_H_
#define TESTASTERIXCAT63DECODING_H_

//global includes
#include "extensions/HelperMacros.h"
#include <iostream>
#include <string.h>

class TestAsterixCAT63Decoding: public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE( TestAsterixCAT63Decoding );

   //Define the test testCAT034
   CPPUNIT_TEST (testCAT063);
   CPPUNIT_TEST (testCAT063EnAndDecoding);
   CPPUNIT_TEST_SUITE_END()
   ;

public:
   virtual void setUp() override;
   virtual void tearDown() override;

   /**
    * Test case for Asterix CAT 63 messages
    */
   void testCAT063();

   /**
    * Test encoding and decoding of messages
    */
   void testCAT063EnAndDecoding();
};

#endif /* TESTASTERIXCAT63DECODING_H_ */
