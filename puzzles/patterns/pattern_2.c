#include <stdio.h>
#include <stdlib.h>

/*
Right-Angled Triangle Pattern
======================
* 
* *
* * *
* * * *
* * * * *
======================
*/

int main(int argc, char *argv[]) {
  // get the row number from the command line
  int rows = atoi(argv[1]);

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c <= r; c++)
      printf("* ");
    
    printf("\n");
  }

  return 0;
}