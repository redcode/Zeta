/* Z Kit - hardware/PSG/General Instrument/AY-3-891x.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

		     .----._.----.
       Vss (GND) -01-|	  \_/	 |-40- Vcc (+5V)
	    N.C. -02-|		 |-39- TEST 1
ANALOG CHANNEL B -03-|     _	 |-38- ANALOG CHANNEL C
ANALOG CHANNEL A -04-|	  (_)	 |-37- DA0
	    N.C. -05-|		 |-36- DA1
	    IOB7 -06-|		 |-35- DA2
	    IOB6 -07-|		 |-34- DA3
	    IOB5 -08-|		 |-33- DA4
	    IOB4 -09-|		 |-32- DA5
	    IOB3 -10-|	 SOUND	 |-31- DA6
	    IOB2 -11-| AY-3-8910 |-30- DA7
	    IOB1 -12-|		 |-29- BC1
	    IOB0 -13-| GI	 |-28- BC2
	    IOA7 -14-|		 |-27- BDIR
	    IOA6 -15-|		 |-26- TEST 2
	    IOA5 -16-|	   _	 |-25- A8
	    IOA4 -17-|	  (_)	 |-24- A9
	    IOA3 -18-|		 |-23- RESET
	    IOA2 -19-|		 |-22- CLOCK
	    IOA1 -20-|		 |-21- IOA0
		     '-----------'

		     .----._.----.
ANALOG CHANNEL C -01-|	  \_/	 |-28- DA0
	  TEST 1 -02-|		 |-27- DA1
       Vcc (+5V) -03-|		 |-26- DA2
ANALOG CHANNEL B -04-|		 |-25- DA3
ANALOG CHANNEL A -05-|		 |-24- DA4
       Vss (GND) -06-|	 SOUND	 |-23- DA5
	    IOA7 -07-| AY-3-8912 |-22- DA6
	    IOA6 -08-|		 |-21- DA7
	    IOA5 -09-| GI	 |-20- BC1
	    IOA4 -10-|		 |-19- BC2
	    IOA3 -11-|		 |-18- BDIR
	    IOA2 -12-|		 |-17- A8
	    IOA1 -13-|		 |-16- RESET
	    IOA0 -14-|		 |-15- CLOCK
		     '-----------'

		     .----._.----.
       Vss (GND) -01-|	  \_/	 |-24- CHIP SELECT
	    BDIR -02-|		 |-23- A8
 	     BC1 -03-|		 |-22- A9
 	     DA7 -04-|		 |-21- RESET
 	     DA6 -05-|		 |-20- CLOCK
 	     DA5 -06-|	 SOUND	 |-19- Vss (GND)
 	     DA4 -07-| AY-3-8913 |-18- ANALOG C
 	     DA3 -08-|		 |-17- ANALOG A
 	     DA2 -09-| GI	 |-16- NO CONNECT
 	     DA1 -10-|		 |-15- ANALOG B
 	     DA0 -11-|		 |-14- TEST IN
	TEST OUT -12-|		 |-13- Vcc
		     '-----------'

						   Content
			      .-----------------------------------------------.
	      Register	      |	 7  |  6  |  5	|  4  |	 3  |  2  |  1	|  0  |
.-----------------------------+-----------------------------------------------|
| R0  |			      |		      8-Bit Fine Tune A		      |
|-----| Channel A Tone Period |-----------------------------------------------|
| R1  |			      | ///////////////////// |  4-Bit Coarse Tune A  |
|-----+-----------------------+-----------------------------------------------|
| R2  |			      |		      8-Bit Fine Tune B		      |
|-----| Channel B Tone Period |-----------------------------------------------|
| R3  |			      | ///////////////////// |  4-Bit Coarse Tune B  |
|-----+-----------------------+-----------------------------------------------|
| R4  |			      |		      8-Bit Fine Tune C		      |
|-----| Channel C Tone Period |-----------------------------------------------|
| R5  |			      | ///////////////////// |  4-Bit Coarse Tune C  |
|-----+-----------------------+-----------------------------------------------|
| R6  | Noise Period	      | /////////////// |    5-Bit Period Control     |
|-----+-----------------------+-----------------------------------------------|
| R7  | Enable		      |	 IN OUT	  |	 Noise	    |	   Noise      |
|     |			      |-----------+-----------------+-----------------|
|     |			      | IOB | IOA |  C	|  B  |  A  |  C  |  B  |  A  |
|-----+-----------------------+-----------------+-----+-----+-----+-----+-----|
| R10 | Channel A Amplitude   | /////////////// |  M  |  L3 |  L2 |  L1 |  L0 |
|-----+-----------------------+-----------------+-----+-----+-----+-----+-----|
| R11 | Channel B Amplitude   | /////////////// |  M  |  L3 |  L2 |  L1 |  L0 |
|-----+-----------------------+-----------------+-----+-----+-----+-----+-----|
| R12 | Channel C Amplitude   | /////////////// |  M  |  L3 |  L2 |  L1 |  L0 |
|-----+-----------------------+-----------------------------------------------|
| R13 |			      |		      8-Bit Fine Tune E		      |
|-----| Envelope Period	      |-----------------------------------------------|
| R14 |			      |		     8-Bit Coarse Tune E	      |
|-----+-----------------------+-----------------------------------------------|
| R15 | Envelope Shape Cycle  | ///////////////////// | CONT| ATT | ALT | HOLD|
|-----+-----------------------+-----------------------------------------------|
| R16 | I/O Port A Data Store |		 8-Bit Parallel I/O on Port A	      |
|-----+-----------------------+-----------------------------------------------|
| R17 | I/O Port B Data Store |		 8-Bit Parallel I/O on Port A	      |
'----------------------------------------------------------------------------*/

