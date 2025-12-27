#pragma once
// MESSAGE SEARCH_STATUS PACKING

#define MAVLINK_MSG_ID_SEARCH_STATUS 25300


typedef struct __mavlink_search_status_t {
 uint64_t time_ms; /*< [ms] Sender timestamp in milliseconds since epoch.*/
 uint32_t boot_id; /*<  Random ID generated on process start, identifies sender instance.*/
 uint32_t msg_seq; /*<  Monotonic sequence counter per sender.*/
 uint32_t ttl_ms; /*< [ms] Time-to-live validity window in milliseconds.*/
 uint16_t area_id; /*<  Search area identifier.*/
 uint8_t status; /*<  Search status (0=NOT_STARTED, 1=IN_PROGRESS, 2=COMPLETED, 3=ABORTED).*/
 uint8_t coverage_pct; /*<  Percentage of area covered (0-100).*/
 uint8_t detections; /*<  Number of detections in this area.*/
} mavlink_search_status_t;

#define MAVLINK_MSG_ID_SEARCH_STATUS_LEN 25
#define MAVLINK_MSG_ID_SEARCH_STATUS_MIN_LEN 25
#define MAVLINK_MSG_ID_25300_LEN 25
#define MAVLINK_MSG_ID_25300_MIN_LEN 25

#define MAVLINK_MSG_ID_SEARCH_STATUS_CRC 236
#define MAVLINK_MSG_ID_25300_CRC 236



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SEARCH_STATUS { \
    25300, \
    "SEARCH_STATUS", \
    8, \
    {  { "boot_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_search_status_t, boot_id) }, \
         { "msg_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_search_status_t, msg_seq) }, \
         { "time_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_search_status_t, time_ms) }, \
         { "ttl_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_search_status_t, ttl_ms) }, \
         { "area_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_search_status_t, area_id) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_search_status_t, status) }, \
         { "coverage_pct", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_search_status_t, coverage_pct) }, \
         { "detections", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_search_status_t, detections) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SEARCH_STATUS { \
    "SEARCH_STATUS", \
    8, \
    {  { "boot_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_search_status_t, boot_id) }, \
         { "msg_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_search_status_t, msg_seq) }, \
         { "time_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_search_status_t, time_ms) }, \
         { "ttl_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_search_status_t, ttl_ms) }, \
         { "area_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_search_status_t, area_id) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_search_status_t, status) }, \
         { "coverage_pct", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_search_status_t, coverage_pct) }, \
         { "detections", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_search_status_t, detections) }, \
         } \
}
#endif

