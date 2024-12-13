#include <stdio.h>
#define SIZE 16
struct student {
	int mis;
	char name[32];
	float marks;
};
typedef struct student student;
int tersearch_recur(student a[], int l, int h, int mis) {
	int m1, m2;
	m1 = (l + h) / 3;
	m2 = (2 * (l + h)) / 3;
	if(l > h)
		return -1;
	else if(a[m1].mis == mis)
		return m1;
	else if(a[m2].mis == mis)
		return m2;
	else if(mis < a[m1].mis)
		return tersearch_recur(a, l, m1 - 1, mis);
	else if(mis > a[m1].mis && mis < a[m2].mis)
		return tersearch_recur(a, m1 + 1, m2 - 1, mis);
	else
		return tersearch_recur(a, m2 + 1, h, mis);
}
int tersearch_mis(student a[], int len, int mis) {
	return tersearch_recur(a, 0, len - 1, mis);
}
int main() {
	student a[SIZE];
	int len = 0;
	int mis, ret;	
	scanf("%d", &mis);
	while(len < SIZE && scanf("%d%s%f", &a[len].mis, 
			a[len].name, &a[len].marks) == 3)
		len++;
	ret = tersearch_mis(a, len, mis);
	if(ret == -1) 
		printf("not found\n");
	else
		printf("%d %s %.2f\n", a[ret].mis, a[ret].name, a[ret].marks);
	return 0;	
}
