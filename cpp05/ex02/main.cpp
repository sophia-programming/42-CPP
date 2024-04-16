#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	ShrubberyCreationForm form("target");
	Bureaucrat highRankBureaucrat("HighRank", 1);
	Bureaucrat lowRankBureaucrat("LowRank", 150);

	try {
		highRankBureaucrat.signForm(form);
		highRankBureaucrat.executeForm(form);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "==========================" << std::endl;
	RobotomyRequestForm form1("neko");

	try {
		lowRankBureaucrat.signForm(form1);
		lowRankBureaucrat.executeForm(form1);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "==========================" << std::endl;
	PresidentialPardonForm form2("dog");

	try {
		highRankBureaucrat.signForm(form2);
		highRankBureaucrat.executeForm(form2);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}

