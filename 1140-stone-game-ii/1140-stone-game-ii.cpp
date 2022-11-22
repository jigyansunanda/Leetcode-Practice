class Solution {
public:
    int n;
    int dp[111][111];
    vector<int> suffix;

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix.resize(n); suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = piles[i] + suffix[i + 1];
        }
        memset(dp, -1, sizeof dp);
        return solve(0, 1);
    }

    int solve(int index, int M) {
        if (index >= n) return 0;
        if (dp[index][M] != -1) return dp[index][M];
        int &ans = dp[index][M] = 0;
        for (int size = 1; size <= 2 * M; ++size) {
            int endIndex = index + size - 1;
            if (endIndex > n - 1) continue;
            int alice = getSum(index, endIndex);
            if (endIndex + 1 < n) alice += suffix[endIndex + 1];
            alice -= solve(endIndex + 1, min(n, max(M, size)));
            ans = max(ans, alice);
        }
        return ans;
    }

    int getSum(int l, int r) {
        if (r + 1 < n) return suffix[l] - suffix[r + 1];
        else return suffix[l];
    }
};