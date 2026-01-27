// problem -> https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

// time complexity  -> O(N)
// space complexity -> O(1)

bool check(int* nums, int numsSize) {
  // use sliding window to solve this problem

  // let's go throught the double the size of array
  // verify if the numbers are in increasing order
  // if not, update the start of sliding window
  // if the no of element crossed matches the size of array, then return true
  // special case:
  //  - if size of array is 1, then return true

  if (numsSize <= 1) return true;

  int count = 1;

  for (int i = 1; i < numsSize * 2; i++) {
    // using % operator in index as we are iterating double the size of array
    // % - will make sure the index always stays within the numsSize
    if (nums[ (i - 1) % numsSize ] <= nums[ i % numsSize ]) {
      count++;

      if (count == numsSize) return true;
    }
    else {
      // we are starting a new slider, so reset the count
      count = 1;
    }
  }

  return false;
}
