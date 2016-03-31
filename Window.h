/**
 * @file Window.h
 * @brief Wrapper for the GLFW window and its events.
 * @author Gabriel Vijiala 
 * @date 3/27/16
 */

#ifndef PFRACT_WINDOW_H
#define PFRACT_WINDOW_H

#include <GLFW/glfw3.h>

#include "View.h"
namespace cf {
	class Window : public View {
	protected:
		GLFWwindow *_window;
		bool _done;
		bool _shouldRecompute;

	public:
		Window();

		virtual ~Window();

		void key_callback(int key, int scancode, int action, int mods);

		void start(Compositor &c);

		void enqueueRecompute();

		static void initGL();

		static void termGL();
	};
}

#endif //PFRACT_WINDOW_H
