class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int rem = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            rem = (rem + (nums[i] % k)) % k;
            if (rem < 0) rem += k;
            if (rem == 0) ++ans;
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};