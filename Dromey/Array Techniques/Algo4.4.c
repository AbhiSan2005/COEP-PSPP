#include <stdio.h>

int main(void)
{
	int a[16] = {1,2,2,2,3,4,5}, n = 7, i = 1, j;
	while (a[i - 1] != a[i] && i < n)
		++i;
	// i = 2
	if (a[i - 1] != a[i])
		++i;
	// i = 3
	j = i - 1;
	// j = 2
	// EVERYTHING UPTO THIS POINT IS FOR FINDING FIRST DUPLICATE PAIR AND MOVING ON TO THE NEXT ONE
	while (i < n) {
		++i;
		// i = 4
		if (a[i - 1] != a[i] && i < n) {
			++j;
			// j = 3
			a[j] = a[i];
			// a[3] = 3
		}
	}
	for (int i = 0; i <= j; ++i) {
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}
