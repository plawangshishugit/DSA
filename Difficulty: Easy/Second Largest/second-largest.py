class Solution:
    def getSecondLargest(self, arr):
        lar = -1
        slr = -1

        for num in arr:
            if num > lar:
                slr = lar
                lar = num
            elif num > slr and num != lar:
                slr = num

        return slr