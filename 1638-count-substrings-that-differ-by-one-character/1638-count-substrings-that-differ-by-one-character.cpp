class Solution {
public:
    int countSubstrings(string s, string t, int ans = 0) {
        int m = s.size(), n = t.size();
        int dp1[m + 1][n + 1]; memset(dp1, 0, sizeof(dp1));
        int dp2[m + 1][n + 1]; memset(dp2, 0, sizeof(dp2));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp1[i][j] = 1 + dp1[i - 1][j - 1];
                    dp2[i][j] = dp2[i - 1][j - 1];
                } else {
                    dp2[i][j] = dp1[i - 1][j - 1] + 1;
                }
                ans += dp2[i][j];
            }
        }
        return ans;
    }
};