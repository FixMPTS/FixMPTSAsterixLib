/**
 * @file TestAsterixCAT65Decoding.h
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
 * Test cases to verify the Asterix CAT 65 decoding
 */
#ifndef TESTASTERIXCAT65DECODING_H_
#define TESTASTERIXCAT65DECODING_H_

//global includes
#include "extensions/HelperMacros.h"
#include <iostream>
#include <string.h>

class TestAsterixCAT65Decoding: public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE( TestAsterixCAT65Decoding );

   //Define the test testCAT034
   CPPUNIT_TEST( testCAT065 );
   CPPUNIT_TEST (testCAT065EnAndDecodingSDPS);
   CPPUNIT_TEST (testCAT065EnAndDecodingEoBatch);
   CPPUNIT_TEST (testCAT065EnAndDecodingService);
   CPPUNIT_TEST (testCAT065EnAndDecodingError);
   CPPUNIT_TEST_SUITE_END()
   ;

public:
   virtual void setUp() override;
   virtual void tearDown() override;

   /**
    * Test case for a complete Asterix CAT 65 message decoding
    */
   void testCAT065();

   /**
    * Test encoding and decoding of SDPS status messages
    */
   void testCAT065EnAndDecodingSDPS();

   /**
    * Test encoding and decoding of end of batch messages
    */
   void testCAT065EnAndDecodingEoBatch();

   /**
    * Test encoding and decoding of service Status messages
    */
   void testCAT065EnAndDecodingService();

   /**
    * Test error handling during encoding and decoding
    */
   void testCAT065EnAndDecodingError();
};

#endif /* TESTASTERIXCAT65DECODING_H_ */
