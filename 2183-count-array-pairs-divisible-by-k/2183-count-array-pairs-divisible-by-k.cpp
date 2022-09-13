class Solution {
public:

	long long countPairs(vector<int>& nums, int k) {
		int n = nums.size();
		unordered_map<int, int> mp;
		long long ans = 0;
		for (int index = 0; index < n; ++index) {
			int factor = gcd(nums[index], k);
			int other_factor = k / factor;
			if (other_factor == 1) {
				ans += (index);
			} else {
				for (auto it = mp.begin(); it != mp.end(); ++it) {
					if (it->first % other_factor == 0) {
						ans += it->second;
					}
				}
			}
			mp[factor]++;
		}
		return ans;
	}
};