/* Q API - formats/multimedia container/Creative Voice.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_formats_multimedia_container_Creative_Voice_H__
#define __Q_formats_multimedia_container_Creative_Voice_H__

#include <Q/types/basics.h>

typedef Q_STRICT_STRUCTURE (
	quint8	identifier[19];		/* 'Creative Voice File' */
	quint8	eof;			/* 1Ah			 */
	quint16	header_size;		/* Usually 001Ah	 */
	quint8	major_version_number;	/* Usually 01h		 */
	quint8	minor_version_number;	/* Usually 0Ah or 14h	 */
	quint8	version_validation;	/* must be equal to version + 1234h */
) QCreativeVoiceHeader;

typedef Q_STRICT_STRUCTURE (
	quint8	type;
	quint16	size;
) QCreativeVoiceBlockHeader;

#define Q_CREATIVE_VOICE_BLOCK_ID_TERMINATOR			0x00
#define Q_CREATIVE_VOICE_BLOCK_ID_SOUND_DATA			0x01
#define Q_CREATIVE_VOICE_BLOCK_ID_SOUND_DATA_CONTINUATION	0x02
#define Q_CREATIVE_VOICE_BLOCK_ID_SILENCE			0x03
#define Q_CREATIVE_VOICE_BLOCK_ID_MARKER			0x04
#define Q_CREATIVE_VOICE_BLOCK_ID_TEXT				0x05
#define Q_CREATIVE_VOICE_BLOCK_ID_REPEAT_START			0x06
#define Q_CREATIVE_VOICE_BLOCK_ID_REPEAT_END			0x07
#define Q_CREATIVE_VOICE_BLOCK_ID_EXTRA_INFORMATION		0x08
#define Q_CREATIVE_VOICE_BLOCK_ID_SOUND_DATA_IN_NEW_FORMAT	0x09

#pragma mark - ID 0 - Terminator


#pragma mark - ID 1 - Sound Data

typedef Q_STRICT_STRUCTURE (
	quint8 frequency_divisor;
	quint8 codec_id;
	quint8 data[];
) QCreativeVoiceSoundData;

#pragma mark - ID 2 - Sound Data Continuation

typedef Q_STRICT_STRUCTURE (
	quint8 data[];
) QCreativeVoiceSoundDataContinuation;

#pragma mark - ID 3 - Silence

typedef Q_STRICT_STRUCTURE (
	quint16 sample_count;
	quint8	frequency_divisor;
) QCreativeVoiceSilence;

#pragma mark - ID 4 - Marker

typedef Q_STRICT_STRUCTURE (
	quint16 value;
) QCreativeVoiceMarker;

#pragma mark - ID 5 - Text

typedef Q_STRICT_STRUCTURE (
	quint8 content[];		/* 0 terminated string */
) QCreativeVoiceText;

#pragma mark - ID 6 - Repeat Start

typedef Q_STRICT_STRUCTURE (
	quint16 count_minus_1;
) QCreativeVoiceRepeatStart;

#pragma mark - ID 7 - Repeat End

#pragma mark - ID 8 - Extra Information

typedef Q_STRICT_STRUCTURE (
	quint16	frequency_divisor;
	quint8	codec_id;
	quint8	channel_count_minus_1;
) QCreativeVoiceExtraInformation;

#pragma mark - ID 9 - Sound Data in New Format

typedef Q_STRICT_STRUCTURE (
	quint16 sample_rate;
	quint8	bits_per_sample;
	quint8	channel_Count;
	quint16 codec_id;
	quint32 reserved;
	quint8	data[];
) QCreativeVoiceSoundDataInNewFormat;


#define Q_CREATIVE_VOICE_HEADER(		  p)	((QCreativeVoiceHeader		      *)(p))
#define Q_CREATIVE_VOICE_BLOCK_HEADER(		  p)	((QCreativeVoiceBlockHeader	      *)(p))
#define Q_CREATIVE_VOICE_SOUND_DATA(		  p)	((QCreativeVoiceSoundData	      *)(p))
#define Q_CREATIVE_VOICE_SOUND_DATA_CONTINUATION( p)	((QCreativeVoiceSoundDataContinuation *)(p))
#define Q_CREATIVE_VOICE_SILENCE(		  p)	((QCreativeVoiceSilence		      *)(p))
#define Q_CREATIVE_VOICE_MARKER(		  p)	((QCreativeVoiceMarker		      *)(p))
#define Q_CREATIVE_VOICE_TEXT(			  p)	((QCreativeVoiceText		      *)(p))
#define Q_CREATIVE_VOICE_REPEAT_START(		  p)	((QCreativeVoiceRepeatStart	      *)(p))
#define Q_CREATIVE_VOICE_EXTRA_INFORMATION(	  p)	((QCreativeVoiceExtraInformation      *)(p))
#define Q_CREATIVE_VOICE_SOUND_DATA_IN_NEW_FORMAT(p)	((QCreativeVoiceSoundDataInNewFormat  *)(p))

#endif /* __Q_formats_multimedia_container_Creative_Voice_H__ */
