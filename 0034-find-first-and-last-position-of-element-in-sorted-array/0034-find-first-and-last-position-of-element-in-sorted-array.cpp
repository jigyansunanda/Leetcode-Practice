class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (l == n or nums[l] != target) return {-1, -1};
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return {l, r - 1};
    }
};