#pragma once
// MESSAGE SLOT_HEARTBEAT PACKING

#define MAVLINK_MSG_ID_SLOT_HEARTBEAT 25200


typedef struct __mavlink_slot_heartbeat_t {
 uint64_t time_ms; /*< [ms] Sender timestamp in milliseconds since epoch.*/
 uint32_t boot_id; /*<  Random ID generated on process start, identifies sender instance.*/
 uint32_t msg_seq; /*<  Monotonic sequence counter per sender.*/
 uint32_t ttl_ms; /*< [ms] Time-to-live validity window in milliseconds.*/
 uint8_t slot_id; /*<  Current slot ID claimed by this node.*/
 uint8_t state; /*<  Current node state.*/
} mavlink_slot_heartbeat_t;

#define MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN 22
#define MAVLINK_MSG_ID_SLOT_HEARTBEAT_MIN_LEN 22
#define MAVLINK_MSG_ID_25200_LEN 22
#define MAVLINK_MSG_ID_25200_MIN_LEN 22

#define MAVLINK_MSG_ID_SLOT_HEARTBEAT_CRC 202
#define MAVLINK_MSG_ID_25200_CRC 202



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SLOT_HEARTBEAT { \
    25200, \
    "SLOT_HEARTBEAT", \
    6, \
    {  { "boot_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_slot_heartbeat_t, boot_id) }, \
         { "msg_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_slot_heartbeat_t, msg_seq) }, \
         { "time_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_slot_heartbeat_t, time_ms) }, \
         { "ttl_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_slot_heartbeat_t, ttl_ms) }, \
         { "slot_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_slot_heartbeat_t, slot_id) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_slot_heartbeat_t, state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SLOT_HEARTBEAT { \
    "SLOT_HEARTBEAT", \
    6, \
    {  { "boot_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_slot_heartbeat_t, boot_id) }, \
         { "msg_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_slot_heartbeat_t, msg_seq) }, \
         { "time_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_slot_heartbeat_t, time_ms) }, \
         { "ttl_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_slot_heartbeat_t, ttl_ms) }, \
         { "slot_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_slot_heartbeat_t, slot_id) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_slot_heartbeat_t, state) }, \
         } \
}
#endif

