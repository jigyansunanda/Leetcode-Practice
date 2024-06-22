class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        for (int i = 1; i < n; ++i) {
            nums[i] = Math.max(nums[i] + i, nums[i - 1]);
        }
        int jumps = 0, index = 0;
        while (index < n - 1) {
            ++jumps;
            index = nums[index];
        }
        return jumps;
    }
}