/* Z Kit C API - formats/archive/9z.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.
 _____________________________________________
/\					      \
\_| Extensions: .9z			       |
  | Endianness: Big			       |
  | Created by: Manuel Sainz de Baranda y Goñi |
  | Used by:	9-Zip			       |
  |   _________________________________________|_
   \_/_________________________________________*/

#ifndef __Z_formats_archive_9z_H__
#define __Z_formats_archive_9z_H__

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint16 signature; /* '9z' */
	zuint16 format_version;
	zuint16 flags;
	zuint32 item_count;
) Z9zHeader;

Z_DEFINE_STRICT_STRUCTURE (
	zuint64 size;

	struct {Z_BIT_FIELD(16) (
		zuint16 directory	  :1;
		zuint16 link		  :1;
		zuint16 creation_time	  :1; /* attoseconds since Epoch */
		zuint16 modification_time :1; /* attoseconds since Epoch */
		zuint16 compression	  :1;
		zuint16 cipher		  :1;
	)} flags;
) Z9zItemHeader;

#define Z_9Z_COMPRESSION_NONE	   0
#define Z_9Z_COMPRESSION_DEFLATE 0
#define Z_9Z_COMPRESSION_LZMA	   0
#define Z_9Z_COMPRESSION_PAQ8	   0
#define Z_9Z_COMPRESSION_PAQ9	   0
#define Z_9Z_COMPRESSION_RAR	   0

#endif /* __Z_formats_archive_9z_H__ */
