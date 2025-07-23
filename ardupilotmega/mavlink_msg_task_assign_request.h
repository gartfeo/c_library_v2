#pragma once
// MESSAGE TASK_ASSIGN_REQUEST PACKING

#define MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST 25106


typedef struct __mavlink_task_assign_request_t {
 float lat; /*<  */
 float lng; /*<  */
 float alt; /*<  */
 uint16_t task_id; /*<  */
 uint8_t sid; /*<  */
 uint8_t rid; /*<  */
 uint8_t task_type; /*<  */
} mavlink_task_assign_request_t;

#define MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN 17
#define MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_MIN_LEN 17
#define MAVLINK_MSG_ID_25106_LEN 17
#define MAVLINK_MSG_ID_25106_MIN_LEN 17

#define MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_CRC 76
#define MAVLINK_MSG_ID_25106_CRC 76



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TASK_ASSIGN_REQUEST { \
    25106, \
    "TASK_ASSIGN_REQUEST", \
    7, \
    {  { "sid", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_task_assign_request_t, sid) }, \
         { "rid", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_task_assign_request_t, rid) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_task_assign_request_t, task_id) }, \
         { "task_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_task_assign_request_t, task_type) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_task_assign_request_t, lat) }, \
         { "lng", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_task_assign_request_t, lng) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_task_assign_request_t, alt) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TASK_ASSIGN_REQUEST { \
    "TASK_ASSIGN_REQUEST", \
    7, \
    {  { "sid", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_task_assign_request_t, sid) }, \
         { "rid", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_task_assign_request_t, rid) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_task_assign_request_t, task_id) }, \
         { "task_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_task_assign_request_t, task_type) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_task_assign_request_t, lat) }, \
         { "lng", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_task_assign_request_t, lng) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_task_assign_request_t, alt) }, \
         } \
}
#endif

