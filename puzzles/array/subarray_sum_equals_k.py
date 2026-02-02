# problem -> https://leetcode.com/problems/subarray-sum-equals-k/description/

# time complexity - O(N)
# space complexity - O(N)

class Solution:
  def subarraySum(self, nums: List[int], k: int) -> int:
    # sum(i) - sum of all elements till i'th index
    # sum(j) - sum of all elements till j'th index
    #
    # sum(j) - sum(i) = k, what it means is that,
    #                      the sum of elements b/w i'th and j'th
    #                      index is equals to k
    # 
    # rewriting the equation,
    # sum(j) = k + sum(i)
    # sum(j) - k = sum(i)  <----- based on this equation we solve the problem

    # TRICK:
    #  - use hash table to keep the record of sum(i) and it frequency
    #  - on every loop calculate sum(j)
    #  - substract it with k and see if the result is in hash table
    #  - if found, then we found a subarray - update the subarr_cnt
    #  - if not, then update the new sum in the hash table and set it's frequency to 1

    record = {0: 1}
    sum = 0
    subarr_cnt = 0

    for num in nums:
      sum += num

      # check if the sum is present in hashtable
      if sum - k in record:
        subarr_cnt += record[sum - k]
      
      # update the hashtable with the sum
      if sum not in record:
        record[sum] = 1
      else:
        record[sum] += 1
    
    return subarr_cnt