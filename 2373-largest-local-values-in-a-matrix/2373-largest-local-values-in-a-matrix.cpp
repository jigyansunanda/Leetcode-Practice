class Solution {
public:
    int d[3] = { -1, 0, 1};
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        function<int(int, int)> get = [&](int row, int col) {
        	int kk = 0;
        	for (int k = 0; k < 3; ++k) {
        		for (int r = 0; r < 3; ++r) {
        			kk = max(kk, grid[row+d[k]][col+d[r]]);
        		}
        	}
        	return kk;
        };
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                ans[i][j] = get(i + 1, j + 1);
            }
        }
        return ans;
    }
};