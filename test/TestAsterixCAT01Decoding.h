/**
 * @file TestAsterixCAT01Decoding.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 28 Feb 2019
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
 * Test case to verify the correct decoding of Asterix CAT 001 messages
 */
#ifndef TESTASTERIXCAT01DECODING_H_
#define TESTASTERIXCAT01DECODING_H_

// global includes
#include "extensions/HelperMacros.h"
#include <iostream>
#include <string.h>

class TestAsterixCAT01Decoding: public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE( TestAsterixCAT01Decoding );

   //Define the test cases
   CPPUNIT_TEST( testCAT001 );
   CPPUNIT_TEST( test2CAT001 );
   CPPUNIT_TEST_SUITE_END()
   ;

public:

   virtual void setUp() override;
   virtual void tearDown() override;

   /**
    * Test at least one well defined CAt 001 message with as many items as possible.
    *
    * @param None
    * @return None
    * @throw None
    */
   void testCAT001();

   void test2CAT001();
};

#endif /* TESTASTERIXCAT01DECODING_H_ */
