#include "BitcoinExchange.hpp"

float ft_stof(const std::string& str);

static int panic(std::string error_msg)
{
	std::cerr << RED << error_msg << STOP << std::endl;
	return EXIT_FAILURE;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return panic("Error: could not open file");

	std::ifstream input_db(argv[1], std::ifstream::in);
	if (!input_db.is_open())
		return panic("Error: could not open file");

	std::ifstream csvFile("./data.csv", std::ifstream::in);
	if (!csvFile.is_open())
		return panic("Error: fatal: could not open internal database file");

	BitcoinExchange btc;
	btc.loadPricesFromCSV(csvFile);

	std::string line;

	// skip first line
	std::getline(input_db, line);
	while (std::getline(input_db, line))
	{
		size_t delim = line.find('|');
		if (delim == std::string::npos
			||	line.length() < delim + 2)
		{
			std::cerr << RED << "Error: bad input => " << "\"" << line << "\"" << STOP << std::endl;
			continue ;
		}

		std::string date = line.substr(0, delim - 1);
		if (!btc.validateDateFormat(date) || !btc.isValidDate(date))
			continue;

		std::string priceStr_as_str = line.substr(delim + 2);
		if (!btc.validatePriceFormat(priceStr_as_str))
			continue;
		float priceStr = ft_stof(priceStr_as_str);

		std::cout << date << " => " << priceStr << " = " << std::setprecision(2) << priceStr * btc.findClosestPrice(date) << std::endl;
	}
	input_db.close();
	csvFile.close();
	return EXIT_SUCCESS;
}
