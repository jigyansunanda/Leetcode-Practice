class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k) return false;
        int mask = (1 << n) - 1;
        vector<int> dp(mask + 1, -1);
        int target = total / k;
        dp[0] = 0;
        for (int i = 0; i <= mask; ++i) {
            if (dp[i] == -1) continue;
            for (int j = 0; j < n; ++j) {
                if (!(i & (1 << j)) and dp[i] + nums[j] <= target) {
                    dp[i ^ (1 << j)] = (dp[i] + nums[j]) % target;
                }
            }
        }
        return dp[mask] == 0;
    }
};