'''
We need to find the largest peak following the smallest valley. 
We can maintain two variables - minprice and maxprofit corresponding 
to the smallest valley and maximum profit 
(maximum difference between selling price and minprice) obtained so far respectively.'''

import sys
class Solution:
    def maxProfit(self, prices):
        min_price = sys.maxsize
        max_profit = 0
        for i in range(len(prices)):
            if min_price>prices[i]:
                min_price = prices[i]
            elif max_profit < prices[i]-min_price:
                max_profit = max(max_profit, prices[i]-min_price)

        return max_profit

sol = Solution()
prices_list = list(map(int, input().split()))
print(sol.maxProfit(prices_list))

        