/**
 * @file AsterixStdDefinitions.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 17 Nov 2017
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
 * Common definitions shared between Asterix related classes.
 */

#ifndef ASTERIXSTDDEFINITIONS_H_
#define ASTERIXSTDDEFINITIONS_H_

#include <map>
#include <string>

/**
 * This map defines the translation between the six bit number and its corresponding character
 */
const std::map<unsigned int, std::string> AIRCRAFT_ID_CHAR_MAP = { { 1, "A" },
   { 2, "B" }, { 3, "C" }, { 4, "D" }, { 5, "E" }, { 6, "F" }, { 7, "G" }, { 8, "H" }, { 9, "I" }, {
      10, "J" }, { 11, "K" }, { 12, "L" }, { 13, "M" }, { 14, "N" }, { 15, "O" }, { 16, "P" }, { 17,
      "Q" }, { 18, "R" }, { 19, "S" }, { 20, "T" }, { 21, "U" }, { 22, "V" }, { 23, "W" },
   { 24, "X" }, { 25, "Y" }, { 26, "Z" }, { 32, " " }, { 48, "0" }, { 49, "1" }, { 50, "2" }, { 51,
      "3" }, { 52, "4" }, { 53, "5" }, { 54, "6" }, { 55, "7" }, { 56, "8" }, { 57, "9" } };


/**
 * The maps containing the five bit and three bit characters used for the NATO track id
 */
const std::map<unsigned int, std::string> NATO_ID_5BIT = { { 0, "0" }, { 1, "1" }, { 2, "2" }, { 3,
   "3" }, { 4, "4" }, { 5, "5" }, { 6, "6" }, { 7, "7" }, { 8, "A" }, { 9, "B" }, { 10, "C" }, { 11,
   "D" }, { 12, "E" }, { 13, "F" }, { 14, "G" }, { 15, "H" }, { 16, "J" }, { 17, "K" }, { 18, "L" },
   { 19, "M" }, { 20, "N" }, { 21, "P" }, { 22, "Q" }, { 23, "R" }, { 24, "S" }, { 25, "T" }, { 26,
      "U" }, { 27, "V" }, { 28, "W" }, { 29, "X" }, { 31, "Y" }, { 31, "Z" } };

const std::map<unsigned int, std::string> NATO_ID_3BIT = { { 0, "0" }, { 1, "1" }, { 2, "2" }, { 3,
   "3" }, { 4, "4" }, { 5, "5" }, { 6, "6" }, { 7, "7" } };
#endif /* ASTERIXSTDDEFINITIONS_H_ */
