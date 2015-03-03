/* Q API - formats/multimedia container/Creative Voice.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_formats_multimedia_container_Creative_Voice_H__
#define __Q_formats_multimedia_container_Creative_Voice_H__

#include <Q/types/base.h>

Q_DEFINE_STRICT_STRUCTURE (
	quint8	identifier[19];		/* 'Creative Voice File' */
	quint8	eof;			/* 1Ah			 */
	quint16	header_size;		/* Usually 001Ah	 */
	quint8	major_version_number;	/* Usually 01h		 */
	quint8	minor_version_number;	/* Usually 0Ah or 14h	 */
	quint8	version_validation;	/* must be equal to version + 1234h */
) QCreativeVoiceHeader;

Q_DEFINE_STRICT_STRUCTURE (
	quint8	type;
	quint16	size;
) QCreativeVoiceBlockHeader;

#define Q_CREATIVE_VOICE_BLOCK_ID_TERMINATOR		   0x00
#define Q_CREATIVE_VOICE_BLOCK_ID_SOUND_DATA		   0x01
#define Q_CREATIVE_VOICE_BLOCK_ID_SOUND_DATA_CONTINUATION  0x02
#define Q_CREATIVE_VOICE_BLOCK_ID_SILENCE		   0x03
#define Q_CREATIVE_VOICE_BLOCK_ID_MARKER		   0x04
#define Q_CREATIVE_VOICE_BLOCK_ID_TEXT			   0x05
#define Q_CREATIVE_VOICE_BLOCK_ID_REPEAT_START		   0x06
#define Q_CREATIVE_VOICE_BLOCK_ID_REPEAT_END		   0x07
#define Q_CREATIVE_VOICE_BLOCK_ID_EXTRA_INFORMATION	   0x08
#define Q_CREATIVE_VOICE_BLOCK_ID_SOUND_DATA_IN_NEW_FORMAT 0x09

/* MARK: - ID 0 - Terminator */


/* MARK: - ID 1 - Sound Data */

Q_DEFINE_STRICT_STRUCTURE (
	quint8 frequency_divisor;
	quint8 codec_id;
	quint8 data[];
) QCreativeVoiceSoundData;

/* MARK: - ID 2 - Sound Data Continuation */

Q_DEFINE_STRICT_STRUCTURE (
	quint8 data[];
) QCreativeVoiceSoundDataContinuation;

/* MARK: - ID 3 - Silence */

Q_DEFINE_STRICT_STRUCTURE (
	quint16 sample_count;
	quint8	frequency_divisor;
) QCreativeVoiceSilence;

/* MARK: - ID 4 - Marker */

Q_DEFINE_STRICT_STRUCTURE (
	quint16 value;
) QCreativeVoiceMarker;

/* MARK: - ID 5 - Text */

Q_DEFINE_STRICT_STRUCTURE (
	quint8 content[]; /* 0 terminated string */
) QCreativeVoiceText;

/* MARK: - ID 6 - Repeat Start */

Q_DEFINE_STRICT_STRUCTURE (
	quint16 count_minus_1;
) QCreativeVoiceRepeatStart;

/* MARK: - ID 7 - Repeat End */

/* MARK: - ID 8 - Extra Information */

Q_DEFINE_STRICT_STRUCTURE (
	quint16	frequency_divisor;
	quint8	codec_id;
	quint8	channel_count_minus_1;
) QCreativeVoiceExtraInformation;

/* MARK: - ID 9 - Sound Data in New Format */

Q_DEFINE_STRICT_STRUCTURE (
	quint16 sample_rate;
	quint8	bits_per_sample;
	quint8	channel_Count;
	quint16 codec_id;
	quint32 reserved;
	quint8	data[];
) QCreativeVoiceSoundDataInNewFormat;

/* MARK: - Casts */

#define Q_CREATIVE_VOICE_HEADER(		  p) ((QCreativeVoiceHeader		   *)(p))
#define Q_CREATIVE_VOICE_BLOCK_HEADER(		  p) ((QCreativeVoiceBlockHeader	   *)(p))
#define Q_CREATIVE_VOICE_SOUND_DATA(		  p) ((QCreativeVoiceSoundData		   *)(p))
#define Q_CREATIVE_VOICE_SOUND_DATA_CONTINUATION( p) ((QCreativeVoiceSoundDataContinuation *)(p))
#define Q_CREATIVE_VOICE_SILENCE(		  p) ((QCreativeVoiceSilence		   *)(p))
#define Q_CREATIVE_VOICE_MARKER(		  p) ((QCreativeVoiceMarker		   *)(p))
#define Q_CREATIVE_VOICE_TEXT(			  p) ((QCreativeVoiceText		   *)(p))
#define Q_CREATIVE_VOICE_REPEAT_START(		  p) ((QCreativeVoiceRepeatStart	   *)(p))
#define Q_CREATIVE_VOICE_EXTRA_INFORMATION(	  p) ((QCreativeVoiceExtraInformation      *)(p))
#define Q_CREATIVE_VOICE_SOUND_DATA_IN_NEW_FORMAT(p) ((QCreativeVoiceSoundDataInNewFormat  *)(p))

#endif /* __Q_formats_multimedia_container_Creative_Voice_H__ */
