#include "main.h"

/**
 * exec - executes a command
 * @cmds: the commands vector
 * @i: the index where the command to
 * be executed resides
 *
 * Return: void
 */
void exec(char **cmds, int i)
{
	char **argv;

	argv = mkargv(cmds[i]);
	if (argv == NULL)
		return;
	if (isOpr(argv[0]))
	{
		free_entire_arr(argv);
		return;
	}
	if (_strcmp(argv[0], "exit") == 0)
	{
		free_entire_arr(argv);
		free_entire_arr(cmds);
		exit (97);
	}
	if (execve(argv[0], argv, NULL) == -1)
		perror("Error:");
	free_entire_arr(cmds);
	free_entire_arr(argv);
}
