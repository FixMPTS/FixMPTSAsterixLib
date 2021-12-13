/**
 * @file AsterixEncodingHelper.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 5 Apr 2016
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
 * Helper class providing a set of generic procedures required during the encoding of Asterix
 * messages, shared between different Asterix categories.
 */
#ifndef ASTERIXENCODINGHELPER_H_
#define ASTERIXENCODINGHELPER_H_

// project includes
#include "TrackTypeIf.h"
#include "TrackDetectionAges.h"

// general includes
#include <vector>
#include <memory>

class AsterixEncodingHelper {
private:
   /**
    * Encode the given age in seconds into one byte with a LSB of 1/4 seconds. This means in case
    * the given age is above 63.75 seconds it will be limited to 63.75 seconds.
    *
    * @param msg the message to append the encoded age to
    * @param age the to be encoded age in seconds
    * @return true of the encoding was successful and false otherwise
    * @throws Not yet decided
    */
   static bool encode8BitAgeItem( std::vector<unsigned char>& msg, double age );

public:
   /**
    * Encode the given SAC and SIC into a 2 byte field. Each items will use up one byte
    *
    * @param sac the SAC to be encoded
    * @param sic the SIC to be encoded
    * @return a two byte representation of the given SAC/SIC values
    * @throws NOt yet decided
    */
   static std::vector<unsigned char> encodeSACSIC16Bit( unsigned sac, unsigned sic );

   /**
    * Encode the given track number into a one byte data field
    *
    * @param number the track number to be encoded
    * @return the given track number encoded in two bytes
    * @throws Not yet decided
    */
   static std::vector<unsigned char> encodeTrackNumber16Bit( unsigned number );

   /**
    * Encode the given mode 3A code and corresponding flags into a two byte data item.
    *
    * @param code the mode 3A code to be encoded
    * @param valid flag indicating whether the code is valid or not
    * @param garbled the flag indicating a garbled mode 3A code
    * @return the two byte data item encoded as specified in the CAT 62 specification
    * @throws Not yet decided
    */
   static std::vector<unsigned char> encodeTrackMode3A( unsigned code, bool valid, bool garbled );

   /**
    * Encode the given time into a three byte data item. The given time is to be expected in ms and
    * will be split into 128 parts of a second as required by the Asterix CAt 62 standard.
    *
    * @param the time in ms to be encoded in 1/128 second intervals.
    */
   static std::vector<unsigned char> encodeTimeOfTrackInfo24Bit( uint64_t time_in_ms );

   /**
    * Use the given track and related given values to encode the track status into a five byte long
    * extensible data item. The FX bit will be taken care of.
    *
    * @param track the track on which the status will be based
    * @param service_track_confirmation_weight this parameter decided whether the state will be set
    * to tentative or confirmed track.
    * @param max_ages the configured maximum ages per detection technology.
    * @param track_live indication which of the track lofe states have to be encoded
    * @return byte vector containing the encoded message
    * @throws Not yet decided
    */
   static std::vector<unsigned char> encodeTrackStatus(std::shared_ptr<TrackTypeIf> track,
      double service_track_confirmation_weight, std::shared_ptr<TrackMaxDetectionAgeMapping> max_ages,
      std::map<std::string, bool> track_live);

   /**
    * Encode the track 2D WGS84 position into a 8 Byte data item. The LSB used is 180`/2**25.
    *
    * @param track the track which position is encoded
    * @return the WGS position as 32 but byte array
    * @throws NOt yet decided
    */
   static std::vector<unsigned char> encodePositionWG(std::shared_ptr<TrackTypeIf> track);

   /**
    * Encode the given WGS position into a eight byte array. The LAS in use is 180./2¬25.
    *
    * @param latitude the position to be encoded
    * @param longitude the position to be encoded
    * @return the encoded byte stream
    * @throws NOt yet decided
    */
   static std::vector<unsigned char> encodePositionWGS8Byte( double latitude, double longitude );
   static std::vector<unsigned char> encodePositionWGS6Byte( double latitude, double longitude );

