#include <iostream>

#define N 42

int main(void)
{
	if (0 <= N <= 1)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;
	return 0;
}
