class Solution {
public:
    int findMin(vector<int>& nums) {
        // comparison to last element of array -> {F, F, F, F, F, T, T, T}
        int n = nums.size();
        int l = -1, r = n - 1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (nums[mid] <= nums.back()) r = mid;
            else l = mid;
        }
        return nums[r];
    }
};