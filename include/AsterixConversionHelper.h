/**
 * @file AsterixConversionHelper.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 28 Apr 2017
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
 * Helper class to provide a set of functions needed during Asterix De/Encoding to convert
 * units of measure.
 */
#ifndef ASTERIXCONVERSIONHELPER_H_
#define ASTERIXCONVERSIONHELPER_H_

class AsterixConversionHelper {
private:
   AsterixConversionHelper();

public:
   virtual ~AsterixConversionHelper();

   /**
    * Helper function to convert meters to feet.
    *
    * @param value the measurement in meters
    * @return the input value converted to feet
    * @throw No throw
    */
   static double metersToFeet( double value );

};

#endif /* ASTERIXCONVERSIONHELPER_H_ */
