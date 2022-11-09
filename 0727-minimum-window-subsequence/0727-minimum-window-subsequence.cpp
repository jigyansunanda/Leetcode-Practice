class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; ++i) if (s[i] == t[0]) dp[i][0] = i;
        for (int j = 1; j < n; ++j) {
            int maxIndex = -1;
            for (int i = 0; i < m; ++i) {
                if (s[i] == t[j]) {
                    dp[i][j] = maxIndex;
                }
                maxIndex = max(maxIndex, dp[i][j - 1]);
            }
        }
        int startIndex = -1, minLength = INT_MAX;
        for (int i = 0; i < m; ++i) {
            if (dp[i][n - 1] != -1 and i - dp[i][n - 1] + 1 < minLength) {
                minLength = i - dp[i][n - 1] + 1;
                startIndex = dp[i][n - 1];
            }
        }
        if (startIndex == -1) return "";
        return s.substr(startIndex, minLength);
    }
};