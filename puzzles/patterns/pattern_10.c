#include <stdio.h>
#include <stdlib.h>

/*
Half Diamond Star Pattern
======================
* 
* * 
* * * 
* * * * 
* * * * * 
* * * * 
* * * 
* * 
*
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  // UPPER HALF
  for (int r = 1; r <= rows; r++) {
    // print symbols
    for (int c = 1; c <= r; c++)
      printf("* ");

    printf("\n");
  }

  // LOWER HALF
  for (int r = rows - 1; r > 0; r--) {
    // print symbols
    for (int c = r; c > 0; c--)
      printf("* ");

    printf("\n");
  }

  return 0;
}