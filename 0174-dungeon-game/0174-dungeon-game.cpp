class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[i][j] = minimum HP required to reach (m-1, n-1) starting from (i, j)
        dp[m - 1][n - 1] = (dungeon[m - 1][n - 1] >= 0) ? 1 : 1 + abs(dungeon[m - 1][n - 1]);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 and j == n - 1) continue;
                int comeFromRight = (j + 1 < n) ? dp[i][j + 1] : INT_MAX;
                int comeFromTop = (i + 1 < m) ? dp[i + 1][j] : INT_MAX;
                int minHealthRequired = min(comeFromRight, comeFromTop) - dungeon[i][j];
                dp[i][j] = (minHealthRequired <= 0) ? 1 : minHealthRequired;
            }
        }
        return dp[0][0];
    }
};