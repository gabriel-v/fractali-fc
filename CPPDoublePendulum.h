//
// Created by gabriel on 4/2/16.
//

#ifndef PFRACT_CPPDOUBLEPENDULUM_H
#define PFRACT_CPPDOUBLEPENDULUM_H


#include "types.h"
#include "CPPCompositor.h"

namespace cf {

	class CPPDoublePendulum: public CPPCompositor {
		virtual uint pixel(scalar x, scalar y);

	};

}

#endif //PFRACT_CPPDOUBLEPENDULUM_H
