#include <stdio.h>
#include <stdlib.h>

/*
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

  // UPPER HALF
  for (int r = 0; r < rows; r++) {
    // printing spaces
    for (int s = rows - r - 1; s > 0; s--)
      printf("  ");          // two spaces as we are adding once space after '*'

    // printing symbols
    for (int c = 0; c < (2 * r + 1); c++)
      printf("* ");       

    printf("\n");
  }

  // LOWER HALF
  // as it's inverted triangle, start from highest and decerment it
  for (int r = rows - 1; r >= 0; r--) {
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