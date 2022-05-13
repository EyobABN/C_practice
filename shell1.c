#include "main.h"
#include <stdio.h>
#include <sys/wait.h>

/**
 * main - a super simple shell
 *
 * Return: 0 upon success, 1 upon failure
 */
int main(void)
{
	char **argv;
	size_t n;
	ssize_t nread;
	int status;
	pid_t child_pid;
	char *line;

	while (1)
	{
		printf("#cisfun$ ");
		line = NULL;
		n = 0;
		nread = getline(&line, &n, stdin);
		if (nread == -1)
			continue;
		/* Check if command exists */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{

			if (line[nread - 1] == '\n')
				line[nread - 1] = '\0';
			argv = makeCmd(line);
			if (_strcmp(argv[0], "exit") == 0)
			{
				free(line);
				exit(97);
			}
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
			free(line);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				if (WEXITSTATUS(status) == 97)
					break;
		}
	}
	return (0);
}
