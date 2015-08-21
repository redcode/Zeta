/* Z Kit C API - network/4/TCP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_network_4_TCP_H__
#define __Z_network_4_TCP_H__

#include <Z/types/base.h>

typedef Z_STRICT_STRUCTURE (
	zuint16 source_port;
	zuint16 destination_port;
	zuint32 sequence_number;
	zuint64 acknowledgment_number;
	zuint16 state; /* WIP */
	zuint16 window_size;
	zuint16 checksum;
	zuint16 urgent_pointer;
) ZTCPHeader;

#endif /* __Z_network_4_TCP_H__ */
