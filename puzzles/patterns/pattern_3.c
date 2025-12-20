#include <stdio.h>
#include <stdlib.h>

/*
======================
1
12
123
1234
12345
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  for (int r = 1; r <= rows; r++) {
    for (int c = 1; c <= r; c++)
      printf("%d", c);
    
    printf("\n");
  }

  return 0;
}