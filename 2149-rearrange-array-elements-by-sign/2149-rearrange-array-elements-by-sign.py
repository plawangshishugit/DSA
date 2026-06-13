class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        l = len(nums)
        ans = [0] * l
        pos =0
        neg = 1
        for num in nums:
            if(num > 0):
                ans[pos] = num
                pos += 2
            else:
                ans[neg] = num
                neg += 2
        return ans