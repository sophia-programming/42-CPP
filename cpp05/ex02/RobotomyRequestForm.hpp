#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string target_;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &rhs);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	virtual ~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &robotomyRequestForm);

#endif
