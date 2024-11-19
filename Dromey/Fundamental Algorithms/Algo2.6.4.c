#include <stdio.h>

int arefibonacci(int a, int b) {
	if (a > b) {
		a = a + b;
		b = a - b;
		a = a - b;
	}
	int diff;
	while (b >= a && a > 0) {
		diff = b - a;
		b = a;
		a = diff;
	}
	if (b == 1 && a == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", arefibonacci(a,b));
	return 0;
}
