#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	private:
	std::string target_;

	public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &rhs);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	virtual ~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &presidentialPardonForm);

#endif
