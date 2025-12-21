#include <stdio.h>
#include <stdlib.h>

/*
======================
1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  for (int r = 0; r < rows; r++) {
    for (int c = 1; c <= rows - r; c++)
      printf("%d ", c);

    printf("\n");
  }

  return 0;
}