/**
 * @file AsterixSubitemSigned.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 18 Oct 2017
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
 * Asterix sub item implementation where the item consists only of one signed integer value.
 */

#ifndef ASTERIXSUBITEMSIGNED_H_
#define ASTERIXSUBITEMSIGNED_H_

#include "AsterixSubitemNumber.h"

class AsterixSubitemSigned: public AsterixSubitemNumber {
public:
   AsterixSubitemSigned( int length,
      std::function<std::string( char*, unsigned int )> converterFunction );
   AsterixSubitemSigned( int length,
      std::function<std::string( char*, unsigned int, double& dest_buffer )> converterFunction );

   virtual ~AsterixSubitemSigned();

   virtual void decode( std::deque<char>& input_buffer, unsigned bit_position = 0 ) override;
};

#endif /* ASTERIXSUBITEMSIGNED_H_ */
