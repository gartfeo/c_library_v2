#pragma once
// MESSAGE VOTE_PHASE PACKING

#define MAVLINK_MSG_ID_VOTE_PHASE 25202


typedef struct __mavlink_vote_phase_t {
 uint64_t time_ms; /*< [ms] Sender timestamp in milliseconds since epoch.*/
 uint32_t boot_id; /*<  Random ID generated on process start, identifies sender instance.*/
 uint32_t msg_seq; /*<  Monotonic sequence counter per sender.*/
 uint32_t ttl_ms; /*< [ms] Time-to-live validity window in milliseconds.*/
 uint16_t round_id; /*<  Voting round identifier.*/
 uint16_t proposal_id; /*<  Proposal being voted on.*/
 uint8_t phase; /*<  Current voting phase (0=PROPOSE, 1=VOTE, 2=COMMIT).*/
 uint8_t vote; /*<  Vote value (0=REJECT, 1=ACCEPT, 2=ABSTAIN).*/
} mavlink_vote_phase_t;

#define MAVLINK_MSG_ID_VOTE_PHASE_LEN 26
#define MAVLINK_MSG_ID_VOTE_PHASE_MIN_LEN 26
#define MAVLINK_MSG_ID_25202_LEN 26
#define MAVLINK_MSG_ID_25202_MIN_LEN 26

#define MAVLINK_MSG_ID_VOTE_PHASE_CRC 195
#define MAVLINK_MSG_ID_25202_CRC 195



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VOTE_PHASE { \
    25202, \
    "VOTE_PHASE", \
    8, \
    {  { "boot_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_vote_phase_t, boot_id) }, \
         { "msg_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_vote_phase_t, msg_seq) }, \
         { "time_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vote_phase_t, time_ms) }, \
         { "ttl_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_vote_phase_t, ttl_ms) }, \
         { "phase", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_vote_phase_t, phase) }, \
         { "round_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_vote_phase_t, round_id) }, \
         { "proposal_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_vote_phase_t, proposal_id) }, \
         { "vote", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_vote_phase_t, vote) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VOTE_PHASE { \
    "VOTE_PHASE", \
    8, \
    {  { "boot_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_vote_phase_t, boot_id) }, \
         { "msg_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_vote_phase_t, msg_seq) }, \
         { "time_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vote_phase_t, time_ms) }, \
         { "ttl_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_vote_phase_t, ttl_ms) }, \
         { "phase", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_vote_phase_t, phase) }, \
         { "round_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_vote_phase_t, round_id) }, \
         { "proposal_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_vote_phase_t, proposal_id) }, \
         { "vote", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_vote_phase_t, vote) }, \
         } \
}
#endif

