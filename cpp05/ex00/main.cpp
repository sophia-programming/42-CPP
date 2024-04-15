#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("Bureaucrat", 1);
		try
		{
			b.decrementGrade();
//			b.incrementGrade();
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
