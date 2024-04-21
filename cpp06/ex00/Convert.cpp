#include "ScalarConverter.hpp"

//bool ScalarConverter::convertPseudo(const std::string &str) {
//	if (str == "inf" || str == "+inf") {
//		display(str, \
//			(0x4 << 12) \
//			+ (0x4 << 8) \
//			+ (0x4 << 4) \
//			+ (0x4 << 0));
//		return (true);
//	}
//	if (str == "-inf") {
//		display(str, \
//			(0x2 << 12) \
//			+ (0x2 << 8) \
//			+ (0x2 << 4) \
//			+ (0x2 << 0));
//		return (true);
//	}
//	if (str == "nan") {
//		display(str, \
//			(0x8 << 12) \
//			+ (0x8 << 8) \
//			+ (0x8 << 4) \
//			+ (0x8 << 0));
//		return (true);
//	}
//	return (false);
//}
//
//}

bool ScalarConverter::convertInt(const std::string &str) {
	std::istringstream ss(str);
	long long n;
	ss >> n;
	if (!ss.fail() && ss.eof()) {
		if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max()) {
			displayLongLong(n);
		} else {
			display(static_cast<int>(n));
		}
		return true;
	}
	return false;
}

bool ScalarConverter::convertChar(const std::string &str) {
	if (str.length() == 1 && isprint(str[0])) {
		display(str[0]);
		return true;
	}
	return false;
}

bool ScalarConverter::convertDouble(const std::string &str) {
	std::istringstream ss(str);
	double dbl;
	ss >> dbl;
	if (!ss.fail() && ss.eof()) {
		display(dbl);
		return true;
	}
	return false;
}

bool ScalarConverter::convertFloat(const std::string &str) {
	if (str.back() == 'f') {
		std::string trimmed = str.substr(0, str.size() - 1);
		std::istringstream ss(trimmed);
		float f;
		ss >> f;
		if (!ss.fail() && ss.eof()) {
			display(f);
			return true;
		}
	}
	return false;
}

void ScalarConverter::display(int value) {
	std::cout << "char: ";
	if (std::isprint(static_cast<int>(value))) {
		std::cout << "'" << std::string(1, static_cast<char>(value)) << "'" << std::endl;
	} else {
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::display(double value) {
	if (value >= std::numeric_limits<int>::min() || value <= std::numeric_limits<int>::max()) {
		display(static_cast<int>(value));
	} else {
		std::cout << "int: " << "impossible" << std::endl;
	}
	std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;
	std::cout << "double: " << value << std::endl;
}

void ScalarConverter::display(float value) {
	std::cout << "float: " << value << 'f' << std::endl;
	display(static_cast<double>(value));
}

void ScalarConverter::displayLongLong(long long value) {
	if (isprint(static_cast<int>(value))) {
		std::cout << "char: " << static_cast<char>(value) << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}
