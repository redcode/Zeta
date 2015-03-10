/* Q Kit C API - ABIs/QWaveCodecABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_ABIs_QWaveCodecABI_H__
#define __Q_ABIs_QWaveCodecABI_H__

#include <Q/types/base.h>

typedef quint8 QWaveCodecCommand;

#define Q_WAVE_CODEC_STATE_CAN_DISCARD_INPUT
#define Q_WAVE_CODEC_STATE_CAN_DISCARD_OUTPUT

typedef struct {
	void*		input;
	void*		output;
	quint32		resolution;
	quint16		channel_count;
	QType		sample_fixed_type;
	QWaveCodecState state;
	QStatus		status;
} QWaveCodecSC;


typedef struct {
	qsize	(* encode) (QWaveCodecSC* sc, qsize sample_count);
	qsize	(* decode) (QWaveCodecSC* sc, qsize sample_count);

	qsize encoding_context_size;
	qsize decoding_context_size;
} QWaveCodecABI;

#define Q_WAVE_CODEC_ABI(p) ((QWaveCodecABI *)(p))

#endif /* __Q_ABIs_QWaveCodecABI_H__ */
