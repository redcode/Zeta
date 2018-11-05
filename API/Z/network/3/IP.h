/* Z Kit - network/3/IP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_network_3_IP_H_
#define _Z_network_3_IP_H_

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

#endif /* _Z_network_3_IP_H_ */
