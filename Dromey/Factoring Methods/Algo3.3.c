#include <stdio.h>

int gcd(int a, int b)
{
	int rem = a > b ? (a % b) : (b % a);
	int gcd;

	if (a == b) {
		gcd = a;
	} else if (a > b) {
		if (a % b == 0)
			gcd = b;
		while (rem) {
			a = b;
			b = rem;
			rem = a % b;
		}
		gcd = b;
	} else {
		if (b % a == 0)
			return a;
		while (rem) {
			b = a;
			a = rem;
			rem = b % a;
		}
		gcd = a;
	}
	return gcd;
}

int main(void)
{
	int a, b;

	scanf("%d%d", &a, &b);
	printf("%d\n", gcd(a, b));
	return 0;
}
