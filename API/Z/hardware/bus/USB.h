/* Zeta API - Z/hardware/bus/USB.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_hardware_bus_USB_H
#define Z_hardware_bus_USB_H

/* MARK: - HID Device Usage Pages */

#define Z_USB_HID_USAGE_PAGE_UNDEFINED			0x00
#define Z_USB_HID_USAGE_PAGE_GENERIC_DESKTOP_CONTROLS	0x01
#define Z_USB_HID_USAGE_PAGE_SIMULATION_CONTROLS	0x02
#define Z_USB_HID_USAGE_PAGE_VR_CONTROLS		0x03
#define Z_USB_HID_USAGE_PAGE_SPORT_CONTROLS		0x04
#define Z_USB_HID_USAGE_PAGE_GAME_CONTROLS		0x05
#define Z_USB_HID_USAGE_PAGE_GENERIC_DEVICE_CONTROLS	0x06
#define Z_USB_HID_USAGE_PAGE_KEYBOARD_KEYPAD		0x07
#define Z_USB_HID_USAGE_PAGE_LEDS			0x08
#define Z_USB_HID_USAGE_PAGE_BUTTON			0x09
#define Z_USB_HID_USAGE_PAGE_ORDINAL			0x0A
#define Z_USB_HID_USAGE_PAGE_TELEPHONY			0x0B
#define Z_USB_HID_USAGE_PAGE_CONSUMER			0x0C
#define Z_USB_HID_USAGE_PAGE_DIGITIZER			0x0D
#define Z_USB_HID_USAGE_PAGE_RESERVED			0x0E
#define Z_USB_HID_USAGE_PAGE_PID			0x0F
#define Z_USB_HID_USAGE_PAGE_UNICODE			0x10
/* 11h-13h - Reserved */
#define Z_USB_HID_USAGE_PAGE_ALPHANUMERIC_DISPLAY	0x14
/* Reserved 0x15 - 0x3F */
#define Z_USB_HID_USAGE_PAGE_MEDICAL_INSTRUMENTS	0x40
/* 41h-7Fh - Reserved */
#define Z_USB_HID_USAGE_PAGE_MONITOR_0			0x80
#define Z_USB_HID_USAGE_PAGE_MONITOR_1			0x81
#define Z_USB_HID_USAGE_PAGE_MONITOR_2			0x82
#define Z_USB_HID_USAGE_PAGE_MONITOR_3			0x83
#define Z_USB_HID_USAGE_PAGE_POWER_0			0x84
#define Z_USB_HID_USAGE_PAGE_POWER_1			0x85
#define Z_USB_HID_USAGE_PAGE_POWER_2			0x86
#define Z_USB_HID_USAGE_PAGE_POWER_3			0x87
/* 88h-8Bh - Reserved */
#define Z_USB_HID_USAGE_PAGE_BAR_CODE_SCANNER		0x8C
#define Z_USB_HID_USAGE_PAGE_SCALE_PAGE			0x8D
#define Z_USB_HID_USAGE_PAGE_MSR_DEVICES		0x8E
#define Z_USB_HID_USAGE_PAGE_RESERVED_POINT_OF_SALE	0x8F
#define Z_USB_HID_USAGE_PAGE_CAMERA_CONTROL		0x90
#define Z_USB_HID_USAGE_PAGE_ARCADE			0x91
#define Z_USB_HID_USAGE_PAGE_VENDOR_DEFINED_START	0xFF00

/* MARK: - HID Usage Page 07h - Keyboard/Keypad */

#include <Z/formats/keymap/USB.h>

#endif /* Z_hardware_bus_USB_H */
