#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define MAXLINE 1024
#define MAXROWS 512
#define MAXCOLUMNS 512

int readline(int fd, char line[], int max) {
        int i = 0;
        char ch;
        while (i < max && read(fd, &ch, 1) && ch != '\n') {
                line[i] = ch;
                i++;
        }
        line[i] = '\0';
        return i;
}

void print_matrix(int mat[][MAXCOLUMNS], int mat_size[]) {
        for (int i = 0; i < mat_size[0]; i++) {
                for (int j = 0; j < mat_size[1]; j++) {
                        printf("%d      ", mat[i][j]);
                }
                printf("\n");
        }
        return;
}

void read_matrix(char *filename, int mat[][MAXCOLUMNS], int mat_size[]) {
        int fd;
        char *p, temp[MAXLINE];
        fd = open(filename, O_RDONLY);
        if (fd == -1) {
                printf("couldn't open file\n");
                exit (1);
        }
        readline(fd, temp, MAXLINE);
        for (int i = 0; i < mat_size[0]; i++) {
                char line[MAXLINE];
                if (readline(fd, line, MAXLINE) != 0) {
                        p = strtok(line, "	");
                        mat[i][0] = atoi(p);
                        for (int j = 1; j < mat_size[1]; j++) {
                                p = strtok(NULL, "	");
                                if (p) {
                                        mat[i][j] = atoi(p);
                                }
                                else {
                                        printf("bad data\n");
                                        exit(1);
                                }
                        }
                }
        }
        close(fd);
        return;
}

void add_matrices(int mat1[][MAXCOLUMNS], int mat2[][MAXCOLUMNS], int mat_size[]) {
        for (int i = 0; i < mat_size[0]; i++) {
                for (int j = 0; j < mat_size[1]; j++) {
                        mat1[i][j] += mat2[i][j];
                }
        }
        return;
}

void read_mat_size(char *filename, int mat_size[]) {
        int fd;
        char *p, line[MAXLINE];
        fd = open(filename, O_RDONLY);
        if (fd == -1) {
                printf("couldn't open file\n");
                exit (1);
        }
        readline(fd, line, MAXLINE);
        p = strtok(line, "	");
        mat_size[0] = atoi(p);
        p = strtok(NULL, "	");
        mat_size[1] = atoi(p);
        close(fd);
        return;
}

int main() {
        char input1[64], input2[64];
        int mat1_size[2], mat2_size[2];
        int mat1[MAXROWS][MAXCOLUMNS], mat2[MAXROWS][MAXCOLUMNS];
        /*MAT_SIZE IS SUPPOSED TO CONTAIN NO. OF ROWS AND COLUMNS IN THE ORDER*/
        scanf("%s", input1);
        scanf("%s", input2);
        read_mat_size(input1, mat1_size);
        read_mat_size(input2, mat2_size);

        for (int i = 0; i < 2; i++) {
                if (mat1_size[i] != mat2_size[i]) {
                        printf("not compatible\n");
                        exit(1);
                }
        }
        read_matrix(input1, mat1, mat1_size);
        read_matrix(input2, mat2, mat2_size);
        add_matrices(mat1, mat2, mat1_size);
        print_matrix(mat1, mat1_size);
        return 0;
}
