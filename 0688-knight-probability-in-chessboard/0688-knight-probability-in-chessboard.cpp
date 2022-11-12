class Solution {
public:
    const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

    double knightProbability(int n, int k, int row, int column) {
        double dp[k + 1][n][n];
        for (int i = 0; i < k + 1; ++i) {
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    dp[i][r][c] = 0.0;
                }
            }
        }
        dp[0][row][column] = 1.0;
        for (int move = 1; move <= k; ++move) {
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    for (int dir = 0; dir < 8; ++dir) {
                        int x = r - dx[dir];
                        int y = c - dy[dir];
                        if (x >= 0 and y >= 0 and x < n and y < n) {
                            dp[move][r][c] += (dp[move - 1][x][y] / 8.0);
                        }
                    }
                }
            }
        }
        double ans = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                ans += dp[k][r][c];
            }
        }
        return ans;
    }
};