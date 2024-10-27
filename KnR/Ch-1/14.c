#include <stdio.h>
#include <ctype.h>

int main() {
	int c, i = 0, j = 0, k = 0;
       	int alp[128];

	for (i = 0; i < 128; ++i) {
		alp[i] = 0;
	}
	while ((c = getchar()) != EOF) {
		++alp[c];
	}
	for (j = 0; j < 128; ++j) {
		printf("%d: ", j);
		for (k = 0; k < alp[j]; ++k) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

	
