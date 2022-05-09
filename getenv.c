#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

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
	int i, j;
	char str[10240];

	if (name == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < 10240; j++)
			str[j] = '\0';
		for (j = 0; environ[i][j] != '\0'; j++)
			str[j] = environ[i][j];
		token = strtok_r(str, delim, &saveptr);
		if (_strcmp(token, name) == 0)
		{
			envv = strtok_r(NULL, "", &saveptr);
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
