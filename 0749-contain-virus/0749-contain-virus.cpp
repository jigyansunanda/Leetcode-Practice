class Solution {
private:
    bool isValid(int row, int col) { return (row >= 0 and row < rows and col >= 0 and col < cols); }

public:
    vector<vector<int>> grid;
    int rows, cols;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int containVirus(vector<vector<int>>& grid, int walls = 0) {
        this->grid = grid;
        this->rows = grid.size();
        this->cols = grid[0].size();
        while (true) {
            int wallsBuild = buildWalls();
            if (wallsBuild == 0) break;
            walls += wallsBuild;
        }
        return walls;
    }

    int buildWalls() {
        vector vis(rows, vector<bool>(cols, false));
        int R = -1, C = -1, maxSpread = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 and !vis[i][j]) {
                    int spreadImpact = 0;
                    vector impact(rows, vector<bool>(cols, false));
                    checkSpreadImpact(i, j, spreadImpact, vis, impact);
                    if (maxSpread < spreadImpact) {
                        maxSpread = spreadImpact;
                        R = i, C = j;
                    }
                }
            }
        }
        if (maxSpread == 0) return 0;
        int wallCount = 0;
        buildWallAround(R, C, wallCount);
        spreadVirus();
        return wallCount;
    }

    void checkSpreadImpact(int row, int col, int& spreadImpact, vector<vector<bool>>& vis, vector<vector<bool>>& impact) {
        if (vis[row][col]) return;
        vis[row][col] = true;
        impact[row][col] = true;
        for (int dir = 0; dir < 4; ++dir) {
            int x = row + dx[dir];
            int y = col + dy[dir];
            if (isValid(x, y)) {
                if (grid[x][y] == 0) {
                    if (!impact[x][y]) {
                        ++spreadImpact;
                        impact[x][y] = true;
                    }
                } else if (grid[x][y] == 1) {
                    checkSpreadImpact(x, y, spreadImpact, vis, impact);
                }
            }
        }
    }

    void buildWallAround(int row, int col, int& wallCount) {
        grid[row][col] = -1;
        for (int dir = 0; dir < 4; ++dir) {
            int x = row + dx[dir];
            int y = col + dy[dir];
            if (isValid(x, y)) {
                if (grid[x][y] == 0) {
                    ++wallCount;
                } else if (grid[x][y] == 1) {
                    buildWallAround(x, y, wallCount);
                }
            }
        }
    }

    void spreadVirus() {
        vector spread(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 and !spread[i][j]) {
                    spread[i][j] = true;
                    for (int dir = 0; dir < 4; ++dir) {
                        int x = i + dx[dir], y = j + dy[dir];
                        if (isValid(x, y) and !spread[x][y] and grid[x][y] == 0) {
                            grid[x][y] = 1;
                            spread[x][y] = true;
                        }
                    }
                }
            }
        }
    }
};