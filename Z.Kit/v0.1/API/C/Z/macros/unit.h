/* Z Kit C API - macros/unit.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_unit_H__
#define __Z_macros_unit_H__

#include <Z/constants/numbers.h>

/* MARK: - Angle */

#define Z_DEGREES_TO_RADIANS(degrees)	((degrees) * (Z_PI / 180.0))
#define Z_RADIANS_TO_DEGREES(radians)	((radians) * (180.0 / Z_PI))

/* MARK: - Time */

#define Z_MINUTES_TO_SECONDS(minutes)	((minutes) *     60)
#define Z_HOURS_TO_SECONDS(    hours)	((hours)   *   3600)
#define Z_DAYS_TO_SECONDS(      days)	((days)    *  86400)
#define Z_WEEKS_TO_SECONDS(    weeks)	((weeks)   * 604800)
#define Z_SECONDS_TO_MINUTES(seconds)	((seconds) /	 60)
#define Z_SECONDS_TO_HOURS(  seconds)	((seconds) /   3600)

/* MARK: - Length */

#define Z_METERS_TO_FOOTS
#define Z_METERS_TO_INCHS

/* MARK: - Area */

/* MARK: - Weight */

#endif /* __Z_macros_unit_H__ */
