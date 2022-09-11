class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int lo = matrix[0][0] - 1, hi = matrix[n - 1][n - 1];

		function<bool(int)> check = [&](int x) {
			int count = 0;
			int row = 0, col = n - 1;
			while (row < n and col >= 0) {
				if (matrix[row][col] <= x) {
					count += (col + 1);
					++row;
				} else {
					--col;
				}
			}
			return (count >= k);
		};

		while (hi > lo + 1) {
			int mid = (lo + hi) >> 1;
			bool ok = check(mid);
			if (ok) hi = mid;
			else lo = mid;
		}
		return hi;
	}
};