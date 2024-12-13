#include <stdio.h>
#define SIZE 16
struct student {
	int mis;
	char name[32];
	float marks;
};
typedef struct student student;

int tersearch_mis(student a[], int len, int mis) {
	int l = 0, h = len -1, m1, m2;
	while(l < h) {
		m1 = (l + h)/ 3;
		m2 = (2 * (l + h)) / 3;
		if(a[m1].mis == mis)
			return m1;
		else if(a[m2].mis == mis)
			return m2;
		else if(a[m1].mis > mis)
			h = m1 - 1;
		else if(a[m1].mis < mis && a[m2].mis > mis) {
			l = m1 + 1;
			h = m2 - 1;
		}
		else
			l = m2 + 1;
	}
	return -1;
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
