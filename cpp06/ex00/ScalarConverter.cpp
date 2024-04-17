#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs) {
	std::cout << "Copy constructor" << std::endl;
	*this = rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	std::cout << "Assignation operator" << std::endl;
	if (this != &rhs)
		*this = rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor" << std::endl;
}

void ScalarConverter::convert(const std::string &str) {
	size_t len = str.length();
	e_type type = getType(str);
	switch (type) {
		case INVALID:
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
