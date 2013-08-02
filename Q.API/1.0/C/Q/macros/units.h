/* Q API - macros/units.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_macros_units_H__
#define __Q_macros_units_H__

#include <Q/constants/numbers.h>

/* MARK: - Angle */

#define Q_DEGREES_TO_RADIANS(degrees)	((degrees) * (Q_PI / 180.0))
#define Q_RADIANS_TO_DEGREES(radians)	((radians) * (180.0 / Q_PI))

/* MARK: - Time */

#define Q_MINUTES_TO_SECONDS(minutes)	((minutes) *     60)
#define Q_HOURS_TO_SECONDS(    hours)	((hours)   *   3600)
#define Q_DAYS_TO_SECONDS(      days)	((days)    *  86400)
#define Q_WEEKS_TO_SECONDS(    weeks)	((weeks)   * 604800)
#define Q_SECONDS_TO_MINUTES(seconds)	((seconds) /	 60)
#define Q_SECONDS_TO_HOURS(  seconds)	((seconds) /   3600)

/* MARK: - Length */

#define Q_METERS_TO_FOOTS
#define Q_METERS_TO_INCHS

/* MARK: - Area */

/* MARK: - Weight */

#endif /* __Q_macros_units_H__ */
