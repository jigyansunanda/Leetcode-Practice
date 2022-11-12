class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = p.first + dx[i];
                int y = p.second + dy[i];
                if (x >= 0 and y >= 0 and x < m and y < n and ans[x][y] == INT_MAX) {
                    ans[x][y] = ans[p.first][p.second] + 1;
                    q.push({x, y});
                }
            }
        }
        return ans;
    }
};