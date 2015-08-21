/* Z Kit C API - functions/color.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_color_H__
#define __Z_functions_color_H__

#include <Z/macros/value.h>

#define Z_R		Z_32BIT_0
#define Z_G		Z_32BIT_1
#define Z_B		Z_32BIT_2
#define Z_A		Z_32BIT_3
#define Z_R_MASK	Z_32BIT_0_MASK
#define Z_G_MASK	Z_32BIT_1_MASK
#define Z_B_MASK	Z_32BIT_2_MASK
#define Z_A_MASK	Z_32BIT_3_MASK

#if Z_INT32_ENDIANNESS == Z_ENDIANNESS_BIG
#	define Z_GREYSCALE_MULTIPLIER 0x01010100
#elif Z_INT32_ENDIANNESS == Z_ENDIANNESS_LITTLE
#	define Z_GREYSCALE_MULTIPLIER 0x00010101
#endif

#ifndef Z_COLOR_EXPORT
#	define Z_COLOR_EXPORT Z_INLINE
#endif

/* MARK: - RGBA 8 8 8 8 */


/*
	argb_8_8_8_8
	argb_4_4_4_4
	argb_1_5_5_5

	rgba_8_8_8_8
	rgba_4_4_4_4
	rgba_5_5_5_1

	rgb_5_6_5
	i_8


*/

#if Z_CPU_ENDIANNESS != Z_CPU_INTEGER_ENDIANNESS(16BIT) || Z_CPU_ENDIANNESS != Z_CPU_ENDIANNESS(32BIT)
#	error "There is no support for multi-endian CPU in color functions."
#endif

#if Z_CPU_ENDIANNESS == Z_ENDIANNESS_BIG

	Z_INLINE zuint32 z_argb_8_8_8_8_to_rgba_8_8_8_8(zuint32 color)
		{return (color << 8) | (color >> 24);}


	Z_INLINE zuint32 z_rgba_8_8_8_8_to_argb_8_8_8_8(zuint32 color)
		{return (color >> 8) | (color << 24);}


	Z_INLINE zuint16 z_rgba_8_8_8_8_to_rgba_4_4_4_4(zuint32 color)
		{
		return	((color >> 16) & 0xF000) | /* R */
			((color >> 12) & 0x0F00) | /* G */
			((color >>  8) & 0x00F0) | /* B */
			((color >>  4) & 0x000F);  /* A */
		}


	Z_INLINE zuint16 z_rgba_8_8_8_8_to_rgba_5_5_5_1(zuint32 color)
		{
		return	((color >> 16) & 0xF800) | /* R */
			((color >> 13) & 0x07C0) | /* G */
			((color >> 10) & 0x003E) | /* B */
			((color >>  7) & 0x0001);  /* A */
		}


	Z_INLINE zuint16 z_rgba_8_8_8_8_to_rgb_5_6_5(zuint32 color)
		{
		return	((color >> 16) & 0xF800) | /* R */
			((color >> 13) & 0x07E0) | /* G */
			((color >> 11) & 0x001F);  /* B */
		}


	Z_INLINE zuint8 z_rgba_8_8_8_8_to_i8(zuint32 color)
		{
		return	((color >> 24) + ((color >> 16) & 255) + ((color >> 8) & 255))
			/ 3;
		}




#elif Z_CPU_ENDIANNESS == Z_ENDIANNESS_LITTLE

#endif





Z_INLINE
zuint16 z_rgba_8_8_8_8_to_rgba_5_5_5_1(zuint32 color)
	{
	return	((((color >>  0) & 0xFF) >> 3) << 11) |	/* R */
		((((color >>  8) & 0xFF) >> 3) <<  6) |	/* G */
		((((color >> 16) & 0xFF) >> 3) <<  1) |	/* B */
		((((color >> 24) & 0xFF) >> 7) <<  0);	/* A */
	}


Z_INLINE
zuint8 z_rgba_8_8_8_8_to_i_8(zuint32 color)
	{return	(Z_R(color) + Z_G(color) + Z_B(color)) / 3;}


Z_INLINE
zuint32 z_rgba_8_8_8_8_plus_rgb(zuint32 color, zuint32 rgb)
	{
	return	Z_MBA(color, rgb, Z_R_MASK) |
		Z_MBA(color, rgb, Z_G_MASK) |
		Z_MBA(color, rgb, Z_B_MASK) |
		(color &	  Z_A_MASK);
	}


Z_COLOR_EXPORT
zuint32 z_rgba_8_8_8_8_minus_rgb(zuint32 color, zuint32 rgb)
	{
	return	Z_MBS(color, rgb, Z_R_MASK) |
		Z_MBS(color, rgb, Z_G_MASK) |
		Z_MBS(color, rgb, Z_B_MASK) |
		(color &	  Z_A_MASK);
	}


Z_COLOR_EXPORT
zuint32 z_rgba_8_8_8_8_plus_a(zuint32 color, zuint32 a)
	{
	return	Z_MBA(color, a, Z_A_MASK) |
		(color & (Z_R_MASK | Z_G_MASK | Z_B_MASK));
	}


