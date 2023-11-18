#include <iostream>

int main()
{
	int x = 1;
	std::cout << x << std::endl;
	int &ref = x;
	ref = 100;
	std::cout << x << std::endl;
	std::cout << ref << std::endl;

	std::cout << "\n----------------\n" << std::endl;

	std::string s = "Hello";
	std::string &str = s;
	std::cout << s << std::endl;
	str = "world";
	std::cout << s << std::endl;
	return 0;
}
