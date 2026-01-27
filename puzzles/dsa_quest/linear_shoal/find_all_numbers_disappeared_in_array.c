// problem -> https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// time complexity  -> O(n)
// space complexity -> O(1)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
  // array to hold the missing numbers (assume size to be numsSize)
  int *missing = (int *)malloc(sizeof(int) * numsSize);
  if (!missing) return NULL;

  int miss_id = 0;

  // no extra space is used to identify the missing entry
  // so how to track a number that is present?

  // TIP 
  // - elements in the array is in the range -> 1 to n
  // - index of array is in range -> 0 to n-1

  // so, if a element is present in the array, to mark that
  // go to that index and make the value to negative of same number

  // if we are visiting the negative value element, then get the abs value
  // of that element and mark it's presence by going to that index


  // marking the element's presence
  for (int i = 0; i < numsSize; i++) {
    // if element is negative, then make it positive (absolute value)
    int id = (nums[i] < 0 ? -nums[i] : nums[i]) - 1;

    // to mark the presence of this element, let's go to the index (denoted by element)
    // then make the value as negative. If it's already made negative - ignore it
    if (nums[id] > 0)
      nums[id] = -nums[id];
  }

  // let's iterate the array again
  // if the value at an index is not negative, then that index number
  // is not present in the array as element
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > 0)
      missing[miss_id++] = i + 1;
  }

  *returnSize = miss_id;
  return missing;
}
