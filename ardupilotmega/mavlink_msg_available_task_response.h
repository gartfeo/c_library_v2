#pragma once
// MESSAGE AVAILABLE_TASK_RESPONSE PACKING

#define MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE 25105


typedef struct __mavlink_available_task_response_t {
 float time[5]; /*<  */
 uint16_t task_id[5]; /*<  */
 uint8_t sid; /*<  */
 uint8_t rid; /*<  */
 uint8_t count; /*<  */
} mavlink_available_task_response_t;

#define MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN 33
#define MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_MIN_LEN 33
#define MAVLINK_MSG_ID_25105_LEN 33
#define MAVLINK_MSG_ID_25105_MIN_LEN 33

#define MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_CRC 155
#define MAVLINK_MSG_ID_25105_CRC 155

#define MAVLINK_MSG_AVAILABLE_TASK_RESPONSE_FIELD_TIME_LEN 5
#define MAVLINK_MSG_AVAILABLE_TASK_RESPONSE_FIELD_TASK_ID_LEN 5

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AVAILABLE_TASK_RESPONSE { \
    25105, \
    "AVAILABLE_TASK_RESPONSE", \
    5, \
    {  { "sid", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_available_task_response_t, sid) }, \
         { "rid", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_available_task_response_t, rid) }, \
         { "count", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_available_task_response_t, count) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 5, 20, offsetof(mavlink_available_task_response_t, task_id) }, \
         { "time", NULL, MAVLINK_TYPE_FLOAT, 5, 0, offsetof(mavlink_available_task_response_t, time) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AVAILABLE_TASK_RESPONSE { \
    "AVAILABLE_TASK_RESPONSE", \
    5, \
    {  { "sid", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_available_task_response_t, sid) }, \
         { "rid", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_available_task_response_t, rid) }, \
         { "count", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_available_task_response_t, count) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 5, 20, offsetof(mavlink_available_task_response_t, task_id) }, \
         { "time", NULL, MAVLINK_TYPE_FLOAT, 5, 0, offsetof(mavlink_available_task_response_t, time) }, \
         } \
}
#endif

