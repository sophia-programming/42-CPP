#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){
	std::cout << "Default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src){
	std::cout << "Copy constructor" << std::endl;
	*this = src;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs) {
	std::cout << "Assignation operator" << std::endl;
	if (this != &rhs)
		*this = rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(void){
	std::cout << "Destructor" << std::endl;
}

void    ScalarConverter::convert(const std::string &str)
{
	size_t  len = str.length();
	e_type  type = getType(str, len);
	switch(type)
	{
		case INVALID:
			std::cout << RED << "Invalid input" << STOP << std::endl;
			break;
		case SPECIAL:
			printSpecial(str);
			break;
		case CHAR:
			convertChar(str, len);
			break;
		case INT:
			convertInt(str);
			break;
		case FLOAT:
			convertFloat(str);
			break;
		case DOUBLE:
			convertDouble(str);
			break;
	}
}
