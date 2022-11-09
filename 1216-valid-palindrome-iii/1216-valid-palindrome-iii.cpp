class Solution {
public:
    int dp[1001][1001];

    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        memset(dp, -1, sizeof dp);
        int len = longestPalindromicSubseq(s, 0, n - 1);
        if (n - len <= k) return true;
        return false;
    }

    int longestPalindromicSubseq(string &s, int l, int r) {
        if (l > r) return 0;
        if (l == r) return 1;
        if (dp[l][r] != -1) return dp[l][r];
        int k1 = longestPalindromicSubseq(s, l + 1, r);
        int k2 = longestPalindromicSubseq(s, l, r - 1);
        if (s[l] == s[r]) {
            return dp[l][r] = max({k1, k2, 2 + longestPalindromicSubseq(s, l + 1, r - 1)});
        } else {
            return dp[l][r] = max(k1, k2);
        }
    }
};