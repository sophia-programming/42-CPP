#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(150) {
	std::cout << "this->grade_ : " << std::endl;
	std::cout << GREEN << "[Bureaucrat] Default constructor called" << STOP << std::endl;
	if (this->grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name), grade_(grade) {
	std::cout << GREEN << "[Bureaucrat] Constructor called" << STOP << std::endl;
	if (this->grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : name_(rhs.name_), grade_(rhs.grade_) {
	std::cout << GREEN << "[Bureaucrat] Copy constructor called"<< STOP << std::endl;
	*this = rhs;
}

Bureaucrat::~Bureaucrat() {
	std::cout << GREEN << "[Bureaucrat] Destructor called" << STOP << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	std::cout << "[Bureaucrat] Assignation operator called" << std::endl;
	if (this != &rhs) {
		this->grade_ = rhs.grade_;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->name_;
}

int Bureaucrat::getGrade() const {
	return this->grade_;
}

void Bureaucrat::incrementGrade() {
	if (this->grade_ <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade_--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade_ >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade_++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << YELLOW << this->getName() << " signed " << form.getName() << STOP << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << this->getName() << " could not sign " << form.getName() << " because " << e.what() << STOP << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << YELLOW << this->getName() << " executed " << form.getName() << STOP << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << this->getName() << " could not execute " << form.getName() << " because " << e.what() << STOP << std::endl;
	}
}
