class Solution {
    public int triangleNumber(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int ans = 0;
        for (int i = n-1; i >= 2; --i) {
            int l = 0, r = i-1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    ans += (r-l);
                    --r;
                }else {
                    ++l;
                }
            }
        }
        return ans;
    }
}