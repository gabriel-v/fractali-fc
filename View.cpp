/**
 * @file View.cpp
 * @brief Holds the 2D position and zoom level.
 *      Constructs args for the compositor.
 * @author Gabriel Vijiala 
 * @date 3/27/16
 */

#include <sstream>
#include <iomanip>

#include "View.h"
namespace cf {

const double PAN_SPEED = 1.0 / 8;
const double ZOOM_SPEED = 1.3;
const int INITIAL_WIDTH = 1920;
const int INITIAL_HEIGHT = 1080;


void View::goRight() {
	_centerX += _zoom * PAN_SPEED;
}

void View::goLeft() {
	_centerX -= _zoom * PAN_SPEED;
}

void View::goUp() {
	_centerY += _zoom * PAN_SPEED;
}

void View::goDown() {
	_centerY -= _zoom * PAN_SPEED;
}

void View::zoomIn() {
	_zoom /= ZOOM_SPEED;
}

void View::zoomOut() {
	_zoom *= ZOOM_SPEED;
}

void View::resize(int width, int height) {
	_width = width;
	_height = height;
	if (width * height > _imgN) {
		_imgN = width * height * 2;
		_img = (uint *) std::realloc(_img, (size_t) _imgN);
	}

	if (width > _ordN || height > _ordN) {
		_ordN = std::max(width, height) * 2;
		_ordX = (scalar *) std::realloc(_ordX, (size_t) _ordN);
		_ordY = (scalar *) std::realloc(_ordY, (size_t) _ordN);
	}
}


View::View() {
	_height = INITIAL_HEIGHT;
	_width = INITIAL_WIDTH;

	_ordN = std::max(_width, _height);
	_imgN = _width * _height;

	_img = (uint *) std::malloc(_imgN * sizeof(uint));

	_ordX = (scalar *) std::malloc(_ordN * sizeof(scalar));
	_ordY = (scalar *) std::malloc(_ordN * sizeof(scalar));

	reset();
}


std::string View::getStatus() {
	std::stringstream ss;
	ss << "  Height: " << std::setw(7) << _height
	<< "  Width: " << std::setw(7) << _width
	<< "  Zoom: " << std::setw(7) << (1.0 / _zoom)
	<< "  Center: " << std::setw(7) << _centerX << ", "
	<< std::setw(7) << _centerY << std::endl;

	return ss.str();
}


View::~View() {
	std::free(_img);
	std::free(_ordX);
	std::free(_ordY);
}


void View::reset() {
	_centerX = 0;
	_centerY = 0;
	_zoom = 1;
}


void View::requestCompute(Compositor &c) {
	double minWidth = std::min(_width, _height);
	for (int i = 0; i < _width; i++) {
		_ordX[i] = (scalar) i / _width - 0.5;
		_ordX[i] =
			_centerX + _zoom * (_width / minWidth) * _ordX[i] * 2;
	}

	for (int i = 0; i < _height; i++) {
		_ordY[i] = (scalar) i / _height - 0.5;
		_ordY[i] =
			_centerY + _zoom * (_height / minWidth) * _ordY[i] * 2;
	}

	c.calculate(_img, _ordX, _ordY, _width, _height);
}

}