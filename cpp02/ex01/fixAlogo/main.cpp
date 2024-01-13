#include <iostream>
#include <cmath>

const int fbits_ = 8;

int floatToFix(const float f)
{
	return (static_cast<int>(f / (1 << fbits_)));
}

int floatToFix2(const float f)
{
	return (static_cast<int>(roundf(f / (1 << fbits_))));
}

int main()
{
	const float f = 12.345;
	std::cout << roundf(f) << std::endl;
	std::cout << (int)f << std::endl;
//	int rawbits = floatToFix2(f);

	std::cout << floatToFix2(f) << std::endl;
}
