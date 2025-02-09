#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <float.h>
#include <string.h>

typedef struct transaction {
    double amount;
    time_t time;
    unsigned int from_id;
    unsigned int to_id;
    char location[32];
} transaction;

char final_time[20];

void copy(char *dest, const char *src, int len) {
    int i = 0;
    while (src[i] && i < len) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return;
}

transaction find_min_transaction(int fd) {
    int n_of_records;
    transaction temp, min_transaction;
    double min_amount = DBL_MAX;
    read(fd, &n_of_records, sizeof(int));
    while (n_of_records) {
        read(fd, &temp, sizeof(transaction));
        if (temp.amount < min_amount) {
            min_amount = temp.amount;
            min_transaction = temp;
        }
        n_of_records--;
    }
    return min_transaction;
}

void convert_ctime_format(const time_t *time_ptr, char *formatted_time) {
    struct tm *time_info = gmtime(time_ptr);
    strftime(formatted_time, 20, "%d:%m:%Y %H:%M:%S", time_info);
    return;
}

void print_min_transaction(transaction *t) {
    convert_ctime_format(&t->time, final_time);
    printf("%s\n", final_time);
    return;
}

int main(int argc, char *argv[]) {
    char input[16];
    scanf("%s", input);
    int fd = open(input, O_RDONLY);
    transaction min_transaction = find_min_transaction(fd);
    print_min_transaction(&min_transaction);
    close(fd);
    return 0;
}
