class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 or nums[i] > n) {
                nums[i] = n + 2;
            }
        }
        for (int i = 0; i < n; ++i) {
            int index = abs(nums[i]) - 1;
            if (index >= n) continue;
            nums[index] = -1 * abs(nums[index]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};