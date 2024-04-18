#include "ScalarConverter.hpp"

static bool isSpecial(const std::string &str) {
	if (str == "nan" || str == "nanf")
		return true;
	if (str == "inf" || str == "inff")
		return true;
	if (str == "+inf" || str == "+inff")
		return true;
	if (str == "-inf" || str == "-inff")
		return true;
	return false;
}

static bool isChar(const std::string &str) {
	size_t len = str.size();

	if (len == 1 && (str[0] == '.' || !isdigit(str[0])))
		return true;
	if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

static bool isInt(const std::string &str) {
	char *endptr = NULL;
	errno = 0;

	long int_value = std::strtol(str.c_str(), &endptr, 10);

	if (*endptr != '\0' || endptr == str.c_str()) {
		std::cerr << RED << "Invalid input: Contains non-numeric characters or is empty." << STOP << std::endl;
		return false;
	}

	if (errno == ERANGE || int_value < INT_MIN || INT_MAX < int_value) {
		std::cerr << RED << "Integer overflow: Value is out of range for int." << STOP << std::endl;
		return false;
	}
	return str.length() > 0;
}

static bool isFloat(const std::string &str) {
	size_t dot = str.find('.');
	if (dot == std::string::npos || str.find('.', dot + 1) != std::string::npos) {
		std::cerr << RED << "Invalid input: Incorrect dot usage." << STOP << std::endl;
		return false;
	}

	// ドット前の文字が数値または符号かチェック
	if (dot > 0 && (str[0] != '+' && str[0] != '-' && !isdigit(str[0]))) {
		std::cerr << RED << "Invalid input: Invalid start character." << STOP << std::endl;
		return false;
	}
	for (size_t j = 1; j < dot; j++) {
		if (!isdigit(str[j])) {
			std::cerr << RED << "Invalid input: Non-digit characters found before the dot." << STOP << std::endl;
			return false;
		}
	}

	// ドット後の文字が数値かどうかチェック
	if (dot + 1 == str.length() || !isdigit(str[dot + 1])) {
		std::cerr << RED << "Invalid input: No digits after dot." << STOP << std::endl;
		return false;
	}
	for (size_t i = dot + 2; i < str.length(); i++) {
		if (str[i] == 'f' && i + 1 != str.length()) {
			std::cerr << RED << "Invalid input: Misplaced 'f' or extra characters." << STOP << std::endl;
			return false;
		}
		if (!isdigit(str[i]) && str[i] != 'f') {
			std::cerr << RED << "Invalid input: Non-numeric characters after dot." << STOP << std::endl;
			return false;
		}
	}
	return true;
}

e_type  getType(const std::string &str)
{
	size_t  dot = str.find('.');
	size_t  f = str.find('f');
	if (dot == std::string::npos)
	{
		if (isSpecial(str))
			return SPECIAL;
		if (isChar(str))
			return CHAR;
		if (isInt(str))
			return INT;
	}
	if (f != std::string::npos && dot != std::string::npos)
	{
		if (isFloat(str))
			return FLOAT;
	}
	else if (f == std::string::npos && dot != std::string::npos)
		return DOUBLE;
	return INVALID;
}
