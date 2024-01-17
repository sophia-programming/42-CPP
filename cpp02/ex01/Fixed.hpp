#ifndef CPP_FIXED_HPP
#define CPP_FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const int &value);
	Fixed(const float &value);
	Fixed(const Fixed &rhs);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int rawBits);
	float toFloat() const;
	int toInt() const;

private:
	int rawBits_;
	static const int FractionalBits_ = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &rhs);

#endif
