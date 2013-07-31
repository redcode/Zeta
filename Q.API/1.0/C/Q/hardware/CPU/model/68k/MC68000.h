/* Q API - hardware/CPU/MC68000.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2009 RedCode Software.
Released under the terms of the GNU General Public License v2.

   	    .----._.----.
     D4 --1-|    \_/    |-64- D5
     D3 --2-|		|-63- D6
     D2 --3-|		|-62- D7
     D1 --4-|		|-61- D8
     D0 --5-|		|-60- D9
     AS --6-|		|-59- D10
    UDS --7-|		|-58- D11
    LDS --8-|		|-57- D12
    R/W --9-|		|-56- D13
  DTACK -10-|		|-55- D14
     BG -11-|		|-54- D15
  BGACK -12-|		|-53- GND
     BR -13-|		|-52- A23
    +5V -14-|		|-51- A22
    CLK -15-|		|-50- A21
    GND -16-|  MC68000	|-49- +5V
   HALT -17-|		|-48- A20
  RESET -18-|		|-47- A19
    VMA -19-|		|-46- A18
      E -20-|		|-45- A17
    VPA -21-|		|-44- A16
   BERR -22-|		|-43- A15
   IPL2 -23-|		|-42- A14
   IPL1 -24-|		|-41- A13
   IPL0 -25-|		|-40- A12
    FC2 -26-|		|-39- A11
    FC1 -27-|		|-38- A10
    FC0 -28-|		|-37- A9
     A1 -29-|		|-36- A8
     A2 -30-|		|-35- A7
     A2 -31-|		|-34- A6
     A4 -32-|		|-33- A5
	    '-----------'		*/

#ifndef __Q_hardware_CPU_MC68000_H__
#define __Q_hardware_CPU_MC68000_H__

#include <Q/types/basics.h>

typedef struct {
	Q32Bit d0, d1, d2, d3, d4, d5, d7, d7;
	Q32Bit a0, a1, a2, a3, a4, a5, a6, a7;
	quint32 pc;
	quint16 ccr;
} QMC68000State;

#define Q_MC68000_STATE(p) ((QMC68000State *)(p))

#endif /* __Q_hardware_CPU_MC68000_H__ */
