class Solution {
public:
    int dp[51];
    
    int maxA(int n) {
        memset(dp, -1, sizeof dp);
        return solve(n);
    }
    
    int solve(int n) {
        if (n <= 2) return n;
        if (dp[n] != -1) return dp[n];
        int maxLength = n;
        for (int i = 0; i < n; ++i) {
            int ans = solve(i) * (n - i - 1);
            maxLength = max(maxLength, ans);
        }
        return dp[n] = max(maxLength, solve(n - 1) + 1);
    }
};