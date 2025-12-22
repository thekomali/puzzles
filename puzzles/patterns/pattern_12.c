#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Number Crown Pattern
======================
1                 1 
1 2             2 1 
1 2 3         3 2 1 
1 2 3 4     4 3 2 1 
1 2 3 4 5 5 4 3 2 1
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  // loop 1 - for row
  //   loop 2 - for printing left triangle
  //   loop 3 - for printing space
  //   loop 4 - for printing right triangle

  for (int r = 1; r <= rows; r++) {
    // LEFT TRIANGLE
    for (int lt = 1; lt <= r; lt++)
      printf("%d ", lt);

    // SPACES
    // total width = rows * 2
    // spaces needed at any given row = total_width - (r * 2)
    for (int s = 1; s <= (rows * 2) - (r * 2); s++)
      printf("  ");

    // RIGHT TRIANGLE
    for (int rt = r; rt > 0; rt--) 
      printf("%d ", rt);

    printf("\n");
  }

  return 0;
}