#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - test fork, wait & execve
 *
 * Return: 0 upon success, 1 upon failure
 */
int main(void)
{
	int i, status;
	pid_t child_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			sleep(2);
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
		}
		else
		{
			wait(&status);
			printf("\nChild %d has exited\n === \n", i + 1);
		}
	}
	return (0);
}
