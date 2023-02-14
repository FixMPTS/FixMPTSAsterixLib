/**
 * @file TestAsterixCAT10Encoding.h
 * @author  Felix Kreuter <felix.kreuter@lordcentury.net>
 * @version 1.0
 * Created on: 6 Nov 2022
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * Test cases to verify th eAsterix Category 010 Eencoding
 */
#ifndef TESTASTERIXCAT10ENCODING_H_
#define TESTASTERIXCAT10ENCODING_H_

#include "extensions/HelperMacros.h"
#include <iostream>
#include <string.h>

#include "AsterixCategory010.h"
#include "TrackTypeIf.h"

class TestAsterixCAT10Encoding: public CppUnit::TestFixture {
   CPPUNIT_TEST_SUITE (TestAsterixCAT10Encoding);

   //Define the test cases
   CPPUNIT_TEST (testCAT010MandatoryTargetReport);
   CPPUNIT_TEST (testCAT010MandatoryStartUpdatCycle);
   CPPUNIT_TEST (testCAT010MandatoryPeriodicStatus);
   CPPUNIT_TEST_SUITE_END();

public:
   virtual void setUp() override;
   virtual void tearDown() override;

   /**
    * Test encoding of Asterix Cat 010 messages with only mandatory items
    */
   void testCAT010MandatoryTargetReport();
   void testCAT010MandatoryStartUpdatCycle();
   void testCAT010MandatoryPeriodicStatus();
};

#endif /* TESTASTERIXCAT10ENCODING_H_ */
