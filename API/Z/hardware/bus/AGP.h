/* Z Kit - hardware/bus/AGP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_hardware_bus_AGP_H_
#define _Z_hardware_bus_AGP_H_

#define Z_AGP_COMMAND_READ		      0x0
#define Z_AGP_COMMAND_READ_HIGH_PRIORITY      0x1
/* Reserved 0x2 - 0x3 */
#define Z_AGP_COMMAND_WRITE		      0x4
#define Z_AGP_COMMAND_WRITE_HIGH_PRIORITY     0x5
/* Reserved 0x6 - 0x7 */
#define Z_AGP_COMMAND_LONG_READ		      0x8
#define Z_AGP_COMMAND_LONG_READ_HIGH_PRIORITY 0x9
#define Z_AGP_COMMAND_FLUSH		      0xA
/* Reserved 0xB */
#define Z_AGP_COMMAND_FENCE		      0xC
/* Reserved 0xD - 0xF */

#endif /* _Z_hardware_bus_AGP_H_ */
