#pragma once
// MESSAGE TASK_CONFIRM_RESPONSE PACKING

#define MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE 25109


typedef struct __mavlink_task_confirm_response_t {
 uint16_t task_id; /*<  */
 uint8_t rid; /*<  */
 uint8_t confirmed; /*<  */
} mavlink_task_confirm_response_t;

#define MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN 4
#define MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN 4
#define MAVLINK_MSG_ID_25109_LEN 4
#define MAVLINK_MSG_ID_25109_MIN_LEN 4

#define MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC 202
#define MAVLINK_MSG_ID_25109_CRC 202



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TASK_CONFIRM_RESPONSE { \
    25109, \
    "TASK_CONFIRM_RESPONSE", \
    3, \
    {  { "rid", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_task_confirm_response_t, rid) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_task_confirm_response_t, task_id) }, \
         { "confirmed", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_task_confirm_response_t, confirmed) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TASK_CONFIRM_RESPONSE { \
    "TASK_CONFIRM_RESPONSE", \
    3, \
    {  { "rid", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_task_confirm_response_t, rid) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_task_confirm_response_t, task_id) }, \
         { "confirmed", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_task_confirm_response_t, confirmed) }, \
         } \
}
#endif

/**
 * @brief Pack a task_confirm_response message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param rid  
 * @param task_id  
 * @param confirmed  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_confirm_response_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t rid, uint16_t task_id, uint8_t confirmed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN];
    _mav_put_uint16_t(buf, 0, task_id);
    _mav_put_uint8_t(buf, 2, rid);
    _mav_put_uint8_t(buf, 3, confirmed);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN);
#else
    mavlink_task_confirm_response_t packet;
    packet.task_id = task_id;
    packet.rid = rid;
    packet.confirmed = confirmed;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC);
}

/**
 * @brief Pack a task_confirm_response message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param rid  
 * @param task_id  
 * @param confirmed  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_confirm_response_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t rid, uint16_t task_id, uint8_t confirmed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN];
    _mav_put_uint16_t(buf, 0, task_id);
    _mav_put_uint8_t(buf, 2, rid);
    _mav_put_uint8_t(buf, 3, confirmed);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN);
#else
    mavlink_task_confirm_response_t packet;
    packet.task_id = task_id;
    packet.rid = rid;
    packet.confirmed = confirmed;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN);
#endif
}

/**
 * @brief Pack a task_confirm_response message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rid  
 * @param task_id  
 * @param confirmed  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_confirm_response_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t rid,uint16_t task_id,uint8_t confirmed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN];
    _mav_put_uint16_t(buf, 0, task_id);
    _mav_put_uint8_t(buf, 2, rid);
    _mav_put_uint8_t(buf, 3, confirmed);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN);
#else
    mavlink_task_confirm_response_t packet;
    packet.task_id = task_id;
    packet.rid = rid;
    packet.confirmed = confirmed;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC);
}

/**
 * @brief Encode a task_confirm_response struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param task_confirm_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_confirm_response_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_task_confirm_response_t* task_confirm_response)
{
    return mavlink_msg_task_confirm_response_pack(system_id, component_id, msg, task_confirm_response->rid, task_confirm_response->task_id, task_confirm_response->confirmed);
}

/**
 * @brief Encode a task_confirm_response struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param task_confirm_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_confirm_response_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_task_confirm_response_t* task_confirm_response)
{
    return mavlink_msg_task_confirm_response_pack_chan(system_id, component_id, chan, msg, task_confirm_response->rid, task_confirm_response->task_id, task_confirm_response->confirmed);
}

/**
 * @brief Encode a task_confirm_response struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param task_confirm_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_confirm_response_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_task_confirm_response_t* task_confirm_response)
{
    return mavlink_msg_task_confirm_response_pack_status(system_id, component_id, _status, msg,  task_confirm_response->rid, task_confirm_response->task_id, task_confirm_response->confirmed);
}

/**
 * @brief Send a task_confirm_response message
 * @param chan MAVLink channel to send the message
 *
 * @param rid  
 * @param task_id  
 * @param confirmed  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_task_confirm_response_send(mavlink_channel_t chan, uint8_t rid, uint16_t task_id, uint8_t confirmed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN];
    _mav_put_uint16_t(buf, 0, task_id);
    _mav_put_uint8_t(buf, 2, rid);
    _mav_put_uint8_t(buf, 3, confirmed);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE, buf, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC);
#else
    mavlink_task_confirm_response_t packet;
    packet.task_id = task_id;
    packet.rid = rid;
    packet.confirmed = confirmed;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE, (const char *)&packet, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC);
#endif
}

/**
 * @brief Send a task_confirm_response message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_task_confirm_response_send_struct(mavlink_channel_t chan, const mavlink_task_confirm_response_t* task_confirm_response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_task_confirm_response_send(chan, task_confirm_response->rid, task_confirm_response->task_id, task_confirm_response->confirmed);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE, (const char *)task_confirm_response, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC);
#endif
}

#if MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_task_confirm_response_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t rid, uint16_t task_id, uint8_t confirmed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, task_id);
    _mav_put_uint8_t(buf, 2, rid);
    _mav_put_uint8_t(buf, 3, confirmed);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE, buf, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC);
#else
    mavlink_task_confirm_response_t *packet = (mavlink_task_confirm_response_t *)msgbuf;
    packet->task_id = task_id;
    packet->rid = rid;
    packet->confirmed = confirmed;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE, (const char *)packet, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC);
#endif
}
#endif

#endif

// MESSAGE TASK_CONFIRM_RESPONSE UNPACKING


/**
 * @brief Get field rid from task_confirm_response message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_task_confirm_response_get_rid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field task_id from task_confirm_response message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_task_confirm_response_get_task_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field confirmed from task_confirm_response message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_task_confirm_response_get_confirmed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Decode a task_confirm_response message into a struct
 *
 * @param msg The message to decode
 * @param task_confirm_response C-struct to decode the message contents into
 */
static inline void mavlink_msg_task_confirm_response_decode(const mavlink_message_t* msg, mavlink_task_confirm_response_t* task_confirm_response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    task_confirm_response->task_id = mavlink_msg_task_confirm_response_get_task_id(msg);
    task_confirm_response->rid = mavlink_msg_task_confirm_response_get_rid(msg);
    task_confirm_response->confirmed = mavlink_msg_task_confirm_response_get_confirmed(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN? msg->len : MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN;
        memset(task_confirm_response, 0, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN);
    memcpy(task_confirm_response, _MAV_PAYLOAD(msg), len);
#endif
}
