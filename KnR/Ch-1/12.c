#include <stdio.h>

int main() {
	int c, lastc = ' ';

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			if (lastc != ' ' || lastc != '\t' || lastc != '\n') {
				printf("\n");
			}
		}
		else if (c == '\n' && lastc == '\n') {
			;
		}
		else {
			if (c != '\n') {
				putchar(c);
			}
		}
		lastc = c;
	}
	return 0;
}
