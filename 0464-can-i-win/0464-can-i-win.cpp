class Solution {
public:
    bool canIWin(int m, int n) {
        if (n <= m) return true;
        int sum = (m * (m + 1)) / 2;
        if (sum < n) return false;
        unordered_map<int, bool> dp;
        return solve(m, n, 0, dp);
    }

    bool solve(int m, int req, int mask, unordered_map<int, bool>& dp) {
        if (req <= 0) return false;
        if (dp.find(mask) != dp.end()) return dp[mask];
        for (int i = 1; i <= m; ++i) {
            if (mask & (1 << (i - 1))) continue;
            if (solve(m, req - i, mask ^ (1 << (i - 1)), dp) == false) {
                dp[mask] = true;
                return true;
            }
        }
        return dp[mask] = false;
    }
};