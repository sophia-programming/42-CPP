#include "Harl.hpp"

void Harl::complain(std::string level)
{
	void (Harl::*f[5])() = {
			&Harl::invalidArg,
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
	};
	const size_t index =
			(level == "DEBUG") * DEBUG
			+ (level == "INFO") * INFO
			+ (level == "WARNING") * WARNING
			+ (level == "ERROR") * ERROR;
	(this->*f[index])();
}

/*
 * messages from PDF
 */
void Harl::debug()
{
	std::cout
	<< GreenColor
	<< "[DEBUG]"
	<< std::endl
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< StopColor
	<< std::endl;
}

void Harl::info()
{
	std::cout
	<< BlueColor
	<< "[INFO]"
	<< std::endl
	<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< StopColor
	<< std::endl;
}

void Harl::warning()
{
	std::cout
	<< YellowColor
	<< "[WARNING]"
	<< std::endl
	<< "I think I deserve to have some extra bacon for free. I’ve been coming for\n"
	   "years whereas you started working here since last month."
	<< StopColor
	<< std::endl;
}

void Harl::error()
{
	std::cout
			<< CyanColor
			<< "[ERROR]"
			<< std::endl
			<< "This is unacceptable! I want to speak to the manager now."
			<< StopColor
			<< std::endl;
}

void Harl::invalidArg()
{
	std::cout
			<< RedColor
			<< "[INVALID]"
			<< std::endl
			<< "You should choose one of the following options."
			<< std::endl
			<< "[DEBUG]/"
			<< "[INFO]/"
			<< "[WARNING]/"
			<< "[ERROR]"
			<< StopColor
			<< std::endl;
}

Harl::Harl() {}

Harl::~Harl() {}

