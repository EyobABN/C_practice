#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

void sigintHandler(int __attribute__((unused)) sig)
{
	exit(97);
}
/**
 * main - a super simple shell
 *
 * Return: 0 upon success, 1 upon failure
 */
int main(void)
{
	char *argv[2];
	size_t n;
	ssize_t nread;
	int status;
	pid_t child_pid;
	char *line;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("#cisfun$ ");
			line = NULL;
			n = 0;
			nread = getline(&line, &n, stdin);
			if (nread != -1)
			{
				if (line[nread - 1] == '\n')
					line[nread - 1] = '\0';
				argv[1] = NULL;
				argv[0] = line;
				if (strcmp(argv[0], "exit") == 0)
				{
					free(line);
					exit(97);
				}
				if (execve(argv[0], argv, NULL) == -1)
					perror("Error:");
			}
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
