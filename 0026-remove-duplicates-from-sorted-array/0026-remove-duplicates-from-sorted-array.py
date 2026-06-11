class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l = len(nums)
        i = 0
        cnt = 1
        for j in range(1,l):
            temp = nums[i]
            if(nums[j] != nums[i]):
                nums[i+1] = nums[j]
                i+=1
                cnt +=1
        return cnt