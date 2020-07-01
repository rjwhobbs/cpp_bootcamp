#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(const Fixed& src);
		~Fixed(void);

		int getRawBits(void) const;
		int getScale(void) const;
		void setRawBits(int const value);

		int toInt(void) const;
		float toFloat(void) const;

		Fixed& operator=(const Fixed& rhs);

	private:

		int _value;

		static int const _scale;

};

std::ostream& operator<<(std::ostream& o, Fixed const& rhs);

#endif