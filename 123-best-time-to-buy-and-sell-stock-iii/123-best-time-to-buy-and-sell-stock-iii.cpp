class Solution {
public:
	int dp[100001][2][3];

	int maxProfit(vector<int>& prices) {
		for (int i = 0; i < prices.size(); ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 3; ++k) {
					dp[i][j][k] = -1;
				}
			}
		}
		return maxProfit(prices, 0, 0, 0);
	}

	int maxProfit(vector<int> &prices, int index, int hold, int transactions) {
		if (transactions >= 2) return 0;
		if (index == prices.size()) return 0;
		if (dp[index][hold][transactions] != -1) return dp[index][hold][transactions];
		int &ans = dp[index][hold][transactions];
		ans = 0;
		if (hold) {
			int sell = maxProfit(prices, index + 1, 1 - hold, transactions + 1) + prices[index];
			int notSell = maxProfit(prices, index + 1, hold, transactions);
			return ans = max(sell, notSell);
		} else {
			int buy = maxProfit(prices, index + 1, 1, transactions) - prices[index];
			int notBuy = maxProfit(prices, index + 1, 0, transactions);
			return ans = max(buy, notBuy);
		}
	}
};