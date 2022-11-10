class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int loCol = -1, hiCol = cols;
        while (hiCol > loCol + 1) {
            int midCol = (loCol + hiCol) >> 1;
            int maxRow = 0;
            for (int row = 0; row < rows; ++row) {
                if (mat[row][midCol] >= mat[maxRow][midCol]) {
                    maxRow = row;
                }
            }
            int left = (midCol - 1 < 0) ? INT_MIN : mat[maxRow][midCol - 1];
            int right = (midCol + 1 == cols) ? INT_MIN : mat[maxRow][midCol + 1];
            if (left <= mat[maxRow][midCol]  and mat[maxRow][midCol] >= right) return {maxRow, midCol};
            else if (left > mat[maxRow][midCol]) hiCol = midCol;
            else loCol = midCol;
        }
        return { -1, -1};
    }
};