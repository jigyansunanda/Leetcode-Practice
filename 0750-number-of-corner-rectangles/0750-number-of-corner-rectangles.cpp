class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid, int ans = 0) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m - 1; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int c = 0;
                for (int k = 0; k < n; ++k) {
                    c += (grid[i][k] == 1 and grid[j][k] == 1);
                }
                ans += (c * (c - 1)) / 2;
            }
        }
        return ans;
    }
};