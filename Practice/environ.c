#include <stdio.h>

/**
 * main - test environ global variable
 *
 * Return: always 0
 */
int main(void)
{
	int i;
	extern char **environ;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
	return (0);
}
