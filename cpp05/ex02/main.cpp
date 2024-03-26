#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

//gradeに大きな値（ex. 1000）を入れるとエラーが出る
int main() {
	ShrubberyCreationForm form("target");
	RobotomyRequestForm form2("Neko");
	Bureaucrat b("Bureaucrat", 40);
	try {
		form.beSigned(b);
		form.execute(b);
		form2.beSigned(b);
		form2.execute(b);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;

}
