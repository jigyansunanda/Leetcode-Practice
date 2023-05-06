class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> power(n + 1, 1);
        constexpr long long mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i) power[i] = (power[i - 1] * 2) % mod;
        long long ans = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans += (power[r - l]);
                ans %= mod;
                l++;
            } else --r;
        }
        return ans;
    }
};