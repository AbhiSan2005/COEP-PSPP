#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double nthroot(double m, int n) {
        double g1 = m/2, g2 = 0;
        while (fabs(g1 - g2) > 1e-6) {
                g2 = (((n - 1) * g1) + (m / pow(g1, n -1))) / n;
                g1 = (g1 + g2) / 2;
        }
        return g1;
}

int main(void)
{
	int n;
	double m = 1, a;
	scanf("%d", &n);
	for (int i = n; i > 0; --i) {
		if (scanf("%lf", &a) != 1) {
			return 1;
		}
		else {
			m = m * a;
		}
	}
	printf("%lf", nthroot(m,n));	
	return 0;
}
