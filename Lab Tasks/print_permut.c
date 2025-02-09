#include <stdio.h>
#include <stdlib.h>

void print_permutations (int numbers[], int len, int n) {
	int i, t, *p;
	if(len < 0)
		return;
	if(len == 1) {
		p = numbers - (n - 1);
		for (i = 0; i < n; i++)
			printf("%d ", p[i]);
		printf("\n");
		return;
	}
	int *b= malloc(len* sizeof(int));
	for (i = 0; i < len; i++)
		b[i] = numbers[i];
	for(i = 0; i < len; i++) {
		t = numbers[i];
		numbers[i] = numbers[0];
		numbers[0] = t;
		print_permutations(numbers + 1, len - 1, n);
		t = numbers[i];
		numbers[i]= numbers[0];
		numbers[0] = t;
	}
	for(i = 0; i < len; i++)
		numbers[i]= b[i];
	free(b);
}

int main() {
	int a[] = {1, 2, 3, 4}, len = 4;
	print_permutations(a, len, len);
	return 0;
}
