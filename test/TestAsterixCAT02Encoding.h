/**
 * @file TestAsterixCAT02Encoding.h
 * @author  Felix Kreuter <felix.kreuter@lordcentury.net>
 * @version 1.0
 * Created on: 31 Mar 2022
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
 * see .h file for more information
 */
#ifndef TESTASTERIXCAT02ENCODING_H_
#define TESTASTERIXCAT02ENCODING_H_

// global includes
#include "extensions/HelperMacros.h"
#include <iostream>
#include <string.h>

class TestAsterixCAT02Encoding: public CppUnit::TestFixture {
   CPPUNIT_TEST_SUITE (TestAsterixCAT02Encoding);

   //Define the test cases
   CPPUNIT_TEST (testCAT002Mandatory);
   CPPUNIT_TEST (testCAT002Common);
   CPPUNIT_TEST (testCAT002EnAndDecoding);
   CPPUNIT_TEST_SUITE_END();

public:
   virtual void setUp() override;
   virtual void tearDown() override;

   /**
    * Test encoding of Asterix Cat 002 messages
    */
   void testCAT002Mandatory();

   /**
    * Test with a commonly used report with not only mandatory items
    */
   void testCAT002Common();

   /**
    * Test encoding and decoding of messages
    */
   void testCAT002EnAndDecoding();
};

#endif /* TESTASTERIXCAT02ENCODING_H_ */
