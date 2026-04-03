/** @file
 *    @brief MAVLink comm protocol testsuite generated from navlink.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef NAVLINK_TESTSUITE_H
#define NAVLINK_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_navlink(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_navlink(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_check_in(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CHECK_IN >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_check_in_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296
    };
    mavlink_check_in_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CHECK_IN_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CHECK_IN_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_check_in_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_check_in_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_check_in_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms );
    mavlink_msg_check_in_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_check_in_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms );
    mavlink_msg_check_in_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_check_in_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_check_in_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms );
    mavlink_msg_check_in_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CHECK_IN") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CHECK_IN) != NULL);
#endif
}

static void mavlink_test_check_out(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CHECK_OUT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_check_out_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,157.0,185.0,213.0
    };
    mavlink_check_out_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        packet1.lat = packet_in.lat;
        packet1.lng = packet_in.lng;
        packet1.alt = packet_in.alt;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_check_out_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_check_out_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_check_out_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.lat , packet1.lng , packet1.alt );
    mavlink_msg_check_out_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_check_out_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.lat , packet1.lng , packet1.alt );
    mavlink_msg_check_out_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_check_out_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_check_out_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.lat , packet1.lng , packet1.alt );
    mavlink_msg_check_out_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CHECK_OUT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CHECK_OUT) != NULL);
#endif
}

static void mavlink_test_swarm_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SWARM_HEARTBEAT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_swarm_heartbeat_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,65
    };
    mavlink_swarm_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        packet1.state = packet_in.state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SWARM_HEARTBEAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SWARM_HEARTBEAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_swarm_heartbeat_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_swarm_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_swarm_heartbeat_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.state );
    mavlink_msg_swarm_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_swarm_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.state );
    mavlink_msg_swarm_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_swarm_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_swarm_heartbeat_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.state );
    mavlink_msg_swarm_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SWARM_HEARTBEAT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SWARM_HEARTBEAT) != NULL);
#endif
}

static void mavlink_test_available_task_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_available_task_request_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,{ 157.0, 158.0, 159.0, 160.0, 161.0 },{ 297.0, 298.0, 299.0, 300.0, 301.0 },{ 437.0, 438.0, 439.0, 440.0, 441.0 },{ 21395, 21396, 21397, 21398, 21399 },147,{ 214, 215, 216, 217, 218 },{ 37, 38, 39, 40, 41 }
    };
    mavlink_available_task_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        packet1.count = packet_in.count;
        
        mav_array_memcpy(packet1.lat, packet_in.lat, sizeof(float)*5);
        mav_array_memcpy(packet1.lng, packet_in.lng, sizeof(float)*5);
        mav_array_memcpy(packet1.alt, packet_in.alt, sizeof(float)*5);
        mav_array_memcpy(packet1.task_id, packet_in.task_id, sizeof(uint16_t)*5);
        mav_array_memcpy(packet1.task_type, packet_in.task_type, sizeof(uint8_t)*5);
        mav_array_memcpy(packet1.class_id, packet_in.class_id, sizeof(uint8_t)*5);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_task_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_available_task_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_task_request_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.count , packet1.task_id , packet1.task_type , packet1.class_id , packet1.lat , packet1.lng , packet1.alt );
    mavlink_msg_available_task_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_task_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.count , packet1.task_id , packet1.task_type , packet1.class_id , packet1.lat , packet1.lng , packet1.alt );
    mavlink_msg_available_task_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_available_task_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_task_request_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.count , packet1.task_id , packet1.task_type , packet1.class_id , packet1.lat , packet1.lng , packet1.alt );
    mavlink_msg_available_task_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AVAILABLE_TASK_REQUEST") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST) != NULL);
#endif
}

static void mavlink_test_available_task_response(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_available_task_response_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,{ 157.0, 158.0, 159.0, 160.0, 161.0 },{ 19315, 19316, 19317, 19318, 19319 },27,94
    };
    mavlink_available_task_response_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        packet1.target_system = packet_in.target_system;
        packet1.count = packet_in.count;
        
        mav_array_memcpy(packet1.time, packet_in.time, sizeof(float)*5);
        mav_array_memcpy(packet1.task_id, packet_in.task_id, sizeof(uint16_t)*5);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_task_response_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_available_task_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_task_response_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.target_system , packet1.count , packet1.task_id , packet1.time );
    mavlink_msg_available_task_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_task_response_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.target_system , packet1.count , packet1.task_id , packet1.time );
    mavlink_msg_available_task_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_available_task_response_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_task_response_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.target_system , packet1.count , packet1.task_id , packet1.time );
    mavlink_msg_available_task_response_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AVAILABLE_TASK_RESPONSE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE) != NULL);
#endif
}

static void mavlink_test_task_assign_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_assign_request_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,157.0,185.0,213.0,18899,235,46,113
    };
    mavlink_task_assign_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        packet1.lat = packet_in.lat;
        packet1.lng = packet_in.lng;
        packet1.alt = packet_in.alt;
        packet1.task_id = packet_in.task_id;
        packet1.target_system = packet_in.target_system;
        packet1.task_type = packet_in.task_type;
        packet1.class_id = packet_in.class_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_assign_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_assign_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_assign_request_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.target_system , packet1.task_id , packet1.task_type , packet1.class_id , packet1.lat , packet1.lng , packet1.alt );
    mavlink_msg_task_assign_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_assign_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.target_system , packet1.task_id , packet1.task_type , packet1.class_id , packet1.lat , packet1.lng , packet1.alt );
    mavlink_msg_task_assign_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_assign_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_assign_request_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.target_system , packet1.task_id , packet1.task_type , packet1.class_id , packet1.lat , packet1.lng , packet1.alt );
    mavlink_msg_task_assign_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_ASSIGN_REQUEST") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST) != NULL);
#endif
}

static void mavlink_test_task_assign_response(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_assign_response_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,18275,199,10
    };
    mavlink_task_assign_response_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        packet1.task_id = packet_in.task_id;
        packet1.target_system = packet_in.target_system;
        packet1.accepted = packet_in.accepted;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_assign_response_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_assign_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_assign_response_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.target_system , packet1.task_id , packet1.accepted );
    mavlink_msg_task_assign_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_assign_response_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.target_system , packet1.task_id , packet1.accepted );
    mavlink_msg_task_assign_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_assign_response_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_assign_response_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.target_system , packet1.task_id , packet1.accepted );
    mavlink_msg_task_assign_response_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_ASSIGN_RESPONSE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE) != NULL);
#endif
}

static void mavlink_test_task_confirm_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_CONFIRM_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_confirm_request_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,157.0,185.0,213.0,18899,235,46
    };
    mavlink_task_confirm_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        packet1.lat = packet_in.lat;
        packet1.lng = packet_in.lng;
        packet1.alt = packet_in.alt;
        packet1.task_id = packet_in.task_id;
        packet1.task_type = packet_in.task_type;
        packet1.class_id = packet_in.class_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_CONFIRM_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_CONFIRM_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_confirm_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_confirm_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_confirm_request_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.task_id , packet1.task_type , packet1.class_id , packet1.lat , packet1.lng , packet1.alt );
    mavlink_msg_task_confirm_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_confirm_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.task_id , packet1.task_type , packet1.class_id , packet1.lat , packet1.lng , packet1.alt );
    mavlink_msg_task_confirm_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_confirm_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_confirm_request_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.task_id , packet1.task_type , packet1.class_id , packet1.lat , packet1.lng , packet1.alt );
    mavlink_msg_task_confirm_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_CONFIRM_REQUEST") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_CONFIRM_REQUEST) != NULL);
#endif
}

static void mavlink_test_task_confirm_response(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_task_confirm_response_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,18275,199,10
    };
    mavlink_task_confirm_response_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        packet1.task_id = packet_in.task_id;
        packet1.target_system = packet_in.target_system;
        packet1.confirmed = packet_in.confirmed;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_confirm_response_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_task_confirm_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_confirm_response_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.target_system , packet1.task_id , packet1.confirmed );
    mavlink_msg_task_confirm_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_confirm_response_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.target_system , packet1.task_id , packet1.confirmed );
    mavlink_msg_task_confirm_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_task_confirm_response_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_task_confirm_response_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.target_system , packet1.task_id , packet1.confirmed );
    mavlink_msg_task_confirm_response_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TASK_CONFIRM_RESPONSE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE) != NULL);
#endif
}

static void mavlink_test_slot_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SLOT_HEARTBEAT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_slot_heartbeat_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,65,132
    };
    mavlink_slot_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        packet1.slot_id = packet_in.slot_id;
        packet1.state = packet_in.state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SLOT_HEARTBEAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SLOT_HEARTBEAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_slot_heartbeat_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_slot_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_slot_heartbeat_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.slot_id , packet1.state );
    mavlink_msg_slot_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_slot_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.slot_id , packet1.state );
    mavlink_msg_slot_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_slot_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_slot_heartbeat_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.slot_id , packet1.state );
    mavlink_msg_slot_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SLOT_HEARTBEAT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SLOT_HEARTBEAT) != NULL);
#endif
}

static void mavlink_test_slot_claim(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SLOT_CLAIM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_slot_claim_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,65,132
    };
    mavlink_slot_claim_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        packet1.slot_id = packet_in.slot_id;
        packet1.priority = packet_in.priority;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SLOT_CLAIM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SLOT_CLAIM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_slot_claim_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_slot_claim_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_slot_claim_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.slot_id , packet1.priority );
    mavlink_msg_slot_claim_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_slot_claim_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.slot_id , packet1.priority );
    mavlink_msg_slot_claim_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_slot_claim_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_slot_claim_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.slot_id , packet1.priority );
    mavlink_msg_slot_claim_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SLOT_CLAIM") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SLOT_CLAIM) != NULL);
#endif
}

static void mavlink_test_vote_phase(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_VOTE_PHASE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_vote_phase_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,18275,18379,77,144
    };
    mavlink_vote_phase_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        packet1.round_id = packet_in.round_id;
        packet1.proposal_id = packet_in.proposal_id;
        packet1.phase = packet_in.phase;
        packet1.vote = packet_in.vote;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_VOTE_PHASE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_VOTE_PHASE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vote_phase_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_vote_phase_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vote_phase_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.phase , packet1.round_id , packet1.proposal_id , packet1.vote );
    mavlink_msg_vote_phase_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vote_phase_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.phase , packet1.round_id , packet1.proposal_id , packet1.vote );
    mavlink_msg_vote_phase_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_vote_phase_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vote_phase_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.phase , packet1.round_id , packet1.proposal_id , packet1.vote );
    mavlink_msg_vote_phase_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("VOTE_PHASE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_VOTE_PHASE) != NULL);
#endif
}

static void mavlink_test_search_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SEARCH_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_search_status_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,18275,199,10,77
    };
    mavlink_search_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_ms = packet_in.time_ms;
        packet1.boot_id = packet_in.boot_id;
        packet1.msg_seq = packet_in.msg_seq;
        packet1.ttl_ms = packet_in.ttl_ms;
        packet1.area_id = packet_in.area_id;
        packet1.status = packet_in.status;
        packet1.coverage_pct = packet_in.coverage_pct;
        packet1.detections = packet_in.detections;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SEARCH_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SEARCH_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_search_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_search_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_search_status_pack(system_id, component_id, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.area_id , packet1.status , packet1.coverage_pct , packet1.detections );
    mavlink_msg_search_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_search_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.area_id , packet1.status , packet1.coverage_pct , packet1.detections );
    mavlink_msg_search_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_search_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_search_status_send(MAVLINK_COMM_1 , packet1.boot_id , packet1.msg_seq , packet1.time_ms , packet1.ttl_ms , packet1.area_id , packet1.status , packet1.coverage_pct , packet1.detections );
    mavlink_msg_search_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SEARCH_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SEARCH_STATUS) != NULL);
#endif
}

static void mavlink_test_navlink(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_check_in(system_id, component_id, last_msg);
    mavlink_test_check_out(system_id, component_id, last_msg);
    mavlink_test_swarm_heartbeat(system_id, component_id, last_msg);
    mavlink_test_available_task_request(system_id, component_id, last_msg);
    mavlink_test_available_task_response(system_id, component_id, last_msg);
    mavlink_test_task_assign_request(system_id, component_id, last_msg);
    mavlink_test_task_assign_response(system_id, component_id, last_msg);
    mavlink_test_task_confirm_request(system_id, component_id, last_msg);
    mavlink_test_task_confirm_response(system_id, component_id, last_msg);
    mavlink_test_slot_heartbeat(system_id, component_id, last_msg);
    mavlink_test_slot_claim(system_id, component_id, last_msg);
    mavlink_test_vote_phase(system_id, component_id, last_msg);
    mavlink_test_search_status(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // NAVLINK_TESTSUITE_H
