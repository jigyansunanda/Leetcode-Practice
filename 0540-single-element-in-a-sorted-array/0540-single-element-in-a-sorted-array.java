class Solution {
    public int singleNonDuplicate(int[] nums) {
        if (nums.length == 1 || (nums[0] != nums[1])) return nums[0];
        int n = nums.length;
        int lo = 0, hi = n;
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (check(nums, n, mid)) hi = mid;
            else lo = mid;
        }
        return nums[lo];
    }
    
    public boolean check(int[] nums, int n, int x) {
        int index = x;
        if (x-1 >= 0 && nums[x-1] == nums[index]) index = x-1;
        if (index % 2  == 0) return false;
        return true;
    }
}