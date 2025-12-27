#pragma once
// MESSAGE TASK_CONFIRM_RESPONSE PACKING

#define MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE 25109


typedef struct __mavlink_task_confirm_response_t {
 uint64_t time_ms; /*< [ms] Sender timestamp in milliseconds since epoch.*/
 uint32_t boot_id; /*<  Random ID generated on process start, identifies sender instance.*/
 uint32_t msg_seq; /*<  Monotonic sequence counter per sender.*/
 uint32_t ttl_ms; /*< [ms] Time-to-live validity window in milliseconds.*/
 uint16_t task_id; /*<  Task ID being confirmed.*/
 uint8_t target_system; /*<  Target system ID (requester).*/
 uint8_t confirmed; /*<  1 if confirmed, 0 if rejected.*/
} mavlink_task_confirm_response_t;

#define MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN 24
#define MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN 24
#define MAVLINK_MSG_ID_25109_LEN 24
#define MAVLINK_MSG_ID_25109_MIN_LEN 24

#define MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC 246
#define MAVLINK_MSG_ID_25109_CRC 246



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TASK_CONFIRM_RESPONSE { \
    25109, \
    "TASK_CONFIRM_RESPONSE", \
    7, \
    {  { "boot_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_task_confirm_response_t, boot_id) }, \
         { "msg_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_task_confirm_response_t, msg_seq) }, \
         { "time_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_task_confirm_response_t, time_ms) }, \
         { "ttl_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_task_confirm_response_t, ttl_ms) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_task_confirm_response_t, target_system) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_task_confirm_response_t, task_id) }, \
         { "confirmed", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_task_confirm_response_t, confirmed) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TASK_CONFIRM_RESPONSE { \
    "TASK_CONFIRM_RESPONSE", \
    7, \
    {  { "boot_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_task_confirm_response_t, boot_id) }, \
         { "msg_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_task_confirm_response_t, msg_seq) }, \
         { "time_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_task_confirm_response_t, time_ms) }, \
         { "ttl_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_task_confirm_response_t, ttl_ms) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_task_confirm_response_t, target_system) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_task_confirm_response_t, task_id) }, \
         { "confirmed", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_task_confirm_response_t, confirmed) }, \
         } \
}
#endif

