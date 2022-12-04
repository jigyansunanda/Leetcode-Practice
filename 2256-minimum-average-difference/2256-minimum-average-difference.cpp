class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n, 0), suffix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i <= n - 1; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        long long mk = INT_MAX;
        for (int i = 0; i < n; ++i) {
            prefix[i] = (prefix[i] / (i + 1));
            if (i != n - 1) suffix[i] = ((suffix[i] - nums[i]) / (n - i - 1));
            else suffix[i] = 0;
            prefix[i] = abs(prefix[i] - suffix[i]);
            mk = min(mk, prefix[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (prefix[i] == mk) return i;
        }
        return -1;
    }
};