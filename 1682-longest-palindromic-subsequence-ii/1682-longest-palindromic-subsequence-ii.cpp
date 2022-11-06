class Solution {
public:
    int n;
    int dp[251][251][27];

    int longestPalindromeSubseq(string s) {
        n = s.size();
        memset(dp, -1, sizeof dp);
        return solve(s, 0, n - 1, 26);
    }

    int solve(string& s, int l, int r, int index) {
        if (l >= r) return 0;
        if (dp[l][r][index] != -1) return dp[l][r][index];
        int &ans = dp[l][r][index] = INT_MIN;
        int subans1 = (s[l] == s[r] and ((s[l] - 'a') != index)) ? solve(s, l + 1, r - 1, s[l] - 'a') : INT_MIN;
        if (s[l] == s[r] and ((s[l] - 'a') != index) and subans1 != INT_MIN) subans1 += 2;
        int subans2 = max(solve(s, l + 1, r, index), solve(s, l, r - 1, index));
        ans = max({ans, subans1, subans2});
        return ans;
    }
};