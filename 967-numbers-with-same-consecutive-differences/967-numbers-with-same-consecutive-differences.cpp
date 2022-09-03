class Solution {
public:
	vector<int> ans;

	vector<int> numsSameConsecDiff(int n, int k) {
		ans.clear();

		function<void(int, int, int)> dfs = [&](int index, int prev, int num) {
			if (index == n) {
				ans.push_back(num);
				return;
			}
			if (prev - k >= 0) dfs(index + 1, prev - k, (num * 10) + (prev - k));
			if (k and prev + k < 10) dfs(index + 1, prev + k, (num * 10) + (prev + k));
		};

		for (int i = 1; i < 10; ++i) {
			dfs(1, i, i);
		}

		return ans;
	}
};