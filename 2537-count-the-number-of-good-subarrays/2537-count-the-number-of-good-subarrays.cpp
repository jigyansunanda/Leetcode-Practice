class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long n = nums.size();
        long long ans = (n * (n + 1)) / 2;
        int l = 0;
        unordered_map<int, long long> mp;
        long long pairCount = 0;
        for (int r = 0; r < n; ++r) {
            mp[nums[r]]++;
            pairCount += mp[nums[r]] - 1;
            while (pairCount >= (long long) k) {
                pairCount -= mp[nums[l]] - 1;
                mp[nums[l]]--;
                ++l;
            }
            if (pairCount < k) {
                long long count = r - l + 1;
                ans -= count;
            }
        }
        return ans;
    }
};