class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> flipped(n);
            for (int j = 0; j < n; ++j) {
                flipped[j] = 1 - matrix[i][j];
            }
            int subans = 0;
            for (int k = 0; k < m; ++k) {
                if ((matrix[i] == matrix[k]) or (matrix[k] == flipped)) {
                    ++subans;
                }
            }
            ans = max(ans, subans);
        }
        return ans;
    }
};