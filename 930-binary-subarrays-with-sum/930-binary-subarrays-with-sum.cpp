class Solution {
public:
	int numSubarraysWithSum(vector<int>& nums, int goal) {
		unordered_map<int, int> mp;
		int pre = 0, ans = 0;
		for (int i = 0; i < nums.size(); ++i) {
			pre += nums[i];
			if (pre == goal) ans++;
			if (mp.count(pre - goal)) ans += mp[pre - goal];
			mp[pre]++;
		}
		return ans;
	}
};