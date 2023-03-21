class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool is_zero_in_first_row = false, is_zero_in_first_col = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) is_zero_in_first_col = true;
        }
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) is_zero_in_first_row = true;
        }

        for (int i = 1; i <= m - 1; ++i) {
            for (int j = 1; j <= n - 1; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 or matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        if (is_zero_in_first_col) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (is_zero_in_first_row) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};