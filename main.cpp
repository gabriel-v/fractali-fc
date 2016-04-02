/**
 * @file main.cpp
 * @brief Entry point.
 * @author Gabriel Vijiala
 * @date 3/27/16
 */

#include <utility>

//#define __NO_STD_VECTOR // Use cl::vector instead of STL version
//#define __CL_ENABLE_EXCEPTIONS

//#include <CL/cl.hpp>
//#include <CImg.h>

#include "Window.h"
#include <iostream>
#include <cmath>
#include "CPPCompositor.h"
#include "CPPDoublePendulum.h"
//namespace cimg = cimg_library;

/*
#include "OpenCLUtilities/openCLUtilities.hpp"

using namespace cl;

float * createBlurMask(float sigma, int * maskSizePointer) {
    int maskSize = (int) ceil(3.0f * sigma);
    float * mask = new float[(maskSize * 2 + 1)*(maskSize * 2 + 1)];
    float sum = 0.0f;
    for (int a = -maskSize; a < maskSize + 1; a++) {
        for (int b = -maskSize; b < maskSize + 1; b++) {
            float temp = exp(-((float) (a * a + b * b) / (2 * sigma * sigma)));
            sum += temp;
            mask[a + maskSize + (b + maskSize)*(maskSize * 2 + 1)] = temp;
        }
    }
    // Normalize the mask
    for (int i = 0; i < (maskSize * 2 + 1)*(maskSize * 2 + 1); i++)
        mask[i] = mask[i] / sum;

    *maskSizePointer = maskSize;

    return mask;
}

int main(int argc, char ** argv) {
    // Load image
    cimg_library::CImg<float> image("images/lena.jpg");
    // Create OpenCL context
    Context context = createCLContextFromArguments(argc, argv);

    // Compile OpenCL code
    Program program = buildProgramFromSource(context, "gaussian_blur.cl");

    // Select device and create a command queue for it
    VECTOR_CLASS<Device> devices = context.getInfo<CL_CONTEXT_DEVICES>();
    CommandQueue queue = CommandQueue(context, devices[0]);

    // Create an OpenCL Image / texture and transfer data to the device
    Image2D clImage = Image2D(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, 
            ImageFormat(CL_R, CL_FLOAT), image->width(), image->height(), 0, (void*) image->data());

    // Create a buffer for the result
    Buffer clResult = Buffer(context, CL_MEM_WRITE_ONLY, sizeof (float)*image->width() * image->height());

    // Create Gaussian mask
    int maskSize;
    float * mask = createBlurMask(10.0f, &maskSize);

    // Create buffer for mask and transfer it to the device
    Buffer clMask = Buffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof (float)*(maskSize * 2 + 1)*(maskSize * 2 + 1), mask);

    // Run Gaussian kernel
    Kernel gaussianBlur = Kernel(program, "gaussian_blur");
    gaussianBlur.setArg(0, clImage);
    gaussianBlur.setArg(1, clMask);
    gaussianBlur.setArg(2, clResult);
    gaussianBlur.setArg(3, maskSize);

    queue.enqueueNDRangeKernel(
            gaussianBlur,
            NullRange,
            NDRange(image->width(), image->height()),
            NullRange
            );

    // Transfer image back to host
    float* data = new float[image->width() * image->height()];
    queue.enqueueReadBuffer(clResult, CL_TRUE, 0, sizeof (float)*image->width() * image->height(), data);
    memcpy(image->data(), data, image->size() * sizeof(float));
    //image->setData(data);
            

    // Save image to disk and display it
    image->save("images/result.jpg");
    image->display();
}
 */
//int main() {
//
//	cimg_library::CImg<unsigned char> image((const char* const) "images/lena.jpg");
//	cimg_library::CImg<unsigned char> visu(500, 400, 1, 3, 0);
//	const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
//	
//	image.blur(1.5f);
//	cimg_library::CImgDisplay main_disp(image,"Click a point"), draw_disp(visu,"Intensity profile");
//	while (!main_disp.is_closed() && !draw_disp.is_closed()) {
//		main_disp.wait();
//		if (main_disp.button() && main_disp.mouse_y()>=0) {
//			const int y = main_disp.mouse_y();
//			visu.fill(0).draw_graph(image.get_crop(0,y,0,0,image.width()-1,y,0,0),red,1,1,0,255,0);
//			visu.draw_graph(image.get_crop(0,y,0,1,image.width()-1,y,0,1),green,1,1,0,255,0);
//			visu.draw_graph(image.get_crop(0,y,0,2,image.width()-1,y,0,2),blue,1,1,0,255,0).display(draw_disp);
//		}
//	}
//	return 0;
//}

int main() {
    cf::Window::initGL();
    cf::Window win;

    cf::CPPCompositor compositor;

    win.start(compositor);

    cf::Window::termGL();
}