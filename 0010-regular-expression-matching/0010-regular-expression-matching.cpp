class Solution {
public:
    bool isMatch(string text, string pattern) {
        int m = text.size(), n = pattern.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        // dp[i][0] = false for all i > 0
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = (j > 1 and pattern[j - 1] == '*' and dp[0][j - 2]);
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (pattern[j - 1] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] and (text[i - 1] == pattern[j - 1] or pattern[j - 1] == '.');
                } else {
                    dp[i][j] = dp[i][j - 2] or ((pattern[j - 2] == text[i - 1] or pattern[j - 2] == '.') and dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};