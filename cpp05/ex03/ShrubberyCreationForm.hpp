#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:
	std::string target_;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	virtual ~ShrubberyCreationForm();
	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &shrubberyCreationForm);

#endif