/**
 * @brief Pack a vote_phase message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param phase  Current voting phase (0=PROPOSE, 1=VOTE, 2=COMMIT).
 * @param round_id  Voting round identifier.
 * @param proposal_id  Proposal being voted on.
 * @param vote  Vote value (0=REJECT, 1=ACCEPT, 2=ABSTAIN).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vote_phase_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint8_t phase, uint16_t round_id, uint16_t proposal_id, uint8_t vote)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VOTE_PHASE_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, round_id);
    _mav_put_uint16_t(buf, 22, proposal_id);
    _mav_put_uint8_t(buf, 24, phase);
    _mav_put_uint8_t(buf, 25, vote);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VOTE_PHASE_LEN);
#else
    mavlink_vote_phase_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.round_id = round_id;
    packet.proposal_id = proposal_id;
    packet.phase = phase;
    packet.vote = vote;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VOTE_PHASE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VOTE_PHASE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VOTE_PHASE_MIN_LEN, MAVLINK_MSG_ID_VOTE_PHASE_LEN, MAVLINK_MSG_ID_VOTE_PHASE_CRC);
}

/**
 * @brief Pack a vote_phase message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param phase  Current voting phase (0=PROPOSE, 1=VOTE, 2=COMMIT).
 * @param round_id  Voting round identifier.
 * @param proposal_id  Proposal being voted on.
 * @param vote  Vote value (0=REJECT, 1=ACCEPT, 2=ABSTAIN).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vote_phase_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint8_t phase, uint16_t round_id, uint16_t proposal_id, uint8_t vote)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VOTE_PHASE_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, round_id);
    _mav_put_uint16_t(buf, 22, proposal_id);
    _mav_put_uint8_t(buf, 24, phase);
    _mav_put_uint8_t(buf, 25, vote);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VOTE_PHASE_LEN);
#else
    mavlink_vote_phase_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.round_id = round_id;
    packet.proposal_id = proposal_id;
    packet.phase = phase;
    packet.vote = vote;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VOTE_PHASE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VOTE_PHASE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_VOTE_PHASE_MIN_LEN, MAVLINK_MSG_ID_VOTE_PHASE_LEN, MAVLINK_MSG_ID_VOTE_PHASE_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_VOTE_PHASE_MIN_LEN, MAVLINK_MSG_ID_VOTE_PHASE_LEN);
#endif
}

/**
 * @brief Pack a vote_phase message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param phase  Current voting phase (0=PROPOSE, 1=VOTE, 2=COMMIT).
 * @param round_id  Voting round identifier.
 * @param proposal_id  Proposal being voted on.
 * @param vote  Vote value (0=REJECT, 1=ACCEPT, 2=ABSTAIN).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vote_phase_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t boot_id,uint32_t msg_seq,uint64_t time_ms,uint32_t ttl_ms,uint8_t phase,uint16_t round_id,uint16_t proposal_id,uint8_t vote)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VOTE_PHASE_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, round_id);
    _mav_put_uint16_t(buf, 22, proposal_id);
    _mav_put_uint8_t(buf, 24, phase);
    _mav_put_uint8_t(buf, 25, vote);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VOTE_PHASE_LEN);
#else
    mavlink_vote_phase_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.round_id = round_id;
    packet.proposal_id = proposal_id;
    packet.phase = phase;
    packet.vote = vote;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VOTE_PHASE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VOTE_PHASE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VOTE_PHASE_MIN_LEN, MAVLINK_MSG_ID_VOTE_PHASE_LEN, MAVLINK_MSG_ID_VOTE_PHASE_CRC);
}

/**
 * @brief Encode a vote_phase struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vote_phase C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vote_phase_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vote_phase_t* vote_phase)
{
    return mavlink_msg_vote_phase_pack(system_id, component_id, msg, vote_phase->boot_id, vote_phase->msg_seq, vote_phase->time_ms, vote_phase->ttl_ms, vote_phase->phase, vote_phase->round_id, vote_phase->proposal_id, vote_phase->vote);
}

/**
 * @brief Encode a vote_phase struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vote_phase C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vote_phase_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vote_phase_t* vote_phase)
{
    return mavlink_msg_vote_phase_pack_chan(system_id, component_id, chan, msg, vote_phase->boot_id, vote_phase->msg_seq, vote_phase->time_ms, vote_phase->ttl_ms, vote_phase->phase, vote_phase->round_id, vote_phase->proposal_id, vote_phase->vote);
}

/**
 * @brief Encode a vote_phase struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param vote_phase C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vote_phase_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_vote_phase_t* vote_phase)
{
    return mavlink_msg_vote_phase_pack_status(system_id, component_id, _status, msg,  vote_phase->boot_id, vote_phase->msg_seq, vote_phase->time_ms, vote_phase->ttl_ms, vote_phase->phase, vote_phase->round_id, vote_phase->proposal_id, vote_phase->vote);
}

/**
 * @brief Send a vote_phase message
 * @param chan MAVLink channel to send the message
 *
 * @param boot_id  Random ID generated on process start, identifies sender instance.
 * @param msg_seq  Monotonic sequence counter per sender.
 * @param time_ms [ms] Sender timestamp in milliseconds since epoch.
 * @param ttl_ms [ms] Time-to-live validity window in milliseconds.
 * @param phase  Current voting phase (0=PROPOSE, 1=VOTE, 2=COMMIT).
 * @param round_id  Voting round identifier.
 * @param proposal_id  Proposal being voted on.
 * @param vote  Vote value (0=REJECT, 1=ACCEPT, 2=ABSTAIN).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vote_phase_send(mavlink_channel_t chan, uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint8_t phase, uint16_t round_id, uint16_t proposal_id, uint8_t vote)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VOTE_PHASE_LEN];
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, round_id);
    _mav_put_uint16_t(buf, 22, proposal_id);
    _mav_put_uint8_t(buf, 24, phase);
    _mav_put_uint8_t(buf, 25, vote);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOTE_PHASE, buf, MAVLINK_MSG_ID_VOTE_PHASE_MIN_LEN, MAVLINK_MSG_ID_VOTE_PHASE_LEN, MAVLINK_MSG_ID_VOTE_PHASE_CRC);
#else
    mavlink_vote_phase_t packet;
    packet.time_ms = time_ms;
    packet.boot_id = boot_id;
    packet.msg_seq = msg_seq;
    packet.ttl_ms = ttl_ms;
    packet.round_id = round_id;
    packet.proposal_id = proposal_id;
    packet.phase = phase;
    packet.vote = vote;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOTE_PHASE, (const char *)&packet, MAVLINK_MSG_ID_VOTE_PHASE_MIN_LEN, MAVLINK_MSG_ID_VOTE_PHASE_LEN, MAVLINK_MSG_ID_VOTE_PHASE_CRC);
#endif
}

/**
 * @brief Send a vote_phase message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_vote_phase_send_struct(mavlink_channel_t chan, const mavlink_vote_phase_t* vote_phase)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_vote_phase_send(chan, vote_phase->boot_id, vote_phase->msg_seq, vote_phase->time_ms, vote_phase->ttl_ms, vote_phase->phase, vote_phase->round_id, vote_phase->proposal_id, vote_phase->vote);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOTE_PHASE, (const char *)vote_phase, MAVLINK_MSG_ID_VOTE_PHASE_MIN_LEN, MAVLINK_MSG_ID_VOTE_PHASE_LEN, MAVLINK_MSG_ID_VOTE_PHASE_CRC);
#endif
}

#if MAVLINK_MSG_ID_VOTE_PHASE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vote_phase_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t boot_id, uint32_t msg_seq, uint64_t time_ms, uint32_t ttl_ms, uint8_t phase, uint16_t round_id, uint16_t proposal_id, uint8_t vote)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_ms);
    _mav_put_uint32_t(buf, 8, boot_id);
    _mav_put_uint32_t(buf, 12, msg_seq);
    _mav_put_uint32_t(buf, 16, ttl_ms);
    _mav_put_uint16_t(buf, 20, round_id);
    _mav_put_uint16_t(buf, 22, proposal_id);
    _mav_put_uint8_t(buf, 24, phase);
    _mav_put_uint8_t(buf, 25, vote);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOTE_PHASE, buf, MAVLINK_MSG_ID_VOTE_PHASE_MIN_LEN, MAVLINK_MSG_ID_VOTE_PHASE_LEN, MAVLINK_MSG_ID_VOTE_PHASE_CRC);
#else
    mavlink_vote_phase_t *packet = (mavlink_vote_phase_t *)msgbuf;
    packet->time_ms = time_ms;
    packet->boot_id = boot_id;
    packet->msg_seq = msg_seq;
    packet->ttl_ms = ttl_ms;
    packet->round_id = round_id;
    packet->proposal_id = proposal_id;
    packet->phase = phase;
    packet->vote = vote;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOTE_PHASE, (const char *)packet, MAVLINK_MSG_ID_VOTE_PHASE_MIN_LEN, MAVLINK_MSG_ID_VOTE_PHASE_LEN, MAVLINK_MSG_ID_VOTE_PHASE_CRC);
#endif
}
#endif

#endif

// MESSAGE VOTE_PHASE UNPACKING


/**
 * @brief Get field boot_id from vote_phase message
 *
 * @return  Random ID generated on process start, identifies sender instance.
 */
