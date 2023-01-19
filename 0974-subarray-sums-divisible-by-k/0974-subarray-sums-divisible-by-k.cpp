class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k, int ans = 0) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int remainder = 0;
        for (auto num : nums) {
            remainder = (remainder + num) % k;
            if (remainder < 0) remainder += k;
            if (remainder == 0) ++ans;
            if (mp.find(remainder) != mp.end()) ans += mp[remainder];
            mp[remainder]++;
        }
        return ans;
    }
};