/* Q API - formats/hardware snapshot/machine/ZX Spectrum/ZX82.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.
 __________________________________________________________________________
/\									   \
\_| Extensions: .zx82							    |
  | Endianness: Big							    |
  | Created by: William James						    |
  | Used by:	Speculator '97 [Amiga]					    |
  |									    |
  | IMPORTANT NOTICE: This format is not well known at all,		    |
  | so the types and constants here declared can be useless.		    |
  | The only documentation I have found is from the SinclairFAQ.	    |
  |									    |
  | From SinclairFAQ:							    |
  |									    |
  | "  Amiga Speculator has its own file format called ZX82 format because  |
  | it contains a file identifier in the first four bytes consisting of the |
  | ASCII characters "ZX82". The format has a 12 byte header which contains |
  | the normal Spectrum type file information like length, type, start etc. |
  | as well as a compression flag which is set if the file is byte run	    |
  | compressed.								    |
  |									    |
  |   The 'data_type' field is derived from the MGT disciple directory	    |
  | MGT_Type-1, so further file types may be supported in this way in the   |
  | future.								    |
  |									    |
  |   The compression used is the standard byte run compression as used by  |
  | ILBM IFF files. The whole 48K data block is compressed as if it were    |
  | one long row.  "							    |
  |									    |
  | See:								    |
  |  Amiga ROM Kernel Reference Manual: Devices (Third Edition)		    |
  |   - Appendix A - IFF Specification (Page 347)			    |
  |   - Appendix C - Example Packer C code (Page 538)			    |
  |   ______________________________________________________________________|_
   \_/______________________________________________________________________*/

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_ZX82_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_ZX82_H__

#include <Q/types/base.h>

#define Q_ZX82_DATA_TYPE_BASIC	  0
#define Q_ZX82_DATA_TYPE_NUMERIC  1
#define Q_ZX82_DATA_TYPE_STRINC	  2
#define Q_ZX82_DATA_TYPE_CODE	  3
#define Q_ZX82_DATA_TYPE_SNAPSHOT 4

Q_DEFINE_STRICT_STRUCTURE (
	quint8	identifier[4];	 /* {'Z', 'X', '8', '2'} */
	quint8	data_type;
	quint8	data_compressed; /* boolean */
	quint16 data_size;	 /* File length up to 64k (ELINE-PROG for BASIC) */
	quint16 start_address;	 /* Start address for code (AUTOSTART for BASIC) */
	quint16 program_size;
) QZX82Header;

Q_DEFINE_STRICT_STRUCTURE_BEGIN
	quint8 border_color, im; /* (0 = use I register, 1 = IM 1 and 2 = IM 2) ??? */
	Q16Bit iy,  ix;
	Q16Bit de,  bc,  hl,  af;
	Q16Bit de_, bc_, hl_, af_, sp;
	Q16Bit i, r;
	Q16Bit pc;
Q_DEFINE_STRICT_STRUCTURE_END QZX82SnapshotHeader;

#define Q_ZX82_HEADER(	       p) ((QZX82Header		*)(p))
#define Q_ZX82_EXTENDED_HEADER(p) ((QZX82ExtendedHeader *)(p))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_ZX82_H__ */
