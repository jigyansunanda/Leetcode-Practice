class Solution {
private:
    bool isValid(int x, int y) {
        return (x >= 0 and y >= 0 and x < n and y < n and grid[x][y] != -1);
    }
public:
    int n;
    int dp[51][51][51];
    vector<vector<int>> grid;

    int cherryPickup(vector<vector<int>>& _grid) {
        this->grid = _grid;
        n = grid.size();
        memset(dp, -1, sizeof dp);
        int ans = solve(0, 0, 0);
        return (ans == INT_MIN) ? 0 : ans;
    }

    int solve(int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;
        if (!isValid(r1, c1) or !isValid(r2, c2)) return INT_MIN;
        if (dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
        if (r1 == n - 1 and r2 == n - 1 and c1 == n - 1) return grid[r1][c1];
        int cherry = (r1 == r2 and c1 == c2) ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];
        int k1 = solve(r1 + 1, c1, r2 + 1); if (k1 != INT_MIN) k1 += cherry;
        int k2 = solve(r1 + 1, c1, r2); if (k2 != INT_MIN) k2 += cherry;
        int k3 = solve(r1, c1 + 1, r2 + 1); if (k3 != INT_MIN) k3 += cherry;
        int k4 = solve(r1, c1 + 1, r2); if (k4 != INT_MIN) k4 += cherry;
        return dp[r1][c1][r2] = max({k1, k2, k3, k4});
    }
};