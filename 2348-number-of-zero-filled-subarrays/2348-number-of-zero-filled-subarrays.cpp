class Solution {
public:
	long long zeroFilledSubarray(vector<int>& nums) {
		for (auto &e : nums) if (e) e = 1;
		long long ans = 0;
		map<int, int> mp;
		int pre = 0;
		for (int i = 0; i < nums.size(); ++i) {
			pre += nums[i];
			if (pre == 0) ++ans;
			if (mp.count(pre)) {
				ans += mp[pre];
			}
			mp[pre]++;
		}
		return ans;
	}
};