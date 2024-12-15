#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define IN 1
#define OUT 0

void print_palindrome(char a[], int len) {
	for (int i = 0; i < len; i++)
		putchar(a[i]);
	printf("\n");
	return;
}

void check_palindrome(char a[], int len) {
	int i, j;
	if (len > 1) {
		for (i = 0, j = len - 1; j > i; i++, j--) {
			if (a[i] != a[j])
				break;
		}
		if (i >= j)
			print_palindrome(a,len);
	}
	return;
}

void find_palindromes(int fd) {
	char c, word[64];
	int state = OUT, i = 0;
	while (read(fd,&c,1) == 1) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN)
				check_palindrome(word,i);
			state = OUT;
			i = 0;
		}
		else {
			word[i++] = c;
			state = IN;
		}
	}
	return;
}

void readfile(char *filename) {
        int fd = open(filename, O_RDONLY);
        if(fd == -1) {
                printf("can't open file\n");
                exit(1);
        }
	find_palindromes(fd);
	close(fd);
	return;
}

int main(int argc, char *argv[])
{
	readfile(argv[1]);
	return 0;
}
