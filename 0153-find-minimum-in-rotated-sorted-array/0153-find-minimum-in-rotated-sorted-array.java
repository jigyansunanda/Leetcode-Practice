class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        // if (nums[0] < nums[n - 1]) return nums[0];
        // isGreateThanLastNumber(arr[]): [T, T, T, T, F, F]
        int lo = -1, hi = n;
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] > nums[n - 1])
                lo = mid;
            else
                hi = mid;
        }
        return nums[hi];
    }
}