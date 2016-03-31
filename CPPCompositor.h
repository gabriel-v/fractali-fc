/**
 * @file
 * @brief
 * @author Gabriel Vijiala 
 * @date 3/27/16
 */

#ifndef PFRACT_CPPCOMPOSITOR_H
#define PFRACT_CPPCOMPOSITOR_H

#include "types.h"
#include "Compositor.h"

namespace cf {
	class CPPCompositor : public Compositor {
	protected:
		virtual uint pixel(scalar x, scalar y);

		virtual void calculate(uint *image, scalar *ordX, scalar *ordY,
		                       int width, int height);
	};
}

#endif //PFRACT_CPPCOMPOSITOR_H
