#include <stdio.h>
#define SIZE 16
struct student {
	int mis;
	char name[32];
	float marks;
};
typedef struct student student;
void print_records(student a[], int len) {
	int i;
	printf("-----array-------\n");
	for(i = 0; i < len; i++)
		printf("%d %s %.2f\n", a[i].mis, 
			a[i].name, a[i].marks);
}
int findithmin(student a[], int len, int i) {
	int min = a[i].mis;
	int minindex = i;
	for(int j = i + 1; j < len; j++)
		if(a[j].mis < min) {
			min = a[j].mis;
			minindex = j;
		}
	return minindex;
}
int findithmax(student a[], int len, int i) {
	int max = a[i].mis;
	int maxindex = i;
	for(int j = i + 1; j < len; j++)
		if(a[j].mis > max) {
			max = a[j].mis;
			maxindex = j;
		}
	return maxindex;
}
void selsort(student a[], int len) {
	student t;
	int min, max;
	for (int i = 0, j = len - 1; j > i; i++, j--) {
		min = findithmin(a, j+1, i);
		max = findithmax(a, j+1, i);
		t = a[i];
		a[i] = a[min];
		a[min] = t;
		t = a[j];
		a[j] = a[max];
		a[max] = t;
	}
	return;
}
int main() {
	student a[SIZE];
	int len = 0;
	while(len < SIZE && scanf("%d%s%f", &a[len].mis, a[len].name,
			&a[len].marks) == 3)
		len++;	
	print_records(a, len);	
	selsort(a, len);
	print_records(a, len);	
	return 0;	
}