/**
 * @brief Pack a slot_heartbeat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param slot_id  Current slot ID claimed by this node.
 * @param state  Current node state.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_slot_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint8_t slot_id, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint8_t(buf, 20, slot_id);
    _mav_put_uint8_t(buf, 21, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN);
#else
    mavlink_slot_heartbeat_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.slot_id = slot_id;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SLOT_HEARTBEAT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SLOT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_CRC);
}

/**
 * @brief Pack a slot_heartbeat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param slot_id  Current slot ID claimed by this node.
 * @param state  Current node state.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_slot_heartbeat_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint8_t slot_id, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint8_t(buf, 20, slot_id);
    _mav_put_uint8_t(buf, 21, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN);
#else
    mavlink_slot_heartbeat_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.slot_id = slot_id;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SLOT_HEARTBEAT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SLOT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SLOT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN);
#endif
}

/**
 * @brief Pack a slot_heartbeat message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param slot_id  Current slot ID claimed by this node.
 * @param state  Current node state.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_slot_heartbeat_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t boot_id,uint32_t msg_seq,uint64_t time_ms,uint32_t ttl_ms,uint8_t slot_id,uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint8_t(buf, 20, slot_id);
    _mav_put_uint8_t(buf, 21, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN);
#else
    mavlink_slot_heartbeat_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.slot_id = slot_id;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SLOT_HEARTBEAT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SLOT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_CRC);
}

/**
 * @brief Encode a slot_heartbeat struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param slot_heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_slot_heartbeat_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_slot_heartbeat_t* slot_heartbeat)
{
    return mavlink_msg_slot_heartbeat_pack(system_id, component_id, msg, slot_heartbeat->boot_id, slot_heartbeat->msg_seq, slot_heartbeat->time_ms, slot_heartbeat->ttl_ms, slot_heartbeat->slot_id, slot_heartbeat->state);
}

/**
 * @brief Encode a slot_heartbeat struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param slot_heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_slot_heartbeat_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_slot_heartbeat_t* slot_heartbeat)
{
    return mavlink_msg_slot_heartbeat_pack_chan(system_id, component_id, chan, msg, slot_heartbeat->boot_id, slot_heartbeat->msg_seq, slot_heartbeat->time_ms, slot_heartbeat->ttl_ms, slot_heartbeat->slot_id, slot_heartbeat->state);
}

/**
 * @brief Encode a slot_heartbeat struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param slot_heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_slot_heartbeat_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_slot_heartbeat_t* slot_heartbeat)
{
    return mavlink_msg_slot_heartbeat_pack_status(system_id, component_id, _status, msg,  slot_heartbeat->boot_id, slot_heartbeat->msg_seq, slot_heartbeat->time_ms, slot_heartbeat->ttl_ms, slot_heartbeat->slot_id, slot_heartbeat->state);
}

/**
 * @brief Send a slot_heartbeat message
 * @param chan MAVLink channel to send the message
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param slot_id  Current slot ID claimed by this node.
 * @param state  Current node state.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_slot_heartbeat_send(mavlink_channel_t chan, uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint8_t slot_id, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint8_t(buf, 20, slot_id);
    _mav_put_uint8_t(buf, 21, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLOT_HEARTBEAT, buf, MAVLINK_MSG_ID_SLOT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_CRC);
#else
    mavlink_slot_heartbeat_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.slot_id = slot_id;
    packet.state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLOT_HEARTBEAT, (const char *)&packet, MAVLINK_MSG_ID_SLOT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_CRC);
#endif
}

/**
 * @brief Send a slot_heartbeat message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_slot_heartbeat_send_struct(mavlink_channel_t chan, const mavlink_slot_heartbeat_t* slot_heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_slot_heartbeat_send(chan, slot_heartbeat->boot_id, slot_heartbeat->msg_seq, slot_heartbeat->time_ms, slot_heartbeat->ttl_ms, slot_heartbeat->slot_id, slot_heartbeat->state);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLOT_HEARTBEAT, (const char *)slot_heartbeat, MAVLINK_MSG_ID_SLOT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_CRC);
#endif
}

#if MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_slot_heartbeat_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint8_t slot_id, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint8_t(buf, 20, slot_id);
    _mav_put_uint8_t(buf, 21, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLOT_HEARTBEAT, buf, MAVLINK_MSG_ID_SLOT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_CRC);
#else
    mavlink_slot_heartbeat_t *packet = (mavlink_slot_heartbeat_t *)msgbuf;
    packet->time_ms = time_ms;
    packet->boot_id = boot_id;
    packet->msg_seq = msg_seq;
    packet->ttl_ms = ttl_ms;
    packet->slot_id = slot_id;
    packet->state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLOT_HEARTBEAT, (const char *)packet, MAVLINK_MSG_ID_SLOT_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN, MAVLINK_MSG_ID_SLOT_HEARTBEAT_CRC);
#endif
}
#endif

#endif

// MESSAGE SLOT_HEARTBEAT UNPACKING


/**
 * @brief Get field boot_id from slot_heartbeat message
 *
 * @return  Random ID generated on process start, identifies sender instance.
 */
static inline uint32_t mavlink_msg_slot_heartbeat_get_boot_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field msg_seq from slot_heartbeat message
 *
 * @return  Monotonic sequence counter per sender.
 */
static inline uint32_t mavlink_msg_slot_heartbeat_get_msg_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field time_ms from slot_heartbeat message
 *
 * @return [ms] Sender timestamp in milliseconds since epoch.
 */
static inline uint64_t mavlink_msg_slot_heartbeat_get_time_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field ttl_ms from slot_heartbeat message
 *
 * @return [ms] Time-to-live validity window in milliseconds.
 */
static inline uint32_t mavlink_msg_slot_heartbeat_get_ttl_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field slot_id from slot_heartbeat message
 *
 * @return  Current slot ID claimed by this node.
 */
static inline uint8_t mavlink_msg_slot_heartbeat_get_slot_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field state from slot_heartbeat message
 *
 * @return  Current node state.
 */
static inline uint8_t mavlink_msg_slot_heartbeat_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Decode a slot_heartbeat message into a struct
 *
 * @param msg The message to decode
 * @param slot_heartbeat C-struct to decode the message contents into
 */
static inline void mavlink_msg_slot_heartbeat_decode(const mavlink_message_t* msg, mavlink_slot_heartbeat_t* slot_heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    slot_heartbeat->time_ms = mavlink_msg_slot_heartbeat_get_time_ms(msg);
    slot_heartbeat->boot_id = mavlink_msg_slot_heartbeat_get_boot_id(msg);
    slot_heartbeat->msg_seq = mavlink_msg_slot_heartbeat_get_msg_seq(msg);
    slot_heartbeat->ttl_ms = mavlink_msg_slot_heartbeat_get_ttl_ms(msg);
    slot_heartbeat->slot_id = mavlink_msg_slot_heartbeat_get_slot_id(msg);
    slot_heartbeat->state = mavlink_msg_slot_heartbeat_get_state(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN? msg->len : MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN;
        memset(slot_heartbeat, 0, MAVLINK_MSG_ID_SLOT_HEARTBEAT_LEN);
    memcpy(slot_heartbeat, _MAV_PAYLOAD(msg), len);
#endif
}
