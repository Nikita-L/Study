// gcc -W -Wall -O2 -std=c99 -fopenmp lab5.c
#include <stdio.h>
#include <omp.h>

int main() {
  char a = 'a';
  //char b = 'b';
  char good[] = 2*a;
  printf("%s\n", good);

  // int x = 42;
  // #pragma omp parallel
  // if(x < 0) num_threads(100)
  // printf("part 1\n");
  // #pragma omp parallel
  // if(x > 0) num_threads(3)
  // printf("part 2\n");
  // #pragma omp parallel
  // num_threads(3)
  // printf("part 3\n");
  // #pragma omp parallel
  // printf("part 4\n");
  // return 0;
}