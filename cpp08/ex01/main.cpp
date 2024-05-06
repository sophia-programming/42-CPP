#include "Span.hpp"
#include <cstdlib>

///* ===== [subject] =====*/
//int main()
//{
//	Span sp = Span(5);
//	sp.addNumber(6);
//	sp.addNumber(3);
//	sp.addNumber(17);
//	sp.addNumber(9);
//	sp.addNumber(11);
//
//	std::cout << sp.shortestSpan() << std::endl;
//	std::cout << sp.longestSpan() << std::endl;
//
//	return 0;
//}

int main(void)
{
	std::cout << GREEN << "=== [ok] ===" << STOP << std::endl;
	Span sp = Span(5);

	sp.addNumber(12);
	sp.addNumber(-3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.printStorage();
	std::cout << "shortestSpan() = " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan() = " << sp.longestSpan() << std::endl;

	std::cout << GREEN << "=== [Pushing beyond N elements] ===" << STOP << std::endl;
	try {
		sp.addNumber(42);
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << STOP << std::endl;
	}

	std::cout << GREEN << "=== [less than 0 elemnts on the vector] ===" << STOP << std::endl;
	Span sp0 = Span(0);
	sp0.printStorage();
	try {
		std::cout << sp0.shortestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << STOP << std::endl;
	}

	std::cout << GREEN << "=== [less than 2 elements on the vector] ===" << STOP << std::endl;
	Span sp1 = Span(1);
	sp1.addNumber(20);
	sp1.printStorage();
	try {
		std::cout << sp1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << STOP << std::endl;
	}

	std::cout << GREEN << "=== [Random & Large Scale Numbers] ===" << STOP << std::endl;
	Span sp2 = Span(100);
	sp2.addRandomNumbers(100);
	sp2.printStorage();
	try {
//		sp2.addNumber(1);
		std::cout << "sp2.shortestSpan() = " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2.longestSpan() = " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << STOP << std::endl;

	}
	return EXIT_SUCCESS;
}
