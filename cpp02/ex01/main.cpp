//
// Created by 小平波琉 on 2022/08/04.
//

#include "Fixed.hpp"

/* PDF */

#include <iostream>
int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "_________output________________" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "_________to Int________________" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "_________to Float______________" << std::endl;
	std::cout << "a is " << a.toFloat() << " as floating point value" << std::endl;
	std::cout << "b is " << b.toFloat() << " as floating point value" << std::endl;
	std::cout << "c is " << c.toFloat() << " as floating point value" << std::endl;
	std::cout << "d is " << d.toFloat() << " as floating point value" << std::endl;
	std::cout << "_______________________________" << std::endl;
	return 0;
}
