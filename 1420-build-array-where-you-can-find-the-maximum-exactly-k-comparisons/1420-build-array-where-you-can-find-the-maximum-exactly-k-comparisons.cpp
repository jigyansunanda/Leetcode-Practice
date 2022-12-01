class Solution {
public:
    const long long mod = 1e9 + 7;
    long long dp[52][102][102];

    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof dp);
        return solve(n, m, k, 1, 0, 0);
    }

    long long solve(int n, int m, int k, int index, int maxTillNow, int score) {
        if (index > n) return (score == k);
        if (score > k) return 0;
        if (dp[index][maxTillNow][score] != -1) return dp[index][maxTillNow][score];
        long long &ans = dp[index][maxTillNow][score] = 0;
        ans = (ans + (maxTillNow * solve(n, m, k, index + 1, maxTillNow, score)) % mod) % mod;
        for (int next = maxTillNow + 1; next <= m; ++next) {
            ans = (ans + solve(n, m, k, index + 1, max(maxTillNow, next), score + 1)) % mod;
        }
        return ans;
    }
};