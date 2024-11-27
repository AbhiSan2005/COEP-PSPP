/* Write a function that locates a given string (b) as a substring in another string (a), and returns a pointer to the first occurrence of b, in a.
* char *strstr(char *a, char *b);
* e.g. if  a is "abhijit is here" and b is "is" , then the function returns a pointer to "i" of "is" in a 
*/
#include <stdio.h>
char *strstr(char *a, char *b) {
	for (char *p = a; *p != '\0'; p++) {
        char *p1 = p;
        char *p2 = b;
        for (; *p1 == *p2 && *p2 != '\0'; p1++, p2++);
        if (*p2 == '\0')
            return p;
	}
	return NULL;
}

int main(void)
{
	char *a = "abhijit is here";
	char *b = "is";
	char *p = strstr(a,b);
	printf("%c", *p);
	return 0;
}
