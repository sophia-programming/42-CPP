#include <stdio.h>

int main(void)
{
	char *str = "aoba";
	for (int i = 0; i[str]; i++)
		printf("%p", &i[str]);

	printf("\n");
	for (int i = 0; *(str + i); i++)
		printf("%p", str + i);

	printf("\n");
	for (int i = 0; str[i]; i++)
		printf("%p", &str[i]);
	return 0;
}