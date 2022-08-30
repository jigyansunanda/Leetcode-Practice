class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        for (int d = 1; d < n; ++d) {
            for (int row = 0; row + d < n; ++row) {
                int col = row + d;
                swap(m[row][col], m[col][row]);
            }
        }
        for (int i = 0; i < n; ++i) {
            reverse(m[i].begin(), m[i].end());
        }
        return;
    }
};