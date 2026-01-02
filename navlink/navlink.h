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

#define MAVLINK_NAVLINK_XML_HASH -8185548260094157166

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{25002, 29, 20, 20, 0, 0, 0}, {25003, 83, 32, 32, 0, 0, 0}, {25004, 129, 21, 21, 0, 0, 0}, {25104, 41, 96, 96, 0, 0, 0}, {25105, 250, 52, 52, 1, 50, 0}, {25106, 210, 36, 36, 1, 34, 0}, {25107, 119, 24, 24, 1, 22, 0}, {25108, 164, 35, 35, 0, 0, 0}, {25109, 246, 24, 24, 1, 22, 0}, {25200, 202, 22, 22, 0, 0, 0}, {25201, 210, 22, 22, 0, 0, 0}, {25202, 195, 26, 26, 0, 0, 0}, {25300, 236, 25, 25, 0, 0, 0}}
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
#include "./mavlink_msg_swarm_heartbeat.h"
#include "./mavlink_msg_available_task_request.h"
#include "./mavlink_msg_available_task_response.h"
#include "./mavlink_msg_task_assign_request.h"
#include "./mavlink_msg_task_assign_response.h"
#include "./mavlink_msg_task_confirm_request.h"
#include "./mavlink_msg_task_confirm_response.h"
#include "./mavlink_msg_slot_heartbeat.h"
#include "./mavlink_msg_slot_claim.h"
#include "./mavlink_msg_vote_phase.h"
#include "./mavlink_msg_search_status.h"

// base include



#if MAVLINK_NAVLINK_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_CHECK_IN, MAVLINK_MESSAGE_INFO_CHECK_OUT, MAVLINK_MESSAGE_INFO_SWARM_HEARTBEAT, MAVLINK_MESSAGE_INFO_AVAILABLE_TASK_REQUEST, MAVLINK_MESSAGE_INFO_AVAILABLE_TASK_RESPONSE, MAVLINK_MESSAGE_INFO_TASK_ASSIGN_REQUEST, MAVLINK_MESSAGE_INFO_TASK_ASSIGN_RESPONSE, MAVLINK_MESSAGE_INFO_TASK_CONFIRM_REQUEST, MAVLINK_MESSAGE_INFO_TASK_CONFIRM_RESPONSE, MAVLINK_MESSAGE_INFO_SLOT_HEARTBEAT, MAVLINK_MESSAGE_INFO_SLOT_CLAIM, MAVLINK_MESSAGE_INFO_VOTE_PHASE, MAVLINK_MESSAGE_INFO_SEARCH_STATUS}
# define MAVLINK_MESSAGE_NAMES {{ "AVAILABLE_TASK_REQUEST", 25104 }, { "AVAILABLE_TASK_RESPONSE", 25105 }, { "CHECK_IN", 25002 }, { "CHECK_OUT", 25003 }, { "SEARCH_STATUS", 25300 }, { "SLOT_CLAIM", 25201 }, { "SLOT_HEARTBEAT", 25200 }, { "SWARM_HEARTBEAT", 25004 }, { "TASK_ASSIGN_REQUEST", 25106 }, { "TASK_ASSIGN_RESPONSE", 25107 }, { "TASK_CONFIRM_REQUEST", 25108 }, { "TASK_CONFIRM_RESPONSE", 25109 }, { "VOTE_PHASE", 25202 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_NAVLINK_H
