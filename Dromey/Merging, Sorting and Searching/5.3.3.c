//ALTERNATING BUBBLESORT ALGORITHM, (IT'LL BE MORE EFFICIENT THAN PASSING IN ONE DIRECTION)
#define TRUE 1
#define FALSE 0
#include <stdio.h>

int *altbubblesort(int a[], int len) {
	int sorted = FALSE, i = 0, j, t;
	while (i < len && !sorted) {
		sorted = TRUE;
		++i;
		if (i % 2) {
			for (j = 0; j < len - i; j++) {
				if (a[j] > a[j+1]) {
					t = a[j];
					a[j] = a[j+1];
					a[j+1] = t;
					sorted = FALSE;
				}
			}
		}
		else {
			for (j = len - 1; j >= 0; j--) {
                                if (a[j-1] > a[j]) {
                                        t = a[j-1];
                                        a[j-1] = a[j];
                                        a[j] = t;
                                        sorted = FALSE;
                                }
                        }
		}
	}
	return a;
}
int main(void)
{
	int arr[] = {30,12,18,8,14,41,3,39}, len = 8;
	int *p = altbubblesort(arr, len);
	for (int i = 0; i < len; i++)
		printf("%d ", p[i]);
	printf("\n");
	return 0;
}
