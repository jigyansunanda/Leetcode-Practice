class Trie {
public:
    Trie* child[27] = {};
    bool isEnd = false;
    string word = "";

    Trie() {}

    void insert(string& word) {
        Trie* node = this;
        for (auto &c : word) {
            if (node->child[c - 'a'] == NULL) node->child[c - 'a'] = new Trie();
            node = node->child[c - 'a'];
        }
        node->isEnd = true;
        node->word = word;
    }
};

class Solution {
public:
    int m, n;
    char dummy = '{';
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<string> ans;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        Trie* root = new Trie();
        for (auto &word : words) root->insert(word);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (root->child[board[i][j] - 'a']) {
                    solve(board, i, j, root);
                }
            }
        }
        return ans;
    }

    void solve(vector<vector<char>>& board, int r, int c, Trie* root) {
        char ch = board[r][c];
        Trie* currNode = root->child[ch - 'a'];
        if (currNode == NULL) return;
        if (currNode) {
            if (currNode->word != "") ans.push_back(currNode->word);
            currNode->word = "";
        }
        board[r][c] = dummy;
        for (int dir = 0; dir < 4; ++dir) {
            int x = r + dx[dir];
            int y = c + dy[dir];
            if (isValid(x, y) and board[x][y] != dummy) {
                solve(board, x, y, currNode);
            }
        }
        board[r][c] = ch;
        return;
    }

    bool isValid(int x, int y) {
        return (x >= 0 and y >= 0 and x < m and y < n);
    }
};