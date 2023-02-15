class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[l]) {
                if (nums[l] <= target and target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                if (nums[mid] < target and target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};