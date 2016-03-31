/**
 * @file CLCompositor.cpp
 * @brief Abstract class that mitigates all drawing logic to a single
 *      OpenCL kernel.
 * @author Gabriel Vijiala 
 * @date 3/27/16
 */

#include <fstream>
#include <iostream>
#include <sstream>

#include "CLCompositor.h"

namespace cf {



const char options[] = "-cl-std=CL1.1";

cl::Context defaultContext;
cl::Device defaultDevice;

inline void checkErr(cl_int err, const std::string name) {
	if (err != CL_SUCCESS) {
		std::cerr << "ERROR: " << name << " (" << err << ")" <<
		std::endl;
		exit(EXIT_FAILURE);
	}
}


std::pair<const char *, unsigned long> getProgramSources(
	const std::string fileName) {
	std::ifstream file(fileName);

	checkErr(file.is_open() ? CL_SUCCESS : -1,
	         std::string("Could not open: ").append(fileName));


	std::stringstream ss;

	std::string line;
	while (std::getline(file, line)) {
		ss << line << "\n";
	}

	file.close();

	std::cout << std::endl << ss.str().c_str() << std::endl;

	/* Memory leak! Yeeeah! */
	char *programBuffer = new char[ss.str().length() + 3];

	strcpy(programBuffer, ss.str().c_str());

	return std::make_pair(programBuffer, ss.str().length() + 1);
}


void CLCompositor::initCL() {
	std::vector<cl::Platform> allPlatforms;

	cl::Platform::get(&allPlatforms);
	if (allPlatforms.size() == 0) {
		std::cout <<
		" No platforms found. Check OpenCL installation!\n";
		exit(1);
	}
	cl::Platform default_platform = allPlatforms[0];
	std::cout << "We have  " << allPlatforms.size() << " platforms." <<
	std::endl;
	std::cout << "Using platform: " <<
	default_platform.getInfo<CL_PLATFORM_NAME>() << "\n";

	//get default device of the default platform
	std::vector<cl::Device> all_devices;
	default_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);
	if (all_devices.size() == 0) {
		std::cout << " No devices found. Check OpenCL installation!\n";
		exit(1);
	}
	defaultDevice = all_devices[0];
	std::cout << "Using device: " <<
	defaultDevice.getInfo<CL_DEVICE_NAME>() << "\n";

	;
	defaultContext = cl::Context(defaultDevice);
}

void CLCompositor::termCL() {

}

CLCompositor::CLCompositor(std::string kernel, std::string file) : _kernel(
	kernel) {
	cl::Program::Sources sources(1, getProgramSources(file));
	initFromSources(sources);
}

CLCompositor::CLCompositor(std::string kernel,
                           std::initializer_list<std::string> files) : _kernel(
	kernel) {
	cl::Program::Sources sources;
	for (auto &file: files) {
		sources.push_back(getProgramSources(file));
	}
	initFromSources(sources);
}


CLCompositor::CLCompositor(std::string kernel, cl::Program::Sources sources)
	: _kernel(kernel) {
	initFromSources(sources);
}

void CLCompositor::initFromSources(cl::Program::Sources &sources) {
	_program = cl::Program(defaultContext, sources);

	if (_program.build({defaultDevice}) != CL_SUCCESS) {
		std::cout << " Error building: " <<
		_program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(defaultDevice) <<
		"\n" << std::endl;
		exit(1);
	}
}


void CLCompositor::calculate(uint *image, scalar *ordX, scalar *ordY, int width,
                             int height) {

	cl::Buffer bufferX(defaultContext, CL_MEM_READ_WRITE,
	                   sizeof(scalar) * width);
	cl::Buffer bufferY(defaultContext, CL_MEM_READ_WRITE,
	                   sizeof(scalar) * height);
	cl::Buffer bufferImg(defaultContext, CL_MEM_READ_WRITE,
	                     sizeof(uint) * width * height);


	//create queue to which we will push commands for the device.
	cl::CommandQueue queue(defaultContext, defaultDevice);

	//write arrays A and B to the device
	queue.enqueueWriteBuffer(bufferX, CL_FALSE, 0, sizeof(int) * width,
	                         ordX);
	queue.enqueueWriteBuffer(bufferY, CL_FALSE, 0, sizeof(int) * height,
	                         ordY);


	cl::Kernel kernel_add = cl::Kernel(_program, _kernel.c_str());
	kernel_add.setArg(0, bufferX);
	kernel_add.setArg(1, bufferY);
	kernel_add.setArg(2, bufferImg);
	kernel_add.setArg(3, width);
	kernel_add.setArg(4, height);

	cl::Event event;

	//TODO figure this out
	queue.enqueueNDRangeKernel(
		kernel_add,
		cl::NullRange,
		cl::NDRange((size_t) width, (size_t) height),
		cl::NullRange,
		NULL,
		&event
	);

	event.wait();

	queue.enqueueReadBuffer(bufferImg, CL_TRUE, 0,
	                        sizeof(uint) * width * height, image);

	queue.finish();
}
}