// problem -> https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// time complexity  -> O(N)
// space complexity -> O(1)

int removeDuplicates(int* nums, int numsSize) {
  // pointer - 'i' for comparing values
  // pointer - 'j' for swaping values

  int i = 1, j = 1;  // since the initial values is always unique
                     // that's why we are starting j at 1

  while (i < numsSize) {
    // if the values don't match
    //  - swap the element from i's position to j's position
    //  - increment the j pointer
    // on each iteration, increment the i pointer
  
    if (nums[i - 1] != nums[i]) {
      nums[j++] = nums[i];
    }

    // update the pointer for comparing
    i++;
  }

  return j;
}