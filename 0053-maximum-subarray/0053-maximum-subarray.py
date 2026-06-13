class Solution:
    def maxSubArray(self, nums):
        maxi = float('-inf')
        curr_sum = 0

        for num in nums:
            curr_sum += num
            maxi = max(maxi, curr_sum)

            if curr_sum < 0:
                curr_sum = 0

        return maxi