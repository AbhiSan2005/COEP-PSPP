#include <stdio.h>

int main(void)
{
	int a, b, diff1, diff2;

	scanf("%d%d", &a, &b);
	while (a > 1 && b > 1) {
		diff1 = b - a;
		diff2 = a - diff1;
		b = diff1;
		a = diff2;
	}
	if ((a == 1 && b == 1) || (a == 1 && b == 2))
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
