#pragma once
// MESSAGE CHECK_OUT PACKING

#define MAVLINK_MSG_ID_CHECK_OUT 25003


typedef struct __mavlink_check_out_t {
 float lat; /*<  */
 float lng; /*<  */
 float alt; /*<  */
 uint8_t sid; /*<  */
} mavlink_check_out_t;

#define MAVLINK_MSG_ID_CHECK_OUT_LEN 13
#define MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN 13
#define MAVLINK_MSG_ID_25003_LEN 13
#define MAVLINK_MSG_ID_25003_MIN_LEN 13

#define MAVLINK_MSG_ID_CHECK_OUT_CRC 178
#define MAVLINK_MSG_ID_25003_CRC 178



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CHECK_OUT { \
    25003, \
    "CHECK_OUT", \
    4, \
    {  { "sid", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_check_out_t, sid) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_check_out_t, lat) }, \
         { "lng", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_check_out_t, lng) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_check_out_t, alt) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CHECK_OUT { \
    "CHECK_OUT", \
    4, \
    {  { "sid", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_check_out_t, sid) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_check_out_t, lat) }, \
         { "lng", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_check_out_t, lng) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_check_out_t, alt) }, \
         } \
}
#endif

/**
 * @brief Pack a check_out message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sid  
 * @param lat  
 * @param lng  
 * @param alt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_check_out_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t sid, float lat, float lng, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHECK_OUT_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lng);
    _mav_put_float(buf, 8, alt);
    _mav_put_uint8_t(buf, 12, sid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHECK_OUT_LEN);
#else
    mavlink_check_out_t packet;
    packet.lat = lat;
    packet.lng = lng;
    packet.alt = alt;
    packet.sid = sid;

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
 * @param sid  
 * @param lat  
 * @param lng  
 * @param alt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_check_out_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t sid, float lat, float lng, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHECK_OUT_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lng);
    _mav_put_float(buf, 8, alt);
    _mav_put_uint8_t(buf, 12, sid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHECK_OUT_LEN);
#else
    mavlink_check_out_t packet;
    packet.lat = lat;
    packet.lng = lng;
    packet.alt = alt;
    packet.sid = sid;

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
 * @param sid  
 * @param lat  
 * @param lng  
 * @param alt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_check_out_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t sid,float lat,float lng,float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHECK_OUT_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lng);
    _mav_put_float(buf, 8, alt);
    _mav_put_uint8_t(buf, 12, sid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHECK_OUT_LEN);
#else
    mavlink_check_out_t packet;
    packet.lat = lat;
    packet.lng = lng;
    packet.alt = alt;
    packet.sid = sid;

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
    return mavlink_msg_check_out_pack(system_id, component_id, msg, check_out->sid, check_out->lat, check_out->lng, check_out->alt);
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
    return mavlink_msg_check_out_pack_chan(system_id, component_id, chan, msg, check_out->sid, check_out->lat, check_out->lng, check_out->alt);
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
    return mavlink_msg_check_out_pack_status(system_id, component_id, _status, msg,  check_out->sid, check_out->lat, check_out->lng, check_out->alt);
}

/**
 * @brief Send a check_out message
 * @param chan MAVLink channel to send the message
 *
 * @param sid  
 * @param lat  
 * @param lng  
 * @param alt  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_check_out_send(mavlink_channel_t chan, uint8_t sid, float lat, float lng, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHECK_OUT_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lng);
    _mav_put_float(buf, 8, alt);
    _mav_put_uint8_t(buf, 12, sid);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_OUT, buf, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN, MAVLINK_MSG_ID_CHECK_OUT_CRC);
#else
    mavlink_check_out_t packet;
    packet.lat = lat;
    packet.lng = lng;
    packet.alt = alt;
    packet.sid = sid;

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
    mavlink_msg_check_out_send(chan, check_out->sid, check_out->lat, check_out->lng, check_out->alt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_OUT, (const char *)check_out, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN, MAVLINK_MSG_ID_CHECK_OUT_CRC);
#endif
}

#if MAVLINK_MSG_ID_CHECK_OUT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_check_out_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t sid, float lat, float lng, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lng);
    _mav_put_float(buf, 8, alt);
    _mav_put_uint8_t(buf, 12, sid);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_OUT, buf, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN, MAVLINK_MSG_ID_CHECK_OUT_CRC);
#else
    mavlink_check_out_t *packet = (mavlink_check_out_t *)msgbuf;
    packet->lat = lat;
    packet->lng = lng;
    packet->alt = alt;
    packet->sid = sid;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHECK_OUT, (const char *)packet, MAVLINK_MSG_ID_CHECK_OUT_MIN_LEN, MAVLINK_MSG_ID_CHECK_OUT_LEN, MAVLINK_MSG_ID_CHECK_OUT_CRC);
#endif
}
#endif

#endif

// MESSAGE CHECK_OUT UNPACKING


/**
 * @brief Get field sid from check_out message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_check_out_get_sid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field lat from check_out message
 *
 * @return  
 */
static inline float mavlink_msg_check_out_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field lng from check_out message
 *
 * @return  
 */
static inline float mavlink_msg_check_out_get_lng(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field alt from check_out message
 *
 * @return  
 */
static inline float mavlink_msg_check_out_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
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
    check_out->lat = mavlink_msg_check_out_get_lat(msg);
    check_out->lng = mavlink_msg_check_out_get_lng(msg);
    check_out->alt = mavlink_msg_check_out_get_alt(msg);
    check_out->sid = mavlink_msg_check_out_get_sid(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CHECK_OUT_LEN? msg->len : MAVLINK_MSG_ID_CHECK_OUT_LEN;
        memset(check_out, 0, MAVLINK_MSG_ID_CHECK_OUT_LEN);
    memcpy(check_out, _MAV_PAYLOAD(msg), len);
#endif
}
