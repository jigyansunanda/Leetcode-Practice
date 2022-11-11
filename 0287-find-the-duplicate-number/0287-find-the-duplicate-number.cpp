class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (auto &num : nums) {
            int k = abs(num) - 1;
            if (nums[k] < 0) return abs(num);
            nums[k] = -1 * abs(nums[k]);
        }
        return -1;
    }
};