#include <stdio.h>
#include <math.h>

int sfactor(int n) {
	if (n % 2 == 0) {
		return 2;
	}
	else {
		int d = 3;
		while (n % d != 0 && sqrt(n) > d) {
			if ((d+2) % 3 == 0)
				d += 4;
			else 
				d += 2;
		}
		if (n % d == 0)
			return d;
		else
			return 1;
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", sfactor(n));
	return 0;
}
