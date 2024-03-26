#include "AForm.hpp"

Form::Form() : name_("Default"), gradeToSign_(5), gradeToExecute_(6)
{
	isSigned_ = false;
	std::cout << "[Form] Default constructor called" << std::endl;
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute) : name_(name), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
	isSigned_ = false;
	std::cout << "[Form] Constructor called" << std::endl;
}

Form::Form(const Form &rhs) : name_(rhs.name_), gradeToSign_(rhs.gradeToSign_), gradeToExecute_(rhs.gradeToExecute_)
{
	std::cout << "[Form] Copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "[Form] Destructor called" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << "[Form] Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->isSigned_ = rhs.getIsSigned();
	}
	return *this;
}

std::string Form::getName() const
{
	return this->name_;
}

bool Form::getIsSigned() const
{
	return this->isSigned_;
}

int Form::getGradeToSign() const
{
	return this->gradeToSign_;
}

int Form::getGradeToExecute() const
{
	return this->gradeToExecute_;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->gradeToSign_)
		this->isSigned_ = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Form::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream &os, const Form &form)
{
	os << "Form name: " << form.getName() << std::endl;
	os << "Grade to sign: " << form.getGradeToSign() << std::endl;
	os << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	os << "Signed: " << form.getIsSigned() << std::endl;
	return (os);
}
