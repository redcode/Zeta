/* Q C API - macros/slot.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_macros_slot_H__
#define __Q_macros_slot_H__

#define QSlot(Type) struct {void *object; Type action;}

#endif /* __Q_macros_slot_H__ */
