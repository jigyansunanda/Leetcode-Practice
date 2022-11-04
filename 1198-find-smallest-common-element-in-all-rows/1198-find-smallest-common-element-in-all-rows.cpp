class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int count[10001] = {0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                count[mat[i][j]]++;
                if (count[mat[i][j]] == m) return mat[i][j];
            }
        }
        return -1;
    }
};