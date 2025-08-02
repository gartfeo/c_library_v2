/** @file
 *  @brief MAVLink comm protocol generated from navlink.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_NAVLINK_H
#define MAVLINK_NAVLINK_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_NAVLINK.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#define MAVLINK_NAVLINK_XML_HASH -3997424583538313864

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{25002, 131, 8, 8, 0, 0, 0}, {25003, 158, 12, 12, 0, 0, 0}, {25104, 106, 76, 76, 0, 0, 0}, {25105, 38, 32, 32, 1, 30, 0}, {25106, 13, 16, 16, 1, 14, 0}, {25107, 194, 4, 4, 1, 2, 0}, {25108, 0, 15, 15, 0, 0, 0}, {25109, 214, 4, 4, 1, 2, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_NAVLINK

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_check_in.h"
#include "./mavlink_msg_check_out.h"
#include "./mavlink_msg_available_task_request.h"
#include "./mavlink_msg_available_task_response.h"
#include "./mavlink_msg_task_assign_request.h"
#include "./mavlink_msg_task_assign_response.h"
#include "./mavlink_msg_task_confirm_request.h"
#include "./mavlink_msg_task_confirm_response.h"

// base include



#if MAVLINK_NAVLINK_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_CHECK_IN, MAVLINK_MESSAGE_INFO_CHECK_OUT, MAVLINK_MESSAGE_INFO_AVAILABLE_TASK_REQUEST, MAVLINK_MESSAGE_INFO_AVAILABLE_TASK_RESPONSE, MAVLINK_MESSAGE_INFO_TASK_ASSIGN_REQUEST, MAVLINK_MESSAGE_INFO_TASK_ASSIGN_RESPONSE, MAVLINK_MESSAGE_INFO_TASK_CONFIRM_REQUEST, MAVLINK_MESSAGE_INFO_TASK_CONFIRM_RESPONSE}
# define MAVLINK_MESSAGE_NAMES {{ "AVAILABLE_TASK_REQUEST", 25104 }, { "AVAILABLE_TASK_RESPONSE", 25105 }, { "CHECK_IN", 25002 }, { "CHECK_OUT", 25003 }, { "TASK_ASSIGN_REQUEST", 25106 }, { "TASK_ASSIGN_RESPONSE", 25107 }, { "TASK_CONFIRM_REQUEST", 25108 }, { "TASK_CONFIRM_RESPONSE", 25109 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_NAVLINK_H
