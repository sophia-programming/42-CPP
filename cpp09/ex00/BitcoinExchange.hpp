#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

class BitcoinExchange {
public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &to_copy);
	BitcoinExchange& operator=(const BitcoinExchange &to_copy);
	~BitcoinExchange(void);

	void  loadPricesFromCSV(std::ifstream &csvFile);
	float findClosestPrice(const std::string &date);

	bool  validateDateFormat(const std::string &date);
	bool  isValidDate(const std::string &date);
	bool  validatePriceFormat(const std::string &priceStr);

private:
	std::map<std::string, float> dataBase;
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
