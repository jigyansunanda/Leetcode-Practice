class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) return nums[0];
		function<int(int, int)> f = [&](int l, int r) {
			int lastTaken = nums[l], lastNotTaken = 0;
			int ans = max(lastTaken, lastNotTaken);
			for (int i = l + 1; i <= r; ++i) {
				int currTaken = lastNotTaken + nums[i];
				int currNotTaken = max(lastTaken, lastNotTaken);
				ans = max({ans, currTaken, currNotTaken});
				lastTaken = currTaken;
				lastNotTaken = currNotTaken;
			}
			return ans;
		};
		return max(f(0, n - 2), f(1, n - 1));
	}
};