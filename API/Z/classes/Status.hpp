/* Zeta API - Z/classes/Status.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Status_HPP
#define Z_classes_Status_HPP

#include <Z/keys/status.h>
#include <Z/macros/language.hpp>
#include <Z/types/integral.hpp>


namespace Zeta {struct Status {
	enum {OK = Z_OK};

	struct Error {enum {
		Unknown		   = Z_ERROR_UNKNOWN,
		AlreadyExists	   = Z_ERROR_ALREADY_EXISTS,
		AlreadyInUse	   = Z_ERROR_ALREADY_IN_USE,
		AlreadyOpen	   = Z_ERROR_ALREADY_OPEN,
		AlreadyRunning	   = Z_ERROR_ALREADY_RUNNING,
		Busy		   = Z_ERROR_BUSY,
		Closed		   = Z_ERROR_CLOSED,
		ClosedByPeer	   = Z_ERROR_CLOSED_BY_PEER,
		Empty		   = Z_ERROR_EMPTY,
		Exception	   = Z_ERROR_EXCEPTION,
		Full		   = Z_ERROR_FULL,
		LimitReached	   = Z_ERROR_LIMIT_REACHED,
		Locked		   = Z_ERROR_LOCKED,
		Loop		   = Z_ERROR_LOOP,
		InvalidAddress	   = Z_ERROR_INVALID_ADDRESS,
		InvalidArgument	   = Z_ERROR_INVALID_ARGUMENT,
		InvalidData	   = Z_ERROR_INVALID_DATA,
		InvalidFormat	   = Z_ERROR_INVALID_FORMAT,
		InvalidIndex	   = Z_ERROR_INVALID_INDEX,
		InvalidInterval	   = Z_ERROR_INVALID_INTERVAL,
		InvalidIO	   = Z_ERROR_INVALID_IO,
		InvalidProtocol	   = Z_ERROR_INVALID_PROTOCOL,
		InvalidRange	   = Z_ERROR_INVALID_RANGE,
		InvalidRatio	   = Z_ERROR_INVALID_RATIO,
		InvalidSize	   = Z_ERROR_INVALID_SIZE,
		InvalidType	   = Z_ERROR_INVALID_TYPE,
		InvalidValue	   = Z_ERROR_INVALID_VALUE,
		NotAvailable	   = Z_ERROR_NOT_AVAILABLE,
		NotEnoughMemory	   = Z_ERROR_NOT_ENOUGH_MEMORY,
		NotEnoughSpace	   = Z_ERROR_NOT_ENOUGH_SPACE,
		NotEnoughResources = Z_ERROR_NOT_ENOUGH_RESOURCES,
		NotExecutable	   = Z_ERROR_NOT_EXECUTABLE,
		NotFinalized	   = Z_ERROR_NOT_FINALIZED,
		NotFound	   = Z_ERROR_NOT_FOUND,
		NotInitialized	   = Z_ERROR_NOT_INITIALIZED,
		NotReadable	   = Z_ERROR_NOT_READABLE,
		NotWritable	   = Z_ERROR_NOT_WRITABLE,
		NotSupported	   = Z_ERROR_NOT_SUPPORTED,
		RaceCondition	   = Z_ERROR_RACE_CONDITION,
		Rejected	   = Z_ERROR_REJECTED,
		StackOverflow	   = Z_ERROR_STACK_OVERFLOW,
		Stalled		   = Z_ERROR_STALLED,
		Terminated	   = Z_ERROR_TERMINATED,
		TimeOut		   = Z_ERROR_TIME_OUT,
		TooBig		   = Z_ERROR_TOO_BIG,
		TooSmall	   = Z_ERROR_TOO_SMALL,
		Unauthorized	   = Z_ERROR_UNAUTHORIZED,
		Unreachable	   = Z_ERROR_UNREACHABLE
	};};

	SInt code;


	Z_INLINE Status() Z_NOTHROW
		Z_DEFAULTED({})


	Z_CT(CPP11) Status(SInt status) Z_NOTHROW
	: code(status) {}


	Z_CT(CPP11) operator SInt() const Z_NOTHROW
		{return code;}


	friend Z_CT(CPP11) Boolean operator ==(const Status &lhs, const Status &rhs) Z_NOTHROW
		{return lhs.code == rhs.code;}


	friend Z_CT(CPP11) Boolean operator ==(const Status &lhs, UInt64 rhs) Z_NOTHROW
		{return lhs.code == rhs;}


	friend Z_CT(CPP11) Boolean operator ==(UInt64 lhs, const Status &rhs) Z_NOTHROW
		{return lhs == rhs.code;}


	friend Z_CT(CPP11) Boolean operator !=(const Status &lhs, const Status &rhs) Z_NOTHROW
		{return lhs.code != rhs.code;}


	friend Z_CT(CPP11) Boolean operator !=(const Status &lhs, UInt64 rhs) Z_NOTHROW
		{return lhs.code != rhs;}


	friend Z_CT(CPP11) Boolean operator !=(UInt64 lhs, const Status &rhs) Z_NOTHROW
		{return lhs != rhs.code;}


	Z_CT(CPP11) Boolean is_error() const Z_NOTHROW
		{return code < 0;}
};}


#endif // Z_classes_Status_HPP
