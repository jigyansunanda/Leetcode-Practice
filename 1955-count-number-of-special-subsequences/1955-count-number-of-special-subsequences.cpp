class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        const long long mod = 1e9 + 7;
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(3, 0LL));
        long long zeros = 0, ones = 0, twos = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                dp[i][0] = (zeros + 1) % mod;
                zeros = (zeros + dp[i][0]) % mod;
            } else if (nums[i] == 1) {
                dp[i][1] = (zeros + ones) % mod;
                ones = (ones + dp[i][1]) % mod;
            } else {
                dp[i][2] = (ones + twos) % mod;
                twos = (twos + dp[i][2]) % mod;
            }
        }
        return twos;
    }
};