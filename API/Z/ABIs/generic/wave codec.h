/* Z Kit - ABIs/generic/wave codec.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_ABIs_generic_wave_codec_H_
#define _Z_ABIs_generic_wave_codec_H_

#include <Z/types/base.h>
#include <Z/macros/key.h>
#include <Z/keys/value.h>

#define Z_WAVE_CODEC_STATE_CAN_DISCARD_INPUT
#define Z_WAVE_CODEC_STATE_CAN_DISCARD_OUTPUT

#define Z_KEY_BITS_WAVE_CODEC_STATE 8
#define Z_KEY_LAST_WAVE_CODEC_STATE Z_WAVE_CODEC_STATE_CAN_DISCARD_OUTPUT

typedef struct {
	void*		       input;
	void*		       output;
	zuint32		       resolution;
	zuint16		       channel_count;
	ZKey(VALUE_TYPE)       sample_fixed_type;
	ZKey(WAVE_CODEC_STATE) state;
	ZStatus		       status;
} ZWaveCodecSC;

typedef zusize (* ZWaveCodecProcess)(ZWaveCodecSC *sc, zusize sample_count);

typedef struct {
	ZWaveCodecProcess encode;
	ZWaveCodecProcess decode;
	zusize		  encoding_context_size;
	zusize		  decoding_context_size;
} ZWaveCodecABI;

#endif /* _Z_ABIs_generic_wave_codec_H_ */
