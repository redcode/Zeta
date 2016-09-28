/* Z Kit C API - hardware/BUS/USB.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_BUS_USB_H__
#define __Z_hardware_BUS_USB_H__

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
/* Reserved 0x11 - 0x13 */
#define Z_USB_HID_USAGE_PAGE_ALPHANUMERIC_DISPLAY	0x14
/* Reserved 0x15 - 0x3F */
#define Z_USB_HID_USAGE_PAGE_MEDICAL_INSTRUMENTS	0x40
/* Reserved 0x41 - 0x7F */
#define Z_USB_HID_USAGE_PAGE_MONITOR_0			0x80
#define Z_USB_HID_USAGE_PAGE_MONITOR_1			0x81
#define Z_USB_HID_USAGE_PAGE_MONITOR_2			0x82
#define Z_USB_HID_USAGE_PAGE_MONITOR_3			0x83
#define Z_USB_HID_USAGE_PAGE_POWER_0			0x84
#define Z_USB_HID_USAGE_PAGE_POWER_1			0x85
#define Z_USB_HID_USAGE_PAGE_POWER_2			0x86
#define Z_USB_HID_USAGE_PAGE_POWER_3			0x87
/* Reserved 0x88 - 0x8B */
#define Z_USB_HID_USAGE_PAGE_BAR_CODE_SCANNER		0x8C
#define Z_USB_HID_USAGE_PAGE_SCALE_PAGE			0x8D
#define Z_USB_HID_USAGE_PAGE_MSR_DEVICES		0x8E
#define Z_USB_HID_USAGE_PAGE_RESERVED_POINT_OF_SALE	0x8F
#define Z_USB_HID_USAGE_PAGE_CAMERA_CONTROL		0x90
#define Z_USB_HID_USAGE_PAGE_ARCADE			0x91
#define Z_USB_HID_USAGE_PAGE_VENDOR_DEFINED_START	0xFF00

#endif /* __Z_hardware_BUS_USB_H__ */
