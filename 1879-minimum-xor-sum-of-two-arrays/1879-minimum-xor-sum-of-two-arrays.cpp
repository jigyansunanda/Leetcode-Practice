class Solution {
public:
	int n;
	int dp[15][(1 << 15) + 1];
	const int inf = 1e9;

	int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
		n = nums1.size();
		int mask = (1 << n) - 1;
		memset(dp, -1, sizeof dp);
		return solve(nums1, nums2, 0, mask);
	}

	int solve(vector<int>& nums1, vector<int>& nums2, int index, int mask) {
		if (index >= n) return 0;
		if (dp[index][mask] != -1) return dp[index][mask];
		int& ans = dp[index][mask];
		ans = inf;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				int subans = (nums1[index] ^ nums2[i]) + solve(nums1, nums2, index + 1, mask ^ (1 << i));
				ans = min(ans, subans);
			}
		}
		return ans;
	}
};