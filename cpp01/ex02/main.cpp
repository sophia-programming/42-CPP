#include <string>
#include <iostream>
int main()
{
	std::string string = "HI THIS IS BRAIN";
	const std::string *stringPTR = &string;
	const std::string &stringREF = string;

	std::cout << "<memory address>" << std::endl;
	std::cout << "The memory address of the string variable(string) : " << &string << std::endl;
	std::cout << "The memory address held by stringPTR              : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF              : " << &stringREF << std::endl;

	std::cout << "<value>" << std::endl;
	std::cout << "The value of the string variable(string)          :" << string << std::endl;
	std::cout << "The value pointed to by stringPTR                 :" << string << std::endl;
	std::cout << "The value pointed to by stringREF                 :" << string << std::endl;
}
