/* Q Kit C API - network/4/UDP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_network_4_UDP_H__
#define __Q_network_4_UDP_H__

#include <Q/types/base.h>

typedef Q_STRICT_STRUCTURE (
	quint32 source_address;
	quint32 destination_address;
	quint8 zeros;
	quint8 protocol;
	quint16 udp_length;
	quint16 source_port;
	quint16 destination_port;
	quint16 size;
	quint16 checksum;
	quint32 data;
) QUDPPseudoHeader;

#endif /* __Q_network_4_UDP_H__ */
