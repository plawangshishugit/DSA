class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l = len(nums)
        start = 0
        end = l-1
        while(start<end):
            mid = start + (end -start)//2
            if(mid % 2 != 0):
                mid -= 1
            if(nums[mid] == nums[mid + 1]):
                start = mid + 2
            else:
                end = mid
        return nums[start]