#include "ScalarConverter.hpp"

static bool	isSpecial(const std::string &str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return true;
	return false;
}

static bool	isChar(const std::string &str, size_t &len)
{
	if (len == 1 && !isdigit(str[0]))
		return true;
	if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

static bool	isInt(const std::string &str, size_t &len)
{
	int		i = 0;
	bool	flag = false;

	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		flag = 1;
	}
	while ((str[i] && 0 < len && len < 12) || (str[i] && !flag && 0 < len && len < 11))
	{
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

static bool	isFloat(const std::string &str, size_t &len, size_t &dot)
{
	for (int j = dot - 1; j >= 0; j--)
	{
		if (!isdigit(str[j]) && j != 0)
			return false;
		if (!isdigit(str[j]) && j == 0 && str[j] != '+' && str[j] != '-')
			return false;
	}
	for (size_t i = dot + 1; i < len; i++)
	{
		if (!isdigit(str[i]) && str[i] != 'f')
			return false;
		if (str[i] == 'f' && i != len - 1)
			return false;
	}
	return true;
}

e_type  getType(const std::string &str, size_t &len)
{
	size_t  dot = str.find('.');
	size_t  f = str.find('f');
	size_t dotCount = 0;
	size_t pos = str.find('.');

	// ドットを探してカウントする
	while (pos != std::string::npos) {
		dotCount++;
		pos = str.find('.', pos + 1);
	}

	if (dotCount >= 2) {
		return INVALID;
	}

	if (dot != std::string::npos){
		if (dot == str.length() - 1)
			return INVALID;
	}

	if (dot == std::string::npos)
	{
		if (isSpecial(str))
			return SPECIAL;
		if (isChar(str, len))
			return CHAR;
		if (isInt(str, len))
			return INT;
	}

	if (f != std::string::npos && dot != std::string::npos)
	{
		if (isFloat(str, len, dot))
			return FLOAT;
	}
	else if (f == std::string::npos && dot != std::string::npos)
		return DOUBLE;
	return INVALID;
}
