#include "main.h"
#include <stdio.h>

/**
 * cat - concatenates the name and value of
 * an environment variable
 * @new: the new concat'd string
 * @name: the name
 * @value: the value
 *
 * Return: void
 */
void cat(char **new, const char **name, const char **value)
{
	int j, k;

	*new = malloc(sizeof(char) * (_strlen(*name) + _strlen(*value) + 2));
	if (new == NULL)
		return;
	for (j = 0; (*name)[j] != '\0'; j++)
		(*new)[j] = (*name)[j];
	(*new)[j++] = '=';
	for (k = 0; (*value)[k] != '\0'; k++)
		(*new)[j++] = (*value)[k];
	(*new)[j] = '\0';
}

/**
 * _setenv - changes or adds an environment variable
 * @name: the name of the environment variable
 * @value: the value of the environment variable
 * @overwrite: overwrite option specifier
 *
 * Return: 0 upon success, -1 upon failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char str[10240], *token, *new;
	int i, j, found = 0, env_count = 0;
	char **env_copy;

	if (name == NULL || value == NULL)
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
			if (overwrite == 0)
				break;
			cat(&new, &name, &value);
			environ[i] = new; /* needs to be free'd */
			break;
		}
	}
	if (found == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			env_count++;
		env_copy = malloc(sizeof(char *) * (env_count + 2));
		if (env_copy == NULL)
			return (-1);
		for (i = 0; environ[i] != NULL; i++)
			env_copy[i] = environ[i];
		cat(&new, &name, &value);
		env_copy[i++] = new; /* needs to be free'd */
		env_copy[i] = NULL;
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
	char *name, *value;
	int check, i;

	name = "YEE";
	value = "HAW!";
	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	check = _setenv(name, value, 1);
	if (check == 0)
	{
		i = 0;
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}
		return (0);
	}
	return (1);
}
