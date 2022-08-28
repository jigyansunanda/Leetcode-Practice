class Solution {
public:

	unordered_set<int> st;

	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		size_t m = mat.size();
		size_t n = mat[0].size();
		for (size_t i = 0; i < m; ++i) {
			for (size_t j = 0; j < n; ++j) {
				diagonalSort(mat, i, j, m, n);
			}
		}
        return mat;
	}

	void diagonalSort(vector<vector<int>> &mat, int r, int c, int m, int n) {
		int cnt[101] = {0};
		int row = r, col = c;
		int diff = row - col;
		if (st.find(diff) != st.end()) return;
		st.insert(diff);
		while (row < m and col < n) {
			cnt[mat[row][col]]++;
			++row; ++col;
		}
		row = r, col = c;
		for (int i = 1; i <= 100; ++i) {
			for (int j = 0; j < cnt[i]; ++j) {
				mat[row][col] = i;
				++row; ++col;
			}
		}
	}
};