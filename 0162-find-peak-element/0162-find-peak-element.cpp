class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = -1, hi = n, mid;
        while (hi > lo + 1) {
            mid = (lo + hi) >> 1;
            int left = (mid - 1 == -1) ? INT_MIN : nums[mid - 1];
            int right = (mid + 1 == n) ? INT_MIN : nums[mid + 1];
            if (left <= nums[mid] and nums[mid] >= right) return mid;
            else if (left > nums[mid]) hi = mid; // descending slope
            else lo = mid;	// ascending slope
        }
        return mid;
    }
};