#include <stdio.h>

double power(double base, int raise)
{
	int i; double p = 1;

	for (i = 0; i < raise; ++i)
		p = p * base;
	return p;
}

long fact(int num)
{
	long prod = 0;

	prod = num;
	if (num == 0)
		prod = 1;
	while (num > 1) {
		prod = prod * (num - 1);
		--num;
	}
	return prod;
}

int main(void)
{
	double x; int n;

	scanf("%lf%d", &x, &n);
	printf("%.2lf", power(x, n) / fact(n));
	return 0;
}
