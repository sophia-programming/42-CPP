#include <iostream>

int main()
{
	std::string string = "Hello";
	string += string;
	std::cout << string << std::endl;
	string += 42;//this is not meaning
	std::cout << string << std::endl;
}