/**
 * @brief Pack a search_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param area_id  Search area identifier.
 * @param status  Search status (0=NOT_STARTED, 1=IN_PROGRESS, 2=COMPLETED, 3=ABORTED).
 * @param coverage_pct  Percentage of area covered (0-100).
 * @param detections  Number of detections in this area.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_search_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint16_t area_id, uint8_t status, uint8_t coverage_pct, uint8_t detections)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SEARCH_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, area_id);
    _mav_put_uint8_t(buf, 22, status);
    _mav_put_uint8_t(buf, 23, coverage_pct);
    _mav_put_uint8_t(buf, 24, detections);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SEARCH_STATUS_LEN);
#else
    mavlink_search_status_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.area_id = area_id;
    packet.status = status;
    packet.coverage_pct = coverage_pct;
    packet.detections = detections;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SEARCH_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SEARCH_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SEARCH_STATUS_MIN_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_CRC);
}

/**
 * @brief Pack a search_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param area_id  Search area identifier.
 * @param status  Search status (0=NOT_STARTED, 1=IN_PROGRESS, 2=COMPLETED, 3=ABORTED).
 * @param coverage_pct  Percentage of area covered (0-100).
 * @param detections  Number of detections in this area.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_search_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint16_t area_id, uint8_t status, uint8_t coverage_pct, uint8_t detections)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SEARCH_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, area_id);
    _mav_put_uint8_t(buf, 22, status);
    _mav_put_uint8_t(buf, 23, coverage_pct);
    _mav_put_uint8_t(buf, 24, detections);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SEARCH_STATUS_LEN);
#else
    mavlink_search_status_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.area_id = area_id;
    packet.status = status;
    packet.coverage_pct = coverage_pct;
    packet.detections = detections;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SEARCH_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SEARCH_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SEARCH_STATUS_MIN_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SEARCH_STATUS_MIN_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_LEN);
#endif
}

/**
 * @brief Pack a search_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param area_id  Search area identifier.
 * @param status  Search status (0=NOT_STARTED, 1=IN_PROGRESS, 2=COMPLETED, 3=ABORTED).
 * @param coverage_pct  Percentage of area covered (0-100).
 * @param detections  Number of detections in this area.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_search_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t boot_id,uint32_t msg_seq,uint64_t time_ms,uint32_t ttl_ms,uint16_t area_id,uint8_t status,uint8_t coverage_pct,uint8_t detections)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SEARCH_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, area_id);
    _mav_put_uint8_t(buf, 22, status);
    _mav_put_uint8_t(buf, 23, coverage_pct);
    _mav_put_uint8_t(buf, 24, detections);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SEARCH_STATUS_LEN);
#else
    mavlink_search_status_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.area_id = area_id;
    packet.status = status;
    packet.coverage_pct = coverage_pct;
    packet.detections = detections;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SEARCH_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SEARCH_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SEARCH_STATUS_MIN_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_CRC);
}

/**
 * @brief Encode a search_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param search_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_search_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_search_status_t* search_status)
{
    return mavlink_msg_search_status_pack(system_id, component_id, msg, search_status->boot_id, search_status->msg_seq, search_status->time_ms, search_status->ttl_ms, search_status->area_id, search_status->status, search_status->coverage_pct, search_status->detections);
}

/**
 * @brief Encode a search_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param search_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_search_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_search_status_t* search_status)
{
    return mavlink_msg_search_status_pack_chan(system_id, component_id, chan, msg, search_status->boot_id, search_status->msg_seq, search_status->time_ms, search_status->ttl_ms, search_status->area_id, search_status->status, search_status->coverage_pct, search_status->detections);
}

/**
 * @brief Encode a search_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param search_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_search_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_search_status_t* search_status)
{
    return mavlink_msg_search_status_pack_status(system_id, component_id, _status, msg,  search_status->boot_id, search_status->msg_seq, search_status->time_ms, search_status->ttl_ms, search_status->area_id, search_status->status, search_status->coverage_pct, search_status->detections);
}

/**
 * @brief Send a search_status message
 * @param chan MAVLink channel to send the message
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param area_id  Search area identifier.
 * @param status  Search status (0=NOT_STARTED, 1=IN_PROGRESS, 2=COMPLETED, 3=ABORTED).
 * @param coverage_pct  Percentage of area covered (0-100).
 * @param detections  Number of detections in this area.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_search_status_send(mavlink_channel_t chan, uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint16_t area_id, uint8_t status, uint8_t coverage_pct, uint8_t detections)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SEARCH_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, area_id);
    _mav_put_uint8_t(buf, 22, status);
    _mav_put_uint8_t(buf, 23, coverage_pct);
    _mav_put_uint8_t(buf, 24, detections);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SEARCH_STATUS, buf, MAVLINK_MSG_ID_SEARCH_STATUS_MIN_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_CRC);
#else
    mavlink_search_status_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.area_id = area_id;
    packet.status = status;
    packet.coverage_pct = coverage_pct;
    packet.detections = detections;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SEARCH_STATUS, (const char *)&packet, MAVLINK_MSG_ID_SEARCH_STATUS_MIN_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_CRC);
#endif
}

/**
 * @brief Send a search_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_search_status_send_struct(mavlink_channel_t chan, const mavlink_search_status_t* search_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_search_status_send(chan, search_status->boot_id, search_status->msg_seq, search_status->time_ms, search_status->ttl_ms, search_status->area_id, search_status->status, search_status->coverage_pct, search_status->detections);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SEARCH_STATUS, (const char *)search_status, MAVLINK_MSG_ID_SEARCH_STATUS_MIN_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_SEARCH_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_search_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint16_t area_id, uint8_t status, uint8_t coverage_pct, uint8_t detections)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, area_id);
    _mav_put_uint8_t(buf, 22, status);
    _mav_put_uint8_t(buf, 23, coverage_pct);
    _mav_put_uint8_t(buf, 24, detections);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SEARCH_STATUS, buf, MAVLINK_MSG_ID_SEARCH_STATUS_MIN_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_CRC);
#else
    mavlink_search_status_t *packet = (mavlink_search_status_t *)msgbuf;
    packet->time_ms = time_ms;
    packet->boot_id = boot_id;
    packet->msg_seq = msg_seq;
    packet->ttl_ms = ttl_ms;
    packet->area_id = area_id;
    packet->status = status;
    packet->coverage_pct = coverage_pct;
    packet->detections = detections;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SEARCH_STATUS, (const char *)packet, MAVLINK_MSG_ID_SEARCH_STATUS_MIN_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_LEN, MAVLINK_MSG_ID_SEARCH_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE SEARCH_STATUS UNPACKING


/**
 * @brief Get field boot_id from search_status message
 *
 * @return  Random ID generated on process start, identifies sender instance.
 */
