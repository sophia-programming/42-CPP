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

static bool isChar(const std::string &str, size_t &len) {
	if (len == 1 && !isdigit(str[0]))
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
	return true;
}

static bool isFloat(const std::string &str) {
	size_t dot = str.find('.');
	if (dot == std::string::npos)
		return false;

	if (dot + 1 >= str.length() || !isdigit(str[dot + 1])) {
		std::cerr << RED << "Error: Malformed number. ExRED << pected at least one digit after decimal point." << STOP << std::endl;
		return 1;
	}
	// Check characters before the dot
	if (0 < dot) {  // Ensure there's at least one character before the dot
		if (str[0] != '+' && str[0] != '-' && !isdigit(str[0]))
			return false;
		for (size_t j = 1; j < dot; j++) {
			if (!isdigit(str[j]))
				return false;
		}
	}
	// Check characters after the dot
	bool foundF = false;
	for (size_t i = dot + 1; i < str.length(); i++) {
		if (str[i] == 'f') {
			if (i != str.length() - 1)
				return false;
			foundF = true;
		} else if (!isdigit(str[i]))
			return false;
	}

	if (dot + 1 == str.length() || (foundF && dot + 2 == str.length()))
		return false;
	return true;
}

e_type  getType(const std::string &str, size_t &len)
{
	size_t  dot = str.find('.');
	size_t  f = str.find('f');
	if (dot == std::string::npos)
	{
		if (isSpecial(str))
			return SPECIAL;
		if (isChar(str, len))
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
