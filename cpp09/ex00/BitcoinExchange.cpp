#include "BitcoinExchange.hpp"

static unsigned int ft_stou(const std::string &str)
{
	unsigned int num;
	std::stringstream ss(str);

	ss >> num;
	return num;
}

float ft_stof(const std::string &str)
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
	if (this != &to_copy)
		this->dataBase = to_copy.dataBase;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

float BitcoinExchange::findClosestPrice(const std::string &date)
{
	if (this->dataBase.empty()) {
		std::cerr << RED << "Error: Database is empty." << STOP << std::endl;
		return -1.0;
	}

	if (0 < this->dataBase.count(date))
		return this->dataBase.at(date);
	return (--this->dataBase.lower_bound(date))->second;
}

bool BitcoinExchange::validateDateFormat(const std::string &date)
{
	if (date.empty())
	{
		std::cerr << RED << "Error: empty date." << STOP << std::endl;
		return false;
	}
	size_t first_hyphen = date.find('-');
	size_t second_hyphen = date.find('-', first_hyphen + 1);

	if (first_hyphen == std::string::npos || second_hyphen == std::string::npos
		||  date.find_first_not_of("0123456789-") != std::string::npos)
	{
		std::cerr << RED << "Error: bad input => " << "\"" << date << "\"" << STOP << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	std::string s;
	std::istringstream ss(date);
	int year, month, day;
	int i = 0;

	while (std::getline(ss, s, '-'))
	{
		if (i == 0)
		{
			year = ft_stou(s);
			if (year < 2009 || 2022 < year)
			{
				std::cerr << RED << "Error: year is not at the database => " << "\"" << date << "\"" << STOP << std::endl;
				return false;
			}
		}
		if (i == 1)
		{
			month = ft_stou(s);
			if (month < 1 || 12 < month)
			{
				std::cerr << RED << "Error: incorrect month => " << "\"" << date << "\"" << STOP << std::endl;
				return false;
			}
		}
		if (i == 2)
		{
			day = ft_stou(s);
			if ((day < 1 || 31 < day)
				||  (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
				||  (28 < day && month == 2))
			{
				std::cerr << RED << "Error: incorrect day => " << "\"" << date << "\"" << STOP << std::endl;
				return false;
			}
		}
		i++;
	}
	if (i != 3)
	{
		std::cerr << RED << "Error: incorrect date => " << "\"" << date << "\"" << STOP << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::validatePriceFormat(const std::string &priceStr)
{
	if (priceStr.at(0) == '-')
	{
		std::cerr << RED << "Error: not a positive number." << STOP << std::endl;
		return false;
	}
	else if (priceStr.empty() || priceStr.find_first_not_of("0123456789.") != std::string::npos ||
		priceStr.at(0) == '.' || priceStr.find('.', priceStr.length() - 1) != std::string::npos)
	{
		std::cerr << RED << "Error: invalid priceStr => " << "\"" << priceStr << "\"" << STOP << std::endl;
		return false;
	}

	float price = ft_stof(priceStr);
	if (price < 0 || 1000 < price) // 範囲を0から1000に限定
	{
		std::cerr << RED << "Error: too large a number." << STOP << std::endl;
		return false;
	}

	return true;
}

void BitcoinExchange::loadPricesFromCSV(std::ifstream &csvFile)
{
	std::string line;
	size_t delim;

	if (!std::getline(csvFile, line)) {
		std::cerr << RED << "Error: CSV file is empty or cannot be read." << STOP << std::endl;
		std::exit(EXIT_FAILURE);
	}

	// データ行がない場合を確認
	bool hasData = false;
	while (std::getline(csvFile, line))
	{
		hasData = true;
		delim = line.find(',');
		if (delim == std::string::npos) {
			std::cerr << RED << "Error: Invalid format in database => " << line << STOP << std::endl;
			continue;
		}

		std::string date = line.substr(0, delim);
		std::string priceStr = line.substr(delim + 1);
		// set a new pair on the map <date, price>
		this->dataBase[date] = ft_stof(priceStr);
	}
	if (!hasData) {
		std::cerr << RED << "Error: CSV file contains no data entries." << STOP << std::endl;
	}
	csvFile.close();
}
