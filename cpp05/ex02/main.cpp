#include "ShrubberyCreationForm.hpp"

int main() {
	ShrubberyCreationForm form("target");
	Bureaucrat b("Bureaucrat", 150);
	try {
		form.beSigned(b);
		form.execute(b);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;

}
