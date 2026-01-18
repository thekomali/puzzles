// problem -> 

// time complexity  -> O(N logN)
// space complexity -> O(N)


// Comparator function for ascending order
int compare_int_asc(const void* p1, const void* p2) {
    int num1 = *(const int*)p1;
    int num2 = *(const int*)p2;
    // Return a value < 0 if num1 should come before num2, 0 if equal, > 0 otherwise.
    return num1 - num2; 
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
  int *ans = (int *)malloc(sizeof(int) * numsSize);
  if (!ans) return NULL;

  // make a copy of the array befor sorting
  int *num_cp = (int *)malloc(sizeof(int) * numsSize);
  if (!num_cp) return NULL;
  memcpy(num_cp, nums, numsSize * sizeof(int));

  // sort the copied array
  qsort(num_cp, numsSize, sizeof(int), compare_int_asc);

  // make another array to act as a hash table 
  // with size 101 (based on constrains nums[i] is b/w 0 to 100)
  int hash_tb[101];
  memset(hash_tb, -1, sizeof(hash_tb));

  // go through sorted num_cp and update the hash table
  for (int i = 0; i < numsSize; i++) {
    // if index is not -1, then don't reupdate it
    if (hash_tb[num_cp[i]] == -1) 
      hash_tb[num_cp[i]] = i;
  }

  // make final array
  for (int i = 0; i < numsSize; i++) {
    ans[i] = hash_tb[nums[i]];
  }

  free(num_cp);
  free(hash_tb);

  *returnSize = numsSize;
  return ans;    
}