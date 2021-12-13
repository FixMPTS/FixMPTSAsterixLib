/**
 * @file Cat065ItemNames.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 24 Nov 2021
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
 * List of all Asterix Category 065 item names and item sub names
 */
#ifndef CAT065ITEMNAMES_H_
#define CAT065ITEMNAMES_H_

#include <string>

class Cat065ItemNames {
public:
   inline static const std::string I065_010 = "I065/010";
   inline static const std::string I065_010_SAC = "I065/010#SAC";
   inline static const std::string I065_010_SIC = "I065/010#SIC";
   inline static const std::string I065_000 = "I065/000";
   inline static const std::string I065_000_TYP = "I065/000#TYP";
   inline static const std::string I065_015 = "I065/015";
   inline static const std::string I065_015_SID = "I065/015#SID";
   inline static const std::string I065_030 = "I065/030";
   inline static const std::string I065_030_TOD = "I065/030#TOD";
   inline static const std::string I065_020 = "I065/020";
   inline static const std::string I065_020_BTN = "I065/020#BTN";
   inline static const std::string I065_040 = "I065/040";
   inline static const std::string I065_040_NOGO = "I065/040#NOGO";
   inline static const std::string I065_040_OVL = "I065/040#OVL";
   inline static const std::string I065_040_TSV = "I065/040#TSV";
   inline static const std::string I065_040_PSS = "I065/040#PSS";
   inline static const std::string I065_040_STTN = "I065/040#STTN";
   inline static const std::string I065_040_SPARE = "I065/040#SPARE";
   inline static const std::string I065_050 = "I065/050";
   inline static const std::string I065_050_REPORT = "I065/050#REPORT";
   inline static const std::string I065_RE = "I065/RE";
   inline static const std::string I065_RE_SRP = "I065/RE#SRP";
   inline static const std::string I065_RE_ARL = "I065/RE#ARL";
   inline static const std::string I065_RE_SRP_LAT = "I065/RE#SRP#LAT";
   inline static const std::string I065_RE_SRP_LNG = "I065/RE#SRP#LNG";
};

#endif /* CAT065ITEMNAMES_H_ */
