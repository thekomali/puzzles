#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Increasing Number Triangle Pattern
======================
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  int to_print = 1;

  for (int r = 1; r <= rows; r++) {
    for (int c = 1; c <= r; c++, to_print++) {
      printf("%d ", to_print);
    }

    printf("\n");
  }

  return 0;
}