// So it's either this:
#pragma OPENCL EXTENSION cl_khr_fp64 : enable

// If that doesn't work, then this.
//#define double float
//#define cdouble cfloat
//#define double2 float2

typedef double2 complex;

#define I ((complex)(0.0, 1.0))


// Return Real (Imaginary) component of complex number:
double real(complex a) {
	return a.x;
}

double imag(complex a) {
	return a.y;
}

//Get the modulus of a complex number (its length):
double cmod(complex a) {
	return (sqrt(a.x * a.x + a.y * a.y));
}

// Get the argument of a complex number (its angle):
// http://en.wikipedia.org/wiki/Complex_number#Absolute_value_and_argument
double carg(complex a) {
	if (a.x > 0) {
		return atan(a.y / a.x);

	} else if (a.x < 0 && a.y >= 0) {
		return atan(a.y / a.x) + M_PI;

	} else if (a.x < 0 && a.y < 0) {
		return atan(a.y / a.x) - M_PI;

	} else if (a.x == 0 && a.y > 0) {
		return M_PI / 2;

	} else if (a.x == 0 && a.y < 0) {
		return -M_PI / 2;

	} else {
		return 0;
	}
}

// Multiply two complex numbers:
complex cmult(complex a, complex b) {
	return (complex) (a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}


// Divide two complex numbers:
complex cdiv(complex a, complex b) {
	return (complex) ((a.x * b.x + a.y * b.y) / (b.x * b.x + b.y * b.y),
		(a.y * b.x - a.x * b.y) / (b.x * b.x + b.y * b.y));
}


//  Square root of complex number. Other one is rotated by pi
complex csqrt(complex a) {
	return (complex) (sqrt(cmod(a)) * cos(carg(a) / 2), sqrt(cmod(a)) *
	                                                    sin(carg(a) / 2));
}