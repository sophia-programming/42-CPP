#include <iostream>
#include <string>

void sample1()
{
	char *const str = strdup("Hello");
	*str = 'X';
	std::cout << str << std::endl;
}

void changeString(const std::string &string)
{
//		string = "42Paris";
	std::cout << string << std::endl;
}

void sample2()
{
	std::string string = "42Tokyo";
	changeString(string);
	std::cout << string << std::endl;
}

int main()
{
//	sample1();
	sample2();
}
