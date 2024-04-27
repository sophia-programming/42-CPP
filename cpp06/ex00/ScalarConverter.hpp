#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <limits>

enum BitShift {
	ShiftChar = 12,
	ShiftInt = 8,
	ShiftFloat = 4,
	ShiftDouble = 0
};

enum Flags {
	FlagRegular = 0x0,
	FlagCast = 0x1,
	FlagNoDisplay = 0x2,
	FlagInteger = 0x2,
	FlagMin = 0x2,
	FlagMax = 0x4,
	FlagPseudo = 0x8,
	FlagImpossible = 0x8
};

enum Masks {
	MaskFlags = 0xf,
	MaskChar = 0xff
};

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
