class Solution {
public:
    int countTriplets(vector<int>& nums, int ans = 0) {
        int N = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> dp(N, 0);
        for (int e : nums)
            for (int j : nums) dp[e & j]++;
        for (int i = 0; i < ((int) nums.size()); ++i) {
            for (int j = 0; j < N; ++j) {
                if ((nums[i] & j) == 0) ans += dp[j];
            }
        }
        return ans;
    }
};