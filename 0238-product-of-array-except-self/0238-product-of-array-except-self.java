class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] leftUntilPrev = new int[n];
        leftUntilPrev[0] = 1;
        for (int i = 1; i < n; i++) {
            leftUntilPrev[i] = leftUntilPrev[i - 1] * nums[i - 1];
        }
        int rightUntilCurrent = 1;
        for (int i = n - 1; i >= 0; --i) {
            leftUntilPrev[i] *= rightUntilCurrent;
            rightUntilCurrent *= nums[i];
        }
        return leftUntilPrev;
    }
}