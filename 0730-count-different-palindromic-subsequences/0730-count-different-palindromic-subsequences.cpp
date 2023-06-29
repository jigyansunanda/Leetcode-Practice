class Solution {
private:
    long long solve(string& s, int l, int r, int ch, vector<vector<vector<long long>>>& dp) {
        if (l > r) return 0;
        if (l == r) {
            if (s[l] == (char) ('a' + ch)) return 1;
            else return 0;
        }
        if (dp[l][r][ch] != -1) return dp[l][r][ch];
        long long& ans = dp[l][r][ch] = 0;
        if (s[l] == s[r] and (s[l] == (char) ('a' + ch))) {
            ans = 2;
            for (int lastChar = 0; lastChar < 4; ++lastChar) {
                ans += solve(s, l + 1, r - 1, lastChar, dp);
                ans %= mod;
            }
        } else {
            ans += solve(s, l, r - 1, ch, dp);
            ans += solve(s, l + 1, r, ch, dp);
            ans -= solve(s, l + 1, r - 1, ch, dp);
            ans %= mod;
            if (ans < 0) ans += mod;
        }
        return ans;
    }

public:
    const long long mod = 1e9 + 7;

    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector dp(n, vector(n, vector<long long>(4, -1)));
        long long ans = 0;
        for (int i = 0; i < 4; ++i) {
            ans += solve(s, 0, n - 1, i, dp);
            ans %= mod;
        }
        return (int) ans;
    }
};