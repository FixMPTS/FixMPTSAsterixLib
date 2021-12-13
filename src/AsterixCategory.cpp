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
 * see .h file for more information
 */

//Asterix include
#include "AsterixCategory.h"
#include "AsterixItemRepetetive.h"
#include "AsterixItemCompoundLI.h"
#include "AsterixItemVariableLength.h"
#include "AsterixItemCompound.h"
#include "AsterixSubitemCompound.h"
#include "AsterixSubItemRep.h"

//general includes
#include <iostream>
#include <bitset>
#include <sstream>
#include <iomanip>

AsterixCategory::AsterixCategory() {
   uap = UAP_t();
   length = 0;
   cat = 0;
   subitems = subitems_list_t();
   unrolled_values = std::map<std::string, std::string>();
}

AsterixCategory::AsterixCategory( int cat ) :
   cat( cat ), length( 0 ), fspec( std::map<int, bool>() ),
      unrolled_values( std::map<std::string, std::string>() ) {
   uap = UAP_t();
   subitems = subitems_list_t();
}

AsterixCategory::AsterixCategory( int cat, int length ) :
   cat( cat ), length( length ), fspec( std::map<int, bool>() ),
      unrolled_values( std::map<std::string, std::string>() ) {
   uap = UAP_t();
   subitems = subitems_list_t();
}

AsterixCategory::AsterixCategory( int cat, int length, std::deque<char>& m_queue ) :
   cat( cat ), length( length ), fspec( std::map<int, bool>() ),
      unrolled_values( std::map<std::string, std::string>() ), message_queue( m_queue ) {
   uap = UAP_t();
   subitems = subitems_list_t();
}

AsterixCategory::AsterixCategory( const AsterixCategory& other_cat ) {
   uap = other_cat.uap;
   cat = other_cat.cat;
   subitems = other_cat.subitems;
   length = other_cat.length;

   fspec = other_cat.fspec;
   message_queue = other_cat.message_queue;
   unrolled_values = other_cat.unrolled_values;
}

AsterixCategory::~AsterixCategory() {
   uap.clear();

   for( auto& item : subitems ) {
      item.second.clear();
   }
   subitems.clear();

   unrolled_values.clear();

   message_queue.clear();
   fspec.clear();
}

void AsterixCategory::setLength( int l ) {
   length = l;
}
void AsterixCategory::setFpsec( std::map<int, bool> spec ) {
   fspec = spec;
}
void AsterixCategory::setUap( UAP_t u ) {
   uap = u;
}
void AsterixCategory::setMessage( char& message_buffer ) {
   //raw_message_buffer = &message_buffer;
   //message_queue =
   //   std::deque<char>( raw_message_buffer,
   //      raw_message_buffer+sizeof( raw_message_buffer )/sizeof(char) );
}

int AsterixCategory::getRemainingLength() {
   return message_queue.size();
}
int AsterixCategory::getCat() {
   return cat;
}

bool AsterixCategory::AsterixCategory::readFspec() {
   if( message_queue.empty() ) {
      return false;
   }

   bool fpsec_end = false;
   // read the first byte
   int frn = 0; // The frn of the message, which is the key for the fspec and item map

   while (!fpsec_end) {
      unsigned char fspec_byte = static_cast<unsigned char>( message_queue.front() );
      message_queue.pop_front();

      std::bitset<8> f_byte( fspec_byte );
      if( f_byte[0] == 0 ) { //FX bit not set
         fpsec_end = true;
      }

      //append fpsec to existing fspec definition
      for( unsigned int i = f_byte.size() - 1; i > 0; i-- ) { //Respect the endianes
         //FRN counting starts at 1
         fspec.insert( std::pair<int, bool>( frn + 1, f_byte[i] == 1 ? true : false ) );
         frn++;
      }
   }

   return true;
}

void AsterixCategory::fillRecord(std::shared_ptr<ReportRecordType> record) {
}

