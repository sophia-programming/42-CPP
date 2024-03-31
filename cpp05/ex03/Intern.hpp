#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern {
public:
	Intern();
	Intern(const Intern &src);
	~Intern();
	Intern &operator=(const Intern &src);

	Form *makeForm(std::string const &formName, std::string target);
};

#endif
