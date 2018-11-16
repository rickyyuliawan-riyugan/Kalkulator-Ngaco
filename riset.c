#include <stdio.h>
#include <string.h>
#include <math.h>
#define NaN 0
int fun(int *p);
int main() {
  int p = 4;
  int k;

  k = fun(&p);
  printf("%d %d", p, k);
}

int fun(int *p){
  *p++;
  return 3;
}