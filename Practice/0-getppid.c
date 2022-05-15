#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_ppid;
	pid_t my_pid;

	my_ppid = getppid();
	my_pid = getpid();
	printf("Parent: %u, Current: %u\n", my_ppid, my_pid);
	return (0);
}
