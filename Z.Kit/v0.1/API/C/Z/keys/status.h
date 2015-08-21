/* Z Kit C API - keys/status.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_keys_status_H__
#define __Z_keys_status_H__

#define	Z_OK				  0

#define Z_UNIMPLEMENTED			  1
#define Z_END				  2
#define Z_UPDATED			  3

#define Z_ERROR				 -1
#define Z_ERROR_ALREADY_EXISTS		 -2
#define Z_ERROR_ALREADY_IN_USE		 -3
#define Z_ERROR_ALREADY_RUNNING		 -4
#define Z_ERROR_BUSY			 -5
#define Z_ERROR_EMPTY			 -6
#define Z_ERROR_FULL			 -7
#define Z_ERROR_LOCKED			 -8
#define Z_ERROR_TOO_BIG			 -9
#define Z_ERROR_TOO_SMALL		-10
#define Z_ERROR_INVALID_ARGUMENT	-11
#define Z_ERROR_INVALID_ADDRESS		-12
#define Z_ERROR_INVALID_INDEX		-13
#define Z_ERROR_INVALID_SIZE		-14
#define Z_ERROR_INVALID_RANGE		-15
#define Z_ERROR_INVALID_INTERVAL	-16
#define Z_ERROR_INVALID_RATIO		-17
#define Z_ERROR_INVALID_VALUE		-18
#define Z_ERROR_INVALID_DATA		-19
#define Z_ERROR_INVALID_FORMAT		-20
#define Z_ERROR_INVALID_PROTOCOL	-21
#define Z_ERROR_INVALID_IO		-22
#define Z_ERROR_NOT_SUPPORTED		-23
#define Z_ERROR_NOT_AVAILABLE		-24
#define Z_ERROR_NOT_ENOUGH_MEMORY	-25
#define Z_ERROR_NOT_ENOUGH_SPACE	-26
#define Z_ERROR_NOT_ENOUGH_RESOURCES	-27
#define Z_ERROR_NOT_FOUND		-28
#define Z_ERROR_NOT_READABLE		-29
#define Z_ERROR_NOT_WRITABLE		-30
#define Z_ERROR_NOT_EXECUTABLE		-31
#define Z_ERROR_STACK_OVERFLOW		-32
#define Z_ERROR_EXCEPTION		-33
#define Z_ERROR_REJECTED		-34
#define Z_ERROR_SYSTEM_LIMIT_REACHED	-35
#define Z_ERROR_TIME_OUT		-36
#define Z_ERROR_CLOSED			-37
#define Z_ERROR_CLOSED_BY_PEER		-38
#define Z_ERROR_UNAUTHORIZED		-39
#define Z_ERROR_UNREACHABLE		-40
#define Z_ERROR_UNKNOWN			-41

#endif /* __Z_keys_status_H__ */
