/*
Write a function that finds the maximum length substring of a given string(b) in another string (a) and returns a pointer to the first occurrence of the maximum length substring of b, in a.

char *strmaxstr(char *a, char *b);

e.g. if  a is "abcee abcdf bdefg" and a is "abcdf", then the maximum length substring of b that occurs in a , is "abcd" (as part of "abcdf" ) and hence a pointer to "a" in "abcdf.." of a is returned.
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
