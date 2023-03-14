class Solution {
    public int maxScore(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int ans = 0;
        long pref = 0;
        for (int i = n-1; i >=0; --i) {
            pref += nums[i];
            if (pref > 0) ++ans;
        }
        return ans;
    }
}