#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs) {
	*this = rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::convert(const std::string &str) {
	size_t len = str.length();
	e_type type = getType(str, len);
	switch (type) {
		case INVALID:
			std::cerr << "Invalid input" << std::endl;
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
