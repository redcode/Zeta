/* Z Kit C API - formats/multimedia container/Creative Voice.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_formats_multimedia_container_Creative_Voice_H__
#define __Z_formats_multimedia_container_Creative_Voice_H__

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	identifier[19];	      /* 'Creative Voice File'		  */
	zuint8	eof;		      /* 1Ah				  */
	zuint16	header_size;	      /* Usually 001Ah			  */
	zuint8	major_version_number; /* Usually 01h			  */
	zuint8	minor_version_number; /* Usually 0Ah or 14h		  */
	zuint8	version_validation;   /* must be equal to version + 1234h */
) ZCreativeVoiceHeader;

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	type;
	zuint16	size;
) ZCreativeVoiceBlockHeader;

#define Z_CREATIVE_VOICE_BLOCK_ID_TERMINATOR		   0x00
#define Z_CREATIVE_VOICE_BLOCK_ID_SOUND_DATA		   0x01
#define Z_CREATIVE_VOICE_BLOCK_ID_SOUND_DATA_CONTINUATION  0x02
#define Z_CREATIVE_VOICE_BLOCK_ID_SILENCE		   0x03
#define Z_CREATIVE_VOICE_BLOCK_ID_MARKER		   0x04
#define Z_CREATIVE_VOICE_BLOCK_ID_TEXT			   0x05
#define Z_CREATIVE_VOICE_BLOCK_ID_REPEAT_START		   0x06
#define Z_CREATIVE_VOICE_BLOCK_ID_REPEAT_END		   0x07
#define Z_CREATIVE_VOICE_BLOCK_ID_EXTRA_INFORMATION	   0x08
#define Z_CREATIVE_VOICE_BLOCK_ID_SOUND_DATA_IN_NEW_FORMAT 0x09

/* MARK: - ID 0 - Terminator */


/* MARK: - ID 1 - Sound Data */

Z_DEFINE_STRICT_STRUCTURE (
	zuint8 frequency_divisor;
	zuint8 codec_id;
	zuint8 data[];
) ZCreativeVoiceSoundData;

/* MARK: - ID 2 - Sound Data Continuation */

Z_DEFINE_STRICT_STRUCTURE (
	zuint8 data[];
) ZCreativeVoiceSoundDataContinuation;

/* MARK: - ID 3 - Silence */

Z_DEFINE_STRICT_STRUCTURE (
	zuint16 sample_count;
	zuint8	frequency_divisor;
) ZCreativeVoiceSilence;

/* MARK: - ID 4 - Marker */

Z_DEFINE_STRICT_STRUCTURE (
	zuint16 value;
) ZCreativeVoiceMarker;

/* MARK: - ID 5 - Text */

Z_DEFINE_STRICT_STRUCTURE (
	zuint8 content[]; /* 0 terminated string */
) ZCreativeVoiceText;

/* MARK: - ID 6 - Repeat Start */

Z_DEFINE_STRICT_STRUCTURE (
	zuint16 count_minus_1;
) ZCreativeVoiceRepeatStart;

/* MARK: - ID 7 - Repeat End */

/* MARK: - ID 8 - Extra Information */

Z_DEFINE_STRICT_STRUCTURE (
	zuint16	frequency_divisor;
	zuint8	codec_id;
	zuint8	channel_count_minus_1;
) ZCreativeVoiceExtraInformation;

/* MARK: - ID 9 - Sound Data in New Format */

Z_DEFINE_STRICT_STRUCTURE (
	zuint16 sample_rate;
	zuint8	bits_per_sample;
	zuint8	channel_Count;
	zuint16 codec_id;
	zuint32 reserved;
	zuint8	data[];
) ZCreativeVoiceSoundDataInNewFormat;

#endif /* __Z_formats_multimedia_container_Creative_Voice_H__ */
