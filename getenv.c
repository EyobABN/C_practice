#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * strcmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 0 if the strings are the same,
 * another integer if they are not equal
 */
int _strcmp(const char *s1, const char *s2)
{
	char c1, c2;
	int i = 0;

	do {
		c1 = (char) s1[i];
		c2 = (char) s2[i++];
		if (c1 == '\0')
			break;
	} while (c1 == c2);
	return (c1 - c2);
}
/**
 * getenv - gets an environment variable
 * @name: name of environment variable
 *
 * Return: a pointer to the environment variable
 */
char *_getenv(const char *name)
{
	extern char **environ;
	const char *delim = "=";
	char *envv = NULL;
	char *token, *saveptr;
	int i;

	if (name == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok_r(environ[i], delim, &saveptr);
		if (_strcmp(token, name) == 0)
		{
			envv = strtok_r(NULL, delim, &saveptr);
			break;
		}
	}
	return (envv);
}

/**
 * main - tests getenv
 *
 * Return: always 0
 */
int main(int ac, char **av)
{
	char *envv;
	int i;

	if (ac < 2)
	{
		printf("Usage: %s environment_variable ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		envv = _getenv(av[i]);
		printf("%s=%s\n", av[i], envv);
		i++;
	}
	return (0);
}
