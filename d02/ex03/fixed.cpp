#include "fixed.hpp"

float fixed::fixed_to_float(fixed::f val) {
	return (float)val / (float)(1 << fixed::scale);
};

int fixed::int_to_fixed(int val) {
		return val << fixed::scale;
};

int fixed::float_to_fixed(float val) {
	return val * (float)(1 << fixed::scale);;
};