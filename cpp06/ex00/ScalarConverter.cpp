#include "ScalarConverter.hpp"

bool	ScalarConverter::convert(std::string &str) {
	if (str.empty()) {
		std::cerr << RED << "Empty string" << STOP << std::endl;
		return false;
	}
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
		display(f, \
			(FlagCast << ShiftChar) \
			+ (FlagCast << ShiftInt) \
			+ (FlagRegular << ShiftFloat) \
			+ (FlagCast << ShiftDouble));
		return (true);
	}
	return (false);
}

bool	ScalarConverter::convertPseudo(const std::string &str) {
	if (str == "inf" || str == "+inf") {
		display(str, \
			(FlagMax << ShiftChar) \
			+ (FlagMax << ShiftInt) \
			+ (FlagMax << ShiftFloat) \
			+ (FlagMax << ShiftDouble));
		return (true);
	}
	if (str == "-inf") {
		display(str, \
			(FlagMin << ShiftChar) \
			+ (FlagMin << ShiftInt) \
			+ (FlagMin << ShiftFloat) \
			+ (FlagMin << ShiftDouble));
		return (true);
	}
	if (str == "nan") {
		display(str, \
			(FlagImpossible << ShiftChar) \
			+ (FlagImpossible << ShiftInt) \
			+ (FlagPseudo << ShiftFloat) \
			+ (FlagPseudo << ShiftDouble));
		return (true);
	}
	return (false);
}

void	ScalarConverter::display(const std::string &str, int flag) {
	std::cout << YELLOW << "char: " << STOP << "impossible" << std::endl;

	if (((flag >> ShiftInt) & MaskFlags) == FlagMax)
		std::cout << YELLOW << "int: " << STOP << std::numeric_limits<int>::max();
	else if (((flag >> ShiftInt) & MaskFlags) == FlagMin)
		std::cout << YELLOW << "int: " << STOP << std::numeric_limits<int>::min();
	else
		std::cout << YELLOW << "int: " << STOP << "impossible";

	std::cout << YELLOW << "float: " << STOP << str << 'f' << std::endl;
	std::cout << YELLOW << "double: " << STOP << str << std::endl;
}

template <typename T>
void	ScalarConverter::display(T scalar, int flag) {
	if (' ' <= static_cast<char>(scalar) && static_cast<char>(scalar) <= '~')
		std::cout << YELLOW << "char: " << STOP << static_cast<char>(scalar) << std::endl;
	else
		std::cout << YELLOW << "char: " << STOP << "Non displayable" << std::endl;

	if (((flag >> ShiftInt) & MaskFlags) == FlagMax)
		std::cout << YELLOW << "int: " << STOP << std::numeric_limits<int>::max();
	else if (((flag >> ShiftInt) & MaskFlags) == FlagMin)
		std::cout << YELLOW << "int: " << STOP << std::numeric_limits<int>::min();
	else
		std::cout << YELLOW << "int: " << STOP << static_cast<int>(scalar);
	std::cout << std::endl;

	const std::ios::fmtflags flags = std::cout.flags();

	if (static_cast<float>(scalar) == static_cast<int>(scalar))
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::setprecision(8);
	std::cout << YELLOW << "float: " << STOP << static_cast<float>(scalar) << 'f' << std::endl;
	std::cout.flags(flags);

	if (static_cast<double>(scalar) == static_cast<int>(scalar))
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::setprecision(27);
	std::cout << YELLOW << "double: " << STOP << static_cast<double>(scalar) << std::endl;
	std::cout.flags(flags);
}
