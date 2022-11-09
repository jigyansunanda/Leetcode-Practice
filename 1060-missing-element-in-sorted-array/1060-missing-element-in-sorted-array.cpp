class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int lo = nums.front(), hi = nums.back() + k;
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            int count = countLessThanOrEqual(nums, mid);
            if (mid > nums.front() + count + k - 1 - 1) hi = mid;
            else lo = mid;
        }
        return hi;
    }

    int countLessThanOrEqual(vector<int>& nums, int k) {
        int lo = -1, hi = nums.size();
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] <= k) lo = mid;
            else hi = mid;
        }
        return lo + 1;
    }
};