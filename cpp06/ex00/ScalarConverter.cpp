#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &str) {
	std::cout << "Copy constructor" << std::endl;
	*this = str;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &str) {
	std::cout << "Assignation operator" << std::endl;
	if (this != &str)
		*this = str;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor" << std::endl;
}

void ScalarConverter::convert(const std::string &str) {
	if (str.empty()){
		std::cerr << RED << "Empty string" << std::endl;
		return;
	}

	if (convertInt(str) || convertChar(str) || convertDouble(str)
		|| convertFloat(str) || convertPseudo(str)) {
		return;
	}
	//どの変換も成功しなかった場合
	std::cout << RED << "Invalid input: " << str << STOP << std::endl;
}

bool ScalarConverter::convertInt(const std::string &str) {
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
		std::clog << "\033[35;2;3mfloat pseudo\033[m" << std::endl;
		return (true);
	}

	std::stringstream	ss;
	float	f;

	ss << str_trim;
	ss >> f;
	if (!ss.fail() && ss.eof()) {
		int	flag;
		(void) flag;
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

bool	ScalarConverter::convertPseudo(const std::string &str) {
	if (str == "inf" || str == "+inf") {
		display(str, \
			(FLAG_MAX << SHIFT_CHAR) \
			+ (FLAG_MAX << SHIFT_INT) \
			+ (FLAG_MAX << SHIFT_FLOAT) \
			+ (FLAG_MAX << SHIFT_DOUBLE));
		return (true);
	}
	if (str == "-inf") {
		display(str, \
			(FLAG_MIN << SHIFT_CHAR) \
			+ (FLAG_MIN << SHIFT_INT) \
			+ (FLAG_MIN << SHIFT_FLOAT) \
			+ (FLAG_MIN << SHIFT_DOUBLE));
		return (true);
	}
	if (str == "nan") {
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
	std::cout << "\033[32mT: \"" << str \
		<< "\" (" << std::hex << flag << std::dec << ")\033[m" << std::endl;

	std::cout << "\033[31mchar: " << "impossible" << "\033[m" << std::endl;

	if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MAX)
		std::cout << "\033[33mint: " << std::numeric_limits<int>::max();
	else if (((flag >> SHIFT_INT) & MASK_FLAG) == FLAG_MIN)
		std::cout << "\033[33mint: " << std::numeric_limits<int>::min();
	else
		std::cout << "\033[31mint: " << "impossible" << std::endl;

	std::cout << "\033[33mfloat: " << str << "f" << "\033[m" << std::endl;
	std::cout << "\033[33mdouble: " << str << "\033[m" << std::endl;
}

template <typename T>
void	ScalarConverter::display(T scalar, int flag) {
	std::cout << "\033[32mT: " << scalar \
		<< " (" << std::hex << flag << std::dec << ")\033[m" << std::endl;

	if (' ' <= static_cast<char>(scalar) && static_cast<char>(scalar) <= '~')
		std::cout << "\033[32mchar: " << static_cast<char>(scalar) << "\033[m" << std::endl;
	else
		std::cout << "\033[33mchar: " << "Non displayable" << std::endl;

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
		<< "f" << "\033[m" << std::endl;
	std::cout.flags(flags);

	if (static_cast<double>(scalar) == static_cast<int>(scalar))
		std::cout << std::fixed << std::setprecision(1);
	else
		std::cout << std::setprecision(27);
	std::cout << "\033[32mdouble: " << static_cast<double>(scalar) \
		<< "\033[m" << std::endl;
	std::cout.flags(flags);
}
