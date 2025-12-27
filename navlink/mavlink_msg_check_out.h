#pragma once
// MESSAGE CHECK_OUT PACKING

#define MAVLINK_MSG_ID_CHECK_OUT 25003


typedef struct __mavlink_check_out_t {
 uint64_t time_ms; /*< [ms] Sender timestamp in milliseconds since epoch.*/
 uint32_t boot_id; /*<  Random ID generated on process start, identifies sender instance.*/
 uint32_t msg_seq; /*<  Monotonic sequence counter per sender.*/
 uint32_t ttl_ms; /*< [ms] Time-to-live validity window in milliseconds.*/
 float lat; /*<  Latitude in degrees.*/
 float lng; /*<  Longitude in degrees.*/
 float alt; /*<  Altitude in meters.*/
} mavlink_check_out_t;

#define MAVLINK_MSG_ID_CHECK_OUT_LEN 32
#define MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN 32
#define MAVLINK_MSG_ID_25003_LEN 32
#define MAVLINK_MSG_ID_25003_MIN_LEN 32

#define MAVLINK_MSG_ID_CHECK_OUT_CRC 83
#define MAVLINK_MSG_ID_25003_CRC 83



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CHECK_OUT { \
    25003, \
    "CHECK_OUT", \
    7, \
    {  { "boot_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_check_out_t, boot_id) }, \
         { "msg_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_check_out_t, msg_seq) }, \
         { "time_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_check_out_t, time_ms) }, \
         { "ttl_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_check_out_t, ttl_ms) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_check_out_t, lat) }, \
         { "lng", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_check_out_t, lng) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_check_out_t, alt) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CHECK_OUT { \
    "CHECK_OUT", \
    7, \
    {  { "boot_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_check_out_t, boot_id) }, \
         { "msg_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_check_out_t, msg_seq) }, \
         { "time_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_check_out_t, time_ms) }, \
         { "ttl_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_check_out_t, ttl_ms) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_check_out_t, lat) }, \
         { "lng", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_check_out_t, lng) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_check_out_t, alt) }, \
         } \
}
#endif

