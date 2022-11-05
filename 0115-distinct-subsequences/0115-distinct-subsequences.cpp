class Solution {
public:
    using ll = unsigned long long;
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0));
        // dp[i][j] = # of distinct subsequences of s[0, i] that equals t[0, j]
        for (int i = 0; i < m + 1; ++i) dp[i][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};