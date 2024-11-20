#include <stdio.h>

int main(void)
{
	int n, b; //MARKS ARE BETWEEN 0 AND N(INCLUDING)
	scanf("%d", &n);
	int a[n+2];
	a[n+1] = '\0';
	for (int i = 0; i <= n; ++i)
		a[i] = 0;
	while (scanf("%d", &b) != EOF && b <= n)
		++a[b];
	if (b > n)
		return 1;
	for (int i = 0; i <= n; ++i) {
		for (int j = a[i]; j > 0; --j)
			printf("*");
		printf("\n");
	}
	return 0;
}
