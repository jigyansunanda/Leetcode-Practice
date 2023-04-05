class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long prefix_sum = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            prefix_sum += nums[i];
            ans = max(ans, (prefix_sum + i) / (i + 1));
        }
        return ans;
    }
};