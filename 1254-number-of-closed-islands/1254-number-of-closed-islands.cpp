class Solution {
public:
    int r, c;
    bool vis[111][111] = {{0}};
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool border_encountered = false;

    bool is_on_border(int x, int y) { return (x == 0 or x == r - 1 or y == 0 or y == c - 1); }

    bool is_valid(int x, int y) { return (x >= 0 and y >= 0 and x < r and y < c); }

    int closedIsland(vector<vector<int>>& grid, int ans = 0) {
        r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (is_on_border(i, j) == false and vis[i][j] == false and grid[i][j] == 0) {
                    border_encountered = false;
                    dfs(grid, i, j);
                    if (!border_encountered) ++ans;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int x, int y) {
        vis[x][y] = true;
        if (is_on_border(x, y)) border_encountered = true;
        for (int dir = 0; dir < 4; ++dir) {
            int xx = x + dx[dir];
            int yy = y + dy[dir];
            if (is_valid(xx, yy)) {
                if (grid[xx][yy] == 0 and !vis[xx][yy]) {
                    dfs(grid, xx, yy);
                }
            }
        }
    }
};