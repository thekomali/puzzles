#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// time complexity  -> O(N)
// space complexity -> O(1)
int* find_second_small_nd_large(int *arr, int size) {
  // array to hold second smallest and largest
  int *ans = (int *)calloc(2, sizeof(int));
  if (!ans) return NULL;

  if (size < 2) return ans;

  int large = INT_MIN, slarge = INT_MIN;
  int small = INT_MAX, ssmall = INT_MAX;

  for (int i = 0; i < size; i++) {
    // LARGE PART //
    if (arr[i] > large) {
      slarge = large;     // current large become second large
      large = arr[i];     // new large
    }
    else if (arr[i] > slarge && arr[i] != large)      
      slarge = arr[i];   // only update the second large

    // SMALL PART //
    if (arr[i] < small) {
      ssmall = small;   // current small become second small
      small = arr[i];   // new small
    }
    else if (arr[i] < ssmall && arr[i] != small)
      ssmall = arr[i];  // only update the second small
  }

  ans[0] = slarge;
  ans[1] = ssmall;

  return ans;
}







int main() {
  int arr[] = {1, 2, 4, 7, 7, 5};

  int *res = find_second_small_nd_large(arr, 6);

  printf("second large => %d, second small => %d\n", res[0], res[1]);

  return 0;


}


