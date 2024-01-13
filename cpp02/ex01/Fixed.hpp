//
// Created by 小平波琉 on 2022/08/04.
//

#ifndef CPP_FIXED_HPP
#define CPP_FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const int &value);
	Fixed(const float &value);
	~Fixed();
	Fixed(const Fixed &rhs);
	Fixed &operator=(const Fixed &rhs);

	int getRawBits() const;
	void setRawBits(int rawBits);
	float toFloat() const;
	int toInt() const;

private:
	int rawBits_;
	static const int kFractionalBits_ = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &rhs);

#endif //CPP_FIXED_HPP
