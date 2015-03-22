/* Q Kit C++ API - classes/base/Value2D.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_classes_base_Value2D_HPP__
#define __Q_classes_base_Value2D_HPP__

#include <Q/types/base.hpp>

namespace QKit {class Value2D : public Q2D {


	inline Boolean operator ==(const Value2D value) const
		{return x == value.x && y == value.y;}


	inline Boolean contains(const Value2D value) const
		{return x >= value.x && y >= value.y;}
	
};}

#endif // __Q_classes_base_Value2D_HPP__
