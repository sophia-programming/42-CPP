#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target_("default") {
	std::cout << CYAN << "[RobotomyRequestForm] Default constructor called" << STOP << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target_(target) {
	std::cout << CYAN << "[RobotomyRequestForm] Constructor called" << STOP << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm(rhs), target_(rhs.target_) {
	std::cout << CYAN << "[RobotomyRequestForm] Copy constructor called" << STOP << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << CYAN << "[RobotomyRequestForm] Destructor called" << STOP << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	std::cout << CYAN << "[RobotomyRequestForm] Assignation operator called" << STOP << std::endl;
	if (this != &rhs) {
		this->target_ = rhs.target_;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else {
		std::cout << YELLOW << "Drilling noises" << STOP << std::endl;
		srand(time(0));
		if (rand() % 2){
			std::cout << YELLOW << this->target_  << " has been robotomized successfully" << STOP << std::endl;
			std::cout << "*************" << std::endl;
			std::cout << rand() << std::endl;
			std::cout << "*************" << std::endl;
		}
//
		else
			std::cout << RED << this->target_ <<  " robotomization failed" << STOP << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &robotomyRequestForm) {
	os << "RobotomyRequestForm " << robotomyRequestForm.getName() << " is ";
	if (robotomyRequestForm.getIsSigned())
		os << "signed";
	else
		os << "not signed";
	os << " and requires grade " << robotomyRequestForm.getGradeToSign() << " to sign and grade " << robotomyRequestForm.getGradeToExecute() << " to execute";
	return os;
}
