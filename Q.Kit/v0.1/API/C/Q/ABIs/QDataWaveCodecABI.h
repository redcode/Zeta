/* Q C API - ABIs/QDataWaveCodecABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_ABIs_QDataWaveCodecABI_H__
#define __Q_ABIs_QDataWaveCodecABI_H__

#include <Q/types/base.h>

typedef struct {
	struct {void* input;
		void* output;
	} buffers;

	struct {quint32 resolution;
		quint16 channel_count;
		QType	sample_fixed_type;
	} wave;

	struct {quint8 content :2;
	} status;
} QDataWaveCodecContext;

#define Q_DATA_WAVE_CODEC_CONTEXT(p) ((QDataWaveCodecContext *)(p))

#define Q_DATA_WAVE_CONTENT_SILENCE		0
#define Q_DATA_WAVE_CONTENT_CONTROL_SEQUENCE	1
#define Q_DATA_WAVE_CONTENT_DATA_BLOCK		2

typedef struct {
	qsize (* encode) (QDataWaveContext* context, qsize sample_count);
	qsize (* decode) (QDataWaveContext* context, qsize sample_count);

	qsize encoding_context_size;
	qsize decoding_context_size;
} QDataWaveCodecABI;

#define Q_DATA_WAVE_CODEC_ABI(p) ((QDataWaveCodecABI *)(p))

#endif /* __Q_ABIs_QDataWaveCodecABI_H__ */
