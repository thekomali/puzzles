#include <stdio.h>
#include <stdlib.h>

/*
Star Pyramid
======================
        * 
      * * * 
    * * * * * 
  * * * * * * * 
* * * * * * * * * 
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  for (int r = 0; r < rows; r++) {
    // printing spaces
    for (int s = rows - r - 1; s > 0; s--)
      printf("  ");          // two spaces as we are adding once space after '*'

    // printing symbols
    for (int c = 0; c < (2 * r + 1); c++)
      printf("* ");       

    printf("\n");
  }

  return 0;
}