#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const& src);
		~Fixed(void);

		int getRawBits(void) const;
		int getScale(void) const;
		void setRawBits(int const value);

		int toInt(void) const;
		float toFloat(void) const;

		Fixed& operator=(Fixed const& rhs);
		Fixed operator+(Fixed& rhs) const;
		Fixed operator-(Fixed& rhs) const;
		Fixed operator*(Fixed& rhs) const;
		Fixed operator/(Fixed& rhs) const;

		bool operator<(Fixed const& rhs);
		bool operator>(Fixed const& rhs);
		bool operator<=(Fixed const& rhs);
		bool operator>=(Fixed const& rhs);
		bool operator==(Fixed const& rhs);
		bool operator!=(Fixed const& rhs);

		void showRawBits(std::string name);

	private:
		int _value;

		static int const _scale;
};

std::ostream& operator<<(std::ostream& o, Fixed const& rhs);

#endif