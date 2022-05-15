#include "main.h"
#include <string.h>

/**
 * main - prints each directory in PATH
 * one directory per line
 *
 * Return; 0 upon success, 1 upon failure
 */
int main()
{
	extern char **environ;
	char str[10240], *token, *saveptr, *dir;
	int i, j;
	path_t *head = NULL, *p;


	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < 10240; j++)
			str[j] = '\0';
		for (j = 0; environ[i][j] != '\0'; j++)
			str[j] = environ[i][j];
		token = strtok_r(str, "=", &saveptr);
		if (_strcmp(token, "PATH") == 0)
			while ((dir = strtok_r(NULL, ":", &saveptr)))
				add_node_end(&head, dir);
	}
	for (p = head; p != NULL; p = p->next)
	{
		_puts(p->dir);
		_putchar('\n');
	}
	free_list(head);
	return (0);
}
