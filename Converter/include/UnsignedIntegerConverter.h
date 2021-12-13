/**
 * @file UnsignedIntegerConverter.h
 * @author  Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 2 Feb 2018
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
 * Class holding the Asterix unsigned integer converter. The conversion if from/to a raw Asterix
 * value which has to be interpreted as unsigned integer.
 *
 * NOTE! All names indication a size in bit (e.g. fraction10Bit ) have no bit constrained at the
 * input or output, but rather indicate that 2 to the power of X, in this case 10, will be used
 * for the conversion. The above example will result in the following conversion
 *
 * ' value / 2**10'
 *
 */

#ifndef UNSIGNEDINTEGERCONVERTER_H_
#define UNSIGNEDINTEGERCONVERTER_H_

class UnsignedIntegerConverter {
public:
   UnsignedIntegerConverter();
   virtual ~UnsignedIntegerConverter();
};

#endif /* UNSIGNEDINTEGERCONVERTER_H_ */
