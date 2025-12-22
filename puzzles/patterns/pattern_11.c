#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Binary Number Triangle Pattern
======================
1 
0 1 
1 0 1 
0 1 0 1 
1 0 1 0 1
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  bool start = false;

  // if row no is odd, start with 1 else start with 0
  for (int r = 1; r <= rows; r++) {
    // identify the start number (either 1 or 0)
    start = r % 2;

    // printing symbols
    for (int c = 1; c <= r; c++) {
      printf("%d ", start);

      // toggle the value
      start = !start;
    }

    printf("\n");
  }

  return 0;
}