/**
 * @file TestAsterixCAT19Decoding.h
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
 * Test case to verify the decoding of Asterix CAT 19 messages
 */
#ifndef TESTASTERIXCAT19DECODING_H_
#define TESTASTERIXCAT19DECODING_H_

//global includes
#include "extensions/HelperMacros.h"
#include <iostream>
#include <string.h>

class TestAsterixCAT19Decoding: public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE( TestAsterixCAT19Decoding );

   //Define the test cases
   CPPUNIT_TEST( testCAT019Start );
   CPPUNIT_TEST_SUITE_END()
   ;

public:
   virtual void setUp() override;
   virtual void tearDown() override;

   /**
    * Asterix CAT 19 test cases
    */
   void testCAT019Start();
};

#endif /* TESTASTERIXCAT19DECODING_H_ */
