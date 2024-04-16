#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("Bureaucrat", 1);
		try
		{
			b.decrementGrade();
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Grade out of range " << e.what() << STOP << std::endl;
		return (0);
	}
	std::cout << "==========================" << std::endl;
	try
	{
		Bureaucrat b("Bureaucrat", 150);
		try
		{
			b.incrementGrade();
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Grade out of range " << e.what() << STOP << std::endl;
		return (0);
	}
	std::cout << "==========================" << std::endl;
	try
	{
		Bureaucrat b("Bureaucrat", 1111);
		try
		{
			b.incrementGrade();
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Grade out of range " << e.what() << STOP << std::endl;
		return (0);
	}
	return (0);
}
