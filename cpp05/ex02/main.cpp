#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//gradeに大きな値（ex. 1000）を入れるとエラーが出る

int main() {
	ShrubberyCreationForm form("target");
	Bureaucrat highRankBureaucrat("HighRank", 1);
	Bureaucrat lowRankBureaucrat("LowRank", 150);

	try {
		highRankBureaucrat.signForm(form);
		form.execute(highRankBureaucrat);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}

//int main() {
//	PresidentialPardonForm form("neko");
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

//int main() {
//	PresidentialPardonForm form("dog");
//	Bureaucrat highRankBureaucrat("HighRank", 1); // 高ランクの役人
//	Bureaucrat lowRankBureaucrat("LowRank", 150); // 低ランクの役人
//
//	try {
//		lowRankBureaucrat.signForm(form);
//		form.execute(highRankBureaucrat);
//	} catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}
//	return 0;
//}
//
