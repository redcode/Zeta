/* Z Kit - ABIs/generic/wave codec.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library.  If not, see <http://www.gnu.org/licenses/>. */

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
