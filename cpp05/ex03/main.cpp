#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern intern;
	Bureaucrat highRankBureaucrat("HighRank", 1);
	Bureaucrat lowRankBureaucrat("LowRank", 150);

	Form *form1 = intern.makeForm("shrubbery creation", "Garden");
	if (form1) {
		try {
			lowRankBureaucrat.signForm(*form1);
			std::cout << "Signed: " << form1->getIsSigned() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete form1;
	}

	std::cout << "----------------------------------------" << std::endl;
	Form *form2 = intern.makeForm("robotomy request", "Bender");
	if (form2) {
		try {
			highRankBureaucrat.signForm(*form2);
			std::cout << "Signed: " << form2->getIsSigned() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete form2;
	}

	std::cout << "----------------------------------------" << std::endl;
	Form *form3 = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");
	if (form3) {
		try {
			highRankBureaucrat.signForm(*form3);
			std::cout << "Signed: " << form3->getIsSigned() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete form3;
	}

	std::cout << "----------------------------------------" << std::endl;

//	 存在しないフォーム名を指定（"Intern cannot create" メッセージが出る）
	Form *formUnknown = intern.makeForm("unknown form", "Nowhere");
	if (formUnknown != NULL) {
		std::cout <<  *formUnknown << std::endl;
		delete formUnknown;
	}
	return 0;
}
