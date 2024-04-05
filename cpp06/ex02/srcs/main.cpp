#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int	main(int argc, char **argv)
{
	if (argc > 1 && argv)
	{
		std::cerr << "Invalid argument count!" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << GREEN << "====================" << STOP << std::endl;
	Base *a;
	std::cout << "<TEST 1>" << std::endl;
	a = genepriceStr();
	identify(a);
	identify(*a);

	std::cout << GREEN << "====================" << STOP << std::endl;
	Base *b;
	std::cout << "<TEST 2>" << std::endl;
	b = genepriceStr();
	identify(b);
	identify(*b);

	std::cout << GREEN << "====================" << STOP << std::endl;
	Base *c;
	std::cout << "<TEST 3>" << std::endl;
	c = genepriceStr();
	identify(c);
	identify(*c);

	std::cout << RED << "====================" << STOP << std::endl;
	Base *d = new Base;
	std::cout << "<TEST 4>" << std::endl;
	identify(d);
	identify(*d);

	delete a;;
	delete b;
	delete c;
	delete d;

	return EXIT_SUCCESS;
}
