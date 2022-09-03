class Solution {
public:

	int palindromePartition(string s, int k) {
		int n = s.size();
		int dp1[n][n]; // dp1[i][j] = min number of changes to make s[i,j] palindrome
		for (int i = 0; i < n; ++i) dp1[i][i] = 0;
		for (int i = 0; i + 1 < n; ++i) dp1[i][i + 1] = (s[i] != s[i + 1]);
		for (int len = 3; len <= n; ++len) {
			for (int i = 0; i + len - 1 < n; ++i) {
				dp1[i][i + len - 1] = (s[i] != s[i + len - 1]) + dp1[i + 1][i + len - 2];
			}
		}
		vector<vector<int>> dp2(k + 1, vector<int>(n, INT_MAX));
		// dp2[i][j] = min number of changes to make i disjoint palindromes from s[0,j]
		for (int i = 0; i < n; ++i) dp2[0][i] = 0;
		for (int i = 0; i < n; ++i) dp2[1][i] = dp1[0][i];
		for (int p = 2; p <= k; ++p) {
			for (int i = p - 1; i < n; ++i) {
				dp2[p][i] = INT_MAX;
				for (int j = 0; j < i; ++j) {
					if (dp2[p - 1][j] != INT_MAX) {
						dp2[p][i] = min(dp2[p][i], dp2[p - 1][j] + dp1[j + 1][i]);
					}
				}
			}
		}
		return dp2[k][n - 1];
	}
};