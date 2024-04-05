#include "BitcoinExchange.hpp"

static unsigned int ft_stou(const std::string& str)
{
	unsigned int num;
	std::stringstream ss(str);

	ss >> num;
	return num;
}

float ft_stof(const std::string& str)
{
	float num;
	std::stringstream ss(str);

	ss >> num;
	return num;
}

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& to_copy) {
	*this = to_copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& to_copy) {
	this->dataBase = to_copy.dataBase;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

float BitcoinExchange::getRateFromDataBase(const std::string& date)
{
	if (this->dataBase.count(date) > 0)
		return this->dataBase.at(date);
	return (--this->dataBase.lower_bound(date))->second;
}

bool BitcoinExchange::isDateInCorrectFormat(const std::string &date)
{
	if (date.empty())
		return false;

	size_t first_hyphen = date.find('-');
	size_t second_hyphen = date.find('-', first_hyphen + 1);

	if (first_hyphen == std::string::npos || second_hyphen == std::string::npos
		||  date.find_first_not_of("0123456789.-") != std::string::npos)
	{
		std::cerr << RED << "Error: bad input => " << "\"" << date << "\"" << STOP << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	std::string s;
	int year, month, day;
	std::istringstream ss(date);
	int i = 0;

	while (std::getline(ss, s, '-'))
	{
		if (i == 0)
		{
			year = ft_stou(s);
			if (year < 2009 || year > 2022)
			{
				std::cerr << RED << "Error: year is not at the database => " << "\"" << date << "\"" << STOP << std::endl;
				return false;
			}
		}
		if (i == 1)
		{
			month = ft_stou(s);
			if (month < 1 || month > 12)
			{
				std::cerr << RED << "Error: incorrect month => " << "\"" << date << "\"" << STOP << std::endl;
				return false;
			}
		}
		if (i == 2)
		{
			day = ft_stou(s);
			if ((day < 1 || day > 31)
				||  (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
				||  (day > 28 && month == 2))
			{
				std::cerr << RED << "Error: incorrect day => " << "\"" << date << "\"" << STOP << std::endl;
				return false;
			}
		}
		i += 1;
	}
	if (i != 3)
	{
		std::cerr << RED << "Error: incorrect date => " << "\"" << date << "\"" << STOP << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isRateInCorrectFormat(const std::string& rate)
{
	if (rate.empty() || rate.find_first_not_of("0123456789.-") != std::string::npos
		||  rate.at(0) == '.' || rate.find('.', rate.length() - 1) != std::string::npos)
		std::cerr << RED << "Error: invalid rate => " << "\"" << rate << "\"" << STOP << std::endl;
	else if (rate.at(0) == '-')
		std::cerr << RED << "Error: not a positive number." << STOP << std::endl;
	else if (rate.length() > 10 || (rate.length() == 10 && rate > "2147483647"))
		std::cerr << RED << "Error: too large a number." << STOP << std::endl;
	else
		return true;
	return false;
}

void BitcoinExchange::readInternalDataBase(std::ifstream& internal_db)
{
	std::string line;
	size_t delim;

	// skip first line
	std::getline(internal_db, line);
	while (std::getline(internal_db, line))
	{
		delim = line.find(',');
		std::string rate = line.substr(delim + 1);
		// set a new pair on the map <date, rate>
		this->dataBase[line.substr(0, delim)] = ft_stof(rate);
	}
	internal_db.close();
}
