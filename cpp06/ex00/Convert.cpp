#include "ScalarConverter.hpp"

bool ScalarConverter::convertInt(const std::string &str) {
	std::istringstream ss(str);
	long long n;
	ss >> n;
	if (!ss.fail() && ss.eof()) {
		display("int", n);
		return true;
	}
	return false;
}

bool ScalarConverter::convertChar(const std::string &str) {
	if (str.length() == 1 && std::isprint(str[0])) {
		display("char", str[0]);
		return true;
	}
	return false;
}

bool ScalarConverter::convertDouble(const std::string &str) {
	double dbl;
	std::istringstream ss(str);
	ss >> dbl;
	if (!ss.fail() && ss.eof()) {
		display("double", dbl);
		return true;
	}
	return false;
}

bool ScalarConverter::convertFloat(const std::string &str) {
	if (str.back() == 'f') {
		std::string str_trim = str.substr(0, str.size() - 1);
		std::istringstream ss(str_trim);
		float f;
		ss >> f;
		if (!ss.fail() && ss.eof()) {
			display("float", f);
			return true;
		}
	}
	return false;
}

bool ScalarConverter::convertPseudo(const std::string &str) {
	if (str == "inf" || str == "-inf" || str == "+inf" || str == "nan") {
		std::cout << "pseudo: " << str << "\n";
		return true;
	}
	return false;
}

void ScalarConverter::display(const std::string &type, double value) {
	std::cout << type << ": ";
	if (type == "char") {
		std::cout << (std::isprint(static_cast<int>(value)) ? "'" + std::string(1, static_cast<char>(value)) + "'" : "Non displayable");
	} else if (type == "int" || type == "double" || type == "float") {
		std::cout << value;
		if (type == "float") std::cout << "f";
	} else if (type == "pseudo") {
		std::cout << value;
	} else {
		std::cout << "invalid";
	}
	std::cout << std::endl;
}
