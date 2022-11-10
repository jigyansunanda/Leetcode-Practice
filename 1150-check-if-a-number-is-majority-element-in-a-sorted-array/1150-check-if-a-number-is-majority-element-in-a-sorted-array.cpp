class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() or * it != target) return false;
        auto it2 = lower_bound(nums.begin(), nums.end(), target + 1);
        it2--;
        return ((it2 - it + 1) > (nums.size() / 2));
    }
};