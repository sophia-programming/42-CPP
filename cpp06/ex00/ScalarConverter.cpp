#include "ScalarConverter.hpp"

int	ScalarConverter::convert(std::string& str) {
	if (str.empty() || str.length() == 0) {
		std::cerr << "\033[31mEmpty string" << std::endl;
		return (1);
	}

	if (forInt(str))
		return (0);

	if (forChar(str))
		return (0);

	if (forDouble(str))
		return (0);

	if (forFloat(str))
		return (0);

	std::cerr << RED << "Invalid input: " << str << STOP << std::endl;
	return (1);
}

bool	ScalarConverter::forInt(const std::string& str) {
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
		std::clog << "\033[35;2;3mint\033[m" << std::endl;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::forChar(const std::string& str) {
	if (str.length() == 1) {
		char	c = str[0];
		display(c, \
			(FLAG_REGULAR << SHIFT_CHAR) \
			+ (FLAG_CAST << SHIFT_INT) \
			+ (FLAG_CAST << SHIFT_FLOAT) \
			+ (FLAG_CAST << SHIFT_DOUBLE));
		std::clog << "\033[35;2;3mchar\033[m" << std::endl;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::forDouble(const std::string& str) {
	if (forPseudo(str)) {
		std::clog << "\033[35;2;3mdouble pseudo\033[m" << std::endl;
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
		std::clog << "\033[35;2;3mdouble\033[m" << std::endl;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::forFloat(const std::string& str) {
	if (str[str.length() - 1] != 'f')
		return (false);
	std::string	str_trim(str);
	str_trim.erase(str_trim.length() - 1);

	if (forPseudo(str_trim)) {
		std::clog << "\033[35;2;3mfloat pseudo\033[m" << std::endl;
		return (true);
	}

	std::stringstream	ss;
	float	f;

	ss << str_trim;
	ss >> f;
	if (!ss.fail() && ss.eof()) {
		int	flag;
		(void)flag; // to avoid warning (unused variable
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
		std::clog << "\033[35;2;3mfloat\033[m" << std::endl;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::forPseudo(const std::string& str) {
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

void	ScalarConverter::display(const std::string& str, int flag) {
	std::cout << "\033[32mT: \"" << str \
		<< "\" (" << std::hex << flag << std::dec << ")\033[m" << std::endl;

	std::cout << "\033[31mchar: " << STR_IMPOS << "\033[m" << std::endl;

	if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MAX)
		std::cout << "\033[33mint: " << std::numeric_limits<int>::max();
	else if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MIN)
		std::cout << "\033[33mint: " << std::numeric_limits<int>::min();
	else
		std::cout << "\033[31mint: " << STR_IMPOS;
	std::cout << "\033[m" << std::endl;

	std::cout << "\033[33mfloat: " << str << CHR_FLOAT << "\033[m" << std::endl;
	std::cout << "\033[33mdouble: " << str << "\033[m" << std::endl;
}

template <typename T>
void	ScalarConverter::display(T scalar, int flag) {
	std::cout << "\033[32mT: " << scalar \
		<< " (" << std::hex << flag << std::dec << ")\033[m" << std::endl;

	if (' ' <= static_cast<char>(scalar) && static_cast<char>(scalar) <= '~')
		std::cout << "\033[32mchar: " << static_cast<char>(scalar) << "\033[m" << std::endl;
	else
		std::cout << "\033[33mchar: " << STR_NODISP << "\033[m" << std::endl;

	if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MAX)
		std::cout << "\033[33mint: " << std::numeric_limits<int>::max();
	else if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MIN)
		std::cout << "\033[33mint: " << std::numeric_limits<int>::min();
	else
		std::cout << "\033[32mint: " << static_cast<int>(scalar);
	std::cout << "\033[m" << std::endl;

	const std::ios::fmtflags flags = std::cout.flags();

	if (static_cast<float>(scalar) == static_cast<int>(scalar))
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::setprecision(8);
	std::cout << "\033[32mfloat: " << static_cast<float>(scalar) \
		<< CHR_FLOAT << "\033[m" << std::endl;
	std::cout.flags(flags);

	if (static_cast<double>(scalar) == static_cast<int>(scalar))
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::setprecision(27);
	std::cout << "\033[32mdouble: " << static_cast<double>(scalar) \
		<< "\033[m" << std::endl;
	std::cout.flags(flags);
}
