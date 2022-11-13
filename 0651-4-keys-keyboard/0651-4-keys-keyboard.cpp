class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i - 2; ++j) {
                dp[i] = max(dp[i], dp[j] * (i - (j + 2) + 1));
            }
        }
        return dp[n];
    }
};