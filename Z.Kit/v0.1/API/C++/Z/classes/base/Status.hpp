/* Z Kit C++ API - classes/base/Status.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Status_HPP__
#define __Z_classes_base_Status_HPP__

#include <Z/keys/status.h>
#include <Z/types/base.hpp>
#include <Z/macros/language.hpp>

namespace Zeta {struct Status;}


struct Zeta::Status {

	enum {	OK	      = Z_OK,
		END	      = Z_END,
		UPDATED	      = Z_UPDATED,
		UNIMPLEMENTED = Z_UNIMPLEMENTED
	};

	enum Error {
		UNKNOWN		     = Z_ERROR_UNKNOWN,
		ALREADY_EXISTS	     = Z_ERROR_ALREADY_EXISTS,
		ALREADY_IN_USE	     = Z_ERROR_ALREADY_IN_USE,
		ALREADY_OPEN	     = Z_ERROR_ALREADY_OPEN,
		ALREADY_RUNNING	     = Z_ERROR_ALREADY_RUNNING,
		BUSY		     = Z_ERROR_BUSY,
		CLOSED		     = Z_ERROR_CLOSED,
		CLOSED_BY_PEER	     = Z_ERROR_CLOSED_BY_PEER,
		EMPTY		     = Z_ERROR_EMPTY,
		EXCEPTION	     = Z_ERROR_EXCEPTION,
		FULL		     = Z_ERROR_FULL,
		LIMIT_REACHED	     = Z_ERROR_LIMIT_REACHED,
		LOCKED		     = Z_ERROR_LOCKED,
		LOOP		     = Z_ERROR_LOOP,
		INVALID_ADDRESS	     = Z_ERROR_INVALID_ADDRESS,
		INVALID_ARGUMENT     = Z_ERROR_INVALID_ARGUMENT,
		INVALID_DATA	     = Z_ERROR_INVALID_DATA,
		INVALID_FORMAT	     = Z_ERROR_INVALID_FORMAT,
		INVALID_INDEX	     = Z_ERROR_INVALID_INDEX,
		INVALID_INTERVAL     = Z_ERROR_INVALID_INTERVAL,
		INVALID_IO	     = Z_ERROR_INVALID_IO,
		INVALID_PROTOCOL     = Z_ERROR_INVALID_PROTOCOL,
		INVALID_RANGE	     = Z_ERROR_INVALID_RANGE,
		INVALID_RATIO	     = Z_ERROR_INVALID_RATIO,
		INVALID_SIZE	     = Z_ERROR_INVALID_SIZE,
		INVALID_TYPE	     = Z_ERROR_INVALID_TYPE,
		INVALID_VALUE	     = Z_ERROR_INVALID_VALUE,
		NOT_AVAILABLE	     = Z_ERROR_NOT_AVAILABLE,
		NOT_ENOUGH_MEMORY    = Z_ERROR_NOT_ENOUGH_MEMORY,
		NOT_ENOUGH_SPACE     = Z_ERROR_NOT_ENOUGH_SPACE,
		NOT_ENOUGH_RESOURCES = Z_ERROR_NOT_ENOUGH_RESOURCES,
		NOT_EXECUTABLE	     = Z_ERROR_NOT_EXECUTABLE,
		NOT_FINALIZED	     = Z_ERROR_NOT_FINALIZED,
		NOT_FOUND	     = Z_ERROR_NOT_FOUND,
		NOT_INITIALIZED	     = Z_ERROR_NOT_INITIALIZED,
		NOT_READABLE	     = Z_ERROR_NOT_READABLE,
		NOT_WRITABLE	     = Z_ERROR_NOT_WRITABLE,
		NOT_SUPPORTED	     = Z_ERROR_NOT_SUPPORTED,
		RACE_CONDITION	     = Z_ERROR_RACE_CONDITION,
		REJECTED	     = Z_ERROR_REJECTED,
		STACK_OVERFLOW	     = Z_ERROR_STACK_OVERFLOW,
		STALLED		     = Z_ERROR_STALLED,
		TERMINATED	     = Z_ERROR_TERMINATED,
		TIME_OUT	     = Z_ERROR_TIME_OUT,
		TOO_BIG		     = Z_ERROR_TOO_BIG,
		TOO_SMALL	     = Z_ERROR_TOO_SMALL,
		UNAUTHORIZED	     = Z_ERROR_UNAUTHORIZED,
		UNREACHABLE	     = Z_ERROR_UNREACHABLE
	};

	ZStatus code;

	Z_INLINE_MEMBER Status() {}
	Z_INLINE_MEMBER Status(ZStatus code) : code(code) {}

#	if Z_LANGUAGE_HAS_TYPE(CPP, BOOLEAN)
		Z_INLINE_MEMBER operator bool() const {return code;}
#	endif

	Z_INLINE_MEMBER operator ZStatus() const {return code;}

	Z_INLINE_MEMBER Boolean operator ==(ZStatus status) const {return code == status;}
	Z_INLINE_MEMBER Boolean operator !=(ZStatus status) const {return code != status;}

	Z_INLINE_MEMBER Boolean is_error() const {return code < 0;}
	Z_INLINE_MEMBER Boolean is_valid() const {return code >= UNREACHABLE && code <= UNIMPLEMENTED;}
};


#endif // __Z_classes_base_Status_HPP__
