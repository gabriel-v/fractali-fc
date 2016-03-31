/**
 * @file CLCompositor.h
 * @brief Abstract class that mitigates all drawing logic to a single
 *      OpenCL kernel.
 * @author Gabriel Vijiala 
 * @date 3/27/16
 */

#ifndef PFRACT_CLCOMPOSITOR_H
#define PFRACT_CLCOMPOSITOR_H

#include <vector>
#include <CL/cl.hpp>
#include "Compositor.h"

namespace cf {

	class CLCompositor : public Compositor {
	protected:
		void initFromSources(cl::Program::Sources &sources);

		cl::Program _program;
		std::string _kernel;

	public:
		static void initCL();

		static void termCL();

		CLCompositor(std::string kernel, cl::Program::Sources sources);

		CLCompositor(std::string kernel, std::string file);

		CLCompositor(std::string kernel,
		             std::initializer_list<std::string> files);

		virtual void calculate(uint *image, scalar *ordX, scalar *ordY,
		                       int width, int height);
	};

}
#endif //PFRACT_CLCOMPOSITOR_H
