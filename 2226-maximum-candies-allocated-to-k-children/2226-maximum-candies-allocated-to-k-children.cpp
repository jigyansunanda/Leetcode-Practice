class Solution {
public:
	int maximumCandies(vector<int>& candies, long long k) {
		if (k == 1) return *max_element(candies.begin(), candies.end());
		long long lo = 0, hi = accumulate(candies.begin(), candies.end(), 0ll);

		function<bool(long long)> check = [&](long long x) {
			long long children = 0;
			for (auto &candy : candies) {
				if (candy < x) continue;
				children += (candy / x);
			}
			return (children >= k);
		};

		while (hi > lo + 1) {
			long long mid = (lo + hi) >> 1;
			if (check(mid)) lo = mid;
			else hi = mid;
		}
		return (int)lo;
	}
};