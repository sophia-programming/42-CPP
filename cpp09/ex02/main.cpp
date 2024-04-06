#include "PmergeMe.hpp"

unsigned int ft_stou(const std::string &str){
	unsigned int num;
	std::stringstream ss(str);

	ss >> num;
	return num;
}

int main(int argc, char **argv) {
	if (argc == 1)
		return EXIT_SUCCESS;
	PmergeMe pmm;

	try {
		for (int i = 1; i < argc; i++) {
			if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
				throw PmergeMe::InvalidElementException();
		}

		std::vector<unsigned int> vec;
		for (int i = 0; i < argc; i++) {
			vec.push_back(ft_stou(argv[i]));
		}

		std::vector<unsigned int>::iterator itr;
		std::vector<unsigned int>::iterator itr2;
		for (itr = vec.begin(); itr != vec.end(); itr++) {
			for (itr2 = itr + 1; itr2 != vec.end(); itr2++) {
				if (*itr == *itr2)
					throw PmergeMe::InvalidElementException();
				}
			}
		}
	catch (PmergeMe::InvalidElementException &e) {
		std::cerr << RED << e.what() << STOP << std::endl;
		return EXIT_FAILURE;
	}
	pmm.sortVector(argc, argv);
	std::cout << std::endl;
	pmm.sortList(argc, argv);

	return EXIT_SUCCESS;
}
