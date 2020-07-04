#ifndef FIXED_HPP
#define FIXED_HPP

namespace fixed {
	typedef int f;
	int const scale = 8;

	float fixed_to_float(f fixed);
	float fixed_to_int(f fixed);
	int int_to_fixed(int val);
	int float_to_fixed(float val);

};


#endif