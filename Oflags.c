#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
	printf("%d\n", O_RDWR);
	printf("%d\n", O_RDONLY);
	printf("%d\n", (1 << 1));
	printf("%d\n", 3 & 2);
	printf("%d\n", 3 | 2);
	printf("%d\n", O_WRONLY);
	printf("%d\n", (O_RDONLY + O_WRONLY));
	printf("%d\n", (O_RDONLY | O_WRONLY));
	printf("%d\n", (O_RDONLY & O_WRONLY));
	printf("%d\n", (O_RDONLY && O_WRONLY));
	printf("%d\n", (O_RDONLY << 1));
	printf("%d\n", (O_WRONLY << 1));
	return (0);
}
