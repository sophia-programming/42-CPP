#include <iostream>
#include <cmath>

//data member
static const int fbits_ = 8;
int rawbits = 0;

int main()
{
	/* ===================int to int=============*/
	const int intValue = 25;
	//input
	rawbits = intValue << fbits_;
	std::cout << rawbits << std::endl;

	//output
	std::cout << (rawbits >> fbits_) << std::endl;

	/* ==================float to fix ==============*/
	const float floatValue = 42.4245;
	rawbits = static_cast<int>(roundf(floatValue * (1 << fbits_)));
	std::cout
	 << rawbits << std::endl;

	std::cout
	<< static_cast<float>(rawbits) / (1 << fbits_) << std::endl;
}
