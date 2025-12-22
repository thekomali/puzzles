#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Hollow Rectangle Pattern
======================
* * * * * 
*       * 
*       * 
*       * 
* * * * * 
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  for (int r = 0; r < rows; r++) {
    // special treatment for first and last row
    if (r == 0 || r == rows - 1) {
      for (int c = 0; c < rows; c++)
        printf("* ");
    }
    else {
      // print left symbol
      printf("* ");

      // print spaces
      for (int c = 1; c < rows - 1; c++)
        printf("  ");
      
      // print right symbol
      printf("* ");
    }

    printf("\n");
  }

  return 0;
}