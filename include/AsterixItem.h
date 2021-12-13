/**
 * @file AsterixItem.h
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
 * Base class representing one single Asterix item. This class also holds the name and length of
 * the item. Only the read functions need overriding by the derived classes.
 */

#ifndef ASTERIXITEM_H_
#define ASTERIXITEM_H_

//general includes
#include <string>
#include <deque>

class AsterixItem {
private:

protected:
   //Full name of the item
   std::string name;

   //Length of the item in bytes. Sometimes the length is not known from the beginning but it will
   // become clear while reading the item
   int length;

public:
   /**
    * Initialise the new Asterix item object with the given name
    *
    * @param name The name of the Asterix item
    * @return None
    * @throw None
    */
   AsterixItem( std::string name );
   virtual ~AsterixItem();

   /**
    * Read length bytes from the given input buffer. The content will not be saved inside this object.
    *
    * @param buffer The input buffer from which to read
    * @return The read bytes stored in a double ended queue
    * @throw None
    */
   virtual std::deque<char> readItem( std::deque<char>& buffer );

   /**
    * @param None
    * @return Name of the Asterix item
    * @throw None
    */
   std::string getName();

   /*
    * @param None
    * @return the length of this item
    * @throw None
    */
   int getItemLength();
};

#endif /* ASTERIXITEM_H_ */
