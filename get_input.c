#include "main.h"

/**
 * get_input - gets input and turns it into cmds
 *
 * Return: a char pointer of the commands
 */
char **get_input(void)
{
	char *line, **cmds;
	size_t n;
	ssize_t nread;

	_puts("#cisfun$ ");
	line = NULL;
	n = 0;
	nread = getline(&line, &n, stdin);
	if (nread == -1)
		exit(0);	/* EOF (Ctrl+D) captured */
	line[nread - 1] = '\0';
	cmds = makeCmds(line);
	if (cmds == NULL)
	{
		perror("Error: failed to create commands");
		free(line);
		get_input();
	}
	free(line);
	return (cmds);
}
