/* Z Kit C API - macros/inspection.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_inspection_H__
#define __Z_macros_inspection_H__

#define Z_IS_AVAILABLE(WHAT) (defined Z_AVAILABLE_##WHAT)

#define Z_ARE_AVAILABLE_2(A, B) ((defined Z_AVAILABLE_##A) || (defined Z_AVAILABLE_##B))

#define Z_ARE_AVAILABLE_3(A, B, C) \
	((defined Z_AVAILABLE_##A) && (defined Z_AVAILABLE_##B) && (defined Z_AVAILABLE_##C))

#define Z_ARE_AVAILABLE_4(A, B, C, D) \
	((defined Z_AVAILABLE_##A) && (defined Z_AVAILABLE_##B) && \
	 (defined Z_AVAILABLE_##C) && (defined Z_AVAILABLE_##D))

#define Z_ARE_AVAILABLE_5(A, B, C, D, E) \
	((defined Z_AVAILABLE_##A) && (defined Z_AVAILABLE_##B) && \
	 (defined Z_AVAILABLE_##C) && (defined Z_AVAILABLE_##D) && (defined Z_AVAILABLE_##E))

#define Z_ARE_AVAILABLE_6(A, B, C, D, E, F) \
	((defined Z_AVAILABLE_##A) && (defined Z_AVAILABLE_##B) && \
	 (defined Z_AVAILABLE_##C) && (defined Z_AVAILABLE_##D) && \
	 (defined Z_AVAILABLE_##E) && (defined Z_AVAILABLE_##F))

#define Z_ARE_AVAILABLE_7(A, B, C, D, E, F, G) \
	((defined Z_AVAILABLE_##A) && (defined Z_AVAILABLE_##B) && \
	 (defined Z_AVAILABLE_##C) && (defined Z_AVAILABLE_##D) && \
	 (defined Z_AVAILABLE_##E) && (defined Z_AVAILABLE_##F) && (defined Z_AVAILABLE_##G))

#define Z_ARE_AVAILABLE_8(A, B, C, D, E, F, G, H) \
	((defined Z_AVAILABLE_##A) && (defined Z_AVAILABLE_##B) && \
	 (defined Z_AVAILABLE_##C) && (defined Z_AVAILABLE_##D) && \
	 (defined Z_AVAILABLE_##E) && (defined Z_AVAILABLE_##F) && \
	 (defined Z_AVAILABLE_##G) && (defined Z_AVAILABLE_##H))

#define Z_ARE_AVAILABLE_ANY_2(A, B) ((defined Z_AVAILABLE_##A) || (defined Z_AVAILABLE_##B))

#define Z_ARE_AVAILABLE_ANY_3(A, B, C) \
	((defined Z_AVAILABLE_##A) || (defined Z_AVAILABLE_##B) || (defined Z_AVAILABLE_##C))

#define Z_ARE_AVAILABLE_ANY_4(A, B, C, D) \
	((defined Z_AVAILABLE_##A) || (defined Z_AVAILABLE_##B) || \
	 (defined Z_AVAILABLE_##C) || (defined Z_AVAILABLE_##D))

#define Z_ARE_AVAILABLE_ANY_5(A, B, C, D, E) \
	((defined Z_AVAILABLE_##A) || (defined Z_AVAILABLE_##B) || \
	 (defined Z_AVAILABLE_##C) || (defined Z_AVAILABLE_##D) || (defined Z_AVAILABLE_##E))

#define Z_ARE_AVAILABLE_ANY_6(A, B, C, D, E, F) \
	((defined Z_AVAILABLE_##A) || (defined Z_AVAILABLE_##B) || \
	 (defined Z_AVAILABLE_##C) || (defined Z_AVAILABLE_##D) || \
	 (defined Z_AVAILABLE_##E) || (defined Z_AVAILABLE_##F))

#define Z_ARE_AVAILABLE_ANY_7(A, B, C, D, E, F, G) \
	((defined Z_AVAILABLE_##A) || (defined Z_AVAILABLE_##B) || \
	 (defined Z_AVAILABLE_##C) || (defined Z_AVAILABLE_##D) || \
	 (defined Z_AVAILABLE_##E) || (defined Z_AVAILABLE_##F) || (defined Z_AVAILABLE_##G))

#define Z_ARE_AVAILABLE_ANY_8(A, B, C, D, E, F, G, H) \
	((defined Z_AVAILABLE_##A) || (defined Z_AVAILABLE_##B) || \
	 (defined Z_AVAILABLE_##C) || (defined Z_AVAILABLE_##D) || \
	 (defined Z_AVAILABLE_##E) || (defined Z_AVAILABLE_##F) || \
	 (defined Z_AVAILABLE_##G) || (defined Z_AVAILABLE_##H))

#define Z_USE(WHAT) (defined Z_USE_##WHAT)

#endif /* __Z_macros_inspection_H__ */
