/* Q API - formats/multimedia container/Microsoft Wave.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_formats_multimedia_container_Microsoft_Wave_H__
#define __Q_formats_multimedia_container_Microsoft_Wave_H__

#include <Q/types/basics.h>

Q_DEFINE_STRICT_STRUCTURE (
	quint32 block_id;		/* 'RIFF' in big endian */
	quint32 block_size;		/* The size of the entire file minus 8 bytes */
	quint32 format;			/* 'WAVE' in big endian */

	struct {quint32 subblock_id;	/* 'fmt ' in big endian */
		quint32 subblock_size;
		quint16 audio_format;
		quint16 channel_count;
		quint32 sample_rate;
		quint32 byte_rate;
		quint16 block_alignment;
		quint16 bits_per_sample;
	} fmt;

	struct {quint32 subblock_id;	/* 'data' in big endian */
		quint32 subblock_size;
		quint8 samples[];
	} data;

) QMicrosoftWave;

#define Q_MICROSOFT_WAVE(p) ((QMicrosoftWare *)(p))

#if Q_UINT32_ENDIANNESS == Q_ENDIANNESS_BIG
#	define Q_MICROSOFT_WAVE_BLOCK_ID	0x52494646
#	define Q_MICROSOFT_WAVE_FORMAT		0x57415645
#elif Q_UINT32_ENDIANNESS == Q_ENDIANNESS_LITTLE
#	define Q_MICROSOFT_WAVE_BLOCK_ID	0x46464952
#	define Q_MICROSOFT_WAVE_FORMAT		0x45564157
#endif

#endif /* __Q_formats_multimedia_container_Microsoft_Wave_H__ */
