class Solution {
public:
	int minInsertions(string s) {
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = 0; i + 1 < n; ++i) dp[i][i + 1] = (s[i] == s[i + 1]) ? 0 : 1;
		for (int len = 3; len <= n; ++len) {
			for (int i = 0; i + len - 1 < n; ++i) {
				int j = i + len - 1;
				if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
				else dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		return dp[0][n - 1];
	}
};