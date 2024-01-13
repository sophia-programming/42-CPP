#include <iostream>
#include <cmath>

int main()
{
	const float fnbr = 12.34f;
	std::cout << fnbr << std::endl;

//	int rawBits = static_cast<int>(std::roundf(fnbr));
	int rawBits = static_cast<int>(fnbr);
	std::cout << rawBits << std::endl;

	std::cout << "roundf(5)::" << roundf(5.0f) << std::endl;
	std::cout << "roundf(4.8)::" << roundf(4.8f) << std::endl;
	std::cout << "roundf(4.5)::" << roundf(4.5f) << std::endl;
	std::cout << "roundf(4.3)::" << roundf(4.3f) << std::endl;
	std::cout << "roundf(4.0)::" << roundf(4.0f) << std::endl;


}