Z_COLOR_EXPORT
zuint32 z_rgba_8_8_8_8_minus_a(zuint32 color, zuint32 a)
	{
	return	Z_MBS(color, a, Z_A_MASK) |
		(color & (Z_R_MASK | Z_G_MASK | Z_B_MASK));
	}


Z_COLOR_EXPORT
zuint32 z_rgba_8_8_8_8_plus_rgba(zuint32 color, zuint32 rgba)
	{
	return	Z_MBA(color, rgba, Z_R_MASK) |
		Z_MBA(color, rgba, Z_G_MASK) |
		Z_MBA(color, rgba, Z_B_MASK) |
		Z_MBA(color, rgba, Z_A_MASK);
	}


Z_COLOR_EXPORT
zuint32 z_rgba_8_8_8_8_minus_rgba(zuint32 color, zuint32 rgba)
	{
	return	Z_MBS(color, rgba, Z_R_MASK) |
		Z_MBS(color, rgba, Z_G_MASK) |
		Z_MBS(color, rgba, Z_B_MASK) |
		Z_MBS(color, rgba, Z_A_MASK);
	}


Z_COLOR_EXPORT
zuint32 z_rgba_8_8_8_8_negative(zuint32 color)
	{return (color & Z_A_MASK) | (~color & (Z_R_MASK | Z_G_MASK | Z_B_MASK));}


Z_COLOR_EXPORT
zuint32 z_rgba_8_8_8_8_grayscale(zuint32 color)
	{return z_rgba_8_8_8_8_to_i_8(color) * Z_GREYSCALE_MULTIPLIER;}


Z_COLOR_EXPORT
zuint32 z_rgba_8_8_8_8_monochrome(
	zuint32 color,
	zuint32 base_color
)
	{
	zuint32 i = 0xFF - z_rgba_8_8_8_8_to_i_8(color);

	return	Z_MBS(color, i, Z_R_MASK) |
		Z_MBS(color, i, Z_G_MASK) |
		Z_MBS(color, i, Z_B_MASK) |
		(color &	Z_A_MASK);
	}


#define Z_A		Z_32BIT_0
#define Z_R		Z_32BIT_1
#define Z_G		Z_32BIT_2
#define Z_B		Z_32BIT_3
#define Z_A_MASK	Z_32BIT_0_MASK
#define Z_R_MASK	Z_32BIT_1_MASK
#define Z_G_MASK	Z_32BIT_2_MASK
#define Z_B_MASK	Z_32BIT_3_MASK

#if Z_INT32_ENDIANNESS == Z_ENDIANNESS_BIG
#	define Z_GREYSCALE_MIRROR_MASK 0x00010101
#elif Z_INT32_ENDIANNESS == Z_ENDIANNESS_LITTLE
#	define Z_GREYSCALE_MIRROR_MASK 0x01010100
#endif



/* MARK: - ARGB 8 8 8 8 */



/*
typedef struct {
	zdouble red;
	zdouble green;
	zdouble blue;
	zdouble alpha;
} ZColor;




Z_INLINE ZColor z__color_monochrome(ZColor object, ZColor base_color)
	{
	zdouble shadow = Z_BIGGER_OF_3(color.red, color.green, color.blue);

	object.red   = (object.red   > shadow) ? object.red   - shadow : 0;
	object.green = (object.green > shadow) ? object.green - shadow : 0;
	object.blue  = (object.blue  > shadow) ? object.blue  - shadow : 0;

	return object;
	}


Z_INLINE ZColor z__color_grayscale(ZColor object)
	{
	zdouble light = (object.red + object.green + object.blue) / 3;

	return (ZColor){light, light, light, object.alpha};
	}




#define Z_COLOR_APPLY_MONOCROME(color, base_color, shadow)					\
	shadow	    = Z_BIGGER_OF_3(color.red, color.green, color.blue);			\
	color.red   = (color.red   > shadow) ? color.red   - shadow : 0;			\
	color.green = (color.green > shadow) ? color.green - shadow : 0;			\
	color.blue  = (color.blue  > shadow) ? color.blue  - shadow : 0;

#define Z_COLOR_APPLY_BLENDING(color, blending, shadow)
	shadow = 255 - blending.alpha;
	color.red = (float)(blending.red / 255) * (float)blending.alpha + 

	(((ARGB32)((((float)(*block & 0xFF0000	)) / 0xFF0000) * (float)blending.alpha)) & 0xFF0000) + (((ARGB32)((((float)(*block2 & 0xFF0000	)) / 0xFF0000) * (float)(shadow >> 8)))  & 0xFF0000) |
	(((ARGB32)((((float)(*block & 0xFF00	)) /   0xFF00) * (float)blending.alpha)) &   0xFF00) + (((ARGB32)((((float)(*block2 & 0xFF00	)) /   0xFF00) * (float)(shadow >> 16))) &   0xFF00) |
	(((ARGB32)((((float)(*block & 0xFF	)) /	 0xFF) * (float)blending.alpha)) &     0xFF) + (((ARGB32)((((float)(*block2 & 0xFF	)) /	 0xFF) * (float)(shadow >> 24))) &     0xFF);

*/

#endif /* __Z_functions_color_H__ */
