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
		display(c, \
			(FlagRegular << ShiftChar) \
			+ (FlagCast << ShiftInt) \
			+ (FlagCast << ShiftFloat) \
			+ (FlagCast << ShiftDouble));
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
		display(n, \
			(FlagCast << ShiftChar) \
			+ (FlagRegular << ShiftInt) \
			+ (FlagInteger << ShiftFloat) \
			+ (FlagInteger << ShiftDouble));
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
		int	flag;
		flag = (FlagCast << ShiftChar) \
			+ (FlagCast << ShiftFloat) \
			+ (FlagRegular << ShiftDouble);
		if (std::numeric_limits<int>::max() < dbl)
			flag += (FlagMax << ShiftInt);
		else if (dbl < std::numeric_limits<int>::min())
			flag += (FlagMin << ShiftInt);
		else
			flag += (FlagCast << ShiftInt);
		display(dbl, flag);
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
		int	flag;
		(void)flag; // to avoid warning (unused variable)
		flag = (FlagCast << ShiftChar) \
			+ (FlagRegular << ShiftFloat) \
			+ (FlagCast << ShiftDouble);
		if (std::numeric_limits<int>::max() < f)
			flag += (FlagMax << ShiftInt);
		else if (f < std::numeric_limits<int>::min())
			flag += (FlagMin << ShiftInt);
		else
			flag += (FlagCast << ShiftInt);
		display(f, flag);
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

template <typename T>
void ScalarConverter::display(T scalar, int flag) {
	(void)flag;
	if (' ' <= static_cast<char>(scalar) && static_cast<char>(scalar) <= '~')
		std::cout << YELLOW << "char: " << STOP << static_cast<char>(scalar) << std::endl;
	else
		std::cout << YELLOW << "char: " << STOP << "Non displayable" << std::endl;

	//最大値以上、最小値以下の場合はimpossibleと表示
	if (static_cast<int>(scalar) <= std::numeric_limits<int>::min() || std::numeric_limits<int>::max() <= static_cast<int>(scalar))
		std::cout << YELLOW << "int: " << STOP << "impossible" << std::endl;
	else
		std::cout << YELLOW << "int: " << STOP << static_cast<int>(scalar) << std::endl;

	const std::ios::fmtflags flags = std::cout.flags(); // フラグを保存

	if (static_cast<float>(scalar) == static_cast<int>(scalar))
		std::cout << std::fixed << std::setprecision(1); //小数点以下1桁
	else
		std::cout << std::setprecision(8);
	std::cout << YELLOW << "float: " << STOP << static_cast<float>(scalar) << 'f' << std::endl;

	std::cout.flags(flags); // フラグを元に戻す

	if (static_cast<double>(scalar) == static_cast<int>(scalar))
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::setprecision(20);
	std::cout << YELLOW << "double: " << STOP << static_cast<double>(scalar) << std::endl;
	std::cout.flags(flags);
}
