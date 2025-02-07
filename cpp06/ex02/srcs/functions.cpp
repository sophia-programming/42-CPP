#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *make_a(void)
{
	return new A;
}

Base *make_b(void)
{
	return new B;
}

Base *make_c(void)
{
	return new C;
}

Base *generate(void)
{
	Base *(*f[3])() = {make_a, make_b, make_c};
	return f[rand() % 3]();
}

void identify(Base *p)
{
	if (!p)
		throw std::invalid_argument("Invalid pointer");
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try {
		B &b = dynamic_cast<B &>(p);
		(void) b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try {
		C &c = dynamic_cast<C &>(p);
		(void) c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	std::cout << "Unknown" << std::endl;
}