static inline uint32_t mavlink_msg_vote_phase_get_boot_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field msg_seq from vote_phase message
 *
 * @return  Monotonic sequence counter per sender.
 */
static inline uint32_t mavlink_msg_vote_phase_get_msg_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field time_ms from vote_phase message
 *
 * @return [ms] Sender timestamp in milliseconds since epoch.
 */
static inline uint64_t mavlink_msg_vote_phase_get_time_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field ttl_ms from vote_phase message
 *
 * @return [ms] Time-to-live validity window in milliseconds.
 */
static inline uint32_t mavlink_msg_vote_phase_get_ttl_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field phase from vote_phase message
 *
 * @return  Current voting phase (0=PROPOSE, 1=VOTE, 2=COMMIT).
 */
static inline uint8_t mavlink_msg_vote_phase_get_phase(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field round_id from vote_phase message
 *
 * @return  Voting round identifier.
 */
static inline uint16_t mavlink_msg_vote_phase_get_round_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field proposal_id from vote_phase message
 *
 * @return  Proposal being voted on.
 */
static inline uint16_t mavlink_msg_vote_phase_get_proposal_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field vote from vote_phase message
 *
 * @return  Vote value (0=REJECT, 1=ACCEPT, 2=ABSTAIN).
 */
static inline uint8_t mavlink_msg_vote_phase_get_vote(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Decode a vote_phase message into a struct
 *
 * @param msg The message to decode
 * @param vote_phase C-struct to decode the message contents into
 */
static inline void mavlink_msg_vote_phase_decode(const mavlink_message_t* msg, mavlink_vote_phase_t* vote_phase)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    vote_phase->time_ms = mavlink_msg_vote_phase_get_time_ms(msg);
    vote_phase->boot_id = mavlink_msg_vote_phase_get_boot_id(msg);
    vote_phase->msg_seq = mavlink_msg_vote_phase_get_msg_seq(msg);
    vote_phase->ttl_ms = mavlink_msg_vote_phase_get_ttl_ms(msg);
    vote_phase->round_id = mavlink_msg_vote_phase_get_round_id(msg);
    vote_phase->proposal_id = mavlink_msg_vote_phase_get_proposal_id(msg);
    vote_phase->phase = mavlink_msg_vote_phase_get_phase(msg);
    vote_phase->vote = mavlink_msg_vote_phase_get_vote(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VOTE_PHASE_LEN? msg->len : MAVLINK_MSG_ID_VOTE_PHASE_LEN;
        memset(vote_phase, 0, MAVLINK_MSG_ID_VOTE_PHASE_LEN);
    memcpy(vote_phase, _MAV_PAYLOAD(msg), len);
#endif
}
