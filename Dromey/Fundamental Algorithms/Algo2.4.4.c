#include <stdio.h>

int lfact(int n) {
	int fact, i = 1;
	while (1) {
		if ((n % i) == 0) {
		       n /= i;
			++i;
	 	}
		else {
			fact = i - 1;
			return fact;
		}
	}
	return n;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d!", lfact(n));
	return 0;
}
