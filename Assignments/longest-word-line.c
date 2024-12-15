#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define IN 1
#define OUT 0

char maxline[1024];
char bufferline[1024];

void copy(char *dest, char *src, int len) {
	for (int i = 0, j = 0; i < len; i++, j++)
		dest[j] = src[i];
	dest[len] = '\0';
	return;
}

void max_word(int fd) {
        char c;
        int state = OUT, wordlen = 0, maxwordlen = 0, line_len = 0;
        while (read(fd,&c,1) == 1) {
                bufferline[line_len++] = c;
		if (c == ' ' || c == '\t') {
                        if (state == IN) {
                                if (wordlen > maxwordlen) {
					maxwordlen = wordlen;
					copy(maxline,bufferline,line_len);
				}
			}
                        state = OUT;
                        wordlen = 0;
                }
		else if (c == '\n') {
			if (state == IN) {
                                if (wordlen > maxwordlen) {
                                        maxwordlen = wordlen;
					copy(maxline,bufferline,line_len);
				}
                        }
			state = OUT;
			line_len = 0;
			wordlen = 0;
		}
		else {
                        wordlen++;
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
        max_word(fd);
	close(fd);
        return;
}

int main(int argc, char *argv[])
{
        readfile(argv[1]);
	printf("%s\n", maxline);
        return 0;
}
