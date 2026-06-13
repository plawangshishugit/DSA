class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l = len(prices)
        maxProfit = 0
        mini = prices[0]
        for price in prices:
            cost = price - mini
            maxProfit = max(cost, maxProfit)
            mini = min(mini, price)
        return maxProfit