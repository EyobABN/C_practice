#include "main.h"

/**
 * check_path - check if a command exists
 * @cmd: the command
 * @builtins
 *
 * Return: a full path of the command, or NULL if not found
 */
char *check_path(char *cmd, char **builtins)
{
	path_t *head = NULL, *head_copy;
	char *temp;
	struct stat st;
	int b_found = 1;

	while (*builtins != NULL)
	{
		if (_strcmp(*builtins, command) == 0)
			return (command);
		builtins++;
	}
	if (stat(command, &st) == 0)
		return (command);
	if (head == NULL)
		
}
