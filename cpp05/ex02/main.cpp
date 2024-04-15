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
		lowRankBureaucrat.signForm(form);
		form.execute(lowRankBureaucrat);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
//
//int main() {
//	RobotomyRequestForm form("neko");
//	Bureaucrat highRankBureaucrat("HighRank", 1);
//	Bureaucrat lowRankBureaucrat("LowRank", 4);
//
//	try {
//		lowRankBureaucrat.signForm(form);
//		form.execute(lowRankBureaucrat);
//	} catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}
//	return 0;
//}
//
//int main() {
//	PresidentialPardonForm form("dog");
//	Bureaucrat highRankBureaucrat("HighRank", 1);
//	Bureaucrat lowRankBureaucrat("LowRank", 150);
//
//	try {
//		highRankBureaucrat.signForm(form);
//		form.execute(highRankBureaucrat);
//	} catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}
//	return 0;
//}
