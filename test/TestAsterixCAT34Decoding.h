/**
 * @file TestAsterixCAT34Decoding.h
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
 * Test cases to verify the decoding of Asterix CAT 34 messages
 */
#ifndef TESTASTERIXCAT34DECODING_H_
#define TESTASTERIXCAT34DECODING_H_

//global includes
#include "extensions/HelperMacros.h"
#include <iostream>
#include <string.h>

class TestAsterixCAT34Decoding: public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE( TestAsterixCAT34Decoding );

   //Define the test testCAT034
   CPPUNIT_TEST( testCAT034 );
   CPPUNIT_TEST_SUITE_END()
   ;

public:
   virtual void setUp() override;
   virtual void tearDown() override;

   /**
    * Test case to verify the decoding of Asterix CAT 034 messages
    *
    * @throws Assertion error on failed test
    */
   void testCAT034();
};

#endif /* TESTASTERIXCAT34DECODING_H_ */
