class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if (n == 0) return 0;
        int[][][] dp = new int[n][2][2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return maxProfit(prices, 0, 0, 0, dp);
    }

    private int maxProfit(int[] prices, int day, int isHold, int isCooldown, int[][][] dp) {
        if (day == prices.length) return 0;
        if (dp[day][isHold][isCooldown] != -1) return dp[day][isHold][isCooldown];
        if (isHold == 0) {
            if (isCooldown == 0) {
                int notBuy = maxProfit(prices, day + 1, 0, 0, dp);
                int buy = maxProfit(prices, day + 1, 1, 0, dp) - prices[day];
                return dp[day][isHold][isCooldown] = Math.max(notBuy, buy);
            } else {
                return dp[day][isHold][isCooldown] = maxProfit(prices, day + 1, 0, 0, dp);
            }
        } else {
            if (isCooldown == 1) {
                return dp[day][isHold][isCooldown] = maxProfit(prices, day + 1, 0, 0, dp);
            } else {
                int notSell = maxProfit(prices, day + 1, 1, 0, dp);
                int sell = maxProfit(prices, day + 1, 0, 1, dp) + prices[day];
                return dp[day][isHold][isCooldown] = Math.max(notSell, sell);
            }
        }
    }
}