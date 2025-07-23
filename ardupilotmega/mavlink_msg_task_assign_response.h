#pragma once
// MESSAGE TASK_ASSIGN_RESPONSE PACKING

#define MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE 25107


typedef struct __mavlink_task_assign_response_t {
 uint16_t task_id; /*<  */
 uint8_t sid; /*<  */
 uint8_t rid; /*<  */
 uint8_t accepted; /*<  */
} mavlink_task_assign_response_t;

#define MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN 5
#define MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_MIN_LEN 5
#define MAVLINK_MSG_ID_25107_LEN 5
#define MAVLINK_MSG_ID_25107_MIN_LEN 5

#define MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_CRC 236
#define MAVLINK_MSG_ID_25107_CRC 236



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TASK_ASSIGN_RESPONSE { \
    25107, \
    "TASK_ASSIGN_RESPONSE", \
    4, \
    {  { "sid", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_task_assign_response_t, sid) }, \
         { "rid", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_task_assign_response_t, rid) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_task_assign_response_t, task_id) }, \
         { "accepted", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_task_assign_response_t, accepted) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TASK_ASSIGN_RESPONSE { \
    "TASK_ASSIGN_RESPONSE", \
    4, \
    {  { "sid", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_task_assign_response_t, sid) }, \
         { "rid", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_task_assign_response_t, rid) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_task_assign_response_t, task_id) }, \
         { "accepted", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_task_assign_response_t, accepted) }, \
         } \
}
#endif

/**
 * @brief Pack a task_assign_response message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sid  
 * @param rid  
 * @param task_id  
 * @param accepted  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_assign_response_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t sid, uint8_t rid, uint16_t task_id, uint8_t accepted)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN];
    _mav_put_uint16_t(buf, 0, task_id);
    _mav_put_uint8_t(buf, 2, sid);
    _mav_put_uint8_t(buf, 3, rid);
    _mav_put_uint8_t(buf, 4, accepted);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN);
#else
    mavlink_task_assign_response_t packet;
    packet.task_id = task_id;
    packet.sid = sid;
    packet.rid = rid;
    packet.accepted = accepted;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_CRC);
}

/**
 * @brief Pack a task_assign_response message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param sid  
 * @param rid  
 * @param task_id  
 * @param accepted  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_assign_response_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t sid, uint8_t rid, uint16_t task_id, uint8_t accepted)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN];
    _mav_put_uint16_t(buf, 0, task_id);
    _mav_put_uint8_t(buf, 2, sid);
    _mav_put_uint8_t(buf, 3, rid);
    _mav_put_uint8_t(buf, 4, accepted);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN);
#else
    mavlink_task_assign_response_t packet;
    packet.task_id = task_id;
    packet.sid = sid;
    packet.rid = rid;
    packet.accepted = accepted;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN);
#endif
}

/**
 * @brief Pack a task_assign_response message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sid  
 * @param rid  
 * @param task_id  
 * @param accepted  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_assign_response_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t sid,uint8_t rid,uint16_t task_id,uint8_t accepted)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN];
    _mav_put_uint16_t(buf, 0, task_id);
    _mav_put_uint8_t(buf, 2, sid);
    _mav_put_uint8_t(buf, 3, rid);
    _mav_put_uint8_t(buf, 4, accepted);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN);
#else
    mavlink_task_assign_response_t packet;
    packet.task_id = task_id;
    packet.sid = sid;
    packet.rid = rid;
    packet.accepted = accepted;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_CRC);
}

/**
 * @brief Encode a task_assign_response struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param task_assign_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_assign_response_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_task_assign_response_t* task_assign_response)
{
    return mavlink_msg_task_assign_response_pack(system_id, component_id, msg, task_assign_response->sid, task_assign_response->rid, task_assign_response->task_id, task_assign_response->accepted);
}

/**
 * @brief Encode a task_assign_response struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param task_assign_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_assign_response_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_task_assign_response_t* task_assign_response)
{
    return mavlink_msg_task_assign_response_pack_chan(system_id, component_id, chan, msg, task_assign_response->sid, task_assign_response->rid, task_assign_response->task_id, task_assign_response->accepted);
}

/**
 * @brief Encode a task_assign_response struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param task_assign_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_assign_response_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_task_assign_response_t* task_assign_response)
{
    return mavlink_msg_task_assign_response_pack_status(system_id, component_id, _status, msg,  task_assign_response->sid, task_assign_response->rid, task_assign_response->task_id, task_assign_response->accepted);
}

/**
 * @brief Send a task_assign_response message
 * @param chan MAVLink channel to send the message
 *
 * @param sid  
 * @param rid  
 * @param task_id  
 * @param accepted  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_task_assign_response_send(mavlink_channel_t chan, uint8_t sid, uint8_t rid, uint16_t task_id, uint8_t accepted)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN];
    _mav_put_uint16_t(buf, 0, task_id);
    _mav_put_uint8_t(buf, 2, sid);
    _mav_put_uint8_t(buf, 3, rid);
    _mav_put_uint8_t(buf, 4, accepted);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE, buf, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_CRC);
#else
    mavlink_task_assign_response_t packet;
    packet.task_id = task_id;
    packet.sid = sid;
    packet.rid = rid;
    packet.accepted = accepted;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE, (const char *)&packet, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_CRC);
#endif
}

/**
 * @brief Send a task_assign_response message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_task_assign_response_send_struct(mavlink_channel_t chan, const mavlink_task_assign_response_t* task_assign_response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_task_assign_response_send(chan, task_assign_response->sid, task_assign_response->rid, task_assign_response->task_id, task_assign_response->accepted);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE, (const char *)task_assign_response, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_CRC);
#endif
}

#if MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_task_assign_response_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t sid, uint8_t rid, uint16_t task_id, uint8_t accepted)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, task_id);
    _mav_put_uint8_t(buf, 2, sid);
    _mav_put_uint8_t(buf, 3, rid);
    _mav_put_uint8_t(buf, 4, accepted);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE, buf, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_CRC);
#else
    mavlink_task_assign_response_t *packet = (mavlink_task_assign_response_t *)msgbuf;
    packet->task_id = task_id;
    packet->sid = sid;
    packet->rid = rid;
    packet->accepted = accepted;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE, (const char *)packet, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_CRC);
#endif
}
#endif

#endif

// MESSAGE TASK_ASSIGN_RESPONSE UNPACKING


/**
 * @brief Get field sid from task_assign_response message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_task_assign_response_get_sid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field rid from task_assign_response message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_task_assign_response_get_rid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field task_id from task_assign_response message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_task_assign_response_get_task_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field accepted from task_assign_response message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_task_assign_response_get_accepted(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a task_assign_response message into a struct
 *
 * @param msg The message to decode
 * @param task_assign_response C-struct to decode the message contents into
 */
static inline void mavlink_msg_task_assign_response_decode(const mavlink_message_t* msg, mavlink_task_assign_response_t* task_assign_response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    task_assign_response->task_id = mavlink_msg_task_assign_response_get_task_id(msg);
    task_assign_response->sid = mavlink_msg_task_assign_response_get_sid(msg);
    task_assign_response->rid = mavlink_msg_task_assign_response_get_rid(msg);
    task_assign_response->accepted = mavlink_msg_task_assign_response_get_accepted(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN? msg->len : MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN;
        memset(task_assign_response, 0, MAVLINK_MSG_ID_TASK_ASSIGN_RESPONSE_LEN);
    memcpy(task_assign_response, _MAV_PAYLOAD(msg), len);
#endif
}
