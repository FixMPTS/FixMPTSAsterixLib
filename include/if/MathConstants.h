/**
 * @file MathConstants.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 21 Jun 2015
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
 * This header provides just some basic constants and conversion factors needed with airspace related
 * tracking.
 */
#ifndef MATHCONSTANTS_H_
#define MATHCONSTANTS_H_

//global inlcudes
#include <math.h>

//Conversion factor from degrees to radiant
double const DEG_TO_RAD_FACTOR = M_PI/180.0;

double const NM_TO_KM_FACTOR = 1.852;
double const NM_TO_METER_FACTOR = NM_TO_KM_FACTOR*1000.0;
double const KT_TO_MS_FACTOR = NM_TO_KM_FACTOR/3.6;

double const FEET_TO_METER_FACTOR = 1.0/3.2808;

int const EARTH_RADIUS_METER = 6367454;

#endif /* MATHCONSTANTS_H_ */
