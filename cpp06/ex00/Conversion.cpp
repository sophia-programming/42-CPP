#include "Conversion.hpp"

void convert(std::string &literal)
{
	uint64_t iVal_ = 0;
	float fVal_ = 0.0f;
	double dVal_ = 0.0;
	char cVal_ = 0;

	int (*p[6])(std::string &literal) = {&check, &isInt, &isDouble, &isFloat, &isChar, &others};
	for (int i = 0; i < 6; i++)
	{
		if (p[i](literal))
		{
			if (i == 1)
			{
				iVal_ = std::stod(literal);
				fVal_ = static_cast<float>(iVal_);
				dVal_ = static_cast<double>(iVal_);
				cVal_ = static_cast<char>(iVal_);
			}
			else if (i == 2)
			{
				dVal_ = std::stod(literal);
				fVal_ = static_cast<float>(dVal_);
				iVal_ = static_cast<int>(dVal_);
				cVal_ = static_cast<char>(dVal_);
			}
			else if (i == 3)
			{
				fVal_ = std::stof(literal);
				dVal_ = static_cast<double>(fVal_);
				iVal_ = static_cast<int>(fVal_);
			}
			else if (i == 4)
			{
				cVal_ = literal[0];
				iVal_ = static_cast<int>(cVal_);
				fVal_ = static_cast<int>(cVal_);
				dVal_ = static_cast<int>(cVal_);
			}
			break;
		}
	}
	std::cout << "char: ";
	if ((cVal_ >= 32 && cVal_ <= 47) || (cVal_ >= 58 && cVal_ <= 126))
		std::cout << "`" << cVal_ << "`" << std::endl;
	else if (cVal_ < 32 || cVal_ > 126 || (cVal_ >= 48 && cVal_ <= 57))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: ";
	if (iVal_ >= INT_MIN && iVal_ <= INT_MAX)
		std::cout << iVal_ << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: ";
	if (fVal_ >= -FLT_MIN && fVal_ <= FLT_MAX)
	{
		if (iVal_ == fVal_)
			std::cout << fVal_ << ".0f" << std::endl;
		else
			std::cout << fVal_ << "f" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

	std::cout << "double: ";
	if (dVal_ >= -DBL_MIN && dVal_ <= DBL_MAX)
	{
		if (dVal_ == fVal_)
			std::cout << dVal_ << ".0" << std::endl;
		else
			std::cout << dVal_ << std::endl;
	}
	else
		std::cout << "impssible" << std::endl;
}

int isInt(std::string &literal)
{
	int i = 0;
	int dot = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	while (literal[i])
	{
		if ((literal[i] == 'e' || literal[i] == 'E') && !isdigit(literal[i]))
		{
			dot++;
			i++;
			if (literal[i] == '+')
				i++;
		}
		else if (!isdigit(literal[i]) || literal[i] == '-')
			return 0;
		else
			i++;
	}
	if (dot > 1)
		return 0;
	return 1;
}

int isDouble(std::string &literal)
{
	int i = 0;
	int dot = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	while (literal[i])
	{
		if (literal[i] == '.')
			dot++;
		else if (!isdigit(literal[i]))
			return 0;
		i++;
	}
	if (dot > 1)
		return 0;
	return 1;
}

int isFloat(std::string &literal)
{
	int i = 0;
	int dot = 0;
	int dot2 = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	while (literal[i])
	{
		if (literal[i] == 'e' || literal[i] == 'E')
		{
			dot2++;
			i++;
			if (literal[i] == '-')
				i++;
		}
		if (literal[i] == '.')
		{
			dot++;
			i++;
		}
		if ((literal[i] == 'f' || literal[i] == 'F') && (size_t)(i + 1) == literal.size())
		{
			i++;
			continue;
		}
		if (!isdigit(literal[i]))
			return 0;
	}
	if (dot > 1 || dot2 > 1)
		return 0;
	return 1;
}

int isChar(std::string &literal)
{
	if (literal.length() == 1 && isprint(literal[0]))
		return 1;
	return 0;
}

int check(std::string &literal)
{
	if (literal == "inf" || literal == "inff" || literal == "infl")
	{
		std::cout << RED << "char: impossible" << STOP << std::endl;
		std::cout << RED << "int: impossible" << STOP << std::endl;
		std::cout << "float: " << "inff" << std::endl;
		std::cout << "double: " << "inf" << std::endl;
		exit(0);
	}
	else if (literal == "-inf" || literal == "-inff" || literal == "-infl")
	{
		std::cout << RED << "char : impossible" << STOP << std::endl;
		std::cout << RED << "int : impossible" << STOP << std::endl;
		std::cout << "float : " << "-inff" << std::endl;
		std::cout << "double : " << "-inf" << std::endl;
		exit(0);
	}
	return 0;
}

int others(std::string &literal)
{
	(void)literal;
	std::cout << "char: infinity" << std::endl;
	std::cout << "int: infinity" << std::endl;
	std::cout << "float: infinity" << std::endl;
	std::cout << "double: infinity" << std::endl;
	exit(0);
}
