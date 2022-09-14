class Solution {
public:
	long long mod = 1e9 + 7;
	long long inf = 1e18;

	int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
		for (auto &box : boxes) sort(box.begin(), box.end());
		sort(packages.begin(), packages.end());
		vector<long long> prefix(packages.begin(), packages.end());
		for (size_t i = 1; i <= prefix.size() - 1; ++i) {
			prefix[i] += prefix[i - 1];
		}
		function<long long(int, int)> getPrefixSum = [&](int l, int r) {
			long long prefixsum = prefix[r];
			if (l - 1 >= 0) prefixsum -= prefix[l - 1];
			return prefixsum;
		};
		function<long long(int)> wastedSpace = [&](int id) {
			auto &box = boxes[id];
			long long space_wasted = 0;
			int index = 0;
			for (auto &b : box) {
				if (index == (int)packages.size()) break;
				int lo = index - 1, hi = packages.size();
				while (hi > lo + 1) {
					int mid = (lo + hi) >> 1;
					if (packages[mid] <= b) lo = mid;
					else hi = mid;
				}
				if (index <= lo) {
					space_wasted += ((long long)(lo - index + 1) * (long long) b) - getPrefixSum(index, lo);
					index = lo + 1;
				}
			}
			if (index != (int) packages.size()) return inf;
			return space_wasted;
		};

		long long ans = inf;
		for (size_t i = 0; i < boxes.size(); ++i) {
			ans = min(ans, wastedSpace(i));
		}
		return (ans == inf) ? -1 : ans % mod;
	}
};