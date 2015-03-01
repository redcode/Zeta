/* Q API - hardware/storage medium/ROM cartridge/NES Game Pak.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_hardware_storage_medium_ROM_cartridge_NES_Game_Pak_H__
#define __Q_hardware_storage_medium_ROM_cartridge_NES_Game_Pak_H__

#include <Q/types/base.h>

Q_DEFINE_STRICT_STRUCTURE (

) QNESGamePakHeader;

#define Q_NES_GAME_PAK_HEADER(p) ((QNESGamePakHeader *)(p))

#endif /* __Q_hardware_storage_medium_ROM_cartridge_NES_Game_Pak_H__ */
