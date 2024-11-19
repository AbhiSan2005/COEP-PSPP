#include <stdio.h>

int main(void)
{
	int n, a, b, i;
	scanf("%d", &n);
	a = 0;
	b = 1;
	i = 2;
	if (n == 1) {
		printf("%d ", a);
		return 0; 
	}
	else if (n > 1) {
		while (i < n) {
			printf("%d %d ", a, b);
			a = a + b;
			b = a + b;
			i += 2;
		}
		if (i == n) {
			printf("%d %d\n", a, b);
		}
		else {
			printf("%d\n", a);
		}
		return 0;
	}
	else {
		printf("invalid n\n");
		return 1;
	}
}
