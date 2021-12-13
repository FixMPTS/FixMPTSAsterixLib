/**
 * @file TimeRelated.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 11 Aug 2015
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
 * Class to provide the means for time management. This includes proper handling of delta times.
 */
#ifndef TIMERELATED_H_
#define TIMERELATED_H_

//global includes
#include <chrono>

/**
 * Get the current time in ms.
 *
 * @param None
 * @return the time since epoche in ms
 * @throws Not yet decided
 */
inline uint64_t getCurrentTimeMS(){

   return std::chrono::duration_cast < std::chrono::milliseconds >
      ( std::chrono::system_clock::now().time_since_epoch() ).count();
}

/**
 * Get the current time in seconds.
 *
 * @param None
 * @return the time since epoche in seconds
 * @throws Not yet decided
 */
inline uint64_t getCurrentTimeS(){
   return getCurrentTimeMS() / 1000.0;
}

/**
 * Calculate the time in ms since midnight based on the given time stamp in ms.
 *
 * @param t the time stamp in ms since the start of the epoch
 * @return the ms passed since midnight to the given time stamp.
 * @throws Not yet decided but should throw error in case of negative time( time stamp was yesterday)
 */
inline unsigned int convertToTimeSinceMidnightMS( uint64_t t ){
   unsigned int return_time;

   // Need to calculate the elapsed times since last midnight
   time_t now = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
   tm *midnight = std::gmtime( &now );
   midnight->tm_hour = 0;
   midnight->tm_min = 0;
   midnight->tm_sec = 0;

   uint64_t d_time =
      std::chrono::duration_cast < std::chrono::milliseconds >
         ( std::chrono::system_clock::from_time_t( std::mktime( midnight ) ).time_since_epoch() ).count();

   return_time = t - d_time;
   return return_time;
}

/**
 * Convert the provided time of day in seconds to a UTC Unix time stamp
 *
 * @param tod the time of day in seconds
 * @return UTC time stamp
 * @throws No throw
 */
inline unsigned int convertTODtoUTC(uint64_t tod) {
   time_t now = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
   tm *midnight = std::gmtime( &now );
   midnight->tm_hour = 0;
   midnight->tm_min = 0;
   midnight->tm_sec = 0;

   uint64_t utc_time = std::chrono::duration_cast<std::chrono::seconds>
      ( std::chrono::system_clock::from_time_t( std::mktime( midnight ) + tod ).time_since_epoch() ).count();

   return utc_time;
}

#endif /* TIMERELATED_H_ */
