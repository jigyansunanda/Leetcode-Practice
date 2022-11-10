class Solution {
private:
    bool isValid(int x, int y) {return x >= 0 and y >= 0 and x < m and y < n;}

public:
    int m, n;
    vector<vector<int>> grid;
    int dp[71][71][71];
    int col[3] = { -1, 0, 1};

    int cherryPickup(vector<vector<int>>& _grid) {
        this->grid = _grid;
        this->m = grid.size();
        this->n = grid[0].size();
        memset(dp, -1, sizeof dp);
        int ans = solve(0, 0, n - 1);
        return (ans == INT_MIN) ? 0 : ans;
    }

    int solve(int r1, int c1, int c2) {
        int r2 = r1;
        if (!isValid(r1, c1) or !isValid(r2, c2)) return INT_MIN;
        if (r1 == m - 1) {
            if (c1 == c2) return grid[r1][c1];
            else return grid[r1][c1] + grid[r2][c2];
        }
        if (dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
        int cherry = (c1 == c2) ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];
        int ans = INT_MIN;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int k = solve(r1 + 1, c1 + col[i], c2 + col[j]);
                if (k != INT_MIN) k += cherry;
                ans = max(ans, k);
            }
        }
        return dp[r1][c1][c2] = ans;
    }
};