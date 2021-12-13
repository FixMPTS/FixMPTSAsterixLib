/**
 * @file TestAsterixCAT244Decoding.h
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
 * Verify the Asterix CAT 244 decoding
 */
#ifndef TESTASTERIXCAT244DECODING_H_
#define TESTASTERIXCAT244DECODING_H_

//global includes
#include "extensions/HelperMacros.h"
#include <iostream>
#include <string.h>

class TestAsterixCAT244Decoding: public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE( TestAsterixCAT244Decoding );

   //Define the test testCAT034
   CPPUNIT_TEST( testCAT244 );
   CPPUNIT_TEST( testCAT244Mach );
   CPPUNIT_TEST_SUITE_END()
   ;

public:
   virtual void setUp() override;
   virtual void tearDown() override;

   /**
    * Asterix CAT 244 (SMART Trajectory( test case
    */
   void testCAT244();
   void testCAT244Mach();
};

#endif /* TESTASTERIXCAT244DECODING_H_ */
