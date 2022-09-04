class Solution {
public:
	int longestNiceSubarray(vector<int>& nums, int ans = 0) {
		int n = nums.size();
		vector<int> bit[n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 31; ++j) {
				if (nums[i] & (1 << j)) {
					bit[i].push_back(j);
				}
			}
		}
		int l = 0;
		vector<int> bitcount(31, 0);
		for (int r = 0; r < n; ++r) {
			for (auto &index : bit[r]) {
				bitcount[index]++;
			}
			while (count_if(bitcount.begin(), bitcount.end(), [](int x) {return (x > 1);}) > 0) {
				for (auto &index : bit[l]) {
					bitcount[index]--;
				}
				l++;
			}
			if (count_if(bitcount.begin(), bitcount.end(), [](int x) {return (x > 1);}) == 0) {
				ans = max(ans, r - l + 1);
			}
		}
		return ans;
	}
};