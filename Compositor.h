/**
 * @file Compositor.h
 * @brief Abstract base class for holding the different algorithms that draw
 *      onto the 2D surface.
 * @author Gabriel Vijiala 
 * @date 3/27/16
 */

#ifndef PFRACT_COMPOSITOR_H
#define PFRACT_COMPOSITOR_H


#include "types.h"
namespace cf {
	class Compositor {
	public:
		virtual void calculate(uint *image, scalar *ordX, scalar *ordY,
		                       int width, int height) = 0;
	};
}

#endif //PFRACT_COMPOSITOR_H
