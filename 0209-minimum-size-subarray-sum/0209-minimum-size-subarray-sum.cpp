class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), l = 0, ans = INT_MAX;
        long long sum = 0;
        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            while (sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                ++l;
            }
        }
        return ans % INT_MAX;
    }
};