/* Q API - network/4/TCP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_network_4_TCP_H__
#define __Q_network_4_TCP_H__

#include <Q/types/base.h>

typedef Q_STRICT_STRUCTURE (
	quint16 source_port;
	quint16 destination_port;
	quint32 sequence_number;
	quint64 acknowledgment_number;
	quint16 state; /* WIP */
	quint16 window_size;
	quint16 checksum;
	quint16 urgent_pointer;
) QTCPHeader;

#endif /* __Q_network_4_TCP_H__ */
