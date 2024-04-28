#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <limits>

enum BitShift {
	ShiftChar = 12,       // 文字のビット位置: 12ビット右シフト
	ShiftInt = 8,         // 整数値のビット位置: 8ビット右シフト
	ShiftFloat = 4,       // フロート値のビット位置: 4ビット右シフト
	ShiftDouble = 0       // ダブル値のビット位置: 最下位（基準点）
};

enum Flags {
	FlagRegular = 0x0,    // 何もフラグを立てない状態: 0000
	FlagCast = 0x1,       // 型変換が行われた: 0001
	FlagNoDisplay = 0x2,  // 表示不可能な値: 0010
	FlagInteger = 0x4,    // 整数値: 0100
	FlagMin = 0x8,        // 最小値を示す: 1000
	FlagMax = 0x10,       // 最大値を示す: 0001 0000
	FlagPseudo = 0x20,    // 擬似値(例えば無限大など): 0010 0000
	FlagImpossible = 0x40 // 不可能な値、またはエラー: 0100 0000
};

enum Masks {
	MaskFlags = 0xf       // フラグを取り出すためのマスク: 1111
};

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
	~ScalarConverter();
	static bool	convert(std::string str);
	static void	display(const std::string &str, int flag);
	template<typename T>
	static void	display(T scalar, int flag);

private:
	static bool	convertInt(const std::string &str);
	static bool	convertChar(const std::string &str);
	static bool	convertDouble(const std::string &str);
	static bool	convertFloat(const std::string &str);
	static bool	convertPseudo(const std::string &str);
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
