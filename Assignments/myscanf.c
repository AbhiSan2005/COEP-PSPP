#include <stdio.h>
#include <stdlib.h>

void copy(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return;
}

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

int myscanf(char *format, void *arg) {
        char a[1024], c;
        int i, successfull_reads = 0;
        if (*(format++) != '%') {
                printf("Expected %%d, %%u, %%c, %%s, %%f, or %%lf only\n");
                exit(1);
        }
	switch (*format) {
	case 'u':
		i = 0;
		while ((c = getchar()) == ' ' || c == '\t' || c == '\n');
		ungetc(c, stdin);
		for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
			if (c >= '0' && c <= '9')
				a[i] = c;
			else {
				ungetc(c, stdin);
				break;
			}
		}
		a[i] = '\0';
		if (i > 0) {
			int *u = (int *)arg;
			*u = stringtoint(a);
			successfull_reads++;
		}
		break;
	case 'd':
		i = 0;
		while ((c = getchar()) == ' ' || c == '\t' || c == '\n');
		ungetc(c, stdin);
		for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
			if ((c >= '0' && c <= '9') || c == '+' || c == '-')
				a[i] = c;
			else {
				ungetc(c, stdin);
				break;
			}
		}
		a[i] = '\0';
		if (i > 0) {
			int *d = (int *)arg;
			*d = stringtoint(a);
			successfull_reads++;
		}
		break;
	case 'c':
		c = getchar();
		char *ch = (char *)arg;
		*ch = c;
		successfull_reads++;
		break;
	case 's':
		i = 0;
		while ((c = getchar()) == ' ' || c == '\t' || c == '\n');
		ungetc(c, stdin);
		while ((c = getchar()) != EOF && c != '\n' && c != ' ' && c != '\t') {
			a[i++] = c;
		}
		a[i] = '\0';
		copy((char *)arg, a);
		successfull_reads++;
		break;
	case 'f':
		i = 0;
		while ((c = getchar()) == ' ' || c == '\t' || c == '\n');
		ungetc(c, stdin);
		for (i = 0; (c = getchar()) != EOF && c != '\n' && c != '.'; i++) {
			if ((c >= '0' && c <= '9') || c == '+' || c == '-')
				a[i] = c;
			else {
				ungetc(c, stdin);
				break;
			}
		}
		if (c == '.') {
			a[i++] = c;
			for (; (c = getchar()) != EOF && c != '\n'; i++) {
				if (c >= '0' && c <= '9')
					a[i] = c;
				else {
					ungetc(c, stdin);
					break;
				}
			}
			a[i] = '\0';
			float *f = (float *)arg;
			*f = atof(a);
		}
		else {
			if (i > 0) {
				a[i] = '\0';
				float *f = (float *)arg;
				*f = atof(a);
			}
		}
		successfull_reads++;
		break;
	case 'l':
		if (*(++format) != 'f') {
			printf("Expected %%d, %%u, %%c, %%s, %%f, or %%lf only\n");
			exit(1);
		}
		i = 0;
		while ((c = getchar()) == ' ' || c == '\t' || c == '\n');
		ungetc(c, stdin);
		for (i = 0; (c = getchar()) != EOF && c != '\n' && c != '.'; i++) {
			if ((c >= '0' && c <= '9') || c == '+' || c == '-')
				a[i] = c;
			else {
				ungetc(c, stdin);
				break;
			}
		}
		if (c == '.') {
			a[i++] = c;
			for (; (c = getchar()) != EOF && c != '\n'; i++) {
				if (c >= '0' && c <= '9')
					a[i] = c;
				else {
					ungetc(c, stdin);
					break;
				}
			}
			a[i] = '\0';
			double *db = (double *)arg;
			*db = atof(a);
		}
		else {
			if (i > 0) {
				a[i] = '\0';
				double *db = (double *)arg;
				*db = atof(a);
			}
		}
		successfull_reads++;
		break;
	default:
		printf("Something went wrong\n");
		return -1;
	}
	return successfull_reads;
}

int main(void) {
	int i = 5;
	myscanf("%d", &i);
	float f = 6.3;
	myscanf("%f", &f);
	printf("%d %f\n", i, f);
        return 0;
}
