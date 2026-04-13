class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        minDis = 100000
        for i in range(len(nums)):
            if nums[i] == target:
                dis = abs(i-start)
                if dis < minDis:
                    minDis = dis
        return minDis