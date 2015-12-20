/* Z Kit C++ API - classes/base/Status.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Status_HPP__
#define __Z_classes_base_Status_HPP__

#include <Z/types/base.hpp>

namespace ZKit {struct Status;}


struct ZKit::Status {

	enum {	OK	      = Z_OK,
		end	      = Z_END,
		updated	      = Z_UPDATED,
		unimplemented = Z_UNIMPLEMENTED
	};

	enum Error {
		unknown		     = Z_ERROR_UNKNOWN,
		already_exists	     = Z_ERROR_ALREADY_EXISTS,
		already_in_use	     = Z_ERROR_ALREADY_IN_USE,
		already_open	     = Z_ERROR_ALREADY_OPEN,
		already_running	     = Z_ERROR_ALREADY_RUNNING,
		busy		     = Z_ERROR_BUSY,
		closed		     = Z_ERROR_CLOSED,
		empty		     = Z_ERROR_EMPTY,
		exception	     = Z_ERROR_EXCEPTION,
		full		     = Z_ERROR_FULL,
		locked		     = Z_ERROR_LOCKED,
		loop		     = Z_ERROR_LOOP,
		invalid_address	     = Z_ERROR_INVALID_ADDRESS,
		invalid_argument     = Z_ERROR_INVALID_ARGUMENT,
		invalid_data	     = Z_ERROR_INVALID_DATA,
		invalid_format	     = Z_ERROR_INVALID_FORMAT,
		invalid_index	     = Z_ERROR_INVALID_INDEX,
		invalid_interval     = Z_ERROR_INVALID_INTERVAL,
		invalid_io	     = Z_ERROR_INVALID_IO,
		invalid_protocol     = Z_ERROR_INVALID_PROTOCOL,
		invalid_range	     = Z_ERROR_INVALID_RANGE,
		invalid_ratio	     = Z_ERROR_INVALID_RATIO,
		invalid_size	     = Z_ERROR_INVALID_SIZE,
		invalid_type	     = Z_ERROR_INVALID_TYPE,
		invalid_value	     = Z_ERROR_INVALID_VALUE,
		not_available	     = Z_ERROR_NOT_AVAILABLE,
		not_enough_memory    = Z_ERROR_NOT_ENOUGH_MEMORY,
		not_enough_space     = Z_ERROR_NOT_ENOUGH_SPACE,
		not_enough_resources = Z_ERROR_NOT_ENOUGH_RESOURCES,
		not_executable	     = Z_ERROR_NOT_EXECUTABLE,
		not_found	     = Z_ERROR_NOT_FOUND,
		not_readable	     = Z_ERROR_NOT_READABLE,
		not_writable	     = Z_ERROR_NOT_WRITABLE,
		not_supported	     = Z_ERROR_NOT_SUPPORTED,
		rejected	     = Z_ERROR_REJECTED,
		stack_overflow	     = Z_ERROR_STACK_OVERFLOW,
		system_limit_reached = Z_ERROR_SYSTEM_LIMIT_REACHED,
		time_out	     = Z_ERROR_TIME_OUT,
		too_big		     = Z_ERROR_TOO_BIG,
		too_small	     = Z_ERROR_TOO_SMALL,
		unauthorized	     = Z_ERROR_UNAUTHORIZED,
		unreachable	     = Z_ERROR_UNREACHABLE
	}

	ZStatus value;

	inline Status(ZStatus code) : value(code) {};
};


#endif // __Z_classes_base_Status_HPP__
