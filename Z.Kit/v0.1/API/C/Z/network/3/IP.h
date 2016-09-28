/* Z Kit C API - network/3/IP.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_network_3_IP_H__
#define __Z_network_3_IP_H__

#include <Z/types/base.h>

Z_DEFINE_STRICT_UNION (
	zuint32 value;
) ZIPv4;

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	version			:4;
	zuint8	header_size		:4;
	zuint8	differenciated_services	:8;


	zuint8	version_and_header_lenght;
	zuint8	service_type;
	zuint16	total_size;
	zuint16	identification;
	zuint8	flags_and_fragment_offset;
	zuint8	time_to_live;
	zuint8	protocol;
	zuint8	header_checksum;
	ZIPv4	source;
	ZIPv4	destination;
	zuint32	options;
) ZIPv4Header;

#endif /* __Z_network_3_IP_H__ */
