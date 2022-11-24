def solve(index, hold, transaction, k, prices, dp):
    if transaction >= k:
        return 0
    if index >= len(prices):
        return 0
    if dp[index][hold][transaction] != -1:
        return dp[index][hold][transaction]
    dp[index][hold][transaction] = 0
    if hold == 1:
        keepHolding = solve(index + 1, hold, transaction, k, prices, dp)
        sell = solve(index + 1, 0, transaction + 1, k, prices, dp) + prices[index]
        dp[index][hold][transaction] = max(keepHolding, sell)
    else:
        buy = solve(index + 1, 1, transaction, k, prices, dp) - prices[index]
        dontBuy = solve(index + 1, 0, transaction, k, prices, dp)
        dp[index][hold][transaction] = max(buy, dontBuy)
    return dp[index][hold][transaction]


class Solution(object):
    def maxProfit(self, k, prices):
        n = len(prices)
        dp = [[[-1 for _ in range(k + 1)] for _ in range(2)] for _ in range(n)]
        return solve(0, 0, 0, k, prices, dp)

