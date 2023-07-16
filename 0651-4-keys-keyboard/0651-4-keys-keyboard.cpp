class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 1; j + 2 < i; ++j) {
                int prev = dp[j - 1];
                int total = prev * (i - (j + 2) + 1);
                dp[i] = max(dp[i], dp[j - 1] + total);
            }
        }
        return dp[n];
    }
};