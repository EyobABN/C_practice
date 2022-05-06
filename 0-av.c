#include <stdio.h>

int main(int ac, const char *av[])
{
	do {
		printf("%s\n", *av);
	} while (*++av);
	return (0);
}
