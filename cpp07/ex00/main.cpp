#include "whatever.hpp"

static int assignment_test(void){
	std::cout << GREEN << "======= assignment_test =======" << STOP << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

static int	my_test(void) {
	std::cout << GREEN << "========== my_test ==========" << STOP << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine";

	std::cout << YELLOW << "Before swap" << STOP << std::endl;
	std::cout << "c[" << &c << "] = " << c << ", d[" << &d << "] = " << d << std::endl;
	::swap(c, d);
	std::cout << YELLOW << "After swap" << STOP << std::endl;
	std::cout << "c[" << &c << "] = " << c << ", d[" << &d << "] = " << d << std::endl;

	std::cout  << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout  << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << GREEN << "Different types" << STOP << std::endl;
	float	a = 3.4;
	int		b = 2;

	std::cout << YELLOW << "Before swap" << STOP << std::endl;
	std::cout << "a[" << &a << "] = " << a << ", b[" << &b << "] = " << b << std::endl;
	::swap( a, b );
	std::cout << YELLOW << "After swap" << STOP << std::endl;
	std::cout << "a[" << &a << "] = " << a << ", b[" << &b << "] = " << b << std::endl;
	std::cout  << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout  << "max( a, b ) = " << ::max( a, b ) << std::endl;
	return (0);
}

int main() {
	assignment_test();
	my_test();
	return 0;
}
