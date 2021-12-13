/**
 * @file AsterixItemCompound.h
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
 * Implementation of the compound Asterix item. The class provides the readItem method, which will read
 * all bytes from the input buffer that belong to this item. The input buffer will than be reduced
 * by the bytes read.
 */

#ifndef ASTERIXITEMCOMPOUND_H_
#define ASTERIXITEMCOMPOUND_H_

#include "AsterixItem.h"

#include <map>
#include <vector>
#include <string>
#include <memory>

class AsterixItemCompound: public AsterixItem {
public:
   typedef std::map<unsigned int, std::shared_ptr<AsterixItem>> subUap_T;
   typedef std::pair<unsigned int, std::shared_ptr<AsterixItem>> SubUAP_Item_T;

private:
   // List of all sub items with their FRN as key
   subUap_T subitem_uap;

   std::vector<bool> sub_fspec; // the pseudo fspec, no FX bit but known length

public:

   AsterixItemCompound( std::string name, subUap_T sub_uap );

   virtual ~AsterixItemCompound();

   /**
    * Read all bytes from the input buffer belonging to this item. The read bytes can than be
    * passed to the decoding procedure.
    *
    * @param buffer The input buffer to read from
    * @return a buffer containing only the bytes for this item.
    * @throw None
    */
   virtual std::deque<char> readItem(std::deque<char>& buffer) override;

   /**
    * Get the presence indication of all sub items. Key of the map is the item name.
    *
    * @return a mapping between the item FPSEC and the names of the sub item
    * @throws No throw
    */
   std::map<std::string, bool> getItemPresenceMap();

   /**
    * Determine if the item with the given name is present within the compound item.
    *
    * Qparam item_name the name of the item
    * @return true if the item is present according to the item FSPEC, false otherwise
    * @throws No throw
    */
   bool isPresent( std::string item_name );
};

#endif /* ASTERIXITEMCOMPOUND_H_ */
