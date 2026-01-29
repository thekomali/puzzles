// problem -> https://leetcode.com/problems/move-zeroes/

// time complexity  -> O(N)
// space complexity -> O(1)

void moveZeroes(int* nums, int numsSize) {
  // use two pointer approach to solve it

  // rptr - move over the array & lptr points the positon to swap
  int rptr = 0, lptr = 0;
  int tmp;

  while (rptr < numsSize) {
    if (nums[rptr] != 0) {
      // let's swap this non-zero value with positon pointer by lptr
      tmp = nums[rptr];
      nums[rptr] = nums[lptr];
      nums[lptr] = tmp;

      lptr++;
    }

    rptr++;
  }
    
}