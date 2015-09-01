/* Z Kit C API - ABIs/ZDataWaveCodecABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_ZDataWaveCodecABI_H__
#define __Z_ABIs_ZDataWaveCodecABI_H__

#include <Z/types/base.h>

typedef struct {
	struct {void* input;
		void* output;
	} buffers;

	struct {zuint32 resolution;
		zuint16 channel_count;
		ZType	sample_fixed_type;
	} wave;

	struct {zuint8 content :2;
	} status;
} ZDataWaveCodecContext;

#define Z_DATA_WAVE_CONTENT_SILENCE		0
#define Z_DATA_WAVE_CONTENT_CONTROL_SEQUENCE	1
#define Z_DATA_WAVE_CONTENT_DATA_BLOCK		2

typedef struct {
	zsize (* encode) (ZDataWaveContext* context, zsize sample_count);
	zsize (* decode) (ZDataWaveContext* context, zsize sample_count);

	zsize encoding_context_size;
	zsize decoding_context_size;
} ZDataWaveCodecABI;

#endif /* __Z_ABIs_ZDataWaveCodecABI_H__ */
