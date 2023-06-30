class Solution {
public:
    int longestPalindrome(string s1, string s2, int ans = 0) {
        string s = s1 + s2;
        int m = s1.size(), n = s2.size(), z = s.size();

        vector dp(z, vector<int>(z, 0));
        for (int len = 1; len <= z; ++len) {
            for (int i = 0; i + len - 1 < z; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = ((len == 1) ? 1 : 2 + dp[i + 1][j - 1]);
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s1[i] == s2[j]) {
                    ans = max(ans, 2 + dp[i + 1][m + j - 1]);
                }
            }
        }
        return ans;
    }
};