// problem -> https://leetcode.com/problems/single-number/

// time complexity  -> O(N)
// space complexity -> O(1)

int singleNumber(int* nums, int numsSize) {
  int missing = 0;

  // XOR of two same numbers is zero
  // XOR of 0 and a number is the number

  for (int i = 0; i < numsSize; i++)
    missing ^= nums[i];

  return missing;    
}