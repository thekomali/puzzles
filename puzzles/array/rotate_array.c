// problem -> https://leetcode.com/problems/rotate-array/description/

// time complexity  -> O(N)
// space complexity -> O(1)

void reverse(int *arr, int start, int end) {
  int left = start;
  int right = end;
  int tmp;

  while (left <= right) {
    tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;

    left++;
    right--;    
  }
}

void rotate(int* nums, int numsSize, int k) {
  // 1. reverse the whole array
  // 2. reverse the array from start to k-1
  // 2. reverse the array from k to numsSize-1

  if (numsSize == 1) return;

  // if k larger than numsSize, let make to be in range of numsSize
  k = k % numsSize;

  // reverse the whole array
  reverse(nums, 0, numsSize - 1);
  
  // reverse front part (0 to k-1)
  reverse(nums, 0, k-1);

  // reverse rear part (k, numsSize - 1)
  reverse(nums, k, numsSize - 1);  
}