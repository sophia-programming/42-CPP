#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern intern;

	Form *form1 = intern.makeForm("shrubbery creation", "Garden");
	if (form1 != nullptr) {
		std::cout << *form1 << std::endl;
		delete form1;
	}

	Form *form2 = intern.makeForm("robotomy request", "Bender");
	if (form2 != nullptr) {
		std::cout << *form2 << std::endl;
		delete form2;
	}

	Form *form3 = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");
	if (form3 != nullptr) {
		std::cout << *form3 << std::endl;
		delete form3;
	}

	std::cout << "----------------------------------------" << std::endl;

	// 存在しないフォーム名を指定（"Intern cannot create" メッセージが出る）
	Form *formUnknown = intern.makeForm("unknown form", "Nowhere");
	if (formUnknown != nullptr) {
		std::cout <<  *formUnknown << std::endl;
		delete formUnknown;
	}
	return 0;
}