   /**
    * Encode the WGS 84 calculated geometric altitude into a 16 bit byte array. The LSB in use is 6.25ft
    *
    * @param track the track to encode the item from
    * @return the 16 bit representation of the altitude
    * @throws Not yet decided
    */
   static std::vector<unsigned char> encodeGeoAltitude(std::shared_ptr<TrackTypeIf> track);
   /**
    * Encode the given altitude in feet into a two byte byte stream with an LSB of 6.25 feet.
    *
    * @param the altitude in feet to be encoded
    * @return a two byte stream containing teh encoded altitude
    * @throws Not yet decided*
    */
   static std::vector<unsigned char> encodeGeoAltitude( double altitude );

   /**
    * Encode the track barometric altitude in FL into a 16 bit byte array. The LSB in use is 25ft.
    *
    * @param flight_level the flight level to encoded
    * @param qnh_corrected indicating whether this FL underwent a QNH correction. This will have an
    * effect onto bit 16 of the encoded byte array, A value of -1 indicates this bit is used for the
    * flight level instead. A value of 0 indicates no QNH correction and a value of 1 indicates the QNH
    * correction.
    * @return the encoded barometric altitude
    * @throws Not yet decided
    */
   static std::vector<unsigned char> encodeBaroAltitude( double flight_level,
      int qnh_corrected = 0 );

   /**
    * Encode the rate of Climb/Descent with an LSB of 6.25 feet/minute into a two byte array
    *
    * @param rate the rate in m/s to be encoded
    * @return the encoded rate in ft/s with the correct LSB
    * @throws Not yet decided
    */
   static std::vector<unsigned char> encodeRateCD( double rate );

   /**
    * Encode the mode of movement of all three directions into a one byte data item.
    *
    * @param track the track to encode the MOFs from
    * @return the encoded mode of movement as specified in CAT 62 item 200
    * @throws Not yet decided
    */
   static std::vector<unsigned char> encodeMOF8Bit(std::shared_ptr<TrackTypeIf> track);

   /**
    * Convert the given string of at most eight characters into a six bit per character byte array.
    * Please refer to section 3.1.2.9 of ICAO Document 4444.
    *
    * @param t_id the target id as string representation
    * @return the six bit per character encoded byte array of the call sign
    * @throws Not yet decided
    */
   static std::vector<char> encodeTargetID( std::string t_id );

   /**
    * Encode the track update and detection ages into a compound Asterix item
    *
    * @param track the track to get the ages from
    * expected that the key of the age items starts with
    */
   static std::vector<unsigned char> encodeSystemTrackAges(std::shared_ptr<TrackTypeIf> track);

   /**
    * Helper function to encode the track data age item.
    *
    * @param track the track from which the items are taken
    * @return the encoded track data ages
    * @throws Not yet decided
    */
   static std::vector<unsigned char> encodeTrackDataAges(std::shared_ptr<TrackTypeIf> track);

   /**
    * Encoding of the measured item. The complete item, as required for CAT 62 is encoded. This
    * includes the sub item FSPEC.
    *
    * @param track teh track from which the items are taken
    * @return the encoded bytes containing the sub item
    * @throws Not yet decided
    */
   static std::vector<unsigned char> encodeMeasuredItems(std::shared_ptr<TrackTypeIf> track);

   /**
    * Take the aircraft derived data from the track and encode it like it is required for
    * CAT 62.
    *
    * @param track the track structure to retrieve the aircraft derived data from
    * @return the encoded bytes including teh sub-item FSPEC
    * @throws Not yet decided
    */
   static std::vector<unsigned char> eoncodeAircraftDerivedData(std::shared_ptr<TrackTypeIf> track);
};

#endif /* ASTERIXENCODINGHELPER_H_ */
