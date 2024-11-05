#include <stdio.h>
#include <math.h>

double sqroot(double n)
{
	double g1 = n / 2, g2 = 0;

	while (fabs(g1 - g2) > 0.000001) {
		g2 = (g1 + (n / g1)) / 2;
		g1 = (g1 + g2) / 2;
	}
	return g2;
}

int main(void)
{
	double a;

	scanf("%lf", &a);
	printf("%lf", sqroot(a));
	return 0;
}
