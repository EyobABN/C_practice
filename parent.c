#include "main.h"

/**
 * parent - executes the parent's commands
 * @status: the status int for wait function
 * @cmds: the array to be free'd before exiting
 *
 * Return: void
 */
void parent(int *status, char **cmds)
{
	int exit_status;

	wait(status);
	if (WIFEXITED(*status))
	{
		exit_status = WEXITSTATUS(*status);
		if (exit_status)
		{
			free_entire_arr(cmds);
			exit(exit_status);
		}
	}
}
