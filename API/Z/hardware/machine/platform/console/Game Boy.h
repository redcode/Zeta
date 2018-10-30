/* Z Kit - hardware/machine/platform/console/Game Boy.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library  is free software: you  can redistribute it and/or  modify it under
the terms  of the  GNU Lesser General  Public License as  published by  the Free
Software Foundation,  either version 3 of  the License, or (at  your option) any
later version.

This library is distributed in the hope  that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty  of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser  General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>.

.--------------------------------------.
|   Vendor: Nintendo		       |
| Released: 1989-04-21 (JP)	       |
|	    1989-07-31 (North America) |
|	    1990-09-28 (Europe)	       |
|      CPU: Sharp LR35902 @ 4.19 MHz   |
'--------------------------------------'

Front view		Back view
 _n__________________	 __________________n_
|_|________________|_|	|   |		=|   |
|  ________________  |	|   |		 |   |
| |   __________   | |	| O |		 | O |
| | .|		|  | |	|   |____________|   |
| |  |		|  | |	|  |		  |  |
| |  |		|  | |	|  |   G0502050   |  |
| |  |		|  | |	|  |  |	       |  |  |
| |  '__________'  | |	|  |  |________|  |  |
| '_______________/  |	| O| 		  |O |
|   _ GAME BOY™	     |	|==|=====.--.=====|==|
| _| |_		  _  |	|==|.----|  |----.|==|
||_ O _|       _ (_) |	|==||============||==|
|  |_|	      (_)  A |	|==||============||==|
|    _	_	B    |	|==||============||==|
|   // //	     |	|==||============||==|
|	     \\\\\\  |	|  ||		 ||  |
|	      \\\\\\ /	\  '|____________|'  |
'_________..________/	 \___________________' */

#ifndef _Z_hardware_machine_platform_console_Game_Boy_H_
#define _Z_hardware_machine_platform_console_Game_Boy_H_

#include <Z/types/base.h>

/* MARK: - Screen */

#define Z_GAME_BOY_SCREEN_FPS	 59.7
#define Z_GAME_BOY_SCREEN_WIDTH	 160
#define Z_GAME_BOY_SCREEN_HEIGHT 144
#define Z_GAME_BOY_SCREEN_PIXELS 23040 /* 160 * 144 */

#endif /* _Z_hardware_machine_platform_console_Game_Boy_H_ */
