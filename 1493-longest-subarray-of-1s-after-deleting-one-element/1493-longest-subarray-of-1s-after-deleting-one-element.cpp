class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int zero = 0, l = 0;
        for (int r = 0; r < n; ++r) {
            zero += (nums[r] == 0);
            while (zero > 1) zero -= (nums[l++] == 0);
            ans = max(ans, r-l);
        }
        return ans;
    }
};