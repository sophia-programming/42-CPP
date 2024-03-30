#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target_("default")
{
	std::cout << BLUE << "[ShrubberyCreationForm] Default constructor called" << STOP << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137), target_(target)
{
	std::cout << BLUE << "[ShrubberyCreationForm] Constructor called" << STOP << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : Form(rhs), target_(rhs.target_)
{
	std::cout << BLUE << "[ShrubberyCreationForm] Copy constructor called" << STOP << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BLUE << "[ShrubberyCreationForm] Destructor called" << STOP << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << BLUE << "[ShrubberyCreationForm] Assignation operator called" << STOP << std::endl;
	if (this != &rhs)
	{
		this->target_ = rhs.target_;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	else if (!this->getIsSigned())
		throw Form::FormNotSignedException();
	std::ofstream file(this->target_ + "_shrubbery");
	if (file.is_open())
	{
		file << "      /\\      " << std::endl;
		file << "     /\\*\\     " << std::endl;
		file << "    /\\O\\*\\    " << std::endl;
		file << "   /*/\\/\\/\\   " << std::endl;
		file << "  /\\O\\/\\*\\/\\  " << std::endl;
		file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << std::endl;
		file.close();
	}
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &shrubberyCreationForm)
{
	os << "ShrubberyCreationForm " << shrubberyCreationForm.getName() << " is ";
	if (shrubberyCreationForm.getIsSigned())
		os << "signed";
	else
		os << "not signed";
	os << " and requires grade " << shrubberyCreationForm.getGradeToSign() << " to sign and grade " << shrubberyCreationForm.getGradeToExecute() << " to execute";
	return os;
}
