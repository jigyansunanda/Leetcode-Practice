class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> ans;
		nums.push_back(1000000);
		for (auto &e : nums) {
			int index = abs(e);
			if (index < nums.size()) nums[index] = -abs(nums[index]);
		}
		for (int index = 1; index < nums.size(); ++index) {
			if (nums[index] > 0) ans.push_back(index);
		}
		return ans;
	}
};