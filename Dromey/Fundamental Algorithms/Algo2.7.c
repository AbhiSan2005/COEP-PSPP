#include <stdio.h>

int main(void)
{
	unsigned long n, rn = 0; 
	int r;
	scanf("%lu", &n);
	while (n) {
		r = n % 10;
		rn = rn * 10 + r;
		n /= 10;
	}
	printf("%lu\n", rn);
	return 0;
}