void AsterixCategory::decode() {
   if( message_queue.empty() ) { // Nothing to do decode it seems no message has been read.
      return;
   }

   //fill the unrolled values map with all items and their value in string representation
   for( auto& uap_it : uap ) {
      std::shared_ptr<AsterixItem> uap_item = uap_it.second;
      int current_frn = uap_it.first;

      //check if the item is present
      if( !fspec[current_frn] ) {
         continue;
      }
      std::deque<char> item_content = uap_item->readItem( message_queue );
      unsigned int original_size_bytes = item_content.size();
      try {

         subitem_map_t sub_item_list = subitems.at( current_frn );
         // In case the item is a repetitive item, duplicate the subitem_list according to the repetition factor
         // Also add the index to the name in order to keep them unique
         if( std::dynamic_pointer_cast<AsterixItemRepetetive>( uap_item ) != nullptr ) {
            subitem_map_t original_list = sub_item_list;
            sub_item_list.clear();
            for( unsigned int i = 0;
               i < std::dynamic_pointer_cast<AsterixItemRepetetive>( uap_item )->getRepetitionFactor(); i++ ) {
               for( auto item : original_list ) {
                  std::string new_name = item.first;
                  new_name += ".";
                  new_name += std::to_string( i );
                  subitem_t new_item( new_name, item.second );
                  sub_item_list.push_back( new_item );
               }
            }
         }

         // Keep track of bits encoded so far and stop if length of item is reached
         unsigned number_encoded_bits = 0;
         for( auto sub_item_it : sub_item_list ) {
            std::string sub_item_name = sub_item_it.first;
            std::shared_ptr<AsterixSubitemBase> sub_item = sub_item_it.second;
            number_encoded_bits += (unsigned) sub_item->getLength();

            //
            if( std::dynamic_pointer_cast<AsterixItemCompound>( uap_item ) != nullptr
               || std::dynamic_pointer_cast<AsterixItemCompoundLI>( uap_item ) != nullptr ) {
               // Check if item is present

               if( std::dynamic_pointer_cast<AsterixItemCompound>( uap_item )->isPresent( sub_item_name ) ) {
                  // Stop reading if all bytes of this item have been read. Thus the sub item encoding
                  // does not need to care about the encoding of the complete item
                  if( isEncodingFinished( number_encoded_bits, original_size_bytes,
                     item_content.size() ) ) {
                     break;
                  }

                  sub_item->decode( item_content,
                     (number_encoded_bits - (unsigned) sub_item->getLength()) );

                  // Store the decoded values for all items present in the message
                  if( std::dynamic_pointer_cast<AsterixSubitemCompound>( sub_item ) != nullptr ) {
                     for( auto value_key : std::dynamic_pointer_cast<AsterixSubitemCompound>( sub_item )->gerUnrolledValues() ) {
                        unrolled_values[value_key.first] = value_key.second;
                     }
                  } else if( std::dynamic_pointer_cast<AsterixSubItemRep>( sub_item ) != nullptr ) {
                     for( auto value_key : std::dynamic_pointer_cast<AsterixSubItemRep>( sub_item )->gerUnrolledValues() ) {
                        unrolled_values[value_key.first] = value_key.second;
                     }
                  } else {
                     // No further sub item available for this compound sub item
                     unrolled_values[sub_item_name] = sub_item->getValue();
                  }
               } else {
                  // Remove bits not encode from total encoded number of bits again
                  number_encoded_bits -= (unsigned) sub_item->getLength();
               }
            } else if( std::dynamic_pointer_cast<AsterixItemRepetetive>( uap_item ) != nullptr
               && sub_item_name == sub_item_list.begin()->first ) {
               if( isEncodingFinished( number_encoded_bits, original_size_bytes,
                  item_content.size() ) ) {
                  break;
               }

               // Remove the repetition factor before decoding the item
               item_content.pop_front();
               sub_item->decode( item_content,
                  (number_encoded_bits - (unsigned) sub_item->getLength()) );

               // Store the decoded value
               unrolled_values[sub_item_name] = sub_item->getValue();
            } else if( std::dynamic_pointer_cast<AsterixItemVariableLength>( uap_item ) != nullptr ) {
               // If only one bit is left and the next item is only of size one bit, discard the
               // item. This is due to the removed FX bit, which will still occupy the last position
               // in the last byte
               bool one_bit_left = (number_encoded_bits - (original_size_bytes * 8.0)) == 0;
               if( isEncodingFinished( number_encoded_bits, original_size_bytes,
                  item_content.size() )
                  || (one_bit_left && sub_item->getLength() == 1) ) {
                  break;
               }
               sub_item->decode( item_content,
                  (number_encoded_bits - (unsigned) sub_item->getLength()) );

               // Store the decoded value
               unrolled_values[sub_item_name] = sub_item->getValue();

            } else {
               if( isEncodingFinished( number_encoded_bits, original_size_bytes,
                  item_content.size() ) ) {
                  break;
               }
               sub_item->decode( item_content,
                  (number_encoded_bits - (unsigned) sub_item->getLength()) );

               // Store the decoded value
               unrolled_values[sub_item_name] = sub_item->getValue();
            }
         }
      } catch (std::out_of_range &e) { // No sub item definition for the uap entry
      }
   }
}

