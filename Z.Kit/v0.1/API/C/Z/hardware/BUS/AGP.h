/* Z Kit C API - hardware/BUS/AGP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_BUS_AGP_H__
#define __Z_hardware_BUS_AGP_H__

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

#endif /* __Z_hardware_BUS_AGP_H__ */
