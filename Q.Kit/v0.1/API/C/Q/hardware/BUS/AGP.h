/* Q Kit API - hardware/BUS/AGP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_hardware_BUS_AGP_H__
#define __Q_hardware_BUS_AGP_H__

#define Q_AGP_COMMAND_READ		      0x0
#define Q_AGP_COMMAND_READ_HIGH_PRIORITY      0x1
/* Reserved 0x2 - 0x3 */
#define Q_AGP_COMMAND_WRITE		      0x4
#define Q_AGP_COMMAND_WRITE_HIGH_PRIORITY     0x5
/* Reserved 0x6 - 0x7 */
#define Q_AGP_COMMAND_LONG_READ		      0x8
#define Q_AGP_COMMAND_LONG_READ_HIGH_PRIORITY 0x9
#define Q_AGP_COMMAND_FLUSH		      0xA
/* Reserved 0xB */
#define Q_AGP_COMMAND_FENCE		      0xC
/* Reserved 0xD - 0xF */

#endif /* __Q_hardware_BUS_AGP_H__ */
