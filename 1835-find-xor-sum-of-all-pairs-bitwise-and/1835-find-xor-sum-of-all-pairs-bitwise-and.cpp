class Solution {
public:
	int getXORSum(vector<int>& arr1, vector<int>& arr2) {
		int m = arr1.size(), n = arr2.size();
		int a[31] = {0};
		int b[31] = {0};
		for (int i = 0; i < 31; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr1[j] & (1 << i)) a[i]++;
			}
			for (int j = 0; j < n; ++j) {
				if (arr2[j] & (1 << i)) b[i]++;
			}
		}
		for (int i = 0; i < 31; ++i) {
			a[i] %= 2;
			b[i] %= 2;
		}
		int ans = 0;
		for (int i = 0; i < 31; ++i) {
			int val = a[i] * b[i];
			if (val & 1) {
				ans |= (1 << i);
			}
		}
		return ans;
	}
};