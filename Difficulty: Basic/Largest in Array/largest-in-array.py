class Solution:
    def largest(self, arr):
        # code here
        l = len(arr)
        maxNum = arr[0]
        for i in range(l):
            if (arr[i] > maxNum):
                maxNum = arr[i]
                
        return maxNum
