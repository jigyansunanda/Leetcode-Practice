class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool vis[10][10];
    int m, n, len;

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size(), len = word.size();
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word.front()) {
                    int doesExist = check(board, word, 0, i, j);
                    if (doesExist) return true;
                }
            }
        }
        return false;
    }

    int check(vector<vector<char>>& board, string& word, int index, int x, int y) {
        if (index + 1 == ((int) word.size())) return true;
        vis[x][y] = 1;
        int ans = 0;
        for (int dir = 0; dir < 4; ++dir) {
            int r = x + dx[dir], c = y + dy[dir];
            if (r >= 0 and c >= 0 and r < m and c < n) {
                if (index + 1 < len and word[index + 1] == board[r][c] and !vis[r][c]) {
                    ans |= check(board, word, index + 1, r, c);
                }
            }
        }
        vis[x][y] = 0;
        return ans;
    }
};