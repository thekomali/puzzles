#include <stdio.h>
#include <stdlib.h>

/*
======================
*****
****
***
**
*
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  for (int r = 0; r < rows; r++) {
    for (int c = rows - r; c > 0; c--)
      printf("*");
    
    printf("\n");
  }

  return 0;
}