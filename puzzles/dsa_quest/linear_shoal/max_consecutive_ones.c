// problem -> https://leetcode.com/problems/max-consecutive-ones/description

// time complexity  -> O(N)
// space complexity -> O(1)

int findMaxConsecutiveOnes(int* nums, int numsSize) {
  int max_consec = 0;
  int one_cnt = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 1) {
      one_cnt++;
    } else {
      // verify the one_cnt is greater than max_consec
      if (one_cnt > max_consec)
        max_consec = one_cnt;
      
      // reset the one_cnt for counting next group of 1's
      one_cnt = 0;
    }
  }

  // final comparison in case the array ends with 1's
  return one_cnt > max_consec ? one_cnt : max_consec;  
}