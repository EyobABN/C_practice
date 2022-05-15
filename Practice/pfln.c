#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void factorize(long long n)
{
	int count = 0;

	while (!(n % 2))
	{
		n = n / 2;
		count++;
	}

	if (count)
		printf("2 %d\n", count);

	for (long long i = 3; i <= sqrt(n); i += 2)
	{
		count = 0;
		while (n % i == 0)
		{
			count++;
			n = n / i;
		}
		if (count)
			printf("%lld %d\n", i, count);
	}
	
	if (n > 2)
		printf("%lld 1\n", n);
}

int main(void)
{
	long long n = 612852475143;
	factorize(n);
	return (0);
}

