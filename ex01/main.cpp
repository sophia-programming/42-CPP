#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string input;
	while (true) {
		std::cout << GREEN << "Please select one of the options." << STOP << std::endl;
		std::cout << UNDERLINE << "[ ADD | SEARCH | EXIT ]  $> " << STOP;

		if (!std::getline(std::cin, input))
			break ;
		if (input == "ADD") {
			phoneBook.addContact();
			continue ;
		}
		else if (input == "SEARCH") {
			phoneBook.searchContact();
			continue ;
		}
		else if (input == "EXIT") {
			return 1;
		}
		else if (is_str_unprintable(input) == true) {
			continue ;
		}
		else {
			std::cout << RED << "invalid input!   "
					  << "Please select one of the options!" << std::endl
					  << "[ ADD | SEARCH | EXIT ]" << STOP << std::endl;
		}
	}
}
