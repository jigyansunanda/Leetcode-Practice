class Solution {
public:
    bool isMatch(string text, string pattern) {
        int m = text.size(), n = pattern.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        // dp[i][0] = false for all i > 0
        for (int j = 1; j <= n; ++j) {
            if (j == 1) dp[0][j] = (pattern[j - 1] == '*');
            else dp[0][j] = dp[0][j - 1] and (pattern[j - 1] == '*');
        }
        vector<bool> hasEverBeenMatched(n + 1, false);
        hasEverBeenMatched[0] = true;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (pattern[j - 1] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] and (pattern[j - 1] == '?' or pattern[j - 1] == text[i - 1]);
                    hasEverBeenMatched[j] = hasEverBeenMatched[j] | dp[i][j];
                } else {
                    dp[i][j] = hasEverBeenMatched[j - 1];
                    hasEverBeenMatched[j] = hasEverBeenMatched[j] | dp[i][j];
                }
            }
        }
        return dp[m][n];
    }
};