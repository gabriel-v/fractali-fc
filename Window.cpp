/**
 * @file Window.cpp
 * @brief Wrapper for the GLFW window and its events.
 * @author Gabriel Vijiala 
 * @date 3/27/16
 */

#include <map>
#include <iostream>
#include "Window.h"

namespace cf {



std::map<GLFWwindow *, Window *> activeWindows;

void global_key_callback(GLFWwindow *window, int key, int scancode, int action,
                         int mods) {
/*	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);*/

	activeWindows[window]->key_callback(key, scancode, action, mods);
}

void global_window_size_callback(GLFWwindow *window, int w, int h) {
	activeWindows[window]->enqueueRecompute();
}

Window::Window() : View() {
	/* Create a windowed mode window and its OpenGL context */
	_window = glfwCreateWindow(150, 150, "PFract", NULL, NULL);
	if (!_window) {
		glfwTerminate();
		throw error("Glfw window creation failed");
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(_window);
	glfwSetKeyCallback(_window, cf::global_key_callback);
	glfwSwapInterval(1);

	cf::activeWindows[_window] = this;

	_done = false;
}

Window::~Window() {
	glfwDestroyWindow(_window);
}

void Window::start(Compositor &c) {
	if (_done) {
		throw error("Can't start the window 2 times!");
	}

	while (!glfwWindowShouldClose(_window)) {
		int width, height;
		glfwGetFramebufferSize(_window, &width, &height);

//		if(buf_height != height || buf_width != width) {
//			buf_height = height;
//			buf_width = width;
//			buffer = (unsigned int*) realloc(buffer, buf_height * buf_width * sizeof(unsigned int));
//			if(buffer == NULL) {
//				std::cerr << "REALLOC FAILED FOR THE BUFFER!!" << std::endl;
//				exit(EXIT_FAILURE);
//			}
//			recompute(buffer, buf_width, buf_height);
//		}

		resize(width, height);

		if (_shouldRecompute) {
			requestCompute(c);
			std::cerr << getStatus();
			_shouldRecompute = false;
		}


		glViewport(0, 0, width, height);
		//glClear(GL_COLOR_BUFFER_BIT);
		//glRasterPos2i(0,0);
		glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8,
		             _img);


		glfwSwapBuffers(_window);
		glfwWaitEvents();
	}

	_done = true;
}


void Window::initGL() {
	if (!glfwInit()) {
		throw error("Glfw initGL failed");
	}

}

void Window::termGL() {
	glfwTerminate();
}


void Window::key_callback(int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		_shouldRecompute = true;
		switch (key) {
			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(_window, GL_TRUE);
				break;
			case GLFW_KEY_LEFT:
				goLeft();
				break;
			case GLFW_KEY_RIGHT:
				goRight();
				break;
			case GLFW_KEY_UP:
				goUp();
				break;
			case GLFW_KEY_DOWN:
				goDown();
				break;

			case GLFW_KEY_MINUS:
			case GLFW_KEY_PAGE_UP:
			case GLFW_KEY_KP_SUBTRACT:
				zoomOut();
				break;
			case GLFW_KEY_PAGE_DOWN:
			case GLFW_KEY_KP_ADD:
			case GLFW_KEY_EQUAL:
				zoomIn();
				break;

			default:
				_shouldRecompute = false;
				break;
		}
	}
}


void Window::enqueueRecompute() {
	_shouldRecompute = true;
}

}