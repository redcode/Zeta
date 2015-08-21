/* Z Kit C API - network/4/UDP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_network_4_UDP_H__
#define __Z_network_4_UDP_H__

#include <Z/types/base.h>

typedef Z_STRICT_STRUCTURE (
	zuint32 source_address;
	zuint32 destination_address;
	zuint8	zeros;
	zuint8	protocol;
	zuint16 udp_length;
	zuint16 source_port;
	zuint16 destination_port;
	zuint16 size;
	zuint16 checksum;
	zuint32 data;
) ZUDPPseudoHeader;

#endif /* __Z_network_4_UDP_H__ */
