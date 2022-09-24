class Solution {
public:
    long long numberOfWays(string s) {
        long long dp[4][2];
        // dp[i][j] = # of alternating subsequences of length i
        // ending at a character j.
        memset(dp, 0, sizeof dp);
        dp[0][0] = dp[0][1] = 1;
        for (size_t index = 1; index <= s.size(); ++index) {
            for (int len = 1; len <= 3; ++len) {
                int end = s[index - 1] - '0';
                dp[len][end] += dp[len - 1][1 - end];
            }
        }
        long long ans = dp[3][0] + dp[3][1];
        return ans;
    }
};