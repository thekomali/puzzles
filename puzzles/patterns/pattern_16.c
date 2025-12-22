#include <stdio.h>
#include <stdlib.h>

/*
The Number Pattern
======================
4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4
======================
*/

int main(int argc, char *argv[]) {
  // get the number from the command line
  int num = atoi(argv[1]);

  // we are printing a square matrix of size rows x rows
  // in a concentric manner, which shrinks to center with number 1

  // loop 1 -> 0 to 2n - 1
  //   loop 2 -> 0 to 2n - 1
  //
  // For each position (i, j), compute its distance from all four edge,
  //      from_top_edge = i
  //      from_bottom_edge = (2n - 1) - 1 - i
  //      from_left_edge = j
  //      from_right_edge = (2n - 1) - 1 - j
  //
  // find the minimum of these four distances, this will determine
  //   how deep the current position is.
  // Print (n - minDistance), as our shape is concentric circles

  // no of rows = (input_no * 2) - 1
  int rows = (num * 2) - 1;

  int from_bottom_edge, from_top_edge;
  int from_left_edge, from_right_edge;
  int min1, min2, min;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      from_top_edge = i;
      from_bottom_edge = rows - 1 - i;
      from_left_edge = j;
      from_right_edge = rows - 1 - j;

      // find the min of these four distances
      min1 = from_top_edge < from_bottom_edge ? from_top_edge : from_bottom_edge;
      min2 = from_left_edge < from_right_edge ? from_left_edge : from_right_edge;
      min = min1 < min2 ? min1 : min2;

      // printing the value
      printf("%d ", num - min);
    }

    printf("\n");
  }


  return 0;
}