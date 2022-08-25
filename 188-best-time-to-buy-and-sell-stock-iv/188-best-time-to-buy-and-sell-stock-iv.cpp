class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (k == 0 or prices.size() == 0) return 0;
		vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0));
		vector<int> minBuyingCost(prices.size());
		for (int transaction = 1; transaction <= k; ++transaction) {
			for (int day = 0; day < prices.size(); ++day) {
				if (day == 0) {
					minBuyingCost[day] = -prices[day];
					continue;
				}

				dp[transaction][day] = max(dp[transaction][day], dp[transaction][day - 1]);
				dp[transaction][day] = max(dp[transaction][day], minBuyingCost[day - 1] + prices[day]);
				minBuyingCost[day] = max(minBuyingCost[day - 1], dp[transaction - 1][day - 1] - prices[day]);
			}
		}
		return dp[k][prices.size() - 1];
	}
};