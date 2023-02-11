class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length, len = Integer.MAX_VALUE, sum = 0, l = 0;       
        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            while (sum >= target) {
                len = Math.min(len, r-l+1);
                sum -= nums[l];
                ++l;
            }
        }
        return (len == Integer.MAX_VALUE) ? 0 : len;
    }
}