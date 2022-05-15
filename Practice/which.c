#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int main(int ac, char **av)
{
	int i;
	char ap[PATH_MAX];
	struct stat st;
	char *path;

	if (ac < 2)
	{
		printf("Usage: %s file ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		if (stat(av[i], &st) == 0)
		{
			path = realpath(av[i], ap);
			printf("%s\n", path);
		}
		i++;
	}
	return (0);
}
