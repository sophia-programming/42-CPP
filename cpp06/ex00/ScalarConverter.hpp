#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <exception>
# include <cstdlib>
# include <limits>
# include <cmath>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::lowest() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::lowest() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308
# define MIN_LONG std::numeric_limits<long>::min() //-9223372036854775808
# define MAX_LONG std::numeric_limits<long>::max() //9223372036854775807

enum    e_type
{
	SPECIAL = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	INVALID = -1
};

class	ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &src);
	~ScalarConverter(void);
	ScalarConverter	&operator=(ScalarConverter const &rhs);
public:
	static void	convert(const std::string &str);
};

e_type	getType(const std::string &str, size_t &len);
void	printSpecial(const std::string &str);
void	convertChar(const std::string &str, size_t &len);
void	convertInt(const std::string &str);
void	convertFloat(const std::string &str);
void	convertDouble(const std::string &str);

/* colors */
const char *const STOP = "\033[0m";
const char *const BOLD = "\033[1m";
const char *const BLACK = "\033[30m";
const char *const RED = "\033[31m";
const char *const GREEN = "\033[32m";
const char *const YELLOW = "\033[33m";
const char *const BLUE = "\033[34m";
const char *const MAGENTA = "\033[35m";
const char *const CYAN = "\033[36m";
const char *const WHITE = "\033[37m";
const char *const UNDERLINE =" \033[4m";

#endif
