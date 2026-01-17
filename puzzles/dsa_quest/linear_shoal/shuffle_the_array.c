// problem -> https://leetcode.com/problems/shuffle-the-array/description/

// time complexity -> O(N)
// space complexity -> O(N)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
  // create new array to hold the shuffled elements
  int *shuffled = (int *)malloc(sizeof(int) * numsSize);
  if (!shuffled) return NULL;

  for (int i = 0, s = 0; i < n; i++) {
    shuffled[s++] = nums[i];
    shuffled[s++] = nums[i + n];
  }

  *returnSize = numsSize;
  return shuffled;
}