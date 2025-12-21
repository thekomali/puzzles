#include <stdio.h>
#include <stdlib.h>

/*
======================
Right-Angled Number Pyramid - II
1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  for (int r = 1; r <= rows; r++) {
    for (int c = 1; c <= r; c++)
      printf("%d ", r);
    
    printf("\n");
  }

  return 0;
}