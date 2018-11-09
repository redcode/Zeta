/* Z Kit - keys/status.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_keys_status_H_
#define _Z_keys_status_H_

#ifdef Z_OK
#	undef Z_OK /* zlib */
#endif

#define Z_OK		0
#define Z_END		1
#define Z_UPDATED	2
#define Z_UNIMPLEMENTED	3

#define Z_ERROR_UNKNOWN		     -1
#define Z_ERROR_ALREADY_EXISTS	     -2
#define Z_ERROR_ALREADY_IN_USE	     -3
#define Z_ERROR_ALREADY_OPEN	     -4
#define Z_ERROR_ALREADY_RUNNING	     -5
#define Z_ERROR_BUSY		     -6
#define Z_ERROR_CLOSED		     -7
#define Z_ERROR_CLOSED_BY_PEER	     -8
#define Z_ERROR_EMPTY		     -9
#define Z_ERROR_EXCEPTION	     -10
#define Z_ERROR_FULL		     -11
#define Z_ERROR_LIMIT_REACHED	     -12
#define Z_ERROR_LOCKED		     -13
#define Z_ERROR_LOOP		     -14
#define Z_ERROR_INVALID_ADDRESS	     -15
#define Z_ERROR_INVALID_ARGUMENT     -16
#define Z_ERROR_INVALID_DATA	     -17
#define Z_ERROR_INVALID_FORMAT	     -18
#define Z_ERROR_INVALID_INDEX	     -19
#define Z_ERROR_INVALID_INTERVAL     -20
#define Z_ERROR_INVALID_IO	     -21
#define Z_ERROR_INVALID_PROTOCOL     -22
#define Z_ERROR_INVALID_RANGE	     -23
#define Z_ERROR_INVALID_RATIO	     -24
#define Z_ERROR_INVALID_SIZE	     -25
#define Z_ERROR_INVALID_TYPE	     -26
#define Z_ERROR_INVALID_VALUE	     -27
#define Z_ERROR_NOT_AVAILABLE	     -28
#define Z_ERROR_NOT_ENOUGH_MEMORY    -29
#define Z_ERROR_NOT_ENOUGH_SPACE     -30
#define Z_ERROR_NOT_ENOUGH_RESOURCES -31
#define Z_ERROR_NOT_EXECUTABLE	     -32
#define Z_ERROR_NOT_FINALIZED	     -33
#define Z_ERROR_NOT_FOUND	     -34
#define Z_ERROR_NOT_INITIALIZED	     -35
#define Z_ERROR_NOT_READABLE	     -36
#define Z_ERROR_NOT_WRITABLE	     -37
#define Z_ERROR_NOT_SUPPORTED	     -38
#define Z_ERROR_RACE_CONDITION	     -39
#define Z_ERROR_REJECTED	     -40
#define Z_ERROR_STACK_OVERFLOW	     -41
#define Z_ERROR_STALLED		     -42
#define Z_ERROR_TERMINATED	     -43
#define Z_ERROR_TIME_OUT	     -44
#define Z_ERROR_TOO_BIG		     -45
#define Z_ERROR_TOO_SMALL	     -46
#define Z_ERROR_UNAUTHORIZED	     -47
#define Z_ERROR_UNREACHABLE	     -48

#endif /* _Z_keys_status_H_ */
