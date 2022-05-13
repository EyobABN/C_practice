#include "main.h"
#include <stdio.h>

/**
 * _unsetenv - delets an environment variable
 * @name: the name of the environment variable
 *
 * Return: 0 upon success, -1 upon failure
 */
int _unsetenv(const char *name)
{
	char str[10240], *token;
	int i, j, found = 0, env_count = 0, d_index;
	char **env_copy;

	if (name == NULL)
		return (-1);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < 10240; j++)
			str[j] = '\0';
		for (j = 0; environ[i][j] != '\0'; j++)
			str[j] = environ[i][j];
		token = strtok(str, "=");
		if (_strcmp(token, name) == 0)
		{
			found = 1;
			d_index = i;
			break;
		}
	}
	if (found == 1)
	{
		for (i = 0; environ[i] != NULL; i++)
			env_count++;
		env_copy = malloc(sizeof(char *) * env_count);
		if (env_copy == NULL)
			return (-1);
		for (i = 0, j = 0; environ[i] != NULL; i++)
		{
			if (i == d_index)
				continue;
			env_copy[j++] = environ[i];
		}
		env_copy[j] = NULL;
		environ = env_copy; /* needs to be free'd */
	}
	return (0);
}

/**
 * main - test code
 *
 * Return: 0 upon success, 1 upon failure
 */
int main(void)
{
	char *name;
	int check, i;

	name = "PATH";
	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	check = _unsetenv(name);
	if (check == 0)
	{
		i = 0;
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}
		free(environ);
		return (0);
	}
	return (1);
}
