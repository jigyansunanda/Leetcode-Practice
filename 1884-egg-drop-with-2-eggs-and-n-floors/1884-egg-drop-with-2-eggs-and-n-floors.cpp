class Solution {
public:
    int dp[1001][3];

    int twoEggDrop(int n) {
        memset(dp, -1, sizeof dp);
        return solve(n, 2);
    }

    int solve(int floor, int eggs) {
        if (eggs == 1) return floor;
        if (floor <= 1) return floor;
        if (dp[floor][eggs] != -1) return dp[floor][eggs];
        dp[floor][eggs] = INT_MAX;
        for (int f = 1; f <= floor; ++f) {
            int eggBreak = solve(f - 1, eggs - 1) + 1;
            int eggNotBreak = solve(floor - f, eggs) + 1;
            int worstCase = max(eggBreak, eggNotBreak);
            dp[floor][eggs] = min(dp[floor][eggs], worstCase);
        }
        return dp[floor][eggs];
    }
};