/**
 * @brief Pack a task_confirm_response message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param target_system  Target system ID (requester).
 * @param task_id  Task ID being confirmed.
 * @param confirmed  1 if confirmed, 0 if rejected.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_confirm_response_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint8_t target_system, uint16_t task_id, uint8_t confirmed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, task_id);
    _mav_put_uint8_t(buf, 22, target_system);
    _mav_put_uint8_t(buf, 23, confirmed);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN);
#else
    mavlink_task_confirm_response_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.task_id = task_id;
    packet.target_system = target_system;
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
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param target_system  Target system ID (requester).
 * @param task_id  Task ID being confirmed.
 * @param confirmed  1 if confirmed, 0 if rejected.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_confirm_response_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint8_t target_system, uint16_t task_id, uint8_t confirmed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, task_id);
    _mav_put_uint8_t(buf, 22, target_system);
    _mav_put_uint8_t(buf, 23, confirmed);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN);
#else
    mavlink_task_confirm_response_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.task_id = task_id;
    packet.target_system = target_system;
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
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param target_system  Target system ID (requester).
 * @param task_id  Task ID being confirmed.
 * @param confirmed  1 if confirmed, 0 if rejected.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_confirm_response_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t boot_id,uint32_t msg_seq,uint64_t time_ms,uint32_t ttl_ms,uint8_t target_system,uint16_t task_id,uint8_t confirmed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, task_id);
    _mav_put_uint8_t(buf, 22, target_system);
    _mav_put_uint8_t(buf, 23, confirmed);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN);
#else
    mavlink_task_confirm_response_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.task_id = task_id;
    packet.target_system = target_system;
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
    return mavlink_msg_task_confirm_response_pack(system_id, component_id, msg, task_confirm_response->boot_id, task_confirm_response->msg_seq, task_confirm_response->time_ms, task_confirm_response->ttl_ms, task_confirm_response->target_system, task_confirm_response->task_id, task_confirm_response->confirmed);
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
    return mavlink_msg_task_confirm_response_pack_chan(system_id, component_id, chan, msg, task_confirm_response->boot_id, task_confirm_response->msg_seq, task_confirm_response->time_ms, task_confirm_response->ttl_ms, task_confirm_response->target_system, task_confirm_response->task_id, task_confirm_response->confirmed);
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
    return mavlink_msg_task_confirm_response_pack_status(system_id, component_id, _status, msg,  task_confirm_response->boot_id, task_confirm_response->msg_seq, task_confirm_response->time_ms, task_confirm_response->ttl_ms, task_confirm_response->target_system, task_confirm_response->task_id, task_confirm_response->confirmed);
}

/**
 * @brief Send a task_confirm_response message
 * @param chan MAVLink channel to send the message
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param target_system  Target system ID (requester).
 * @param task_id  Task ID being confirmed.
 * @param confirmed  1 if confirmed, 0 if rejected.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_task_confirm_response_send(mavlink_channel_t chan, uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint8_t target_system, uint16_t task_id, uint8_t confirmed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, task_id);
    _mav_put_uint8_t(buf, 22, target_system);
    _mav_put_uint8_t(buf, 23, confirmed);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE, buf, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC);
#else
    mavlink_task_confirm_response_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.task_id = task_id;
    packet.target_system = target_system;
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
    mavlink_msg_task_confirm_response_send(chan, task_confirm_response->boot_id, task_confirm_response->msg_seq, task_confirm_response->time_ms, task_confirm_response->ttl_ms, task_confirm_response->target_system, task_confirm_response->task_id, task_confirm_response->confirmed);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE, (const char *)task_confirm_response, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC);
#endif
}

#if MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_task_confirm_response_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint8_t target_system, uint16_t task_id, uint8_t confirmed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, task_id);
    _mav_put_uint8_t(buf, 22, target_system);
    _mav_put_uint8_t(buf, 23, confirmed);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE, buf, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC);
#else
    mavlink_task_confirm_response_t *packet = (mavlink_task_confirm_response_t *)msgbuf;
    packet->time_ms = time_ms;
    packet->boot_id = boot_id;
    packet->msg_seq = msg_seq;
    packet->ttl_ms = ttl_ms;
    packet->task_id = task_id;
    packet->target_system = target_system;
    packet->confirmed = confirmed;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE, (const char *)packet, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_CRC);
#endif
}
#endif

#endif

// MESSAGE TASK_CONFIRM_RESPONSE UNPACKING


/**
 * @brief Get field boot_id from task_confirm_response message
 *
 * @return  Random ID generated on process start, identifies sender instance.
 */
static inline uint32_t mavlink_msg_task_confirm_response_get_boot_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field msg_seq from task_confirm_response message
 *
 * @return  Monotonic sequence counter per sender.
 */
static inline uint32_t mavlink_msg_task_confirm_response_get_msg_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field time_ms from task_confirm_response message
 *
 * @return [ms] Sender timestamp in milliseconds since epoch.
 */
static inline uint64_t mavlink_msg_task_confirm_response_get_time_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field ttl_ms from task_confirm_response message
 *
 * @return [ms] Time-to-live validity window in milliseconds.
 */
static inline uint32_t mavlink_msg_task_confirm_response_get_ttl_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field target_system from task_confirm_response message
 *
 * @return  Target system ID (requester).
 */
static inline uint8_t mavlink_msg_task_confirm_response_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Get field task_id from task_confirm_response message
 *
 * @return  Task ID being confirmed.
 */
static inline uint16_t mavlink_msg_task_confirm_response_get_task_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field confirmed from task_confirm_response message
 *
 * @return  1 if confirmed, 0 if rejected.
 */
static inline uint8_t mavlink_msg_task_confirm_response_get_confirmed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  23);
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
    task_confirm_response->time_ms = mavlink_msg_task_confirm_response_get_time_ms(msg);
    task_confirm_response->boot_id = mavlink_msg_task_confirm_response_get_boot_id(msg);
    task_confirm_response->msg_seq = mavlink_msg_task_confirm_response_get_msg_seq(msg);
    task_confirm_response->ttl_ms = mavlink_msg_task_confirm_response_get_ttl_ms(msg);
    task_confirm_response->task_id = mavlink_msg_task_confirm_response_get_task_id(msg);
    task_confirm_response->target_system = mavlink_msg_task_confirm_response_get_target_system(msg);
    task_confirm_response->confirmed = mavlink_msg_task_confirm_response_get_confirmed(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN? msg->len : MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN;
        memset(task_confirm_response, 0, MAVLINK_MSG_ID_TASK_CONFIRM_RESPONSE_LEN);
    memcpy(task_confirm_response, _MAV_PAYLOAD(msg), len);
#endif
}
