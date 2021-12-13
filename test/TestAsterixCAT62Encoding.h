/**
 * @file TestAsterixCAT62Encoding.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 13 May 2016
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
 * Class to provide the test cases for the Asterix CAT 62 encoding functions. This includes testing
 * of the helper functions which just encode one item as well as the overall encoding of entire
 * CAT 62 messages with several different item selections.
 */
#ifndef TESTASTERIXCAT62ENCODING_H_
#define TESTASTERIXCAT62ENCODING_H_

//global includes
#include <iostream>
#include <string.h>
#include <map>
#include "extensions/HelperMacros.h"

// local includes
#include "AsterixCategory062.h"
#include "AsterixEncodingHelper.h"

class TestAsterixCAT62Encoding: public CppUnit::TestFixture {
   CPPUNIT_TEST_SUITE (TestAsterixCAT62Encoding);

   //Define the test cases
   CPPUNIT_TEST (testI062_010);
   CPPUNIT_TEST (testI062_015);
   CPPUNIT_TEST (testI062_070);
   CPPUNIT_TEST (testI062_105);
   CPPUNIT_TEST (testI062_060);
   CPPUNIT_TEST (testI062_040);
   CPPUNIT_TEST (testI062_080);
   CPPUNIT_TEST (testI062_290);
   CPPUNIT_TEST (testI062_200);
   CPPUNIT_TEST (testI062_295);
   CPPUNIT_TEST (testI062_136);
   CPPUNIT_TEST (testI062_130);
   CPPUNIT_TEST (testI062_135);
   CPPUNIT_TEST (testI062_220);
   CPPUNIT_TEST (testI062_340);
   CPPUNIT_TEST (testI062_380);
   CPPUNIT_TEST_SUITE_END();

private:
   std::shared_ptr<AsterixItemMaxAges> max_ages;

public:
   virtual void setUp() override;
   virtual void tearDown() override;

   /**
    * Test of item I062/010 encoding. It is tested the proper entry in the FPSEC is set as well as
    * different combinations of the SAC/SICs passed into the helper function
    */
   void testI062_010();

   /**
    * Test case for item I062/015 (service identification) encoding
    */
   void testI062_015();

   /**
    * Test case for item I062/070 (Time of Track Information) encoding
    */
   void testI062_070();

   /**
    * Test case for the WGS position. This test verifies the complete CAT 62 message is encoded
    * correctly with respect to the item I062/105 and the dedicated encoding function works as
    * expected as well.
    */
   void testI062_105();

   /**
    * Test case for the encoding of the Mode 3A. This test verifies the correct FSPEC bit is set as
    * well as the mode 3A encoding within a complete CAT 62 message. In addition also the standalone
    * encoding function is tested.
    */
   void testI062_060();

   /**
    * Test case for item I062/040 track number. Several numbers within the range are tested along
    * with a dedicated test to make sure the fpsec is encoded properly.
    */
   void testI062_040();

   /**
    * Test case for item I062/080 Track Status. This test include some testing for the message
    * fspec.
    */
   void testI062_080();

   /**
    * Test case for item I062/290, System Track update Ages. Several different combinations of
    * updating age and max age are tested. Along with this also the correct encoding of a complete
    * Asterix message, with respect to this item, as well as the encoding of the FSPEC is checked.
    */
   void testI062_290();

   /**
    * Test cases for the Mode of Movement encoding. This test verifies the encoding with in a CAT 62
    * message along with the FSPEC. IN addition the encoding function is tested separately.
    */
   void testI062_200();

   /**
    * Test case for item I062/295 Track Data ages. It is tested that the CAT 62 message containing
    * item 062/295 is properly encoded along with the correct FSPEC set. In second subset of tests
    * it is also made sure, that the stand alone encoding function is working as expected.
    */
   void testI062_295();

   /**
    * Test case for the measured flight level. This item is derived from the reported mode C. It is
    * tested that the encoding of all mandatory items, the correct fpspec and the correct encoding of
    * this item works as designed. After that a set of stand alone test are conducted to verify the
    * underlying encoding function.
    */
   void testI062_136();

   /**
    * Test for the Calculated Track Geometric Altitude data item. Within this test case the encoding
    * of a CAT 62 message containing all mandatory items along with the proper fspec and the
    * calculated track geometric altitude is tested. It is also verified, that the stand alone encoding
    * of this items works as expected.
    */
   void testI062_130();

   /**
    * Test cases for the encoding of the measured flight level. Within this test the encoding of one
    * CAT 62 containing the mandatory items, fpsec plus item I062/120 is tested. In addition also the
    * stand alone encoding function is evaluated.
    */
   void testI062_135();

   /**
    * Test cases to verify the correct encoding of the rate of climb and descent. Within this test
    * the correct encoding of a CAT 62 message, the corresponding fspec and item I062/220 in stead.
    * in addition also the stand alone encoding function is verified.
    */
   void testI062_220();

   /**
    * Test case for the measured information item. Within this test it is verified that the fspec is
    * encoded as expected. In addition the encoding of one CAT 62 message including all mandatory
    * items along with item I062/340 is verified. In a further test the stand alone encoding function
    * for the measured information is checkd.
    */
   void testI062_340();

   /**
    * Test the encoding of the aircraft derived data item. The test verifies the correctness of the
    * complete message encoded along with all mandatory items, the fpsec and this item. In addition
    * also the stand alone encoding function is tested.
    */
   void testI062_380();
};

#endif /* TESTASTERIXCAT62ENCODING_H_ */
