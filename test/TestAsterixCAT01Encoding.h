/**
 * @file TestAsterixCAT01Encoding.h
 * @author  Felix Kreuter <felix.kreuter@lordcentury.net>
 * @version 1.0
 * Created on: 6 Feb 2022
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
 * Test cases to verify the encoding of Asterix Cat 001 messages
 */
#ifndef TESTASTERIXCAT01ENCODING_H_
#define TESTASTERIXCAT01ENCODING_H_

// global includes
#include "extensions/HelperMacros.h"
#include <iostream>
#include <string.h>

class TestAsterixCAT01Encoding: public CppUnit::TestFixture {
   CPPUNIT_TEST_SUITE (TestAsterixCAT01Encoding);

   //Define the test cases
   CPPUNIT_TEST (testCAT001Mandatory);
   CPPUNIT_TEST (testCAT001Common);
   CPPUNIT_TEST_SUITE_END();

public:

   virtual void setUp() override;
   virtual void tearDown() override;

   /**
    * Test encoding of Asterix Cat 001 messages
    */
   void testCAT001Mandatory();

   /**
    * Test with a commonly used report with not only mandatory items
    */
   void testCAT001Common();
};

#endif /* TESTASTERIXCAT01ENCODING_H_ */
