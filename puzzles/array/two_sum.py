# problem -> https://leetcode.com/problems/two-sum

# time complexity -> O(N)
# space complexity -> O(N)

class Solution:
  def twoSum(self, nums: List[int], target: int) -> List[int]:
    # num1 + num2 = target
    # target - num1 = num2
    # 
    # TRICK:
    # use hash table to keep record of num2 and it's index positon
    # use loop to go through nums
    # calculate target - num1
    # if the value result is in hashtable, then we found a pair
    # else update hashtable with num1 and it's index

    record = {}
    sum_pair = []

    for i, num in enumerate(nums):
      t = target - num

      if t in record:
        # update the sum pair
        sum_pair.extend([i, record[t]])
      else:
        # update the record
        record[num] = i

    return sum_pair