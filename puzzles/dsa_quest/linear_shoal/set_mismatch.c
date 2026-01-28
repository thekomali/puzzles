// problem -> https://leetcode.com/problems/set-mismatch/

// time complexity  -> O(N)
// space complexity -> O(N)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
  // aray to hold the output
  int *ans = (int *)calloc(2, sizeof(int));
  if (!ans) return NULL;

  // array to mark the presence of elements
  int *presence = (int *)calloc(numsSize, sizeof(int));
  if (!presence) return NULL;

  for (int i = 0; i < numsSize; i++) {
    presence[nums[i] - 1]++;
  }

  for (int i = 0; i < numsSize; i++) {
    if (presence[i] >= 2)
      ans[0] = i + 1;

    if (presence[i] == 0)
      ans[1] = i + 1;
  }

  *returnSize = 2;
  return ans;    
}