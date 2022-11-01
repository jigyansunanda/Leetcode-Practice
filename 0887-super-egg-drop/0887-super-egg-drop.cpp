class Solution {
public:
    int superEggDrop(int eggs, int floor) {
        // dp[M][K]means that, given K eggs and M moves,
        // what is the maximum number of floor that we can check.
        vector<vector<int>> dp(floor + 1, vector<int>(eggs + 1, 0));
        int moves = 0;
        while (dp[moves][eggs] < floor) {
            ++moves;
            for (int egg = 1; egg <= eggs; ++egg) {
                dp[moves][egg] = dp[moves - 1][egg - 1] + dp[moves - 1][egg] + 1;
            }
        }
        return moves;
    }
};