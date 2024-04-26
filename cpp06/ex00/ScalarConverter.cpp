#include "ScalarConverter.hpp"

bool	ScalarConverter::convert(std::string &str) {
	if (str.empty() || str.length() == 0) {
		std::cerr << RED << "Empty string" << STOP << std::endl;
		return false;
	}
	if (convertInt(str) || convertChar(str) || convertDouble(str) || convertFloat(str))
		return true;
	std::cerr << RED << "Invalid input: " << str << STOP << std::endl;
	return false;
}

bool	ScalarConverter::convertInt(const std::string &str) {
	std::stringstream	ss;
	int					n;

	ss << str;
	ss >> n;
	if (!ss.fail() && ss.eof()) {
		display(n, \
			(FLAG_CAST << SHIFT_CHAR) \
			+ (FLAG_REGULAR << SHIFT_INT) \
			+ (FLAG_INTEGER << SHIFT_FLOAT) \
			+ (FLAG_INTEGER << SHIFT_DOUBLE));
		return (true);
	}
	return (false);
}

bool	ScalarConverter::convertChar(const std::string &str) {
	if (str.length() == 1) {
		char	c = str[0];
		display(c, \
			(FLAG_REGULAR << SHIFT_CHAR) \
			+ (FLAG_CAST << SHIFT_INT) \
			+ (FLAG_CAST << SHIFT_FLOAT) \
			+ (FLAG_CAST << SHIFT_DOUBLE));
		return (true);
	}
	return (false);
}

bool	ScalarConverter::convertDouble(const std::string &str) {
	if (convertPseudo(str)) {
		std::cout << YELLOW << "double pseudo" << STOP << std::endl;
		return (true);
	}

	std::stringstream	ss;
	double				dbl;

	ss << str;
	ss >> dbl;
	if (!ss.fail() && ss.eof()) {
		int	flag;
		flag = (FLAG_CAST << SHIFT_CHAR) \
			+ (FLAG_CAST << SHIFT_FLOAT) \
			+ (FLAG_REGULAR << SHIFT_DOUBLE);
		if (dbl > std::numeric_limits<int>::max())
			flag += (FLAG_MAX << SHIFT_INT);
		else if (dbl < std::numeric_limits<int>::min())
			flag += (FLAG_MIN << SHIFT_INT);
		else
			flag += (FLAG_CAST << SHIFT_INT);
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

	if (convertPseudo(str_trim)) {
		std::cout << YELLOW << "float pseudo" << STOP << std::endl;
		return (true);
	}

	std::stringstream	ss;
	float	f;

	ss << str_trim;
	ss >> f;
	if (!ss.fail() && ss.eof()) {
		int	flag;
		(void)flag; // to avoid warning (unused variable)
		flag = (FLAG_CAST << SHIFT_CHAR) \
			+ (FLAG_REGULAR << SHIFT_FLOAT) \
			+ (FLAG_CAST << SHIFT_DOUBLE);
		if (f > std::numeric_limits<int>::max())
			flag += (FLAG_MAX << SHIFT_INT);
		else if (f < std::numeric_limits<int>::min())
			flag += (FLAG_MIN << SHIFT_INT);
		else
			flag += (FLAG_CAST << SHIFT_INT);
		display(f, \
			(FLAG_CAST << SHIFT_CHAR) \
			+ (FLAG_CAST << SHIFT_INT) \
			+ (FLAG_REGULAR << SHIFT_FLOAT) \
			+ (FLAG_CAST << SHIFT_DOUBLE));
		return (true);
	}
	return (false);
}

bool	ScalarConverter::convertPseudo(const std::string &str) {
	if (str == STR_INF || str == STR_INF_POS) {
		display(str, \
			(FLAG_MAX << SHIFT_CHAR) \
			+ (FLAG_MAX << SHIFT_INT) \
			+ (FLAG_MAX << SHIFT_FLOAT) \
			+ (FLAG_MAX << SHIFT_DOUBLE));
		return (true);
	}
	if (str == STR_INF_NEG) {
		display(str, \
			(FLAG_MIN << SHIFT_CHAR) \
			+ (FLAG_MIN << SHIFT_INT) \
			+ (FLAG_MIN << SHIFT_FLOAT) \
			+ (FLAG_MIN << SHIFT_DOUBLE));
		return (true);
	}
	if (str == STR_NAN) {
		display(str, \
			(FLAG_IMPOS << SHIFT_CHAR) \
			+ (FLAG_IMPOS << SHIFT_INT) \
			+ (FLAG_PSEUDO << SHIFT_FLOAT) \
			+ (FLAG_PSEUDO << SHIFT_DOUBLE));
		return (true);
	}
	return (false);
}

void	ScalarConverter::display(const std::string &str, int flag) {
	std::cout << YELLOW << "char: " << STOP << "impossible" << std::endl;

	if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MAX)
		std::cout << YELLOW << "int: " << STOP << std::numeric_limits<int>::max();
	else if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MIN)
		std::cout << YELLOW << "int: " << STOP << std::numeric_limits<int>::min();
	else
		std::cout << YELLOW << "int: " << STOP << "impossible";

	std::cout << YELLOW << "float: " << STOP << str << CHR_FLOAT << std::endl;
	std::cout << YELLOW << "double: " << STOP << str << std::endl;
}

template <typename T>
void	ScalarConverter::display(T scalar, int flag) {
	if (' ' <= static_cast<char>(scalar) && static_cast<char>(scalar) <= '~')
		std::cout << YELLOW << "char: " << STOP << static_cast<char>(scalar) << std::endl;
	else
		std::cout << YELLOW << "char: " << STOP << "Non displayable" << std::endl;

	if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MAX)
		std::cout << YELLOW << "int: " << STOP << std::numeric_limits<int>::max();
	else if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MIN)
		std::cout << YELLOW << "int: " << STOP << std::numeric_limits<int>::min();
	else
		std::cout << YELLOW << "int: " << STOP << static_cast<int>(scalar);
	std::cout << std::endl;

	const std::ios::fmtflags flags = std::cout.flags();

	if (static_cast<float>(scalar) == static_cast<int>(scalar))
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::setprecision(8);
	std::cout << YELLOW << "float: " << STOP << static_cast<float>(scalar) << CHR_FLOAT << std::endl;
	std::cout.flags(flags);

	if (static_cast<double>(scalar) == static_cast<int>(scalar))
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::setprecision(27);
	std::cout << YELLOW << "double: " << STOP << static_cast<double>(scalar) << std::endl;
	std::cout.flags(flags);
}
