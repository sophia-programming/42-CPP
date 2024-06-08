#include "PmergeMe.hpp"

int	main( int argc, char **argv )
{
	if (argc < 3)
	{
		std::cout << RED << "invalid arguments count" << STOP << std::endl;
		return (0);
	}
	try
	{
		PmergeMe algorithm;
		algorithm.merge(argc, argv);
	}
	catch (std::exception const &e)
	{
		std::cerr << RED << e.what() << STOP << std::endl;
	}
}
