class Solution {
public:
    int waysToDistribute(int n, int k) {
        const long long mod = 1e9 + 7;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0LL));
        for (int i = 1; i <= k; ++i) {
            dp[i][i] = 1;
        }
        for (int i = 1; i <= k; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                dp[i][j] = ((dp[i][j - 1] * i) % mod + dp[i - 1][j - 1]) % mod;
            }
        }
        return dp[k][n];
    }
};