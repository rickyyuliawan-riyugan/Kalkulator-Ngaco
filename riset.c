#include <stdio.h>
#include <string.h>
#include <math.h>
#define NaN 0

int main() {
  char s[100] = "123";
  float f;

  f = atof(s);
  int c = strlen(s);
  printf("%d", c);
  printf("%f", f);
}
