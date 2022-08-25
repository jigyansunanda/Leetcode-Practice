class Solution {
public:
	int dp[1001][101][2];

	int maxProfit(int k, vector<int>& prices) {
		memset(dp, -1, sizeof dp);
		return maxProfit(prices, k, 0, 0, 0);
	}

	int maxProfit(vector<int> &prices, int k, int index, int hold, int transaction) {
		if (transaction >= k) return 0;
		if (index == prices.size()) return 0;
		if (dp[index][transaction][hold] != -1) return dp[index][transaction][hold];
		int &ans = dp[index][transaction][hold];
		if (hold) {
			int sell = maxProfit(prices, k, index + 1, 0, transaction + 1) + prices[index];
			int notSell = maxProfit(prices, k, index + 1, 1, transaction);
			ans = max(sell, notSell);
		} else {
			int buy = maxProfit(prices, k, index + 1, 1, transaction) - prices[index];
			int notBuy = maxProfit(prices, k, index + 1, 0, transaction);
			ans = max(buy, notBuy);
		}
		return ans;
	}
};