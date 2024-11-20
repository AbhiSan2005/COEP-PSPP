#include <stdio.h>
#include <limits.h>

int main(void)
{
	int a[16] = {1, 3, 4, 5 , 6, 2, 3, 8, 8, 1}, len = 10;
	int maxcount = 0, mincount = 0, max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < len; ++i) {
		if (a[i] > max) {
			max = a[i];
			maxcount = 1;
		}
		else if (a[i] == max) {
			++maxcount;
		}
		if (a[i] < min) {
			min = a[i];
			mincount = 1;
		}
		else if (a[i] == min) {
			++mincount;
		}
	}
	printf("max :%d occurs %d times\n", max, maxcount);
	printf("min :%d occurs %d times\n", min, mincount);
	return 0;
}
