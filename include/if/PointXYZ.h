/**
 * @file PointXYZ.h
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
 * Helper class providing the means to store and distribut positional information of 3D measurements
 */
#ifndef POINTXYZ_H_
#define POINTXYZ_H_

class PointXYZ {
private:
   double x;
   double y;
   double z;

public:
   PointXYZ();
   PointXYZ(double x, double y, double z);
   virtual ~PointXYZ();

   bool operator==(PointXYZ &other);

   // Get and Set
   void setX(double x);
   void setY(double y);
   void setZ(double z);

   double getX();
   double getY();
   double getZ();
};

#endif /* POINTXYZ_H_ */