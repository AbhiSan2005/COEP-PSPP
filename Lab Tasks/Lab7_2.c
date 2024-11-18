#include <stdio.h>

int abs(int a)
{
	if (a > 0)
		return a;
	if (a < 0)
		return -a;
	else
		return 0;
}

int main(void)
{
	int i = 1, term = 1, n, sum = 0;

	scanf("%d", &n);
	while (i <= n) {
		printf("%d", term);
		sum += term;
		if (i % 2 == 0)
			term = (abs(term) + 2);
		if (i % 2 != 0)
			term = -(abs(term) + 2);
		if (i != 1 && i % 2 == 0 && i != n)
			printf("+");
		++i;
	}
	printf("\n%d\n", sum);
	return 0;
}
