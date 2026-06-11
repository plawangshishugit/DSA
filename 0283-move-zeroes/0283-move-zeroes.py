class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        i =0
        cnt =0
        for num in nums:
            if (num != 0):
                nums[i] = num
                i+=1
                cnt += 1
        for i in range(cnt,l):
            nums[i] = 0