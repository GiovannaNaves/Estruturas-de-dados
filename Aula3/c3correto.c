#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  int i;
  int *a;

    a = malloc(sizeof(int) * 1000);
  free(a);
  return 0;
}

