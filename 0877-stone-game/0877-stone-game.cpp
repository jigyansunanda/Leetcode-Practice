class Solution {
public:
    int dp[501][501];

    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), total = accumulate(piles.begin(), piles.end(), 0);
        memset(dp, -1, sizeof dp);
        int alice = game(piles, 0, n - 1);
        int bob = total - alice;
        return (alice > bob);
    }

    int game(vector<int> &piles, int l, int r) {
        if (l > r) return 0;
        if (l == r) return piles[l];
        if (dp[l][r] != -1) return dp[l][r];
        auto &ans = dp[l][r] = 0;
        int takeFromStart = piles[l] + min(game(piles, l + 1, r - 1), game(piles, l + 2, r));
        int takeFromEnd = piles[r] + min(game(piles, l + 1, r - 1), game(piles, l, r - 2));
        return ans = max(takeFromStart, takeFromEnd);
    }
};