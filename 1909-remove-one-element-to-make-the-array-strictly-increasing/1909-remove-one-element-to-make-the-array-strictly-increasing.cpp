class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int ops = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                ops++;
                if (i - 2 >= 0 and nums[i - 2] >= nums[i]) {
                    nums[i] = nums[i - 1];
                }
            }
            if (ops > 1) return false;
        }
        return (ops <= 1);
    }
};