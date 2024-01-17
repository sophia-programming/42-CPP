#include "Fixed.hpp"

Fixed::Fixed(): rawBits_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &value)
{
	std::cout << "Int constructor called" << std::endl;
	rawBits_ = (value << FractionalBits_);
}

Fixed::Fixed(const float &value)
{
	std::cout << "Float constructor called" << std::endl;
	rawBits_ = static_cast<int>(roundf(value * (1 << FractionalBits_)));
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		rawBits_ = rhs.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return rawBits_;
}

void Fixed::setRawBits(const int rawBits)
{
	rawBits_ = rawBits;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(rawBits_) / (1 << FractionalBits_));
}

int Fixed::toInt() const
{
	return (rawBits_ >> FractionalBits_);
}

std::ostream &operator<<(std::ostream &os, const Fixed &rhs)
{
	return (os << rhs.toFloat());
}
