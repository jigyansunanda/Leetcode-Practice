class Solution {
public:
	int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
		vector<int> prefix(nums.size(), 0);
		prefix[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			prefix[i] = nums[i] + prefix[i-1];
		}
		int ans = 0;
		for (int start = 0; start <= n - 1; ++start) {
			int lo = start - 1, hi = n;
			while (hi > lo + 1) {
				int mid = (lo + hi) >> 1;
				int sum = prefix[mid] - ((start - 1 >= 0) ? prefix[start - 1] : 0);
				if (mid - start + 1 - sum <= k) lo = mid;
				else hi = mid;
			}
			ans = max(ans, lo - start + 1);
		}
		return ans;
	}
};