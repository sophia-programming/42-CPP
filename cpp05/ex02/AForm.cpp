#include "AForm.hpp"

AForm::AForm() : name_("Default"), gradeToSign_(5), gradeToExecute_(6)
{
	isSigned_ = false;
	std::cout << "[AForm] Default constructor called" << std::endl;
	if (gradeToSign_ < 1 || gradeToExecute_ < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign_ > 150 || gradeToExecute_ > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute) : name_(name), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
	isSigned_ = false;
	std::cout << "[AForm] Constructor called" << std::endl;
	if (gradeToSign_ < 1 || gradeToExecute_ < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign_ > 150 || gradeToExecute_ > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &rhs) : name_(rhs.name_), gradeToSign_(rhs.gradeToSign_), gradeToExecute_(rhs.gradeToExecute_)
{
	std::cout << "[AForm] Copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "[AForm] Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs)
{
	std::cout << "[AForm] Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->isSigned_ = rhs.getIsSigned();
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->name_;
}

bool AForm::getIsSigned() const
{
	return this->isSigned_;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign_;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute_;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->gradeToSign_)
		this->isSigned_ = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!this->isSigned_) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > this->gradeToExecute_) {
		throw GradeTooLowException();
	}
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "AForm is not signed";
}

std::ostream& operator<<(std::ostream &os, const AForm &form)
{
	os << "AForm name: " << form.getName() << std::endl;
	os << "Grade to sign: " << form.getGradeToSign() << std::endl;
	os << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	os << "Signed: " << form.getIsSigned() << std::endl;
	return (os);
}
