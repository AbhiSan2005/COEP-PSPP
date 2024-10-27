#include <stdio.h>
#define IN 1
#define OUT 0

void print(int num) {
	int i;
	for (i = num; i > 0; --i) {
		printf("-");
	}
	printf("\n");
}

int main() {
	int c, i = 0, len = 0, state = OUT, j;
	int word[100];

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			word[i] = len;
			state = OUT;
			len = 0;
			++i;
		}
		else {
			state = IN;
			++len;
		}
	}
	state = OUT;

	for (j = i; j >= 0; --j) {
		if (word[j]) {
			printf("word %d : ", j + 1);
			print(word[j]);
		}
	}
	return 0;
}
