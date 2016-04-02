//
// Created by gabriel on 4/2/16.
//

#include "CPPDoublePendulum.h"
#include <cmath>

const double m1 = 1.1;
const double m2 = 0.9;
const double l1 = 1.12;
const double l2 = 2.91;
const double g = -10;
const double dt = 0.035;
const int N = 38;

double w1p(double t1, double t2, double w1, double w2) {
	return (
		       -g * (2 * m1 + m2) * sin(t1)
		       - m2 * g * sin(t1 - 2 * t2)
		       - 2 * sin(t1 - t2) * m2 * (l2 * w2 * w2 + l1 * w1 * w1 * cos(t1 - t2))
	       ) / (
		       l1 * (2 * m1 + m2 * (1 - cos(2 * (t1 - t2))))
	       );
}

double w2p(double t1, double t2, double w1, double w2) {
	return 2 * sin(t1 - t2) *
	       (
		       l1 * w1 * w1 * (m1 + m2) +
		       cos(t1) * g * (m1 + m2) +
		       l2 * m2 * w2 * w2 * cos(t1 - t2)
	       ) / (
		       l2 * (2 * m1 + m2 * (1 - cos(2 * (t1 - t2))))
	       );
}

uint cf::CPPDoublePendulum::pixel(scalar x, scalar y) {
	double t1 = x;
	double t2 = y;

	double w1 = 0;
	double w2 = 0;

	double nt1, nt2, nw1, nw2;

	for(int i = 0; i < N; i++) {
		nt1 = t1 + dt * w1;
		nt2 = t2 + dt * w2;

		nw1 = w1 + dt * w1p(t1, t2, w1, t2);
		nw2 = w2 + dt * w2p(t1, t2, w1, w2);

		t1 = nt1;
		t2 = nt2;
		w1 = nw1;
		w2 = nw2;
	}

	return bernstein((1 + sin(t2)) / 2);
}
