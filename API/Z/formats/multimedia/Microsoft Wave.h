/* Z Kit - formats/multimedia/Microsoft Wave.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.--------------------------------------------------.
| Extensions: wav				   |
| Endianness: Little (fields), Litte or Big (data) |
| Created by: Microsoft				   |
'-------------------------------------------------*/

#ifndef _Z_formats_multimedia_Microsoft_Wave_H_
#define _Z_formats_multimedia_Microsoft_Wave_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint32 block_id;   /* 'RIFF' in big endian (if data is little-endian)
			       'RIFX' in big endian (if data is big-endian)    */
	zuint32 block_size; /* The size of the entire file minus 8 bytes       */
	zuint32 format;	    /* 'WAVE' in big-endian			       */

	struct {zuint32 subblock_id; /* 'fmt ' in big-endian */
		zuint32 subblock_size;
		zuint16 audio_format;
		zuint16 channel_count;
		zuint32 sample_rate;
		zuint32 byte_rate;
		zuint16 block_alignment;
		zuint16 bits_per_sample;
	} fmt;

	struct {zuint32 subblock_id; /* 'data' in big-endian */
		zuint32 subblock_size;
		Z_FLEXIBLE_ARRAY_MEMBER(Z_zuint8 samples[];)
	} data;
) ZMicrosoftWave;

#if Z_UINT32_ENDIANNESS == Z_ENDIANNESS_BIG
#	define Z_MICROSOFT_WAVE_BLOCK_ID	0x52494646
#	define Z_MICROSOFT_WAVE_FORMAT		0x57415645
#elif Z_UINT32_ENDIANNESS == Z_ENDIANNESS_LITTLE
#	define Z_MICROSOFT_WAVE_BLOCK_ID	0x46464952
#	define Z_MICROSOFT_WAVE_FORMAT		0x45564157
#endif

#endif /* _Z_formats_multimedia_Microsoft_Wave_H_ */
