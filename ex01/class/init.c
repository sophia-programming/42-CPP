#include <stdio.h>
int main(void)
{
	int c[100] = {0};
	for (int i = 0; i < 100; i++)
		printf("%i:%d\n", i, c[i]);
	
	const int d[100] = {1};
	for (int i = 0; i < 100; i++)
		printf("%i:%d\n", i, d[i]);

	/* int e[5] = {}; */
	int e[5];
	for (int i = 0; i < 5; i++)
		printf("%i:%d\n", i, e[i]);
	return 0;
}
