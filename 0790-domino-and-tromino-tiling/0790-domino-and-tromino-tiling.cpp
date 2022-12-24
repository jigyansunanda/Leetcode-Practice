class Solution {
public:
    const long long mod = 1e9 + 7;
    int numTilings(int n) {
        vector<long long> dp(n + 1, 0LL);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = (dp[i] + dp[i - 1]) % mod;
            if (i >= 2) {
                dp[i] = (dp[i] + dp[i - 2]) % mod;
            }
            if (i >= 3) {
                dp[i] = (dp[i] + (2 * dp[i - 3]) % mod) % mod;
            }
            for (int j = 0; j <= i; ++j) {
                if ((i - j) % 2 == 0 and (i - j) >= 4) {
                    dp[i] = (dp[i] + (2 * dp[j]) % mod) % mod;
                }
                if ((i - j) % 2 == 1 and (i - j) >= 5) {
                    dp[i] = (dp[i] + (2 * dp[j]) % mod) % mod;
                }
            }
        }
        return dp[n];
    }
};