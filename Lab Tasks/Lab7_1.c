#include <stdio.h>

int main(void)
{
	char shape, oper; float b, h, s1, s2, s3, r;
	int result = scanf(" %c %c", &shape, &oper);

	if (result != 2 || (oper != 'a' && oper != 'p')) {
		printf("error\n");
		return 0;
	}
	switch (shape) {
	case 't':
		if (oper == 'a') {
			result = scanf("%f %f", &b, &h);
			if (result == 2)
				printf("%.2f\n", (b * h) / 2);
			else
				printf("error\n");
		} else if (oper == 'p') {
			result = scanf("%f %f %f", &s1, &s2, &s3);
			if (result == 3)
				printf("%.2f\n", s1 + s2 + s3);
			else
				printf("error\n");
		} else {
			printf("error\n");
		}
		break;
	case 'r':
		result = scanf("%f %f", &b, &h);
		if (result == 2) {
			if (oper == 'a')
				printf("%.2f\n", b * h);
			else if (oper == 'p')
				printf("%.2f\n", 2 * (b + h));
			else
				printf("error\n");
		} else {
			printf("error\n");
		}
		break;
	case 's':
		result = scanf("%f", &b);
		if (result == 1) {
			if (oper == 'a')
				printf("%.2f\n", b * b);
			else if (oper == 'p')
				printf("%.2f\n", 4 * b);
			else
				printf("error\n");
		} else {
			printf("error\n");
		}
		break;
	case 'c':
		result = scanf("%f", &r);
		if (result == 1) {
			if (oper == 'a')
				printf("%.2f\n", 3.14 * r * r);
			else if (oper == 'p')
				printf("%.2f\n", 2 * 3.14 * r);
			else
				printf("error\n");
		} else {
			printf("error\n");
		}
		break;
	default:
		printf("error\n");
		break;
	}
	return 0;
}
