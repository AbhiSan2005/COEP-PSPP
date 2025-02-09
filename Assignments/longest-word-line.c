#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void copy(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return;
}

int find_max_word_len(char line[]) {
    int max_word_len = 0, current_word_len = 0, i = 0;
    while (line[i] != '\n' && line[i] != '\0') {
        if (line[i] == ' ' || line[i] == '\t') {
            if (current_word_len > max_word_len) {
                max_word_len = current_word_len;
            }
            current_word_len = 0;
        } else {
            current_word_len++;
        }
        i++;
    }
    if (current_word_len > max_word_len) {
        max_word_len = current_word_len;
    }
    return max_word_len;
}

void mygetline(char line[], int fd) {
    int line_len = 0;
    char c;
    while (read(fd, &c, 1) > 0 && c != '\n') {
        line[line_len++] = c;
    }
    line[line_len] = '\0';
    return;
}

void max_word(char maxline[], int fd) {
    char bufferline[1024];
    int max_word_len = 0;

    while (read(fd, bufferline, 1) > 0) {
        lseek(fd, -1, SEEK_CUR);
        mygetline(bufferline,fd);
        int word_len = find_max_word_len(bufferline);
        if (word_len > max_word_len) {
            max_word_len = word_len;
            copy(maxline,bufferline);
        }
    }
    return;
}

void readfile(char *filename, char maxline[]) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Can't open file\n");
        exit(1);
    }
    max_word(maxline,fd);
    close(fd);
    return;
}

int main(int argc, char *argv[]) {
    char maxline[1024], input[16];
    scanf("%s", input);
    readfile(input, maxline);
    printf("%s\n", maxline);
    return 0;
}
