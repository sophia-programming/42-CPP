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
	if (ss.fail())
		throw std::runtime_error("Error: invalid number format: " + str);
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

	std::map<std::string, float>::const_iterator it = this->dataBase.lower_bound(date);

	if (it != this->dataBase.end() && it->first == date) {
		// 日付が正確に存在する場合、その値を返す
		return it->second;
	} else if (it == this->dataBase.begin()) {
		// 日付がデータベースの最初の日付より前の場合、エラーとして扱う
		std::cerr << RED << "Error: date is before the database starts => " << "\"" << date << "\"" << STOP << std::endl;
		return -1.0;
	} else if (it == this->dataBase.end()) {
		// 日付がデータベースの最後の日付より後の場合、最新の値を返す
		--it;
		return it->second;
	} else {
		// それ以外の場合、最も近い小さい日付の値を返す
		--it;
		return it->second;
	}
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

	// 日付の長さと区切り文字をチェック
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		std::cerr << RED << "Error: date format should be YYYY-MM-DD => " << "\"" << date << "\"" << STOP << std::endl;
		return false;
	}


	while (std::getline(ss, s, '-'))
	{
		if (i == 0)
		{
			year = ft_stou(s);
			if (year < 2009)
			{
				std::cerr << RED << "Error: year is not at the database => " << "\"" << date << "\"" << STOP << std::endl;
				return false;
			}
			else if (year > 2023)
				return true;
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
				|| (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
				|| (month == 2 && day > 29)
				|| (month == 2 && day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))))
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
		std::cerr << RED << "Error: No data in the CSV file." << STOP << std::endl;
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
		std::cerr << RED << "Error: No data in the CSV file." << STOP << std::endl;
	}
	csvFile.close();
}
