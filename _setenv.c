#include "main.h"

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
	extern char *environ;
	char str[10240], *token, *saveptr, *dir, *n, *v;
	int i, j;

	if (name == NULL || value == NULL)
		return (-1);
	nm = _strdup(name);
	vl = _strdup(value);
	if (nm == NULL || vl == NULL)
		return (-1);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < 10240; j++)
			str[j] = '\0';
		for (j = 0; environ[i][j] != '\0'; j++)
			str[j] = environ[i][j];
		token = strtok_r(str, "=", &saveptr);
		if (_strcmp(token, nm) == 0)
		{
			if (overwrite == 0)
				break;
		}	
	}
	free(nm);
	free(vl);
	return (0);
}
