class Solution {
public:
	vector<int> findOriginalArray(vector<int>& changed) {
		if (changed.size() % 2) return {};
		int mx = *max_element(changed.begin(), changed.end());
		vector<int> F((mx << 1) + 1, 0), ans;
		for (auto &e : changed) F[e]++;
		if (F[0] & 1) return {};
		else for (int j = 0; j < F[0] / 2; ++j) ans.push_back(0);
		for (int i = 1; i <= mx; ++i) {
			if (F[i]) {
				int count = F[i];
				if (2 * i >= (int)F.size() or F[2 * i] < count) return {};
				else {
					for (int j = 0; j < count; ++j) {
						ans.push_back(i);
					}
					F[2 * i] -= count;
				}
			}
		}
		return ans;
	}
};