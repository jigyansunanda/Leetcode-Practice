class Solution {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
			return (a[0] != b[0]) ? a[0] < b[0] : a[1] > b[1];
		});
		vector<int> dp;
		for (auto& envelope : envelopes) {
			if (dp.empty()) dp.push_back(envelope[1]);
			else {
				auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);
				if (it == dp.end()) {
					dp.push_back(envelope[1]);
				} else {
					int index = it - dp.begin();
					dp[index] = min(dp[index], envelope[1]);
				}
			}
		}
		return dp.size();
	}
};