class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		unordered_map<int, int> mp;
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				int diff = i - j;
				if (mp.count(diff) and mp[diff] != matrix[i][j]) return false;
				mp[diff] = matrix[i][j];
			}
		}
		return true;
	}
};