#include <iostream>
#include <sstream>

int main()
{
	std::stringstream ss;
	std::string name("Hello World");
//	size_t i = 0;
//	ss << i;

	std::cout << ss.str("") << std::endl;
//	std::cout << name << std::endl;
}