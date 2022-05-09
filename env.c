#include <stdio.h>

/**
 * main - test env
 *
 * Return: always 0
 */
int main(int ac, char **av, char**env)
{
	do {
		printf("%s\n", *env);
	} while (*++env);
	return (0);
}
