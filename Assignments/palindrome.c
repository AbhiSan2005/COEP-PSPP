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

void to_lower(char src[], char dest[], int len) {
        for (int i = 0; i < len; i++) {
                if (src[i] >= 'A' && src[i] <= 'Z')
                        dest[i] = src[i] + 32;
                else
                        dest[i] = src[i];
        }
        dest[len] = '\0';
	return;
}

void check_palindrome(char a[], int len) {
        char temp[64];
        to_lower(a,temp,len);
        int i, j;
        if (len == 1) {
                print_palindrome(a,len);
        } else {
                for (i = 0, j = len - 1; j > i; i++, j--) {
                        if (temp[i] != temp[j])
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
                        if (state == IN) {
                                word[i] = '\0';
                                check_palindrome(word,i);
                        }
                        state = OUT;
                        i = 0;
                } else {
                        word[i++] = c;
                        state = IN;
                }
        }
        if (state == IN) {
                word[i] = '\0';
                check_palindrome(word,i);
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

int main(int argc, char *argv[]) {
        char input[16];
        scanf("%s", input);
	readfile(input);
        return 0;
}