static inline uint32_t mavlink_msg_search_status_get_boot_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field msg_seq from search_status message
 *
 * @return  Monotonic sequence counter per sender.
 */
static inline uint32_t mavlink_msg_search_status_get_msg_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field time_ms from search_status message
 *
 * @return [ms] Sender timestamp in milliseconds since epoch.
 */
static inline uint64_t mavlink_msg_search_status_get_time_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field ttl_ms from search_status message
 *
 * @return [ms] Time-to-live validity window in milliseconds.
 */
static inline uint32_t mavlink_msg_search_status_get_ttl_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field area_id from search_status message
 *
 * @return  Search area identifier.
 */
static inline uint16_t mavlink_msg_search_status_get_area_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field status from search_status message
 *
 * @return  Search status (0=NOT_STARTED, 1=IN_PROGRESS, 2=COMPLETED, 3=ABORTED).
 */
static inline uint8_t mavlink_msg_search_status_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Get field coverage_pct from search_status message
 *
 * @return  Percentage of area covered (0-100).
 */
static inline uint8_t mavlink_msg_search_status_get_coverage_pct(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  23);
}

/**
 * @brief Get field detections from search_status message
 *
 * @return  Number of detections in this area.
 */
static inline uint8_t mavlink_msg_search_status_get_detections(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Decode a search_status message into a struct
 *
 * @param msg The message to decode
 * @param search_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_search_status_decode(const mavlink_message_t* msg, mavlink_search_status_t* search_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    search_status->time_ms = mavlink_msg_search_status_get_time_ms(msg);
    search_status->boot_id = mavlink_msg_search_status_get_boot_id(msg);
    search_status->msg_seq = mavlink_msg_search_status_get_msg_seq(msg);
    search_status->ttl_ms = mavlink_msg_search_status_get_ttl_ms(msg);
    search_status->area_id = mavlink_msg_search_status_get_area_id(msg);
    search_status->status = mavlink_msg_search_status_get_status(msg);
    search_status->coverage_pct = mavlink_msg_search_status_get_coverage_pct(msg);
    search_status->detections = mavlink_msg_search_status_get_detections(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SEARCH_STATUS_LEN? msg->len : MAVLINK_MSG_ID_SEARCH_STATUS_LEN;
        memset(search_status, 0, MAVLINK_MSG_ID_SEARCH_STATUS_LEN);
    memcpy(search_status, _MAV_PAYLOAD(msg), len);
#endif
}
