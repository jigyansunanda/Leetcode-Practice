class Solution {
public:
	bool isConsecutive(vector<int>& nums) {
		int m = *min_element(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			int val = abs(nums[i]);
			if (val - m >= nums.size() or val - m < 0) return false;
			if (nums[val - m] < 0) return false;
			nums[val - m] = -abs(nums[val - m]);
		}
		int c = count_if(nums.begin(), nums.end(), [](int x) {return x > 0;});
		int d = count_if(nums.begin(), nums.end(), [](int x) {return x == 0;});
		if (c or (d > 1)) return false;
		return true;
	}
};