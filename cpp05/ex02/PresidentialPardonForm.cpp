#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target_("default") {
	std::cout << MAGENTA << "[PresidentialPardonForm] default constructor" << STOP << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target_(target) {
	std::cout << MAGENTA << "[PresidentialPardonForm] constructor called" << STOP << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : AForm(rhs), target_(rhs.target_) {
	std::cout << MAGENTA << "[PresidentialPardonForm] copy constructor called" << STOP << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << MAGENTA << "[PresidentialPardonForm] destructor called" << STOP << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	std::cout << MAGENTA << "[PresidentialPardonForm] assignation operator called" << STOP << std::endl;
	if (this != &rhs) {
		this->target_ = rhs.target_;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else
		std::cout << this->target_ << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &presidentialPardonForm) {
	os << "PresidentialPardonForm " << presidentialPardonForm.getName() << " is ";
	if (presidentialPardonForm.getIsSigned())
		os << "signed";
	else
		os << "not signed";
	os << " and requires grade " << presidentialPardonForm.getGradeToSign() << " to sign and grade " << presidentialPardonForm.getGradeToExecute() << " to execute";
	return os;
}
