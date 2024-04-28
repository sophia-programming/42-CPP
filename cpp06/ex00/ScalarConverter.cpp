#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	std::cout << "Copy constructor" << std::endl;
	*this = src;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src) {
	std::cout << "Assignation operator" << std::endl;
	if (this != &src) {
		*this = src;
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor" << std::endl;
}

bool	ScalarConverter::convert(std::string str) {
	if (str.empty()) {
		std::cerr << RED << "Empty string" << STOP << std::endl;
		return false;
	}
	if (convertPseudo(str))
		return true;
	if (convertInt(str) || convertChar(str) || convertDouble(str) || convertFloat(str))
		return true;
	std::cerr << RED << "Invalid input: " << str << STOP << std::endl;
	return false;
}

bool	ScalarConverter::convertChar(const std::string &str) {
	if (str.length() == 1) {
		char	c = str[0];

		if (' ' <= static_cast<char>(c) && static_cast<char>(c) <= '~')
			std::cout << YELLOW << "char: " << STOP << static_cast<char>(c) << std::endl;
		else
			std::cout << YELLOW << "char: " << STOP << "Non displayable" << std::endl;

		//最大値以上、最小値以下の場合はimpossibleと表示
		if (static_cast<int>(c) < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < static_cast<int>(c))
			std::cout << YELLOW << "int: " << STOP << "impossible" << std::endl;
		else
			std::cout << YELLOW << "int: " << STOP << static_cast<int>(c) << std::endl;

		const std::ios::fmtflags flags = std::cout.flags(); // フラグを保存

		if (static_cast<float>(c) == static_cast<int>(c))
			std::cout << std::fixed << std::setprecision(1); //小数点以下1桁
		else
			std::cout << std::setprecision(8);
		std::cout << YELLOW << "float: " << STOP << static_cast<float>(c) << 'f' << std::endl;

		std::cout.flags(flags); // フラグを元に戻す

		if (static_cast<double>(c) == static_cast<int>(c))
			std::cout << std::fixed << std::setprecision(1);
		else
			std::cout << std::setprecision(20);
		std::cout << YELLOW << "double: " << STOP << static_cast<double>(c) << std::endl;
		std::cout.flags(flags);
		return (true);
	}
	return (false);
}

bool	ScalarConverter::convertInt(const std::string &str) {
	std::stringstream ss;
	int n;

	ss << str;
	ss >> n;
	if (!ss.fail() && ss.eof()) {
		if (' ' <= static_cast<char>(n) && static_cast<char>(n) <= '~')
			std::cout << YELLOW << "char: " << STOP << static_cast<char>(n) << std::endl;
		else
			std::cout << YELLOW << "char: " << STOP << "Non displayable" << std::endl;

		//最大値以上、最小値以下の場合はimpossibleと表示
		if (static_cast<int>(n) < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < static_cast<int>(n))
			std::cout << YELLOW << "int: " << STOP << "impossible" << std::endl;
		else
			std::cout << YELLOW << "int: " << STOP << static_cast<int>(n) << std::endl;

		const std::ios::fmtflags flags = std::cout.flags(); // フラグを保存

		if (static_cast<float>(n) == static_cast<int>(n))
			std::cout << std::fixed << std::setprecision(1); //小数点以下1桁
		else
			std::cout << std::setprecision(8);
		std::cout << YELLOW << "float: " << STOP << static_cast<float>(n) << 'f' << std::endl;

		std::cout.flags(flags); // フラグを元に戻す

		if (static_cast<double>(n) == static_cast<int>(n))
			std::cout << std::fixed << std::setprecision(1);
		else
			std::cout << std::setprecision(20);
		std::cout << YELLOW << "double: " << STOP << static_cast<double>(n) << std::endl;
		std::cout.flags(flags);
		return (true);
	}
	return (false);
}

bool	ScalarConverter::convertDouble(const std::string &str) {
	std::stringstream ss;
	double dbl;

	ss << str;
	ss >> dbl;
	if (!ss.fail() && ss.eof()) {
		if (' ' <= static_cast<char>(dbl) && static_cast<char>(dbl) <= '~')
			std::cout << YELLOW << "char: " << STOP << static_cast<char>(dbl) << std::endl;
		else
			std::cout << YELLOW << "char: " << STOP << "Non displayable" << std::endl;

		//最大値以上、最小値以下の場合はimpossibleと表示
		if (static_cast<double>(dbl) < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < static_cast<double>(dbl))
			std::cout << YELLOW << "int: " << STOP << "impossible" << std::endl;
		else
			std::cout << YELLOW << "int: " << STOP << static_cast<int>(dbl) << std::endl;

		const std::ios::fmtflags flags = std::cout.flags(); // フラグを保存

		if (static_cast<float>(dbl) == static_cast<int>(dbl))
			std::cout << std::fixed << std::setprecision(1); //小数点以下1桁
		else
			std::cout << std::setprecision(8);
		std::cout << YELLOW << "float: " << STOP << static_cast<float>(dbl) << 'f' << std::endl;

		std::cout.flags(flags); // フラグを元に戻す

		if (static_cast<double>(dbl) == static_cast<int>(dbl))
			std::cout << std::fixed << std::setprecision(1);
		else
			std::cout << std::setprecision(20);
		std::cout << YELLOW << "double: " << STOP << static_cast<double>(dbl) << std::endl;
		std::cout.flags(flags);
		return (true);
	}
	return (false);
}

bool	ScalarConverter::convertFloat(const std::string &str) {
	if (str[str.length() - 1] != 'f')
		return (false);
	std::string	str_trim(str);
	str_trim.erase(str_trim.length() - 1);

	std::stringstream ss;
	float f;

	ss << str_trim;
	ss >> f;
	if (!ss.fail() && ss.eof()) {
		if (' ' <= static_cast<char>(f) && static_cast<char>(f) <= '~')
			std::cout << YELLOW << "char: " << STOP << static_cast<char>(f) << std::endl;
		else
			std::cout << YELLOW << "char: " << STOP << "Non displayable" << std::endl;

		//最大値以上、最小値以下の場合はimpossibleと表示
		if (static_cast<float>(f) < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < static_cast<float>(f))
			std::cout << YELLOW << "int: " << STOP << "impossible" << std::endl;
		else
			std::cout << YELLOW << "int: " << STOP << static_cast<int>(f) << std::endl;

		const std::ios::fmtflags flags = std::cout.flags(); // フラグを保存

		if (static_cast<float>(f) == static_cast<int>(f))
			std::cout << std::fixed << std::setprecision(1); //小数点以下1桁
		else
			std::cout << std::setprecision(8);
		std::cout << YELLOW << "float: " << STOP << static_cast<float>(f) << 'f' << std::endl;

		std::cout.flags(flags); // フラグを元に戻す

		if (static_cast<double>(f) == static_cast<int>(f))
			std::cout << std::fixed << std::setprecision(1);
		else
			std::cout << std::setprecision(20);
		std::cout << YELLOW << "double: " << STOP << static_cast<double>(f) << std::endl;
		std::cout.flags(flags);
		return (true);
	}
	return (false);
}

bool	ScalarConverter::convertPseudo(const std::string &str) {
	if (str == "inf" || str == "+inf" || str == "-inf") {
		std::cout << YELLOW << "char: " << STOP << "impossible" << std::endl;
		std::cout << YELLOW << "int: " << STOP << "impossible" << std::endl;
		std::cout << YELLOW << "float: " << STOP << str << 'f' << std::endl;
		std::cout << YELLOW << "double: " << STOP << str << std::endl;
		return (true);
	}
	if (str == "inff" || str == "+inff" || str == "-inff") {
		std::cout << YELLOW << "char: " << STOP << "impossible" << std::endl;
		std::cout << YELLOW << "int: " << STOP << "impossible" << std::endl;
		std::cout << YELLOW << "float: " << STOP << str << std::endl;
		if (str == "inff")
			std::cout << YELLOW << "double: " << STOP << "inf" << std::endl;
		else if (str == "+inff")
			std::cout << YELLOW << "double: " << STOP << "+inf" << std::endl;
		else
			std::cout << YELLOW << "double: " << STOP << "-inf" << std::endl;
		return (true);
	}
	if (str == "nan" || str == "+nan") {
		std::cout << YELLOW << "char: " << STOP << "impossible" << std::endl;
		std::cout << YELLOW << "int: " << STOP << "impossible" << std::endl;
		std::cout << YELLOW << "float: " << STOP << str << 'f' << std::endl;
		std::cout << YELLOW << "double: " << STOP << str << std::endl;
		return (true);
	}
	if (str == "nanf" || str == "+nanf") {
		std::cout << YELLOW << "char: " << STOP << "impossible" << std::endl;
		std::cout << YELLOW << "int: " << STOP << "impossible" << std::endl;
		std::cout << YELLOW << "float: " << STOP << str << std::endl;
		if (str == "nanf")
			std::cout << YELLOW << "double: " << STOP << "nan" << std::endl;
		else
			std::cout << YELLOW << "double: " << STOP << "+nan" << std::endl;
		return (true);
	}
	return (false);
}
