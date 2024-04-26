#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <limits>

# define SHIFT_CHAR		12
# define SHIFT_INT		8
# define SHIFT_FLOAT	4
# define SHIFT_DOUBLE	0
# define FLAG_REGULAR	0x0
# define FLAG_CAST		0x1
# define FLAG_NODISP	0x2
# define FLAG_INTEGER	0x2
# define FLAG_MIN		0x2
# define FLAG_MAX		0x4
# define FLAG_PSEUDO	0x8
# define FLAG_IMPOS		0x8
# define MASK_FLAG		0xf
# define MASK_CHAR		0xff
# define CHR_FLOAT		'f'
# define STR_NAN		"nan"
# define STR_INF		"inf"
# define STR_INF_POS	"+inf"
# define STR_INF_NEG	"-inf"
# define STR_DECIMAL	".0"

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	static bool	convertInt(const std::string &str);
	static bool	convertChar(const std::string &str);
	static bool	convertDouble(const std::string &str);
	static bool	convertFloat(const std::string &str);
	static bool	convertPseudo(const std::string &str);

public:
	static bool	convert(std::string &str);
	static void	display(const std::string &str, int flag);
	template<typename T>
	static void	display(T scalar, int flag);
};

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
