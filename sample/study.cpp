#include <iostream>
#include <string>
#include <cctype>
#include <locale>

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		std::cout << "invalid argument count." << std::endl;
	else {
		//*stringの変換であれば以下のようにする
		std::string str("hello world");
		std::transform(str.begin(), str.end(), str.begin(), toupper);
		std::cout << "after transform(~, toupper)" << std::endl;
		std::cout << str << std::endl;
		std::cout << "after transform(~, tolower)" << std::endl;
		std::transform(str.begin(), str.end(), str.begin(), tolower);
		std::cout << str << std::endl;
		//*char arrayの変換
		char *p = argv[1];
		while (*p) {
			*p = toupper(*p);
			p++;
		}
		std::cout << argv[1] << std::endl;

		size_t i = 0;
		while (argv[1][i]) {
			argv[1][i] = std::tolower(argv[1][i]);
			i++;
		}
		std::cout << argv[1] << std::endl;
	}
	return 0;
}
