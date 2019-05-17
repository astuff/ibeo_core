/*
* Unpublished Copyright (c) 2009-2019 AutonomouStuff, LLC, All Rights Reserved.
*
* This file is part of the ibeo_core ROS driver which is released under the MIT license.
* See file LICENSE included with this software or go to https://opensource.org/licenses/MIT for full license details.
*/

#ifndef IBEO_CORE_UTILS_H
#define IBEO_CORE_UTILS_H

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <ctime>
#include <vector>

namespace AS
{
namespace Drivers
{
namespace Ibeo
{
const size_t MAGIC_WORD = 0xAFFEC0C2;
typedef uint64_t NTPTime;

inline NTPTime unix_time_to_ntp(struct tm *tm, struct timeval *tv)
{
  NTPTime ret_val;

  uint64_t ntp_sec = tm->tm_year * 31536000;  // Add years since 1900 (in seconds)
  ntp_sec += tm->tm_yday * 86400;                  // Add days since Jan 1st (in seconds)
  ntp_sec += tm->tm_hour * 3600;                   // Add hours since midnight (in seconds)
  ntp_sec += tm->tm_min * 60;                      // Add minutes after the hour (in seconds)
  ntp_sec += tm->tm_sec;                           // Add seconds after the minute

  ret_val = (ntp_sec << 32);

  uint64_t ntp_frac = tv->tv_usec;

  ret_val |= ntp_frac;

  return ret_val;
}

inline double ticks_to_angle(int16_t angle_ticks, uint16_t angle_ticks_per_rotation)
{
  return (2.0 * M_PI * static_cast<double>(angle_ticks) / static_cast<double>(angle_ticks_per_rotation));
};
}  // namespace Ibeo
}  // namespace Drivers
}  // namespace AS

#endif  // IBEO_CORE_UTILS_H
