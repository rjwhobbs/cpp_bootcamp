#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed& src);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const value);
		Fixed& operator=(const Fixed& rhs);

	private:
	int _value;

	static int const _scale;
};
#endif