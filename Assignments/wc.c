#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define IN 1
#define OUT 0

int counts[3] = {0};//THIS WILL CONTAIN THE COUNT OF CHARACTERS, WORDS AND LINES RESP.

void print_count(int a[], char *filename) {
	printf("%d ", a[2]);
	printf("%d ", a[1]);
	printf("%d ", a[0]);
	printf("%s\n", filename);
	return;
}

void count(int fd, int a[]) {
	char c;
	int state = OUT;

	while (read(fd,&c,1) == 1) {
		a[0]++;
		if (c == '\n')
			a[2]++;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			a[1]++;
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
	count(fd,counts);
	close(fd);
	return;
}

int main(int argc, char *argv[])
{
	readfile(argv[1]);
	print_count(counts,argv[1]);
	return 0;
}
