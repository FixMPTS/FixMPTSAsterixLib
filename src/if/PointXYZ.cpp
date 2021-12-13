/**
 * @file PointXYZ.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 9 Apr 2021
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
 * See .h file for more information
 */
#include "PointXYZ.h"

#include <limits>

PointXYZ::PointXYZ()
{
   x = std::numeric_limits<double>::quiet_NaN();
   y = std::numeric_limits<double>::quiet_NaN();
   z = std::numeric_limits<double>::quiet_NaN();
}

PointXYZ::~PointXYZ() {
}

PointXYZ::PointXYZ(double x, double y, double z) {
   this->x = x;
   this->y = y;
   this->z = z;
}

bool PointXYZ::operator ==(PointXYZ &other) {
   return x == other.x && y == other.y && z == other.z;
}

void PointXYZ::setX(double x) {
   this->x = x;
}

void PointXYZ::setY(double y) {
   this->y = y;
}

void PointXYZ::setZ(double z) {
   this->z = z;
}

double PointXYZ::getX() {
   return x;
}

double PointXYZ::getY() {
   return y;
}

double PointXYZ::getZ() {
   return z;
}
