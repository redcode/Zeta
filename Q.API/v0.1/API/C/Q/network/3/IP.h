/* Q API - network/3/IP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_network_3_IP_H__
#define __Q_network_3_IP_H__

#include <Q/types/base.h>

Q_DEFINE_STRICT_UNION (
	quint32 value;
) QIPv4;

Q_DEFINE_STRICT_STRUCTURE (
	quint8	version			:4;
	quint8	header_size		:4;
	quint8	differenciated_services	:8;


	quint8	version_and_header_lenght;
	quint8	service_type;
	quint16	total_size;
	quint16	identification;
	quint8	flags_and_fragment_offset;
	quint8	time_to_live;
	quint8	protocol;
	quint8	header_checksum;
	QIPv4	source;
	QIPv4	destination;
	quint32	options;
) QIPv4Header;

#endif /* __Q_network_3_IP_H__ */
