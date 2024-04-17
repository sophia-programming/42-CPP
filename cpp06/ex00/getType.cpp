#include "ScalarConverter.hpp"

static bool isSpecial(const std::string &str) {
	if (str == "nan" || str == "nanf")
		return true;
	if (str == "+inf" || str == "+inff")
		return true;
	if (str == "-inf" || str == "-inff")
		return true;
	return false;
}

static bool isChar(const std::string &str) {
	size_t len = str.size();

	if (len == 1 && !isdigit(str[0]))
		return true;
	if (len == 3 && str[0] == '\'' && str[2] == '\'' && !isdigit(str[1]))
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
	return true;
}

static bool isFloat(const std::string &str) {
	size_t dot = str.find('.');
	if (dot == std::string::npos){
		std::cerr << RED << "Invalid input: No dot found." << STOP << std::endl;
		return false;
	}

	// Check if there's a digit after the dot
	if (str.length() <= dot + 1 || !isdigit(str[dot + 1])){
		std::cerr << RED << "Invalid input" << STOP << std::endl;
		return false;
	}

	// Check characters before the dot
	if (0 < dot) {  // Ensure there's at least one character before the dot
		if (str[0] != '+' && str[0] != '-' && !isdigit(str[0])) {
			std::cerr << RED << "Invalid input: Invalid start character." << STOP << std::endl;
			return false;
		}

		for (size_t j = 1; j < dot; j++) {
			if (!isdigit(str[j])){
				std::cerr << RED << "Invalid input: Non-digit characters found before the dot." << STOP << std::endl;
				return false;
			}
		}
	} else {
		std::cerr << RED << "Invalid input: No characters found before the dot." << STOP << std::endl;
		return false;
	}

	// Check characters after the dot
	bool foundF = false;
	for (size_t i = dot + 1; i < str.length(); i++) {
		if (str[i] == 'f') {
			if (i != str.length() - 1){
				std::cerr << RED << "Invalid input: Characters found after 'f' ." << STOP << std::endl;
				return false;
			}
			foundF = true;
		} else if (!isdigit(str[i])){
			std::cerr << RED << "Invalid input: Contains non-numeric characters." << STOP << std::endl;
			return false;
		}
	}
	if (dot + 1 == str.length() || (foundF && dot + 2 == str.length()))
		return false;
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
