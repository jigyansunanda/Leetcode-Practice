/*

1. O(n * k) solution (top-down dp, recursion with memoization)

class Solution {
public:
	int dp[1001][2][101];
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		memset(dp, -1, sizeof dp);
		return maxProfit(prices, 0, 0, k);
	}

	int maxProfit(vector<int>& prices, int index, int hold, int k) {
		if (k == 0) return 0;
		if (index == prices.size()) return 0;
		if (dp[index][hold][k] != -1) return dp[index][hold][k];
		int& ans = dp[index][hold][k];
		ans = 0;
		if (hold) {
			int sell = prices[index] + maxProfit(prices, index + 1, 0, k - 1);
			int keepHolding = maxProfit(prices, index + 1, hold, k);
			ans = max(sell, keepHolding);
		} else {
			int buy = -prices[index] + maxProfit(prices, index + 1, 1, k);
			int dontBuy = maxProfit(prices, index + 1, 0, k);
			ans = max(buy, dontBuy);
		}
		return ans;
	}
};


2. O(k * n * n) solution without optimization (bottom - up dp)
Here dp[i][j] = max profit with at max i number of transactions till day j

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (k == 0 or prices.size() == 0) return 0;
		int n = prices.size();
		vector<vector<int>> dp(k + 1, vector<int>(n, 0));
		for (int t = 1; t <= k; ++t) {
			for (int i = 0; i < n; ++i) {
				if (i) dp[t][i] = dp[t][i - 1];
				for (int j = 0; j < i; ++j) {
					int buyAtJ = prices[j];
					int sellAtI = prices[i];
					int profit = sellAtI - buyAtJ +
								 ((j >= 1) ? dp[t - 1][j - 1] : 0);
					dp[t][i] = max(dp[t][i], profit);
				}
			}
		}
		return dp[k][n - 1];
	}
};

*/

class Solution {
public:
	// O(k * n) solution (bottom - up optimized dp)
	// dp[t][i] = max profit with at max t number of transactions till day i

	int maxProfit(int k, vector<int>& prices) {
		if (k == 0 or prices.size() == 0) return 0;
		int n = prices.size();
		vector<vector<int>> dp(k + 1, vector<int>(n, 0));
		vector<int> minBuyingCost(n);
		for (int t = 1; t <= k; ++t) {
			for (int i = 0; i < n; ++i) {
				if (i == 0) {
					minBuyingCost[i] = -prices[0];
					continue;
				}
				dp[t][i] = dp[t][i - 1];  // don't do anything on i-th day
				dp[t][i] = max(dp[t][i], prices[i] + minBuyingCost[i-1]);
				minBuyingCost[i] = max(minBuyingCost[i-1], dp[t-1][i-1] - prices[i]);
			}
		}
		return dp[k][n - 1];
	}
};