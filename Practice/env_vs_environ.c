#include <stdio.h>

/**
 * main - test env vs environ
 *
 * Return: always 0
 */
int main(int ac, char **av, char **env)
{
	extern char **environ;
	printf("address of env: %p\n", &env);
	printf("add of environ: %p\n", &environ);
	return (0);
}
