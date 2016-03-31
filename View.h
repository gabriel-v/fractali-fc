/**
 * @file View.h
 * @brief Holds the 2D position and zoom level.
 *      Constructs args for the compositor.
 * @author Gabriel Vijiala 
 * @date 3/27/16
 */

#ifndef PFRACT_VIEW_H
#define PFRACT_VIEW_H

#include "Compositor.h"
#include "types.h"
#include <string>

namespace cf {
	class View {
	protected:
		scalar _zoom;
		scalar _centerX, _centerY;

		int _width, _height;

		int _ordN;
		int _imgN;

		uint *_img;
		scalar *_ordX;
		scalar *_ordY;
	public:
		void goRight();

		void goLeft();

		void goUp();

		void goDown();

		void zoomIn();

		void zoomOut();

		void reset();

		void requestCompute(Compositor &c);

		void resize(int width, int height);

		View();

		std::string getStatus();

		virtual ~View();
	};
}

#endif //PFRACT_VIEW_H
