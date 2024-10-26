#include <stdio.h>

int main(void) {
    int c, lastc;
    lastc = ' ';

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (lastc != ' ')
                putchar(c);
        }
	else {
            putchar(c);
	}
	lastc = c;
    }
    return 0;
}
