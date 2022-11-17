class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = accumulate(stones.begin(), stones.end(), 0);
        int sum = total / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; ++i) dp[i][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= sum; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= stones[i - 1]) dp[i][j] = dp[i][j] | dp[i - 1][j - stones[i - 1]];
            }
        }
        for (int i = sum; i >= 0; --i) {
            if (dp[n][i]) return abs(total - i * 2);
        }
        return 0;
    }
};