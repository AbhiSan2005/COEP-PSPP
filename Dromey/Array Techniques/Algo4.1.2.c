//ARRAY REVERSAL USING I AND J... 4.1.2
#include <stdio.h>

int *rarr(int *a, int n) {
	int i = 0, j = n - 1, t; 
	if (n % 2 == 0) {
		while (i != j - 1) {
			t = a[j];
			a[j] = a[i];
			a[i] = t;
			++i;
			--j;
		}
		return a;
	}
	else {
		while (i != j) {
			t = a[j];
                        a[j] = a[i];
                        a[i] = t;
                        ++i;
                        --j;
		}
		return a;
	}
}

int main(void)
{
	int a[16] = {1, 2, 3, 4, 5, 6, 7}, len = 7;
	int *ra = rarr(a, len);
	for (int i = 0; i < len; ++i)
		printf("%d", ra[i]);
	printf("\n");
	return 0;
}