void AsterixCategory::printMessage(bool skip_spare) {
   //iterate over all items and print them
   if( unrolled_values.empty() ) {
      std::cout << "No items have been decoded so far .... " << std::endl;
      return;
   }

   std::cout << "****************** Message of CAT " << cat << " ****************** \n FSPEC:\n"
      << getFspecString() << "\nMESSAGE:" << std::endl;
   for( auto value_it = unrolled_values.begin(); value_it != unrolled_values.end(); ++value_it ) {
      std::string item_name = value_it->first;

      if( skip_spare && item_name.find( "SPARE" ) != item_name.npos ) {
         continue;
      }

      std::string item_value = value_it->second;
      int tabs = std::count( item_name.begin(), item_name.end(), '#' );
      std::stringstream sstream;
      //Fill the string with leading 0
      sstream << "" << std::setfill( '\t' ) << std::setw( tabs ) << item_name << std::setfill( ' ' )
         << std::setw( 40 - item_name.length() ) << item_value;
      std::cout << sstream.str() << std::endl;
   }
   std::cout << std::endl;
}

bool AsterixCategory::isEncodingFinished( unsigned int number_encoded_bits,
   unsigned int item_size_bytes, unsigned int buffer_size ) {
   bool return_value = false;

   if( (number_encoded_bits / 8.0) > item_size_bytes ) {
      return_value = true;
   }

   if( buffer_size <= 0 ) {
      return_value = true; //no more content for the remaining sub items
   }
   return return_value;
}

void AsterixCategory::initCategory() {
   setUAP();
   setSubitems();

   readFspec();
   decode();
}

std::string AsterixCategory::getValue( std::string name ) {
   //if( unrolled_values.find( name ) == unrolled_values.end() ) {
   //   std::cerr << "Item " << name << " not part of the message " << std::endl;
   //}
   return unrolled_values.at( name );
}

bool AsterixCategory::isItemPresent( std::string item_name ) {
   return (unrolled_values.find( item_name ) != unrolled_values.end());
}

std::string AsterixCategory::getFspecString() {
   std::string return_string;
   for( auto it = fspec.begin(); it != fspec.end(); ++it )
      return_string.append( it->second ? "1" : "0" );
   return return_string;
}

void AsterixCategory::getHeader( std::vector<unsigned char>& header, unsigned length ) {
   //
   std::vector<unsigned char> tmp_header;
   // Add the FSPEC
   unsigned partial_fspec = 0;

   // Unfortunately this is the only way with the hard coded number because of the container design
   std::bitset<36> current_fspec( getFspecString() );

   // Copy all set bit into the tmp fspec in order to modify it
   for( unsigned b = 0; b < fspec.size(); b++ ) {
      current_fspec[b] = fspec[b];
   }

   for( unsigned bit = 0; bit < current_fspec.size(); bit++ ) {

      bool current_fspec_bit_backup = current_fspec[bit];
      // Shift current fspec bit by one
      if( bit % 7 != 0 ) {
         partial_fspec = partial_fspec << 1;
      }

      if( current_fspec[bit] ) {
         partial_fspec += 1;

         // reset the bit
         current_fspec[bit] = false;
      }

      // each fspec has space for seven bits plus one FX bit
      if( bit % 7 == 0 && bit > 0 ) {
         // In case of an FX bit we need to remove the curent item and add it to the new fpsec byte
         partial_fspec -= current_fspec_bit_backup;
         partial_fspec = partial_fspec << 1; // make space for the FX bit

         // Set the FX if there are one's left in the bit set
         if( current_fspec.any() || current_fspec_bit_backup ) {
            partial_fspec += 1;
         }

         // add the fspec bit to the header
         tmp_header.push_back( partial_fspec );

         // reset to start with the next fspec byte
         partial_fspec = current_fspec_bit_backup;

         //If either several bits set to one or if the current bit is set
         if( !current_fspec.any() && !current_fspec_bit_backup ) {
            break;
         }
      }
   }

   int msg_length = length + tmp_header.size() + 3;

   // Add Category, length and FSPEC to the message
   // One byte for the category
   header.push_back( cat );

   // Two bytes for the length, including the header
   header.push_back( (msg_length >> 8) & 0xff );
   header.push_back( msg_length & 0xff );

   // add the fspec
   header.insert( header.end(), tmp_header.begin(), tmp_header.end() );
}
