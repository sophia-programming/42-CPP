#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	for (int i = 0; argv[i]; i++) {
		char *p = argv[i];
		for (; *p; p++) {
			*p = toupper(*p);
		}
	}
	for (int i = 0; argv[i]; i++) {
		std::cout << argv[i] << std::endl;
	}
	(void)argc;
	return 0;
}