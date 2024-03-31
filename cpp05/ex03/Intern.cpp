#include "Intern.hpp"

Intern::Intern() {
	return ;
}

Intern::Intern(const Intern &src) {
	*this = src;
	return ;
}

Intern::~Intern() {
	return ;
}

Intern &Intern::operator=(const Intern &src) {
	if (this != &src) {

	}
	return *this;
}

Form *makeShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form *makeRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

Form *makePresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(const std::string &formName, std::string target) {
	typedef Form *(*formFunc)(std::string target);
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	formFunc formFuncs[3] = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};
	for(int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << YELLOW << "Intern creates " << formName << STOP << std::endl;
			return formFuncs[i](target);
		}
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	return NULL;
}
