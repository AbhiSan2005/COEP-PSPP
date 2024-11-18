#include <stdio.h>

int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	a = a + b;
	b = a - b; //b = (a+b) - b = a
	a = a - b; //a = (a+b) - a = b	
	return 0;
}
