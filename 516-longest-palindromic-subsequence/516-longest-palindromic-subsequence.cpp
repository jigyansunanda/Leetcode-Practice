/*                    Recursive Solution

class Solution {
public:

	int dp[1001][1001];

	int longestPalindromeSubseq(string s) {
		memset(dp, -1, sizeof dp);
		return solve(s, 0, s.size() - 1);
	}

	int solve(string &s, int L, int R) {
		if (L > R) return 0;
		if (L == R) return 1;
		if (dp[L][R] != -1) return dp[L][R];
		int &ans = dp[L][R];
		if (s[L] == s[R]) ans = 2 + solve(s, L + 1, R - 1);
		else ans = max(solve(s, L + 1, R), solve(s, L, R - 1));
		return ans;
	}
};

*/


class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) {
			dp[i][i] = 1;
		}
		for (int i = 0; i + 1 < n; ++i) {
			dp[i][i + 1] = (s[i] == s[i + 1]) ? 2 : 1;
		}
		for (int len = 3; len <= n; ++len) {
			for (int i = 0; i + len <= s.size(); ++i) {
				int j = i + len - 1;
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				} else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][n - 1];
	}
};
