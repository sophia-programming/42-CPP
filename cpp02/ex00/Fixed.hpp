#ifndef CPP_FIXED_HPP
#define CPP_FIXED_HPP
#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &rhs);
	Fixed &operator=(Fixed const &rhs);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int rawBits_;
	static const int FractionalBits_ = 8;
};

#endif
