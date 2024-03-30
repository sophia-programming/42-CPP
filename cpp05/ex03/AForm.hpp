#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
private:
	const std::string name_;
	bool isSigned_;
	const int gradeToSign_;
	const int gradeToExecute_;

public:
	Form();
	Form(const std::string &name, const int gradeToSign, const int gradeToExecute);
	Form(const Form &rhs);
	Form &operator=(const Form &rhs);
	virtual ~Form();

	std::string getName() const;
	bool getIsSigned() const;
	int  getGradeToSign() const;
	int  getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);

	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
