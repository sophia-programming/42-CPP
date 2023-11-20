#include <iostream>
#include <string>

void replace(std::string s1, std::string s2)
{
	size_t pos = 0;
	size_t s1len = s1.length();
	pos = s2.find(s1, pos);
	if (pos == std::string::npos) {
		std::cerr << "s1 was not found in s2" << std::endl;
		exit(EXIT_FAILURE);
	} else {
		s2.erase(pos, s1len);
		s2.insert(pos, s2);
	}
	std::cout << s2 << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 3) {
		std::string s1(argv[1]);
		std::string s2(argv[2]);
		replace(s1, s2);
	}
	else {
		std::cerr << "Invalid argument count" << std::endl;
		return (EXIT_FAILURE);
	}
}