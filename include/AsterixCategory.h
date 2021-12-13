/**
 * @file AsterixCategory.cpp
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
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
 * Base class for all Asterix categories. All common code for reading and understanding the Asterix
 * record is contained in this class. The main purpose for the derived classes will be the provision
 * of the UAP and sub item definitions.
 */

#ifndef ASTERIXCATEGORY_H_
#define ASTERIXCATEGORY_H_

//Asterix includes
#include "AsterixItem.h"
#include "AsterixCommonDef.h"

// Data types include
#include "TrackTypeIf.h"
#include "ReportRecordType.h"

// global includes
#include <string>
#include <map>
#include <deque>

class AsterixCategory {
private:
   /**
    * Check if there are enough data left for the item or if not all data required for the item has
    * been processed so far.
    *
    * @param number_encoded_bits number of bits so far processed for the item
    * @param item_size_bytes total size of the item in bytes
    * @param buffer_size number of bytes currently available in the buffer
    * @return true if no more data has to be decoded, false otherwise
    */
   bool isEncodingFinished( unsigned int number_encoded_bits, unsigned int item_size_bytes,
      unsigned int buffer_size );

protected:
   //Asterix category of the message
   int cat;

   //Length of this message in bytes message
   int length;

   //Representation of the FSPEC of the Asterix block
   std::map<int, bool> fspec;

   //Because of the important order in the UAP we need to define the comparator for independence
   struct cmpByFRN {
      bool operator()( const int a, const int b ) const{
         return a < b;
      }
   };

   //Representation of the specific UAP. Will be defined in the derived classes
   typedef std::map<unsigned int, std::shared_ptr<AsterixItem>, cmpByFRN> UAP_t;
   typedef std::pair<unsigned int, std::shared_ptr<AsterixItem>> UAP_Item_T;
   UAP_t uap;

   subitems_list_t subitems;

   //Map containing the values of all (sub)items contained in the message.
   std::map<std::string, std::string> unrolled_values;

   //not decoded message as it was received
   //char raw_message_buffer;   //Uncomment if need arises for the raw message

   //For better accessibility of the bytes
   std::deque<char> message_queue;

   // Should not be called directly, thus declared as private
   AsterixCategory();

   /**
    * Initiate the category by setting up every information required for the de/en-encoding process.
    *
    * @throws Not yet decided
    */
   void initCategory();

   /**
    * Initiate the UAP representing a single Asterix message. This defines the mapping
    * between the binary data and the information contained within the message.
    *
    * @throws Not yet decided
    */
   virtual void setUAP() = 0;

   /**
    * Setup the detailed definition of all individual Asterix items.
    *
    * @throws Not yet decided
    */
   virtual void setSubitems() = 0;

   /**
    * Encoding of the  header for this message. This consists of the following items to be properly
    * encode.
    *
    * 1. The correct Asterix category.
    * 2. The length of the message including the header.
    * 3. Encoding of the FSPEC
    *
    * @param the list to store the encoded header in
    * @param length the length of the message without the header
    * @throws Not yet decided
    */
   void getHeader( std::vector<unsigned char>& header, unsigned length );

public:
   /**
    * The Asterix category object is initialised with an empty UAP and sub item list and without
    * any content to be decoded. This has to be provided with the corresponding setter methods,
    * before the message can actually be decoded.
    *
    * @param cat category of the message to be decoded
    * @return None
    * @throw None
    */
   AsterixCategory( int cat );
   /**
    * Initialise the new Asterix category object by only providing the category and the length of the
    * message buffer, which has to be provided with the corresponding setter method. Also the UAP and
    * sub item lists must be provided by the derived class, in order to be able to actually decode the
    * message.
    *
    * @param cat category of the message
    * @param length length of the Asterix block
    * @return None
    * @throw None
    */
   AsterixCategory( int cat, int length );

   /**
    * Initialise the Asterix category object directly with the correct category and content. This
    * content can directly be used for decoding.
    *
    * @param cat category of the message
    * @param length length of the Asterix block
    * @param buffer the input buffer as byte array in the form is is read from the input socket
    * @return None
    * @throw None
    */
   AsterixCategory( int cat, int length, std::deque<char>& m_queue );
   AsterixCategory( const AsterixCategory& other_cat );

   virtual ~AsterixCategory();

   //SET
   void setLength( int l );
   void setFpsec( std::map<int, bool> spec );
   void setUap( UAP_t u );
   void setMessage( char& message_buffer );

   //GET
   /*After calling decode this length contains the remaining length of the input message.
    *These are all bytes not needed by the current message. If this function is called before the
    *call to decode, the length matches the length of the input buffer.
    */
   int getRemainingLength();
   int getCat();

   /**
    * Read the fspec from the message buffer, The buffer must already be stored inside the object.
    *
    * @param None
    * @return None
    * @throws None
    */
   bool readFspec();

   /**
    * Fill the given record with the decoded content of the message. Since it is necessary
    * at this point to understand the semantic of the message, this can not be done in the base
    * class and therefore this method is declared abstract and need to be overwritten in every
    * derived class.
    *
    * @param record The record which needs to be filled with the decoded content.
    * @return None
    * @throw None
    */
   virtual void fillRecord(std::shared_ptr<ReportRecordType> record);

   /**
    * Print the decoded message in human readable format.
    *
    * @param skip_spare if set to true to not print items where the name contains SPARE. If set to false, print all
    * @return None
    * @throw None
    */
   void printMessage(bool skip_spare = true);

   /**
    * Decode the Asterix Block. Reading all items marked as present by the fspec. For every item for which
    * a sub item is defined, the decoding of this sub item will be called. The decoded result is stored
    * as string in the unrolled_values map.
    *
    * @param None
    * @return None
    * @throws out_of_range which is caught inside this function
    */
   void decode();

   /**
    * Takes the given key and returns the string representation of the decoded value. If the key could
    * not be found, an exception is raise.
    *
    * @param None
    * @return Value for the given item name
    * @throw std::out_of_range if the key is not present
    */
   std::string getValue( std::string name );

   /**
    * Check if the item in question was contained in the message.
    *
    * @param item_name the name of the item to look for
    * @return true if the item is present, false otherwise
    * @throws None
    */
   bool isItemPresent( std::string item_name );

   /**
    * Return a string representing the fspec. The string is in binary representation.
    *
    * Note: The FX Bits are removed already.
    *
    * @param None
    * @return binary representation of the fspec
    * @throws None
    */
   std::string getFspecString();
};

#endif /* ASTERIXCATEGORY_H_ */
