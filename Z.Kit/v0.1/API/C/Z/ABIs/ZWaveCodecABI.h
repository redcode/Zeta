/* Z Kit C API - ABIs/ZWaveCodecABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_ZWaveCodecABI_H__
#define __Z_ABIs_ZWaveCodecABI_H__

#include <Z/types/base.h>

typedef zuint8 ZWaveCodecCommand;

#define Z_WAVE_CODEC_STATE_CAN_DISCARD_INPUT
#define Z_WAVE_CODEC_STATE_CAN_DISCARD_OUTPUT

typedef struct {
	void*		input;
	void*		output;
	zuint32		resolution;
	zuint16		channel_count;
	ZType		sample_fixed_type;
	ZWaveCodecState state;
	ZStatus		status;
} ZWaveCodecSC;


typedef struct {
	zsize	(* encode) (ZWaveCodecSC* sc, zsize sample_count);
	zsize	(* decode) (ZWaveCodecSC* sc, zsize sample_count);

	zsize encoding_context_size;
	zsize decoding_context_size;
} ZWaveCodecABI;

#define Z_WAVE_CODEC_ABI(p) ((ZWaveCodecABI *)(p))

#endif /* __Z_ABIs_ZWaveCodecABI_H__ */
