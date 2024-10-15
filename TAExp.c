#include <stdio.h>

int main() {
        int a, b, c;
	a = 18;
	b = 16;
	c = a | b;
	c = c & b;
	a = b >> 2;
	b = a == 4;
	c = b != 16;
	a = b & c;
	printf("%d\n", a);
	return 0;
}
