#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Symmetric-Void Pattern
======================
* * * * * * * * * * 
* * * *     * * * * 
* * *         * * * 
* *             * * 
*                 * 
*                 * 
* *             * * 
* * *         * * * 
* * * *     * * * * 
* * * * * * * * * * 
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  // loop 1 - iterate rows
  //   loop 2 - print left symbol
  //   loop 3 - print spaces
  //   loop 4 - print right symbol

  // UPPER HALF
  for (int r = 0; r < rows; r++) {
    // print left symbol
    for (int ls = rows - r; ls > 0; ls--)
      printf("* ");

    // print spaces
    for (int s = 0; s < (2 * r); s++)
      printf("  ");

    // print right symbol
    for (int rs = rows - r; rs > 0; rs--)
      printf("* ");

    printf("\n");
  }


  // LOWER HALF (inverted upper half)
  for (int r = 1; r <= rows; r++) {
    // print left symbol
    for (int lt = 1; lt <= r; lt++)
      printf("* ");

    // SPACES
    // total width = rows * 2
    // spaces needed at any given row = total_width - (r * 2)
    for (int s = 1; s <= (rows * 2) - (r * 2); s++)
      printf("  ");

    // RIGHT TRIANGLE
    for (int rt = r; rt > 0; rt--) 
      printf("* ");

    printf("\n");
  }


  return 0;
}