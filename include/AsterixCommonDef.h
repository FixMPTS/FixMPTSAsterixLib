/**
 * @file AsterixCommonDef.h
 * @author Felix Kreuter <felix@fixmpts.org>
 * @version 1.0
 * Created on: 27 Jul 2017
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
 * File containing Asterix related definitions.
 */
#ifndef ASTERIXCOMMONDEF_H_
#define ASTERIXCOMMONDEF_H_

#include <vector>
#include <unordered_map>
#include <string>
#include <memory>

// Lib related includes
#include "AsterixSubitemBase.h"

// Type Definitions
typedef std::pair<std::string, std::shared_ptr<AsterixSubitemBase>> subitem_t;
typedef std::vector<subitem_t> subitem_map_t;
typedef std::unordered_map<int, subitem_map_t> subitems_list_t;
typedef std::pair<int, subitem_map_t> subitem_map_item_t;


#endif /* ASTERIXCOMMONDEF_H_ */
