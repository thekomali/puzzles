#include <stdio.h>
#include <stdlib.h>

/*
======================
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  for (int r = 1; r <= rows; r++) {
    for (int c = 1; c <= r; c++)
      printf("%d ", c);
    
    printf("\n");
  }

  return 0;
}