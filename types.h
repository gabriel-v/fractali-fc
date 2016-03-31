/**
 * @file
 * @brief
 * @author Gabriel Vijiala 
 * @date 3/27/16
 */

#ifndef PFRACT_TYPES_H
#define PFRACT_TYPES_H

#include <exception>
#include <string>

typedef unsigned int uint;
typedef double scalar;
typedef unsigned char byte;

namespace cf {

	struct error : public std::exception {
		std::string s;

		error(std::string ss) : s(ss) { }

		~error() throw() { }

		const char *what() const throw() { return s.c_str(); }
	};
}
#endif /* PFRACT_TYPES_H */
