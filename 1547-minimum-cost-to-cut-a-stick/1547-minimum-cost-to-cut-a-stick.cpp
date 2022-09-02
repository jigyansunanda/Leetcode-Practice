class Solution {
public:

	int dp[102][102];

	int minCost(int n, vector<int>& cuts) {
		memset(dp, -1, sizeof dp);
		sort(cuts.begin(), cuts.end());
		return solve(cuts, 0, cuts.size() - 1, 0, n);
	}

	int solve(vector<int>& cuts, int l, int r, int start, int end) {
		if (l > r) return 0;
		if (dp[l][r] != -1) return dp[l][r];
		int& ans = dp[l][r];
		ans = INT_MAX;
		int currCost = end - start;
		for (int i = l; i <= r; ++i) {
			int subans = currCost + solve(cuts, l, i - 1, start, cuts[i]) + solve(cuts, i + 1, r, cuts[i], end);
			ans = min(ans, subans);
		}
		return ans;
	}
};