#ifndef _Z_hardware_PSG_General_Instrument_AY_3_891x_H_
#define _Z_hardware_PSG_General_Instrument_AY_3_891x_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (Z_BIT_FIELD(8, 8) (
	zuint8 unused0 :1,
	zuint8 unused1 :1,
	zuint8 unused2 :1,
	zuint8 m       :1,
	zuint8 l3      :1,
	zuint8 l2      :1,
	zuint8 l1      :1,
	zuint8 l0      :1
)) ZAY3891xAmplitude;

Z_DEFINE_STRICT_UNION (
	zuint8 registers[16];

	struct {zuint8 channel_a_tone_period_fine_tune;
		zuint8 channel_a_tone_period_coarse_tune;
		zuint8 channel_b_tone_period_fine_tune;
		zuint8 channel_b_tone_perid_coarse_tune;
		zuint8 channel_c_tone_period_fine_tune;
		zuint8 channel_c_tone_period_coarse_tune;
		zuint8 noise_period;

		struct {Z_BIT_FIELD(8, 8) (
			zuint8 iob     :1,
			zuint8 ioa     :1,
			zuint8 noise_c :1,
			zuint8 noise_b :1,
			zuint8 noise_a :1,
			zuint8 tone_c  :1,
			zuint8 tone_b  :1,
			zuint8 tone_a  :1
		)} enable;

		ZAY3891xAmplitude channel_a_amplitude;
		ZAY3891xAmplitude channel_b_amplitude;
		ZAY3891xAmplitude channel_c_amplitude;

		zuint8 envelope_period_fine_tune;
		zuint8 envelope_period_coarse_tune;

		struct {Z_BIT_FIELD(8, 8) (
			zuint8 unused0 :1,
			zuint8 unused1 :1,
			zuint8 unused2 :1,
			zuint8 unused3 :1,
			zuint8 cont    :1,
			zuint8 att     :1,
			zuint8 alt     :1,
			zuint8 hold    :1
		)} envelope_shape_cycle;

		zuint8 io_port_a_data_store;
		zuint8 io_port_b_data_store;
	} values;
) ZAY3891xState;

#define Z_AY_3_891X_CHANNEL_A_TONE_PERIOD_FINE_TUNE    0
#define Z_AY_3_891X_CHANNEL_A_TONE_PERIOD_COARSE_TUNE  1
#define Z_AY_3_891X_CHANNEL_B_TONE_PERIOD_FINE_TUNE    2
#define Z_AY_3_891X_CHANNEL_B_TONE_PERID_COARSE_TUNE   3
#define Z_AY_3_891X_CHANNEL_C_TONE_PERIOD_FINE_TUNE    4
#define Z_AY_3_891X_CHANNEL_C_TONE_PERIOD_COARSE_TUNE  5
#define Z_AY_3_891X_NOISE_PERIOD		       6
#define Z_AY_3_891X_ENABLEE			       7
#define Z_AY_3_891X_CHANNEL_A_AMPLITUDE		       8
#define Z_AY_3_891X_CHANNEL_B_AMPLITUDE		       9
#define Z_AY_3_891X_CHANNEL_C_AMPLITUDE		      10
#define Z_AY_3_891X_ENVELOPE_PERIOD_FINE_TUNE	      11
#define Z_AY_3_891X_ENVELOPE_PERIOD_COARSE_TUNE	      12
#define Z_AY_3_891X_ENVELOPE_SHAPE_CYCLE	      13
#define Z_AY_3_891X_IO_PORT_A_DATA_STORE	      14
#define Z_AY_3_891X_IO_PORT_B_DATA_STORE	      15

#endif /* _Z_hardware_PSG_General_Instrument_AY_3_891x_H_ */
