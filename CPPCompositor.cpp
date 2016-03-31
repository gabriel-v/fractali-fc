/**
 * @file
 * @brief
 * @author Gabriel Vijiala 
 * @date 3/27/16
 */

#include <complex>
#include "types.h"
#include "CPPCompositor.h"

namespace cf {
	const int maxiter = 260;

	inline uint color(byte r, byte b, byte g) {
		return (uint) 255 + (g << 8) + (b << 16) + (r << 24);
	}

	uint CPPCompositor::pixel(scalar x, scalar y) {
		std::complex<scalar> z(0), c(x, y);
		int iter = 0;
		while (std::abs(z) < 2 && iter < maxiter) {
			iter++;
			z = z * z + c;
		}
		scalar t = (scalar) iter / (scalar) maxiter;

		byte r = (byte) (255.0 * 9 * (1 - t) * t * t * t);
		byte g = (byte) (255.0 * 15 * (1 - t) * (1 - t) * t * t);
		byte b = (byte) (255.0 * 8.5 * (1 - t) * (1 - t) * (1 - t) * t);

		return color(r, g, b);
		//return r << 24;
	}

	void CPPCompositor::calculate(uint *image, scalar *ordX, scalar *ordY,
	                              int width, int height) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				image[i * width + j] = pixel(ordX[j], ordY[i]);
			}
		}
	}
}