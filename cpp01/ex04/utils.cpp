#include "replace.hpp"

void printUsage()
{
	std::cout
	<< RedColor << UnderlineColor
	<< "./replace [1] [2] [3]" << StopColor << std::endl
	<< RedColor << "[1] <filename>" << std::endl
	<< "[2] <string1>" << std::endl
	<< "[3] <string2>" << StopColor << std::endl;
}
