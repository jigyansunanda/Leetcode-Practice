class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
            if (i + 1 < n) dp[i][i + 1] = max(nums[i], nums[i + 1]);
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                int takeFromStart = nums[i] + min(dp[i + 1][j - 1], dp[i + 2][j]);
                int takeFromEnd = nums[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(takeFromStart, takeFromEnd);
            }
        }
        int player1 = dp[0][n - 1];
        int player2 = total - player1;
        return (player1 >= player2);
    }
};