/**
 * @file TestAsterixMain.cpp
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
 * Main Test Suite to combine all Asterix related unit test cases.
 */

// local includes
#include "TestAsterixCAT62Encoding.h"
#include "TestAsterixCAT01Decoding.h"
#include "TestAsterixCAT02Decoding.h"
#include "TestAsterixCAT10Decoding.h"
#include "TestAsterixCAT11Decoding.h"
#include "TestAsterixCAT19Decoding.h"
#include "TestAsterixCAT20Decoding.h"
#include "TestAsterixCAT21Decoding.h"
#include "TestAsterixCAT23Decoding.h"
#include "TestAsterixCAT25Decoding.h"
#include "TestAsterixCAT32Decoding.h"
#include "TestAsterixCAT34Decoding.h"
#include "TestAsterixCAT48Decoding.h"
#include "TestAsterixCAT61Decoding.h"
#include "TestAsterixCAT63Decoding.h"
#include "TestAsterixCAT65Decoding.h"
#include "TestAsterixCAT204Decoding.h"
#include "TestAsterixCAT244Decoding.h"

//#include "Core/Logging/LogManager.h"
//#include "Core/Logging/Termlog.h"

//global includes
#include "extensions/TestFactoryRegistry.h"
#include "TestRunner.h"
#include "ui/text/TestRunner.h"
#include "extensions/HelperMacros.h"
#include "TestResult.h"
#include "TestResultCollector.h"
#include "XmlOutputter.h"
#include "TextOutputter.h"

CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT62Encoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT01Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT02Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT10Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT11Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT19Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT20Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT21Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT23Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT25Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT32Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT34Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT48Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT61Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT63Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT65Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT204Decoding );
CPPUNIT_TEST_SUITE_REGISTRATION( TestAsterixCAT244Decoding );

int main( int argc, char **argv ){
   //LogManager logger = LogManager( "TestAsterix" );
   //logger.addLogger( std::move( std::make_unique<Termlog>( "TestAsterix", LoggerBase::LOG_LEVEL::DEBUG ) ) );

   CppUnit::TestResult controller;

   CppUnit::TestResultCollector result;
   controller.addListener( &result );
   ;

   std::ofstream xmlout( "../Results/testresult_asterix_standalone.xml" );
   CppUnit::XmlOutputter xmlOutputter( &result, xmlout );
   CppUnit::TextOutputter consoleOutputter( &result, std::cout );

   //Setup the test cases
   CppUnit::TextUi::TestRunner runner;

   //Add test cases to test runner
   CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
   runner.addTest( registry.makeTest() );

   //Run all test cases
   runner.run( controller, "" );
   xmlOutputter.write();
   consoleOutputter.write();

   exit( 0 );
}