/**
 * @brief Pack a available_task_response message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sid  
 * @param rid  
 * @param count  
 * @param task_id  
 * @param time  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_available_task_response_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t sid, uint8_t rid, uint8_t count, const uint16_t *task_id, const float *time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN];
    _mav_put_uint8_t(buf, 30, sid);
    _mav_put_uint8_t(buf, 31, rid);
    _mav_put_uint8_t(buf, 32, count);
    _mav_put_float_array(buf, 0, time, 5);
    _mav_put_uint16_t_array(buf, 20, task_id, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN);
#else
    mavlink_available_task_response_t packet;
    packet.sid = sid;
    packet.rid = rid;
    packet.count = count;
    mav_array_assign_float(packet.time, time, 5);
    mav_array_assign_uint16_t(packet.task_id, task_id, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_CRC);
}

/**
 * @brief Pack a available_task_response message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param sid  
 * @param rid  
 * @param count  
 * @param task_id  
 * @param time  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_available_task_response_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t sid, uint8_t rid, uint8_t count, const uint16_t *task_id, const float *time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN];
    _mav_put_uint8_t(buf, 30, sid);
    _mav_put_uint8_t(buf, 31, rid);
    _mav_put_uint8_t(buf, 32, count);
    _mav_put_float_array(buf, 0, time, 5);
    _mav_put_uint16_t_array(buf, 20, task_id, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN);
#else
    mavlink_available_task_response_t packet;
    packet.sid = sid;
    packet.rid = rid;
    packet.count = count;
    mav_array_memcpy(packet.time, time, sizeof(float)*5);
    mav_array_memcpy(packet.task_id, task_id, sizeof(uint16_t)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN);
#endif
}

/**
 * @brief Pack a available_task_response message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sid  
 * @param rid  
 * @param count  
 * @param task_id  
 * @param time  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_available_task_response_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t sid,uint8_t rid,uint8_t count,const uint16_t *task_id,const float *time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN];
    _mav_put_uint8_t(buf, 30, sid);
    _mav_put_uint8_t(buf, 31, rid);
    _mav_put_uint8_t(buf, 32, count);
    _mav_put_float_array(buf, 0, time, 5);
    _mav_put_uint16_t_array(buf, 20, task_id, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN);
#else
    mavlink_available_task_response_t packet;
    packet.sid = sid;
    packet.rid = rid;
    packet.count = count;
    mav_array_assign_float(packet.time, time, 5);
    mav_array_assign_uint16_t(packet.task_id, task_id, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_CRC);
}

/**
 * @brief Encode a available_task_response struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param available_task_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_available_task_response_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_available_task_response_t* available_task_response)
{
    return mavlink_msg_available_task_response_pack(system_id, component_id, msg, available_task_response->sid, available_task_response->rid, available_task_response->count, available_task_response->task_id, available_task_response->time);
}

/**
 * @brief Encode a available_task_response struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param available_task_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_available_task_response_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_available_task_response_t* available_task_response)
{
    return mavlink_msg_available_task_response_pack_chan(system_id, component_id, chan, msg, available_task_response->sid, available_task_response->rid, available_task_response->count, available_task_response->task_id, available_task_response->time);
}

/**
 * @brief Encode a available_task_response struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param available_task_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_available_task_response_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_available_task_response_t* available_task_response)
{
    return mavlink_msg_available_task_response_pack_status(system_id, component_id, _status, msg,  available_task_response->sid, available_task_response->rid, available_task_response->count, available_task_response->task_id, available_task_response->time);
}

/**
 * @brief Send a available_task_response message
 * @param chan MAVLink channel to send the message
 *
 * @param sid  
 * @param rid  
 * @param count  
 * @param task_id  
 * @param time  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_available_task_response_send(mavlink_channel_t chan, uint8_t sid, uint8_t rid, uint8_t count, const uint16_t *task_id, const float *time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN];
    _mav_put_uint8_t(buf, 30, sid);
    _mav_put_uint8_t(buf, 31, rid);
    _mav_put_uint8_t(buf, 32, count);
    _mav_put_float_array(buf, 0, time, 5);
    _mav_put_uint16_t_array(buf, 20, task_id, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE, buf, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_CRC);
#else
    mavlink_available_task_response_t packet;
    packet.sid = sid;
    packet.rid = rid;
    packet.count = count;
    mav_array_assign_float(packet.time, time, 5);
    mav_array_assign_uint16_t(packet.task_id, task_id, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE, (const char *)&packet, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_CRC);
#endif
}

/**
 * @brief Send a available_task_response message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_available_task_response_send_struct(mavlink_channel_t chan, const mavlink_available_task_response_t* available_task_response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_available_task_response_send(chan, available_task_response->sid, available_task_response->rid, available_task_response->count, available_task_response->task_id, available_task_response->time);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE, (const char *)available_task_response, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_CRC);
#endif
}

#if MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_available_task_response_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t sid, uint8_t rid, uint8_t count, const uint16_t *task_id, const float *time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 30, sid);
    _mav_put_uint8_t(buf, 31, rid);
    _mav_put_uint8_t(buf, 32, count);
    _mav_put_float_array(buf, 0, time, 5);
    _mav_put_uint16_t_array(buf, 20, task_id, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE, buf, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_CRC);
#else
    mavlink_available_task_response_t *packet = (mavlink_available_task_response_t *)msgbuf;
    packet->sid = sid;
    packet->rid = rid;
    packet->count = count;
    mav_array_assign_float(packet->time, time, 5);
    mav_array_assign_uint16_t(packet->task_id, task_id, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE, (const char *)packet, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_CRC);
#endif
}
#endif

#endif

// MESSAGE AVAILABLE_TASK_RESPONSE UNPACKING


/**
 * @brief Get field sid from available_task_response message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_available_task_response_get_sid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field rid from available_task_response message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_available_task_response_get_rid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Get field count from available_task_response message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_available_task_response_get_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field task_id from available_task_response message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_available_task_response_get_task_id(const mavlink_message_t* msg, uint16_t *task_id)
{
    return _MAV_RETURN_uint16_t_array(msg, task_id, 5,  20);
}

/**
 * @brief Get field time from available_task_response message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_available_task_response_get_time(const mavlink_message_t* msg, float *time)
{
    return _MAV_RETURN_float_array(msg, time, 5,  0);
}

/**
 * @brief Decode a available_task_response message into a struct
 *
 * @param msg The message to decode
 * @param available_task_response C-struct to decode the message contents into
 */
static inline void mavlink_msg_available_task_response_decode(const mavlink_message_t* msg, mavlink_available_task_response_t* available_task_response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_available_task_response_get_time(msg, available_task_response->time);
    mavlink_msg_available_task_response_get_task_id(msg, available_task_response->task_id);
    available_task_response->sid = mavlink_msg_available_task_response_get_sid(msg);
    available_task_response->rid = mavlink_msg_available_task_response_get_rid(msg);
    available_task_response->count = mavlink_msg_available_task_response_get_count(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN? msg->len : MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN;
        memset(available_task_response, 0, MAVLINK_MSG_ID_AVAILABLE_TASK_RESPONSE_LEN);
    memcpy(available_task_response, _MAV_PAYLOAD(msg), len);
#endif
}
