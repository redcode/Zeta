/* Q API - hardware/storage medium/ROM cartridge//SNES Game Pak.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_hardware_storage_medium_ROM_cartridge_SNES_Game_Pak_H__
#define __Q_hardware_storage_medium_ROM_cartridge_SNES_Game_Pak_H__

#include <Q/types/basics.h>

Q_DEFINE_STRICT_STRUCTURE (
	QString	name[21];
	quint8	layout;
	quint8	type;
	quint8	rom_size;
	quint8	ram_size;
	quint8	region;
	quint8	license;
	quint8	version;
	quint16	checksum;
	quint16	snes_checksum;
	quint8	unknown1[4];
	quint8	native_cop_interrupt_rutine_pointer;
	quint8	native_brk_interrupt_rutine_pointer;
	quint8	native_abort_interrupt_rutine_pointer;
	quint8	native_unused;
	quint8	native_irq_interrupt_rutine_pointer;
	quint8	unknown2[4];
	quint8	emulation_cop_interrupt_rutine_pointer;
	quint8	emulation_unused;
	quint8	emulation_abort_interrupt_rutine_pointer;
	quint8	emulation_nmi_interrupt_rutine_pointer;
	quint8	emulation_reset_interrupt_rutine_pointer;
	quint8	emulation_irq_or_brk_interrupt_rutine_pointer;
) QSNESGamePakHeader;

#define Q_SNES_GAME_PAK_LAYOUT_LO_ROM					0x20
#define Q_SNES_GAME_PAK_LAYOUT_HI_ROM					0x21
#define Q_SNES_GAME_PAK_LAYOUT_LO_ROM_FAST				0x30
#define Q_SNES_GAME_PAK_LAYOUT_HI_ROM_FAST				0x31

#define Q_SNES_GAME_PAK_TYPE_ROM_ONLY					0x00
#define Q_SNES_GAME_PAK_TYPE_ROM_AND_RAM				0x01
#define Q_SNES_GAME_PAK_TYPE_ROM_AND_SAVE_RAM				0x02
#define Q_SNES_GAME_PAK_TYPE_ROM_AND_SUPER_FX_A				0x13
#define Q_SNES_GAME_PAK_TYPE_ROM_AND_SUPER_FX_B				0x14
#define Q_SNES_GAME_PAK_TYPE_ROM_SAVE_RAM_AND_SUPER_FX_A		0x15
#define Q_SNES_GAME_PAK_TYPE_ROM_SAVE_RAM_AND_SUPER_FX_B		0x1A
#define Q_SNES_GAME_PAK_TYPE_ROM_AND_SA_1_A				0x34
#define Q_SNES_GAME_PAK_TYPE_ROM_AND_SA_1_B				0x35

#define Q_SNES_GAME_PAK_MEMORY_SIZE_0					0x00
#define Q_SNES_GAME_PAK_MEMORY_SIZE_2_KIB				0x01
#define Q_SNES_GAME_PAK_MEMORY_SIZE_4_KIB				0x02
#define Q_SNES_GAME_PAK_MEMORY_SIZE_8_KIB				0x03
#define Q_SNES_GAME_PAK_MEMORY_SIZE_16_KIB				0x04
#define Q_SNES_GAME_PAK_MEMORY_SIZE_32_KIB				0x05
#define Q_SNES_GAME_PAK_MEMORY_SIZE_64_KIB				0x06
#define Q_SNES_GAME_PAK_MEMORY_SIZE_128_KIB				0x07
#define Q_SNES_GAME_PAK_MEMORY_SIZE_256_KIB				0x08
#define Q_SNES_GAME_PAK_MEMORY_SIZE_512_KIB				0x09
#define Q_SNES_GAME_PAK_MEMORY_SIZE_1_MIB				0x0A
#define Q_SNES_GAME_PAK_MEMORY_SIZE_2_MIB				0x0B
#define Q_SNES_GAME_PAK_MEMORY_SIZE_4_MIB				0x0C

#define Q_SNES_GAME_PAK_REGION_JAPAN					 0
#define Q_SNES_GAME_PAK_REGION_USA					 1
#define Q_SNES_GAME_PAK_REGION_AUSTRALIA_EUROPE_OCEANIA_AND_ASIA	 2
#define Q_SNES_GAME_PAK_REGION_SWEDEN					 3
#define Q_SNES_GAME_PAK_REGION_FINLAND					 4
#define Q_SNES_GAME_PAK_REGION_DENMARK					 5
#define Q_SNES_GAME_PAK_REGION_FRANCE					 6
#define Q_SNES_GAME_PAK_REGION_HOLLAND					 7
#define Q_SNES_GAME_PAK_REGION_SPAIN					 8
#define Q_SNES_GAME_PAK_REGION_GERMANY_AUSTRIA_AND_SWITZERLAND		 9
#define Q_SNES_GAME_PAK_REGION_ITALY					10
#define Q_SNES_GAME_PAK_REGION_HONG_KONG_AND_CHINA			11
#define Q_SNES_GAME_PAK_REGION_INDONESIA				12
#define Q_SNES_GAME_PAK_REGION_KOREA					13
/*
#define Q_SNES_GAME_PAK_LICENSE_Nintendo				  1
#define Q_SNES_GAME_PAK_LICENSE_Imagineer-Zoom				  3
#define Q_SNES_GAME_PAK_LICENSE_Zamuse					  5
#define Q_SNES_GAME_PAK_LICENSE_Falcom					  6
#define Q_SNES_GAME_PAK_LICENSE_Capcom					  8
#define Q_SNES_GAME_PAK_LICENSE_HOT-B					  9
#define Q_SNES_GAME_PAK_LICENSE_Jaleco					 10
#define Q_SNES_GAME_PAK_LICENSE_Coconuts				 11
#define Q_SNES_GAME_PAK_LICENSE_Rage Software				 12
#define Q_SNES_GAME_PAK_LICENSE_Technos					 14
#define Q_SNES_GAME_PAK_LICENSE_Mebio Software				 15
#define Q_SNES_GAME_PAK_LICENSE_Gremlin Graphics			 18
#define Q_SNES_GAME_PAK_LICENSE_Electronic Arts				 19
#define Q_SNES_GAME_PAK_LICENSE_COBRA Team				 21
#define Q_SNES_GAME_PAK_LICENSE_Human/Field				 22
#define Q_SNES_GAME_PAK_LICENSE_KOEI					 23
#define Q_SNES_GAME_PAK_LICENSE_Hudson Soft				 24
#define Q_SNES_GAME_PAK_LICENSE_Yanoman					 26
#define Q_SNES_GAME_PAK_LICENSE_Tecmo					 28
#define Q_SNES_GAME_PAK_LICENSE_Open System				 30
#define Q_SNES_GAME_PAK_LICENSE_Virgin Games				 31
#define Q_SNES_GAME_PAK_LICENSE_KSS					 32
#define Q_SNES_GAME_PAK_LICENSE_Sunsoft					 33
#define Q_SNES_GAME_PAK_LICENSE_POW					 34
#define Q_SNES_GAME_PAK_LICENSE_Micro World				 35
#define Q_SNES_GAME_PAK_LICENSE_Enix					 38
#define Q_SNES_GAME_PAK_LICENSE_Loriciel/Electro Brain			 39
#define Q_SNES_GAME_PAK_LICENSE_Kemco					 40
#define Q_SNES_GAME_PAK_LICENSE_Seta Co.,Ltd.				 41
#define Q_SNES_GAME_PAK_LICENSE_Visit Co.,Ltd.				 45
#define Q_SNES_GAME_PAK_LICENSE_Carrozzeria				 49
#define Q_SNES_GAME_PAK_LICENSE_Dynamic					 50
#define Q_SNES_GAME_PAK_LICENSE_Nintendo				 51
#define Q_SNES_GAME_PAK_LICENSE_Magifact				 52
#define Q_SNES_GAME_PAK_LICENSE_Hect					 53
#define Q_SNES_GAME_PAK_LICENSE_Empire Software				 60
#define Q_SNES_GAME_PAK_LICENSE_Loriciel				 61
#define Q_SNES_GAME_PAK_LICENSE_Seika Corp.				 64
#define Q_SNES_GAME_PAK_LICENSE_UBI Soft				 65
#define Q_SNES_GAME_PAK_LICENSE_System 3				 70
#define Q_SNES_GAME_PAK_LICENSE_Spectrum Holobyte			 71
#define Q_SNES_GAME_PAK_LICENSE_Irem					 73
#define Q_SNES_GAME_PAK_LICENSE_Raya Systems/Sculptured Software	 75
#define Q_SNES_GAME_PAK_LICENSE_Renovation Products			 76
#define Q_SNES_GAME_PAK_LICENSE_Malibu Games/Black Pearl		 77
#define Q_SNES_GAME_PAK_LICENSE_U.S. Gold				 79
#define Q_SNES_GAME_PAK_LICENSE_Absolute Entertainment			 80
#define Q_SNES_GAME_PAK_LICENSE_Acclaim					 81
#define Q_SNES_GAME_PAK_LICENSE_Activision				 82
#define Q_SNES_GAME_PAK_LICENSE_American Sammy				 83
#define Q_SNES_GAME_PAK_LICENSE_GameTek					 84
#define Q_SNES_GAME_PAK_LICENSE_Hi Tech Expressions			 85
#define Q_SNES_GAME_PAK_LICENSE_LJN Toys				 86
#define Q_SNES_GAME_PAK_LICENSE_Mindscape				 90
#define Q_SNES_GAME_PAK_LICENSE_Tradewest				 93
#define Q_SNES_GAME_PAK_LICENSE_American Softworks Corp.		 95
#define Q_SNES_GAME_PAK_LICENSE_Titus					 96
#define Q_SNES_GAME_PAK_LICENSE_Virgin Interactive Entertainment	 97
#define Q_SNES_GAME_PAK_LICENSE_Maxis					 98
#define Q_SNES_GAME_PAK_LICENSE_Ocean					103
#define Q_SNES_GAME_PAK_LICENSE_Electronic Arts				105
#define Q_SNES_GAME_PAK_LICENSE_Laser Beam				107
#define Q_SNES_GAME_PAK_LICENSE_Elite					110
#define Q_SNES_GAME_PAK_LICENSE_Electro Brain				111
#define Q_SNES_GAME_PAK_LICENSE_Infogrames				112
#define Q_SNES_GAME_PAK_LICENSE_Interplay				113
#define Q_SNES_GAME_PAK_LICENSE_LucasArts				114
#define Q_SNES_GAME_PAK_LICENSE_Parker Brothers				115
#define Q_SNES_GAME_PAK_LICENSE_STORM					117
#define Q_SNES_GAME_PAK_LICENSE_THQ Software				120
#define Q_SNES_GAME_PAK_LICENSE_Accolade Inc.				121
#define Q_SNES_GAME_PAK_LICENSE_Triffix Entertainment			122
#define Q_SNES_GAME_PAK_LICENSE_Microprose				124
#define Q_SNES_GAME_PAK_LICENSE_Kemco					127
#define Q_SNES_GAME_PAK_LICENSE_Misawa					128
#define Q_SNES_GAME_PAK_LICENSE_Teichio					129
#define Q_SNES_GAME_PAK_LICENSE_Namco Ltd.				130
#define Q_SNES_GAME_PAK_LICENSE_Lozc					131
#define Q_SNES_GAME_PAK_LICENSE_Koei					132
#define Q_SNES_GAME_PAK_LICENSE_Tokuma Shoten Intermedia		134
#define Q_SNES_GAME_PAK_LICENSE_DATAM-Polystar				136
#define Q_SNES_GAME_PAK_LICENSE_Bullet-Proof Software			139
#define Q_SNES_GAME_PAK_LICENSE_Vic Tokai				140
#define Q_SNES_GAME_PAK_LICENSE_Character Soft				142
#define Q_SNES_GAME_PAK_LICENSE_I''Max					143
#define Q_SNES_GAME_PAK_LICENSE_Takara					144
#define Q_SNES_GAME_PAK_LICENSE_CHUN Soft				145
#define Q_SNES_GAME_PAK_LICENSE_Video System Co., Ltd.			146
#define Q_SNES_GAME_PAK_LICENSE_BEC					147
#define Q_SNES_GAME_PAK_LICENSE_Varie					149
#define Q_SNES_GAME_PAK_LICENSE_Kaneco					151
#define Q_SNES_GAME_PAK_LICENSE_Pack in Video				153
#define Q_SNES_GAME_PAK_LICENSE_Nichibutsu				154
#define Q_SNES_GAME_PAK_LICENSE_TECMO					155
#define Q_SNES_GAME_PAK_LICENSE_Imagineer Co.				156
#define Q_SNES_GAME_PAK_LICENSE_Telenet					160
#define Q_SNES_GAME_PAK_LICENSE_Konami					164
#define Q_SNES_GAME_PAK_LICENSE_K.Amusement Leasing Co.			165
#define Q_SNES_GAME_PAK_LICENSE_Takara					167
#define Q_SNES_GAME_PAK_LICENSE_Technos Jap.				169
#define Q_SNES_GAME_PAK_LICENSE_JVC					170
#define Q_SNES_GAME_PAK_LICENSE_Toei Animation				172
#define Q_SNES_GAME_PAK_LICENSE_Toho					173
#define Q_SNES_GAME_PAK_LICENSE_Namco Ltd.				175
#define Q_SNES_GAME_PAK_LICENSE_ASCII Co. Activison			177
#define Q_SNES_GAME_PAK_LICENSE_BanDai America				178
#define Q_SNES_GAME_PAK_LICENSE_Enix					180
#define Q_SNES_GAME_PAK_LICENSE_Halken					182
#define Q_SNES_GAME_PAK_LICENSE_Culture Brain				186
#define Q_SNES_GAME_PAK_LICENSE_Sunsoft					187
#define Q_SNES_GAME_PAK_LICENSE_Toshiba EMI				188
#define Q_SNES_GAME_PAK_LICENSE_Sony Imagesoft				189
#define Q_SNES_GAME_PAK_LICENSE_Sammy					191
#define Q_SNES_GAME_PAK_LICENSE_Taito					192
#define Q_SNES_GAME_PAK_LICENSE_Kemco					194
#define Q_SNES_GAME_PAK_LICENSE_Square					195
#define Q_SNES_GAME_PAK_LICENSE_Tokuma Soft				196
#define Q_SNES_GAME_PAK_LICENSE_Data East				197
#define Q_SNES_GAME_PAK_LICENSE_Tonkin House				198
#define Q_SNES_GAME_PAK_LICENSE_KOEI					200
#define Q_SNES_GAME_PAK_LICENSE_Konami USA				202
#define Q_SNES_GAME_PAK_LICENSE_NTVIC					203
#define Q_SNES_GAME_PAK_LICENSE_Meldac					205
#define Q_SNES_GAME_PAK_LICENSE_Pony Canyon				206
#define Q_SNES_GAME_PAK_LICENSE_Sotsu Agency/Sunrise			207
#define Q_SNES_GAME_PAK_LICENSE_Disco/Taito				208
#define Q_SNES_GAME_PAK_LICENSE_Sofel					209
#define Q_SNES_GAME_PAK_LICENSE_Quest Corp.				210
#define Q_SNES_GAME_PAK_LICENSE_Sigma					211
#define Q_SNES_GAME_PAK_LICENSE_Naxat					214
#define Q_SNES_GAME_PAK_LICENSE_Capcom Co., Ltd.			216
#define Q_SNES_GAME_PAK_LICENSE_Banpresto				217
#define Q_SNES_GAME_PAK_LICENSE_Tomy					218
#define Q_SNES_GAME_PAK_LICENSE_Acclaim					219
#define Q_SNES_GAME_PAK_LICENSE_NCS					221
#define Q_SNES_GAME_PAK_LICENSE_Human Entertainment			222
#define Q_SNES_GAME_PAK_LICENSE_Altron					223
#define Q_SNES_GAME_PAK_LICENSE_Jaleco					224
#define Q_SNES_GAME_PAK_LICENSE_Yutaka					226
#define Q_SNES_GAME_PAK_LICENSE_T&ESoft					228
#define Q_SNES_GAME_PAK_LICENSE_EPOCH Co.,Ltd.				229
#define Q_SNES_GAME_PAK_LICENSE_Athena					231
#define Q_SNES_GAME_PAK_LICENSE_Asmik					232
#define Q_SNES_GAME_PAK_LICENSE_Natsume					233
#define Q_SNES_GAME_PAK_LICENSE_King Records				234
#define Q_SNES_GAME_PAK_LICENSE_Atlus					235
#define Q_SNES_GAME_PAK_LICENSE_Sony Music Entertainment		236
#define Q_SNES_GAME_PAK_LICENSE_IGS					238
#define Q_SNES_GAME_PAK_LICENSE_Motown Software				241
#define Q_SNES_GAME_PAK_LICENSE_Left Field Entertainment		242
#define Q_SNES_GAME_PAK_LICENSE_Beam Software				243
#define Q_SNES_GAME_PAK_LICENSE_Tec Magik				244
#define Q_SNES_GAME_PAK_LICENSE_Cybersoft				249
#define Q_SNES_GAME_PAK_LICENSE_Hudson Soft				255*/

#endif /* __Q_hardware_storage_medium_ROM_cartridge_SNES_Game_Pak_H__ */
