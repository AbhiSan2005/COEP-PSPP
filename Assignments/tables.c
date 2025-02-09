#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#define MAX_STUDENTS 1024
#define MAX_SUBJECTS 16
#define BUFFER_SIZE 1024
#define RECORD_SIZE 1024
#define GRADE_COUNT 7

typedef struct subject {
	char subject_name[16];
	int no_of_credits;
	int semester;
} subjects;

typedef struct grades {
	double lower[GRADE_COUNT];
} grades;

typedef struct marks {
	long mis;
	double mark[MAX_SUBJECTS];
} marks;

int stringtoint(char *str) {
    int integer = 0, sign = 1, i = 0;
    while (str[i] == ' ') {
        i++;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    else if (str[i] == '+') {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        integer = integer * 10 + (str[i] - '0');
        i++;
    }
    return integer * sign;
}

double stringtofloat(char *str) {
    double num = 0.0;
    double frac = 0.0;
    int sign = 1, i = 0;
    double divisor = 1.0;

    while (str[i] == ' ') {
        i++;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    else if (str[i] == '+') {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.') {
        i++;
        while (str[i] >= '0' && str[i] <= '9') {
            frac = frac * 10 + (str[i] - '0');
            divisor *= 10;
            i++;
        }
        num += frac / divisor;
    }
    return num * sign;
}

long stringtolong(char *str) {
    long integer = 0, sign = 1, i = 0;
    while (str[i] == ' ') {
        i++;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    else if (str[i] == '+') {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        integer = integer * 10 + (str[i] - '0');
        i++;
    }
    return integer * sign;
}
//THIS WAS WRITTEN TO ACT LIKE STRCPY WITH LENGTH SIZE
void copy(char *dest, const char *src, int len) {
    int i = 0;
    while (i < len) {
        dest[i] = src[i];
        i++;
    }
    dest[len] = '\0';
    return;
}

void sort(marks *mrk, int no_of_students, int column) {
    if (column < 0 || column >= MAX_SUBJECTS) {
        printf("Error: Invalid column number\n");
        return;
    }
    for (int i = 0; i < no_of_students - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < no_of_students; j++) {
            if (mrk[j].mark[column] > mrk[max_index].mark[column]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            marks temp = mrk[i];
            mrk[i] = mrk[max_index];
            mrk[max_index] = temp;
        }
    }
	return;
}
//MY OWN SQROOT TO AVOID USING MATH.H
double sqroot(double n) {
        double g1 = n / 2, g2 = 0;
        while((g1 - g2) > 0.000001 || (g2 - g1) > 0.000001) {
                g2 = (g1 + (n / g1)) / 2;
                g1 = (g1 + g2) / 2;
        }
        return g2;
}

int read_subjects (subjects sub[]) {
    int fd, N = 0, buffer_size, irecord = 0;
    char record[RECORD_SIZE], buffer[BUFFER_SIZE];
    
    fd = open("subjects.csv", O_RDONLY);
    
    while ((buffer_size = read(fd, buffer, sizeof(buffer))) > 0) {
        for (int k = 0; k < buffer_size; k++) {
            if (buffer[k] == '\n') {
                record[irecord] = '\0';
                irecord = 0;
                char *subject = strtok(record, ",");
                char *credits = strtok(NULL, ",");
                char *semester = strtok(NULL, ",");
                if (!subject || !credits || !semester) {
                    printf("Skipping incomplete entry\n");
                    exit(1);
                }
                strncpy(sub[N].subject_name, subject, sizeof(sub[N].subject_name) - 1);
                sub[N].subject_name[sizeof(sub[N].subject_name) - 1] = '\0';
                sub[N].no_of_credits = stringtoint(credits);
                sub[N].semester = stringtoint(semester);
                N++;
            } else {
                if (irecord < RECORD_SIZE - 1) {
                    record[irecord++] = buffer[k];
                }
            }
        }
    }
    close(fd);
	return N;
}

void read_grades(grades grd[], int N) {
    int fd, n = 0, buffer_size, irecord = 0;
    char record[RECORD_SIZE], buffer[BUFFER_SIZE];
    
    fd = open("grades.csv", O_RDONLY);
    
    while ((buffer_size = read(fd, buffer, sizeof(buffer))) > 0) {
        for (int k = 0; k < buffer_size; k++) {
            if (buffer[k] == '\n') {
                record[irecord] = '\0';
                irecord = 0;
                char *token = strtok(record, ",");
                int j = 0;
                while (token && j < GRADE_COUNT) {
                    grd[n].lower[j++] = stringtofloat(token);
                    token = strtok(NULL, ",");
                }
                if (j != GRADE_COUNT) {
                    printf("Incomplete grade entry\n");
                    exit(1);
                }           
                n++;
            } else {
                if (irecord < RECORD_SIZE - 1) {
                    record[irecord++] = buffer[k];
                }
            }
        }
    }
    if (n != N) {
        printf("Grades for all subjects are required\n");
        exit(1);
    }
    close(fd);
}

char *grade_name[] = {"AA", "AB", "BB", "BC", "CC", "CD", "DD", "FF"};
double grade_point[] = {10, 9, 8, 7, 6, 5, 4, 0};

int read_marks(marks *mrk, int no_of_subjects) {
    int fd, no_of_students = 0, buffer_size, irecord = 0;
    char record[RECORD_SIZE], buffer[BUFFER_SIZE];
    
    fd = open("marks.csv", O_RDONLY);
    
    while ((buffer_size = read(fd, buffer, sizeof(buffer))) > 0) {
        for (int k = 0; k < buffer_size; k++) {
            if (buffer[k] == '\n') {
                record[irecord] = '\0';
                irecord = 0;
                char *mis_str = strtok(record, ",");
                if (!mis_str) {
                    printf("Skipping incomplete entry\n");
                    exit(1);
                }
                mrk[no_of_students].mis = stringtolong(mis_str);
                char *token;
                int j = 0;
                while ((token = strtok(NULL, ",")) && j < no_of_subjects) {
                    mrk[no_of_students].mark[j++] = stringtofloat(token);
                }
                if (j != no_of_subjects) {
                    printf("Skipping entry with missing marks\n");
                    exit(1);
                }
                no_of_students++;
            } else {
                if (irecord < RECORD_SIZE - 1) {
                    record[irecord++] = buffer[k];
                }
            }
        }
    }
    close(fd);
    if (no_of_students > MAX_STUDENTS) {
        printf("Amount of students is too large\n");
        exit(1);
    }
    return no_of_students;
}

int main(void) {
	subjects sub[MAX_SUBJECTS];
	grades grd[MAX_SUBJECTS];
	marks mrk[MAX_STUDENTS];
	int N, no_of_students;
	char command[32], subject_name[16];
	N = read_subjects(sub);
	read_grades(grd,N);
	no_of_students = read_marks(mrk,N);
	
	while (1) {
        printf(">");
        scanf("%s", command);
		int sem, n, student_found = 0, subject_found = 0, semester_found = 0, failure = 0;
		long mis;
		if (strcmp(command, "grade") == 0) {
            if (scanf("%ld%s", &mis, subject_name) == 2) {;
                for (int i = 0; i < no_of_students; i++) {
                    if (mrk[i].mis == mis) {
                        student_found = 1;
                        for (int j = 0; j < N; j++) {
                            if (strcmp(sub[j].subject_name, subject_name) == 0) {
                                    subject_found = 1;
                                    int k;
                                    for (k = 0; k < 7; k++) {
                                        if (grd[j].lower[k] >= mrk[i].mark[j])
                                            break;
                                    }
                                    printf("%s\n", grade_name[GRADE_COUNT - k]);
                                	break;
                        	}
							
                        }
                        break;
                    }
                }
				if (!student_found)
                	printf("Student with MIS %ld not found\n", mis);
				if (!subject_found)
                	printf("Subject %s not found\n", subject_name);
			} else {
                for (int i = 0; i < no_of_students; i++) {
                    printf("%ld", mrk[i].mis);
                    for (int j = 0; j < N; j++) {
                        int k;
                        for (k = 0; k < 7; k++) {
                        	if (grd[j].lower[k] >= mrk[i].mark[j])
                                break;
                        }
                        printf(", %s", grade_name[7 - k]);
                    }
                    printf("\n");
                }
				int c;
    			while ((c = getchar()) != '\n' && c != EOF);
			}
		} else if (strcmp(command, "cgpa") == 0) {
            scanf("%ld", &mis);
            for (int i = 0; i < no_of_students; i++) {
                if (mrk[i].mis == mis) {
                    student_found = 1;
					double weighted_credits = 0;
					double total_credits = 0;
                    for (int j = 0; j < N; j++) {
                        int k;
                        for (k = 0; k < 7; k++) {
                            if (grd[j].lower[k] >= mrk[i].mark[j])
                                break;
                        }
                        total_credits += sub[j].no_of_credits;
						weighted_credits += (sub[j].no_of_credits * grade_point[GRADE_COUNT - k]);
					}
					printf("%lf\n", weighted_credits / total_credits);
                    break;
                }
            }
			if (!student_found) {
                printf("Student with MIS %ld not found\n", mis);
            }
		} else if (strcmp(command, "sgpa") == 0) {
            scanf("%ld%d", &mis, &sem);
            for (int i = 0; i < no_of_students; i++) {
                if (mrk[i].mis == mis) {
                    student_found = 1;
                    double weighted_credits = 0;
                    double total_credits = 0;
					for (int j = 0; j < N; j++) {
                    	if (sub[j].semester == sem) {
                        	semester_found = 1;
							int k;
                            for (k = 0; k < 7; k++) {
                                if (grd[j].lower[k] >= mrk[i].mark[j])
                                    break;
                            }
                            total_credits += sub[j].no_of_credits;
                        	weighted_credits += (sub[j].no_of_credits * grade_point[GRADE_COUNT - k]);
						}
                    }
                	printf("%lf\n", weighted_credits / total_credits);
                    break;
                }
            }
			if (!student_found) {
                printf("Student with MIS %ld not found\n", mis);
            }
			if (!semester_found) {
                printf("Semester not mentioned in subjects.csv file\n");
        	}
		} else if (strcmp(command, "failed") == 0) {
            scanf("%ld", &mis);
            for (int i = 0; i < no_of_students; i++) {
                if (mrk[i].mis == mis) {
                    student_found = 1;
					for (int j = 0; j < N; j++) {
                        if (mrk[i].mark[j] <= grd[j].lower[0]) {
                            failure = 1;
							printf("%s\n", sub[j].subject_name);
                        }
                    }
                    break;
                }
            }
			if (!student_found) {
                printf("Student with MIS %ld not found\n", mis);
        	}
			if (!failure) {
                printf("Student with MIS %ld not failed in any subject\n", mis);
        	}
		} else if (strcmp(command, "topsem") == 0) {
            scanf("%d", &sem);
            for (int j = 0; j < N; j++) {
                if (sub[j].semester == sem) {
                    semester_found = 1;
					double max = DBL_MIN;
					int toppers_index[8];
					for (int i = 0; i < 8; i++) {
    					toppers_index[i] = -1;
					}
					for (int i = 0; i < no_of_students; i++) {
						if (mrk[i].mark[j] >= max) {
							max = mrk[i].mark[j];
						}
					}
					for (int i = 0, k = 0; i < no_of_students; i++) {
                    	if (mrk[i].mark[j] == max) {
                        	toppers_index[k++] = i;
                    	}
                	}
					for (int i = 0; i < 8; i++) {
						if (toppers_index[i] >= 0) {
							printf("%ld, ", mrk[toppers_index[i]].mis);
						}
					}
					printf("%s\n", sub[j].subject_name);
            	}
			}
            if (!semester_found) {
                printf("Semester not mentioned in subjects.csv file\n");
            }
		} else if (strcmp(command, "topsub") == 0) {
            scanf("%s", subject_name);
            for (int j = 0; j < N; j++) {
                if (strcmp(sub[j].subject_name, subject_name) == 0) {
                	subject_found = 1;
                    double max = DBL_MIN;
                	int toppers_index[8];
                	for (int i = 0; i < 8; i++) {
                        toppers_index[i] = -1;
                    }
                    for (int i = 0; i < no_of_students; i++) {
                        if (mrk[i].mark[j] >= max) {
                            max = mrk[i].mark[j];
                        }
                    }
                    for (int i = 0, k = 0; i < no_of_students; i++) {
                        if (mrk[i].mark[j] == max) {
                            toppers_index[k++] = i;
                        }
                    }
                    for (int i = 0; i < 8; i++) {
                		if (toppers_index[i] >= 0) {
                            printf("%ld\n", mrk[toppers_index[i]].mis);
                        }
                    }
					break;
				}
            }
			if (!subject_found) {
                printf("Subject %s not found\n", subject_name);
            }
		} else if (strcmp(command, "topnsub") == 0) {
            scanf("%s %d", subject_name, &n);
            for (int j = 0; j < N; j++) {
                if (strcmp(sub[j].subject_name, subject_name) == 0) {
                    subject_found = 1;
					sort(mrk, no_of_students, j);
					for (int i = 0; i < n; i++) {
                            printf("%ld, %lf\n", mrk[i].mis, mrk[i].mark[j]);
                    }
                	break;
                }
            }
            if (!subject_found) {
                printf("Subject %s not found\n", subject_name);
            }
		} else if (strcmp(command, "stdev") == 0) {
            scanf("%s", subject_name);
            int subject_index = -1;
			for (int j = 0; j < N; j++) {
                if (strcmp(sub[j].subject_name, subject_name) == 0) {
                    subject_found = 1;
					subject_index = j;
                    break;
                }
            }
            if (subject_index != -1) {
                double sum = 0, sum_sq = 0;
                for (int i = 0; i < no_of_students; i++) {
                    sum += mrk[i].mark[subject_index];
                }
                double mean = sum / no_of_students;
                for (int i = 0; i < no_of_students; i++) {
                    sum_sq += (mrk[i].mark[subject_index] - mean) * (mrk[i].mark[subject_index] - mean);
                }
				double variance = sum_sq / no_of_students;
                printf("%.2lf\n", sqroot(variance));
            }
		} else if (strcmp(command, "exit") == 0) {
			return 0;
        } else {
            printf("Invalid command\n");
        }
	}
	return 0;
}