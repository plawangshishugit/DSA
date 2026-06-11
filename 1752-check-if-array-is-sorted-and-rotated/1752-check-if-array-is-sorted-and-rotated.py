class Solution:
    def check(self, nums: List[int]) -> bool:
        l = len(nums)
        cnt = 0
        for i in range(l):
            if(nums[i] > nums[(i+1) % l]):
                cnt += 1
        if(cnt >1):
            return False
        else:
            return True