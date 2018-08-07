#pragma once

#include <Arduino.h>

enum class SIM808_ECHO : uint8_t
{
	OFF = 0,
	ON = 1
};

enum class SIM808_SMS_MESSAGE_FORMAT : uint8_t
{
	PDU = 0,
	TEXT = 1
};

enum class SIM808_HTTP_ACTION : uint8_t
{
	GET = 0,
	POST = 1,
	HEAD = 2
};

enum class SIM808_HTTP_ACTION_RESPONSE : uint8_t
{
	METHOD = 0,
	STATUS_CODE = 1,
	DATA_LEN = 2
};

enum class SIM808_REGISTRATION_STATUS_RESPONSE : uint8_t
{
	N = 0,
	STAT = 1,
	LAC = 2,
	CI = 3
};

enum class SIM808_SIGNAL_QUALITY_RESPONSE : uint8_t
{
	SIGNAL_STRENGTH = 0,
	BIT_ERROR_RATE = 1
};

enum class SIM808_PHONE_FUNCTIONALITY : int8_t
{
	FAIL = -1,
	MINIMUM = 0,
	FULL = 1,
	DISABLED = 4
};

enum class SIM808_GPS_STATUS : int8_t
{
	FAIL = -1,
	OFF = 0,
	NO_FIX = 1,
	FIX = 2,
	ACCURATE_FIX = 3
};

enum class SIM808_GPS_FIELD : uint8_t
{
	UTC = 2,
	LATITUDE = 3,
	LONGITUDE = 4,
	ALTITUDE = 5,
	SPEED = 6,
	COURSE = 7,
	GPS_IN_VIEW = 14,
	GNSS_USED = 15
};

enum class SIM808_BATTERY_CHARGE_FIELD : uint8_t
{
	BCS = 0,
	BCL = 1,
	VOLTAGE = 2
};

enum class SIM808_SLOW_CLOCK : uint8_t
{
	DISABLE = 0,
	ENABLE = 1,
	AUTO = 2
};

enum class SIM808_CHARGING_STATE : int8_t
{
	ERROR = -1,
	NOT_CHARGING = 0,
	CHARGING = 1,
	CHARGING_DONE = 2
};

enum class SIM808_NETWORK_REGISTRATION_STATE : int8_t
{
	ERROR = -1,
	NOT_SEARCHING = 0,
	REGISTERED = 1,
	SEARCHING  = 2,
	DENIED = 3,
	UNKNOWN = 4,
	ROAMING = 5
};

struct SIM808SignalQualityReport
{
	uint8_t ssri;
	uint8_t ber;
	int8_t attenuation;
};

struct SIM808RegistrationStatus
{
	uint8_t n;
	SIM808_NETWORK_REGISTRATION_STATE stat;
};

struct SIM808ChargingStatus
{
	SIM808_CHARGING_STATE state;
	int8_t level;
	int16_t voltage;
};