/**
 * @brief Pack a task_assign_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sid  
 * @param rid  
 * @param task_id  
 * @param task_type  
 * @param lat  
 * @param lng  
 * @param alt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_assign_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t sid, uint8_t rid, uint16_t task_id, uint8_t task_type, float lat, float lng, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lng);
    _mav_put_float(buf, 8, alt);
    _mav_put_uint16_t(buf, 12, task_id);
    _mav_put_uint8_t(buf, 14, sid);
    _mav_put_uint8_t(buf, 15, rid);
    _mav_put_uint8_t(buf, 16, task_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN);
#else
    mavlink_task_assign_request_t packet;
    packet.lat = lat;
    packet.lng = lng;
    packet.alt = alt;
    packet.task_id = task_id;
    packet.sid = sid;
    packet.rid = rid;
    packet.task_type = task_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_CRC);
}

/**
 * @brief Pack a task_assign_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param sid  
 * @param rid  
 * @param task_id  
 * @param task_type  
 * @param lat  
 * @param lng  
 * @param alt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_assign_request_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t sid, uint8_t rid, uint16_t task_id, uint8_t task_type, float lat, float lng, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lng);
    _mav_put_float(buf, 8, alt);
    _mav_put_uint16_t(buf, 12, task_id);
    _mav_put_uint8_t(buf, 14, sid);
    _mav_put_uint8_t(buf, 15, rid);
    _mav_put_uint8_t(buf, 16, task_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN);
#else
    mavlink_task_assign_request_t packet;
    packet.lat = lat;
    packet.lng = lng;
    packet.alt = alt;
    packet.task_id = task_id;
    packet.sid = sid;
    packet.rid = rid;
    packet.task_type = task_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN);
#endif
}

/**
 * @brief Pack a task_assign_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sid  
 * @param rid  
 * @param task_id  
 * @param task_type  
 * @param lat  
 * @param lng  
 * @param alt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_task_assign_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t sid,uint8_t rid,uint16_t task_id,uint8_t task_type,float lat,float lng,float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lng);
    _mav_put_float(buf, 8, alt);
    _mav_put_uint16_t(buf, 12, task_id);
    _mav_put_uint8_t(buf, 14, sid);
    _mav_put_uint8_t(buf, 15, rid);
    _mav_put_uint8_t(buf, 16, task_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN);
#else
    mavlink_task_assign_request_t packet;
    packet.lat = lat;
    packet.lng = lng;
    packet.alt = alt;
    packet.task_id = task_id;
    packet.sid = sid;
    packet.rid = rid;
    packet.task_type = task_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_CRC);
}

/**
 * @brief Encode a task_assign_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param task_assign_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_assign_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_task_assign_request_t* task_assign_request)
{
    return mavlink_msg_task_assign_request_pack(system_id, component_id, msg, task_assign_request->sid, task_assign_request->rid, task_assign_request->task_id, task_assign_request->task_type, task_assign_request->lat, task_assign_request->lng, task_assign_request->alt);
}

/**
 * @brief Encode a task_assign_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param task_assign_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_assign_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_task_assign_request_t* task_assign_request)
{
    return mavlink_msg_task_assign_request_pack_chan(system_id, component_id, chan, msg, task_assign_request->sid, task_assign_request->rid, task_assign_request->task_id, task_assign_request->task_type, task_assign_request->lat, task_assign_request->lng, task_assign_request->alt);
}

/**
 * @brief Encode a task_assign_request struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param task_assign_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_task_assign_request_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_task_assign_request_t* task_assign_request)
{
    return mavlink_msg_task_assign_request_pack_status(system_id, component_id, _status, msg,  task_assign_request->sid, task_assign_request->rid, task_assign_request->task_id, task_assign_request->task_type, task_assign_request->lat, task_assign_request->lng, task_assign_request->alt);
}

/**
 * @brief Send a task_assign_request message
 * @param chan MAVLink channel to send the message
 *
 * @param sid  
 * @param rid  
 * @param task_id  
 * @param task_type  
 * @param lat  
 * @param lng  
 * @param alt  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_task_assign_request_send(mavlink_channel_t chan, uint8_t sid, uint8_t rid, uint16_t task_id, uint8_t task_type, float lat, float lng, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lng);
    _mav_put_float(buf, 8, alt);
    _mav_put_uint16_t(buf, 12, task_id);
    _mav_put_uint8_t(buf, 14, sid);
    _mav_put_uint8_t(buf, 15, rid);
    _mav_put_uint8_t(buf, 16, task_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST, buf, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_CRC);
#else
    mavlink_task_assign_request_t packet;
    packet.lat = lat;
    packet.lng = lng;
    packet.alt = alt;
    packet.task_id = task_id;
    packet.sid = sid;
    packet.rid = rid;
    packet.task_type = task_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_CRC);
#endif
}

/**
 * @brief Send a task_assign_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_task_assign_request_send_struct(mavlink_channel_t chan, const mavlink_task_assign_request_t* task_assign_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_task_assign_request_send(chan, task_assign_request->sid, task_assign_request->rid, task_assign_request->task_id, task_assign_request->task_type, task_assign_request->lat, task_assign_request->lng, task_assign_request->alt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST, (const char *)task_assign_request, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_task_assign_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t sid, uint8_t rid, uint16_t task_id, uint8_t task_type, float lat, float lng, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lng);
    _mav_put_float(buf, 8, alt);
    _mav_put_uint16_t(buf, 12, task_id);
    _mav_put_uint8_t(buf, 14, sid);
    _mav_put_uint8_t(buf, 15, rid);
    _mav_put_uint8_t(buf, 16, task_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST, buf, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_CRC);
#else
    mavlink_task_assign_request_t *packet = (mavlink_task_assign_request_t *)msgbuf;
    packet->lat = lat;
    packet->lng = lng;
    packet->alt = alt;
    packet->task_id = task_id;
    packet->sid = sid;
    packet->rid = rid;
    packet->task_type = task_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST, (const char *)packet, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_MIN_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE TASK_ASSIGN_REQUEST UNPACKING


/**
 * @brief Get field sid from task_assign_request message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_task_assign_request_get_sid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field rid from task_assign_request message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_task_assign_request_get_rid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Get field task_id from task_assign_request message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_task_assign_request_get_task_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field task_type from task_assign_request message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_task_assign_request_get_task_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field lat from task_assign_request message
 *
 * @return  
 */
static inline float mavlink_msg_task_assign_request_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field lng from task_assign_request message
 *
 * @return  
 */
static inline float mavlink_msg_task_assign_request_get_lng(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field alt from task_assign_request message
 *
 * @return  
 */
static inline float mavlink_msg_task_assign_request_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a task_assign_request message into a struct
 *
 * @param msg The message to decode
 * @param task_assign_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_task_assign_request_decode(const mavlink_message_t* msg, mavlink_task_assign_request_t* task_assign_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    task_assign_request->lat = mavlink_msg_task_assign_request_get_lat(msg);
    task_assign_request->lng = mavlink_msg_task_assign_request_get_lng(msg);
    task_assign_request->alt = mavlink_msg_task_assign_request_get_alt(msg);
    task_assign_request->task_id = mavlink_msg_task_assign_request_get_task_id(msg);
    task_assign_request->sid = mavlink_msg_task_assign_request_get_sid(msg);
    task_assign_request->rid = mavlink_msg_task_assign_request_get_rid(msg);
    task_assign_request->task_type = mavlink_msg_task_assign_request_get_task_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN;
        memset(task_assign_request, 0, MAVLINK_MSG_ID_TASK_ASSIGN_REQUEST_LEN);
    memcpy(task_assign_request, _MAV_PAYLOAD(msg), len);
#endif
}
