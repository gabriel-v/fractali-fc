/**
 * @file
 * @brief
 * @author Gabriel Vijiala 
 * @date 3/27/16
 */

#include <complex>
#include <thread>
#include <random>
#include <vector>
#include <algorithm>
#include "types.h"
#include "CPPCompositor.h"

namespace cf {

	const std::uniform_real_distribution<double> unif(0,1);
	const std::default_random_engine re;

	const int maxiter = 256;

	inline uint bernstein(double t) {
		if(t > 1.0) t = 1.0;
		if(t < 0.0) t = 0.0;
		byte r = (byte) (255.0 * 9 * (1 - t) * t * t * t);
		byte g = (byte) (255.0 * 15 * (1 - t) * (1 - t) * t * t);
		byte b = (byte) (255.0 * 8.5 * (1 - t) * (1 - t) * (1 - t) * t);

		return (uint) 255 + (g << 8) + (b << 16) + (r << 24);
	}

	uint CPPCompositor::pixel(scalar x, scalar y) {
		std::complex<scalar> z(0), c(x, y);
		int iter = 0;
		while (std::abs(z) < 2 && iter < maxiter) {
			iter++;
			z = z * z + c;
		}
		scalar t = (scalar) (iter + (scalar) rand() / RAND_MAX) / (scalar) maxiter;



		return bernstein(t);
		//return r << 24;
	}

	void CPPCompositor::calculate(uint *imgo, scalar *ordX, scalar *ordY,
	                              int width, int height) {
		const int num_threads = 4;
		std::vector<std::thread> threads;

		for(int i = 0; i < num_threads; i++) {
			threads.push_back(std::thread([this, i, imgo, ordX, ordY, width, height](){
				int i1 = i * width / num_threads;
				int i2 = (i + 1) * width / num_threads;
				for (int ii = i1; ii < i2; ii++) {
					for (int j = 0; j < width; j++) {
						imgo[ii * width + j] = pixel(ordX[j], ordY[ii]);
					}
				}
			}));
		}

		std::for_each(threads.begin(), threads.end(), [](std::thread& t){
			t.join();
		});
	}
}