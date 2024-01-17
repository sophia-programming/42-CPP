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

	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int getRawBits() const;
	void setRawBits(int rawBits);
	float toFloat() const;
	int toInt() const;

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);

	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

private:
	int rawBits_;
	static const int FractionalBits_ = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &rhs);
#endif
