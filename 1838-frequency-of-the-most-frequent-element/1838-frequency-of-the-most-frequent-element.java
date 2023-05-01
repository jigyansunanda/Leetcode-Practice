class Solution {
    public static int maxFrequency(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int l = 0, res = 0;
        long sum = 0;
        for (int r=0; r<n; ++r) {
            sum += nums[r];
            while (sum + k < (long)nums[r] * (r-l+1)) {
                sum -= nums[l];
                ++l;
            }
            if (sum + k >= (long)nums[r] * (r-l+1)) {
                res = Math.max(res, r-l+1);
            }
        }
        return res;
    }
}