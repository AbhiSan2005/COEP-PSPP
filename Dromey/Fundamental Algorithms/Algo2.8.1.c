//Used 2.7 instead of using an array... felt more efficient this way(even though it's not)
#include <stdio.h>
#define BASE 8 //Choose any value between 2 to 36(26+10) 

long unsigned rev_dig(long unsigned n) {
	int r;
	unsigned long rn;
	while (n) {
                r = n % 10;
                rn = rn * 10 + r;
                n /= 10;
        }
	return rn;
}

int main(void)
{
	long unsigned n, n1 = 0;
	int r;
	scanf("%lu", &n);
	while (n) {
		r = n % BASE;
		n1 = n1 * 10 + r;
	        n /= BASE;
	}
	printf("%lu\n", rev_dig(n1));		
	return 0;
}
