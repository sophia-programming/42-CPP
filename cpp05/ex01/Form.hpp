#ifndef FORM_HPP
#define FORM_HPP

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
	~Form();
	Form &operator=(const Form &rhs);

	const std::string &getName() const;
	bool getIsSigned() const;
	int  getGradeToSign() const;
	int  getGradeToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);
	void signForm(const Bureaucrat &bureaucrat);


	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

/* colors */
const char *const STOP = "\033[0m";
const char *const BOLD = "\033[1m";
const char *const BLACK = "\033[30m";
const char *const RED = "\033[31m";
const char *const GREEN = "\033[32m";
const char *const YELLOW = "\033[33m";
const char *const BLUE = "\033[34m";
const char *const MAGENTA = "\033[35m";
const char *const CYAN = "\033[36m";
const char *const WHITE = "\033[37m";
const char *const UNDERLINE =" \033[4m";

#endif
