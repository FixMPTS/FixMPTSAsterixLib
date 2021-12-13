/**
 * @file Constants.h
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
 * This file provides some constants need by the core part of the software. Not all of the are needed
 * any time but the provide some useful default values is not provided otherwise.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>
#include <string>
#include <stdlib.h>


// Config base directory
const std::string CONFIG_BASE = "/home/felix/Projects/FixMPTS/config/";

// Default path and name for the kernel main configuration file
const std::string KERNEL_CONFIG = "/home/felix/Projects/FixMPTS/config/kernel_config.xml";
const std::string KERNEL_CONFIG_DEF = "/home/felix/Projects/FixMPTS/config/kernel_config.xsd";

// Default path and name for the module loader configuration file
const std::string MODULE_TREE = "/home/felix/Projects/FixMPTS/config/module_loader_modules.xml";

// Default path and name for the module loader configuration file
const std::string MLOADER_CONFIG = "/home/felix/Projects/FixMPTS/config/module_loader_config.xml";

// Default path and name for the module loader configuration file
const std::string CHAINER_CONFIG = "/home/felix/Projects/FixMPTS/config/input_chainer_config.xml";

//
const std::string CHAINER_MODULES = "/home/felix/Projects/FixMPTS/config/chainer_modules.xml";

//
const std::string SENSOR_CONFIG =
   "/home/felix/Projects/FixMPTS/config/input_data/input_sensors.xml";

//
const std::string SENSOR_CONFIG_DEF =
   "/home/felix/Projects/FixMPTS/config/input_data/input_sensors.xsd";

//
const std::string ASSOC_CONFIG =
   "/home/felix/Projects/FixMPTS/config/association/association_config.xml";

//
const std::string ASSOC_CONFIG_DEF =
   "/home/felix/Projects/FixMPTS/config/association/association_config.xsd";

//
const std::string DISTRIBUTION_CONFIG =
   "/home/felix/Projects/FixMPTS/config/distribution/distribution_config.xml";

//
const std::string DISTRIBUTION_CONFIG_DEF =
   "/home/felix/Projects/FixMPTS/config/distribution/distribution_config.xsd";

//
const std::string DISTRIBUTION_SERVICE_CONFIG_DEF =
   "/home/felix/Projects/FixMPTS/config/distribution/services/service_type.xsd";

//
const std::string MONITORING_CONFIG =
   "/home/felix/Projects/FixMPTS/config/monitoring/monitoring_config.xml";

//
const std::string MONITORING_CONFIG_DEF =
   "/home/felix/Projects/FixMPTS/config/monitoring/monitoring_config.xsd";

const std::string TRACK_MGNT_CONFIG =
   "/home/felix/Projects/FixMPTS/config/tracking/track_maintenance_config.xml";

const std::string TRACK_MGNT_SCHEMA =
   "/home/felix/Projects/FixMPTS/config/tracking/track_maintenance_config.xsd";
const std::string TRACK_INIT_SCHEMA =
   "/home/felix/Projects/FixMPTS/config/tracking/initiator_config.xsd";
const std::string TRACK_CONT_SCHEMA =
   "/home/felix/Projects/FixMPTS/config/tracking/continuator_config.xsd";
//
const int MAX_AST_BLOCK_BUFFER_SIZE = 1000; // 1KB

//
const unsigned int MAX_INVALID_ASTX_TOD_MS = 25 * 60 * 60 * 1000;
const unsigned int MIN_INVALID_ASTX_TOD_MS = 24.5 * 60 * 60 * 1000;

//
const unsigned MODULE_ID_LENGTH = 100;

//
const unsigned MAX_ADD_ITEM_LENGTH = 20;

//
const unsigned MAX_STAT_GEN_VALUE_LEN = 50;

#endif