/**
 * @brief Pack a check_out message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param lat  Latitude in degrees.
 * @param lng  Longitude in degrees.
 * @param alt  Altitude in meters.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_check_out_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, float lat, float lng, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHECK_OUT_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_float(buf, 20, lat);
    _mav_put_float(buf, 24, lng);
    _mav_put_float(buf, 28, alt);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHECK_OUT_LEN);
#else
    mavlink_check_out_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.lat = lat;
    packet.lng = lng;
    packet.alt = alt;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHECK_OUT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CHECK_OUT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN, MAVLINK_MSG_ID_CHECK_OUT_CRC);
}

/**
 * @brief Pack a check_out message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param lat  Latitude in degrees.
 * @param lng  Longitude in degrees.
 * @param alt  Altitude in meters.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_check_out_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, float lat, float lng, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHECK_OUT_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_float(buf, 20, lat);
    _mav_put_float(buf, 24, lng);
    _mav_put_float(buf, 28, alt);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHECK_OUT_LEN);
#else
    mavlink_check_out_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.lat = lat;
    packet.lng = lng;
    packet.alt = alt;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHECK_OUT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CHECK_OUT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN, MAVLINK_MSG_ID_CHECK_OUT_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN);
#endif
}

/**
 * @brief Pack a check_out message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param lat  Latitude in degrees.
 * @param lng  Longitude in degrees.
 * @param alt  Altitude in meters.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_check_out_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t boot_id,uint32_t msg_seq,uint64_t time_ms,uint32_t ttl_ms,float lat,float lng,float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHECK_OUT_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_float(buf, 20, lat);
    _mav_put_float(buf, 24, lng);
    _mav_put_float(buf, 28, alt);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHECK_OUT_LEN);
#else
    mavlink_check_out_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.lat = lat;
    packet.lng = lng;
    packet.alt = alt;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHECK_OUT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CHECK_OUT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN, MAVLINK_MSG_ID_CHECK_OUT_CRC);
}

/**
 * @brief Encode a check_out struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param check_out C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_check_out_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_check_out_t* check_out)
{
    return mavlink_msg_check_out_pack(system_id, component_id, msg, check_out->boot_id, check_out->msg_seq, check_out->time_ms, check_out->ttl_ms, check_out->lat, check_out->lng, check_out->alt);
}

/**
 * @brief Encode a check_out struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param check_out C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_check_out_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_check_out_t* check_out)
{
    return mavlink_msg_check_out_pack_chan(system_id, component_id, chan, msg, check_out->boot_id, check_out->msg_seq, check_out->time_ms, check_out->ttl_ms, check_out->lat, check_out->lng, check_out->alt);
}

/**
 * @brief Encode a check_out struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param check_out C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_check_out_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_check_out_t* check_out)
{
    return mavlink_msg_check_out_pack_status(system_id, component_id, _status, msg,  check_out->boot_id, check_out->msg_seq, check_out->time_ms, check_out->ttl_ms, check_out->lat, check_out->lng, check_out->alt);
}

/**
 * @brief Send a check_out message
 * @param chan MAVLink channel to send the message
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param lat  Latitude in degrees.
 * @param lng  Longitude in degrees.
 * @param alt  Altitude in meters.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_check_out_send(mavlink_channel_t chan, uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, float lat, float lng, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHECK_OUT_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_float(buf, 20, lat);
    _mav_put_float(buf, 24, lng);
    _mav_put_float(buf, 28, alt);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_OUT, buf, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN, MAVLINK_MSG_ID_CHECK_OUT_CRC);
#else
    mavlink_check_out_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.lat = lat;
    packet.lng = lng;
    packet.alt = alt;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_OUT, (const char *)&packet, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN, MAVLINK_MSG_ID_CHECK_OUT_CRC);
#endif
}

/**
 * @brief Send a check_out message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_check_out_send_struct(mavlink_channel_t chan, const mavlink_check_out_t* check_out)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_check_out_send(chan, check_out->boot_id, check_out->msg_seq, check_out->time_ms, check_out->ttl_ms, check_out->lat, check_out->lng, check_out->alt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_OUT, (const char *)check_out, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN, MAVLINK_MSG_ID_CHECK_OUT_CRC);
#endif
}

#if MAVLINK_MSG_ID_CHECK_OUT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_check_out_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, float lat, float lng, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_float(buf, 20, lat);
    _mav_put_float(buf, 24, lng);
    _mav_put_float(buf, 28, alt);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_OUT, buf, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN, MAVLINK_MSG_ID_CHECK_OUT_CRC);
#else
    mavlink_check_out_t *packet = (mavlink_check_out_t *)msgbuf;
    packet->time_ms = time_ms;
    packet->boot_id = boot_id;
    packet->msg_seq = msg_seq;
    packet->ttl_ms = ttl_ms;
    packet->lat = lat;
    packet->lng = lng;
    packet->alt = alt;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_OUT, (const char *)packet, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN, MAVLINK_MSG_ID_CHECK_OUT_CRC);
#endif
}
#endif

#endif

// MESSAGE CHECK_OUT UNPACKING


/**
 * @brief Get field boot_id from check_out message
 *
 * @return  Random ID generated on process start, identifies sender instance.
 */
static inline uint32_t mavlink_msg_check_out_get_boot_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field msg_seq from check_out message
 *
 * @return  Monotonic sequence counter per sender.
 */
static inline uint32_t mavlink_msg_check_out_get_msg_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field time_ms from check_out message
 *
 * @return [ms] Sender timestamp in milliseconds since epoch.
 */
static inline uint64_t mavlink_msg_check_out_get_time_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field ttl_ms from check_out message
 *
 * @return [ms] Time-to-live validity window in milliseconds.
 */
static inline uint32_t mavlink_msg_check_out_get_ttl_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field lat from check_out message
 *
 * @return  Latitude in degrees.
 */
static inline float mavlink_msg_check_out_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field lng from check_out message
 *
 * @return  Longitude in degrees.
 */
static inline float mavlink_msg_check_out_get_lng(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field alt from check_out message
 *
 * @return  Altitude in meters.
 */
static inline float mavlink_msg_check_out_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Decode a check_out message into a struct
 *
 * @param msg The message to decode
 * @param check_out C-struct to decode the message contents into
 */
static inline void mavlink_msg_check_out_decode(const mavlink_message_t* msg, mavlink_check_out_t* check_out)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    check_out->time_ms = mavlink_msg_check_out_get_time_ms(msg);
    check_out->boot_id = mavlink_msg_check_out_get_boot_id(msg);
    check_out->msg_seq = mavlink_msg_check_out_get_msg_seq(msg);
    check_out->ttl_ms = mavlink_msg_check_out_get_ttl_ms(msg);
    check_out->lat = mavlink_msg_check_out_get_lat(msg);
    check_out->lng = mavlink_msg_check_out_get_lng(msg);
    check_out->alt = mavlink_msg_check_out_get_alt(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CHECK_OUT_LEN? msg->len : MAVLINK_MSG_ID_CHECK_OUT_LEN;
        memset(check_out, 0, MAVLINK_MSG_ID_CHECK_OUT_LEN);
    memcpy(check_out, _MAV_PAYLOAD(msg), len);
#endif
}
