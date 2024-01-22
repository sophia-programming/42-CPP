#include "Fixed.hpp"

Fixed::Fixed() :rawBits_(0){
//	std::cout << "(Default constructor called)" << std::endl;
}

Fixed::Fixed(const int &value)
{
//	std::cout << "(Int constructor called)" << std::endl;
	rawBits_ = (value << FractionalBits_);
}

Fixed::Fixed(const float &value)
{
//	std::cout << "(Float constructor called)" << std::endl;
	rawBits_ = static_cast<int>(roundf(value * (1 << FractionalBits_)));
}

Fixed::~Fixed()
{
//	std::cout << "(Destructor called)" << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
//	std::cout << "(Copy constructor called)" << std::endl;
	*this = rhs;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
//	std::cout << "(Copy assignment operator called)" << std::endl;
	if (this != &rhs) {
		rawBits_ = rhs.rawBits_;
	}
	return *this;
}

bool Fixed::operator>(const Fixed& rhs) const { return (rawBits_ > rhs.getRawBits()); }
bool Fixed::operator<(const Fixed& rhs) const { return (rawBits_ < rhs.getRawBits()); }
bool Fixed::operator>=(const Fixed& rhs) const { return (rawBits_ >= rhs.getRawBits()); }
bool Fixed::operator<=(const Fixed& rhs) const { return (rawBits_ <= rhs.getRawBits()); }
bool Fixed::operator==(const Fixed& rhs) const { return (rawBits_ == rhs.getRawBits()); }
bool Fixed::operator!=(const Fixed &rhs) const { return(rawBits_ != rhs.getRawBits()); }

Fixed Fixed::operator+(const Fixed &rhs) const { return Fixed(toFloat() + rhs.toFloat()); }
Fixed Fixed::operator-(const Fixed &rhs) const { return Fixed(toFloat() - rhs.toFloat()); }
Fixed Fixed::operator*(const Fixed &rhs) const { return Fixed(toFloat() * rhs.toFloat()); }
Fixed Fixed::operator/(const Fixed &rhs) const { return Fixed(toFloat() / rhs.toFloat()); }

Fixed &Fixed::operator++()
{
	++rawBits_;
	return *this;
}

Fixed &Fixed::operator--()
{
	--rawBits_;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	operator++();
	return old;
}

Fixed Fixed::operator--(int)
{
	 Fixed old = *this;
	 operator--();
	 return old;
}

int Fixed::getRawBits() const
{
	return rawBits_;
}

void Fixed::setRawBits(const int value)
{
	rawBits_ = value;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(rawBits_) / (1 << FractionalBits_));
}

int Fixed::toInt() const
{
	return (rawBits_ >> FractionalBits_);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b) {
		return a;
	} else {
		return b;
	}
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b) {
		return a;
	} else {
		return b;
	}
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
	if (a <= b) {
		return a;
	} else {
		return b;
	}
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
	if (a >= b) {
		return a;
	} else {
		return b;
	}
}

std::ostream &operator<<(std::ostream &os, Fixed const &rhs)
{
	return (os << rhs.toFloat());
}
