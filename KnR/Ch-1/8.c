#include <stdio.h>

int main() {
  int ch, bl=0, nl=0, tab=0;
  while ((ch = getchar()) != EOF) {
    if (ch == ' ') {
      ++bl;
    }
    if (ch == '\n') {
      ++nl;
    }
    if (ch == '\t') {
      ++tab;
    }
    if (ch == '\0') {
      break;
    }
  }
  printf("\nblanks : %d\n", bl);
  printf("tabs: %d\n", tab);
  printf("newlines : %d\n", nl);
  return 0;
}
