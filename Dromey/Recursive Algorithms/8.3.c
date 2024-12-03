//TOWERS OF HANOI FOR 3 PEGS ONLY
#include <stdio.h>

void tower_of_hanoi(int n, char origin, char spare, char final) {
	if (n > 1) {
		tower_of_hanoi(n-1,origin,final,spare);
		printf("disk_%d from %c to %c\n", n, origin, final);
		tower_of_hanoi(n-1,spare,origin,final);
	}
	else {
		printf("disk_%d from %c to %c\n", n, origin, final);
	}
	return ;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	tower_of_hanoi(n,'o','s','f');
	return 0;
}
