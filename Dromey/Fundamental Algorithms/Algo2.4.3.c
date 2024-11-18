#include <stdio.h>

int fact_num(int n) {
	int i = 1;
	while (1) {
		if (n % i == 0) {
			n /= i;
			++i;
		}
		else {
			break;
		}
	}
	if (n == 1) {
		return 0;
	}
	else {
		return 1;
	}
}

int main(void)
{
	int n, y;
	scanf("%d", &n);
	y = fact_num(n);
	if (y == 1) {
		printf("not a factorial number\n");
	}
	else {
		printf("factorial number\n");
	}
	return 0;
}
