/* Z Kit C API - ABIs/generic/wave codec.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_generic_wave_codec_H__
#define __Z_ABIs_generic_wave_codec_H__

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

typedef zsize (* ZWaveCodecEncode)(ZWaveCodecSC* sc, zsize sample_count);
typedef ZWaveCodecEncode ZWaveCodecDecode;

typedef struct {
	ZWaveCodecEncode encode;
	ZWaveCodecDecode decode;
	zsize		 encoding_context_size;
	zsize		 decoding_context_size;
} ZWaveCodecABI;

#endif /* __Z_ABIs_generic_wave_codec_H__ */
