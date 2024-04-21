#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &str) {
	std::cout << "Copy constructor" << std::endl;
	*this = str;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &str) {
	std::cout << "Assignation operator" << std::endl;
	if (this != &str)
		*this = str;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor" << std::endl;
}

void ScalarConverter::convert(const std::string &str) {
	if (str.empty()){
		std::cerr << RED << "Empty string" << std::endl;
		return;
	}

//	if (convertInt(str) || convertChar(str) || convertDouble(str)
//		|| convertFloat(str) || convertPseudo(str)) {
	if (convertInt(str) || convertChar(str) || convertDouble(str)
		|| convertFloat(str) )
		return;
	//どの変換も成功しなかった場合
	std::cout << RED << "Invalid input: " << str << STOP << std::endl;
}
