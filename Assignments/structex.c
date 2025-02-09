#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct course {
	char name[32];
	char course_id[16];
	int credits;
	int type;
	char category[16];
} course;

void print_records(course a[], int n) {
	int sum_all_courses = 0, sum_lab_courses = 0, sum_PCC = 0, sum_HSSC = 0, sum_LC = 0, sum_LLC = 0, sum_OE = 0, sum_DE = 0;
	for (int i = 0; i < n; i++) {
		sum_all_courses += a[i].credits;
		if (a[i].type == 2)
			sum_lab_courses += a[i].credits;
		if (!strcmp(a[i].category,"PCC"))
			sum_PCC += a[i].credits;
		if (!strcmp(a[i].category,"HSSC"))
			sum_HSSC += a[i].credits;
		if (!strcmp(a[i].category,"LC"))
			sum_LC += a[i].credits;
		if (!strcmp(a[i].category,"LLC"))
			sum_LLC += a[i].credits;
		if (!strcmp(a[i].category,"OE"))
			sum_OE += a[i].credits;
		if (!strcmp(a[i].category,"DE"))
			sum_DE += a[i].credits;
	}
	if (n == 0) {
    		printf("0\n0\nPCC 0\nHSSC 0\nLC 0\nLLC 0\nOE 0\nDE 0\n");
    		return;
	}
	printf("%d\n", sum_all_courses);
	printf("%d\n", sum_lab_courses);
	printf("PCC %d\n", sum_PCC);
	printf("HSSC %d\n", sum_HSSC);
	printf("LC %d\n", sum_LC);
	printf("LLC %d\n", sum_LLC);
	printf("OE %d\n", sum_OE);
	printf("DE %d\n", sum_DE);
	return;
}

int read_records(course a[]) {
	int i = 0;
	while(i < 32 && scanf("%s %s%d%d %s", a[i].name, a[i].course_id, &a[i].credits, &a[i].type, a[i].category) != EOF)
		i++;
	return i;
}

int main(void) {
	course data[32];
	int records = read_records(data);
	print_records(data,records);
	return 0;
}
