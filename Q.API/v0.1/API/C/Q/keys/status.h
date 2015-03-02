/* Q API - keys/status.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_keys_status_H__
#define __Q_keys_status_H__

#ifdef OK
#	undef OK
#endif

#define	OK				  0

#define Q_UNIMPLEMENTED			  1
#define Q_END				  2
#define Q_UPDATED			  3

#define Q_ERROR				 -1
#define Q_ERROR_ALREADY_EXISTS		 -2
#define Q_ERROR_ALREADY_IN_USE		 -3
#define Q_ERROR_ALREADY_RUNNING		 -4
#define Q_ERROR_BUSY			 -5
#define Q_ERROR_EMPTY			 -6
#define Q_ERROR_FULL			 -7
#define Q_ERROR_LOCKED			 -8
#define Q_ERROR_TOO_BIG			 -9
#define Q_ERROR_TOO_SMALL		-10
#define Q_ERROR_INVALID_ARGUMENT	-11
#define Q_ERROR_INVALID_ADDRESS		-12
#define Q_ERROR_INVALID_INDEX		-13
#define Q_ERROR_INVALID_SIZE		-14
#define Q_ERROR_INVALID_RANGE		-15
#define Q_ERROR_INVALID_INTERVAL	-16
#define Q_ERROR_INVALID_RATIO		-17
#define Q_ERROR_INVALID_VALUE		-18
#define Q_ERROR_INVALID_DATA		-19
#define Q_ERROR_INVALID_FORMAT		-20
#define Q_ERROR_INVALID_PROTOCOL	-21
#define Q_ERROR_INVALID_IO		-22
#define Q_ERROR_NOT_SUPPORTED		-23
#define Q_ERROR_NOT_AVAILABLE		-24
#define Q_ERROR_NOT_ENOUGH_MEMORY	-25
#define Q_ERROR_NOT_ENOUGH_SPACE	-26
#define Q_ERROR_NOT_ENOUGH_RESOURCES	-27
#define Q_ERROR_NOT_FOUND		-28
#define Q_ERROR_NOT_READABLE		-29
#define Q_ERROR_NOT_WRITABLE		-30
#define Q_ERROR_NOT_EXECUTABLE		-31
#define Q_ERROR_STACK_OVERFLOW		-32
#define Q_ERROR_EXCEPTION		-33
#define Q_ERROR_REJECTED		-34
#define Q_ERROR_SYSTEM_LIMIT_REACHED	-35
#define Q_ERROR_TIME_OUT		-36
#define Q_ERROR_CLOSED			-37
#define Q_ERROR_CLOSED_BY_PEER		-38
#define Q_ERROR_UNAUTHORIZED		-39
#define Q_ERROR_UNREACHABLE		-40
#define Q_ERROR_UNKNOWN			-41

#endif /* __Q_keys_status_H__ */
