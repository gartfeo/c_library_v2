#pragma once
// MESSAGE CHECK_IN PACKING

#define MAVLINK_MSG_ID_CHECK_IN 25002


typedef struct __mavlink_check_in_t {
 uint64_t time_ms; /*< [ms] Sender timestamp in milliseconds since epoch.*/
 uint32_t boot_id; /*<  Random ID generated on process start, identifies sender instance.*/
 uint32_t msg_seq; /*<  Monotonic sequence counter per sender.*/
 uint32_t ttl_ms; /*< [ms] Time-to-live validity window in milliseconds.*/
} mavlink_check_in_t;

#define MAVLINK_MSG_ID_CHECK_IN_LEN 20
#define MAVLINK_MSG_ID_CHECK_IN_MIN_LEN 20
#define MAVLINK_MSG_ID_25002_LEN 20
#define MAVLINK_MSG_ID_25002_MIN_LEN 20

#define MAVLINK_MSG_ID_CHECK_IN_CRC 29
#define MAVLINK_MSG_ID_25002_CRC 29



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CHECK_IN { \
    25002, \
    "CHECK_IN", \
    4, \
    {  { "boot_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_check_in_t, boot_id) }, \
         { "msg_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_check_in_t, msg_seq) }, \
         { "time_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_check_in_t, time_ms) }, \
         { "ttl_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_check_in_t, ttl_ms) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CHECK_IN { \
    "CHECK_IN", \
    4, \
    {  { "boot_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_check_in_t, boot_id) }, \
         { "msg_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_check_in_t, msg_seq) }, \
         { "time_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_check_in_t, time_ms) }, \
         { "ttl_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_check_in_t, ttl_ms) }, \
         } \
}
#endif

/**
 * @brief Pack a check_in message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_check_in_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHECK_IN_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHECK_IN_LEN);
#else
    mavlink_check_in_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHECK_IN_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CHECK_IN;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CHECK_IN_MIN_LEN, MAVLINK_MSG_ID_CHECK_IN_LEN, MAVLINK_MSG_ID_CHECK_IN_CRC);
}

/**
 * @brief Pack a check_in message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_check_in_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHECK_IN_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHECK_IN_LEN);
#else
    mavlink_check_in_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHECK_IN_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CHECK_IN;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CHECK_IN_MIN_LEN, MAVLINK_MSG_ID_CHECK_IN_LEN, MAVLINK_MSG_ID_CHECK_IN_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CHECK_IN_MIN_LEN, MAVLINK_MSG_ID_CHECK_IN_LEN);
#endif
}

/**
 * @brief Pack a check_in message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_check_in_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t boot_id,uint32_t msg_seq,uint64_t time_ms,uint32_t ttl_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHECK_IN_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHECK_IN_LEN);
#else
    mavlink_check_in_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHECK_IN_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CHECK_IN;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CHECK_IN_MIN_LEN, MAVLINK_MSG_ID_CHECK_IN_LEN, MAVLINK_MSG_ID_CHECK_IN_CRC);
}

/**
 * @brief Encode a check_in struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param check_in C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_check_in_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_check_in_t* check_in)
{
    return mavlink_msg_check_in_pack(system_id, component_id, msg, check_in->boot_id, check_in->msg_seq, check_in->time_ms, check_in->ttl_ms);
}

/**
 * @brief Encode a check_in struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param check_in C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_check_in_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_check_in_t* check_in)
{
    return mavlink_msg_check_in_pack_chan(system_id, component_id, chan, msg, check_in->boot_id, check_in->msg_seq, check_in->time_ms, check_in->ttl_ms);
}

/**
 * @brief Encode a check_in struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param check_in C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_check_in_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_check_in_t* check_in)
{
    return mavlink_msg_check_in_pack_status(system_id, component_id, _status, msg,  check_in->boot_id, check_in->msg_seq, check_in->time_ms, check_in->ttl_ms);
}

/**
 * @brief Send a check_in message
 * @param chan MAVLink channel to send the message
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_check_in_send(mavlink_channel_t chan, uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHECK_IN_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_IN, buf, MAVLINK_MSG_ID_CHECK_IN_MIN_LEN, MAVLINK_MSG_ID_CHECK_IN_LEN, MAVLINK_MSG_ID_CHECK_IN_CRC);
#else
    mavlink_check_in_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_IN, (const char *)&packet, MAVLINK_MSG_ID_CHECK_IN_MIN_LEN, MAVLINK_MSG_ID_CHECK_IN_LEN, MAVLINK_MSG_ID_CHECK_IN_CRC);
#endif
}

/**
 * @brief Send a check_in message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_check_in_send_struct(mavlink_channel_t chan, const mavlink_check_in_t* check_in)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_check_in_send(chan, check_in->boot_id, check_in->msg_seq, check_in->time_ms, check_in->ttl_ms);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_IN, (const char *)check_in, MAVLINK_MSG_ID_CHECK_IN_MIN_LEN, MAVLINK_MSG_ID_CHECK_IN_LEN, MAVLINK_MSG_ID_CHECK_IN_CRC);
#endif
}

#if MAVLINK_MSG_ID_CHECK_IN_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_check_in_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_IN, buf, MAVLINK_MSG_ID_CHECK_IN_MIN_LEN, MAVLINK_MSG_ID_CHECK_IN_LEN, MAVLINK_MSG_ID_CHECK_IN_CRC);
#else
    mavlink_check_in_t *packet = (mavlink_check_in_t *)msgbuf;
    packet->time_ms = time_ms;
    packet->boot_id = boot_id;
    packet->msg_seq = msg_seq;
    packet->ttl_ms = ttl_ms;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_IN, (const char *)packet, MAVLINK_MSG_ID_CHECK_IN_MIN_LEN, MAVLINK_MSG_ID_CHECK_IN_LEN, MAVLINK_MSG_ID_CHECK_IN_CRC);
#endif
}
#endif

#endif

// MESSAGE CHECK_IN UNPACKING


/**
 * @brief Get field boot_id from check_in message
 *
 * @return  Random ID generated on process start, identifies sender instance.
 */
static inline uint32_t mavlink_msg_check_in_get_boot_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field msg_seq from check_in message
 *
 * @return  Monotonic sequence counter per sender.
 */
static inline uint32_t mavlink_msg_check_in_get_msg_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field time_ms from check_in message
 *
 * @return [ms] Sender timestamp in milliseconds since epoch.
 */
static inline uint64_t mavlink_msg_check_in_get_time_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field ttl_ms from check_in message
 *
 * @return [ms] Time-to-live validity window in milliseconds.
 */
static inline uint32_t mavlink_msg_check_in_get_ttl_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Decode a check_in message into a struct
 *
 * @param msg The message to decode
 * @param check_in C-struct to decode the message contents into
 */
static inline void mavlink_msg_check_in_decode(const mavlink_message_t* msg, mavlink_check_in_t* check_in)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    check_in->time_ms = mavlink_msg_check_in_get_time_ms(msg);
    check_in->boot_id = mavlink_msg_check_in_get_boot_id(msg);
    check_in->msg_seq = mavlink_msg_check_in_get_msg_seq(msg);
    check_in->ttl_ms = mavlink_msg_check_in_get_ttl_ms(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CHECK_IN_LEN? msg->len : MAVLINK_MSG_ID_CHECK_IN_LEN;
        memset(check_in, 0, MAVLINK_MSG_ID_CHECK_IN_LEN);
    memcpy(check_in, _MAV_PAYLOAD(msg), len);
#endif
}
