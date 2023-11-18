#include <iostream>
#include <vector>

int	main(int argc, char **argv)
{
	try {
		std::cout << "Throw an integer exeception...\n";
		throw 42;
	}
	catch (int i) {
		std::cout << "the integer exception value was caught, with value : " << i << std::endl;
	}

	try {
		std::cout << "Creating a vector of size 5... \n";
		std::vector<int> v(5);
		std::cout << "Accessing the 11th element of the vector...\n";
		std::cout << v.at(10) << std::endl;
	}
	catch (const std::exception& e) // caught by reference to base
	{
		std::cout << " a standard exception was caught, with message '"
				  << e.what() << "'\n";
	}
	return 0;
}
