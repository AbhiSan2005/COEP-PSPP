#include <stdio.h>

int main(void)
{
	int a[16] = {1,2,2,2,3,4,5}, n = 7, i = 1, j;
	while (a[i - 1] != a[i] && i < n)
		++i;
	if (a[i - 1] != a[i])
		++i;
	j = i - 1;
	while (i < n) {
		++i;
		if (a[i - 1] != a[i] && i < n) {
			++j;
			a[j] = a[i];
		}
	}
	for (int i = 0; i <= j; ++i) {
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}
