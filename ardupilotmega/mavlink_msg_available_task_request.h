#pragma once
// MESSAGE AVAILABLE_TASK_REQUEST PACKING

#define MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST 25104


typedef struct __mavlink_available_task_request_t {
 float lat[5]; /*<  */
 float lng[5]; /*<  */
 float alt[5]; /*<  */
 uint16_t task_id[5]; /*<  */
 uint8_t sid; /*<  */
 uint8_t count; /*<  */
 uint8_t task_type[5]; /*<  */
} mavlink_available_task_request_t;

#define MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN 77
#define MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_MIN_LEN 77
#define MAVLINK_MSG_ID_25104_LEN 77
#define MAVLINK_MSG_ID_25104_MIN_LEN 77

#define MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_CRC 254
#define MAVLINK_MSG_ID_25104_CRC 254

#define MAVLINK_MSG_AVAILABLE_TASK_REQUEST_FIELD_LAT_LEN 5
#define MAVLINK_MSG_AVAILABLE_TASK_REQUEST_FIELD_LNG_LEN 5
#define MAVLINK_MSG_AVAILABLE_TASK_REQUEST_FIELD_ALT_LEN 5
#define MAVLINK_MSG_AVAILABLE_TASK_REQUEST_FIELD_TASK_ID_LEN 5
#define MAVLINK_MSG_AVAILABLE_TASK_REQUEST_FIELD_TASK_TYPE_LEN 5

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AVAILABLE_TASK_REQUEST { \
    25104, \
    "AVAILABLE_TASK_REQUEST", \
    7, \
    {  { "sid", NULL, MAVLINK_TYPE_UINT8_T, 0, 70, offsetof(mavlink_available_task_request_t, sid) }, \
         { "count", NULL, MAVLINK_TYPE_UINT8_T, 0, 71, offsetof(mavlink_available_task_request_t, count) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 5, 60, offsetof(mavlink_available_task_request_t, task_id) }, \
         { "task_type", NULL, MAVLINK_TYPE_UINT8_T, 5, 72, offsetof(mavlink_available_task_request_t, task_type) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 5, 0, offsetof(mavlink_available_task_request_t, lat) }, \
         { "lng", NULL, MAVLINK_TYPE_FLOAT, 5, 20, offsetof(mavlink_available_task_request_t, lng) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 5, 40, offsetof(mavlink_available_task_request_t, alt) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AVAILABLE_TASK_REQUEST { \
    "AVAILABLE_TASK_REQUEST", \
    7, \
    {  { "sid", NULL, MAVLINK_TYPE_UINT8_T, 0, 70, offsetof(mavlink_available_task_request_t, sid) }, \
         { "count", NULL, MAVLINK_TYPE_UINT8_T, 0, 71, offsetof(mavlink_available_task_request_t, count) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 5, 60, offsetof(mavlink_available_task_request_t, task_id) }, \
         { "task_type", NULL, MAVLINK_TYPE_UINT8_T, 5, 72, offsetof(mavlink_available_task_request_t, task_type) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 5, 0, offsetof(mavlink_available_task_request_t, lat) }, \
         { "lng", NULL, MAVLINK_TYPE_FLOAT, 5, 20, offsetof(mavlink_available_task_request_t, lng) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 5, 40, offsetof(mavlink_available_task_request_t, alt) }, \
         } \
}
#endif

/**
 * @brief Pack a available_task_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sid  
 * @param count  
 * @param task_id  
 * @param task_type  
 * @param lat  
 * @param lng  
 * @param alt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_available_task_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t sid, uint8_t count, const uint16_t *task_id, const uint8_t *task_type, const float *lat, const float *lng, const float *alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN];
    _mav_put_uint8_t(buf, 70, sid);
    _mav_put_uint8_t(buf, 71, count);
    _mav_put_float_array(buf, 0, lat, 5);
    _mav_put_float_array(buf, 20, lng, 5);
    _mav_put_float_array(buf, 40, alt, 5);
    _mav_put_uint16_t_array(buf, 60, task_id, 5);
    _mav_put_uint8_t_array(buf, 72, task_type, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN);
#else
    mavlink_available_task_request_t packet;
    packet.sid = sid;
    packet.count = count;
    mav_array_assign_float(packet.lat, lat, 5);
    mav_array_assign_float(packet.lng, lng, 5);
    mav_array_assign_float(packet.alt, alt, 5);
    mav_array_assign_uint16_t(packet.task_id, task_id, 5);
    mav_array_assign_uint8_t(packet.task_type, task_type, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_CRC);
}

/**
 * @brief Pack a available_task_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param sid  
 * @param count  
 * @param task_id  
 * @param task_type  
 * @param lat  
 * @param lng  
 * @param alt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_available_task_request_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t sid, uint8_t count, const uint16_t *task_id, const uint8_t *task_type, const float *lat, const float *lng, const float *alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN];
    _mav_put_uint8_t(buf, 70, sid);
    _mav_put_uint8_t(buf, 71, count);
    _mav_put_float_array(buf, 0, lat, 5);
    _mav_put_float_array(buf, 20, lng, 5);
    _mav_put_float_array(buf, 40, alt, 5);
    _mav_put_uint16_t_array(buf, 60, task_id, 5);
    _mav_put_uint8_t_array(buf, 72, task_type, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN);
#else
    mavlink_available_task_request_t packet;
    packet.sid = sid;
    packet.count = count;
    mav_array_memcpy(packet.lat, lat, sizeof(float)*5);
    mav_array_memcpy(packet.lng, lng, sizeof(float)*5);
    mav_array_memcpy(packet.alt, alt, sizeof(float)*5);
    mav_array_memcpy(packet.task_id, task_id, sizeof(uint16_t)*5);
    mav_array_memcpy(packet.task_type, task_type, sizeof(uint8_t)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN);
#endif
}

/**
 * @brief Pack a available_task_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sid  
 * @param count  
 * @param task_id  
 * @param task_type  
 * @param lat  
 * @param lng  
 * @param alt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_available_task_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t sid,uint8_t count,const uint16_t *task_id,const uint8_t *task_type,const float *lat,const float *lng,const float *alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN];
    _mav_put_uint8_t(buf, 70, sid);
    _mav_put_uint8_t(buf, 71, count);
    _mav_put_float_array(buf, 0, lat, 5);
    _mav_put_float_array(buf, 20, lng, 5);
    _mav_put_float_array(buf, 40, alt, 5);
    _mav_put_uint16_t_array(buf, 60, task_id, 5);
    _mav_put_uint8_t_array(buf, 72, task_type, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN);
#else
    mavlink_available_task_request_t packet;
    packet.sid = sid;
    packet.count = count;
    mav_array_assign_float(packet.lat, lat, 5);
    mav_array_assign_float(packet.lng, lng, 5);
    mav_array_assign_float(packet.alt, alt, 5);
    mav_array_assign_uint16_t(packet.task_id, task_id, 5);
    mav_array_assign_uint8_t(packet.task_type, task_type, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_CRC);
}

/**
 * @brief Encode a available_task_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param available_task_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_available_task_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_available_task_request_t* available_task_request)
{
    return mavlink_msg_available_task_request_pack(system_id, component_id, msg, available_task_request->sid, available_task_request->count, available_task_request->task_id, available_task_request->task_type, available_task_request->lat, available_task_request->lng, available_task_request->alt);
}

/**
 * @brief Encode a available_task_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param available_task_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_available_task_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_available_task_request_t* available_task_request)
{
    return mavlink_msg_available_task_request_pack_chan(system_id, component_id, chan, msg, available_task_request->sid, available_task_request->count, available_task_request->task_id, available_task_request->task_type, available_task_request->lat, available_task_request->lng, available_task_request->alt);
}

/**
 * @brief Encode a available_task_request struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param available_task_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_available_task_request_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_available_task_request_t* available_task_request)
{
    return mavlink_msg_available_task_request_pack_status(system_id, component_id, _status, msg,  available_task_request->sid, available_task_request->count, available_task_request->task_id, available_task_request->task_type, available_task_request->lat, available_task_request->lng, available_task_request->alt);
}

/**
 * @brief Send a available_task_request message
 * @param chan MAVLink channel to send the message
 *
 * @param sid  
 * @param count  
 * @param task_id  
 * @param task_type  
 * @param lat  
 * @param lng  
 * @param alt  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_available_task_request_send(mavlink_channel_t chan, uint8_t sid, uint8_t count, const uint16_t *task_id, const uint8_t *task_type, const float *lat, const float *lng, const float *alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN];
    _mav_put_uint8_t(buf, 70, sid);
    _mav_put_uint8_t(buf, 71, count);
    _mav_put_float_array(buf, 0, lat, 5);
    _mav_put_float_array(buf, 20, lng, 5);
    _mav_put_float_array(buf, 40, alt, 5);
    _mav_put_uint16_t_array(buf, 60, task_id, 5);
    _mav_put_uint8_t_array(buf, 72, task_type, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST, buf, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_CRC);
#else
    mavlink_available_task_request_t packet;
    packet.sid = sid;
    packet.count = count;
    mav_array_assign_float(packet.lat, lat, 5);
    mav_array_assign_float(packet.lng, lng, 5);
    mav_array_assign_float(packet.alt, alt, 5);
    mav_array_assign_uint16_t(packet.task_id, task_id, 5);
    mav_array_assign_uint8_t(packet.task_type, task_type, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_CRC);
#endif
}

/**
 * @brief Send a available_task_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_available_task_request_send_struct(mavlink_channel_t chan, const mavlink_available_task_request_t* available_task_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_available_task_request_send(chan, available_task_request->sid, available_task_request->count, available_task_request->task_id, available_task_request->task_type, available_task_request->lat, available_task_request->lng, available_task_request->alt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST, (const char *)available_task_request, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_available_task_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t sid, uint8_t count, const uint16_t *task_id, const uint8_t *task_type, const float *lat, const float *lng, const float *alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 70, sid);
    _mav_put_uint8_t(buf, 71, count);
    _mav_put_float_array(buf, 0, lat, 5);
    _mav_put_float_array(buf, 20, lng, 5);
    _mav_put_float_array(buf, 40, alt, 5);
    _mav_put_uint16_t_array(buf, 60, task_id, 5);
    _mav_put_uint8_t_array(buf, 72, task_type, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST, buf, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_CRC);
#else
    mavlink_available_task_request_t *packet = (mavlink_available_task_request_t *)msgbuf;
    packet->sid = sid;
    packet->count = count;
    mav_array_assign_float(packet->lat, lat, 5);
    mav_array_assign_float(packet->lng, lng, 5);
    mav_array_assign_float(packet->alt, alt, 5);
    mav_array_assign_uint16_t(packet->task_id, task_id, 5);
    mav_array_assign_uint8_t(packet->task_type, task_type, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST, (const char *)packet, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_MIN_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE AVAILABLE_TASK_REQUEST UNPACKING


/**
 * @brief Get field sid from available_task_request message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_available_task_request_get_sid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  70);
}

/**
 * @brief Get field count from available_task_request message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_available_task_request_get_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  71);
}

/**
 * @brief Get field task_id from available_task_request message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_available_task_request_get_task_id(const mavlink_message_t* msg, uint16_t *task_id)
{
    return _MAV_RETURN_uint16_t_array(msg, task_id, 5,  60);
}

/**
 * @brief Get field task_type from available_task_request message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_available_task_request_get_task_type(const mavlink_message_t* msg, uint8_t *task_type)
{
    return _MAV_RETURN_uint8_t_array(msg, task_type, 5,  72);
}

/**
 * @brief Get field lat from available_task_request message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_available_task_request_get_lat(const mavlink_message_t* msg, float *lat)
{
    return _MAV_RETURN_float_array(msg, lat, 5,  0);
}

/**
 * @brief Get field lng from available_task_request message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_available_task_request_get_lng(const mavlink_message_t* msg, float *lng)
{
    return _MAV_RETURN_float_array(msg, lng, 5,  20);
}

/**
 * @brief Get field alt from available_task_request message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_available_task_request_get_alt(const mavlink_message_t* msg, float *alt)
{
    return _MAV_RETURN_float_array(msg, alt, 5,  40);
}

/**
 * @brief Decode a available_task_request message into a struct
 *
 * @param msg The message to decode
 * @param available_task_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_available_task_request_decode(const mavlink_message_t* msg, mavlink_available_task_request_t* available_task_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_available_task_request_get_lat(msg, available_task_request->lat);
    mavlink_msg_available_task_request_get_lng(msg, available_task_request->lng);
    mavlink_msg_available_task_request_get_alt(msg, available_task_request->alt);
    mavlink_msg_available_task_request_get_task_id(msg, available_task_request->task_id);
    available_task_request->sid = mavlink_msg_available_task_request_get_sid(msg);
    available_task_request->count = mavlink_msg_available_task_request_get_count(msg);
    mavlink_msg_available_task_request_get_task_type(msg, available_task_request->task_type);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN;
        memset(available_task_request, 0, MAVLINK_MSG_ID_AVAILABLE_TASK_REQUEST_LEN);
    memcpy(available_task_request, _MAV_PAYLOAD(msg), len);
#endif
}
