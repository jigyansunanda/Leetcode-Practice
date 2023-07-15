class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector dp(n, vector<int>(2, 0));
        dp[0][0] = dp[0][1] = 1;
        int ans = 1;
        for (int i = 1; i <= n - 1; ++i) {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] == nums[i]) continue;
                if (nums[i] > nums[j]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                if (nums[i] < nums[j]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
            ans = max({ans, dp[i][0], dp[i][1]});
        }
        return ans;
    }
};