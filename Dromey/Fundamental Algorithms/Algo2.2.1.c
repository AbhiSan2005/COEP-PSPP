#include <stdio.h>
#define PMARKS 50

int main(void)
{
	int sum = 0, count = 0, i = 0, a;
	while (scanf("%d", &a) != EOF) {
		if (a >= PMARKS) {
			++i;
			++count;
			sum += a;
		}
		else {
			++i;
			sum += a;
		}
	printf("Total Marks: %d", sum);
	printf("Total Passes: %d", count);
	printf("Pass Percentage: %d%%", (count/i) * 100);
	return 0;
}
